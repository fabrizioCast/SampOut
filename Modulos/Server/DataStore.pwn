enum JugadorInfo{
    ID,
    Nombre[25],
    Password[65],
    Email[250],
    Edad,
    Logeado,
    Float:PosX,
    Float:PosY,
    Float:PosZ,
    Skin,
};
new CuentaInfo[MAX_PLAYERS][JugadorInfo];

//------------------VARIABLES REGISTRO/LOGEO-----------------//
enum{
    d_registro,
    d_pass,
    d_email,
    d_edad,
    d_login,
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