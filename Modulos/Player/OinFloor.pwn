#include "YSI\y_hooks"


//_______________VARIABLES_______________________//
//new Randomobj; //Almacena el objeto random para spawnearlo.



//=============[CORDENADAS LOOT BASICO]======================//
stock const Float:CoordLootBasicos[][] = {
    {1967.1367,-2020.9553,13.5469},
    {1968.6241,-2042.9961,13.5469},
    {1957.8922,-2047.8676,13.3828},
    {1944.5829,-2048.0410,13.3828},
    {1940.7380,-2057.6499,13.5469},
    {1959.1528,-2067.3354,13.3828},
    {1971.8301,-2066.3193,13.5469},
    {1975.1056,-2054.3411,13.5469}
};
//==========[IDS OBJETOS BASICOS]==================//
new ObjetosBasicos[][] = {
    {10},
    {11},
    {12},
    {13},
    {14},
    {15},
    {16}
};


//==============[LOOT MECANICO]=====================//
stock const Float:CoordLootMecanico[][] = {
	{2696.9824,-2467.9143,13.6481}, // loot mecanico
	{2696.9814,-2452.3870,13.6405}, // loot mecanico
	{2696.9822,-2437.1833,13.6331}, // loot mecanico
	{2700.4292,-2384.1724,13.6428}, // loot mecanico
	{2670.9128,-2384.1760,13.6428}, // loot mecanico
	{2640.7549,-2384.1726,13.6428} // loot mecanico
};



//====================[LOOT MEDICO]=============================//
stock const Float:CoordLootMedico[][] = {
	{2041.4272,-1430.3933,17.1641}, // loot medico
	{1170.4233,-1308.6229,13.9913}, // loot medico
	{-320.2326,1048.2341,20.3403}, // loot medico
	{-330.7688,1050.7594,19.7392}, // loot medico
	{1584.0470,1769.0239,10.8203}, // loot medico
	{1585.0011,1750.3346,10.8203} // loot medico
};



stock CrearOInFloor(Float:Floorx, Float:Floory, Float:Floorz, itemfloor)
{
    ObjetosPiso[O_infloor][itemid] = itemfloor;
    ObjetosPiso[O_infloor][modelid] = Objetos[itemfloor][model];
    ObjetosPiso[O_infloor][pos][0] = Floorx;
    ObjetosPiso[O_infloor][pos][1] = Floory;
    ObjetosPiso[O_infloor][pos][2] = Floorz;
    ObjetosPiso[O_infloor][objeto] = CreateObject(ObjetosPiso[O_infloor][modelid], Floorx, Floory, Floorz-0.95, 5.0, 0, 0, 30.0);
    new string3d[60];
    format(string3d, sizeof(string3d), "{154265}%s", Objetos[itemfloor][name]);
    ObjetosPiso[O_infloor][dtext] = Create3DTextLabel(string3d, -1, Floorx, Floory, Floorz-0.95, 8.0, 0, 0);
    if(O_infloor == MAX_OBJETOS_WORDl-2) O_infloor = 0;
    else O_infloor += 1;
}

stock RandomType(type)
{
    new Randomobj;
    if(type == 1)
    {
        for(new i; i < sizeof ObjetosBasicos; i++)
        {
            new rnd = random(7);
            Randomobj = ObjetosBasicos[rnd][0];
        }
    }
    return Randomobj;
}
stock RespawnObjetos()
{
    new contadorobjetos;
    for(new i; i < sizeof CoordLootBasicos; i++)
    {
        CrearOInFloor(CoordLootBasicos[i][0], CoordLootBasicos[i][1], CoordLootBasicos[i][2], RandomType(1));
        contadorobjetos++;
    }
    printf("[SampOut]: Se respawnearon %d objetos.", contadorobjetos);
}

CMD:respawn(playerid)
{
    RespawnObjetos();
    return 1;
}

CMD:ir(playerid, params[3])
{
    new Float:po[3];
    if(sscanf(params, "fff", po[0], po[1], po[2])) return SendClientMessageToAll(-1, "Uso /ir [X][Y][Z]");
    {
        SetPlayerPos(playerid, po[0], po[1], po[2]);
    }
    return 1;
}





































/*
new zona1[2];

hook:OnGameModeInit()
{
    zona1[0] = GangZoneCreate(1820.5, -2165.5, 1970.5, -2059.5);
    zona1[1] = CreateDynamicRectangle(1820.5, -2165.5, 1970.5, -2059.5, -1, -1, -1);
}
hook:OnPlayerConnect(playerid)
{
    GangZoneShowForPlayer(playerid, zona1[0], 0x00FFFFFF);
}
public OnPlayerEnterDynamicArea(playerid, areaid)
{
    if(areaid == zona1[1])
    {
        SendClientMessage(playerid, -1, "Hola");
    }
}*/
