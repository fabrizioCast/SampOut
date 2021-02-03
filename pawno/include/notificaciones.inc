
#include <zcmd>
#include <sscanf2>



new PlayerText:TD_Notificacion[MAX_PLAYERS][3];
new bool:notificacion[MAX_PLAYERS][3];
new timer[MAX_PLAYERS];


stock CrearTDNT(playerid)
{
    TD_Notificacion[playerid][0] = CreatePlayerTextDraw(playerid, 15.915312, 265.833557, "El mejor sistema de notificaciones ha sido creado correctamente");
    PlayerTextDrawLetterSize(playerid, TD_Notificacion[playerid][0], 0.250000, 1.200000);
    PlayerTextDrawTextSize(playerid, TD_Notificacion[playerid][0], 192.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, TD_Notificacion[playerid][0], 1);
    PlayerTextDrawColor(playerid, TD_Notificacion[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, TD_Notificacion[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, TD_Notificacion[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, TD_Notificacion[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TD_Notificacion[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TD_Notificacion[playerid][0], 255);
    PlayerTextDrawFont(playerid, TD_Notificacion[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, TD_Notificacion[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TD_Notificacion[playerid][0], 0);

    TD_Notificacion[playerid][1] = CreatePlayerTextDraw(playerid, 15.446791, 232.583755, "El mejor sistema de notificaciones ha sido creado correctamente");
    PlayerTextDrawLetterSize(playerid, TD_Notificacion[playerid][1], 0.250000, 1.200000);
    PlayerTextDrawTextSize(playerid, TD_Notificacion[playerid][1], 192.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, TD_Notificacion[playerid][1], 1);
    PlayerTextDrawColor(playerid, TD_Notificacion[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, TD_Notificacion[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, TD_Notificacion[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, TD_Notificacion[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TD_Notificacion[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TD_Notificacion[playerid][1], 255);
    PlayerTextDrawFont(playerid, TD_Notificacion[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, TD_Notificacion[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TD_Notificacion[playerid][1], 0);

    TD_Notificacion[playerid][2] = CreatePlayerTextDraw(playerid, 15.915312, 197.000579, "El mejor sistema de notificaciones ha sido creado correctamente");
    PlayerTextDrawLetterSize(playerid, TD_Notificacion[playerid][2], 0.250000, 1.200000);
    PlayerTextDrawTextSize(playerid, TD_Notificacion[playerid][2], 192.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, TD_Notificacion[playerid][2], 1);
    PlayerTextDrawColor(playerid, TD_Notificacion[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, TD_Notificacion[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, TD_Notificacion[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, TD_Notificacion[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TD_Notificacion[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, TD_Notificacion[playerid][2], 255);
    PlayerTextDrawFont(playerid, TD_Notificacion[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, TD_Notificacion[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TD_Notificacion[playerid][2], 0);

    for(new i;i<4;i++)
    {
        PlayerTextDrawHide(playerid, TD_Notificacion[playerid][i]);
        notificacion[playerid][i] = false;
    }
    return 1;
}

stock SendClientNotification(playerid, text[], time)
{
    if(notificacion[playerid][0] == false)
    {
        PlayerTextDrawSetString(playerid, TD_Notificacion[playerid][0], text);
        PlayerTextDrawShow(playerid, TD_Notificacion[playerid][0]);
        notificacion[playerid][0] = true;
        timer[playerid] = SetTimerEx("BorrarNotificacion", time, false, "dd", playerid, 0);
        return 1;
    } else if(notificacion[playerid][1] == false)
    {
        PlayerTextDrawSetString(playerid, TD_Notificacion[playerid][1], text);
        PlayerTextDrawShow(playerid, TD_Notificacion[playerid][1]);
        notificacion[playerid][1] = true;
        SetTimerEx("BorrarNotificacion", time, false, "dd", playerid, 1);
        return 1;
    } else if(notificacion[playerid][2] == false)
    {
        PlayerTextDrawSetString(playerid, TD_Notificacion[playerid][2], text);
        PlayerTextDrawShow(playerid, TD_Notificacion[playerid][2]);
        notificacion[playerid][2] = true;
        SetTimerEx("BorrarNotificacion", time, false, "dd", playerid, 2);
        return 1;
    } else{
        KillTimer(timer[playerid]);
        PlayerTextDrawSetString(playerid, TD_Notificacion[playerid][0], text);
        notificacion[playerid][0] = true;
        timer[playerid] = SetTimerEx("BorrarNotificacion", time, false, "dd", playerid, 0);
    }
    PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
    return 1;
}

forward BorrarNotificacion(playerid, textid);
public BorrarNotificacion(playerid, textid)
{
    PlayerTextDrawHide(playerid, TD_Notificacion[playerid][textid]);
    notificacion[playerid][textid] = false;
    return 1;
}