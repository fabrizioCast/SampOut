/*
    -----------------
    Include: By Sleek
    -----------------
*/

new PlayerText:mostrarobjeto[MAX_PLAYERS][3],
TimerShowobj[MAX_PLAYERS];

stock CrearTDShowObject(playerid)
{
    mostrarobjeto[playerid][0] = CreatePlayerTextDraw(playerid, 543.000000, 114.000000, "_");
    PlayerTextDrawFont(playerid, mostrarobjeto[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, mostrarobjeto[playerid][0], 0.600000, 2.350002);
    PlayerTextDrawTextSize(playerid, mostrarobjeto[playerid][0], 298.500000, 162.500000);
    PlayerTextDrawSetOutline(playerid, mostrarobjeto[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, mostrarobjeto[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, mostrarobjeto[playerid][0], 2);
    PlayerTextDrawColor(playerid, mostrarobjeto[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, mostrarobjeto[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, mostrarobjeto[playerid][0], 135);
    PlayerTextDrawUseBox(playerid, mostrarobjeto[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, mostrarobjeto[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, mostrarobjeto[playerid][0], 0);

    mostrarobjeto[playerid][1] = CreatePlayerTextDraw(playerid, 617.000000, 116.000000, "Preciona  ~r~C ~w~para recoger el objeto");
    PlayerTextDrawFont(playerid, mostrarobjeto[playerid][1], 1);
    PlayerTextDrawLetterSize(playerid, mostrarobjeto[playerid][1], 0.254166, 1.750002);
    PlayerTextDrawTextSize(playerid, mostrarobjeto[playerid][1], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, mostrarobjeto[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, mostrarobjeto[playerid][1], 1);
    PlayerTextDrawAlignment(playerid, mostrarobjeto[playerid][1], 3);
    PlayerTextDrawColor(playerid, mostrarobjeto[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, mostrarobjeto[playerid][1], 255);
    PlayerTextDrawBoxColor(playerid, mostrarobjeto[playerid][1], 135);
    PlayerTextDrawUseBox(playerid, mostrarobjeto[playerid][1], 0);
    PlayerTextDrawSetProportional(playerid, mostrarobjeto[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, mostrarobjeto[playerid][1], 0);

    mostrarobjeto[playerid][2] = CreatePlayerTextDraw(playerid, 463.000000, 115.000000, "_");
    PlayerTextDrawFont(playerid, mostrarobjeto[playerid][2], 1);
    PlayerTextDrawLetterSize(playerid, mostrarobjeto[playerid][2], 0.600000, 2.250001);
    PlayerTextDrawTextSize(playerid, mostrarobjeto[playerid][2], 298.500000, 2.500000);
    PlayerTextDrawSetOutline(playerid, mostrarobjeto[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, mostrarobjeto[playerid][2], 0);
    PlayerTextDrawAlignment(playerid, mostrarobjeto[playerid][2], 2);
    PlayerTextDrawColor(playerid, mostrarobjeto[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, mostrarobjeto[playerid][2], 255);
    PlayerTextDrawBoxColor(playerid, mostrarobjeto[playerid][2], -1962934137);
    PlayerTextDrawUseBox(playerid, mostrarobjeto[playerid][2], 1);
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