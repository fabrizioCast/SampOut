public OnPlayerEnterDynamicArea(playerid, areaid)
{
    SendClientMessage(playerid, -1, "aca si");
    for(new i; i < MAX_CLANES; i++)
    {
        SendClientMessage(playerid, -1, "aca no");
        if(areaid == Clanes[i][C_AreaID])
        {
            new str[128];
            format(str, 128, "{FFC900}• {ffffff}Entraste al territorio del grupo {%06x}%s", Clanes[i][C_Color] >>> 8, Clanes[i][C_Nombre]);
            SendClientMessage(playerid, -1, str);
            break;
        }
    }
}

stock CrearTerritorio(playerid)
{
    new Float:posa[3];
    GetPlayerPos(playerid, posa[0], posa[1], posa[2]);
    GetBoundsOfGangZone(posa[0], posa[1], 200.00, 200.00, Clanes[ ClanPlayer[playerid][Cp_ID] ][C_minX], Clanes[ ClanPlayer[playerid][Cp_ID] ][C_minY], Clanes[ ClanPlayer[playerid][Cp_ID] ][C_maxX], Clanes[ ClanPlayer[playerid][Cp_ID] ][C_maxY]);
    Clanes[ ClanPlayer[playerid][Cp_ID] ][C_GangZone] = GangZoneCreate(Clanes[ ClanPlayer[playerid][Cp_ID] ][C_minX], Clanes[ ClanPlayer[playerid][Cp_ID] ][C_minY], Clanes[ ClanPlayer[playerid][Cp_ID] ][C_maxX], Clanes[ ClanPlayer[playerid][Cp_ID] ][C_maxY]);
    new color_terri, r, g, b, a;
    HexToRGBA(Clanes[ ClanPlayer[playerid][Cp_ID] ][C_Color], r, g, b, a);
    color_terri = RGBAToHex(r, g, b, 135);
    GangZoneShowForAll(Clanes[ ClanPlayer[playerid][Cp_ID] ][C_GangZone], color_terri);
    Clanes[ ClanPlayer[playerid][Cp_ID] ][C_Territorio] = 1;
    Clanes[ ClanPlayer[playerid][Cp_ID] ][C_AreaID]  = CreateDynamicCube(Clanes[ ClanPlayer[playerid][Cp_ID] ][C_minX], Clanes[ ClanPlayer[playerid][Cp_ID] ][C_minY], -100.00, Clanes[ ClanPlayer[playerid][Cp_ID] ][C_maxX], Clanes[ ClanPlayer[playerid][Cp_ID] ][C_maxY], 1000.00);
    new str[128];
    format(str, 128, "{36FF00}• {ffffff}Felicidades, creaste un territorio para el grupo {%06x}%s", Clanes[ ClanPlayer[playerid][Cp_ID] ][C_Color] >>> 8, Clanes[ ClanPlayer[playerid][Cp_ID] ][C_Nombre]);
    SendClientMessage(playerid, -1, str);
}

stock MostrarTerritorios(playerid)
{
    for(new i = 1; i < MAX_CLANES; i++)
    {
        if(Clanes[i][C_ID] > 0)
        {
            if(Clanes[i][C_Territorio] == 1)
            {
                Clanes[i][C_GangZone] = GangZoneCreate(Clanes[i][C_minX],Clanes[i][C_minY], Clanes[i][C_maxX], Clanes[i][C_maxY]);
                new color_terri, r, g, b, a;
                HexToRGBA(Clanes[i][C_Color], r, g, b, a);
                color_terri = RGBAToHex(r, g, b, 135);
                GangZoneShowForPlayer(playerid, Clanes[i][C_GangZone], color_terri);
            }
        }
    }
}