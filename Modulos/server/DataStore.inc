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

enum temp{
    cooldown,
    bool:puedeconstruir
};
new TempPlayer[MAX_PLAYERS][temp];

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
    d_objetos_pass_1,
    d_objetos_confirm
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


//__________________________NECESIDADES VARIABLES___________________//
new PlayerBar:PlayerProgressBar[MAX_PLAYERS][2];

enum necesidades{
    Float:N_Hambre,
    Float:N_Sed,
    TimmerNecesidades
};
new Necesidades[MAX_PLAYERS][necesidades];

//______________MYSQL_____________//
new MySQL:Database;


#define HOLDING(%0) \
    ((newkeys & (%0)) == (%0))

// PRESSED(keys)
#define PRESSED(%0) \
    (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

//       VARIABLES     //
#include "../Modulos/inventario/InvData.inc"
#include "../Modulos/grupos/DataGroups.inc"
#include "../Modulos/construccion/DataConstruction.inc"


//______EXTRAS_________//
#include "../Modulos/server/doors.inc"
#include "../Modulos/Server/stocks.inc"

//_______COMANDOS__________//
#include "../Modulos/player/Commands.inc"