/*
    Aca pondre las funciones de los objetos, como la radio, cajas fuertes,etc...
*/
#include <YSI\y_hooks>


//___________________CALLBACKS________________________//
hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (PRESSED( KEY_CROUCH ))
    {
        PickObject(playerid);
        return 0;
    }
    if (PRESSED( KEY_YES ))
    {
        OpenInv(playerid);
        return 0;
    }
    if (PRESSED( KEY_WALK ))
    {
        if(VE[playerid][Mano][DER] == AMMOM4)
        {
            if(GetPlayerWeapon(playerid) == WEAPON_M4)
            {
                GivePlayerWeapon(playerid, 31, 50);
                DestroyItemHand(playerid, DER);
                ShowInfoForPlayer(playerid, "~b~+30 balas", 3000);
            } else return ShowInfoForPlayer(playerid, "~r~Debes tener el arma en mano.", 3000);
        }
        else if(VE[playerid][Mano][DER] == M4)
        {
            GivePlayerWeapon(playerid, 31, 30);
            DestroyItemHand(playerid, DER);
            ShowInfoForPlayer(playerid, "~b~M4 ~w~equipada", 3000);
        }
        else if(VE[playerid][Mano][DER] == MP5)
        {
            GivePlayerWeapon(playerid, 29, 30);
            DestroyItemHand(playerid, DER);
            ShowInfoForPlayer(playerid, "~b~MP5 ~w~equipada", 3000);
        }
        else if(VE[playerid][Mano][DER] == DEAGLE)
        {
            GivePlayerWeapon(playerid, 24, 7);
            DestroyItemHand(playerid, DER);
            ShowInfoForPlayer(playerid, "~b~D.Eagle equipada", 3000);
        }
        else if(VE[playerid][Mano][DER] == AMMODK)
        {
            if(GetPlayerWeapon(playerid) == WEAPON_DEAGLE)
            {
                GivePlayerWeapon(playerid, 24, 7);
                DestroyItemHand(playerid, DER);
                ShowInfoForPlayer(playerid, "~b~D.Eagle equipada", 3000);
            } else return ShowInfoForPlayer(playerid, "~r~Debes tener el arma en mano.", 3000);
        }
        else if(VE[playerid][Mano][DER] == GUN9MM)
        {
            GivePlayerWeapon(playerid, 24, 15);
            DestroyItemHand(playerid, DER);
            ShowInfoForPlayer(playerid, "~b~D.Eagle equipada", 3000);
        }
        else if(VE[playerid][Mano][DER] == BOTELLADEAGUA)
        {
            if(Necesidades[playerid][N_Sed] >= 100.00)
            {
                ShowNotification(playerid, "Tu personaje no puede beber mas", 4000);
                return 1;
            }
            Necesidades[playerid][N_Sed]+=10.0;
            DestroyItemHand(playerid, DER);
            ShowInfoForPlayer(playerid, "~b~Botella de agua consumida", 3000);
            SetPlayerProgressBarValue(playerid, PlayerProgressBar[playerid][0], Necesidades[playerid][N_Sed]);
        }
        else if(VE[playerid][Mano][DER] == HAMBURGESA)
        {
            if(Necesidades[playerid][N_Hambre] >= 100.00)
            {
                ShowNotification(playerid, "Tu personaje no puede comer mas", 4000);
                return 1;
            }
            Necesidades[playerid][N_Hambre]+=7.0;
            DestroyItemHand(playerid, DER);
            ShowInfoForPlayer(playerid, "~b~Hamburgesa consumida", 3000);
            SetPlayerProgressBarValue(playerid, PlayerProgressBar[playerid][1], Necesidades[playerid][N_Hambre]);
        }
        else if(VE[playerid][Mano][DER] == RADIO)
        {
           if(Radio[playerid][GetRadio] == 1)
           {
               ShowInfoForPlayer(playerid, "~r~Ya tienes una radio equipada", 3000); 
           }
           else
           {
                DestroyItemHand(playerid, DER);
                ShowInfoForPlayer(playerid, "~b~Radio encendida", 3000); 
                Radio[playerid][GetRadio] = 1;
                Radio[playerid][Baterias] = 0;
           }
        }
        else if(VE[playerid][Mano][DER] == BATERIA)
        {
            if(Radio[playerid][GetRadio] == 1)
            {
                if(Radio[playerid][Baterias] < 10)
                {
                    if(Radio[playerid][Baterias] == 0)
                    {
                        Radio[playerid][RadioTimer] = SetTimerEx("BateriasRadio", 1200000, false, "d", playerid);
                    }
                    DestroyItemHand(playerid, DER);
                    Radio[playerid][Baterias]++;
                    new str[128];
                    format(str, sizeof(str), "~b~Baterias %d/10", Radio[playerid][Baterias]);
                    ShowInfoForPlayer(playerid, str, 3000);
                } else ShowInfoForPlayer(playerid, "~r~Tu radio ya esta cargada", 3000);
            } else ShowInfoForPlayer(playerid, "~r~No tienes una radio", 3000);
        }
        else ChangeHand(playerid);
    }
    return 1;
}

//__________________[FUNCIONES DE LA RADIO]___________________//
forward BateriasRadio(playerid);
public BateriasRadio(playerid)
{
    if(Radio[playerid][Baterias] > 0)
    {
        Radio[playerid][Baterias]--;
        Radio[playerid][RadioTimer] = SetTimerEx("BateriasRadio", 1200000, false, "d", playerid);
    }
}

stock RadioSupervivientes(string[])
{
    for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
    {
        SendClientMessage(i, -1, string);
    }
}