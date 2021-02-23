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
#include "../Modulos/grupos/groups.inc"
#include "../Modulos/necesidades/needs.inc"
#include "../Modulos/inventario/inventory.inc"
#include "../Modulos/tutorial/characterization.inc"
#include "../Modulos/Server/registry.inc"
#include "../Modulos/loot/OinFloor.inc"
#include "../Modulos/recursos/resources.inc"


//____________-MAPEOS____________________//
#include "../Modulos/Mapeos/maps.inc"

//____________TextDraws____________________//
#include "../Modulos/server/hud.inc"

//------------------MYSQL-----------------//
#define mysql_host "localhost"
#define mysql_user "root"
#define mysql_pass ""
#define mysql_database "SampOut"

//----------------------INICIO GAMEMODE---------------------//
main ()
{
    printf("\n<-         SampOut RolePlay         ->\n");
}

//-------------------------PUBLIC´S-----------------------//
public OnGameModeInit()
{
    //_______________MYSQL___________________//
    SQL::Connect(mysql_host, mysql_user, mysql_pass, mysql_database);
    //______Mapeos_______//
    CargarHospital();
    CargarMapeoCara();
    //____TextDraw______//
    CargarClave();
    CargarEmail();
    CargarEdad();
    CargarLogin();
    CargarInventario();
    CargarRadar();
    CargarLogo();
    //______Mysql_______//
    CargarRecursos();
    CargarGrupos();
    //______Otros______//
    SetGameModeText(NOMBRE_SV);
    LabelsDoors();
    SetWeather(20);
    DisableInteriorEnterExits();
    CargarApariencia();
    O_infloor = 0;
    //_____Objetos_______//
    RespawnObjetos();
    return 1;
}

public OnPlayerConnect(playerid)
{ 
    CrearTDDeSIFP(playerid);
    CrearTDShowObject(playerid);
    CrearNoti(playerid);
    CargarTDProgress(playerid);
    CargarBotonesApariencia(playerid);
    CargarPlayerInventario(playerid);
    PlayerTextDrawSetString(playerid, names[playerid], NombreJugador(playerid));
    CargarClave2(playerid);
    CargarEmail2(playerid);
    CargarEdad2(playerid);
    CargarLogin2(playerid);
    MostrarLogo(playerid);
    MostrarRadar(playerid);
    clearChat(playerid);
    SendClientMessage(playerid, -1, "{FFC900}• {ffffff}Cargando datos...");
    SetTimerEx("MostrarInicio", 3000, false, "d", playerid);
    SetSpawnInfo(playerid, 0, 0, 2349.4131,-700.9865,117.3094, 0, 0, 0,0, 0, 0, 0);
    SpawnPlayer(playerid);
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    SaveAccount(playerid);
    KillTimer(Radio[playerid][RadioTimer]);
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

public OnPlayerText(playerid, text[])
{
    if(CuentaInfo[playerid][Logeado] == 0)
    {
        return 0;
    }
    else if(text[0] == '!' && Radio[playerid][GetRadio] == 1 && Radio[playerid][Baterias] > 0)
    {
        new str[128];
        format(str, sizeof(str), "{1D4C7D}[Frecuencia General] {ffffff}%s dice: %s", NombreJugador(playerid), text[1]);
        RadioSupervivientes(str);
        return 0;
    }
    else if(text[0] == '#' && ClanPlayer[playerid][Cp_Grupo] == 1)
    {
        RadioClanes(playerid, text[1]);
        return 0;
    }
    else
    {
        new string[128];
        format(string, sizeof(string), "%s dice: %s",NombreJugador(playerid), text);
        ProxDetector(5.0, playerid, string,-1,-1,-1,-1,-1); 
        return 0;
    }
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
            SQL::WriteFloat(handle, "Hambre", Necesidades[playerid][N_Hambre]);
            SQL::WriteFloat(handle, "Sed", Necesidades[playerid][N_Sed]);
            SQL::WriteFloat(handle, "Vida", CuentaInfo[playerid][Vida]);
            SQL::WriteInt(handle, "Coin", CuentaInfo[playerid][Coin]);
            SQL::WriteInt(handle, "GrupoID", ClanPlayer[playerid][Cp_ID]);
            SQL::WriteInt(handle, "Grupo", ClanPlayer[playerid][Cp_Grupo]);
            SQL::WriteInt(handle, "GrupoLider", ClanPlayer[playerid][Cp_Lider]);
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
        if(SQL::RowExists("objetosplayer", "ID", CuentaInfo[playerid][ID]))
        {
            new handle3 = SQL::Open(SQL::UPDATE, "objetosplayer", "ID", CuentaInfo[playerid][ID]);
            SQL::WriteInt(handle3, "ID",CuentaInfo[playerid][ID]);
            SQL::WriteString(handle3, "Nombre", ret_pName(playerid));
            SQL::WriteInt(handle3, "GetRadio", Radio[playerid][GetRadio]);
            SQL::WriteInt(handle3, "BateriasRadio", Radio[playerid][Baterias]);
            SQL::Close(handle3);
        }
        CuentaInfo[playerid][Logeado] = 0;
        PassYes[playerid] = 0;
        Pasos[playerid] = 0;
        MaxIntentos[playerid] = 0;
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
    SQL::ReadFloat(handle, "Vida", CuentaInfo[playerid][Vida]);
    SQL::ReadInt(handle, "Coin", CuentaInfo[playerid][Coin]);
    SQL::ReadInt(handle, "GrupoID", ClanPlayer[playerid][Cp_ID]);
    SQL::ReadInt(handle, "Grupo", ClanPlayer[playerid][Cp_Grupo]);
    SQL::ReadInt(handle, "GrupoLider", ClanPlayer[playerid][Cp_Lider]);
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
    new handle3 = SQL::Open(SQL::READ, "objetosplayer", "ID", CuentaInfo[playerid][ID]);
    SQL::ReadInt(handle3, "GetRadio", Radio[playerid][GetRadio]);
    SQL::ReadInt(handle3, "BateriasRadio", Radio[playerid][Baterias]);
    SQL::Close(handle3);
    //____{extras}____//
    timerobjetos[playerid] = SetTimerEx("MostrarOb", 4000, true, "d", playerid);
    Radio[playerid][RadioTimer] = SetTimerEx("BateriasRadio", 1200000, false, "d", playerid);
    return 1;
}

forward MostrarInicio(playerid);
public MostrarInicio(playerid)
{
    InterpolateCameraPos(playerid, 355.597930, -1715.070434, 105.277404, 483.929016, -1476.202514, 97.490631, 30000);
    InterpolateCameraLookAt(playerid, 355.481750, -1710.357788, 103.610702, 479.389251, -1477.755615, 96.084091, 30000);
    SetSpawnInfo(playerid, 0, 0, 2349.4131,-700.9865,117.3094, 0, 0, 0,0, 0, 0, 0);
    if(strfind(GetName(playerid),"_", false) != -1 || !strcmp(GetName(playerid), "Sleek", false, 5))
    {
        clearChat(playerid);
        if(SQL::RowExistsEx("usuarios", "Nombre", ret_pName(playerid)))
        {
            clearChat(playerid);
            new handle = SQL::OpenEx(SQL::READ, "usuarios", "Nombre", ret_pName(playerid));
            SQL::ReadInt(handle, "ID", CuentaInfo[playerid][ID]);
			SQL::ReadString(handle, "Password", CuentaInfo[playerid][Password], 65);
            SQL::Close(handle);
            for(new i; i <11; i++)
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
    }
    else
    {
        clearChat(playerid);
        SendClientMessage(playerid, -1, "{FF0000}Error: {ffffff}Nombre de usuario no valido. (NOMBRE_APELLIDO)");
        SetTimerEx("KickearR", 1000, false, "d", playerid);
    }
    return 1;
}