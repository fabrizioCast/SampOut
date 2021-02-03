///// Movible_TD - By Wosbb

#if defined movible_td_included
	#endinput
#endif
#define movible_td_included

#define VERSION_INCLUDE "0.2"
#define CREDITOS "Wosbb"


new PlayerText:BOX_WOS[MAX_PLAYERS][2];


enum TD{
	Float:posicion_y,
	Timer[2]
};

new Text[MAX_PLAYERS][TD];


stock crearTextDrawPrueba(playerid)
{
	BOX_WOS[playerid][0] = CreatePlayerTextDraw(playerid, 99.000000, 169.000000, "_");
	PlayerTextDrawFont(playerid, BOX_WOS[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, BOX_WOS[playerid][0], 0.600000, 3.849996);
	PlayerTextDrawTextSize(playerid, BOX_WOS[playerid][0],  298.500000, Text[playerid][posicion_y]);
	PlayerTextDrawSetOutline(playerid, BOX_WOS[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, BOX_WOS[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, BOX_WOS[playerid][0], 2);
	PlayerTextDrawColor(playerid, BOX_WOS[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, BOX_WOS[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, BOX_WOS[playerid][0], 255);
	PlayerTextDrawUseBox(playerid, BOX_WOS[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, BOX_WOS[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, BOX_WOS[playerid][0], 0);

	BOX_WOS[playerid][1] = CreatePlayerTextDraw(playerid, 20.000000, 171.000000, "Anclado");
	PlayerTextDrawFont(playerid, BOX_WOS[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, BOX_WOS[playerid][1], 0.165833, 1.199999);
	PlayerTextDrawTextSize(playerid, BOX_WOS[playerid][1], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BOX_WOS[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, BOX_WOS[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, BOX_WOS[playerid][1], 1);
	PlayerTextDrawColor(playerid, BOX_WOS[playerid][1], -1);
	PlayerTextDrawBackgroundColor(playerid, BOX_WOS[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, BOX_WOS[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, BOX_WOS[playerid][1], 0);
	PlayerTextDrawSetProportional(playerid, BOX_WOS[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, BOX_WOS[playerid][1], 0);
	return 1;
}

forward IrBorrando(playerid);
public IrBorrando(playerid)
{
	PlayerTextDrawHide(playerid, BOX_WOS[playerid][0]);
	PlayerTextDrawDestroy(playerid, BOX_WOS[playerid][0]);
	PlayerTextDrawDestroy(playerid, BOX_WOS[playerid][1]);
	return 1;
}


forward Actualizando(playerid);
public Actualizando(playerid)
{
	if(Text[playerid][posicion_y] == 0.0) return IrBorrando(playerid);
	{
		Text[playerid][posicion_y] -= 1.5;
		PlayerTextDrawTextSize(playerid, BOX_WOS[playerid][0], 298.500000, Text[playerid][posicion_y]);
		PlayerTextDrawShow(playerid, BOX_WOS[playerid][0]);
	}

	return 1;
}
forward XD(playerid);
public XD(playerid)
{
	Text[playerid][Timer][0] = SetTimerEx("Actualizando", 3, true, "i", playerid);
	PlayerTextDrawHide(playerid, BOX_WOS[playerid][1]);
	return 0;
}
stock Notificacion(playerid, texto[], tiempo)
{
	KillTimer(Text[playerid][Timer][0]);
	KillTimer(Text[playerid][Timer][1]);
	IrBorrando(playerid);
	Text[playerid][posicion_y] = 165.000;
	crearTextDrawPrueba(playerid);
	PlayerTextDrawSetString(playerid,BOX_WOS[playerid][1], texto);
	PlayerTextDrawShow(playerid, BOX_WOS[playerid][0]);
	PlayerTextDrawShow(playerid, BOX_WOS[playerid][1]);
	Text[playerid][Timer][1] = SetTimerEx("XD", tiempo, false,"i", playerid);
	return 1;
}