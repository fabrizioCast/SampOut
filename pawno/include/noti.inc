/*
    /================/
    Include by: Sleek
    /================/

*/

new PlayerText:mostarnotificaciones[MAX_PLAYERS][4];
new bool:notifcacion[MAX_PLAYERS][4];
new timernoti[MAX_PLAYERS];

stock CrearNoti(playerid)
{
    mostarnotificaciones[playerid][0] = CreatePlayerTextDraw(playerid, 11.000000, 307.000000, "Ysi no te merecia eee sii por que es lo que vamos a hacer chaminnn jijij hola");
    PlayerTextDrawFont(playerid, mostarnotificaciones[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, mostarnotificaciones[playerid][0], 0.233331, 1.500002);
    PlayerTextDrawTextSize(playerid, mostarnotificaciones[playerid][0], 186.000000, 165.000000);
    PlayerTextDrawSetOutline(playerid, mostarnotificaciones[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, mostarnotificaciones[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, mostarnotificaciones[playerid][0], 1);
    PlayerTextDrawColor(playerid, mostarnotificaciones[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, mostarnotificaciones[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, mostarnotificaciones[playerid][0], 252645335);
    PlayerTextDrawUseBox(playerid, mostarnotificaciones[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, mostarnotificaciones[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, mostarnotificaciones[playerid][0], 0);

    mostarnotificaciones[playerid][1] = CreatePlayerTextDraw(playerid, 11.000000, 273.000000, "Ysi no te merecia eee sii por que es lo que vamos a hacer chaminnn jijij hola");
    PlayerTextDrawFont(playerid, mostarnotificaciones[playerid][1], 1);
    PlayerTextDrawLetterSize(playerid, mostarnotificaciones[playerid][1], 0.233331, 1.500002);
    PlayerTextDrawTextSize(playerid, mostarnotificaciones[playerid][1], 186.000000, 165.000000);
    PlayerTextDrawSetOutline(playerid, mostarnotificaciones[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, mostarnotificaciones[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, mostarnotificaciones[playerid][1], 1);
    PlayerTextDrawColor(playerid, mostarnotificaciones[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, mostarnotificaciones[playerid][1], 255);
    PlayerTextDrawBoxColor(playerid, mostarnotificaciones[playerid][1], 252645335);
    PlayerTextDrawUseBox(playerid, mostarnotificaciones[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, mostarnotificaciones[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, mostarnotificaciones[playerid][1], 0);

    mostarnotificaciones[playerid][2] = CreatePlayerTextDraw(playerid, 11.000000, 238.000000, "Ysi no te merecia eee sii por que es lo que vamos a hacer chaminnn jijij hola");
    PlayerTextDrawFont(playerid, mostarnotificaciones[playerid][2], 1);
    PlayerTextDrawLetterSize(playerid, mostarnotificaciones[playerid][2], 0.233331, 1.500002);
    PlayerTextDrawTextSize(playerid, mostarnotificaciones[playerid][2], 186.000000, 165.000000);
    PlayerTextDrawSetOutline(playerid, mostarnotificaciones[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, mostarnotificaciones[playerid][2], 0);
    PlayerTextDrawAlignment(playerid, mostarnotificaciones[playerid][2], 1);
    PlayerTextDrawColor(playerid, mostarnotificaciones[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, mostarnotificaciones[playerid][2], 255);
    PlayerTextDrawBoxColor(playerid, mostarnotificaciones[playerid][2], 252645335);
    PlayerTextDrawUseBox(playerid, mostarnotificaciones[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, mostarnotificaciones[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, mostarnotificaciones[playerid][2], 0);

    mostarnotificaciones[playerid][3] = CreatePlayerTextDraw(playerid, 11.000000, 203.000000, "Ysi no te merecia eee sii por que es lo que vamos a hacer chaminnn jijij hola");
    PlayerTextDrawFont(playerid, mostarnotificaciones[playerid][3], 1);
    PlayerTextDrawLetterSize(playerid, mostarnotificaciones[playerid][3], 0.233331, 1.500002);
    PlayerTextDrawTextSize(playerid, mostarnotificaciones[playerid][3], 186.000000, 165.000000);
    PlayerTextDrawSetOutline(playerid, mostarnotificaciones[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, mostarnotificaciones[playerid][3], 0);
    PlayerTextDrawAlignment(playerid, mostarnotificaciones[playerid][3], 1);
    PlayerTextDrawColor(playerid, mostarnotificaciones[playerid][3], -1);
    PlayerTextDrawBackgroundColor(playerid, mostarnotificaciones[playerid][3], 255);
    PlayerTextDrawBoxColor(playerid, mostarnotificaciones[playerid][3], 252645335);
    PlayerTextDrawUseBox(playerid, mostarnotificaciones[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, mostarnotificaciones[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, mostarnotificaciones[playerid][3], 0);
    for(new i; i < 4; i++)
    {
        PlayerTextDrawHide(playerid, mostarnotificaciones[playerid][i]);
        notifcacion[playerid][i] = false;
    }
    return 1;
}

stock ShowNotification(playerid, text[], time)
{
    if(notifcacion[playerid][0] == false)
    {
        PlayerTextDrawSetString(playerid, mostarnotificaciones[playerid][0], text);
        PlayerTextDrawShow(playerid, mostarnotificaciones[playerid][0]);
        notifcacion[playerid][0] = true;
        timernoti[playerid] = SetTimerEx("BorrarNotificacion", time, false, "dd", playerid, 0);
        return 1;
    }
    else if(notifcacion[playerid][1] == false)
    {
        PlayerTextDrawSetString(playerid, mostarnotificaciones[playerid][1], text);
        PlayerTextDrawShow(playerid, mostarnotificaciones[playerid][1]);
        notifcacion[playerid][1] = true;
        timernoti[playerid] = SetTimerEx("BorrarNotificacion", time, false, "dd", playerid, 1);
        return 1;
    }
    else if(notifcacion[playerid][2] == false)
    {
        PlayerTextDrawSetString(playerid, mostarnotificaciones[playerid][2], text);
        PlayerTextDrawShow(playerid, mostarnotificaciones[playerid][2]);
        notifcacion[playerid][2] = true;
        timernoti[playerid] = SetTimerEx("BorrarNotificacion", time, false, "dd", playerid, 2);
        return 1;
    }
    else if(notifcacion[playerid][3] == false)
    {
        PlayerTextDrawSetString(playerid, mostarnotificaciones[playerid][3], text);
        PlayerTextDrawShow(playerid, mostarnotificaciones[playerid][3]);
        notifcacion[playerid][3] = true;
        timernoti[playerid] = SetTimerEx("BorrarNotificacion", time, false, "dd", playerid, 3);
        return 1;
    }
    return 1;
}
forward BorrarNotificacion(playerid, notiid);
public BorrarNotificacion(playerid, notiid)
{
    PlayerTextDrawHide(playerid, mostarnotificaciones[playerid][notiid]);
    notifcacion[playerid][notiid] = false;
    return 1;
}
stock ActualizarPosicion(playerid, notifID, textn[])
{
    for(new i; i < 4; i++)
    {
        if(notifcacion[playerid][i] == false)
        {
            for(new j; j < 4; j++)
            {
                if(notifcacion[playerid][j] == true)
                {
                    PlayerTextDrawSetString(playerid, notifcacion[playerid][i], textn);
                    PlayerTextDrawShow(playerid, notifcacion[playerid][i]);
                    PlayerTextDrawHide(playerid, notifcacion[playerid][j]);
                }
            }
        }
    }
    return 1;
}