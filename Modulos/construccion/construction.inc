#include <YSI\y_hooks>
#include "../Modulos/construccion/DataConstruction.inc"


CMD:construir(playerid)
{
    TogglePlayerControllable(playerid, 0);
    ShowPlayerMenu(playerid, construccionc, "Construccion", "Elige la categoria", 0xf7f7f7ff, 0x463B31FF);
    AddPlayerMenuItem(playerid, "Puertas y Rejas", "Categorias de puertas y rejas");
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
            new Float:p[3];
            GetPlayerPos(playerid, p[0], p[1], p[2]);
            Objeto_Temp_Create[playerid] = CreateObject(modelidd, p[0]+5, p[1], p[2], 0, 0, 0, DISTANCIA_DIBUJADO_OBJ);
            EditObject(playerid, Objeto_Temp_Create[playerid]);
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
        new bool:found = false;
        for(new i; i < MAX_OBJETOS_SERVER; i++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 4.0, Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2]))
            {
                if(Objetosc[i][O_gPassword] == 0)
                {
                    MoverObjeto(playerid);
                    found = true;
                    break;
                }
            }
        }
        if(!found)
        {
            ShowPlayerDialog(playerid, d_objetos_pass, DIALOG_STYLE_PASSWORD, "Contraseña", "{FFC900}• {ffffff}Ingresa la contraseña", "Aceptar", "Salir");
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
            Objetosc[i][O_Create] = CreateObject(modeloid, X, Y, Z, rX, rY, rZ, DISTANCIA_DIBUJADO_OBJ);
            if(ObjetoConFuncion(modeloid) > 0)
            {
                new str[128];
                format(str, 128, "{949090}Usa {14528D}N {949090}para interactuar\n{949090}Resistencia: {14528D}%.0f", Objetosc[i][O_Vida]);
                Objetosc[i][O_Text] = Create3DTextLabel(str, -1, X, Y, Z, 6.0, 0);
            }
            else
            {
                new str[128];
                format(str, 128, "{949090}Resistencia: {14528D}%.0f", Objetosc[i][O_Vida]);
                Objetosc[i][O_Text] = Create3DTextLabel(str, -1, X, Y, Z, 6.0, 0);
            }
            break;
        }
    }
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
                        MoveObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2], 0.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]+82);
                        Objetosc[i][O_Abierto] = true;
                        break;
                    } 
                    else 
                    {
                        MoveObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2], 0.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]);
                        Objetosc[i][O_Abierto] = false;
                        break;
                    }
                }
                else if(Objetosc[i][O_gPassword] == 0)
                {
                    if(Objetosc[i][O_Abierto] == false)
                    {
                        MoveObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2], 0.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]+82);
                        Objetosc[i][O_Abierto] = true;
                        break;
                    } 
                    else 
                    {
                        MoveObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2], 0.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]);
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
                        MoveObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2]+4, 1.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]);
                        Objetosc[i][O_Abierto] = true;
                        break;
                    } 
                    else 
                    {
                        MoveObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2], 1.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]);
                        Objetosc[i][O_Abierto] = false;
                        break;
                    }
                }
                else if(Objetosc[i][O_gPassword] == 0)
                {
                    if(Objetosc[i][O_Abierto] == false)
                    {
                        MoveObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2], 0.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]+82);
                        Objetosc[i][O_Abierto] = true;
                        break;
                    } 
                    else 
                    {
                        MoveObject(Objetosc[i][O_Create], Objetosc[i][O_Pos][0], Objetosc[i][O_Pos][1], Objetosc[i][O_Pos][2], 0.50, Objetosc[i][O_Rot][0], Objetosc[i][O_Rot][1], Objetosc[i][O_Rot][2]);
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
ObjetoConFuncion(objectid)
{
    switch(objectid)
    {
        case 1497,1495,1498,1505,1506,1507,1537: return 1;
        case 980,975,987,1412,1413,3850,1408: return 2;
    }
    return 0;
}