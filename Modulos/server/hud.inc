
new Text:hud[6];
new Text:radar;

stock MostrarLogo(playerid)
{
    for(new i; i < 6; i++)
    {
        TextDrawShowForPlayer(playerid, hud[i]);
    }
    return 1;
}

stock MostrarRadar(playerid)
{
    TextDrawShowForPlayer(playerid, radar);
    return 1;
}

stock EsconderRadar(playerid)
{
    TextDrawHideForPlayer(playerid, radar);
    return 1;
}
stock CargarRadar()
{
    radar = TextDrawCreate(19.000000, 323.000000, "ld_beat:chit");
    TextDrawFont(radar, 4);
    TextDrawLetterSize(radar, 0.600000, 2.000000);
    TextDrawTextSize(radar, 136.000000, 116.500000);
    TextDrawSetOutline(radar, 1);
    TextDrawSetShadow(radar, 0);
    TextDrawAlignment(radar, 1);
    TextDrawColor(radar, 255);
    TextDrawBackgroundColor(radar, 255);
    TextDrawBoxColor(radar, 50);
    TextDrawUseBox(radar, 1);
    TextDrawSetProportional(radar, 1);
    TextDrawSetSelectable(radar, 0);
    return 1;
}
stock CargarLogo()
{
    hud[0] = TextDrawCreate(573.000000, 1.000000, "S");
    TextDrawFont(hud[0], 1);
    TextDrawLetterSize(hud[0], 0.408333, 2.249999);
    TextDrawTextSize(hud[0], 400.000000, 17.000000);
    TextDrawSetOutline(hud[0], 0);
    TextDrawSetShadow(hud[0], 1);
    TextDrawAlignment(hud[0], 1);
    TextDrawColor(hud[0], -1);
    TextDrawBackgroundColor(hud[0], 255);
    TextDrawBoxColor(hud[0], 50);
    TextDrawUseBox(hud[0], 0);
    TextDrawSetProportional(hud[0], 1);
    TextDrawSetSelectable(hud[0], 0);

    hud[1] = TextDrawCreate(582.000000, 4.000000, "amp");
    TextDrawFont(hud[1], 1);
    TextDrawLetterSize(hud[1], 0.387500, 1.850000);
    TextDrawTextSize(hud[1], 400.000000, 17.000000);
    TextDrawSetOutline(hud[1], 0);
    TextDrawSetShadow(hud[1], 1);
    TextDrawAlignment(hud[1], 1);
    TextDrawColor(hud[1], -1);
    TextDrawBackgroundColor(hud[1], 255);
    TextDrawBoxColor(hud[1], 50);
    TextDrawUseBox(hud[1], 0);
    TextDrawSetProportional(hud[1], 1);
    TextDrawSetSelectable(hud[1], 0);

    hud[2] = TextDrawCreate(610.000000, 1.000000, "O");
    TextDrawFont(hud[2], 1);
    TextDrawLetterSize(hud[2], 0.408333, 2.249999);
    TextDrawTextSize(hud[2], 400.000000, 17.000000);
    TextDrawSetOutline(hud[2], 0);
    TextDrawSetShadow(hud[2], 1);
    TextDrawAlignment(hud[2], 1);
    TextDrawColor(hud[2], -1);
    TextDrawBackgroundColor(hud[2], 255);
    TextDrawBoxColor(hud[2], 50);
    TextDrawUseBox(hud[2], 0);
    TextDrawSetProportional(hud[2], 1);
    TextDrawSetSelectable(hud[2], 0);

    hud[3] = TextDrawCreate(621.000000, 4.000000, "ut");
    TextDrawFont(hud[3], 1);
    TextDrawLetterSize(hud[3], 0.387500, 1.850000);
    TextDrawTextSize(hud[3], 400.000000, 17.000000);
    TextDrawSetOutline(hud[3], 0);
    TextDrawSetShadow(hud[3], 1);
    TextDrawAlignment(hud[3], 1);
    TextDrawColor(hud[3], -1);
    TextDrawBackgroundColor(hud[3], 255);
    TextDrawBoxColor(hud[3], 50);
    TextDrawUseBox(hud[3], 0);
    TextDrawSetProportional(hud[3], 1);
    TextDrawSetSelectable(hud[3], 0);

    hud[4] = TextDrawCreate(570.000000, 3.000000, "ld_chat:dpad_lr");
    TextDrawFont(hud[4], 4);
    TextDrawLetterSize(hud[4], 0.600000, 2.000000);
    TextDrawTextSize(hud[4], 22.500000, 19.000000);
    TextDrawSetOutline(hud[4], 1);
    TextDrawSetShadow(hud[4], 0);
    TextDrawAlignment(hud[4], 1);
    TextDrawColor(hud[4], -1);
    TextDrawBackgroundColor(hud[4], 255);
    TextDrawBoxColor(hud[4], 50);
    TextDrawUseBox(hud[4], 1);
    TextDrawSetProportional(hud[4], 1);
    TextDrawSetSelectable(hud[4], 0);

    hud[5] = TextDrawCreate(638.000000, 3.000000, "ld_chat:dpad_lr");
    TextDrawFont(hud[5], 4);
    TextDrawLetterSize(hud[5], 0.600000, 2.000000);
    TextDrawTextSize(hud[5], -25.000000, 19.500000);
    TextDrawSetOutline(hud[5], 1);
    TextDrawSetShadow(hud[5], 0);
    TextDrawAlignment(hud[5], 1);
    TextDrawColor(hud[5], -1);
    TextDrawBackgroundColor(hud[5], 255);
    TextDrawBoxColor(hud[5], 50);
    TextDrawUseBox(hud[5], 1);
    TextDrawSetProportional(hud[5], 1);
    TextDrawSetSelectable(hud[5], 0);
    return 1;
}