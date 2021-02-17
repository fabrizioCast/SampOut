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
#include <noti>
#include <progressmessage>

//------------------DEFINES-----------------//
#undef MAX_PLAYERS
#define MAX_PLAYERS 100
#define NOMBRE_SV "SampOut 0.1"

//------------------M O D U L O S-----------------//
#include "../Modulos/server/DataStore.inc"
#include "../Modulos/necesidades/needs.inc"
#include "../Modulos/inventario/inventory.inc"
#include "../Modulos/tutorial/characterization.inc"
#include "../Modulos/Server/registry.inc"
#include "../Modulos/loot/OinFloor.inc"
#include "../Modulos/recursos/resources.inc"

CMD:noti(playerid, params[])
{
    new mensaje[128];
    if(sscanf(params, "s[128]", mensaje)) return 1;
    {
        ShowNotification(playerid, mensaje, 4000);
    }
    return 1;
}

//------------------MYSQL-----------------//
#define mysql_host "localhost"
#define mysql_user "root"
#define mysql_pass ""
#define mysql_database "SampOut"

//----------------------INICIO GAMEMODE---------------------//
main ()
{
    printf("\n<         |SampOut RolePlay|         >\n");
}

//-------------------------PUBLIC´S-----------------------//
public OnGameModeInit()
{
    //_______________MYSQL___________________//
    SQL::Connect(mysql_host, mysql_user, mysql_pass, mysql_database);
    SetGameModeText(NOMBRE_SV);
    CargarClave();
    CargarEmail();
    CargarEdad();
    CargarLogin();
    SetWeather(20);
    CargarRecursos();
    return 1;
}

public OnPlayerConnect(playerid)
{ 
    CrearTDDeSIFP(playerid);
    CrearTDShowObject(playerid);
    CrearNoti(playerid);
    CargarTDProgress(playerid);
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    SaveAccount(playerid);
    for(new i; i <15; i++)
    {
        TextDrawHideForPlayer(playerid, LoginTD[i]);
    }
    for(new i; i <2; i++)
    {
        PlayerTextDrawHide(playerid, LoginTD2[playerid][i]);
    }   
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
        else if(temp_inmenu_carac[playerid] == true)
        {
            SelectTextDraw(playerid, 0xFF6C00FF);
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
forward CinematicaInicio(playerid);
public CinematicaInicio(playerid)
{
    SetPlayerCameraPos(playerid, 1478.2531,-1683.3368,104.4600);
    SetPlayerCameraLookAt(playerid, 1478.2531,-1683.3368,104.4600, CAMERA_MOVE);
    InterpolateCameraLookAt(playerid, 50.0, 50.0, 10.0, -50.0, -50.0, -10.0, 15000, CAMERA_MOVE);
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
            SQL::WriteFloat(handle, "Hambre", Necesidades[playerid][N_Hambre]);
            SQL::WriteFloat(handle, "Sed", Necesidades[playerid][N_Sed]);
            SQL::Close(handle);
        }
        if(SQL::RowExists("inventario", "ID", CuentaInfo[playerid][ID]))
        {
            new handle = SQL::Open(SQL::UPDATE, "inventario", "ID", CuentaInfo[playerid][ID]);
            SQL::WriteInt(handle, "Slot1", VE[playerid][Inv][0]);
            SQL::WriteInt(handle, "Slot2", VE[playerid][Inv][1]);
            SQL::WriteInt(handle, "Slot3", VE[playerid][Inv][2]);
            SQL::WriteInt(handle, "Slot4", VE[playerid][Inv][3]);
            SQL::WriteInt(handle, "Slot5", VE[playerid][Inv][4]);
            SQL::WriteInt(handle, "Slot6", VE[playerid][Inv][5]);
            SQL::WriteInt(handle, "Slot7", VE[playerid][Inv][6]);
            SQL::WriteInt(handle, "Slot8", VE[playerid][Inv][7]);
            SQL::WriteInt(handle, "Slot9", VE[playerid][Inv][8]);
            SQL::WriteInt(handle, "Slot10", VE[playerid][Inv][9]);
            SQL::WriteInt(handle, "Slot11", VE[playerid][Inv][10]);
            SQL::WriteInt(handle, "Slot12", VE[playerid][Inv][11]);
            SQL::WriteInt(handle, "Slot13", VE[playerid][Inv][12]);
            SQL::WriteInt(handle, "Slot14", VE[playerid][Inv][13]);
            SQL::WriteInt(handle, "Slot15", VE[playerid][Inv][14]);
            SQL::WriteInt(handle, "Usos1", Objetos[VE[playerid][Inv][0]][usos]);
            SQL::WriteInt(handle, "Usos2", Objetos[VE[playerid][Inv][1]][usos]);
            SQL::WriteInt(handle, "Usos3", Objetos[VE[playerid][Inv][2]][usos]);
            SQL::WriteInt(handle, "Usos4", Objetos[VE[playerid][Inv][3]][usos]);
            SQL::WriteInt(handle, "Usos5", Objetos[VE[playerid][Inv][4]][usos]);
            SQL::WriteInt(handle, "Usos6", Objetos[VE[playerid][Inv][5]][usos]);
            SQL::WriteInt(handle, "Usos7", Objetos[VE[playerid][Inv][6]][usos]);
            SQL::WriteInt(handle, "Usos8", Objetos[VE[playerid][Inv][7]][usos]);
            SQL::WriteInt(handle, "Usos9", Objetos[VE[playerid][Inv][8]][usos]);
            SQL::WriteInt(handle, "Usos10", Objetos[VE[playerid][Inv][9]][usos]);
            SQL::WriteInt(handle, "Usos11", Objetos[VE[playerid][Inv][10]][usos]);
            SQL::WriteInt(handle, "Usos12", Objetos[VE[playerid][Inv][11]][usos]);
            SQL::WriteInt(handle, "Usos13", Objetos[VE[playerid][Inv][12]][usos]);
            SQL::WriteInt(handle, "Usos14", Objetos[VE[playerid][Inv][13]][usos]);
            SQL::WriteInt(handle, "Usos15", Objetos[VE[playerid][Inv][14]][usos]);
            SQL::Close(handle);
        }
        CuentaInfo[playerid][Logeado] = 0;
    }
    return 1;
}
stock CargarDataPlayer(playerid)
{
    new handle = SQL::Open(SQL::READ, "usuarios", "ID", CuentaInfo[playerid][ID]);
    SQL::ReadInt(handle, "Edad", CuentaInfo[playerid][Edad]);
    SQL::ReadInt(handle, "Skin", CuentaInfo[playerid][Skin]);
    SQL::ReadFloat(handle, "PosX", CuentaInfo[playerid][PosX]);
    SQL::ReadFloat(handle, "PosY", CuentaInfo[playerid][PosY]);
    SQL::ReadFloat(handle, "PosZ", CuentaInfo[playerid][PosZ]);
    SQL::ReadFloat(handle, "Sed", Necesidades[playerid][N_Hambre]);
    SQL::ReadFloat(handle, "Hambre", Necesidades[playerid][N_Hambre]);
    SQL::Close(handle);
    SetPlayerPos(playerid, CuentaInfo[playerid][PosX], CuentaInfo[playerid][PosY], CuentaInfo[playerid][PosZ]);
    SetPlayerSkin(playerid, CuentaInfo[playerid][Skin]);
    SetPlayerProgressBarValue(playerid, PlayerProgressBar[playerid][1], Necesidades[playerid][N_Hambre]);
    SetPlayerProgressBarValue(playerid, PlayerProgressBar[playerid][0], Necesidades[playerid][N_Sed]);
    new handle2 = SQL::Open(SQL::READ, "inventario", "ID", CuentaInfo[playerid][ID]);
    SQL::ReadInt(handle2, "Slot1", VE[playerid][Inv][0]);
    SQL::ReadInt(handle2, "Slot2", VE[playerid][Inv][1]);
    SQL::ReadInt(handle2, "Slot3", VE[playerid][Inv][2]);
    SQL::ReadInt(handle2, "Slot4", VE[playerid][Inv][3]);
    SQL::ReadInt(handle2, "Slot5", VE[playerid][Inv][4]);
    SQL::ReadInt(handle2, "Slot6", VE[playerid][Inv][5]);
    SQL::ReadInt(handle2, "Slot7", VE[playerid][Inv][6]);
    SQL::ReadInt(handle2, "Slot8", VE[playerid][Inv][7]);
    SQL::ReadInt(handle2, "Slot9", VE[playerid][Inv][8]);
    SQL::ReadInt(handle2, "Slot10", VE[playerid][Inv][9]);
    SQL::ReadInt(handle2, "Slot11", VE[playerid][Inv][10]);
    SQL::ReadInt(handle2, "Slot12", VE[playerid][Inv][11]);
    SQL::ReadInt(handle2, "Slot13", VE[playerid][Inv][12]);
    SQL::ReadInt(handle2, "Slot14", VE[playerid][Inv][13]);
    SQL::ReadInt(handle2, "Slot15", VE[playerid][Inv][14]);
    SQL::ReadInt(handle2, "Usos1", Objetos[VE[playerid][Inv][0]][usos]);
    SQL::ReadInt(handle2, "Usos2", Objetos[VE[playerid][Inv][1]][usos]);
    SQL::ReadInt(handle2, "Usos3", Objetos[VE[playerid][Inv][2]][usos]);
    SQL::ReadInt(handle2, "Usos4", Objetos[VE[playerid][Inv][3]][usos]);
    SQL::ReadInt(handle2, "Usos5", Objetos[VE[playerid][Inv][4]][usos]);
    SQL::ReadInt(handle2, "Usos6", Objetos[VE[playerid][Inv][5]][usos]);
    SQL::ReadInt(handle2, "Usos7", Objetos[VE[playerid][Inv][6]][usos]);
    SQL::ReadInt(handle2, "Usos8", Objetos[VE[playerid][Inv][7]][usos]);
    SQL::ReadInt(handle2, "Usos9", Objetos[VE[playerid][Inv][8]][usos]);
    SQL::ReadInt(handle2, "Usos10", Objetos[VE[playerid][Inv][9]][usos]);
    SQL::ReadInt(handle2, "Usos11", Objetos[VE[playerid][Inv][10]][usos]);
    SQL::ReadInt(handle2, "Usos12", Objetos[VE[playerid][Inv][11]][usos]);
    SQL::ReadInt(handle2, "Usos13", Objetos[VE[playerid][Inv][12]][usos]);
    SQL::ReadInt(handle2, "Usos14", Objetos[VE[playerid][Inv][13]][usos]);
    SQL::ReadInt(handle2, "Usos15", Objetos[VE[playerid][Inv][14]][usos]);
    SQL::Close(handle2);
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