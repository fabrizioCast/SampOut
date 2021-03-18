//________________________________________________________________________________//
stock CargarTds(playerid)
{
    CrearTDDeSIFP(playerid);
    CrearTDShowObject(playerid);
    CrearNoti(playerid);
    CargarTDProgress(playerid);
    CargarBotonesApariencia(playerid);
    CargarPlayerInventario(playerid);
    CargarClave2(playerid);
    CargarEmail2(playerid);
    CargarEdad2(playerid);
    CargarLogin2(playerid);
    MostrarLogo(playerid);
    MostrarTerritorios(playerid);
    PlayerTDCofre(playerid);
}


//______________STOCKS_______________//
stock SaveAccount(playerid)
{
    if(CuentaInfo[playerid][Logeado] == 1)
    {
        if(SQL::RowExists("usuarios", "ID", CuentaInfo[playerid][ID]))
        {
            CuentaInfo[playerid][Skin] = GetPlayerSkin(playerid);
            GetPlayerPos(playerid, CuentaInfo[playerid][PosX], CuentaInfo[playerid][PosY], CuentaInfo[playerid][PosZ]);
            new handle = SQL::Open(SQL::UPDATE, "usuarios", "ID", CuentaInfo[playerid][ID]);
            SQL::WriteString(handle, "Nombre", ret_pName(playerid));
            SQL::WriteString(handle, "Password", CuentaInfo[playerid][Password]);
            SQL::WriteInt(handle, "Edad", CuentaInfo[playerid][Edad]);
            SQL::WriteInt(handle, "Skin", CuentaInfo[playerid][Skin]);
            SQL::WriteFloat(handle, "PosX", CuentaInfo[playerid][PosX]);
            SQL::WriteFloat(handle, "PosY", CuentaInfo[playerid][PosY]);
            SQL::WriteFloat(handle, "PosZ", CuentaInfo[playerid][PosZ]);
            SQL::WriteFloat(handle, "Hambre", Necesidades[playerid][N_Hambre]);
            SQL::WriteFloat(handle, "Sed", Necesidades[playerid][N_Sed]);
            SQL::WriteFloat(handle, "Vida", CuentaInfo[playerid][Vida]);
            SQL::WriteInt(handle, "Coin", CuentaInfo[playerid][Coin]);
            SQL::WriteInt(handle, "GrupoID", ClanPlayer[playerid][Cp_ID]);
            SQL::WriteInt(handle, "Grupo", ClanPlayer[playerid][Cp_Grupo]);
            SQL::WriteInt(handle, "GrupoLider", ClanPlayer[playerid][Cp_Lider]);
            SQL::Close(handle);
        }
        if(SQL::RowExists("inventario", "ID", CuentaInfo[playerid][ID]))
        {
            new handle = SQL::Open(SQL::UPDATE, "inventario", "ID", CuentaInfo[playerid][ID]);
            SQL::WriteInt(handle, "Slot1", VE[playerid][Inv][0]);
            SQL::WriteInt(handle, "Slot2", VE[playerid][Inv][1]);
            SQL::WriteInt(handle, "Slot3", VE[playerid][Inv][2]);
            SQL::WriteInt(handle, "Slot4", VE[playerid][Inv][3]);
            SQL::WriteInt(handle, "Slot5", VE[playerid][Inv][4]);
            SQL::WriteInt(handle, "Slot6", VE[playerid][Inv][5]);
            SQL::WriteInt(handle, "Slot7", VE[playerid][Inv][6]);
            SQL::WriteInt(handle, "Slot8", VE[playerid][Inv][7]);
            SQL::WriteInt(handle, "Slot9", VE[playerid][Inv][8]);
            SQL::WriteInt(handle, "Slot10", VE[playerid][Inv][9]);
            SQL::WriteInt(handle, "Slot11", VE[playerid][Inv][10]);
            SQL::WriteInt(handle, "Slot12", VE[playerid][Inv][11]);
            SQL::WriteInt(handle, "Slot13", VE[playerid][Inv][12]);
            SQL::WriteInt(handle, "Slot14", VE[playerid][Inv][13]);
            SQL::WriteInt(handle, "Slot15", VE[playerid][Inv][14]);
            SQL::WriteInt(handle, "Usos1", VE[playerid][usos][VE[playerid][Inv][0]]);
            SQL::WriteInt(handle, "Usos2", VE[playerid][usos][VE[playerid][Inv][1]]);
            SQL::WriteInt(handle, "Usos3", VE[playerid][usos][VE[playerid][Inv][2]]);
            SQL::WriteInt(handle, "Usos4", VE[playerid][usos][VE[playerid][Inv][3]]);
            SQL::WriteInt(handle, "Usos5", VE[playerid][usos][VE[playerid][Inv][4]]);
            SQL::WriteInt(handle, "Usos6", VE[playerid][usos][VE[playerid][Inv][5]]);
            SQL::WriteInt(handle, "Usos7", VE[playerid][usos][VE[playerid][Inv][6]]);
            SQL::WriteInt(handle, "Usos8", VE[playerid][usos][VE[playerid][Inv][7]]);
            SQL::WriteInt(handle, "Usos9", VE[playerid][usos][VE[playerid][Inv][8]]);
            SQL::WriteInt(handle, "Usos10", VE[playerid][usos][VE[playerid][Inv][9]]);
            SQL::WriteInt(handle, "Usos11", VE[playerid][usos][VE[playerid][Inv][10]]);
            SQL::WriteInt(handle, "Usos12", VE[playerid][usos][VE[playerid][Inv][11]]);
            SQL::WriteInt(handle, "Usos13", VE[playerid][usos][VE[playerid][Inv][12]]);
            SQL::WriteInt(handle, "Usos14", VE[playerid][usos][VE[playerid][Inv][13]]);
            SQL::WriteInt(handle, "Usos15", VE[playerid][usos][VE[playerid][Inv][14]]);
            SQL::Close(handle);
        }
        if(SQL::RowExists("objetosplayer", "ID", CuentaInfo[playerid][ID]))
        {
            new handle3 = SQL::Open(SQL::UPDATE, "objetosplayer", "ID", CuentaInfo[playerid][ID]);
            SQL::WriteInt(handle3, "ID",CuentaInfo[playerid][ID]);
            SQL::WriteString(handle3, "Nombre", ret_pName(playerid));
            SQL::WriteInt(handle3, "GetRadio", Radio[playerid][GetRadio]);
            SQL::WriteInt(handle3, "BateriasRadio", Radio[playerid][Baterias]);
            SQL::Close(handle3);
        }
        CuentaInfo[playerid][Logeado] = 0;
        PassYes[playerid] = 0;
        Pasos[playerid] = 0;
        MaxIntentos[playerid] = 0;
    }
    return 1;
}
stock CargarDataPlayer(playerid)
{
    new handle = SQL::Open(SQL::READ, "usuarios", "ID", CuentaInfo[playerid][ID]);
    SQL::ReadInt(handle, "Edad", CuentaInfo[playerid][Edad]);
    SQL::ReadInt(handle, "Skin", CuentaInfo[playerid][Skin]);
    SQL::ReadFloat(handle, "PosX", CuentaInfo[playerid][PosX]);
    SQL::ReadFloat(handle, "PosY", CuentaInfo[playerid][PosY]);
    SQL::ReadFloat(handle, "PosZ", CuentaInfo[playerid][PosZ]);
    SQL::ReadFloat(handle, "Sed", Necesidades[playerid][N_Hambre]);
    SQL::ReadFloat(handle, "Hambre", Necesidades[playerid][N_Hambre]);
    SQL::ReadFloat(handle, "Vida", CuentaInfo[playerid][Vida]);
    SQL::ReadInt(handle, "Coin", CuentaInfo[playerid][Coin]);
    SQL::ReadInt(handle, "GrupoID", ClanPlayer[playerid][Cp_ID]);
    SQL::ReadInt(handle, "Grupo", ClanPlayer[playerid][Cp_Grupo]);
    SQL::ReadInt(handle, "GrupoLider", ClanPlayer[playerid][Cp_Lider]);
    SQL::Close(handle);
    SetPlayerPos(playerid, CuentaInfo[playerid][PosX], CuentaInfo[playerid][PosY], CuentaInfo[playerid][PosZ]);
    SetPlayerSkin(playerid, CuentaInfo[playerid][Skin]);
    SetPlayerProgressBarValue(playerid, PlayerProgressBar[playerid][1], Necesidades[playerid][N_Hambre]);
    SetPlayerProgressBarValue(playerid, PlayerProgressBar[playerid][0], Necesidades[playerid][N_Sed]);
    new handle2 = SQL::Open(SQL::READ, "inventario", "ID", CuentaInfo[playerid][ID]);
    SQL::ReadInt(handle2, "Slot1", VE[playerid][Inv][0]);
    SQL::ReadInt(handle2, "Slot2", VE[playerid][Inv][1]);
    SQL::ReadInt(handle2, "Slot3", VE[playerid][Inv][2]);
    SQL::ReadInt(handle2, "Slot4", VE[playerid][Inv][3]);
    SQL::ReadInt(handle2, "Slot5", VE[playerid][Inv][4]);
    SQL::ReadInt(handle2, "Slot6", VE[playerid][Inv][5]);
    SQL::ReadInt(handle2, "Slot7", VE[playerid][Inv][6]);
    SQL::ReadInt(handle2, "Slot8", VE[playerid][Inv][7]);
    SQL::ReadInt(handle2, "Slot9", VE[playerid][Inv][8]);
    SQL::ReadInt(handle2, "Slot10", VE[playerid][Inv][9]);
    SQL::ReadInt(handle2, "Slot11", VE[playerid][Inv][10]);
    SQL::ReadInt(handle2, "Slot12", VE[playerid][Inv][11]);
    SQL::ReadInt(handle2, "Slot13", VE[playerid][Inv][12]);
    SQL::ReadInt(handle2, "Slot14", VE[playerid][Inv][13]);
    SQL::ReadInt(handle2, "Slot15", VE[playerid][Inv][14]);
    SQL::ReadInt(handle2, "Usos1",  VE[playerid][usos][VE[playerid][Inv][0]]);
    SQL::ReadInt(handle2, "Usos2",  VE[playerid][usos][VE[playerid][Inv][1]]);
    SQL::ReadInt(handle2, "Usos3",  VE[playerid][usos][VE[playerid][Inv][2]]);
    SQL::ReadInt(handle2, "Usos4",  VE[playerid][usos][VE[playerid][Inv][3]]);
    SQL::ReadInt(handle2, "Usos5",  VE[playerid][usos][VE[playerid][Inv][4]]);
    SQL::ReadInt(handle2, "Usos6",  VE[playerid][usos][VE[playerid][Inv][5]]);
    SQL::ReadInt(handle2, "Usos7",  VE[playerid][usos][VE[playerid][Inv][6]]);
    SQL::ReadInt(handle2, "Usos8",  VE[playerid][usos][VE[playerid][Inv][7]]);
    SQL::ReadInt(handle2, "Usos9",  VE[playerid][usos][VE[playerid][Inv][8]]);
    SQL::ReadInt(handle2, "Usos10",  VE[playerid][usos][VE[playerid][Inv][9]]);
    SQL::ReadInt(handle2, "Usos11",  VE[playerid][usos][VE[playerid][Inv][10]]);
    SQL::ReadInt(handle2, "Usos12",  VE[playerid][usos][VE[playerid][Inv][11]]);
    SQL::ReadInt(handle2, "Usos13",  VE[playerid][usos][VE[playerid][Inv][12]]);
    SQL::ReadInt(handle2, "Usos14",  VE[playerid][usos][VE[playerid][Inv][13]]);
    SQL::ReadInt(handle2, "Usos15",  VE[playerid][usos][VE[playerid][Inv][14]]);
    SQL::Close(handle2);
    new handle3 = SQL::Open(SQL::READ, "objetosplayer", "ID", CuentaInfo[playerid][ID]);
    SQL::ReadInt(handle3, "GetRadio", Radio[playerid][GetRadio]);
    SQL::ReadInt(handle3, "BateriasRadio", Radio[playerid][Baterias]);
    SQL::Close(handle3);
    timerobjetos[playerid] = SetTimerEx("MostrarOb", 4000, true, "d", playerid);
    if(Radio[playerid][Baterias] > 0)
    {
        Radio[playerid][RadioTimer] = SetTimerEx("BateriasRadio", 1200000, false, "d", playerid);
    }
    return 1;
}






stock ProxDetector(Float:radi, playerid, string[],col1,col2,col3,col4,col5)
{
	if(IsPlayerConnected(playerid))
	{
		
		new BigEar[MAX_PLAYERS];
		new Float:posx, Float:posy, Float:posz;
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;
		GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		for (new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
		{
			
			if(IsPlayerConnected(i) && (GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(i)))
			{
				
				if(!BigEar[i])
				{
					
					GetPlayerPos(i, posx, posy, posz);
					tempposx = (oldposx -posx);
					tempposy = (oldposy -posy);
					tempposz = (oldposz -posz);
					if (((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16)))
					{
						
						SendClientMessageEx(i, col1, string);
					}
					else if (((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8)))
					{
						
						SendClientMessageEx(i, col2, string);
					}
					else if (((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4)))
					{
						
						SendClientMessageEx(i, col3, string);
					}
					else if (((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2)))
					{
						
						SendClientMessageEx(i, col4, string);
					}
					else if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
					{
						
						SendClientMessageEx(i, col5, string);
					}
				}
				else
				{
					
					SendClientMessageEx(i, col1, string);
				}
			}
		}
	}
	return 1;
}
stock SendClientMessageEx(playerid, color, const text[], {Float, _}:...)
{
	static
	args,
	str[144];

	if ((args = numargs()) == 3)
	{
		
		SendClientMessage(playerid, color, text);
	}
	else
	{
		
		while (--args >= 3)
		{
			
			#emit LCTRL 5
			#emit LOAD.alt args
			#emit SHL.C.alt 2
			#emit ADD.C 12
			#emit ADD
			#emit LOAD.I
			#emit PUSH.pri
		}
		#emit PUSH.S text
		#emit PUSH.C 144
		#emit PUSH.C str
		#emit PUSH.S 8
		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

		SendClientMessage(playerid, color, str);

		#emit RETN
	}
	return 1;
}

NombreJugador(playerid)
{
    new Nombrer[24];
    GetPlayerName(playerid,Nombrer,24);
    new N[24];
    strmid(N,Nombrer,0,strlen(Nombrer),24);
    for(new i = 0; i < MAX_PLAYER_NAME; i++)
    {
        if (N[i] == '_') N[i] = ' ';
    }
    return N;
}

stock ret_pName(playerid)
{
    new namee[24];
    GetPlayerName(playerid, namee, sizeof(namee));
    return namee;
}

new temp_timer[MAX_PLAYERS];
stock CongelarPlayer(playerid, time)
{
    KillTimer(temp_timer[playerid]);
    TogglePlayerControllable(playerid, 0);
    temp_timer[playerid] = SetTimerEx("CongelarPlayerT", time, false, "d", playerid);
    return 1;
}

forward CongelarPlayerT(playerid);
public CongelarPlayerT(playerid)
{
    TogglePlayerControllable(playerid, 1);
    return 1;
}

stock GetName(playerid) 
{
	new namer[MAX_PLAYER_NAME];
	GetPlayerName(playerid, namer, sizeof(namer));
	return namer;
}

clearChat(playerid)
{
	for(new i; i<50; i++)
	{
		SendClientMessage(playerid, -1, "");
	}
	return 1;
}

IsNumeric(const string[])
{
    return !sscanf(string, "{d}");
}

stock HexToRGBA(colour, &r, &g, &b, &a) //By Betamaster
{
    r = (colour >> 24) & 0xFF;
    g = (colour >> 16) & 0xFF;
    b = (colour >> 8) & 0xFF;
    a = colour & 0xFF;
}

stock RGBAToHex(r, g, b, a) //By Betamaster
{
    return (r<<24 | g<<16 | b<<8 | a);
}