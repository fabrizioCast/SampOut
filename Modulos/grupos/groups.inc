#include <YSI\y_hooks>


#include "../Modulos/grupos/DataGroups.inc"



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


stock CrearClan(playerid, nombre[20], color)
{
    for(new i = 1; i < MAX_CLANES; i++)
    {
        if(Clanes[i][C_ID] == 0)
        {
            Clanes[i][C_Nombre] = nombre;
            Clanes[i][C_Color] = color;
            Clanes[i][C_Owner] = ret_pName(playerid);
            Clanes[i][C_Miembros] = 1;
            Clanes[i][C_Territorio] = 0;
            ClanPlayer[playerid][Cp_Grupo] = 1;
            ClanPlayer[playerid][Cp_Lider] = 1;
            ClanPlayer[playerid][Cp_Color] = color;
            countclanes++;
            new handle2 = SQL::Open(SQL::INSERT, "grupos");
            SQL::ToggleAutoIncrement(handle2, true);
            SQL::WriteString(handle2, "Nombre", Clanes[i][C_Nombre]);
            SQL::WriteInt(handle2, "Color", Clanes[i][C_Color]);
            SQL::WriteString(handle2, "Owner", Clanes[i][C_Owner]);
            SQL::WriteInt(handle2, "Miembros", Clanes[i][C_Miembros]);
            SQL::WriteInt(handle2, "Territorio", Clanes[i][C_Territorio]);
            Clanes[i][C_ID] = SQL::Close(handle2);
            ClanPlayer[playerid][Cp_ID] = Clanes[i][C_ID];
            new handle = SQL::Open(SQL::UPDATE, "usuarios", "ID", CuentaInfo[playerid][ID]);
            SQL::WriteInt(handle, "GrupoID", ClanPlayer[playerid][Cp_ID]);
            SQL::WriteInt(handle, "Grupo", ClanPlayer[playerid][Cp_Grupo]);
            SQL::WriteInt(handle, "GrupoLider", ClanPlayer[playerid][Cp_Lider]);
            SQL::Close(handle);
            new str[128];
            format(str, 128, "{36FF00}• {ffffff}Felicidades, creaste el grupo {%06x}%s", Clanes[i][C_Color] >>> 8, Clanes[i][C_Nombre]);
            SendClientMessage(playerid, -1, str);
            break;
        }
    }
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == d_panel)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
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
                case 1: SendClientMessage(playerid, -1, "{FFC900}• {ffffff}Proximamente...");
                case 2:
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
            Clanes[ClanPlayer[playerid][Cp_ID]][C_Color] = RandomColors[listitem];
        }
    }
}
//_________Panel____________//
CMD:clan(playerid)
{
    if(ClanPlayer[playerid][Cp_Grupo] == 1)
    {
        new temp_nombre_clan[256];
        format(temp_nombre_clan, 256, "{%06x}%s", Clanes[ClanPlayer[playerid][Cp_ID]][C_Color] >>> 8, Clanes[ClanPlayer[playerid][Cp_ID]][C_Nombre]);
        ShowPlayerDialog(playerid, d_panel, DIALOG_STYLE_LIST, temp_nombre_clan, "Color del Clan\nTerritorio\nInformacion", "Aceptar", "Salir");
    }
    return 1;
}

CMD:saveclan(playerid)
{
    GuardarGrupos();
    return 1;
}
stock RadioClanes(playerid, string[])
{
    for(new p; p <= countclanes; p++)
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
        countclanes = SQL::Close(hand);
    }
    printf("[Clanes Cargados]: %d", countclanes);
}

stock GuardarGrupos()
{
    for(new i = 1; i <= countclanes; i++)
    {
        if(Clanes[i][C_ID] > 0)
        {
            new handle2 = SQL::Open(SQL::UPDATE, "grupos", "ID", Clanes[i][C_ID]);
            SQL::WriteString(handle2, "Nombre", Clanes[i][C_Nombre]);
            SQL::WriteString(handle2, "Owner", Clanes[i][C_Owner]);
            SQL::WriteInt(handle2, "Color", Clanes[i][C_Color]);
            SQL::WriteInt(handle2, "Miembros", Clanes[i][C_Miembros]);
            SQL::WriteInt(handle2, "Territorio", Clanes[i][C_Territorio]);
            SQL::Close(handle2);
        }
    }
}