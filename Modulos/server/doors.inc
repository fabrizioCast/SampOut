#include <YSI\y_hooks>


hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_CTRL_BACK))
    {
        if(IsPlayerInRangeOfPoint(playerid, 5.0, 1172.0769,-1323.3700,15.4030)) //Exterior Hospital
        {
            CongelarPlayer(playerid, 3000);
            SetPlayerPos(playerid, 1402.7000,-25.9069,1000.8640);
        }
        if(IsPlayerInRangeOfPoint(playerid, 5.0, 1402.7000,-25.9069,1000.8640)) //Interior Hospital
        {
            CongelarPlayer(playerid, 3000);
            SetPlayerPos(playerid, 1172.0769,-1323.3700,15.4030);
        }
    }
}

stock LabelsDoors()
{
    //__________________________________Hospital_____________________________________//
    CreatePickup(19133, 1, 1172.0769,-1323.3700,15.4030); //Exterior
    Create3DTextLabel("Preciona {FFC900}H {ffffff}para interactuar", -1, 1172.0769,-1323.3700,15.4030, 5.0, 0);
    CreatePickup(19133, 1, 1402.7000,-25.9069,1000.8640); //Interior
    Create3DTextLabel("Preciona {FFC900}H {ffffff}para interactuar", -1, 1402.7000,-25.9069,1000.8640, 5.0, 0);
}