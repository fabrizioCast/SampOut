#include "../Modulos/tutorial/funcionmapeo.inc"
#include "YSI\y_hooks"



new Text:apariencia[13];
new PlayerText:femenino[MAX_PLAYERS];
new PlayerText:masculino[MAX_PLAYERS];
new PlayerText:masedad[MAX_PLAYERS];
new PlayerText:menosedad[MAX_PLAYERS];
new PlayerText:mostraredad[MAX_PLAYERS];
new PlayerText:raza[MAX_PLAYERS];
new PlayerText:finalizar[MAX_PLAYERS];

new bool:temp_inmenu_carac[MAX_PLAYERS];
new temp_edad[MAX_PLAYERS] = 20;
new countfinalizar[MAX_PLAYERS];

hook:OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    if(playertextid == femenino[playerid])
    {
        if(countfinalizar[playerid] < 1)
        {
            CuentaInfo[playerid][Genero] = 1;
            ShowInfoForPlayer(playerid, "Genero: ~r~Femenino", 4000);
            SetPlayerSkin(playerid, 13);
            PlayerTextDrawSetSelectable(playerid, femenino[playerid], 1);
            countfinalizar[playerid] = 1;
        }
    }
    if(playertextid == masculino[playerid])
    {
        if(countfinalizar[playerid] < 1)
        {
            CuentaInfo[playerid][Genero] = 0;
            SetPlayerSkin(playerid, 7);
            ShowInfoForPlayer(playerid, "Genero: ~b~Masculino", 4000);
            PlayerTextDrawSetSelectable(playerid, masculino[playerid], 1);
            countfinalizar[playerid] = 1;
        }
    }
    if(playertextid == menosedad[playerid])
    {
        if(temp_edad[playerid] < 16)
        {
            return 0;
        }
        else
        {
            temp_edad[playerid]--;
            CuentaInfo[playerid][EdadPJ] = temp_edad[playerid];
            new temp_string[128];
            valstr(temp_string, temp_edad[playerid]);
            PlayerTextDrawSetString(playerid, mostraredad[playerid], temp_string);
        }
    }
    if(playertextid == masedad[playerid])
    {
        if(temp_edad[playerid] >= 80)
        {
            return 0;
        }
        else
        {
            temp_edad[playerid]++;
            CuentaInfo[playerid][EdadPJ] = temp_edad[playerid];
            new temp_string[128];
            FIX_valstr(temp_string, temp_edad[playerid]);
            PlayerTextDrawSetString(playerid, mostraredad[playerid], temp_string);
        }
    }
    if(playertextid == raza[playerid])
    {
        ShowPlayerDialog(playerid, raza_d, DIALOG_STYLE_LIST, "Razas:", "{C58C85}@@@@@@\n{3F2E2C}@@@@@@\n{D6AAAA}@@@@@@\n{81583A}@@@@@@", "Aceptar", "Salir");
        CancelSelectTextDraw(playerid);
    }
    if(playertextid == finalizar[playerid])
    {
        if(countfinalizar[playerid] == 2)
        {
            if(temp_edad[playerid] > 14 && temp_edad[playerid] <= 80)
            {
                CuentaInfo[playerid][Skin] = GetPlayerSkin(playerid);
                new handle = SQL::Open(SQL::INSERT, "usuarios");
                SQL::ToggleAutoIncrement(handle, true);
                SQL::WriteString(handle, "Nombre", ret_pName(playerid));
                SQL::WriteString(handle, "Password", CuentaInfo[playerid][Password]);
                SQL::WriteString(handle, "Email",  CuentaInfo[playerid][Email]);
                SQL::WriteInt(handle, "Edad", CuentaInfo[playerid][Edad]);
                SQL::WriteInt(handle, "EdadPJ", CuentaInfo[playerid][EdadPJ]);
                SQL::WriteInt(handle, "Skin", CuentaInfo[playerid][Skin]);
                SQL::WriteFloat(handle, "PosX", 2349.4131);
                SQL::WriteFloat(handle, "PosY", -700.9865);
                SQL::WriteFloat(handle, "PosZ", 117.3094);
                CuentaInfo[playerid][ID] = SQL::Close(handle);

                new handle2 = SQL::Open(SQL::INSERT, "inventario");
                SQL::WriteInt(handle2, "ID",CuentaInfo[playerid][ID]);
                SQL::WriteString(handle2, "Nombre", ret_pName(playerid));
                SQL::WriteInt(handle2, "Slot1", VE[playerid][Inv][0]);
                SQL::WriteInt(handle2, "Slot2", VE[playerid][Inv][1]);
                SQL::WriteInt(handle2, "Slot3", VE[playerid][Inv][2]);
                SQL::WriteInt(handle2, "Slot4", VE[playerid][Inv][3]);
                SQL::WriteInt(handle2, "Slot5", VE[playerid][Inv][4]);
                SQL::WriteInt(handle2, "Slot6", VE[playerid][Inv][5]);
                SQL::WriteInt(handle2, "Slot7", VE[playerid][Inv][6]);
                SQL::WriteInt(handle2, "Slot8", VE[playerid][Inv][7]);
                SQL::WriteInt(handle2, "Slot9", VE[playerid][Inv][8]);
                SQL::WriteInt(handle2, "Slot10", VE[playerid][Inv][9]);
                SQL::WriteInt(handle2, "Slot11", VE[playerid][Inv][10]);
                SQL::WriteInt(handle2, "Slot12", VE[playerid][Inv][11]);
                SQL::WriteInt(handle2, "Slot13", VE[playerid][Inv][12]);
                SQL::WriteInt(handle2, "Slot14", VE[playerid][Inv][13]);
                SQL::WriteInt(handle2, "Slot15", VE[playerid][Inv][14]);
                SQL::WriteInt(handle2, "Usos1", Objetos[VE[playerid][Inv][0]][usos]);
                SQL::WriteInt(handle2, "Usos2", Objetos[VE[playerid][Inv][1]][usos]);
                SQL::WriteInt(handle2, "Usos3", Objetos[VE[playerid][Inv][2]][usos]);
                SQL::WriteInt(handle2, "Usos4", Objetos[VE[playerid][Inv][3]][usos]);
                SQL::WriteInt(handle2, "Usos5", Objetos[VE[playerid][Inv][4]][usos]);
                SQL::WriteInt(handle2, "Usos6", Objetos[VE[playerid][Inv][5]][usos]);
                SQL::WriteInt(handle2, "Usos7", Objetos[VE[playerid][Inv][6]][usos]);
                SQL::WriteInt(handle2, "Usos8", Objetos[VE[playerid][Inv][7]][usos]);
                SQL::WriteInt(handle2, "Usos9", Objetos[VE[playerid][Inv][8]][usos]);
                SQL::WriteInt(handle2, "Usos10", Objetos[VE[playerid][Inv][9]][usos]);
                SQL::WriteInt(handle2, "Usos11", Objetos[VE[playerid][Inv][10]][usos]);
                SQL::WriteInt(handle2, "Usos12", Objetos[VE[playerid][Inv][11]][usos]);
                SQL::WriteInt(handle2, "Usos13", Objetos[VE[playerid][Inv][12]][usos]);
                SQL::WriteInt(handle2, "Usos14", Objetos[VE[playerid][Inv][13]][usos]);
                SQL::WriteInt(handle2, "Usos15", Objetos[VE[playerid][Inv][14]][usos]);
                SQL::Close(handle2);
                CuentaInfo[playerid][Logeado] = 1;
                ClearAnimations(playerid);
                for(new i; i < 13; i++)
                {
                    TextDrawHideForPlayer(playerid, apariencia[i]);
                }
                PlayerTextDrawHide(playerid, masculino[playerid]);
                PlayerTextDrawHide(playerid, femenino[playerid]);
                PlayerTextDrawHide(playerid, menosedad[playerid]);
                PlayerTextDrawHide(playerid, masedad[playerid]);
                PlayerTextDrawHide(playerid, mostraredad[playerid]);
                PlayerTextDrawHide(playerid, raza[playerid]);
                PlayerTextDrawHide(playerid, finalizar[playerid]);
                temp_inmenu_carac[playerid] = false;
                CancelSelectTextDraw(playerid);
                SetPlayerVirtualWorld(playerid, 0);
                SetPlayerPos(playerid, 2349.4131,-700.9865,117.3094);
                TogglePlayerControllable(playerid, 1);
                SetCameraBehindPlayer(playerid);
                CongelarPlayer(playerid, 2000);
            } else return ShowInfoForPlayer(playerid, "~r~Completa la edad!", 3000);
        }
    }
    return 1;
}
hook:OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == raza_d)
    {
        if(!response)
        {
            ShowInfoForPlayer(playerid, "~r~Elige un tono de piel!", 3000);
            ShowPlayerDialog(playerid, raza_d, DIALOG_STYLE_LIST, "Razas:", "{C58C85}@@@@@@\n{D6AAAA}@@@@@@\n{81583A}@@@@@@\n{3F2E2C}@@@@@@", "Aceptar", "Salir");
        }
        else
        {
            switch(listitem)
            {
                case 0:
                {
                    CuentaInfo[playerid][Tono] = 0;
                    countfinalizar[playerid] = 2;
                    SelectTextDraw(playerid, 0xFF6C00FF);
                }
                case 1:
                {
                    CuentaInfo[playerid][Tono] = 1;
                    countfinalizar[playerid] = 2;
                    SelectTextDraw(playerid, 0xFF6C00FF);
                }
                case 2:
                {
                    CuentaInfo[playerid][Tono] = 2;
                    countfinalizar[playerid] = 2;
                    SelectTextDraw(playerid, 0xFF6C00FF);
                }
                case 3:
                {
                    CuentaInfo[playerid][Tono] = 3;
                    countfinalizar[playerid] = 2;
                    SelectTextDraw(playerid, 0xFF6C00FF);
                }
            }
        }
    }
    return 1;
}
stock MostrarPersonalizacion(playerid)
{
    
    SendClientMessage(playerid, -1, "[{FF8F00}TIP{FFFFFF}]: Una vez selecionado el genero no lo podras cambiar, cuidado!.");
    for(new i; i < 13; i++)
    {
        TextDrawShowForPlayer(playerid, apariencia[i]);
    }
    PlayerTextDrawShow(playerid, masculino[playerid]);
    PlayerTextDrawShow(playerid, femenino[playerid]);
    PlayerTextDrawShow(playerid, menosedad[playerid]);
    PlayerTextDrawShow(playerid, masedad[playerid]);
    PlayerTextDrawShow(playerid, mostraredad[playerid]);
    PlayerTextDrawShow(playerid, raza[playerid]);
    PlayerTextDrawShow(playerid, finalizar[playerid]);
    SelectTextDraw(playerid, 0xFF6C00FF);
    temp_inmenu_carac[playerid] = true;
    new vwa = random(5670);
    SetPlayerSkin(playerid, 7);
    SetPlayerVirtualWorld(playerid, vwa);
    SetPlayerPos(playerid, 2331.3108,-648.2766,958.3655);
    SetPlayerFacingAngle(playerid,91.6271);
    SetTimerEx("CinematicaInicio2", 1, false, "d", playerid);
}

forward CinematicaInicio2(playerid);
public CinematicaInicio2(playerid)
{
    SetPlayerCameraPos(playerid,2327.6436,-648.0535,958.3655);
    SetPlayerCameraLookAt(playerid, 2331.3108,-648.2766,958.3655);
    return 1;
}

hook:OnGameModeInit()
{
    CargarApariencia();
    CargarMapeoCara();
    return 1;
}
hook:OnPlayerConnect(playerid)
{
    CargarBotonesApariencia(playerid);
    return 1;
}









stock CargarBotonesApariencia(playerid)
{
    femenino[playerid] = CreatePlayerTextDraw(playerid, 579.000000, 252.000000, "Femenino");
    PlayerTextDrawFont(playerid, femenino[playerid], 1);
    PlayerTextDrawLetterSize(playerid, femenino[playerid], 0.366666, 2.250002);
    PlayerTextDrawTextSize(playerid, femenino[playerid], 298.500000, 61.000000);
    PlayerTextDrawSetOutline(playerid, femenino[playerid], 0);
    PlayerTextDrawSetShadow(playerid, femenino[playerid], 0);
    PlayerTextDrawAlignment(playerid, femenino[playerid], 2);
    PlayerTextDrawColor(playerid, femenino[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, femenino[playerid], 255);
    PlayerTextDrawBoxColor(playerid, femenino[playerid], -1523963337);
    PlayerTextDrawUseBox(playerid, femenino[playerid], 1);
    PlayerTextDrawSetProportional(playerid, femenino[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, femenino[playerid], 1);

    masculino[playerid] = CreatePlayerTextDraw(playerid, 487.000000, 251.000000, "Masculino");
    PlayerTextDrawFont(playerid, masculino[playerid], 1);
    PlayerTextDrawLetterSize(playerid, masculino[playerid], 0.341666, 2.250002);
    PlayerTextDrawTextSize(playerid, masculino[playerid], 298.500000, 61.000000);
    PlayerTextDrawSetOutline(playerid, masculino[playerid], 0);
    PlayerTextDrawSetShadow(playerid, masculino[playerid], 0);
    PlayerTextDrawAlignment(playerid, masculino[playerid], 2);
    PlayerTextDrawColor(playerid, masculino[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, masculino[playerid], 255);
    PlayerTextDrawBoxColor(playerid, masculino[playerid], 1097457975);
    PlayerTextDrawUseBox(playerid, masculino[playerid], 1);
    PlayerTextDrawSetProportional(playerid, masculino[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, masculino[playerid], 1);

    masedad[playerid] = CreatePlayerTextDraw(playerid, 554.000000, 320.000000, "ld_beat:right");
    PlayerTextDrawFont(playerid, masedad[playerid], 4);
    PlayerTextDrawLetterSize(playerid, masedad[playerid], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, masedad[playerid], 17.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, masedad[playerid], 1);
    PlayerTextDrawSetShadow(playerid, masedad[playerid], 0);
    PlayerTextDrawAlignment(playerid, masedad[playerid], 1);
    PlayerTextDrawColor(playerid, masedad[playerid], -8388353);
    PlayerTextDrawBackgroundColor(playerid, masedad[playerid], 1296911871);
    PlayerTextDrawBoxColor(playerid, masedad[playerid], 50);
    PlayerTextDrawUseBox(playerid, masedad[playerid], 1);
    PlayerTextDrawSetProportional(playerid, masedad[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, masedad[playerid], 1);

    menosedad[playerid] = CreatePlayerTextDraw(playerid, 492.000000, 320.000000, "ld_beat:left");
    PlayerTextDrawFont(playerid, menosedad[playerid], 4);
    PlayerTextDrawLetterSize(playerid, menosedad[playerid], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, menosedad[playerid], 17.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, menosedad[playerid], 1);
    PlayerTextDrawSetShadow(playerid, menosedad[playerid], 0);
    PlayerTextDrawAlignment(playerid, menosedad[playerid], 1);
    PlayerTextDrawColor(playerid, menosedad[playerid], -8388353);
    PlayerTextDrawBackgroundColor(playerid, menosedad[playerid], 1296911871);
    PlayerTextDrawBoxColor(playerid, menosedad[playerid], 50);
    PlayerTextDrawUseBox(playerid, menosedad[playerid], 1);
    PlayerTextDrawSetProportional(playerid, menosedad[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, menosedad[playerid], 1);

    mostraredad[playerid] = CreatePlayerTextDraw(playerid, 532.000000, 319.000000, "20");
    PlayerTextDrawFont(playerid, mostraredad[playerid], 1);
    PlayerTextDrawLetterSize(playerid, mostraredad[playerid], 0.325000, 1.999995);
    PlayerTextDrawTextSize(playerid, mostraredad[playerid], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, mostraredad[playerid], 0);
    PlayerTextDrawSetShadow(playerid, mostraredad[playerid], 0);
    PlayerTextDrawAlignment(playerid, mostraredad[playerid], 2);
    PlayerTextDrawColor(playerid, mostraredad[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, mostraredad[playerid], 255);
    PlayerTextDrawBoxColor(playerid, mostraredad[playerid], 135);
    PlayerTextDrawUseBox(playerid, mostraredad[playerid], 0);
    PlayerTextDrawSetProportional(playerid, mostraredad[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, mostraredad[playerid], 0);

    raza[playerid] = CreatePlayerTextDraw(playerid, 533.000000, 385.000000, "Seleciona");
    PlayerTextDrawFont(playerid, raza[playerid], 1);
    PlayerTextDrawLetterSize(playerid, raza[playerid], 0.341666, 2.250002);
    PlayerTextDrawTextSize(playerid, raza[playerid], 298.500000, 61.000000);
    PlayerTextDrawSetOutline(playerid, raza[playerid], 0);
    PlayerTextDrawSetShadow(playerid, raza[playerid], 0);
    PlayerTextDrawAlignment(playerid, raza[playerid], 2);
    PlayerTextDrawColor(playerid, raza[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, raza[playerid], 255);
    PlayerTextDrawBoxColor(playerid, raza[playerid], -1061109745);
    PlayerTextDrawUseBox(playerid, raza[playerid], 1);
    PlayerTextDrawSetProportional(playerid, raza[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, raza[playerid], 1);

    finalizar[playerid] = CreatePlayerTextDraw(playerid, 596.000000, 414.000000, "Finalizar");
    PlayerTextDrawFont(playerid, finalizar[playerid], 1);
    PlayerTextDrawLetterSize(playerid, finalizar[playerid], 0.341666, 2.250002);
    PlayerTextDrawTextSize(playerid, finalizar[playerid], 298.500000, 61.000000);
    PlayerTextDrawSetOutline(playerid, finalizar[playerid], 0);
    PlayerTextDrawSetShadow(playerid, finalizar[playerid], 0);
    PlayerTextDrawAlignment(playerid, finalizar[playerid], 2);
    PlayerTextDrawColor(playerid, finalizar[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, finalizar[playerid], 255);
    PlayerTextDrawBoxColor(playerid, finalizar[playerid], -1061109745);
    PlayerTextDrawUseBox(playerid, finalizar[playerid], 0);
    PlayerTextDrawSetProportional(playerid, finalizar[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, finalizar[playerid], 1);
    return 1;
}

stock CargarApariencia()
{
    apariencia[0] = TextDrawCreate(532.000000, 216.000000, "_");
    TextDrawFont(apariencia[0], 1);
    TextDrawLetterSize(apariencia[0], 0.600000, 23.499977);
    TextDrawTextSize(apariencia[0], 298.500000, 176.500000);
    TextDrawSetOutline(apariencia[0], 1);
    TextDrawSetShadow(apariencia[0], 0);
    TextDrawAlignment(apariencia[0], 2);
    TextDrawColor(apariencia[0], -1);
    TextDrawBackgroundColor(apariencia[0], 255);
    TextDrawBoxColor(apariencia[0], 202116095);
    TextDrawUseBox(apariencia[0], 1);
    TextDrawSetProportional(apariencia[0], 1);
    TextDrawSetSelectable(apariencia[0], 0);

    apariencia[1] = TextDrawCreate(532.000000, 210.000000, "_");
    TextDrawFont(apariencia[1], 1);
    TextDrawLetterSize(apariencia[1], 0.600000, 24.699958);
    TextDrawTextSize(apariencia[1], 298.500000, 167.000000);
    TextDrawSetOutline(apariencia[1], 1);
    TextDrawSetShadow(apariencia[1], 0);
    TextDrawAlignment(apariencia[1], 2);
    TextDrawColor(apariencia[1], -1);
    TextDrawBackgroundColor(apariencia[1], 255);
    TextDrawBoxColor(apariencia[1], 202116095);
    TextDrawUseBox(apariencia[1], 1);
    TextDrawSetProportional(apariencia[1], 1);
    TextDrawSetSelectable(apariencia[1], 0);

    apariencia[2] = TextDrawCreate(451.000000, 194.000000, "o");
    TextDrawFont(apariencia[2], 1);
    TextDrawLetterSize(apariencia[2], 0.775000, 4.299997);
    TextDrawTextSize(apariencia[2], 298.500000, 75.000000);
    TextDrawSetOutline(apariencia[2], 1);
    TextDrawSetShadow(apariencia[2], 0);
    TextDrawAlignment(apariencia[2], 2);
    TextDrawColor(apariencia[2], 202116095);
    TextDrawBackgroundColor(apariencia[2], 202116095);
    TextDrawBoxColor(apariencia[2], 135);
    TextDrawUseBox(apariencia[2], 0);
    TextDrawSetProportional(apariencia[2], 1);
    TextDrawSetSelectable(apariencia[2], 0);

    apariencia[3] = TextDrawCreate(451.000000, 399.000000, "o");
    TextDrawFont(apariencia[3], 1);
    TextDrawLetterSize(apariencia[3], 0.775000, 4.299997);
    TextDrawTextSize(apariencia[3], 298.500000, 75.000000);
    TextDrawSetOutline(apariencia[3], 1);
    TextDrawSetShadow(apariencia[3], 0);
    TextDrawAlignment(apariencia[3], 2);
    TextDrawColor(apariencia[3], 202116095);
    TextDrawBackgroundColor(apariencia[3], 202116095);
    TextDrawBoxColor(apariencia[3], 135);
    TextDrawUseBox(apariencia[3], 0);
    TextDrawSetProportional(apariencia[3], 1);
    TextDrawSetSelectable(apariencia[3], 0);

    apariencia[4] = TextDrawCreate(615.000000, 194.000000, "o");
    TextDrawFont(apariencia[4], 1);
    TextDrawLetterSize(apariencia[4], 0.775000, 4.299997);
    TextDrawTextSize(apariencia[4], 298.500000, 75.000000);
    TextDrawSetOutline(apariencia[4], 1);
    TextDrawSetShadow(apariencia[4], 0);
    TextDrawAlignment(apariencia[4], 2);
    TextDrawColor(apariencia[4], 202116095);
    TextDrawBackgroundColor(apariencia[4], 202116095);
    TextDrawBoxColor(apariencia[4], 135);
    TextDrawUseBox(apariencia[4], 0);
    TextDrawSetProportional(apariencia[4], 1);
    TextDrawSetSelectable(apariencia[4], 0);

    apariencia[5] = TextDrawCreate(615.000000, 399.000000, "o");
    TextDrawFont(apariencia[5], 1);
    TextDrawLetterSize(apariencia[5], 0.775000, 4.299997);
    TextDrawTextSize(apariencia[5], 298.500000, 75.000000);
    TextDrawSetOutline(apariencia[5], 1);
    TextDrawSetShadow(apariencia[5], 0);
    TextDrawAlignment(apariencia[5], 2);
    TextDrawColor(apariencia[5], 202116095);
    TextDrawBackgroundColor(apariencia[5], 202116095);
    TextDrawBoxColor(apariencia[5], 135);
    TextDrawUseBox(apariencia[5], 0);
    TextDrawSetProportional(apariencia[5], 1);
    TextDrawSetSelectable(apariencia[5], 0);

    apariencia[6] = TextDrawCreate(532.000000, 215.000000, "Genero");
    TextDrawFont(apariencia[6], 1);
    TextDrawLetterSize(apariencia[6], 0.325000, 1.999995);
    TextDrawTextSize(apariencia[6], 298.500000, 75.000000);
    TextDrawSetOutline(apariencia[6], 0);
    TextDrawSetShadow(apariencia[6], 0);
    TextDrawAlignment(apariencia[6], 2);
    TextDrawColor(apariencia[6], -1);
    TextDrawBackgroundColor(apariencia[6], 255);
    TextDrawBoxColor(apariencia[6], 135);
    TextDrawUseBox(apariencia[6], 0);
    TextDrawSetProportional(apariencia[6], 1);
    TextDrawSetSelectable(apariencia[6], 0);

    apariencia[7] = TextDrawCreate(530.000000, 235.000000, "_");
    TextDrawFont(apariencia[7], 1);
    TextDrawLetterSize(apariencia[7], 0.600000, -0.299997);
    TextDrawTextSize(apariencia[7], 298.500000, 75.000000);
    TextDrawSetOutline(apariencia[7], 1);
    TextDrawSetShadow(apariencia[7], 0);
    TextDrawAlignment(apariencia[7], 2);
    TextDrawColor(apariencia[7], -1);
    TextDrawBackgroundColor(apariencia[7], 255);
    TextDrawBoxColor(apariencia[7], -8388473);
    TextDrawUseBox(apariencia[7], 1);
    TextDrawSetProportional(apariencia[7], 1);
    TextDrawSetSelectable(apariencia[7], 0);

    apariencia[8] = TextDrawCreate(533.000000, 280.000000, "Edad");
    TextDrawFont(apariencia[8], 1);
    TextDrawLetterSize(apariencia[8], 0.325000, 1.999995);
    TextDrawTextSize(apariencia[8], 298.500000, 75.000000);
    TextDrawSetOutline(apariencia[8], 0);
    TextDrawSetShadow(apariencia[8], 0);
    TextDrawAlignment(apariencia[8], 2);
    TextDrawColor(apariencia[8], -1);
    TextDrawBackgroundColor(apariencia[8], 255);
    TextDrawBoxColor(apariencia[8], 135);
    TextDrawUseBox(apariencia[8], 0);
    TextDrawSetProportional(apariencia[8], 1);
    TextDrawSetSelectable(apariencia[8], 0);

    apariencia[9] = TextDrawCreate(533.000000, 302.000000, "_");
    TextDrawFont(apariencia[9], 1);
    TextDrawLetterSize(apariencia[9], 0.600000, -0.349997);
    TextDrawTextSize(apariencia[9], 298.500000, 78.000000);
    TextDrawSetOutline(apariencia[9], 1);
    TextDrawSetShadow(apariencia[9], 0);
    TextDrawAlignment(apariencia[9], 2);
    TextDrawColor(apariencia[9], -1);
    TextDrawBackgroundColor(apariencia[9], 255);
    TextDrawBoxColor(apariencia[9], -8388473);
    TextDrawUseBox(apariencia[9], 1);
    TextDrawSetProportional(apariencia[9], 1);
    TextDrawSetSelectable(apariencia[9], 0);

    apariencia[10] = TextDrawCreate(482.000000, 188.000000, "Apariencia");
    TextDrawFont(apariencia[10], 1);
    TextDrawLetterSize(apariencia[10], 0.391666, 2.299995);
    TextDrawTextSize(apariencia[10], 298.500000, 75.000000);
    TextDrawSetOutline(apariencia[10], 0);
    TextDrawSetShadow(apariencia[10], 1);
    TextDrawAlignment(apariencia[10], 2);
    TextDrawColor(apariencia[10], -1);
    TextDrawBackgroundColor(apariencia[10], 255);
    TextDrawBoxColor(apariencia[10], 135);
    TextDrawUseBox(apariencia[10], 0);
    TextDrawSetProportional(apariencia[10], 1);
    TextDrawSetSelectable(apariencia[10], 0);

    apariencia[11] = TextDrawCreate(533.000000, 350.000000, "Tono");
    TextDrawFont(apariencia[11], 1);
    TextDrawLetterSize(apariencia[11], 0.325000, 1.999995);
    TextDrawTextSize(apariencia[11], 298.500000, 75.000000);
    TextDrawSetOutline(apariencia[11], 0);
    TextDrawSetShadow(apariencia[11], 0);
    TextDrawAlignment(apariencia[11], 2);
    TextDrawColor(apariencia[11], -1);
    TextDrawBackgroundColor(apariencia[11], 255);
    TextDrawBoxColor(apariencia[11], 135);
    TextDrawUseBox(apariencia[11], 0);
    TextDrawSetProportional(apariencia[11], 1);
    TextDrawSetSelectable(apariencia[11], 0);

    apariencia[12] = TextDrawCreate(533.000000, 372.000000, "_");
    TextDrawFont(apariencia[12], 1);
    TextDrawLetterSize(apariencia[12], 0.600000, -0.299997);
    TextDrawTextSize(apariencia[12], 298.500000, 75.000000);
    TextDrawSetOutline(apariencia[12], 1);
    TextDrawSetShadow(apariencia[12], 0);
    TextDrawAlignment(apariencia[12], 2);
    TextDrawColor(apariencia[12], -1);
    TextDrawBackgroundColor(apariencia[12], 255);
    TextDrawBoxColor(apariencia[12], -8388473);
    TextDrawUseBox(apariencia[12], 1);
    TextDrawSetProportional(apariencia[12], 1);
    TextDrawSetSelectable(apariencia[12], 0);
    return 1;
}