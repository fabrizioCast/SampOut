#include "../Modulos/tutorial/map.inc"
#include <YSI\y_hooks>

 
new bool:InVault[MAX_PLAYERS];
 
forward DoorOpen1();
forward DoorOpen2();
forward DoorOpen3();
forward DoorClose1();
forward DoorClose2();
forward DoorClose3();
forward VaultStopped();

hook:OnGameModeInit()
{
    CargarMapeoTuto();
	Create3DTextLabel("Preciona [{FF6C00}H{FFFFFF}] para interactuar", -1, 2348.1279,-693.4337,117.3094, 5.0, 0);
	Create3DTextLabel("Preciona [{FF6C00}H{FFFFFF}] para interactuar", -1, 2352.8789,-674.0874,116.6405, 5.0, 0);
	Create3DTextLabel("Preciona [{FF6C00}H{FFFFFF}] para interactuar", -1, 2352.7734,-685.5914,117.3035, 5.0, 0);
	Create3DTextLabel("Preciona [{FF6C00}H{FFFFFF}] para interactuar", -1, 2357.3994,-648.3740,128.4521, 5.0, 0);
}

hook OnPlayerConnect(playerid)
{
	InVault[playerid] = false;
	//Removed cottage
	RemoveBuildingForPlayer(playerid, 3414, 2351.830, -652.921, 129.188, 0.250);
	RemoveBuildingForPlayer(playerid, 3421, 2351.830, -652.921, 129.188, 0.250);
	return 1;
}
hook:OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_CTRL_BACK)
	{
		if(IsPlayerInRangeOfPoint(playerid,3.0, 2357.9458,-648.4282,128.2592))
		{
		    if(!v_DoorsState)
		    {
		    	MoveDynamicObject(v_Door[0], 2356.932128, -649.176269, 128.298858, 0.001 ,10.545300, -44.007022, -10.728575);
		    	MoveDynamicObject(v_Door[1], 2356.932128, -647.656677, 128.298858, 0.001, 10.545289, 44.007022, -169.271377);
		    	v_DoorsState = true;
			}
			else
			{
			    MoveDynamicObject(v_Door[0], 2356.932128, -649.176269, 128.297851, 0.001, -45.000000, 0.000000, 90.000000);
		    	MoveDynamicObject(v_Door[1], 2356.932128, -647.656677, 128.297851, 0.001, -44.999977, -0.000029, 89.999938);
		    	v_DoorsState = false;
			}
		}
		if(IsPlayerInRangeOfPoint(playerid,2.0,2352.8767,-674.0881,116.6405) || IsPlayerInRangeOfPoint(playerid,2.0,2352.8081,-685.5921,117.3035))
	    {
	        if(v_Operating)return 1;
	        if(!v_State)
	        {
	            v_Operating = true;
	            MoveDynamicObject(v_Engine[0],2349.785888, -683.260559, 118.738502,2.0);
	            MoveDynamicObject(v_Engine[1],2349.785888, -683.260559, 118.098526,2.0);
	            MoveDynamicObject(v_Engine[2],2349.768310, -683.631774, 118.365005,2.0);
	            MoveDynamicObject(v_Engine[3],2349.775390, -681.142944, 118.127899,2.0);
	            MoveDynamicObject(v_Engine[4],2349.775390, -682.342651, 118.127899,2.0);
	            MoveDynamicObject(v_Engine[5],2349.766601, -681.953552, 119.527534,2.0);
	            MoveDynamicObject(v_Engine[6],2349.776611, -683.454162, 119.527534,2.0);
	            MoveDynamicObject(v_Engine[7],2349.783691, -683.584716, 120.821884,2.0);
	            MoveDynamicObject(v_Engine[8],2349.783691, -682.054809, 120.821884,2.0);
 
	            MoveDynamicObject(v_Rod[0],2350.389160, -675.981384, 115.151199,0.5);
	            MoveDynamicObject(v_Rod[1],2349.078613, -675.981384, 115.170211,0.5);
	            MoveDynamicObject(v_Rod[2],2350.389160, -675.981384, 121.090171,0.5);
	            MoveDynamicObject(v_Rod[3],2349.078613, -675.981384, 121.071159,0.5);
	            MoveDynamicObject(v_Rod[4],2352.736328, -675.981384, 117.465461,0.5);
	            MoveDynamicObject(v_Rod[5],2352.717285, -675.981384, 118.776008,0.5);
	            MoveDynamicObject(v_Rod[6],2346.805908, -675.981384, 118.776008,0.5);
	            MoveDynamicObject(v_Rod[7],2346.824951, -675.981384, 117.465461,0.5);
	            MoveDynamicObject(v_Rod[8],2350.389160, -677.041442, 115.151199,0.5);
	            MoveDynamicObject(v_Rod[9],2349.078613, -677.041442, 115.170211,0.5);
	            MoveDynamicObject(v_Rod[10],2350.389160, -677.041442, 121.090171,0.5);
	            MoveDynamicObject(v_Rod[11],2349.078613, -677.041442, 121.071159,0.5);
	            MoveDynamicObject(v_Rod[12],2352.736328, -677.041442, 117.465461,0.5);
	            MoveDynamicObject(v_Rod[13],2352.717285, -677.041442, 118.776008,0.5);
	            MoveDynamicObject(v_Rod[14],2346.805908, -677.041442, 118.776008,0.5);
	            MoveDynamicObject(v_Rod[15],2346.824951, -677.041442, 117.465461,0.5);
 
	            SetDynamicObjectMaterialText(v_Scroll, 0, "PLEASE STAND BY!", 110, "Ariel", 40, 0, 0xFFE8CD31, 0xFF070707, 1);
	            SetTimer("DoorOpen1",2500,false);
	        }
	        else
	        {
	            v_Operating = true;
	            SetDynamicObjectMaterialText(v_Scroll, 0, "PLEASE STAND BY!", 110, "Ariel", 40, 0, 0xFFE8CD31, 0xFF070707, 1);
	            MoveDynamicObject(v_Engine[0],2349.785888, -683.290527, 118.738502,1.0);
    			MoveDynamicObject(v_Engine[1],2349.785888, -683.290527, 118.098526,1.0);
			    MoveDynamicObject(v_Engine[2],2349.768310, -683.661743, 118.365005,1.0);
			    MoveDynamicObject(v_Engine[3],2349.775390, -681.172912, 118.127899,1.0);
			    MoveDynamicObject(v_Engine[4],2349.775390, -682.372619, 118.127899,1.0);
			    MoveDynamicObject(v_Engine[5],2349.766601, -681.983520, 119.527534,1.0);
			    MoveDynamicObject(v_Engine[6],2349.776611, -683.484130, 119.527534,1.0);
			    MoveDynamicObject(v_Engine[7],2349.783691, -683.614685, 120.821884,1.0);
			    MoveDynamicObject(v_Engine[8],2349.783691, -682.084777, 120.821884,1.0);
			    MoveDynamicObject(v_MainDoor,2349.765869, -678.225061, 118.112266,1.0, 89.999992, 90.000030, -89.999961);
	            SetTimer("DoorClose1", 5000,false);
	        }
	    }
	    if(IsPlayerInRangeOfPoint(playerid,2.0,2347.9746,-692.3457,117.3035) || IsPlayerInRangeOfPoint(playerid,2.0,2348.2285,-693.4334,117.3094))
	    {
	        if(IsDynamicObjectMoving(v_SafeDoor))return 1;
	        if(!v_sdState)
	        {
	            v_sdState = true;
	            MoveDynamicObject(v_SafeDoor,2350.605712, -692.847351, 117.933525, 0.1 ,0.000000, 0.000000, -105.300003);
	        }
	        else
	        {
	            v_sdState = false;
	            MoveDynamicObject(v_SafeDoor,2350.531738, -692.954467, 117.933525, 0.1 ,0.000000, 0.000000, 0.000000);
	        }
		}
	}
	return 1;
}

public DoorClose1()
{
    MoveDynamicObject(v_Engine[0],2349.785888, -680.948852, 118.738502,1.0);
	MoveDynamicObject(v_Engine[1],2349.785888, -680.948852, 118.098526,1.0);
	MoveDynamicObject(v_Engine[2],2349.768310, -681.320068, 118.365005,1.0);
	MoveDynamicObject(v_Engine[3],2349.775390, -678.831237, 118.127899,1.0);
	MoveDynamicObject(v_Engine[4],2349.775390, -680.030944, 118.127899,1.0);
	MoveDynamicObject(v_Engine[5],2349.766601, -679.641845, 119.527534,1.0);
	MoveDynamicObject(v_Engine[6],2349.776611, -681.142456, 119.527534,1.0);
	MoveDynamicObject(v_Engine[7],2349.783691, -681.273010, 120.821884,1.0);
	MoveDynamicObject(v_Engine[8],2349.783691, -679.743103, 120.821884,1.0);
	MoveDynamicObject(v_MainDoor,2349.765869, -675.783386, 118.112266,1.0);
	SetTimer("DoorClose2",2500,false);
	return 1;
}
public DoorClose2()
{
    MoveDynamicObject(v_Engine[0],2349.785888, -683.290527, 118.738502,2.0);
    MoveDynamicObject(v_Engine[1],2349.785888, -683.290527, 118.098526,2.0);
    MoveDynamicObject(v_Engine[2],2349.768310, -683.661743, 118.365005,2.0);
    MoveDynamicObject(v_Engine[3],2349.775390, -681.172912, 118.127899,2.0);
    MoveDynamicObject(v_Engine[4],2349.775390, -682.372619, 118.127899,2.0);
    MoveDynamicObject(v_Engine[5],2349.766601, -681.983520, 119.527534,2.0);
    MoveDynamicObject(v_Engine[6],2349.776611, -683.484130, 119.527534,2.0);
    MoveDynamicObject(v_Engine[7],2349.783691, -683.614685, 120.821884,2.0);
    MoveDynamicObject(v_Engine[8],2349.783691, -682.084777, 120.821884,2.0);
 
    MoveDynamicObject(v_Rod[0],2350.389160, -675.981384, 115.821189,0.5);
    MoveDynamicObject(v_Rod[1],2349.078613, -675.981384, 115.840202,0.5);
    MoveDynamicObject(v_Rod[2],2350.389160, -675.981384, 120.400199,0.5);
    MoveDynamicObject(v_Rod[3],2349.078613, -675.981384, 120.381187,0.5);
	MoveDynamicObject(v_Rod[4],2352.075683, -675.981384, 117.465461,0.5);
	MoveDynamicObject(v_Rod[5],2352.056640, -675.981384, 118.776008,0.5);
	MoveDynamicObject(v_Rod[6],2347.476562, -675.981384, 118.776008,0.5);
	MoveDynamicObject(v_Rod[7],2347.495605, -675.981384, 117.465461,0.5);
	MoveDynamicObject(v_Rod[8],2350.389160, -677.041442, 115.821189,0.5);
	MoveDynamicObject(v_Rod[9],2349.078613, -677.041442, 115.840202,0.5);
	MoveDynamicObject(v_Rod[10],2350.389160, -677.041442, 120.400199,0.5);
	MoveDynamicObject(v_Rod[11],2349.078613, -677.041442, 120.381187,0.5);
	MoveDynamicObject(v_Rod[12],2352.075683, -677.041442, 117.465461,0.5);
	MoveDynamicObject(v_Rod[13],2352.056640, -677.041442, 118.776008,0.5);
	MoveDynamicObject(v_Rod[14],2347.476562, -677.041442, 118.776008,0.5);
	MoveDynamicObject(v_Rod[15],2347.495605, -677.041442, 117.465461,0.5);
	SetTimer("DoorClose3", 2500,false);
	return 1;
}
public DoorClose3()
{
    MoveDynamicObject(v_Engine[0],2354.460449, -683.260559, 118.738502,2.0);
    MoveDynamicObject(v_Engine[1],2354.460449, -683.260559, 118.098526,2.0);
    MoveDynamicObject(v_Engine[2],2354.442871, -683.631774, 118.365005,2.0);
    MoveDynamicObject(v_Engine[3],2354.449951, -681.142944, 118.127899,2.0);
    MoveDynamicObject(v_Engine[4],2354.449951, -682.342651, 118.127899,2.0);
    MoveDynamicObject(v_Engine[5],2354.441162, -681.953552, 119.527534,2.0);
    MoveDynamicObject(v_Engine[6],2354.451171, -683.454162, 119.527534,2.0);
    MoveDynamicObject(v_Engine[7],2354.458251, -683.584716, 120.821884,2.0);
    MoveDynamicObject(v_Engine[8],2354.458251, -682.054809, 120.821884,2.0);
    v_State = false;
	SetTimer("VaultStopped",1000,false);
	return 1;
}
 
public DoorOpen1()
{
	MoveDynamicObject(v_Engine[0],2349.785888, -680.948852, 118.738502,2.0);
	MoveDynamicObject(v_Engine[1],2349.785888, -680.948852, 118.098526,2.0);
	MoveDynamicObject(v_Engine[2],2349.768310, -681.320068, 118.365005,2.0);
	MoveDynamicObject(v_Engine[3],2349.775390, -678.831237, 118.127899,2.0);
	MoveDynamicObject(v_Engine[4],2349.775390, -680.030944, 118.127899,2.0);
	MoveDynamicObject(v_Engine[5],2349.766601, -679.641845, 119.527534,2.0);
	MoveDynamicObject(v_Engine[6],2349.776611, -681.142456, 119.527534,2.0);
	MoveDynamicObject(v_Engine[7],2349.783691, -681.273010, 120.821884,2.0);
	MoveDynamicObject(v_Engine[8],2349.783691, -679.743103, 120.821884,2.0);
	SetTimer("DoorOpen2",1200,false);
	return 1;
}
public DoorOpen2()
{
    MoveDynamicObject(v_Engine[0],2349.785888, -683.290527, 118.738502,1.0);
    MoveDynamicObject(v_Engine[1],2349.785888, -683.290527, 118.098526,1.0);
    MoveDynamicObject(v_Engine[2],2349.768310, -683.661743, 118.365005,1.0);
    MoveDynamicObject(v_Engine[3],2349.775390, -681.172912, 118.127899,1.0);
    MoveDynamicObject(v_Engine[4],2349.775390, -682.372619, 118.127899,1.0);
    MoveDynamicObject(v_Engine[5],2349.766601, -681.983520, 119.527534,1.0);
    MoveDynamicObject(v_Engine[6],2349.776611, -683.484130, 119.527534,1.0);
    MoveDynamicObject(v_Engine[7],2349.783691, -683.614685, 120.821884,1.0);
    MoveDynamicObject(v_Engine[8],2349.783691, -682.084777, 120.821884,1.0);
    MoveDynamicObject(v_MainDoor,2349.765869, -678.225061, 118.112266,1.0);
    SetTimer("DoorOpen3",2500,false);
	return 1;
}
public DoorOpen3()
{
    MoveDynamicObject(v_Engine[0],2354.869873, -683.290527, 118.738502,1.0);
    MoveDynamicObject(v_Engine[1],2354.869873, -683.290527, 118.098526,1.0);
    MoveDynamicObject(v_Engine[2],2354.852294, -683.661743, 118.365005,1.0);
    MoveDynamicObject(v_Engine[3],2354.859375, -681.172912, 118.127899,1.0);
    MoveDynamicObject(v_Engine[4],2354.859375, -682.372619, 118.127899,1.0);
    MoveDynamicObject(v_Engine[5],2354.850585, -681.983520, 119.527534,1.0);
    MoveDynamicObject(v_Engine[6],2354.860595, -683.484130, 119.527534,1.0);
    MoveDynamicObject(v_Engine[7],2354.867675, -683.614685, 120.821884,1.0);
    MoveDynamicObject(v_Engine[8],2354.867675, -682.084777, 120.821884,1.0);
    MoveDynamicObject(v_MainDoor,2354.849853, -678.225061, 118.112266,1.0,0.199790, 90.000083, -89.999961);
    v_State = true;
	SetTimer("VaultStopped",4000,false);
    return 1;
}
public VaultStopped()
{
    v_Operating = false;
    SetDynamicObjectMaterialText(v_Scroll, 0, "  ", 110, "Ariel", 40, 0, 0xFFE8CD31, 0xFF070707, 1);
	return 1;
}