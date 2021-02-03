


#define CREADOR "Wosbb"

#define MAX_BARS_WOS 20


#define COLOR_DEFAULT 404232447




enum wosbar{
	bar_id,
	PlayerText:bar_barra,
	Float:pos_y[2],
	Float:pos_z[2],
	porcentaje_bar
};

new barwos[MAX_PLAYERS][MAX_BARS_WOS][wosbar];

stock CreatePlayerLoadBar(playerid, idbar, Float:posy_1,Float:posy_2, Float:posz_1, Float:posz_2, porcentaje, color = COLOR_DEFAULT)
{
	new strw[24];
	format(strw, 24, "%d%", porcentaje);


	barwos[playerid][idbar][bar_barra] = CreatePlayerTextDraw(playerid, posy_1, posz_1, strw);
	PlayerTextDrawFont(playerid, barwos[playerid][idbar][bar_barra], 1);
	PlayerTextDrawLetterSize(playerid, barwos[playerid][idbar][bar_barra], 0.241666, 1.049998);
	PlayerTextDrawTextSize(playerid, barwos[playerid][idbar][bar_barra], posy_2,posz_2);
	PlayerTextDrawSetOutline(playerid, barwos[playerid][idbar][bar_barra], 0);
	PlayerTextDrawSetShadow(playerid, barwos[playerid][idbar][bar_barra], 0);
	PlayerTextDrawAlignment(playerid, barwos[playerid][idbar][bar_barra], 2);
	PlayerTextDrawColor(playerid, barwos[playerid][idbar][bar_barra], -1);
	PlayerTextDrawBackgroundColor(playerid, barwos[playerid][idbar][bar_barra], 255);
	PlayerTextDrawBoxColor(playerid,barwos[playerid][idbar][bar_barra], color);
	PlayerTextDrawUseBox(playerid, barwos[playerid][idbar][bar_barra], 1);
	PlayerTextDrawSetProportional(playerid, barwos[playerid][idbar][bar_barra], 1);
	PlayerTextDrawSetSelectable(playerid, barwos[playerid][idbar][bar_barra], 0);


	PlayerTextDrawShow(playerid, barwos[playerid][idbar][bar_barra]);

	barwos[playerid][idbar][pos_y][0] = posy_1;
	barwos[playerid][idbar][pos_y][1] = posy_2;
	barwos[playerid][idbar][pos_z][0] = posz_1;
	barwos[playerid][idbar][pos_z][1] = posz_2;
	barwos[playerid][idbar][porcentaje_bar] = porcentaje;


	return true;
}



forward UpdatePlayerLoadBar(playerid, idbar, cantidad);
public UpdatePlayerLoadBar(playerid, idbar, cantidad)
{
	new strw[24];
	format(strw, 24, "%d%", cantidad);

	PlayerTextDrawSetString(playerid, barwos[playerid][idbar][bar_barra], strw);
	PlayerTextDrawShow(playerid, barwos[playerid][idbar][bar_barra]);
	return true;
}


forward DestroyPlayerLoadBar(playerid, idbar);
public DestroyPlayerLoadBar(playerid, idbar)
{
	PlayerTextDrawHide(playerid, barwos[playerid][idbar][bar_barra]);
	PlayerTextDrawDestroy(playerid, barwos[playerid][idbar][bar_barra]);

	return true;
}