/*
    Inventario by Sleek
    ---------------------
    Textdraw: Sleek
    Progrmacion: Sleek
    Servidor: SAMP-Out
    ---------------------
*/


//__________________I N C L U D E S___________________//

#include  <YSI\y_hooks>
#include "../Modulos/inventario/oFunctions.inc"



//________________________C A L L  B A C K S____________________//


forward MostrarOb(playerid);
public MostrarOb(playerid)
{
    ObjetosTimer[playerid] = true;
}


hook Inv_OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if(clickedid == inventari[8])
    {
        closeInv(playerid);
    }
    return 1;
}


hook Inv_OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    if(playertextid == tirard[playerid])
    {
        if(InvSelect[playerid] != NADA)
        {
            for(new i; i<MAX_INV; i++)
            {
                if(VE[playerid][Inv][i] == InvSelect[playerid])
                {
                    if(VE[playerid][usos][VE[playerid][Inv][i]] == 1)
                    {
                        VE[playerid][Inv][i] = NADA;
                        VE[playerid][usos][ VE[playerid][Inv][ VE[playerid][Inv][i]] ] = 0;
                        SendClientMessageEx(playerid, -1, "Uso: %d", VE[playerid][usos][ VE[playerid][Inv][ VE[playerid][Inv][i]] ] );
                        DropObjeto(playerid, InvSelect[playerid], 1);
                        closeInv(playerid);
                        OpenInv(playerid);
                        break;
                    }
                    else
                    {
                        ShowPlayerDialog(playerid, tirar_dialog, DIALOG_STYLE_INPUT, "Tirar Objeto", "Ingresa la cantidad que deseas tirar", "Aceptar", "Salir");
                        temp_tirar[playerid] = i;
                        SendClientMessageEx(playerid, -1, "Inv:%d Tirar:%d Total: %d", VE[playerid][Inv][i], temp_tirar[playerid], VE[playerid][Inv][temp_tirar[playerid]]);
                        break;
                    }
                }
            }
        }
    }
    if(playertextid == usard[playerid])
    {
        if(VE[playerid][Mano][DER] != NADA)
        {
            SaveObject(playerid, VE[playerid][Mano][DER]);
            OpenInv(playerid);
        }
        else if(VE[playerid][Mano][IZQ] != NADA)
        {
            SaveObject(playerid, VE[playerid][Mano][IZQ]);
            OpenInv(playerid);
        }
    }
    if(playertextid == sacard[playerid])
    {
        if(InvSelect[playerid] != NADA)
        {
            TakeObject(playerid, InvSelect[playerid], 1);
            OpenInv(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][0])
    {
        InvSelect[playerid] = VE[playerid][Inv][0];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][1])
    {
        InvSelect[playerid] = VE[playerid][Inv][1];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][2])
    {
        InvSelect[playerid] = VE[playerid][Inv][2];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][3])
    {
        InvSelect[playerid] = VE[playerid][Inv][3];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][4])
    {
        InvSelect[playerid] = VE[playerid][Inv][4];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][4])
    {
        InvSelect[playerid] = VE[playerid][Inv][4];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][5])
    {
        InvSelect[playerid] = VE[playerid][Inv][5];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][6])
    {
        InvSelect[playerid] = VE[playerid][Inv][6];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][7])
    {
        InvSelect[playerid] = VE[playerid][Inv][7];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][8])
    {
        InvSelect[playerid] = VE[playerid][Inv][8];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][9])
    {
        InvSelect[playerid] = VE[playerid][Inv][9];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][10])
    {
        InvSelect[playerid] = VE[playerid][Inv][10];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][11])
    {
        InvSelect[playerid] = VE[playerid][Inv][11];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][12])
    {
        InvSelect[playerid] = VE[playerid][Inv][12];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][13])
    {
        InvSelect[playerid] = VE[playerid][Inv][13];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    if(playertextid == PlayerTDI[playerid][14])
    {
        InvSelect[playerid] = VE[playerid][Inv][14];
        if(InvSelect[playerid] != NADA)
        {
            ActualizarSelected(playerid);
        }
    }
    return 1;
}
hook Inv_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == tirar_dialog)
    {
        if(response)
        {
            SendClientMessageEx(playerid, -1, "Tirar:%d", VE[playerid][usos][temp_tirar[playerid]]);
            new temp_cantidad_tirar = strval(inputtext);
            if(temp_cantidad_tirar > 0)
            {
                if(temp_cantidad_tirar <= VE[playerid][usos][ VE[playerid][Inv][temp_tirar[playerid]] ])
                {
                    VE[playerid][usos][ VE[playerid][Inv][temp_tirar[playerid]] ] -= temp_cantidad_tirar;
                    if(VE[playerid][usos][ VE[playerid][Inv][temp_tirar[playerid]] ] == 0)
                    {
                        VE[playerid][Inv][temp_tirar[playerid]] = NADA;
                        SendClientMessageEx(playerid, -1, "Tirar:%d", temp_tirar[playerid]);
                    }
                    DropObjeto(playerid, InvSelect[playerid], temp_cantidad_tirar);
                    closeInv(playerid);
                    OpenInv(playerid);
                } else return ShowInfoForPlayer(playerid, "~r~No tienes esa cantidad!", 4000);
            } else return ShowInfoForPlayer(playerid, "~r~Cantidad incorrecta!", 4000);
        }
    }
    return 1;
}
hook Inv_OnPlayerUpdate(playerid)
{
    if(ObjetosTimer[playerid] == true)
    {
        for(new i; i<O_infloor; i++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 1.5, ObjetosPiso[i][pos][0], ObjetosPiso[i][pos][1], ObjetosPiso[i][pos][2]))
            {
                ShowInfoPickUp(playerid, 4000);
                ObjetosTimer[playerid] = false;
                break;
            }
        }
    }
}

//_______________________C O M A N D O S____________________//
CMD:inventario(playerid)
{
    OpenInv(playerid);
    return 1;
}


CMD:limpiarinv(playerid, params[])
{
    new idi;
    if(sscanf(params, "u", idi)) return SendClientMessage(playerid, -1, "/limpiarinv [ID]");
    {
        LimpiarInv(idi);
    }
    return 1;
}


CMD:darobjeto(playerid, params[2])
{
    if(sscanf(params, "dd", params[0], params[1])) return SendClientMessage(playerid, -1, "Error /darobjeto [ID] [Cantidad]");
    {
        if(params[0] <= MAX_OBJETOS)
        {
            GiveItemAdmin(playerid, params[0], params[1]);
        }
        else SendClientMessage(playerid, -1, "ID invalida");
    }
    return 1;
}


//____________________F U N C I O N E S_____________________//
stock GiveItem(playerid, itemidd, cantidad)
{
    new bool:found = false;
    for(new i; i<MAX_INV; i++)
    {
        if(VE[playerid][Inv][i] == itemidd)
        {
            VE[playerid][usos][VE[playerid][Inv][i]] += cantidad;
            found = true;
            break;
        }
        else if(VE[playerid][Inv][i] == 0)
        {
            VE[playerid][Inv][i] = itemidd;
            VE[playerid][usos][VE[playerid][Inv][i]] += cantidad;
            found = true;
            break;
        }
    }
    for(new i; i<MAX_INV; i++)
    {
      if(VE[playerid][Inv][i] == itemidd && VE[playerid][usos][VE[playerid][Inv][i]] == 0)
      {
            VE[playerid][Inv][i] = NADA;
            break;
      }  
    }
    if(!found)
    {
        ShowInfoForPlayer(playerid, "~r~[Error]: ~w~Inventario lleno", 3000);
        return 0;
    } else return 1;
}

stock GiveItemAdmin(playerid, itemidd, cantidad)
{
    new bool:found = false;
    for(new i; i<MAX_INV; i++)
        {
            if(VE[playerid][Inv][i] == itemidd)
            {
                VE[playerid][usos][VE[playerid][Inv][i]] += cantidad;
                new mensaje[128];
                format(mensaje, sizeof(mensaje), "Un administrador te dio el objeto: {154265}%s (%d)", Objetos[VE[playerid][Inv][i]][name], VE[playerid][usos][VE[playerid][Inv][i]]);
                SendClientMessage(playerid, -1, mensaje);
                found = true;
                break;
            }
            else if(VE[playerid][Inv][i] == 0)
            {
                VE[playerid][Inv][i] = itemidd;
                VE[playerid][usos][VE[playerid][Inv][i]] += cantidad-1;
                new mensaje[128];
                format(mensaje, sizeof(mensaje), "Un administrador te dio el objeto: {154265}%s (%d)", Objetos[VE[playerid][Inv][i]][name], VE[playerid][usos][VE[playerid][Inv][i]]);
                SendClientMessage(playerid, -1, mensaje);
                found = true;
                break;
            }
        }
    if(!found)
    {
        ShowInfoForPlayer(playerid, "~r~[Error]: ~w~Inventario lleno", 3000);
        return 0;
    } else return 1;
}


stock DropObjeto(playerid, item, usost)
{
    if(O_infloor > MAX_OBJETOS_WORDl-2) return ShowInfoForPlayer(playerid, "~r~[Error]: ~w~Limite de objetos en el mundo.", 3000);
    {
        new Float:Poso[3];
        GetPlayerPos(playerid, Poso[0], Poso[1], Poso[2]);
        ObjetosPiso[O_infloor][itemid] = item;
        ObjetosPiso[O_infloor][modelid] = Objetos[item][model];
        ObjetosPiso[O_infloor][pos][0] = Poso[0];
        ObjetosPiso[O_infloor][pos][1] = Poso[1];
        ObjetosPiso[O_infloor][pos][2] = Poso[2];
        ObjetosPiso[O_infloor][usos] = usost;
        ObjetosPiso[O_infloor][objeto] = CreateObject(ObjetosPiso[O_infloor][modelid], Poso[0], Poso[1], Poso[2]-0.95, 5.0, 0, 0, 30.0);
        new string3d[60];
        format(string3d, sizeof(string3d), "{154265}%s (%d)", Objetos[item][name], usost);
        ObjetosPiso[O_infloor][dtext] = Create3DTextLabel(string3d, -1, Poso[0], Poso[1], Poso[2]-0.95, 8.0, 0, 0);
        Puedetirar[playerid] = true;
        if(O_infloor == MAX_OBJETOS_WORDl-2) O_infloor = 0;
        else O_infloor += 1;
    }
    return 1;
}


stock PickObject(playerid)
{
    for(new i; i<O_infloor; i++)
    {
        if(VE[playerid][Mano][DER] != NADA && VE[playerid][Mano][IZQ] != NADA) return ShowInfoForPlayer(playerid, "~r~[Error]: ~w~Tienes las manos ocupadas.", 3000);
        if(IsPlayerInRangeOfPoint(playerid, 1.5, ObjetosPiso[i][pos][0], ObjetosPiso[i][pos][1], ObjetosPiso[i][pos][2]))
        {
            GiveItem(playerid, ObjetosPiso[i][itemid], ObjetosPiso[i][usos]);
            DestroyFloorObject(i);
            ApplyAnimation(playerid, "BOMBER", "BOM_PLANT", 4.1, 0, 0, 0, 0, 0);
            break;
        } else continue;
    }
    return 1;
}


stock TakeObject(playerid, item, cantidad)
{
    if(VE[playerid][Mano][DER] != NADA && VE[playerid][Mano][IZQ] != NADA) return ShowInfoForPlayer(playerid, "~r~[Error]: ~w~Tienes las manos ocupadas", 3000);
    for(new i; i<MAX_INV; i++)
    {
        if(VE[playerid][Inv][i] == item)
        {
            VE[playerid][usos][VE[playerid][Inv][i]] -= cantidad;
            //Objetos[VE[playerid][Inv][i]][usos] -= cantidad;
            if(VE[playerid][usos][VE[playerid][Inv][i]] <= 0)
            {
                VE[playerid][Inv][i] = NADA;
            }
            break;
        }
    }
    if(VE[playerid][Mano][DER] == NADA)
    {
        SetPlayerHandObject(playerid, DER, item);
        VE[playerid][Mano][DER] = item;
        VE[playerid][usosder] = cantidad;
        return 1;
    } 
    else if(VE[playerid][Mano][IZQ] == NADA)
    {
        SetPlayerHandObject(playerid, IZQ, item);
        VE[playerid][Mano][IZQ] = item;
        VE[playerid][usosizq] = cantidad;
        return 1;
    }
    closeInv(playerid);
    OpenInv(playerid);
    return 1;
}


stock SaveObject(playerid, item)
{
    if(GiveItem(playerid, item, 1) == 1)
    {
        if(VE[playerid][Mano][IZQ] == item)
        {
            RemovePlayerAttachedObject(playerid, IZQ);
            VE[playerid][Mano][IZQ] = NADA;
            return 1;
        } 
        else 
        {
            RemovePlayerAttachedObject(playerid, DER);
            VE[playerid][Mano][DER] = NADA;
            return 1;
        }
    } else return 0;
}


stock ChangeHand(playerid)
{
    if(VE[playerid][Mano][DER] == NADA && VE[playerid][Mano][IZQ] == NADA) return 0;
    new newder, newizq;
    newder = VE[playerid][Mano][IZQ];
    newizq = VE[playerid][Mano][DER];
    VE[playerid][Mano][DER] = newder;
    VE[playerid][Mano][IZQ] = newizq;
    RemovePlayerAttachedObject(playerid, IZQ);
    RemovePlayerAttachedObject(playerid, DER);
    if(VE[playerid][Mano][DER] != NADA) SetPlayerHandObject(playerid, DER, VE[playerid][Mano][DER]);
    if(VE[playerid][Mano][IZQ] != NADA) SetPlayerHandObject(playerid, IZQ, VE[playerid][Mano][IZQ]);
    return 1;
}


stock DestroyItemHand(playerid, hand)
{
    VE[playerid][Mano][hand] = NADA;
    if(hand == DER)
    {
        RemovePlayerAttachedObject(playerid, DER);
    } else RemovePlayerAttachedObject(playerid, IZQ);
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


stock OpenInv(playerid)
{
    ActualizarInventario(playerid);
    for(new i; i < 14; i++)
    {
        TextDrawShowForPlayer(playerid, inventari[i]);
    }
    for(new i; i < 15; i++)
    {
        PlayerTextDrawShow(playerid, PlayerTDI[playerid][i]);
    }
    ActualizarSelected(playerid);
    InvSelect[playerid] = NADA;
    PlayerTextDrawSetString(playerid, names[playerid], NombreJugador(playerid));
    PlayerTextDrawSetPreviewModel(playerid, showskin[playerid], GetPlayerSkin(playerid));
    PlayerTextDrawShow(playerid, names[playerid]);
    PlayerTextDrawShow(playerid, usard[playerid]);
    PlayerTextDrawShow(playerid, tirard[playerid]);
    PlayerTextDrawShow(playerid, sacard[playerid]);
    PlayerTextDrawShow(playerid, showskin[playerid]);
    SelectTextDraw(playerid,  0xFFFFFFAA);
    ShowPlayerProgressBar(playerid, PlayerProgressBar[playerid][0]);
    ShowPlayerProgressBar(playerid, PlayerProgressBar[playerid][1]);
    VE[playerid][inmenu] = true;
    return 1;
}


stock ActualizarInventario(playerid)
{
    for(new i; i < 15; i++)
    {
        PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][i], Objetos[VE[playerid][Inv][i]][model]);
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


stock LimpiarInv(playerid)
{
    for(new i; i<14; i++)
    {
        VE[playerid][Inv][i] = NADA;
    }
    VE[playerid][Mano][DER] = NADA;
    VE[playerid][Mano][IZQ] = NADA;
}


stock ActualizarSelected(playerid)
{
    PlayerTextDrawShow(playerid, showpreview[playerid]);
    PlayerTextDrawShow(playerid, infocantidad[playerid]);
    PlayerTextDrawShow(playerid, infodes[playerid]);
    PlayerTextDrawShow(playerid, infoobjeto[playerid]);
    PlayerTextDrawSetPreviewModel(playerid, showpreview[playerid], Objetos[InvSelect[playerid]][model]);
    new showusos[128];
    valstr(showusos, VE[playerid][usos][InvSelect[playerid]]);
    PlayerTextDrawSetString(playerid, infoobjeto[playerid], Objetos[InvSelect[playerid]][name]);
    PlayerTextDrawSetString(playerid, infocantidad[playerid], showusos);
    PlayerTextDrawSetString(playerid, infodes[playerid], Objetos[InvSelect[playerid]][Descripcion]);
    PlayerTextDrawHide(playerid, showpreview[playerid]);
    PlayerTextDrawShow(playerid, showpreview[playerid]);
    return 1;
}

stock closeInv(playerid)
{
    for(new i; i < 14; i++)
    {
        TextDrawHideForPlayer(playerid, inventari[i]);
    }
    for(new i; i < 15; i++)
    {
        PlayerTextDrawHide(playerid, PlayerTDI[playerid][i]);
    }
    PlayerTextDrawHide(playerid, names[playerid]);
    PlayerTextDrawHide(playerid, usard[playerid]);
    PlayerTextDrawHide(playerid, tirard[playerid]);
    PlayerTextDrawHide(playerid, sacard[playerid]);
    PlayerTextDrawHide(playerid, showpreview[playerid]);
    PlayerTextDrawHide(playerid, infocantidad[playerid]);
    PlayerTextDrawHide(playerid, infodes[playerid]);
    PlayerTextDrawHide(playerid, infoobjeto[playerid]);
    PlayerTextDrawHide(playerid, showskin[playerid]);
    HidePlayerProgressBar(playerid, PlayerProgressBar[playerid][0]);
    HidePlayerProgressBar(playerid, PlayerProgressBar[playerid][1]);
    CancelSelectTextDraw(playerid);
    VE[playerid][inmenu] = false;
    InvSelect[playerid] = NADA;
    return 1;
}


//_________________TEXTDRAW INVENTARIO_____________________//
stock CargarPlayerInventario(playerid)
{
    infoobjeto[playerid] = CreatePlayerTextDraw(playerid, 387.000000, 293.000000, "Radio");
    PlayerTextDrawFont(playerid, infoobjeto[playerid], 1);
    PlayerTextDrawLetterSize(playerid, infoobjeto[playerid], 0.166666, 1.650002);
    PlayerTextDrawTextSize(playerid, infoobjeto[playerid], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, infoobjeto[playerid], 0);
    PlayerTextDrawSetShadow(playerid, infoobjeto[playerid], 0);
    PlayerTextDrawAlignment(playerid, infoobjeto[playerid], 2);
    PlayerTextDrawColor(playerid, infoobjeto[playerid], -764862721);
    PlayerTextDrawBackgroundColor(playerid, infoobjeto[playerid], 255);
    PlayerTextDrawBoxColor(playerid, infoobjeto[playerid], 135);
    PlayerTextDrawUseBox(playerid, infoobjeto[playerid], 0);
    PlayerTextDrawSetProportional(playerid, infoobjeto[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, infoobjeto[playerid], 0);

    names[playerid] = CreatePlayerTextDraw(playerid, 191.000000, 108.000000, "Nombre Apellido");
    PlayerTextDrawFont(playerid, names[playerid], 1);
    PlayerTextDrawLetterSize(playerid, names[playerid], 0.224996, 2.000000);
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

    PlayerTDI[playerid][0] = CreatePlayerTextDraw(playerid, 268.000000, 116.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][0], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][0], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][0], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][0], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][0], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][0], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][0], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][0], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][0], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][0], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][0], 1, 1);

    PlayerTDI[playerid][1] = CreatePlayerTextDraw(playerid, 268.000000, 169.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][1], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][1], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][1], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][1], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][1], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][1], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][1], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][1], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][1], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][1], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][1], 1, 1);

    PlayerTDI[playerid][2] = CreatePlayerTextDraw(playerid, 268.000000, 222.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][2], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][2], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][2], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][2], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][2], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][2], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][2], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][2], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][2], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][2], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][2], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][2], 1, 1);

    PlayerTDI[playerid][3] = CreatePlayerTextDraw(playerid, 318.000000, 116.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][3], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][3], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][3], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][3], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][3], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][3], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][3], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][3], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][3], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][3], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][3], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][3], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][3], 1, 1);

    PlayerTDI[playerid][4] = CreatePlayerTextDraw(playerid, 368.000000, 116.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][4], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][4], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][4], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][4], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][4], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][4], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][4], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][4], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][4], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][4], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][4], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][4], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][4], 1, 1);

    PlayerTDI[playerid][5] = CreatePlayerTextDraw(playerid, 418.000000, 116.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][5], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][5], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][5], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][5], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][5], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][5], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][5], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][5], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][5], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][5], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][5], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][5], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][5], 1, 1);

    PlayerTDI[playerid][6] = CreatePlayerTextDraw(playerid, 468.000000, 116.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][6], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][6], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][6], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][6], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][6], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][6], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][6], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][6], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][6], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][6], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][6], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][6], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][6], 1, 1);

    PlayerTDI[playerid][7] = CreatePlayerTextDraw(playerid, 318.000000, 222.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][7], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][7], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][7], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][7], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][7], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][7], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][7], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][7], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][7], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][7], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][7], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][7], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][7], 1, 1);

    PlayerTDI[playerid][8] = CreatePlayerTextDraw(playerid, 318.000000, 169.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][8], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][8], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][8], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][8], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][8], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][8], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][8], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][8], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][8], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][8], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][8], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][8], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][8], 1, 1);

    PlayerTDI[playerid][9] = CreatePlayerTextDraw(playerid, 368.000000, 169.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][9], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][9], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][9], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][9], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][9], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][9], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][9], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][9], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][9], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][9], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][9], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][9], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][9], 1, 1);

    PlayerTDI[playerid][10] = CreatePlayerTextDraw(playerid, 418.000000, 169.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][10], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][10], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][10], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][10], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][10], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][10], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][10], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][10], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][10], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][10], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][10], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][10], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][10], 1, 1);

    PlayerTDI[playerid][11] = CreatePlayerTextDraw(playerid, 468.000000, 169.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][11], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][11], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][11], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][11], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][11], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][11], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][11], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][11], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][11], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][11], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][11], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][11], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][11], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][11], 1, 1);

    PlayerTDI[playerid][12] = CreatePlayerTextDraw(playerid, 368.000000, 222.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][12], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][12], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][12], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][12], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][12], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][12], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][12], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][12], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][12], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][12], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][12], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][12], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][12], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][12], 1, 1);

    PlayerTDI[playerid][13] = CreatePlayerTextDraw(playerid, 418.000000, 222.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][13], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][13], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][13], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][13], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][13], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][13], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][13], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][13], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][13], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][13], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][13], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][13], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][13], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][13], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][13], 1, 1);

    PlayerTDI[playerid][14] = CreatePlayerTextDraw(playerid, 468.000000, 222.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, PlayerTDI[playerid][14], 5);
    PlayerTextDrawLetterSize(playerid, PlayerTDI[playerid][14], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, PlayerTDI[playerid][14], 48.000000, 50.500000);
    PlayerTextDrawSetOutline(playerid, PlayerTDI[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTDI[playerid][14], 0);
    PlayerTextDrawAlignment(playerid, PlayerTDI[playerid][14], 1);
    PlayerTextDrawColor(playerid, PlayerTDI[playerid][14], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTDI[playerid][14], 370480639);
    PlayerTextDrawBoxColor(playerid, PlayerTDI[playerid][14], 255);
    PlayerTextDrawUseBox(playerid, PlayerTDI[playerid][14], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTDI[playerid][14], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTDI[playerid][14], 1);
    PlayerTextDrawSetPreviewModel(playerid, PlayerTDI[playerid][14], 2769);
    PlayerTextDrawSetPreviewRot(playerid, PlayerTDI[playerid][14], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PlayerTDI[playerid][14], 1, 1);

    showpreview[playerid] = CreatePlayerTextDraw(playerid, 280.000000, 295.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, showpreview[playerid], 5);
    PlayerTextDrawLetterSize(playerid, showpreview[playerid], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, showpreview[playerid], 56.000000, 62.000000);
    PlayerTextDrawSetOutline(playerid, showpreview[playerid], 0);
    PlayerTextDrawSetShadow(playerid, showpreview[playerid], 0);
    PlayerTextDrawAlignment(playerid, showpreview[playerid], 1);
    PlayerTextDrawColor(playerid, showpreview[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, showpreview[playerid], 370480639);
    PlayerTextDrawBoxColor(playerid, showpreview[playerid], 255);
    PlayerTextDrawUseBox(playerid, showpreview[playerid], 0);
    PlayerTextDrawSetProportional(playerid, showpreview[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, showpreview[playerid], 1);
    PlayerTextDrawSetPreviewModel(playerid, showpreview[playerid], 2769);
    PlayerTextDrawSetPreviewRot(playerid, showpreview[playerid], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, showpreview[playerid], 1, 1);

    tirard[playerid] = CreatePlayerTextDraw(playerid, 311.000000, 379.000000, "Tirar");
    PlayerTextDrawFont(playerid, tirard[playerid], 1);
    PlayerTextDrawLetterSize(playerid, tirard[playerid], 0.345831, 1.950003);
    PlayerTextDrawTextSize(playerid, tirard[playerid], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, tirard[playerid], 0);
    PlayerTextDrawSetShadow(playerid, tirard[playerid], 0);
    PlayerTextDrawAlignment(playerid, tirard[playerid], 2);
    PlayerTextDrawColor(playerid, tirard[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, tirard[playerid], 255);
    PlayerTextDrawBoxColor(playerid, tirard[playerid], 135);
    PlayerTextDrawUseBox(playerid, tirard[playerid], 0);
    PlayerTextDrawSetProportional(playerid, tirard[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, tirard[playerid], 1);

    sacard[playerid] = CreatePlayerTextDraw(playerid, 392.000000, 379.000000, "Sacar");
    PlayerTextDrawFont(playerid, sacard[playerid], 1);
    PlayerTextDrawLetterSize(playerid, sacard[playerid], 0.345831, 1.950003);
    PlayerTextDrawTextSize(playerid, sacard[playerid], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, sacard[playerid], 0);
    PlayerTextDrawSetShadow(playerid, sacard[playerid], 0);
    PlayerTextDrawAlignment(playerid, sacard[playerid], 2);
    PlayerTextDrawColor(playerid, sacard[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, sacard[playerid], 255);
    PlayerTextDrawBoxColor(playerid, sacard[playerid], 135);
    PlayerTextDrawUseBox(playerid, sacard[playerid], 0);
    PlayerTextDrawSetProportional(playerid, sacard[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, sacard[playerid], 1);

    usard[playerid] = CreatePlayerTextDraw(playerid, 475.000000, 379.000000, "Guardar");
    PlayerTextDrawFont(playerid, usard[playerid], 1);
    PlayerTextDrawLetterSize(playerid, usard[playerid], 0.345831, 1.950003);
    PlayerTextDrawTextSize(playerid, usard[playerid], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, usard[playerid], 0);
    PlayerTextDrawSetShadow(playerid, usard[playerid], 0);
    PlayerTextDrawAlignment(playerid, usard[playerid], 2);
    PlayerTextDrawColor(playerid, usard[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, usard[playerid], 255);
    PlayerTextDrawBoxColor(playerid, usard[playerid], 135);
    PlayerTextDrawUseBox(playerid, usard[playerid], 0);
    PlayerTextDrawSetProportional(playerid, usard[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, usard[playerid], 1);

    infocantidad[playerid] = CreatePlayerTextDraw(playerid, 387.000000, 310.000000, "100");
    PlayerTextDrawFont(playerid, infocantidad[playerid], 1);
    PlayerTextDrawLetterSize(playerid, infocantidad[playerid], 0.166666, 1.650002);
    PlayerTextDrawTextSize(playerid, infocantidad[playerid], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, infocantidad[playerid], 0);
    PlayerTextDrawSetShadow(playerid, infocantidad[playerid], 0);
    PlayerTextDrawAlignment(playerid, infocantidad[playerid], 2);
    PlayerTextDrawColor(playerid, infocantidad[playerid], -764862721);
    PlayerTextDrawBackgroundColor(playerid, infocantidad[playerid], 255);
    PlayerTextDrawBoxColor(playerid, infocantidad[playerid], 135);
    PlayerTextDrawUseBox(playerid, infocantidad[playerid], 0);
    PlayerTextDrawSetProportional(playerid, infocantidad[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, infocantidad[playerid], 0);

    infodes[playerid] = CreatePlayerTextDraw(playerid, 416.000000, 329.000000, "Permite comunicarse con otros jugadores");
    PlayerTextDrawFont(playerid, infodes[playerid], 1);
    PlayerTextDrawLetterSize(playerid, infodes[playerid], 0.166666, 1.650002);
    PlayerTextDrawTextSize(playerid, infodes[playerid], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, infodes[playerid], 0);
    PlayerTextDrawSetShadow(playerid, infodes[playerid], 0);
    PlayerTextDrawAlignment(playerid, infodes[playerid], 2);
    PlayerTextDrawColor(playerid, infodes[playerid], -764862721);
    PlayerTextDrawBackgroundColor(playerid, infodes[playerid], 255);
    PlayerTextDrawBoxColor(playerid, infodes[playerid], 135);
    PlayerTextDrawUseBox(playerid, infodes[playerid], 0);
    PlayerTextDrawSetProportional(playerid, infodes[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, infodes[playerid], 0);

    showskin[playerid] = CreatePlayerTextDraw(playerid, 134.000000, 143.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, showskin[playerid], 5);
    PlayerTextDrawLetterSize(playerid, showskin[playerid], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, showskin[playerid], 115.500000, 151.500000);
    PlayerTextDrawSetOutline(playerid, showskin[playerid], 0);
    PlayerTextDrawSetShadow(playerid, showskin[playerid], 0);
    PlayerTextDrawAlignment(playerid, showskin[playerid], 1);
    PlayerTextDrawColor(playerid, showskin[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, showskin[playerid], 0);
    PlayerTextDrawBoxColor(playerid, showskin[playerid], 255);
    PlayerTextDrawUseBox(playerid, showskin[playerid], 0);
    PlayerTextDrawSetProportional(playerid, showskin[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, showskin[playerid], 0);
    PlayerTextDrawSetPreviewModel(playerid, showskin[playerid], 250);
    PlayerTextDrawSetPreviewRot(playerid, showskin[playerid], -10.000000, 0.000000, -28.000000, 0.889998);
    PlayerTextDrawSetPreviewVehCol(playerid, showskin[playerid], 1, 1);

}
stock CargarInventario()
{
    inventari[0] = TextDrawCreate(322.000000, 102.000000, "_");
    TextDrawFont(inventari[0], 1);
    TextDrawLetterSize(inventari[0], 0.600000, 30.050024);
    TextDrawTextSize(inventari[0], 298.500000, 395.500000);
    TextDrawSetOutline(inventari[0], 1);
    TextDrawSetShadow(inventari[0], 0);
    TextDrawAlignment(inventari[0], 2);
    TextDrawColor(inventari[0], -1);
    TextDrawBackgroundColor(inventari[0], 255);
    TextDrawBoxColor(inventari[0], 286199807);
    TextDrawUseBox(inventari[0], 1);
    TextDrawSetProportional(inventari[0], 1);
    TextDrawSetSelectable(inventari[0], 0);

    inventari[1] = TextDrawCreate(264.000000, 120.000000, "_");
    TextDrawFont(inventari[1], 1);
    TextDrawLetterSize(inventari[1], 0.600000, 25.999958);
    TextDrawTextSize(inventari[1], 298.500000, -2.500000);
    TextDrawSetOutline(inventari[1], 1);
    TextDrawSetShadow(inventari[1], 0);
    TextDrawAlignment(inventari[1], 2);
    TextDrawColor(inventari[1], -1);
    TextDrawBackgroundColor(inventari[1], 255);
    TextDrawBoxColor(inventari[1], -121);
    TextDrawUseBox(inventari[1], 1);
    TextDrawSetProportional(inventari[1], 1);
    TextDrawSetSelectable(inventari[1], 0);

    inventari[2] = TextDrawCreate(311.000000, 379.000000, "_");
    TextDrawFont(inventari[2], 1);
    TextDrawLetterSize(inventari[2], 0.600000, 1.950083);
    TextDrawTextSize(inventari[2], 298.500000, 63.500000);
    TextDrawSetOutline(inventari[2], 1);
    TextDrawSetShadow(inventari[2], 0);
    TextDrawAlignment(inventari[2], 2);
    TextDrawColor(inventari[2], -1);
    TextDrawBackgroundColor(inventari[2], 255);
    TextDrawBoxColor(inventari[2], 370480639);
    TextDrawUseBox(inventari[2], 1);
    TextDrawSetProportional(inventari[2], 1);
    TextDrawSetSelectable(inventari[2], 0);

    inventari[3] = TextDrawCreate(322.000000, 101.000000, "_");
    TextDrawFont(inventari[3], 1);
    TextDrawLetterSize(inventari[3], 0.600000, -0.199992);
    TextDrawTextSize(inventari[3], 298.500000, 395.500000);
    TextDrawSetOutline(inventari[3], 1);
    TextDrawSetShadow(inventari[3], 0);
    TextDrawAlignment(inventari[3], 2);
    TextDrawColor(inventari[3], -1);
    TextDrawBackgroundColor(inventari[3], 255);
    TextDrawBoxColor(inventari[3], -510575361);
    TextDrawUseBox(inventari[3], 1);
    TextDrawSetProportional(inventari[3], 1);
    TextDrawSetSelectable(inventari[3], 0);

    inventari[4] = TextDrawCreate(127.000000, 309.000000, "HUD:radar_centre");
    TextDrawFont(inventari[4], 4);
    TextDrawLetterSize(inventari[4], 0.600000, 2.000000);
    TextDrawTextSize(inventari[4], 17.000000, 17.000000);
    TextDrawSetOutline(inventari[4], 1);
    TextDrawSetShadow(inventari[4], 0);
    TextDrawAlignment(inventari[4], 1);
    TextDrawColor(inventari[4], -2016478535);
    TextDrawBackgroundColor(inventari[4], 255);
    TextDrawBoxColor(inventari[4], 50);
    TextDrawUseBox(inventari[4], 1);
    TextDrawSetProportional(inventari[4], 1);
    TextDrawSetSelectable(inventari[4], 0);

    inventari[5] = TextDrawCreate(127.000000, 335.000000, "HUD:radar_burgershot");
    TextDrawFont(inventari[5], 4);
    TextDrawLetterSize(inventari[5], 0.600000, 2.000000);
    TextDrawTextSize(inventari[5], 17.000000, 17.000000);
    TextDrawSetOutline(inventari[5], 1);
    TextDrawSetShadow(inventari[5], 0);
    TextDrawAlignment(inventari[5], 1);
    TextDrawColor(inventari[5], -71);
    TextDrawBackgroundColor(inventari[5], 255);
    TextDrawBoxColor(inventari[5], 50);
    TextDrawUseBox(inventari[5], 1);
    TextDrawSetProportional(inventari[5], 1);
    TextDrawSetSelectable(inventari[5], 0);

    inventari[6] = TextDrawCreate(392.000000, 288.000000, "_");
    TextDrawFont(inventari[6], 1);
    TextDrawLetterSize(inventari[6], 0.600000, -0.399996);
    TextDrawTextSize(inventari[6], 294.500000, 238.000000);
    TextDrawSetOutline(inventari[6], 1);
    TextDrawSetShadow(inventari[6], 0);
    TextDrawAlignment(inventari[6], 2);
    TextDrawColor(inventari[6], -1);
    TextDrawBackgroundColor(inventari[6], 255);
    TextDrawBoxColor(inventari[6], -121);
    TextDrawUseBox(inventari[6], 1);
    TextDrawSetProportional(inventari[6], 1);
    TextDrawSetSelectable(inventari[6], 0);

    inventari[7] = TextDrawCreate(350.000000, 293.000000, "Objeto:");
    TextDrawFont(inventari[7], 1);
    TextDrawLetterSize(inventari[7], 0.166666, 1.650002);
    TextDrawTextSize(inventari[7], 298.500000, 75.000000);
    TextDrawSetOutline(inventari[7], 0);
    TextDrawSetShadow(inventari[7], 0);
    TextDrawAlignment(inventari[7], 2);
    TextDrawColor(inventari[7], -1);
    TextDrawBackgroundColor(inventari[7], 255);
    TextDrawBoxColor(inventari[7], 135);
    TextDrawUseBox(inventari[7], 0);
    TextDrawSetProportional(inventari[7], 1);
    TextDrawSetSelectable(inventari[7], 0);

    inventari[8] = TextDrawCreate(391.000000, 273.000000, "Informacion");
    TextDrawFont(inventari[8], 1);
    TextDrawLetterSize(inventari[8], 0.295832, 1.500004);
    TextDrawTextSize(inventari[8], 298.500000, 75.000000);
    TextDrawSetOutline(inventari[8], 0);
    TextDrawSetShadow(inventari[8], 0);
    TextDrawAlignment(inventari[8], 2);
    TextDrawColor(inventari[8], -1);
    TextDrawBackgroundColor(inventari[8], 255);
    TextDrawBoxColor(inventari[8], 135);
    TextDrawUseBox(inventari[8], 0);
    TextDrawSetProportional(inventari[8], 1);
    TextDrawSetSelectable(inventari[8], 0);

    inventari[9] = TextDrawCreate(391.000000, 102.000000, "Inventario");
    TextDrawFont(inventari[9], 1);
    TextDrawLetterSize(inventari[9], 0.295832, 1.500004);
    TextDrawTextSize(inventari[9], 298.500000, 75.000000);
    TextDrawSetOutline(inventari[9], 0);
    TextDrawSetShadow(inventari[9], 0);
    TextDrawAlignment(inventari[9], 2);
    TextDrawColor(inventari[9], -1);
    TextDrawBackgroundColor(inventari[9], 255);
    TextDrawBoxColor(inventari[9], 135);
    TextDrawUseBox(inventari[9], 0);
    TextDrawSetProportional(inventari[9], 1);
    TextDrawSetSelectable(inventari[9], 0);

    inventari[10] = TextDrawCreate(352.000000, 310.000000, "Cantidad:");
    TextDrawFont(inventari[10], 1);
    TextDrawLetterSize(inventari[10], 0.166666, 1.650002);
    TextDrawTextSize(inventari[10], 298.500000, 75.000000);
    TextDrawSetOutline(inventari[10], 0);
    TextDrawSetShadow(inventari[10], 0);
    TextDrawAlignment(inventari[10], 2);
    TextDrawColor(inventari[10], -1);
    TextDrawBackgroundColor(inventari[10], 255);
    TextDrawBoxColor(inventari[10], 135);
    TextDrawUseBox(inventari[10], 0);
    TextDrawSetProportional(inventari[10], 1);
    TextDrawSetSelectable(inventari[10], 0);

    inventari[11] = TextDrawCreate(357.000000, 328.000000, "Informacion:");
    TextDrawFont(inventari[11], 1);
    TextDrawLetterSize(inventari[11], 0.166666, 1.650002);
    TextDrawTextSize(inventari[11], 298.500000, 75.000000);
    TextDrawSetOutline(inventari[11], 0);
    TextDrawSetShadow(inventari[11], 0);
    TextDrawAlignment(inventari[11], 2);
    TextDrawColor(inventari[11], -1);
    TextDrawBackgroundColor(inventari[11], 255);
    TextDrawBoxColor(inventari[11], 135);
    TextDrawUseBox(inventari[11], 0);
    TextDrawSetProportional(inventari[11], 1);
    TextDrawSetSelectable(inventari[11], 0);

    inventari[12] = TextDrawCreate(392.000000, 379.000000, "_");
    TextDrawFont(inventari[12], 1);
    TextDrawLetterSize(inventari[12], 0.600000, 1.950083);
    TextDrawTextSize(inventari[12], 298.500000, 63.500000);
    TextDrawSetOutline(inventari[12], 1);
    TextDrawSetShadow(inventari[12], 0);
    TextDrawAlignment(inventari[12], 2);
    TextDrawColor(inventari[12], -1);
    TextDrawBackgroundColor(inventari[12], 255);
    TextDrawBoxColor(inventari[12], 370480639);
    TextDrawUseBox(inventari[12], 1);
    TextDrawSetProportional(inventari[12], 1);
    TextDrawSetSelectable(inventari[12], 0);

    inventari[13] = TextDrawCreate(475.000000, 379.000000, "_");
    TextDrawFont(inventari[13], 1);
    TextDrawLetterSize(inventari[13], 0.600000, 1.950083);
    TextDrawTextSize(inventari[13], 298.500000, 63.500000);
    TextDrawSetOutline(inventari[13], 1);
    TextDrawSetShadow(inventari[13], 0);
    TextDrawAlignment(inventari[13], 2);
    TextDrawColor(inventari[13], -1);
    TextDrawBackgroundColor(inventari[13], 255);
    TextDrawBoxColor(inventari[13], 370480639);
    TextDrawUseBox(inventari[13], 1);
    TextDrawSetProportional(inventari[13], 1);
    TextDrawSetSelectable(inventari[13], 0);
}