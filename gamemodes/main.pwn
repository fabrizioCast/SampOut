#include <a_samp>
#include <a_mysql>
#include <foreach>
#include <sscanf2>
#include <zcmd>
#include <Pawn.Regex>
#include  <YSI\y_hooks>
#include <ShowInfoForPlayer>
#include <progress3D>


//------------------DEFINES-----------------//
#undef MAX_PLAYERS
#define MAX_PLAYERS 100
#define NOMBRE_SV "Samp-X 0.1"


//------------------M O D U L O S-----------------//
#include "../Modulos/Server/DataStore.pwn"
#include "../Modulos/Server/prox.pwn"
#include "../Modulos/Server/registry.pwn"
#include "../Modulos/Player/inventory.pwn"
#include "../Modulos/Player/Commands.pwn"




//------------------MYSQL-----------------//
#define mysql_host "localhost"
#define mysql_user "root"
#define mysql_pass ""
#define mysql_database "ZombieRP"
//----------------------INICIO GAMEMODE---------------------//
main ()
{
    printf("//------------------------------------//");
    printf("//-----------SINNOMBRE ROLEPLAY----------//");
    printf("//----------------BY------------------//");
    printf("//---------------Sleek----------------//");
}
//-------------------------PUBLIC´S-----------------------//
public OnGameModeInit()
{
    //_______________MYSQL___________________//
    Database = mysql_connect(mysql_host, mysql_user, mysql_pass, mysql_database);
    if(Database == MYSQL_INVALID_HANDLE || mysql_errno(Database) != 0)
    {
        printf("[ERROR]: ERROR AL CONECTAR CON LA DATABASE!");
        SendRconCommand("exit");
        return 0;
    }
    else
    {
        printf("Conectado a la base de datos correctamente!");
    }
    //___________NOMBRE DEL SV Y ESAS PELOTUDESES______________//
    SetGameModeText(NOMBRE_SV);
    return 1;
}

public OnPlayerConnect(playerid)
{ 
    if(strfind(GetName(playerid),"_", false) != -1 || !strcmp(GetName(playerid), "Sleek", false, 5))
    {
        new str[128];
        GetPlayerName(playerid, CuentaInfo[playerid][Nombre], MAX_PLAYER_NAME);
        mysql_format(Database, str, sizeof(str), "SELECT * FROM `usuarios` WHERE `Nombre` = '%e' LIMIT 1", CuentaInfo[playerid][Nombre]);
        mysql_tquery(Database, str, "OnPlayerDataCheck", "i", playerid);
    }
    else
    {
        clearChat(playerid);
        SendClientMessage(playerid, -1, "{FF0000}Error: {ffffff}Nombre de usuario no valido. (NOMBRE_APELLIDO)");
        SetSpawnInfo(playerid, 0, 0,  320.0000,50.0000,190.0000, 269.15, 0, 0, 0, 0, 0, 0 );
        SpawnPlayer(playerid);
        SetPlayerCameraPos(playerid, 1478.2531,-1683.3368,104.4600);
        SetPlayerCameraLookAt(playerid, 1478.2531,-1683.3368,104.4600, CAMERA_MOVE);
        InterpolateCameraLookAt(playerid, 50.0, 50.0, 10.0, -50.0, -50.0, -10.0, 15000, CAMERA_MOVE);
        SetTimerEx("KickearR", 1000, false, "d", playerid);
    }
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    GuardarCuentas(playerid);
}
public OnGameModeExit()
{
    foreach(new i : Player)
    {
        GuardarCuentas(i);
    }
    mysql_close(Database);
    return 0;
}
public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if(clickedid == Text:INVALID_TEXT_DRAW)
	{
		if(CuentaInfo[playerid][Logeado] == 0)
        {
            SelectTextDraw(playerid, 0xF9BB0AFF);
            return 1;
        }
        else if(VE[playerid][inmenu] == true)
        {
            SelectTextDraw(playerid,  0xFFFFFFAA);
            return 1;
        }
	}
    return 0;
}

//-----------------------FUNCIONES MYSQL-----------------------//
forward KickearR(playerid);
public KickearR(playerid)
{
    Kick(playerid);
    return 1;
}
forward OnPlayerDataCheck(playerid);
public OnPlayerDataCheck(playerid)
{
    new rows;
    cache_get_row_count(rows);
    if(rows > 0)
    {
        cache_get_value(0, "Password", CuentaInfo[playerid][Password], 65);
        for(new i; i <12; i++)
        {
            TextDrawShowForPlayer(playerid, LoginTD[i]);
        }
        PlayerTextDrawShow(playerid, LoginTD2[playerid][1]);
        SelectTextDraw(playerid, 0xF9BB0AFF);
    }
    else
    {
        for(new i = 0; i<15; i++)
        {
            TextDrawShowForPlayer(playerid, ClaveTD[i]);
        }
        for(new i = 0; i<2; i++)
        {
            PlayerTextDrawShow(playerid, PlayerTD[playerid][i]);
        }
        SelectTextDraw(playerid, 0xF9BB0AFF); 
    }
    return 1;
}

forward CargarCuenta(playerid);
public CargarCuenta(playerid) 
{
	new rows;
	cache_get_row_count(rows);
	if(!rows) return 0;
	else 
    {
		cache_get_value_int(0, "ID", CuentaInfo[playerid][ID]);
		cache_get_value_int(0, "Edad", CuentaInfo[playerid][Edad]);
		cache_get_value_float(0, "PosX", CuentaInfo[playerid][PosX]);
		cache_get_value_float(0, "PosY", CuentaInfo[playerid][PosY]);
		cache_get_value_float(0, "PosZ", CuentaInfo[playerid][PosZ]);
        cache_get_value_int(0, "Skin", CuentaInfo[playerid][Skin]);
        SetPlayerPos(playerid, CuentaInfo[playerid][PosX], CuentaInfo[playerid][PosY], CuentaInfo[playerid][PosZ]);
        SetPlayerSkin(playerid, CuentaInfo[playerid][Skin]);
        TogglePlayerControllable(playerid, 1);
	}
	return 1;
}
stock GuardarCuentas(playerid)
{
	new str[256];
    CuentaInfo[playerid][Skin] = GetPlayerSkin(playerid);
    GetPlayerPos(playerid, CuentaInfo[playerid][PosX], CuentaInfo[playerid][PosY], CuentaInfo[playerid][PosZ]);
    mysql_format(Database, str, sizeof(str),"UPDATE `usuarios` SET `PosX` = %f, `PosY`= %f, `PosZ`= %f, `Skin` = %d WHERE `ID` = %d LIMIT 1", CuentaInfo[playerid][PosX], CuentaInfo[playerid][PosY], CuentaInfo[playerid][PosZ], CuentaInfo[playerid][Skin], CuentaInfo[playerid][ID]);
    mysql_tquery(Database, str);
	return 1;
}

stock GetName(playerid) 
{
	new namer[MAX_PLAYER_NAME];
	GetPlayerName(playerid, namer, sizeof(namer));
	return namer;
}

clearChat(playerid)
{
	for(new i; i<50; i++)
	{
		SendClientMessage(playerid, -1, "");
	}
	return 1;
}