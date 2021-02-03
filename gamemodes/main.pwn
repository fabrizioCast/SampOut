#include <a_samp>
#include <easy-mysql>
#include <foreach>
#include <sscanf2>
#include <Pawn.CMD>
#include <Pawn.Regex>
#include <YSI\y_hooks>
#include <ShowInfoForPlayer>
#include <progress2>
#include <ShowObject>
#include <streamer>

//------------------DEFINES-----------------//
#undef MAX_PLAYERS
#define MAX_PLAYERS 100
#define NOMBRE_SV "Samp-X 0.1"

//------------------M O D U L O S-----------------//
#include "../Modulos/Server/DataStore.pwn"
#include "../Modulos/Server/prox.pwn"
#include "../Modulos/Server/registry.pwn"
#include "../Modulos/Player/Needs.pwn"
#include "../Modulos/Player/inventory.pwn"
#include "../Modulos/Player/Commands.pwn"
#include "../Modulos/Player/OinFloor.pwn"




//------------------MYSQL-----------------//
#define mysql_host "localhost"
#define mysql_user "root"
#define mysql_pass ""
#define mysql_database "SampOut"
//----------------------INICIO GAMEMODE---------------------//
main ()
{
    printf("//------------------------------------//");
    printf("//-----------Samp X ROLEPLAY----------//");
    printf("//----------------BY------------------//");
    printf("//---------------Sleek----------------//");
}
//-------------------------PUBLIC´S-----------------------//
public OnGameModeInit()
{
    //_______________MYSQL___________________//
    SQL::Connect(mysql_host, mysql_user, mysql_pass, mysql_database);
    //___________NOMBRE DEL SV Y ESAS PELOTUDESES______________//
    SetGameModeText(NOMBRE_SV);
    return 1;
}

public OnPlayerConnect(playerid)
{ 
    if(strfind(GetName(playerid),"_", false) != -1 || !strcmp(GetName(playerid), "Sleek", false, 5))
    {
        if(SQL::RowExistsEx("usuarios", "Nombre", ret_pName(playerid)))
        {
            new handle = SQL::OpenEx(SQL::READ, "usuarios", "p_nombre", CuentaInfo[playerid][Nombre]);
			SQL::ReadString(handle, "Password", CuentaInfo[playerid][Password], 65);
            SQL::Close(handle);
            for(new i; i <15; i++)
            {
                TextDrawShowForPlayer(playerid, LoginTD[i]);
            }
            for(new i; i <2; i++)
            {
                PlayerTextDrawShow(playerid, LoginTD2[playerid][i]);
            }
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
    CrearTDDeSIFP(playerid);
    CrearTDShowObject(playerid);
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    SaveAccount(playerid);
    for(new i; i <15; i++)
    {
        TextDrawDestroy(LoginTD[i]);
    }
    for(new i; i <2; i++)
    {
        PlayerTextDrawDestroy(playerid, LoginTD2[playerid][i]);
    }
    printf("%s abandono", ret_pName(playerid));
}
public OnGameModeExit()
{
    foreach(new i : Player)
    {
        SaveAccount(i);
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
            closeInv(playerid);
            return 1;
        }
	}
    return 0;
}


public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
    if(result == -1)
    {
        ShowInfoForPlayer(playerid, "~r~Error: ~w~Comando desconocido.", 3000);
        return 0;
    }
    return 1;
}


//-----------------------FUNCIONES MYSQL-----------------------//
forward KickearR(playerid);
public KickearR(playerid)
{
    Kick(playerid);
    return 1;
}

stock SaveAccount(playerid)
{
    if(CuentaInfo[playerid][Logeado] == 1)
    {
        if(SQL::RowExists("usuarios", "ID", CuentaInfo[playerid][ID]))
        {
            CuentaInfo[playerid][Skin] = GetPlayerSkin(playerid);
            GetPlayerPos(playerid, CuentaInfo[playerid][PosX], CuentaInfo[playerid][PosY], CuentaInfo[playerid][PosZ]);
            new handle = SQL::Open(SQL::UPDATE, "usuarios", "ID", CuentaInfo[playerid][ID]);
            SQL::WriteString(handle, "Nombre", ret_pName(playerid));
            SQL::WriteString(handle, "Password", CuentaInfo[playerid][Password]);
            SQL::WriteInt(handle, "Edad", CuentaInfo[playerid][Edad]);
            SQL::WriteInt(handle, "Skin", CuentaInfo[playerid][Skin]);
            SQL::WriteFloat(handle, "PosX", CuentaInfo[playerid][PosX]);
            SQL::WriteFloat(handle, "PosY", CuentaInfo[playerid][PosY]);
            SQL::WriteFloat(handle, "PosZ", CuentaInfo[playerid][PosZ]);
            SQL::Close(handle);
            printf("%s abandono exitoso", ret_pName(playerid));
            CuentaInfo[playerid][Logeado] = 0;
        }
        printf("%s abandono mysql", ret_pName(playerid));
    }
    printf("%s abandono logeado", ret_pName(playerid));
    return 1;
}
CMD:id(playerid)
{
    printf("ID: %d", CuentaInfo[playerid][ID]);
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