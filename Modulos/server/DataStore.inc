enum JugadorInfo{
    ID,
    Nombre[25],
    Password[65],
    Email[250],
    Edad, //Edad OOC (opcional)
    Logeado,
    Genero, // 0 masculino 1 femenino
    Tono, // de 0 a 3 mas ocuro el 3 mas blanco el 0
    EdadPJ, //Edad IC
    Float:PosX,
    Float:PosY,
    Float:PosZ,
    Skin,
    Float:Vida,
    Coin
};
new CuentaInfo[MAX_PLAYERS][JugadorInfo];

//------------------VARIABLES REGISTRO/LOGEO-----------------//
enum{
    d_registro,
    d_pass,
    d_email,
    d_edad,
    d_login,
    raza_d,
    tirar_dialog,
    d_panel,
    d_clan_colores,
    d_clan_territorio,
    d_clan_info,
    d_clan_reclutar,
    d_clan_expulsar,
    d_clan_crear,
    d_objetos_crear,
    d_objetos_pass,
    d_objetos_pass_1
};
new Text:ClaveTD[15];
new PlayerText:PlayerTD[MAX_PLAYERS][2];
new PlayerText:EmailTD2[MAX_PLAYERS][2];
new PlayerText:EdadTD2[MAX_PLAYERS][2];
new PlayerText:LoginTD2[MAX_PLAYERS][2];
new Text:EmailTD[15];
new Text:LoginTD[15];
new Text:EdadTD[15];
new Pasos[MAX_PLAYERS];
new MaxIntentos[MAX_PLAYERS];
new PassYes[MAX_PLAYERS];

//______________MYSQL_____________//
new MySQL:Database;


#define HOLDING(%0) \
    ((newkeys & (%0)) == (%0))

// PRESSED(keys)
#define PRESSED(%0) \
    (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))


NombreJugador(playerid)
{
    new Nombrer[24];
    GetPlayerName(playerid,Nombrer,24);
    new N[24];
    strmid(N,Nombrer,0,strlen(Nombrer),24);
    for(new i = 0; i < MAX_PLAYER_NAME; i++)
    {
        if (N[i] == '_') N[i] = ' ';
    }
    return N;
}

stock ret_pName(playerid)
{
    new name[24];
    GetPlayerName(playerid, name, sizeof(name));
    return name;
}

new temp_timer[MAX_PLAYERS];
stock CongelarPlayer(playerid, time)
{
    KillTimer(temp_timer[playerid]);
    TogglePlayerControllable(playerid, 0);
    temp_timer[playerid] = SetTimerEx("CongelarPlayerT", time, false, "d", playerid);
    return 1;
}

forward CongelarPlayerT(playerid);
public CongelarPlayerT(playerid)
{
    TogglePlayerControllable(playerid, 1);
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

IsNumeric(const string[])
{
    return !sscanf(string, "{d}");
}

stock HexToRGBA(colour, &r, &g, &b, &a) //By Betamaster
{
    r = (colour >> 24) & 0xFF;
    g = (colour >> 16) & 0xFF;
    b = (colour >> 8) & 0xFF;
    a = colour & 0xFF;
}

stock RGBAToHex(r, g, b, a) //By Betamaster
{
    return (r<<24 | g<<16 | b<<8 | a);
}


#include "../Modulos/server/doors.inc"