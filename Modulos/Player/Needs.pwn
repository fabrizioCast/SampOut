#include "YSI\y_hooks"

new PlayerBar:PlayerProgressBar[MAX_PLAYERS][2];

hook:Ned_OnPlayerConnect(playerid)
{
    PlayerProgressBar[playerid][0] = CreatePlayerProgressBar(playerid, 147.000000, 314.000000, 106.000000, 10.500000, -2016478465, 100.000000, 0);
    SetPlayerProgressBarValue(playerid, PlayerProgressBar[playerid][0], 50.000000);

    PlayerProgressBar[playerid][1] = CreatePlayerProgressBar(playerid, 147.000000, 338.000000, 106.000000, 10.500000, -764862721, 100.000000, 0);
    SetPlayerProgressBarValue(playerid, PlayerProgressBar[playerid][1], 50.000000);
    return 1;
}
CMD:bajar(playerid, params[1])
{
    if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, -1, "bajar monto");
    SetPlayerProgressBarValue(playerid, PlayerProgressBar[playerid][0], params[0]);
    return 1;
}
/*
PlayerProgressBar[playerid][0] = CreatePlayerProgressBar(playerid, 237.000000, 337.000000, 78.000000, 9.000000, -9436989, 100.000000, 0);
SetPlayerProgressBarValue(playerid, PlayerProgressBar[playerid][0], 50.000000);
CreatePlayerProgressBar(playerid, Float:x, Float:y, Float:width = 55.5, Float:height = 3.2, colour = 0xFF1C1CFF, Float:max = 100.0, direction = BAR_DIRECTION_RIGHT)

PlayerProgressBar[playerid][1] = CreatePlayerProgressBar(playerid, 346.000000, 337.000000, 78.000000, 9.000000, 13959117, 100.000000, 0);
SetPlayerProgressBarValue(playerid, PlayerProgressBar[playerid][1], 50.000000);*/