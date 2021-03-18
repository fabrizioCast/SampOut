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
#include <mSelection>
#include <gmenu>

//------------------DEFINES-----------------//
#undef MAX_PLAYERS
#define MAX_PLAYERS 100
#define NOMBRE_SV "SampOut 0.1"

//------------------M O D U L O S-----------------//
#include "../Modulos/server/DataStore.inc"

#include "../Modulos/grupos/groups.inc"

#include "../Modulos/necesidades/needs.inc"

#include "../Modulos/construccion/construction.inc"

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

//-----------------------------------------------------------//
forward KickearR(playerid);
forward GuardarTodo();
forward MostrarInicio(playerid);

//-------------------------PUBLIC´S-----------------------//
public OnGameModeInit()
{
    CargarServer();
    printf("Hola pete");
    return 1;
}


public OnPlayerConnect(playerid)
{ 
    CargarTds(playerid);
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
        else if(VE[playerid][inmenu])
        {
            closeInv(playerid);
            return 1;
        }
        else if(temp_inmenu_carac[playerid])
        {
            SelectTextDraw(playerid, 0xFF6C00FF);
        }
        else if(inmenucofre[playerid])
        {
            OcultarCofre(playerid);
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

public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
    printf("[Log]: El jugador %s uso el comando /%s %s", ret_pName(playerid), cmd, params);
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


CMD:cool(playerid)
{
    new str[128];
    format(str, 128, "{FFC900}• {ffffff}Debes esperar {C62D2D}%ds {ffffff}para volver a usar este comando", TempPlayer[playerid][cooldown] - gettime());
    if(TempPlayer[playerid][cooldown] > gettime()) return SendClientMessage(playerid, -1, str);

    GivePlayerMoney(playerid, 500);
    TempPlayer[playerid][cooldown] = gettime() + 30;
    return 1;
}


stock CargarServer()
{
    SQL::Connect(mysql_host, mysql_user, mysql_pass, mysql_database);
    CargarHospital();
    CargarMapeoCara();
    CargarClave();
    CargarEmail();
    CargarEdad();
    CargarLogin();
    CargarInventario();
    CargarRadar();
    CargarLogo();
    CargarRecursos();
    CargarGrupos();
    RespawnObjetos();
    CargarTerritorios();
    SetTimer("GuardarTodo", 900000, true);
    SetGameModeText(NOMBRE_SV);
    LabelsDoors();
    SetWeather(20);
    DisableInteriorEnterExits();
    CargarApariencia();
    TextDrawCofre();
    CargarObjetosc();
    O_infloor = 0;
    ObjetosSelection_Puertas = LoadModelSelectionMenu("Objetos_Puertas.txt");
    ObjetosSelection_Vallas = LoadModelSelectionMenu("Objetos_Vallas.txt");
    ObjetosSelection_Paredes = LoadModelSelectionMenu("Objetos_Paredes.txt");
    ObjetosSelection_Almacenes = LoadModelSelectionMenu("Objetos_Almacenes.txt");
}

//-----------------------FUNCIONES MYSQL-----------------------//
public KickearR(playerid)
{
    Kick(playerid);
    return 1;
}

public GuardarTodo()
{
    GuardarGrupos();
    GuardarObjetosc();
}


public MostrarInicio(playerid)
{
    InterpolateCameraPos(playerid, 355.597930, -1715.070434, 105.277404, 483.929016, -1476.202514, 97.490631, 30000);
    InterpolateCameraLookAt(playerid, 355.481750, -1710.357788, 103.610702, 479.389251, -1477.755615, 96.084091, 30000);
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
        SendClientMessage(playerid, -1, "{FF0000}Error: {ffffff}Nombre de usuario no valido. (NOMBRE_APELLIDO)");
        SetTimerEx("KickearR", 1000, false, "d", playerid);
    }
    return 1;
}