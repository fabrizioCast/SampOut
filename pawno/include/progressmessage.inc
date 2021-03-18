/*
    Include: Progress Message
    By: Sleek
*/
#include <YSI\y_hooks>


forward OnPlayerFinishProgress(playerid, typer);
//______________[Variables]______________//
new PlayerText:progressm[MAX_PLAYERS][2];
new PlayerBar:progressme[MAX_PLAYERS][1];


new bool:inprogress[MAX_PLAYERS];
new KeyProgress[MAX_PLAYERS];
new KeyPressed[MAX_PLAYERS];
new TypeItem[MAX_PLAYERS];
new Float:subir[MAX_PLAYERS];
new resourceids[MAX_PLAYERS];

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KeyProgress[playerid])
    {
        if(inprogress[playerid] == true)
        {
            subir[playerid] += 2; 
            SetPlayerProgressBarValue(playerid, progressme[playerid][0], subir[playerid]);
            KeyPressed[playerid]++;
            if(KeyPressed[playerid] > 50)
            {
                DestroyProgressMessage(playerid);
                OnPlayerFinishProgress(playerid, TypeItem[playerid]);
                return 1;
            }
        }
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    inprogress[playerid] = false;
    return 1;
}

public OnPlayerFinishProgress(playerid, typer)
{
    if(typer == 0)
    {
       GiveItem(playerid, 2, 2);
       DestroyResource(typer, resourceids[playerid]);
       ShowInfoForPlayer(playerid, "~b~+2 madera!", 3000);
    }
    if(typer == 1)
    {
       GiveItem(playerid, 3, 2);
       DestroyResource(typer, resourceids[playerid]);
       ShowInfoForPlayer(playerid, "~b~+2 mina de hierro!", 3000);
    }
    TogglePlayerControllable(playerid, 1);
    ApplyAnimation(playerid, "BOMBER", "BOM_PLANT", 4.1, 0, 0, 0, 0, 0);
    subir[playerid] = 0;
    KeyPressed[playerid] = 0;
    return 1;
}


stock DestroyProgressMessage(playerid)
{
    PlayerTextDrawHide(playerid, progressm[playerid][0]);
    PlayerTextDrawHide(playerid, progressm[playerid][1]);
    HidePlayerProgressBar(playerid, progressme[playerid][0]);
    SetPlayerProgressBarValue(playerid, progressme[playerid][0], 0.000000);
}
stock ShowProgressMessage(playerid, key, text[], type, resourceid)
{
    TogglePlayerControllable(playerid, 0);
    PlayerTextDrawSetString(playerid, progressm[playerid][0], text);
    PlayerTextDrawShow(playerid, progressm[playerid][0]);
    PlayerTextDrawShow(playerid, progressm[playerid][1]);
    SetPlayerProgressBarValue(playerid, progressme[playerid][0], 0.000000);
    ShowPlayerProgressBar(playerid, progressme[playerid][0]);
    subir[playerid] = 0;
    resourceids[playerid] = resourceid;
    TypeItem[playerid] = type;
    KeyProgress[playerid] = key;
    KeyPressed[playerid] = 0;
    inprogress[playerid] = true;
    return 1;
}

stock CargarTDProgress(playerid)
{
    progressm[playerid][0] = CreatePlayerTextDraw(playerid, 493.000000, 176.000000, "Preciona ~g~C ~w~para lograr talar el arbol ese");
    PlayerTextDrawFont(playerid, progressm[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, progressm[playerid][0], 0.216665, 1.450000);
    PlayerTextDrawTextSize(playerid, progressm[playerid][0], 619.000000, 105.000000);
    PlayerTextDrawSetOutline(playerid, progressm[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, progressm[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, progressm[playerid][0], 1);
    PlayerTextDrawColor(playerid, progressm[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, progressm[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, progressm[playerid][0], 75);
    PlayerTextDrawUseBox(playerid, progressm[playerid][0], 0);
    PlayerTextDrawSetProportional(playerid, progressm[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, progressm[playerid][0], 0);

    progressm[playerid][1] = CreatePlayerTextDraw(playerid, 557.000000, 169.000000, "_");
    PlayerTextDrawFont(playerid, progressm[playerid][1], 1);
    PlayerTextDrawLetterSize(playerid, progressm[playerid][1], 0.600000, 7.449996);
    PlayerTextDrawTextSize(playerid, progressm[playerid][1], 298.500000, 136.000000);
    PlayerTextDrawSetOutline(playerid, progressm[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, progressm[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, progressm[playerid][1], 2);
    PlayerTextDrawColor(playerid, progressm[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, progressm[playerid][1], 255);
    PlayerTextDrawBoxColor(playerid, progressm[playerid][1], 75);
    PlayerTextDrawUseBox(playerid, progressm[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, progressm[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, progressm[playerid][1], 0);
    //________________________Progress___________________________________________//
    progressme[playerid][0] = CreatePlayerProgressBar(playerid, 494.000000, 221.000000, 129.000000, 8.500000, -741092463, 100.000000, 0);
    SetPlayerProgressBarValue(playerid, progressme[playerid][0], 50.000000);
    SetPlayerProgressBarMaxValue(playerid, progressme[playerid][0], 100.000000);
}