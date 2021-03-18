#define MAX_OBJETOS_SERVER 1000
#define DISTANCIA_DIBUJADO_OBJ 300
/*
    FUNCIONES (O_Funcion)
    0: Nada
    1: Reja
    2: Puerta
*/

new ObjetosSelection_Puertas = mS_INVALID_LISTID;
new ObjetosSelection_Vallas = mS_INVALID_LISTID;
new ObjetosSelection_Paredes = mS_INVALID_LISTID;
new ObjetosSelection_Almacenes = mS_INVALID_LISTID;

enum ObjetosIC{
    O_ID,
    O_ModelID,
    O_Owner[MAX_PLAYER_NAME],
    O_gPassword,
    O_Password[5],
    O_Create,
    Float:O_Vida,
    O_Funcion,
    Text3D:O_Text,
    bool:O_Abierto,
    Float:O_Pos[3],
    Float:O_Rot[3],
    O_gCofre,
    O_Cofre[12],
    O_CofreModelID[12]
};
new Objetosc[MAX_OBJETOS_SERVER][ObjetosIC];


new temp_modelid_c[MAX_PLAYERS];

///_____________Temp____________//
new Objeto_Temp_Create[MAX_PLAYERS];


//_________FUNCS____________//
Float:WeaponDamageObject(weaponid)
{
    if(weaponid == 22 || weaponid == 23)
    {
        return 0.50;
    }
    else if(weaponid == 24 || weaponid == 25)
    {
        return 1.25;
    }
    else if(weaponid == 27)
    {
        return 1.70;
    }
    else if(weaponid == 29)
    {
        return 0.70;
    }
    else if(weaponid == 30 || weaponid == 31)
    {
        return 1.30;
    }
    else if(weaponid == 33 || weaponid == 34)
    {
        return 1.50;
    }
    else if(weaponid == 38)
    {
        return 1.20;
    }
    return 0.0;
}

//____________C O F R E_______________//
new Text:cofretds[3];
new PlayerText:cofretd[MAX_PLAYERS][12];
new bool:inmenucofre[MAX_PLAYERS];
