/*
    Sistema de clanes
    By: Sleek

*/

#include <YSI\y_hooks>


#include "../Modulos/grupos/DataGroups.inc"
#include "../Modulos/grupos/territories.inc"



CMD:crearclan(playerid, params[1])
{
    new nombreclan[20];
    if(sscanf(params, "s[20]", nombreclan)) return SendClientMessage(playerid, -1, "{FF0000}• {ffffff}Uso: /crearclan [Nombre del Clan]");
    {
        new rnd = random(206);
        CrearClan(playerid, nombreclan, RandomColors[rnd]);
    }
    return 1;
}

//_________Panel____________//
CMD:clan(playerid)
{
    if(ClanPlayer[playerid][Cp_Grupo] == 1)
    {
        new temp_nombre_clan[256];
        format(temp_nombre_clan, 256, "{%06x}%s", Clanes[ClanPlayer[playerid][Cp_ID]][C_Color] >>> 8, Clanes[ClanPlayer[playerid][Cp_ID]][C_Nombre]);
        ShowPlayerDialog(playerid, d_panel, DIALOG_STYLE_LIST, temp_nombre_clan, "Agregar Miembro\nExpulsar Miembro\nColor del Clan\nTerritorio\nInformacion", "Aceptar", "Salir");
    }
    return 1;
}

CMD:saveclan(playerid)
{
    GuardarGrupos();
    return 1;
}


hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == d_panel)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0: ShowPlayerDialog(playerid, d_clan_reclutar, DIALOG_STYLE_INPUT, "Reclutar Miembro", "{FFC900}• {ffffff}Escribe la {FF5733}ID {ffffff}del jugador a reclutar", "Reclutar", "Cancelar");
                case 1: ShowPlayerDialog(playerid, d_clan_expulsar, DIALOG_STYLE_INPUT, "Reclutar Miembro", "{FFC900}• {ffffff}Escribe la {FF5733}ID {ffffff}del jugador a expulsar", "Expulsar", "Cancelar");
                case 2:
                {
                    new colores_temp[3620];
                    for(new i; i < sizeof(RandomColors); i++)
                    {
                        new temp_temp[256];
                        format(temp_temp, 256, "{%06x}Color %d\n", RandomColors[i] >>> 8, i);
                        strcat(colores_temp, temp_temp);
                    }
                    ShowPlayerDialog(playerid, d_clan_colores, DIALOG_STYLE_LIST, "Seleciona un color", colores_temp, "Aceptar", "Salir");
                }
                case 3: 
                {
                    if(Clanes[ClanPlayer[playerid][Cp_ID]][C_Territorio] == 0)
                    {
                        if(PuedeReclamarTerritorio(playerid) > 0)
                        {
                            CrearTerritorio(playerid);
                        } else ShowInfoForPlayer(playerid, "~r~Busca otro lugar", 3000);
                    }
                }
                case 4:
                {
                    new str[350];
                    format(str, sizeof(str), "{ffffff}Clan ID: {%06x}%d\n{ffffff}Clan Lider: {%06x}%s\n{ffffff}Clan Miembros: {%06x}%d", Clanes[ClanPlayer[playerid][Cp_ID]][C_Color] >>> 8, Clanes[ClanPlayer[playerid][Cp_ID]][C_ID], 
                    Clanes[ClanPlayer[playerid][Cp_ID]][C_Color] >>> 8, Clanes[ClanPlayer[playerid][Cp_ID]][C_Owner], Clanes[ClanPlayer[playerid][Cp_ID]][C_Color] >>> 8, Clanes[ClanPlayer[playerid][Cp_ID]][C_Miembros]);
                    ShowPlayerDialog(playerid, d_clan_info, DIALOG_STYLE_MSGBOX, "Informacion", str, "Aceptar", "Salir");
                }
            }
        }
    }
    if(dialogid == d_clan_colores)
    {
        if(response)
        {
            Clanes[ ClanPlayer[playerid][Cp_ID] ][C_Color] = RandomColors[listitem];
            new str[128];
            format(str, 128, "{36FF00}• {ffffff}Actualizaste el {%06x}color {ffffff}de %s", Clanes[ ClanPlayer[playerid][Cp_ID] ][C_Color] >>> 8, Clanes[ ClanPlayer[playerid][Cp_ID] ][C_Nombre]);
            SendClientMessage(playerid, -1, str);
            if(Clanes[ ClanPlayer[playerid][Cp_ID] ][C_Territorio] == 1)
            {
                ActualizarColorTerritorio(playerid);
            }
        }
    }
    if(dialogid == d_clan_reclutar)
    {
        if(response)
        {
            if(IsNumeric(inputtext))
            {
                new id_temp = strval(inputtext);
                UnirMiembroClan(playerid, id_temp);
            } else  ShowInfoForPlayer(playerid, "~r~Solo puedes ingresar la ID del jugador", 3000);
        }
    }
    if(dialogid == d_clan_expulsar)
    {
        if(response)
        {
            if(IsNumeric(inputtext))
            {
                new id_temp = strval(inputtext);
                ExpulsarMiembroClan(playerid, id_temp);
            } else ShowInfoForPlayer(playerid, "~r~Solo puedes ingresar la ID del jugador", 3000);
        }
    }
}

stock CrearClan(playerid, nombre[20], color)
{
    for(new i = 1; i < MAX_CLANES; i++)
    {
        if(Clanes[i][C_ID] == 0)
        {
            ClanPlayer[playerid][Cp_Grupo] = 1;
            ClanPlayer[playerid][Cp_Lider] = 1;
            countclanes++;
            new handle2 = SQL::Open(SQL::INSERT, "grupos");
            SQL::ToggleAutoIncrement(handle2, true);
            SQL::WriteString(handle2, "Nombre", nombre);
            SQL::WriteInt(handle2, "Color", color);
            SQL::WriteString(handle2, "Owner", ret_pName(playerid));
            SQL::WriteInt(handle2, "Miembros", 1);
            SQL::WriteInt(handle2, "Territorio", 0);
            SQL::WriteInt(handle2, "GangZone", 0);
            SQL::WriteFloat(handle2, "minX", 0.0);
            SQL::WriteFloat(handle2, "minY", 0.0);
            SQL::WriteFloat(handle2, "maxX", 0.0);
            SQL::WriteFloat(handle2, "maxY", 0.0);
            new pia = SQL::Close(handle2);
            Clanes[pia][C_ID] = pia;
            Clanes[pia][C_Nombre] = nombre;
            Clanes[pia][C_Color] = color;
            Clanes[pia][C_Owner] = ret_pName(playerid);
            Clanes[pia][C_Miembros] = 1;
            Clanes[pia][C_Territorio] = 0;
            ClanPlayer[playerid][Cp_ID] = Clanes[pia][C_ID];
            new handle = SQL::Open(SQL::UPDATE, "usuarios", "ID", CuentaInfo[playerid][ID]);
            SQL::WriteInt(handle, "GrupoID", ClanPlayer[playerid][Cp_ID]);
            SQL::WriteInt(handle, "Grupo", ClanPlayer[playerid][Cp_Grupo]);
            SQL::WriteInt(handle, "GrupoLider", ClanPlayer[playerid][Cp_Lider]);
            SQL::Close(handle);
            new str[128];
            format(str, 128, "{36FF00}• {ffffff}Felicidades, creaste el grupo {%06x}%s", Clanes[pia][C_Color] >>> 8, Clanes[pia][C_Nombre]);
            SendClientMessage(playerid, -1, str);
            break;
        }
    }
}


//_________________FUNCIONES PARA LIDER____________//
stock UnirMiembroClan(playerid, id)
{
    if(IsPlayerConnected(id))
    {
        new Float:idpos[3];
        GetPlayerPos(id, idpos[0], idpos[1], idpos[2]);
        if(IsPlayerInRangeOfPoint(playerid, 7.0, idpos[0], idpos[1], idpos[2]))
        {
            if(ClanPlayer[id][Cp_Grupo] == 0)
            {
                ClanPlayer[id][Cp_Grupo] = 1;
                ClanPlayer[id][Cp_ID] = ClanPlayer[playerid][Cp_ID];
                new str[128];
                format(str, 128, "%s ha ingresado al clan!", ret_pName(id));
                RadioClanes(playerid, str);
            } else  ShowInfoForPlayer(playerid, "~r~El jugador ya tiene un clan", 3000);
        } else  ShowInfoForPlayer(playerid, "~r~El jugador no se encuentra cerca", 3000);
    } else  ShowInfoForPlayer(playerid, "~r~Jugador no conectado!", 3000);
}

stock ExpulsarMiembroClan(playerid, id)
{
    if(IsPlayerConnected(id))
    {
        if(ClanPlayer[id][Cp_Grupo] == ClanPlayer[playerid][Cp_Grupo])
        {
            ClanPlayer[id][Cp_Grupo] = 0;
            ClanPlayer[id][Cp_ID] = 0;
            new str[128];
            format(str, 128, "%s fue expulsado del clan!", ret_pName(id));
            RadioClanes(playerid, str);
        } else ShowInfoForPlayer(playerid, "~r~El jugador no es parte de tu clan", 3000);
    } else ShowInfoForPlayer(playerid, "~r~Jugador no conectado!", 3000);
}

stock SalirClan(playerid)
{
    if(ClanPlayer[playerid][Cp_Grupo] > 0)
    {
        ClanPlayer[playerid][Cp_Grupo] = 0;
        ClanPlayer[playerid][Cp_ID] = 0;
        new str[128];
        format(str, 128, "%s salio del clan!", ret_pName(id));
        RadioClanes(playerid, str);
    }
}

stock RadioClanes(playerid, string[])
{
    for(new p; p < MAX_CLANES; p++)
    {
        if(ClanPlayer[playerid][Cp_ID] == Clanes[p][C_ID])
        {
            for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
            {
                if(ClanPlayer[playerid][Cp_ID] == ClanPlayer[i][Cp_ID])
                {
                    new str[256];
                    format(str, 256, "{%06x}[%s] %s: %s", Clanes[p][C_Color] >>> 8, Clanes[p][C_Nombre], ret_pName(playerid), string);
                    SendClientMessage(i, -1, str);
                }
            }
            break;
        } else continue;
    }
}

stock CargarGrupos()
{
    for(new i; i < MAX_CLANES; i++)
    {
        new hand = SQL::Open(SQL::MTREAD, "grupos");
        new pia;
        SQL::ReadInt(hand, "ID", pia, i);
        Clanes[pia][C_ID] = pia;
        SQL::ReadString(hand, "Nombre", Clanes[pia][C_Nombre], 20, i);
        SQL::ReadInt(hand, "Color", Clanes[pia][C_Color], i);
        SQL::ReadString(hand, "Owner", Clanes[pia][C_Owner], MAX_PLAYER_NAME, i);
        SQL::ReadInt(hand, "Miembros", Clanes[pia][C_Miembros], i);
        SQL::ReadInt(hand, "Territorio", Clanes[pia][C_Territorio], i);
        SQL::ReadInt(hand, "GangZone", Clanes[pia][C_GangZone], i);
        SQL::ReadInt(hand, "AreaID", Clanes[pia][C_AreaID], i);
        SQL::ReadFloat(hand, "minX", Clanes[pia][C_minX], i);
        SQL::ReadFloat(hand, "minY", Clanes[pia][C_minY], i);
        SQL::ReadFloat(hand, "maxX", Clanes[pia][C_maxX], i);
        SQL::ReadFloat(hand, "maxY", Clanes[pia][C_maxY], i);
        countclanes = SQL::Close(hand);
        Clanes[pia][C_AreaID] = CreateDynamicCube(Clanes[pia][C_minX], Clanes[pia][C_minY], -100.00, Clanes[pia][C_maxX], Clanes[pia][C_maxY], 1000.00);
    }
    printf("[Clanes Cargados]: %d", countclanes);
}
stock GuardarGrupos()
{
    for(new i = 1; i < MAX_CLANES; i++)
    {
        if(Clanes[i][C_ID] > 0)
        {
            new handle2 = SQL::Open(SQL::UPDATE, "grupos", "ID", Clanes[i][C_ID]);
            SQL::WriteString(handle2, "Nombre", Clanes[i][C_Nombre]);
            SQL::WriteString(handle2, "Owner", Clanes[i][C_Owner]);
            SQL::WriteInt(handle2, "Color", Clanes[i][C_Color]);
            SQL::WriteInt(handle2, "Miembros", Clanes[i][C_Miembros]);
            SQL::WriteInt(handle2, "Territorio", Clanes[i][C_Territorio]);
            SQL::WriteInt(handle2, "GangZone", Clanes[i][C_GangZone]);
            SQL::WriteInt(handle2, "AreaID", Clanes[i][C_AreaID]);
            SQL::WriteFloat(handle2, "minX", Clanes[i][C_minX]);
            SQL::WriteFloat(handle2, "minY", Clanes[i][C_minY]);
            SQL::WriteFloat(handle2, "maxX", Clanes[i][C_maxX]);
            SQL::WriteFloat(handle2, "maxY", Clanes[i][C_maxY]);
            SQL::Close(handle2);
        }
    }
}