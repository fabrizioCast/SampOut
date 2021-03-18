#include <YSI\y_hooks>


CMD:construir(playerid)
{
    if(TempPlayer[playerid][puedeconstruir] == true)
    {
        TogglePlayerControllable(playerid, 0);
        ShowPlayerMenu(playerid, construccionc, "Construccion", "Elige la categoria", 0xf7f7f7ff, 0x463B31FF);
        AddPlayerMenuItem(playerid, "Puertas y Rejas", "Categoria de puertas y rejas");
        AddPlayerMenuItem(playerid, "Vallas", "Categoria de vallas y cercas");
        AddPlayerMenuItem(playerid, "Paredes", "Categoria de  paredes");
        //AddPlayerMenuItem(playerid, "Almacenes", "Categoria de Almacenes y cofres");
    }
    return 1;
}


MENU:construccionc(playerid, response, listitem)
{
    switch(response)
    {
        case MENU_RESPONSE_SELECT:
        switch(listitem)
        {
            case 0:
            {
                ShowModelSelectionMenu(playerid, ObjetosSelection_Puertas, "Puertas y Rejas", 0x0E0E0F33, 0x14131333 , 0xB72020F0);
                TogglePlayerControllable(playerid, 1);
            }
            case 1:
            {
                ShowModelSelectionMenu(playerid, ObjetosSelection_Vallas, "Vallas", 0x0E0E0F33, 0x14131333 , 0xB72020F0);
                TogglePlayerControllable(playerid, 1);
            }
            case 2:
            {
                ShowModelSelectionMenu(playerid, ObjetosSelection_Paredes, "Paredes", 0x0E0E0F33, 0x14131333 , 0xB72020F0);
                TogglePlayerControllable(playerid, 1);
            }
            case 3:
            {
                ShowModelSelectionMenu(playerid, ObjetosSelection_Almacenes, "Almacenes", 0x0E0E0F33, 0x14131333 , 0xB72020F0);
                TogglePlayerControllable(playerid, 1);
            }
        }
        case MENU_RESPONSE_CLOSE:
        {
            TogglePlayerControllable(playerid, 1);
        }
    }
}


public OnPlayerModelSelection(playerid, response, listid, modelidd)
{
    if(response)
    {
        if(listid == ObjetosSelection_Puertas)
        {
            temp_modelid_c[playerid] = modelidd;
            ShowPlayerDialog(playerid, d_objetos_confirm, DIALOG_STYLE_MSGBOX, "Creacion", "{FFC900}• {ffffff}Gastataras {B92B2B}20 {ffffff}de madera y {B92B2B}10 {ffffff}de hierro.", "Aceptar", "Cancelar");
        }
        if(listid == ObjetosSelection_Vallas)
        {
            temp_modelid_c[playerid] = modelidd;
            ShowPlayerDialog(playerid, d_objetos_confirm, DIALOG_STYLE_MSGBOX, "Creacion", "{FFC900}• {ffffff}Gastataras {B92B2B}15 {ffffff}de madera y {B92B2B}15 {ffffff}de hierro.", "Aceptar", "Cancelar");
        }
        if(listid == ObjetosSelection_Paredes)
        {
            temp_modelid_c[playerid] = modelidd;
            ShowPlayerDialog(playerid, d_objetos_confirm, DIALOG_STYLE_MSGBOX, "Creacion", "{FFC900}• {ffffff}Gastataras {B92B2B}10 {ffffff}de madera y {B92B2B}5 {ffffff}de hierro.", "Aceptar", "Cancelar");
        }
        if(listid == ObjetosSelection_Almacenes)
        {
            temp_modelid_c[playerid] = modelidd;
            ShowPlayerDialog(playerid, d_objetos_confirm, DIALOG_STYLE_MSGBOX, "Creacion", "{FFC900}• {ffffff}Gastataras {B92B2B}30 {ffffff}de madera y {B92B2B}50 {ffffff}de hierro.", "Aceptar", "Cancelar");
        }
    }
}


hook OnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ )
{
    switch(response)
    {
        case EDIT_RESPONSE_FINAL:
        {
            new mdid = GetObjectModel(objectid);
            DestroyObject(objectid);
            CrearObjeto(playerid, mdid, fX, fY, fZ, fRotX, fRotY, fRotZ);
        }
        case EDIT_RESPONSE_CANCEL:
        {
            DestroyObject(objectid);
        }
    }
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (PRESSED( KEY_NO ))
    {
        for(new i; i < MAX_OBJETOS_SERVER; i++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 4.0, Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2]))
            {
                if(Objetosc[i][O_gCofre] == 1)
                {
                    MostrarCofre(playerid, Objetosc[i][O_ID]);
                }
                else if(Objetosc[i][O_gPassword] == 0)
                {
                    MoverObjeto(playerid);
                    break;
                }
                else
                {
                    ShowPlayerDialog(playerid, d_objetos_pass, DIALOG_STYLE_PASSWORD, "Contraseña", "{FFC900}• {ffffff}Ingresa la contraseña", "Aceptar", "Salir");
                    break;
                }
            }
        }
    }
}

public OnPlayerShootDynamicObject(playerid, weaponid, STREAMER_TAG_OBJECT:objectid, Float:x, Float:y, Float:z)
{
    for(new i; i < MAX_OBJETOS_SERVER; i++)
    {
        if(objectid == Objetosc[i][O_Create])
        {
            Objetosc[i][O_Vida] -= WeaponDamageObject(weaponid);
            if(ObjetoConFuncion(Objetosc[i][O_ModelID]) > 0)
            {
                new str[128];
                format(str, 128, "Resistencia: %.0f\nDueño: %s", Objetosc[i][O_Vida], Objetosc[i][O_Owner]);
                UpdateDynamic3DTextLabelText(Objetosc[i][O_Text], 0x9C939399, str);
            }
            else
            {
                new str[128];
                format(str, 128, "Resistencia: %.0f\nDueño: %s", Objetosc[i][O_Vida], Objetosc[i][O_Owner]);
                UpdateDynamic3DTextLabelText(Objetosc[i][O_Text], 0x9C939399, str);
            }
            if(Objetosc[i][O_Vida] <= 0)
            {
                RemoverObjeto(Objetosc[i][O_ID]);
            }
        }
    }
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[5])
{
    switch(dialogid)
    {
        case d_objetos_pass:
        {
            if(response)
            {
                new long = strlen(inputtext);
                if(long == 4)
                {
                    MoverObjeto(playerid, inputtext);
                } else ShowInfoForPlayer(playerid, "~r~Incorrecto", 3000);
            }
        }
        case d_objetos_pass_1:
        {
            if(response)
            {
                new long = strlen(inputtext);
                if(long == 4)
                {
                    PonerPass(playerid, inputtext);
                }
            }
        }
        case d_objetos_confirm:
        {
            if(response)
            {
                if(RecursosNecesarios(playerid, temp_modelid_c[playerid]))
                {
                    CrearPreview(playerid, temp_modelid_c[playerid]);
                }
            }
        }
    }
}

stock CrearObjeto(playerid, modeloid, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ)
{
    for(new i = 1; i < MAX_OBJETOS_SERVER; i++)
    {
        if(Objetosc[i][O_ID] == 0)
        {
            new handle2 = SQL::Open(SQL::INSERT, "objetos");
            SQL::WriteInt(handle2, "ID", i);
            SQL::WriteInt(handle2, "ModelID", modeloid);
            SQL::WriteInt(handle2, "gPassword", 0);
            SQL::WriteString(handle2, "Owner", ret_pName(playerid));
            SQL::WriteString(handle2, "Password", "0000");
            SQL::WriteFloat(handle2, "Vida", 1000.00);
            SQL::WriteFloat(handle2, "PosX", X);
            SQL::WriteFloat(handle2, "PosY", Y);
            SQL::WriteFloat(handle2, "PosZ", Z);
            SQL::WriteFloat(handle2, "RotX", rX);
            SQL::WriteFloat(handle2, "RotY", rY);
            SQL::WriteFloat(handle2, "RotZ", rZ);
            SQL::Close(handle2);
            Objetosc[i][O_ID] = i;
            Objetosc[i][O_Abierto] = false;
            Objetosc[i][O_ModelID] = modeloid;
            Objetosc[i][O_Owner] = ret_pName(playerid);
            Objetosc[i][O_Vida] = 1000.00;
            Objetosc[i][O_Pos][0] = X;
            Objetosc[i][O_Pos][1] = Y;
            Objetosc[i][O_Pos][2] = Z;
            Objetosc[i][O_Rot][0] = rX;
            Objetosc[i][O_Rot][1] = rY;
            Objetosc[i][O_Rot][2] = rZ;
            Objetosc[i][O_Password] = "0000";
            Objetosc[i][O_gPassword] = 0;
            Objetosc[i][O_Create] = CreateDynamicObject(modeloid, X, Y, Z, rX, rY, rZ);
            if(ObjetoConFuncion(modeloid) == 3)
            {
                Objetosc[i][O_gCofre] = 1;
                new str[128];
                format(str, 128, "Resistencia: %.0f\nDueño: %s", Objetosc[i][O_Vida], Objetosc[i][O_Owner]);
                Objetosc[i][O_Text] = CreateDynamic3DTextLabel(str, 0x9C939399, X, Y, Z, 6.0);
            }
            else if(ObjetoConFuncion(modeloid) == 1 || ObjetoConFuncion(modeloid) == 2)
            {
                new str[128];
                format(str, 128, "Resistencia: %.0f\nDueño: %s", Objetosc[i][O_Vida], Objetosc[i][O_Owner]);
                Objetosc[i][O_Text] = CreateDynamic3DTextLabel(str, 0x9C939399, X, Y, Z, 6.0);
                Objetosc[i][O_gCofre] = 0;
            }
            else
            {
                new str[128];
                format(str, 128, "Resistencia: %.0f\nDueño: %s", Objetosc[i][O_Vida], Objetosc[i][O_Owner]);
                Objetosc[i][O_Text] = CreateDynamic3DTextLabel(str, 0x9C939399, X, Y, Z, 6.0);
                Objetosc[i][O_gCofre] = 0;
            }
            break;
        }
    }
}


stock CrearPreview(playerid, modelidd)
{
    new Float:p[9];
    const Float:Fscale = 5.0;
    GetPlayerCameraPos(playerid, p[0], p[1], p[2]);
    GetPlayerCameraFrontVector(playerid, p[3], p[4], p[5]);
    p[6] = p[0] + floatmul(p[3], Fscale);
    p[7] = p[1] + floatmul(p[4], Fscale);
    p[8] = p[2] + floatmul(p[5], Fscale);
    Objeto_Temp_Create[playerid] = CreateObject(modelidd, p[6], p[7], p[8], 0, 0, 0, DISTANCIA_DIBUJADO_OBJ);
    EditObject(playerid, Objeto_Temp_Create[playerid]);
}

stock RemoverObjeto(Oi)
{
    SQL::DeleteRow("objetos", "ID", Objetosc[Oi][O_ID]);
    DestroyDynamicObject(Objetosc[Oi][O_Create]);
    DestroyDynamic3DTextLabel(Objetosc[Oi][O_Text]);
    Objetosc[Oi][O_ID] = 0;
}

stock MoverObjeto(playerid, pass[] = "")
{
    for(new i; i < MAX_OBJETOS_SERVER; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 4.0, Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2]))
        {
            if(ObjetoConFuncion(Objetosc[i][O_ModelID]) == 1)
            {
                if(!strcmp(pass, Objetosc[i][O_Password]))
                {
                    if(Objetosc[i][O_Abierto] == false)
                    {
                        MoveDynamicObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2], 0.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]+82);
                        Objetosc[i][O_Abierto] = true;
                        break;
                    } 
                    else 
                    {
                        MoveDynamicObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2], 0.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]);
                        Objetosc[i][O_Abierto] = false;
                        break;
                    }
                }
                else if(Objetosc[i][O_gPassword] == 0)
                {
                    if(Objetosc[i][O_Abierto] == false)
                    {
                        MoveDynamicObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2], 0.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]+82);
                        Objetosc[i][O_Abierto] = true;
                        break;
                    } 
                    else 
                    {
                        MoveDynamicObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2], 0.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]);
                        Objetosc[i][O_Abierto] = false;
                        break;
                    }
                } else ShowInfoForPlayer(playerid, "~r~Incorrecto", 3000);

            }
            else if(ObjetoConFuncion(Objetosc[i][O_ModelID]) == 2)
            {
                if(!strcmp(pass, Objetosc[i][O_Password]))
                {
                    if(Objetosc[i][O_Abierto] == false)
                    {
                        MoveDynamicObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2]+4, 1.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]);
                        Objetosc[i][O_Abierto] = true;
                        break;
                    } 
                    else 
                    {
                        MoveDynamicObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2], 1.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]);
                        Objetosc[i][O_Abierto] = false;
                        break;
                    }
                }
                else if(Objetosc[i][O_gPassword] == 0)
                {
                    if(Objetosc[i][O_Abierto] == false)
                    {
                        MoveDynamicObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2], 0.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]+82);
                        Objetosc[i][O_Abierto] = true;
                        break;
                    } 
                    else 
                    {
                        MoveDynamicObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2], 0.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]);
                        Objetosc[i][O_Abierto] = false;
                        break;
                    }
                } else ShowInfoForPlayer(playerid, "~r~Incorrecto", 3000);
            }
        }
    }
}

stock PonerPass(playerid, pass[5])
{
    for(new i; i < MAX_OBJETOS_SERVER; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 4.0, Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2]))
        {
            Objetosc[i][O_gPassword] = 1;
            Objetosc[i][O_Password] = pass;
            new handle = SQL::Open(SQL::UPDATE, "objetos", "ID", Objetosc[i][O_ID]);
            SQL::WriteString(handle, "Password", pass);
            SQL::WriteInt(handle, "gPassword", 1);
            SQL::Close(handle);
            break;
        }
    }
}


stock GuardarObjetosc()
{
    for(new i = 1; i < MAX_OBJETOS_SERVER; i++)
    {
        if(Objetosc[i][O_ID] > 0)
        {
            new handle2 = SQL::Open(SQL::UPDATE, "objetos", "ID", Objetosc[i][O_ID]);
            SQL::WriteString(handle2, "Password", Objetosc[i][O_Password]);
            SQL::WriteFloat(handle2, "Vida", Objetosc[i][O_Vida]);
            SQL::WriteInt(handle2, "gPassword", Objetosc[i][O_gPassword]);
            SQL::Close(handle2);
        }
    }
}


stock CargarObjetosc()
{
    new countc;
    for(new i; i < MAX_OBJETOS_SERVER; i++)
    {
        new hand = SQL::Open(SQL::MTREAD, "objetos");
        new pia;
        SQL::ReadInt(hand, "ID", pia, i);
        Objetosc[pia][O_ID] = pia;
        SQL::ReadInt(hand, "ModelID", Objetosc[pia][O_ModelID], i);
        SQL::ReadString(hand, "Owner", Objetosc[pia][O_Owner], MAX_PLAYER_NAME, i);
        SQL::ReadFloat(hand, "Vida", Objetosc[pia][O_Vida], i);
        SQL::ReadFloat(hand, "PosX", Objetosc[pia][O_Pos][0], i);
        SQL::ReadFloat(hand, "PosY", Objetosc[pia][O_Pos][1], i);
        SQL::ReadFloat(hand, "PosZ", Objetosc[pia][O_Pos][2], i);
        SQL::ReadFloat(hand, "RotX", Objetosc[pia][O_Rot][0], i);
        SQL::ReadFloat(hand, "RotY", Objetosc[pia][O_Rot][1], i);
        SQL::ReadFloat(hand, "RotZ", Objetosc[pia][O_Rot][2], i);
        SQL::ReadString(hand, "Password", Objetosc[pia][O_Password], 5, i);
        SQL::ReadInt(hand, "gPassword", Objetosc[pia][O_gPassword], i);
        countc = SQL::Close(hand);
        if(Objetosc[pia][O_ID] > 0)
        {
            Objetosc[pia][O_Create] = CreateDynamicObject(Objetosc[pia][O_ModelID], Objetosc[pia][O_Pos][0], Objetosc[pia][O_Pos][1], Objetosc[pia][O_Pos][2], Objetosc[pia][O_Rot][0], Objetosc[pia][O_Rot][1], Objetosc[pia][O_Rot][2]);
            if(ObjetoConFuncion(Objetosc[pia][O_ModelID]) > 0)
            {
                new str[128];
                format(str, 128, "Resistencia: %.0f\nDueño: %s", Objetosc[pia][O_Vida], Objetosc[pia][O_Owner]);
                Objetosc[pia][O_Text] = CreateDynamic3DTextLabel(str, 0x9C939399, Objetosc[pia][O_Pos][0], Objetosc[pia][O_Pos][1], Objetosc[pia][O_Pos][2], 6.0);
            }
            else
            {
                new str[128];
                format(str, 128, "Resistencia: %.0f\nDueño: %s", Objetosc[pia][O_Vida], Objetosc[pia][O_Owner]);
                Objetosc[pia][O_Text] = CreateDynamic3DTextLabel(str, 0x9C939399, Objetosc[pia][O_Pos][0], Objetosc[pia][O_Pos][1], Objetosc[pia][O_Pos][2], 6.0);
            }
        }
    }
    printf("[Objetos InGame Cargados]: %d", countc);
}

stock RecursosNecesarios(playerid, objectid)
{
    switch(objectid)
    {
        //______________P U E R T A S _____________//
        case 1497,1495,1498,1504,1505,1506,1507,1537,2949,980,975,971:
        {
            new bool:found = false;
            new found2 = false;
            new i, p;
            for(i = 0; i < MAX_INV; i++)
            {
                if(VE[playerid][Inv][i] == MADERA && VE[playerid][usos][VE[playerid][Inv][i]] >= 20)
                {
                    found = true;
                    break;
                }
            }
            for(p = 0; p < MAX_INV; p++)
            {
                if(VE[playerid][Inv][p] == HIERRO && VE[playerid][usos][VE[playerid][Inv][p]] >= 10)
                {
                    found2 = true;
                    break;
                }
            }
            if(found && found2)
            {
                VE[playerid][usos][VE[playerid][Inv][i]] -= 20;
                if(VE[playerid][usos][VE[playerid][Inv][i]] == 0)
                {
                    VE[playerid][Inv][i] = NADA;
                }
                VE[playerid][usos][VE[playerid][Inv][p]] -= 10;
                if(VE[playerid][usos][VE[playerid][Inv][p]] == 0)
                {
                    VE[playerid][Inv][p] = NADA;
                }
                return true;
            }else ShowInfoForPlayer(playerid, "~r~Materiales insuficientes", 3000);
        }
        //______________P A R E D E S_____________//
        case 19353,19354,19355,19356,19357,19358,19359,19360,19361,19362,19363,19364,19365,19366,19367,19368,19369,19370,19371,19372:
        {
            new bool:found = false;
            new found2 = false;
            new i, p;
            for(i = 0; i < MAX_INV; i++)
            {
                if(VE[playerid][Inv][i] == MADERA && VE[playerid][usos][VE[playerid][Inv][i]] >= 10)
                {
                    found = true;
                    break;
                }
            }
            for(p = 0; p < MAX_INV; p++)
            {
                if(VE[playerid][Inv][p] == HIERRO && VE[playerid][usos][VE[playerid][Inv][p]] >= 5)
                {
                    found2 = true;
                    break;
                }
            }
            if(found && found2)
            {
                VE[playerid][usos][VE[playerid][Inv][i]] -= 10;
                if(VE[playerid][usos][VE[playerid][Inv][i]] == 0)
                {
                    VE[playerid][Inv][i] = NADA;
                }
                VE[playerid][usos][VE[playerid][Inv][p]] -= 5;
                if(VE[playerid][usos][VE[playerid][Inv][p]] == 0)
                {
                    VE[playerid][Inv][p] = NADA;
                }
                return true;
            }else ShowInfoForPlayer(playerid, "~r~Materiales insuficientes", 3000);
        }
        //______________V A L L A S _____________//
        case 987,1412,1413,1419,1468,16088,19868,19869,994,3406,1407,12921,19866,3275,972,3749,3578:
        {
            new bool:found = false;
            new found2 = false;
            new i, p;
            for(i = 0; i < MAX_INV; i++)
            {
                if(VE[playerid][Inv][i] == MADERA && VE[playerid][usos][VE[playerid][Inv][i]] >= 15)
                {
                    found = true;
                    break;
                }
            }
            for(p = 0; p < MAX_INV; p++)
            {
                if(VE[playerid][Inv][p] == HIERRO && VE[playerid][usos][VE[playerid][Inv][p]] >= 15)
                {
                    found2 = true;
                    break;
                }
            }
            if(found && found2)
            {
                VE[playerid][usos][VE[playerid][Inv][i]] -= 15;
                if(VE[playerid][usos][VE[playerid][Inv][i]] == 0)
                {
                    VE[playerid][Inv][i] = NADA;
                }
                VE[playerid][usos][VE[playerid][Inv][p]] -= 15;
                if(VE[playerid][usos][VE[playerid][Inv][p]] == 0)
                {
                    VE[playerid][Inv][p] = NADA;
                }
                return true;
            }else ShowInfoForPlayer(playerid, "~r~Materiales insuficientes", 3000);
        }
        case 19918,2972:
        {
            new bool:found = false;
            new found2 = false;
            new i, p;
            for(i = 0; i < MAX_INV; i++)
            {
                if(VE[playerid][Inv][i] == MADERA && VE[playerid][usos][VE[playerid][Inv][i]] >= 30)
                {
                    found = true;
                    break;
                }
            }
            for(p = 0; p < MAX_INV; p++)
            {
                if(VE[playerid][Inv][p] == HIERRO && VE[playerid][usos][VE[playerid][Inv][p]] >= 50)
                {
                    found2 = true;
                    break;
                }
            }
            if(found && found2)
            {
                VE[playerid][usos][VE[playerid][Inv][i]] -= 30;
                if(VE[playerid][usos][VE[playerid][Inv][i]] == 0)
                {
                    VE[playerid][Inv][i] = NADA;
                }
                VE[playerid][usos][VE[playerid][Inv][p]] -= 50;
                if(VE[playerid][usos][VE[playerid][Inv][p]] == 0)
                {
                    VE[playerid][Inv][p] = NADA;
                }
                return true;
            }else ShowInfoForPlayer(playerid, "~r~Materiales insuficientes", 3000);
        }
    }
    return false;
}


ObjetoConFuncion(objectid)
{
    switch(objectid)
    {
        case 1497,1495,1498,1504,1505,1506,1507,1537,2949: return 1; //Puertas
        case 980,975,971: return 2; //Rejas
        case 19918,2972: return 3; //Cofres
    }
    return 0;
}
//_______________________________________________C   O   F   R   E   S  ______________________________________________________//
stock MostrarCofre(playerid, id)
{
    ActualizarCofre(playerid, id);
    for(new i; i < 12; i++)
    {
        PlayerTextDrawShow(playerid, cofretd[playerid][i]);
    }
    for(new i; i < 3; i++)
    {
        TextDrawShowForPlayer(playerid, cofretds[i]);
    }
    SelectTextDraw(playerid, 0xF9BB0AFF);
    inmenucofre[playerid] = true;
}

stock OcultarCofre(playerid)
{
    for(new i; i < 12; i++)
    {
        PlayerTextDrawHide(playerid, cofretd[playerid][i]);
    }
    for(new i; i < 3; i++)
    {
        TextDrawHideForPlayer(playerid, cofretds[i]);
    }
    inmenucofre[playerid] = false;
}

CMD:cofre(playerid, params[2])
{
    if(sscanf(params, "dd", params[0], params[1])) return ShowInfoForPlayer(playerid, "/Cofre ID Item", 3000);
    {
        ObjetoEnCofre(playerid, params[0], params[1]);
    }
    return 1;
}

stock ObjetoEnCofre(playerid, id, itema)
{
    new bool:found = false;
    for(new i; i < 12; i++)
    {
        if(Objetosc[id][O_Cofre][i] == NADA)
        {
            Objetosc[id][O_Cofre][i] = itema;
            found = true;
            break;
        }
    }
    if(!found)
    {
        ShowInfoForPlayer(playerid, "~r~Cofre Lleno", 3000);
    }
}

stock ActualizarCofre(playerid, id)
{
    for(new i; i < 12; i++)
    {
        PlayerTextDrawSetPreviewModel(playerid, cofretd[playerid][i], Objetos[Objetosc[id][O_Cofre][i]][model]);
    }
}

stock PlayerTDCofre(playerid)
{
    cofretd[playerid][0] = CreatePlayerTextDraw(playerid, 200.000000, 162.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, cofretd[playerid][0], 5);
    PlayerTextDrawLetterSize(playerid, cofretd[playerid][0], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, cofretd[playerid][0], 54.500000, 61.500000);
    PlayerTextDrawSetOutline(playerid, cofretd[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, cofretd[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, cofretd[playerid][0], 1);
    PlayerTextDrawColor(playerid, cofretd[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, cofretd[playerid][0], 125);
    PlayerTextDrawBoxColor(playerid, cofretd[playerid][0], 255);
    PlayerTextDrawUseBox(playerid, cofretd[playerid][0], 0);
    PlayerTextDrawSetProportional(playerid, cofretd[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, cofretd[playerid][0], 1);
    PlayerTextDrawSetPreviewModel(playerid, cofretd[playerid][0], 19566);
    PlayerTextDrawSetPreviewRot(playerid, cofretd[playerid][0], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, cofretd[playerid][0], 1, 1);

    cofretd[playerid][1] = CreatePlayerTextDraw(playerid, 200.000000, 225.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, cofretd[playerid][1], 5);
    PlayerTextDrawLetterSize(playerid, cofretd[playerid][1], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, cofretd[playerid][1], 54.500000, 61.500000);
    PlayerTextDrawSetOutline(playerid, cofretd[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, cofretd[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, cofretd[playerid][1], 1);
    PlayerTextDrawColor(playerid, cofretd[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, cofretd[playerid][1], 125);
    PlayerTextDrawBoxColor(playerid, cofretd[playerid][1], 255);
    PlayerTextDrawUseBox(playerid, cofretd[playerid][1], 0);
    PlayerTextDrawSetProportional(playerid, cofretd[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, cofretd[playerid][1], 1);
    PlayerTextDrawSetPreviewModel(playerid, cofretd[playerid][1], 19566);
    PlayerTextDrawSetPreviewRot(playerid, cofretd[playerid][1], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, cofretd[playerid][1], 1, 1);

    cofretd[playerid][2] = CreatePlayerTextDraw(playerid, 200.000000, 289.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, cofretd[playerid][2], 5);
    PlayerTextDrawLetterSize(playerid, cofretd[playerid][2], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, cofretd[playerid][2], 54.500000, 61.500000);
    PlayerTextDrawSetOutline(playerid, cofretd[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, cofretd[playerid][2], 0);
    PlayerTextDrawAlignment(playerid, cofretd[playerid][2], 1);
    PlayerTextDrawColor(playerid, cofretd[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, cofretd[playerid][2], 125);
    PlayerTextDrawBoxColor(playerid, cofretd[playerid][2], 255);
    PlayerTextDrawUseBox(playerid, cofretd[playerid][2], 0);
    PlayerTextDrawSetProportional(playerid, cofretd[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, cofretd[playerid][2], 1);
    PlayerTextDrawSetPreviewModel(playerid, cofretd[playerid][2], 19566);
    PlayerTextDrawSetPreviewRot(playerid, cofretd[playerid][2], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, cofretd[playerid][2], 1, 1);

    cofretd[playerid][3] = CreatePlayerTextDraw(playerid, 256.000000, 162.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, cofretd[playerid][3], 5);
    PlayerTextDrawLetterSize(playerid, cofretd[playerid][3], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, cofretd[playerid][3], 54.500000, 61.500000);
    PlayerTextDrawSetOutline(playerid, cofretd[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, cofretd[playerid][3], 0);
    PlayerTextDrawAlignment(playerid, cofretd[playerid][3], 1);
    PlayerTextDrawColor(playerid, cofretd[playerid][3], -1);
    PlayerTextDrawBackgroundColor(playerid, cofretd[playerid][3], 125);
    PlayerTextDrawBoxColor(playerid, cofretd[playerid][3], 255);
    PlayerTextDrawUseBox(playerid, cofretd[playerid][3], 0);
    PlayerTextDrawSetProportional(playerid, cofretd[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, cofretd[playerid][3], 1);
    PlayerTextDrawSetPreviewModel(playerid, cofretd[playerid][3], 19566);
    PlayerTextDrawSetPreviewRot(playerid, cofretd[playerid][3], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, cofretd[playerid][3], 1, 1);

    cofretd[playerid][4] = CreatePlayerTextDraw(playerid, 256.000000, 225.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, cofretd[playerid][4], 5);
    PlayerTextDrawLetterSize(playerid, cofretd[playerid][4], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, cofretd[playerid][4], 54.500000, 61.500000);
    PlayerTextDrawSetOutline(playerid, cofretd[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, cofretd[playerid][4], 0);
    PlayerTextDrawAlignment(playerid, cofretd[playerid][4], 1);
    PlayerTextDrawColor(playerid, cofretd[playerid][4], -1);
    PlayerTextDrawBackgroundColor(playerid, cofretd[playerid][4], 125);
    PlayerTextDrawBoxColor(playerid, cofretd[playerid][4], 255);
    PlayerTextDrawUseBox(playerid, cofretd[playerid][4], 0);
    PlayerTextDrawSetProportional(playerid, cofretd[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, cofretd[playerid][4], 1);
    PlayerTextDrawSetPreviewModel(playerid, cofretd[playerid][4], 19566);
    PlayerTextDrawSetPreviewRot(playerid, cofretd[playerid][4], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, cofretd[playerid][4], 1, 1);

    cofretd[playerid][5] = CreatePlayerTextDraw(playerid, 312.000000, 162.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, cofretd[playerid][5], 5);
    PlayerTextDrawLetterSize(playerid, cofretd[playerid][5], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, cofretd[playerid][5], 54.500000, 61.500000);
    PlayerTextDrawSetOutline(playerid, cofretd[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, cofretd[playerid][5], 0);
    PlayerTextDrawAlignment(playerid, cofretd[playerid][5], 1);
    PlayerTextDrawColor(playerid, cofretd[playerid][5], -1);
    PlayerTextDrawBackgroundColor(playerid, cofretd[playerid][5], 125);
    PlayerTextDrawBoxColor(playerid, cofretd[playerid][5], 255);
    PlayerTextDrawUseBox(playerid, cofretd[playerid][5], 0);
    PlayerTextDrawSetProportional(playerid, cofretd[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, cofretd[playerid][5], 1);
    PlayerTextDrawSetPreviewModel(playerid, cofretd[playerid][5], 19566);
    PlayerTextDrawSetPreviewRot(playerid, cofretd[playerid][5], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, cofretd[playerid][5], 1, 1);

    cofretd[playerid][6] = CreatePlayerTextDraw(playerid, 368.000000, 162.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, cofretd[playerid][6], 5);
    PlayerTextDrawLetterSize(playerid, cofretd[playerid][6], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, cofretd[playerid][6], 54.500000, 61.500000);
    PlayerTextDrawSetOutline(playerid, cofretd[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, cofretd[playerid][6], 0);
    PlayerTextDrawAlignment(playerid, cofretd[playerid][6], 1);
    PlayerTextDrawColor(playerid, cofretd[playerid][6], -1);
    PlayerTextDrawBackgroundColor(playerid, cofretd[playerid][6], 125);
    PlayerTextDrawBoxColor(playerid, cofretd[playerid][6], 255);
    PlayerTextDrawUseBox(playerid, cofretd[playerid][6], 0);
    PlayerTextDrawSetProportional(playerid, cofretd[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, cofretd[playerid][6], 1);
    PlayerTextDrawSetPreviewModel(playerid, cofretd[playerid][6], 19566);
    PlayerTextDrawSetPreviewRot(playerid, cofretd[playerid][6], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, cofretd[playerid][6], 1, 1);

    cofretd[playerid][7] = CreatePlayerTextDraw(playerid, 312.000000, 225.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, cofretd[playerid][7], 5);
    PlayerTextDrawLetterSize(playerid, cofretd[playerid][7], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, cofretd[playerid][7], 54.500000, 61.500000);
    PlayerTextDrawSetOutline(playerid, cofretd[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, cofretd[playerid][7], 0);
    PlayerTextDrawAlignment(playerid, cofretd[playerid][7], 1);
    PlayerTextDrawColor(playerid, cofretd[playerid][7], -1);
    PlayerTextDrawBackgroundColor(playerid, cofretd[playerid][7], 125);
    PlayerTextDrawBoxColor(playerid, cofretd[playerid][7], 255);
    PlayerTextDrawUseBox(playerid, cofretd[playerid][7], 0);
    PlayerTextDrawSetProportional(playerid, cofretd[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, cofretd[playerid][7], 1);
    PlayerTextDrawSetPreviewModel(playerid, cofretd[playerid][7], 19566);
    PlayerTextDrawSetPreviewRot(playerid, cofretd[playerid][7], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, cofretd[playerid][7], 1, 1);

    cofretd[playerid][8] = CreatePlayerTextDraw(playerid, 368.000000, 225.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, cofretd[playerid][8], 5);
    PlayerTextDrawLetterSize(playerid, cofretd[playerid][8], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, cofretd[playerid][8], 54.500000, 61.500000);
    PlayerTextDrawSetOutline(playerid, cofretd[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, cofretd[playerid][8], 0);
    PlayerTextDrawAlignment(playerid, cofretd[playerid][8], 1);
    PlayerTextDrawColor(playerid, cofretd[playerid][8], -1);
    PlayerTextDrawBackgroundColor(playerid, cofretd[playerid][8], 125);
    PlayerTextDrawBoxColor(playerid, cofretd[playerid][8], 255);
    PlayerTextDrawUseBox(playerid, cofretd[playerid][8], 0);
    PlayerTextDrawSetProportional(playerid, cofretd[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, cofretd[playerid][8], 1);
    PlayerTextDrawSetPreviewModel(playerid, cofretd[playerid][8], 19566);
    PlayerTextDrawSetPreviewRot(playerid, cofretd[playerid][8], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, cofretd[playerid][8], 1, 1);

    cofretd[playerid][9] = CreatePlayerTextDraw(playerid, 256.000000, 289.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, cofretd[playerid][9], 5);
    PlayerTextDrawLetterSize(playerid, cofretd[playerid][9], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, cofretd[playerid][9], 54.500000, 61.500000);
    PlayerTextDrawSetOutline(playerid, cofretd[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, cofretd[playerid][9], 0);
    PlayerTextDrawAlignment(playerid, cofretd[playerid][9], 1);
    PlayerTextDrawColor(playerid, cofretd[playerid][9], -1);
    PlayerTextDrawBackgroundColor(playerid, cofretd[playerid][9], 125);
    PlayerTextDrawBoxColor(playerid, cofretd[playerid][9], 255);
    PlayerTextDrawUseBox(playerid, cofretd[playerid][9], 0);
    PlayerTextDrawSetProportional(playerid, cofretd[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, cofretd[playerid][9], 1);
    PlayerTextDrawSetPreviewModel(playerid, cofretd[playerid][9], 19566);
    PlayerTextDrawSetPreviewRot(playerid, cofretd[playerid][9], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, cofretd[playerid][9], 1, 1);

    cofretd[playerid][10] = CreatePlayerTextDraw(playerid, 312.000000, 289.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, cofretd[playerid][10], 5);
    PlayerTextDrawLetterSize(playerid, cofretd[playerid][10], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, cofretd[playerid][10], 54.500000, 61.500000);
    PlayerTextDrawSetOutline(playerid, cofretd[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, cofretd[playerid][10], 0);
    PlayerTextDrawAlignment(playerid, cofretd[playerid][10], 1);
    PlayerTextDrawColor(playerid, cofretd[playerid][10], -1);
    PlayerTextDrawBackgroundColor(playerid, cofretd[playerid][10], 125);
    PlayerTextDrawBoxColor(playerid, cofretd[playerid][10], 255);
    PlayerTextDrawUseBox(playerid, cofretd[playerid][10], 0);
    PlayerTextDrawSetProportional(playerid, cofretd[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, cofretd[playerid][10], 1);
    PlayerTextDrawSetPreviewModel(playerid, cofretd[playerid][10], 19566);
    PlayerTextDrawSetPreviewRot(playerid, cofretd[playerid][10], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, cofretd[playerid][10], 1, 1);

    cofretd[playerid][11] = CreatePlayerTextDraw(playerid, 368.000000, 289.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, cofretd[playerid][11], 5);
    PlayerTextDrawLetterSize(playerid, cofretd[playerid][11], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, cofretd[playerid][11], 54.500000, 61.500000);
    PlayerTextDrawSetOutline(playerid, cofretd[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, cofretd[playerid][11], 0);
    PlayerTextDrawAlignment(playerid, cofretd[playerid][11], 1);
    PlayerTextDrawColor(playerid, cofretd[playerid][11], -1);
    PlayerTextDrawBackgroundColor(playerid, cofretd[playerid][11], 125);
    PlayerTextDrawBoxColor(playerid, cofretd[playerid][11], 255);
    PlayerTextDrawUseBox(playerid, cofretd[playerid][11], 0);
    PlayerTextDrawSetProportional(playerid, cofretd[playerid][11], 1);
    PlayerTextDrawSetSelectable(playerid, cofretd[playerid][11], 1);
    PlayerTextDrawSetPreviewModel(playerid, cofretd[playerid][11], 19566);
    PlayerTextDrawSetPreviewRot(playerid, cofretd[playerid][11], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, cofretd[playerid][11], 1, 1);
}

stock TextDrawCofre()
{
    cofretds[0] = TextDrawCreate(312.000000, 139.000000, "_");
    TextDrawFont(cofretds[0], 1);
    TextDrawLetterSize(cofretds[0], 0.641665, 24.149913);
    TextDrawTextSize(cofretds[0], 298.500000, 236.500000);
    TextDrawSetOutline(cofretds[0], 1);
    TextDrawSetShadow(cofretds[0], 0);
    TextDrawAlignment(cofretds[0], 2);
    TextDrawColor(cofretds[0], -1);
    TextDrawBackgroundColor(cofretds[0], 255);
    TextDrawBoxColor(cofretds[0], 202050559);
    TextDrawUseBox(cofretds[0], 1);
    TextDrawSetProportional(cofretds[0], 1);
    TextDrawSetSelectable(cofretds[0], 0);

    cofretds[1] = TextDrawCreate(312.000000, 158.000000, "_");
    TextDrawFont(cofretds[1], 1);
    TextDrawLetterSize(cofretds[1], 0.600000, -0.399997);
    TextDrawTextSize(cofretds[1], 298.500000, 221.500000);
    TextDrawSetOutline(cofretds[1], 1);
    TextDrawSetShadow(cofretds[1], 0);
    TextDrawAlignment(cofretds[1], 2);
    TextDrawColor(cofretds[1], -1);
    TextDrawBackgroundColor(cofretds[1], 255);
    TextDrawBoxColor(cofretds[1], -764862841);
    TextDrawUseBox(cofretds[1], 1);
    TextDrawSetProportional(cofretds[1], 1);
    TextDrawSetSelectable(cofretds[1], 0);

    cofretds[2] = TextDrawCreate(312.000000, 140.000000, "Almacen");
    TextDrawFont(cofretds[2], 1);
    TextDrawLetterSize(cofretds[2], 0.533333, 1.700002);
    TextDrawTextSize(cofretds[2], 298.500000, 221.500000);
    TextDrawSetOutline(cofretds[2], 0);
    TextDrawSetShadow(cofretds[2], 0);
    TextDrawAlignment(cofretds[2], 2);
    TextDrawColor(cofretds[2], -1061109505);
    TextDrawBackgroundColor(cofretds[2], 255);
    TextDrawBoxColor(cofretds[2], 1687547271);
    TextDrawUseBox(cofretds[2], 0);
    TextDrawSetProportional(cofretds[2], 1);
    TextDrawSetSelectable(cofretds[2], 0);
}