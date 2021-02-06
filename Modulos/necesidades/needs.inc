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
