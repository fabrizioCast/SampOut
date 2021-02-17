#include "YSI\y_hooks"

new PlayerBar:PlayerProgressBar[MAX_PLAYERS][2];

enum necesidades{
    Float:N_Hambre,
    Float:N_Sed,
    TimmerNecesidades
};
new Necesidades[MAX_PLAYERS][necesidades];

hook Ned_OnPlayerConnect(playerid)
{
    PlayerProgressBar[playerid][0] = CreatePlayerProgressBar(playerid, 147.000000, 314.000000, 106.000000, 10.500000, -2016478465, 100.000000, 0);
    PlayerProgressBar[playerid][1] = CreatePlayerProgressBar(playerid, 147.000000, 338.000000, 106.000000, 10.500000, -764862721, 100.000000, 0);
    Necesidades[playerid][TimmerNecesidades] =  SetTimerEx("ActualizarNecesidades", 900000, true, "d", playerid);
    return 1;
}

forward ActualizarNecesidades(playerid);
public ActualizarNecesidades(playerid)
{
    Necesidades[playerid][N_Hambre]-= 2.0;
    Necesidades[playerid][N_Sed]-=4.0;
    if(Necesidades[playerid][N_Hambre] < 5)
    {
        new Float:vida_temp;
        GetPlayerHealth(playerid, vida_temp);
        vida_temp -= 2.0;
        SetPlayerHealth(playerid, vida_temp);
        ShowNotification(playerid, "Tu personaje tiene demasiada ~r~hambre~w~, come algo pronto!", 3000);
        if(Necesidades[playerid][N_Hambre] < 0)
        {
            Necesidades[playerid][N_Hambre] = 0.0;
        }
    }
    if(Necesidades[playerid][N_Sed] < 5)
    {
        new Float:vida_temp;
        GetPlayerHealth(playerid, vida_temp);
        vida_temp -= 2.0;
        SetPlayerHealth(playerid, vida_temp);
        ShowNotification(playerid, "Tu personaje se esta ~b~deshidratandose~w~, bebe algo pronto!", 3000);
        if(Necesidades[playerid][N_Sed] < 0)
        {
            Necesidades[playerid][N_Sed] = 0.0;
        }
    }
    SetPlayerProgressBarValue(playerid, PlayerProgressBar[playerid][1], Necesidades[playerid][N_Hambre]);
    SetPlayerProgressBarValue(playerid, PlayerProgressBar[playerid][0], Necesidades[playerid][N_Sed]);
    return 1;
}
