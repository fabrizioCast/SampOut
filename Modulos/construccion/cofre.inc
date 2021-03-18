stock MostrarCofre(playerid)
{
    for(new i; i < 12; i++)
    {
        PlayerTextDrawShow(playerid, cofretd[playerid][i]);
    }
    for(new i; i < 3; i++)
    {
        TextDrawShowForPlayer(playerid, cofretds[i]);
    }
    SelectTextDraw(playerid, hovercolor);
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