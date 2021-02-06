/*
    -----------------
    Include: By Sleek
    -----------------
*/

new PlayerText:mostrarobjeto[MAX_PLAYERS][3],
TimerShowobj[MAX_PLAYERS];

stock CrearTDShowObject(playerid)
{
    mostrarobjeto[playerid][0] = CreatePlayerTextDraw(playerid, 546.000000, 107.000000, "_");
    PlayerTextDrawFont(playerid, mostrarobjeto[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, mostrarobjeto[playerid][0], 0.600000, 1.700001);
    PlayerTextDrawTextSize(playerid, mostrarobjeto[playerid][0], 298.500000, 184.000000);
    PlayerTextDrawSetOutline(playerid, mostrarobjeto[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, mostrarobjeto[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, mostrarobjeto[playerid][0], 2);
    PlayerTextDrawColor(playerid, mostrarobjeto[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, mostrarobjeto[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, mostrarobjeto[playerid][0], 85);
    PlayerTextDrawUseBox(playerid, mostrarobjeto[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, mostrarobjeto[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, mostrarobjeto[playerid][0], 0);

    mostrarobjeto[playerid][1] = CreatePlayerTextDraw(playerid, 546.000000, 107.000000, "_");
    PlayerTextDrawFont(playerid, mostrarobjeto[playerid][1], 1);
    PlayerTextDrawLetterSize(playerid, mostrarobjeto[playerid][1], 0.600000, -0.399996);
    PlayerTextDrawTextSize(playerid, mostrarobjeto[playerid][1], 298.500000, 184.000000);
    PlayerTextDrawSetOutline(playerid, mostrarobjeto[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, mostrarobjeto[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, mostrarobjeto[playerid][1], 2);
    PlayerTextDrawColor(playerid, mostrarobjeto[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, mostrarobjeto[playerid][1], 255);
    PlayerTextDrawBoxColor(playerid, mostrarobjeto[playerid][1], -1962934017);
    PlayerTextDrawUseBox(playerid, mostrarobjeto[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, mostrarobjeto[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, mostrarobjeto[playerid][1], 0);

    mostrarobjeto[playerid][2] = CreatePlayerTextDraw(playerid, 546.000000, 108.000000, "[~r~!~w~]Preciona ~r~C ~w~para recoger");
    PlayerTextDrawFont(playerid, mostrarobjeto[playerid][2], 1);
    PlayerTextDrawLetterSize(playerid, mostrarobjeto[playerid][2], 0.345833, 1.350002);
    PlayerTextDrawTextSize(playerid, mostrarobjeto[playerid][2], 298.500000, 180.500000);
    PlayerTextDrawSetOutline(playerid, mostrarobjeto[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, mostrarobjeto[playerid][2], 1);
    PlayerTextDrawAlignment(playerid, mostrarobjeto[playerid][2], 2);
    PlayerTextDrawColor(playerid, mostrarobjeto[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, mostrarobjeto[playerid][2], 255);
    PlayerTextDrawBoxColor(playerid, mostrarobjeto[playerid][2], 135);
    PlayerTextDrawUseBox(playerid, mostrarobjeto[playerid][2], 0);
    PlayerTextDrawSetProportional(playerid, mostrarobjeto[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, mostrarobjeto[playerid][2], 0);

}


stock ShowInfoPickUp(playerid, time)
{
    KillTimer(TimerShowobj[playerid]);
    for(new i; i < 3; i++)
    {
        PlayerTextDrawShow(playerid, mostrarobjeto[playerid][i]);
    }
    TimerShowobj[playerid] = SetTimerEx("HideInfoPickUp", time, false, "i", playerid);
}


forward HideInfoPickUp(playerid);
public HideInfoPickUp(playerid)
{
	if(!IsPlayerConnected(playerid)) return 1;
    for(new i; i < 3; i++)
    {
        PlayerTextDrawHide(playerid, mostrarobjeto[playerid][i]);
    }
    return 1;
}