#include  <YSI\y_hooks>
#define MAX_OBJETOS_WORDl 1000
#define MAX_INV 12
#define MAX_ARMAS 4

#define IZQ 0
#define DER 1

#define NADA            0
#define HAMBURGUESA     1
#define BURRITO         2
#define JUGO_NARANJA    3
#define CAFE            4
#define PAN             5
#define REFRESCO        6
#define PIZZA           7
#define MANZANA         8
#define CERVEZA         9
#define GUN9MM          10
#define DEAGLE          11
#define MP5             12
#define M4              13
#define AMMO            14


//Variables 
new Text:inventari[7];
new PlayerText:PlayerTDI[MAX_PLAYERS][12];
new PlayerBar:PlayerProgressBar[MAX_PLAYERS][2];
new PlayerText:names[MAX_PLAYERS];


new bool:Puedetirar[MAX_PLAYERS];
//Objetos
new O_infloor;

enum Inventory{
    bool:inmenu,
    Inv[12],
    Mano[2],
    Selected,
    weapon[4],
    ammo[4]
};
new VE[MAX_PLAYERS][Inventory];

enum ObjetosEnum{
    itemid,
    model,
    name[25],
    bool:tirar,
    Float:paramsizq[9],
    Float:paramsder[9]
};
enum ObjetosWordl{
    itemid,
    modelid,
    Text3D:dtext,
    objeto,
    balas,
    Float:pos[3],
};
new ObjetosPiso[MAX_OBJETOS_WORDl][ObjetosWordl];

new Objetos[][ObjetosEnum] =
{
    {0, 19382, "Nada", false, {0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000}},
    {1, 2703, "Hamburguesa", true, {0.068999, 0.030000, -0.032000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000}, {0.051999, 0.014999, 0.012000, -13.499937, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000}},
    {2, 2769, "Burrito", true, {0.071999, 0.045999, -0.019999, 0.000000, -115.900077, 26.700002, 0.842999, 0.759000, 0.666999}, {0.074999, 0.029999, -0.016999, 0.000000, -86.600021, 168.099975, 0.842999, 0.759000, 0.666999}},
    {3, 19563, "Jugo de Naranja", true, {0.155999, 0.028000, 0.008000, 0.000000, -107.200096, 26.700002, 0.678000, 0.759000, 0.514000}, {0.150999, 0.035000, 0.043999, 0.000000, -107.200096, 26.700002, 0.678000, 0.759000, 0.514000}},
    {4, 19835, "Cafe", true, {0.092999, 0.036999, -0.013999, 0.000000, -107.200096, 26.700002, 0.678000, 0.759000, 0.643999}, {0.074999, 0.036999, 0.025000, 0.000000, -107.200096, 26.700002, 0.678000, 0.759000, 0.643999}},
    {5, 19883, "Pan", true, {0.092999, 0.036999, -0.013999, 0.000000, -107.200096, 26.700002, 0.678000, 0.759000, 0.643999}, {0.074999, 0.036999, 0.025000, 0.000000, -107.200096, 26.700002, 0.678000, 0.759000, 0.643999}},
    {6, 2647, "Refresco", true, {0.071999, 0.045999, -0.019999, 0.000000, -115.900077, 26.700002, 0.842999, 0.759000, 0.666999}, {0.062999, 0.065999, -0.002999, 0.000000, -86.600021, -166.700027, 0.842999, 0.759000, 0.666999}},
    {7, 2702, "Pizza", true, {0.139999, 0.021999, -0.037999, -134.800033, 179.399978, 87.200019, 0.678000, 0.759000, 0.643999}, {0.122999, 0.031999, 0.029000, 85.499954, -172.700057, 87.200019, 0.678000, 0.759000, 0.643999}},
    {8, 19575, "Manzana", true, {0.089999, 0.032999, -0.032999, 0.000000, -89.200004, 4.800000, 1.000000, 1.000000, 1.000000}, {0.064999, 0.032999, 0.020000, 0.000000, -89.200004, 4.800000, 1.000000, 1.000000, 1.000000}},
    {9, 1544, "Cerveza", true, {0.0, 0.0, 0.0, 0.000000, 0.0000, 0.000000, 1.000000, 1.000000, 1.000000}, {0.064999, 0.032999, 0.020000, 0.000000, -89.200004, 4.800000, 1.000000, 1.000000, 1.000000}},
    {10, 346, "Pistola 9mm", true, {0.056999, 0.051000, -0.023000, 161.199935, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000}, {0.049999, -0.000999, 0.005999, 4.099944, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000}},
    {11, 348, "Desert Eagle", true, {0.005999, 0.047999, -0.004000, 161.199935, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000}, {-0.012000, 0.004999, -0.011000, 4.299956, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000}},
    {12, 353, "MP5", true, {0.022000, 0.050999, 0.013000, 164.699996, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000}, {0.003999, 0.004999, 0.004000, -3.200038, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000}},
    {13, 356, "M4", true, {0.032999, 0.031000, -0.043999, 172.299972, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000}, {0.018999, 0.003999, 0.036000, -4.300058, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000}},
    {14, 3013, "Caja de balas", true, {0.064999, 0.032999, 0.020000, 0.000000, -89.200004, 4.800000, 1.000000, 0.600000, 0.600000}, {0.064999, 0.032999, 0.020000, 0.000000, -89.200004, 4.800000, 1.000000, 0.600000, 0.600000}}
};

hook:Inv_OnGameModeInit()
{
    O_infloor = 0;
    CargarInventario();
    return 1;
}
hook:In_OnPlayerConnect(playerid)
{
    CargarPlayerInventario(playerid);
    PlayerTextDrawSetString(playerid, names[playerid], NombreJugador(playerid));
    return 1;
}
hook:Inv_OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if(clickedid == inventari[3])
    {
        for(new i; i < 7; i++)
        {
            TextDrawHideForPlayer(playerid, inventari[i]);
        }
        for(new i; i < 12; i++)
        {
            PlayerTextDrawHide(playerid, PlayerTDI[playerid][i]);
        }
        PlayerTextDrawHide(playerid, names[playerid]);
        CancelSelectTextDraw(playerid);
        VE[playerid][inmenu] = false;
    }
    return 1;
}
CMD:inventario(playerid)
{
    ActualizarInventario(playerid);
    for(new i; i < 7; i++)
    {
        TextDrawShowForPlayer(playerid, inventari[i]);
    }
    for(new i; i < 12; i++)
    {
        PlayerTextDrawShow(playerid, PlayerTDI[playerid][i]);
    }
    PlayerTextDrawShow(playerid, names[playerid]);
    SelectTextDraw(playerid,  0xFFFFFFAA);
    VE[playerid][inmenu] = true;
    return 1;
}

stock ActualizarInventario(playerid)
{
    for(new i; i < 12; i++)
    {
        PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][i], Objetos[VE[playerid][Inv][i]][model]);
    }
    return 1;
}
stock LimpiarInv(playerid)
{
    for(new i; i<12; i++)
    {
        VE[playerid][Inv][i] = NADA;
    }
    VE[playerid][Mano][DER] = NADA;
    VE[playerid][Mano][IZQ] = NADA;
}

forward SetPlayerHandObject(playerid, hand, object);
public SetPlayerHandObject(playerid, hand, object)
{
    if(object == 0) return 0;
    if(hand == 0)
    {
        SetPlayerAttachedObject(playerid, DER, Objetos[object][model], 6, Objetos[object][paramsder][0], Objetos[object][paramsder][1], Objetos[object][paramsder][2], Objetos[object][paramsder][3], Objetos[object][paramsder][4], Objetos[object][paramsder][5], Objetos[object][paramsder][6], Objetos[object][paramsder][7], Objetos[object][paramsder][8]);
        return 1;
    } 
    else 
    {
        SetPlayerAttachedObject(playerid, IZQ, Objetos[object][model], 5, Objetos[object][paramsizq][0], Objetos[object][paramsizq][1], Objetos[object][paramsizq][2], Objetos[object][paramsizq][3], Objetos[object][paramsizq][4], Objetos[object][paramsizq][5], Objetos[object][paramsizq][6], Objetos[object][paramsizq][7], Objetos[object][paramsizq][8]);
    }
    return 1;
}

stock GiveItem(playerid, itemidd)
{
    new bool:found = false;
    new bool:found2 = false;
    if(IsWeapon(itemidd))
    {
        for(new d; d<MAX_ARMAS; d++)
        {
            if(VE[playerid][weapon][d] == NADA)
            {
                VE[playerid][weapon][d] = GetWeaponID(Objetos[itemidd][model]);
                VE[playerid][ammo][d] = 0;
                found2 = true;
                break;
            }
        }
        if(!found2)
        {
            SendClientMessage(playerid, -1, "{FF0000}No puedes llevar mas armas!");
            return 0;
        }
    }
    for(new i; i<MAX_INV; i++)
        {
            if(VE[playerid][Inv][i] == 0)
            {
                VE[playerid][Inv][i] = itemidd;
                new string[128];
                format(string, sizeof(string), "Objeto: %s", Objetos[VE[playerid][Inv][i]][model]);
                SendClientMessage(playerid, -1, string);
                found = true;
                break;
            }
        }
    if(!found)
    {
        SendClientMessage(playerid, -1, "{FF0000} Inventario lleno!");
        return 0;
    } else return 1;
}

stock DropObjeto(playerid, item, ammod = 0)
{
    if(O_infloor > MAX_OBJETOS_WORDl-2) return SendClientMessage(playerid, -1, "Error: Maximo de objetos alcanzado.");
    {
        new Float:Poso[3];
        GetPlayerPos(playerid, Poso[0], Poso[1], Poso[2]);
        ObjetosPiso[O_infloor][itemid] = item;
        ObjetosPiso[O_infloor][modelid] = Objetos[item][model];
        if(IsWeapon(item)) ObjetosPiso[O_infloor][balas] = ammod;
        ObjetosPiso[O_infloor][pos][0] = Poso[0];
        ObjetosPiso[O_infloor][pos][1] = Poso[1];
        ObjetosPiso[O_infloor][pos][2] = Poso[2];
        ObjetosPiso[O_infloor][objeto] = CreateObject(ObjetosPiso[O_infloor][modelid], Poso[0], Poso[1], Poso[2]-0.95, 5.0, 0, 0, 30.0);
        new string3d[60];
        format(string3d, sizeof(string3d), "{FFA600} Objeto: '%s'", Objetos[item][name]);
        ObjetosPiso[O_infloor][dtext] = Create3DTextLabel(string3d, -1, Poso[0], Poso[1], Poso[2]-0.95, 8.0, 0, 0);
        Puedetirar[playerid] = true;
        if(O_infloor == MAX_OBJETOS_WORDl-2) O_infloor = 0;
        else O_infloor += 1;
    }
    return 1;
}

stock PickObject(playerid)
{
    if(GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK) return SendClientMessage(playerid, -1, "Debes agacharte para recoger un objeto!");
    if(VE[playerid][Mano][DER] != NADA && VE[playerid][Mano][IZQ] != NADA) return SendClientMessage(playerid, -1, "Tienes las manos ocupadas!");
    for(new i; i<O_infloor; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 1.5, ObjetosPiso[i][pos][0], ObjetosPiso[i][pos][1], ObjetosPiso[i][pos][2]))
        {
            if(IsWeapon(i) && VE[playerid][Mano][DER] != NADA) return SendClientMessage(playerid, -1, "{FF0000}Debes tener la mano derecha vacia para recoger esto!");
            if(IsWeapon(i) && VE[playerid][weapon][0] != NADA && VE[playerid][weapon][1] != NADA && VE[playerid][weapon][2] != NADA && VE[playerid][weapon][3] != NADA) return SendClientMessage(playerid, -1, "{FF0000}No puedes llevar mas armas!");
            if(IsWeapon(i))
            {
                for(new d; d<MAX_ARMAS; d++)
                {
                    if(VE[playerid][weapon][d] == NADA)
                    {
                        VE[playerid][weapon][d] = GetWeaponID(Objetos[i][model]);
                        VE[playerid][ammo][d] = ObjetosPiso[i][balas];
                        break;
                    }
                }
            }
            if(VE[playerid][Mano][DER] == NADA)
            {
                VE[playerid][Mano][DER] = ObjetosPiso[i][itemid];
                SetPlayerHandObject(playerid, DER, VE[playerid][Mano][DER]);
            } 
            else 
            {
                VE[playerid][Mano][IZQ] = ObjetosPiso[i][itemid];
                SetPlayerHandObject(playerid, IZQ, VE[playerid][Mano][IZQ]);
            }
            DestroyFloorObject(i);
            break;
        } else continue;
    }
    return 1;
}

stock DestroyFloorObject(i)
{
    DestroyObject(ObjetosPiso[i][objeto]);
    Delete3DTextLabel(ObjetosPiso[i][dtext]);
    ObjetosPiso[i][itemid] = 0;
    ObjetosPiso[i][modelid] = 0;
    ObjetosPiso[i][pos][0] = 0.0;
    ObjetosPiso[i][pos][1] = 0.0;
    ObjetosPiso[i][pos][2] = 0.0;
    ObjetosPiso[i][balas] = 0;
    return 1;
}

CMD:darobjeto(playerid, params[])
{
    if(sscanf(params, "d", params[1])) return SendClientMessage(playerid, -1, "Error /dar [ID]");
    {
        if(params[1] <= 14)
        {
            GiveItem(playerid, params[1]);
        }
        else return SendClientMessage(playerid, -1, "ID invalida");
    }
    return 1;
}
CMD:dropear(playerid, params[])
{
    new itemdrop;
    if(sscanf(params, "d", itemdrop)) return SendClientMessage(playerid, -1, "Error /dropear [ID]");
    {
        for(new i; i<MAX_INV; i++)
        {
            if(VE[playerid][Inv][i] == itemdrop)
            {
                DropObjeto(playerid, itemdrop);
                if(Puedetirar[playerid] == true)
                {
                    VE[playerid][Inv][i] = NADA;
                }
                break;
            }
            else return SendClientMessage(playerid, -1, "No tienes ese objeto");
        }
    }
    return 1;
}
CMD:recoger(playerid)
{
    PickObject(playerid);
    return 1;
}
stock IsWeapon(weaponid)
{
    if(weaponid == 10 || weaponid == 11 || weaponid == 12 || weaponid == 13) return true;
    else return false;
}

stock GetWeaponID(weaponmodel)
{
    switch(weaponmodel)
    {
        case 22: return 346;
        case 24: return 348;
        case 29: return 353;
        case 31: return 356;
        case 346: return 22;
        case 348: return 24;
        case 353: return 29;
        case 356: return 31;
    }
    return 1;
}






stock CargarPlayerInventario(playerid)
{
    names[playerid] = CreatePlayerTextDraw(playerid, 322.000000, 105.000000, "Sleek Wayne");
    PlayerTextDrawFont(playerid, names[playerid], 1);
    PlayerTextDrawLetterSize(playerid, names[playerid], 0.354166, 1.800001);
    PlayerTextDrawTextSize(playerid, names[playerid], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, names[playerid], 0);
    PlayerTextDrawSetShadow(playerid, names[playerid], 0);
    PlayerTextDrawAlignment(playerid, names[playerid], 2);
    PlayerTextDrawColor(playerid, names[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, names[playerid], 255);
    PlayerTextDrawBoxColor(playerid, names[playerid], 135);
    PlayerTextDrawUseBox(playerid, names[playerid], 0);
    PlayerTextDrawSetProportional(playerid, names[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, names[playerid], 0);

    PlayerTDI[playerid][0] = CreatePlayerTextDraw(playerid, 213.000000, 127.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][0], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][0], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][0], 52.500000, 62.000000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][0], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][0], 125);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][0], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][0], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][0], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][0], 2663);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][0], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][0], 1, 1);

    PlayerTDI[playerid][1] = CreatePlayerTextDraw(playerid, 213.000000, 192.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][1], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][1], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][1], 52.500000, 62.000000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][1], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][1], 125);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][1], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][1], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][1], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][1], 2663);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][1], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][1], 1, 1);

    PlayerTDI[playerid][2] = CreatePlayerTextDraw(playerid, 213.000000, 256.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][2], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][2], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][2], 52.500000, 62.000000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][2], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][2], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][2], 125);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][2], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][2], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][2], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][2], 2663);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][2], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][2], 1, 1);

    PlayerTDI[playerid][3] = CreatePlayerTextDraw(playerid, 267.000000, 127.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][3], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][3], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][3], 52.500000, 62.000000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][3], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][3], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][3], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][3], 125);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][3], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][3], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][3], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][3], 2663);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][3], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][3], 1, 1);

    PlayerTDI[playerid][4] = CreatePlayerTextDraw(playerid, 322.000000, 127.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][4], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][4], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][4], 52.500000, 62.000000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][4], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][4], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][4], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][4], 125);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][4], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][4], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][4], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][4], 2663);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][4], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][4], 1, 1);

    PlayerTDI[playerid][5] = CreatePlayerTextDraw(playerid, 377.000000, 127.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][5], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][5], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][5], 52.500000, 62.000000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][5], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][5], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][5], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][5], 125);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][5], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][5], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][5], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][5], 2663);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][5], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][5], 1, 1);

    PlayerTDI[playerid][6] = CreatePlayerTextDraw(playerid, 267.000000, 192.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][6], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][6], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][6], 52.500000, 62.000000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][6], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][6], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][6], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][6], 125);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][6], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][6], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][6], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][6], 2663);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][6], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][6], 1, 1);

    PlayerTDI[playerid][7] = CreatePlayerTextDraw(playerid, 267.000000, 256.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][7], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][7], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][7], 52.500000, 62.000000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][7], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][7], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][7], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][7], 125);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][7], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][7], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][7], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][7], 2663);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][7], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][7], 1, 1);

    PlayerTDI[playerid][8] = CreatePlayerTextDraw(playerid, 322.000000, 192.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][8], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][8], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][8], 52.500000, 62.000000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][8], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][8], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][8], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][8], 125);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][8], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][8], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][8], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][8], 2663);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][8], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][8], 1, 1);

    PlayerTDI[playerid][9] = CreatePlayerTextDraw(playerid, 322.000000, 256.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][9], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][9], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][9], 52.500000, 62.000000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][9], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][9], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][9], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][9], 125);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][9], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][9], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][9], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][9], 2663);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][9], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][9], 1, 1);

    PlayerTDI[playerid][10] = CreatePlayerTextDraw(playerid, 377.000000, 192.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][10], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][10], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][10], 52.500000, 62.000000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][10], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][10], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][10], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][10], 125);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][10], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][10], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][10], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][10], 2663);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][10], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][10], 1, 1);

    PlayerTDI[playerid][11] = CreatePlayerTextDraw(playerid, 377.000000, 256.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][11], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][11], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][11], 52.500000, 62.000000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][11], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][11], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][11], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][11], 125);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][11], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][11], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][11], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][11], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][11], 2663);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][11], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][11], 1, 1);
}
stock CargarInventario()
{
    inventari[0] = TextDrawCreate(322.000000, 106.000000, "_");
    TextDrawFont(inventari[0], 1);
    TextDrawLetterSize(inventari[0], 0.600000, 28.049949);
    TextDrawTextSize(inventari[0], 298.500000, 224.500000);
    TextDrawSetOutline(inventari[0], 1);
    TextDrawSetShadow(inventari[0], 0);
    TextDrawAlignment(inventari[0], 2);
    TextDrawColor(inventari[0], -1);
    TextDrawBackgroundColor(inventari[0], 255);
    TextDrawBoxColor(inventari[0], 235802367);
    TextDrawUseBox(inventari[0], 1);
    TextDrawSetProportional(inventari[0], 1);
    TextDrawSetSelectable(inventari[0], 0);

    inventari[1] = TextDrawCreate(322.000000, 327.000000, "_");
    TextDrawFont(inventari[1], 1);
    TextDrawLetterSize(inventari[1], 0.600000, 2.999948);
    TextDrawTextSize(inventari[1], 298.500000, 221.000000);
    TextDrawSetOutline(inventari[1], 1);
    TextDrawSetShadow(inventari[1], 0);
    TextDrawAlignment(inventari[1], 2);
    TextDrawColor(inventari[1], -1);
    TextDrawBackgroundColor(inventari[1], 255);
    TextDrawBoxColor(inventari[1], 125);
    TextDrawUseBox(inventari[1], 1);
    TextDrawSetProportional(inventari[1], 1);
    TextDrawSetSelectable(inventari[1], 0);

    inventari[2] = TextDrawCreate(322.000000, 125.000000, "_");
    TextDrawFont(inventari[2], 1);
    TextDrawLetterSize(inventari[2], 0.600000, 21.349918);
    TextDrawTextSize(inventari[2], 298.500000, 218.500000);
    TextDrawSetOutline(inventari[2], 1);
    TextDrawSetShadow(inventari[2], 0);
    TextDrawAlignment(inventari[2], 2);
    TextDrawColor(inventari[2], -1);
    TextDrawBackgroundColor(inventari[2], 255);
    TextDrawBoxColor(inventari[2], 125);
    TextDrawUseBox(inventari[2], 1);
    TextDrawSetProportional(inventari[2], 1);
    TextDrawSetSelectable(inventari[2], 0);

    inventari[3] = TextDrawCreate(425.000000, 103.000000, "X");
    TextDrawFont(inventari[3], 1);
    TextDrawLetterSize(inventari[3], 0.474999, 1.700001);
    TextDrawTextSize(inventari[3], 298.500000, 75.000000);
    TextDrawSetOutline(inventari[3], 0);
    TextDrawSetShadow(inventari[3], 0);
    TextDrawAlignment(inventari[3], 2);
    TextDrawColor(inventari[3], 255);
    TextDrawBackgroundColor(inventari[3], 255);
    TextDrawBoxColor(inventari[3], 135);
    TextDrawUseBox(inventari[3], 0);
    TextDrawSetProportional(inventari[3], 1);
    TextDrawSetSelectable(inventari[3], 1);

    inventari[4] = TextDrawCreate(425.000000, 106.000000, "_");
    TextDrawFont(inventari[4], 1);
    TextDrawLetterSize(inventari[4], 0.304165, 1.000002);
    TextDrawTextSize(inventari[4], 298.500000, 17.500000);
    TextDrawSetOutline(inventari[4], 1);
    TextDrawSetShadow(inventari[4], 0);
    TextDrawAlignment(inventari[4], 2);
    TextDrawColor(inventari[4], -1);
    TextDrawBackgroundColor(inventari[4], 255);
    TextDrawBoxColor(inventari[4], -16777081);
    TextDrawUseBox(inventari[4], 1);
    TextDrawSetProportional(inventari[4], 1);
    TextDrawSetSelectable(inventari[4], 0);

    inventari[5] = TextDrawCreate(218.000000, 331.000000, "HUD:radar_datefood");
    TextDrawFont(inventari[5], 4);
    TextDrawLetterSize(inventari[5], 0.600000, 2.000000);
    TextDrawTextSize(inventari[5], 17.000000, 17.000000);
    TextDrawSetOutline(inventari[5], 1);
    TextDrawSetShadow(inventari[5], 0);
    TextDrawAlignment(inventari[5], 1);
    TextDrawColor(inventari[5], -1);
    TextDrawBackgroundColor(inventari[5], 255);
    TextDrawBoxColor(inventari[5], 50);
    TextDrawUseBox(inventari[5], 1);
    TextDrawSetProportional(inventari[5], 1);
    TextDrawSetSelectable(inventari[5], 0);

    inventari[6] = TextDrawCreate(328.000000, 332.000000, "HUD:radar_centre");
    TextDrawFont(inventari[6], 4);
    TextDrawLetterSize(inventari[6], 0.600000, 2.000000);
    TextDrawTextSize(inventari[6], 17.000000, 17.000000);
    TextDrawSetOutline(inventari[6], 1);
    TextDrawSetShadow(inventari[6], 0);
    TextDrawAlignment(inventari[6], 1);
    TextDrawColor(inventari[6], 16777215);
    TextDrawBackgroundColor(inventari[6], 255);
    TextDrawBoxColor(inventari[6], 50);
    TextDrawUseBox(inventari[6], 1);
    TextDrawSetProportional(inventari[6], 1);
    TextDrawSetSelectable(inventari[6], 0);
}