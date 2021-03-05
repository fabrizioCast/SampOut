#define MAX_OBJETOS_SERVER 1000
#define DISTANCIA_DIBUJADO_OBJ 300
/*
    FUNCIONES (O_Funcion)
    0: Nada
    1: Reja
    2: Puerta
*/

new ObjetosSelection_Puertas = mS_INVALID_LISTID;

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
    Float:O_Rot[3]
};
new Objetosc[MAX_OBJETOS_SERVER][ObjetosIC];


///_____________Temp____________//
new Objeto_Temp_Create[MAX_PLAYERS];