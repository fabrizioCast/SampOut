//  Registro
/*
    Hecho por: Sleek
    Fecha: 25/01/2021 - 20:03
*/

#include <YSI\y_hooks>

#include "../Modulos/Server/prox.inc"
#include "../Modulos/inicio/Commands.inc"
//------------------CALLBACKS-----------------//


hook r_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == d_pass)
    {
        if(!response)
        {
            SendClientMessage(playerid, -1, "{FF0000}• {ffffff}Ingresa una clave para poder continuar");
            ShowPlayerDialog(playerid, d_pass, DIALOG_STYLE_PASSWORD, "Clave", "{F9BB0A}Ingresa tu clave", "Aceptar", "Salir");
        }
        else
        {
            if(strlen(inputtext) < 5 || strlen(inputtext) > 20)
            {
                SendClientMessage(playerid, -1, "{FF0000}• {ffffff}Su clave debe comprender entre 5 y 20 caracteres.");
                ShowPlayerDialog(playerid, d_pass, DIALOG_STYLE_PASSWORD, "Clave", "{F9BB0A}Ingresa tu clave", "Aceptar", "Salir");
                return 0;
            }
            else
            {
                strmid(CuentaInfo[playerid][Password], inputtext, 0, 65, 65);
                PlayerTextDrawSetString(playerid, PlayerTD[playerid][1], inputtext);
                Pasos[playerid] = 1;
            }
        }
    }
    if(dialogid == d_email)
    {
        if(!response)
        {
            SendClientMessage(playerid, -1, "{FF0000}• {ffffff}Ingresa un correo electronico valido para continua");
            ShowPlayerDialog(playerid, d_email, DIALOG_STYLE_INPUT, "E-mail", "{F9BB0A}Ingresa tu e-mail", "Aceptar", "Salir");
        }
        else
        {
            if(IsValidMail(inputtext))
            {
                strmid(CuentaInfo[playerid][Email], inputtext, 0, 250, 250);
                PlayerTextDrawSetString(playerid, EmailTD2[playerid][1], inputtext);
                Pasos[playerid] = 2;
            }
            else
            {
                SendClientMessage(playerid, -1, "{FF0000}• {ffffff}Correo invalido");
            }
        }
    }
    if(dialogid == d_edad)
    {
        if(!response)
        {
            SendClientMessage(playerid, -1, "{FF0000}• {ffffff}Ingresa una edad para continuar");
            ShowPlayerDialog(playerid, d_edad, DIALOG_STYLE_INPUT, "Edad", "{F9BB0A}Ingresa tu edad (OOC)", "Aceptar", "Salir");
        }
        else
        {
            CuentaInfo[playerid][Edad] = strval(inputtext);
            if(IsNumeric(inputtext))
            if(CuentaInfo[playerid][Edad] <= 7 || CuentaInfo[playerid][Edad] >= 60)
            {
                SendClientMessage(playerid, -1, "{FF0000}• {ffffff}Edad invalida");
                ShowPlayerDialog(playerid, d_edad, DIALOG_STYLE_INPUT, "Edad", "{F9BB0A}Ingresa tu edad (OOC)", "Aceptar", "Salir");
            }
            else
            {
                PlayerTextDrawSetString(playerid, EdadTD2[playerid][1], inputtext);
                Pasos[playerid] = 3;
            }
        }
    }
    if(dialogid == d_login)
    {
        if(!response)
        {
            SendClientMessage(playerid, -1, "{FF0000}• {ffffff}Debes ingresar una contraseña para poder logearte");
            Kick(playerid);
        }
        else
        {
            if(strlen(inputtext) < 5 || strlen(inputtext) > 20)
            {
                SendClientMessage(playerid, -1, "{FF0000}• {ffffff}Clave incorrecta, vuelve a intentarlo");
                ShowPlayerDialog(playerid, d_login, DIALOG_STYLE_PASSWORD, "Clave", "{F9BB0A}Ingresa tu clave para logear.", "Aceptar", "Salir");
            }
            else
            {
                if(strcmp(inputtext, CuentaInfo[playerid][Password]) != 0)
                {
                    MaxIntentos[playerid]++;
                    if(MaxIntentos[playerid] == 3)
                    {
                        SendClientMessage(playerid, -1, "{FF0000}• {ffffff}Seguro que está es tu cuenta?");
                        Kick(playerid);
                        return 0;
                    }
                    else
                    {
                        SendClientMessage(playerid, -1, "{FF0000}• {ffffff}Clave incorrecta, vuelve a intentarlo");
                        ShowPlayerDialog(playerid, d_login, DIALOG_STYLE_PASSWORD, "Clave", "{F9BB0A}Ingresa tu clave para logear.", "Aceptar", "Salir");
                        return 0;
                    }
                }
                else
                {
                    SetCameraBehindPlayer(playerid);
                    new str[128];
                    format(str, sizeof(str), "{36FF00}• {ffffff}Bienvenido de nuevo a {FFC300}SampOut {ffffff}%s", NombreJugador(playerid));
                    SendClientMessage(playerid, -1, str);
                    for(new i; i <15; i++)
                    {
                        TextDrawHideForPlayer(playerid, LoginTD[i]);
                    }
                    for(new i; i <2; i++)
                    {
                        PlayerTextDrawHide(playerid, LoginTD2[playerid][i]);
                    }
                    CancelSelectTextDraw(playerid);
                    CongelarPlayer(playerid, 2000);
                    CargarDataPlayer(playerid);
                    CuentaInfo[playerid][Logeado] = 1;
                }
            }
        }
    }
    return 1;
}

hook r_OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    //---------------------------R E G I S T R O ----------------------------------------//
    if(playertextid == PlayerTD[playerid][1])
    {
        ShowPlayerDialog(playerid, d_pass, DIALOG_STYLE_PASSWORD, "Clave", "{F9BB0A}Ingresa tu clave", "Aceptar", "Salir");
        return 1;
    }
    if(playertextid == PlayerTD[playerid][0])
    {
        if(Pasos[playerid] == 1)
        {
            for(new i = 0; i<15; i++)
            {
                TextDrawHideForPlayer(playerid, ClaveTD[i]);
                TextDrawShowForPlayer(playerid, EmailTD[i]);
            }
            for(new i = 0; i<2; i++)
            {
                PlayerTextDrawHide(playerid, PlayerTD[playerid][i]);
                PlayerTextDrawShow(playerid, EmailTD2[playerid][i]);
            }
            SelectTextDraw(playerid, 0xF9BB0AFF);
        }
        else
        {
            SendClientMessage(playerid, -1, "{FF0000}• {ffffff}Rellana el formulario");
        }
        return 1;
    }
    if(playertextid == EmailTD2[playerid][1])
    {
        ShowPlayerDialog(playerid, d_email, DIALOG_STYLE_INPUT, "E-mail", "{F9BB0A}Ingresa tu e-mail", "Aceptar", "Salir");
        return 1;
    }
    if(playertextid == EmailTD2[playerid][0])
    {
        if(Pasos[playerid] == 2)
        {
            for(new i = 0; i<15; i++)
            {
                TextDrawHideForPlayer(playerid, EmailTD[i]);
                TextDrawShowForPlayer(playerid, EdadTD[i]);
            }
            for(new i = 0; i<2; i++)
            {
                PlayerTextDrawHide(playerid, EmailTD2[playerid][i]);
                PlayerTextDrawShow(playerid, EdadTD2[playerid][i]);
            }
            SelectTextDraw(playerid, 0xF9BB0AFF);
        }
        else
        {
            SendClientMessage(playerid, -1, "{FF0000}• {ffffff}Rellana el formulario");
        }
    }
    if(playertextid == EdadTD2[playerid][1])
    {
        ShowPlayerDialog(playerid, d_edad, DIALOG_STYLE_INPUT, "Edad", "{F9BB0A}Ingresa tu edad", "Aceptar", "Salir");
        SendClientMessage(playerid, -1, "{FFC900}• {ffffff}Si no deseas ingresas tu edad, elige cualquiera");
        return 1;
    }
    if(playertextid == EdadTD2[playerid][0])
    {
        if(Pasos[playerid] == 3)
        {
            MostrarPersonalizacion(playerid);
            for(new i; i<15; i++)
            {
                TextDrawHideForPlayer(playerid, EdadTD[i]);
                TextDrawHideForPlayer(playerid, ClaveTD[i]);
            }
            for(new i; i<2; i++)
            {
                PlayerTextDrawHide(playerid, EdadTD2[playerid][i]);
                PlayerTextDrawHide(playerid, PlayerTD[playerid][i]);
            }
            CancelSelectTextDraw(playerid);
        }
        else
        {
            SendClientMessage(playerid, -1, "{FF0000}• {ffffff}Rellana el formulario");
        }
    }
    //---------------------------L O G I N ----------------------------------------//
    if(playertextid == LoginTD2[playerid][1])
    {
        ShowPlayerDialog(playerid, d_login, DIALOG_STYLE_PASSWORD, "Clave", "{F9BB0A}Ingresa tu clave para logear.", "Aceptar", "Salir");
    }
    return 1;
}


//-----------------------------STOCKS-----------------------------//
stock IsValidMail(mail[])
{
	new len = strlen(mail), bool:find[2], w;
 	if(!(6 < len < 129)) return 0;
  	for(new l; l < len; l++)
  	{
   		if(mail[l] == '.') find[0] = true;
     	if(mail[l] == '@')
      	{
       		if(find[1]) return 0;
         	find[1] = true;
          	w = l;
           	if(w > 64) return 0;
       	}
        if(!(mail[l] >= 'A' && mail[l] <= 'Z' || mail[l] >= 'a' && mail[l] <= 'z' || mail[l] >= '0' && mail[l] <= '9' || mail[l] == '.' || mail[l] == '-' || mail[l] == '_' || mail[l] == '@')) return 0;
   	}
    if(len - w > 65) return 0;
    if(!find[0] || !find[1]) return 0;
    return 1;
}

stock FIX_valstr(dest[], value, bool:pack = false)
{
    // format can't handle cellmin properly
    static const cellmin_value[] = !"-2147483648";

    if (value == cellmin)
        pack && strpack(dest, cellmin_value, 12) || strunpack(dest, cellmin_value, 12);
    else
        format(dest, 12, "%d", value), pack && strpack(dest, dest, 12);
}
#define valstr FIX_valstr

IsNumeric(const string[])
{
    return !sscanf(string, "{d}");
}




//-------------------------TEXTDRAW REGISTRO-----------------------//
stock CargarClave2(playerid)
{
    PlayerTD[playerid][0] = CreatePlayerTextDraw(playerid, 415.000000, 205.000000, ">");
    PlayerTextDrawFont(playerid, PlayerTD[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, PlayerTD[playerid][0], 0.662500, 2.950001);
    PlayerTextDrawTextSize(playerid, PlayerTD[playerid][0], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, PlayerTD[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTD[playerid][0], 1);
    PlayerTextDrawAlignment(playerid, PlayerTD[playerid][0], 2);
    PlayerTextDrawColor(playerid, PlayerTD[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTD[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, PlayerTD[playerid][0], 135);
    PlayerTextDrawUseBox(playerid, PlayerTD[playerid][0], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTD[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTD[playerid][0], 1);

    PlayerTD[playerid][1] = CreatePlayerTextDraw(playerid, 292.000000, 214.000000, "......");
    PlayerTextDrawFont(playerid, PlayerTD[playerid][1], 1);
    PlayerTextDrawLetterSize(playerid, PlayerTD[playerid][1], 0.229166, 1.649994);
    PlayerTextDrawTextSize(playerid, PlayerTD[playerid][1], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, PlayerTD[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, PlayerTD[playerid][1], 1);
    PlayerTextDrawAlignment(playerid, PlayerTD[playerid][1], 2);
    PlayerTextDrawColor(playerid, PlayerTD[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, PlayerTD[playerid][1], 45);
    PlayerTextDrawBoxColor(playerid, PlayerTD[playerid][1], 135);
    PlayerTextDrawUseBox(playerid, PlayerTD[playerid][1], 0);
    PlayerTextDrawSetProportional(playerid, PlayerTD[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, PlayerTD[playerid][1], 1);
}
stock CargarEmail2(playerid)
{
    EmailTD2[playerid][0] = CreatePlayerTextDraw(playerid, 415.000000, 205.000000, ">");
    PlayerTextDrawFont(playerid, EmailTD2[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, EmailTD2[playerid][0], 0.662500, 2.950001);
    PlayerTextDrawTextSize(playerid, EmailTD2[playerid][0], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, EmailTD2[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, EmailTD2[playerid][0], 1);
    PlayerTextDrawAlignment(playerid, EmailTD2[playerid][0], 2);
    PlayerTextDrawColor(playerid, EmailTD2[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, EmailTD2[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, EmailTD2[playerid][0], 135);
    PlayerTextDrawUseBox(playerid, EmailTD2[playerid][0], 0);
    PlayerTextDrawSetProportional(playerid, EmailTD2[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, EmailTD2[playerid][0], 1);

    EmailTD2[playerid][1] = CreatePlayerTextDraw(playerid, 292.000000, 214.000000, "ejemplo(a)gmail.com");
    PlayerTextDrawFont(playerid, EmailTD2[playerid][1], 1);
    PlayerTextDrawLetterSize(playerid, EmailTD2[playerid][1], 0.229166, 1.649994);
    PlayerTextDrawTextSize(playerid, EmailTD2[playerid][1], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, EmailTD2[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, EmailTD2[playerid][1], 1);
    PlayerTextDrawAlignment(playerid, EmailTD2[playerid][1], 2);
    PlayerTextDrawColor(playerid, EmailTD2[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, EmailTD2[playerid][1], 45);
    PlayerTextDrawBoxColor(playerid, EmailTD2[playerid][1], 135);
    PlayerTextDrawUseBox(playerid, EmailTD2[playerid][1], 0);
    PlayerTextDrawSetProportional(playerid, EmailTD2[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, EmailTD2[playerid][1], 1);
}
stock CargarEdad2(playerid)
{
    EdadTD2[playerid][0] = CreatePlayerTextDraw(playerid, 415.000000, 205.000000, ">");
    PlayerTextDrawFont(playerid, EdadTD2[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, EdadTD2[playerid][0], 0.662500, 2.950001);
    PlayerTextDrawTextSize(playerid, EdadTD2[playerid][0], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, EdadTD2[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, EdadTD2[playerid][0], 1);
    PlayerTextDrawAlignment(playerid, EdadTD2[playerid][0], 2);
    PlayerTextDrawColor(playerid, EdadTD2[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, EdadTD2[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, EdadTD2[playerid][0], 135);
    PlayerTextDrawUseBox(playerid, EdadTD2[playerid][0], 0);
    PlayerTextDrawSetProportional(playerid, EdadTD2[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, EdadTD2[playerid][0], 1);

    EdadTD2[playerid][1] = CreatePlayerTextDraw(playerid, 266.000000, 214.000000, ".....");
    PlayerTextDrawFont(playerid, EdadTD2[playerid][1], 1);
    PlayerTextDrawLetterSize(playerid, EdadTD2[playerid][1], 0.229166, 1.649994);
    PlayerTextDrawTextSize(playerid, EdadTD2[playerid][1], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, EdadTD2[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, EdadTD2[playerid][1], 1);
    PlayerTextDrawAlignment(playerid, EdadTD2[playerid][1], 2);
    PlayerTextDrawColor(playerid, EdadTD2[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, EdadTD2[playerid][1], 45);
    PlayerTextDrawBoxColor(playerid, EdadTD2[playerid][1], 135);
    PlayerTextDrawUseBox(playerid, EdadTD2[playerid][1], 0);
    PlayerTextDrawSetProportional(playerid, EdadTD2[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, EdadTD2[playerid][1], 1);
}
stock CargarLogin2(playerid)
{

    LoginTD2[playerid][1] = CreatePlayerTextDraw(playerid, 272.000000, 214.000000, ".....");
    PlayerTextDrawFont(playerid, LoginTD2[playerid][1], 1);
    PlayerTextDrawLetterSize(playerid, LoginTD2[playerid][1], 0.229166, 1.649994);
    PlayerTextDrawTextSize(playerid, LoginTD2[playerid][1], 298.500000, 75.000000);
    PlayerTextDrawSetOutline(playerid, LoginTD2[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, LoginTD2[playerid][1], 1);
    PlayerTextDrawAlignment(playerid, LoginTD2[playerid][1], 2);
    PlayerTextDrawColor(playerid, LoginTD2[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, LoginTD2[playerid][1], 45);
    PlayerTextDrawBoxColor(playerid, LoginTD2[playerid][1], 135);
    PlayerTextDrawUseBox(playerid, LoginTD2[playerid][1], 0);
    PlayerTextDrawSetProportional(playerid, LoginTD2[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, LoginTD2[playerid][1], 1);

}
stock CargarLogin()
{
    LoginTD[0] = TextDrawCreate(326.000000, 176.000000, "_");
    TextDrawFont(LoginTD[0], 1);
    TextDrawLetterSize(LoginTD[0], 0.600000, 10.549996);
    TextDrawTextSize(LoginTD[0], 298.500000, 169.500000);
    TextDrawSetOutline(LoginTD[0], 1);
    TextDrawSetShadow(LoginTD[0], 0);
    TextDrawAlignment(LoginTD[0], 2);
    TextDrawColor(LoginTD[0], -1);
    TextDrawBackgroundColor(LoginTD[0], 255);
    TextDrawBoxColor(LoginTD[0], 454695679);
    TextDrawUseBox(LoginTD[0], 1);
    TextDrawSetProportional(LoginTD[0], 1);
    TextDrawSetSelectable(LoginTD[0], 0);

    LoginTD[1] = TextDrawCreate(264.000000, 156.000000, "Login");
    TextDrawFont(LoginTD[1], 1);
    TextDrawLetterSize(LoginTD[1], 0.358332, 1.799996);
    TextDrawTextSize(LoginTD[1], 298.500000, 75.000000);
    TextDrawSetOutline(LoginTD[1], 0);
    TextDrawSetShadow(LoginTD[1], 1);
    TextDrawAlignment(LoginTD[1], 2);
    TextDrawColor(LoginTD[1], -1);
    TextDrawBackgroundColor(LoginTD[1], 45);
    TextDrawBoxColor(LoginTD[1], 135);
    TextDrawUseBox(LoginTD[1], 0);
    TextDrawSetProportional(LoginTD[1], 1);
    TextDrawSetSelectable(LoginTD[1], 0);

    LoginTD[2] = TextDrawCreate(326.000000, 176.000000, "_");
    TextDrawFont(LoginTD[2], 1);
    TextDrawLetterSize(LoginTD[2], 0.600000, 10.549996);
    TextDrawTextSize(LoginTD[2], 298.500000, 169.500000);
    TextDrawSetOutline(LoginTD[2], 1);
    TextDrawSetShadow(LoginTD[2], 0);
    TextDrawAlignment(LoginTD[2], 2);
    TextDrawColor(LoginTD[2], -1);
    TextDrawBackgroundColor(LoginTD[2], 255);
    TextDrawBoxColor(LoginTD[2], 454695679);
    TextDrawUseBox(LoginTD[2], 1);
    TextDrawSetProportional(LoginTD[2], 1);
    TextDrawSetSelectable(LoginTD[2], 0);

    LoginTD[3] = TextDrawCreate(329.000000, 213.000000, "_");
    TextDrawFont(LoginTD[3], 1);
    TextDrawLetterSize(LoginTD[3], 0.600000, 2.100003);
    TextDrawTextSize(LoginTD[3], 298.500000, 155.000000);
    TextDrawSetOutline(LoginTD[3], 1);
    TextDrawSetShadow(LoginTD[3], 0);
    TextDrawAlignment(LoginTD[3], 2);
    TextDrawColor(LoginTD[3], -1);
    TextDrawBackgroundColor(LoginTD[3], 255);
    TextDrawBoxColor(LoginTD[3], 135);
    TextDrawUseBox(LoginTD[3], 1);
    TextDrawSetProportional(LoginTD[3], 1);
    TextDrawSetSelectable(LoginTD[3], 1);

    LoginTD[4] = TextDrawCreate(385.000000, 189.000000, "ld_beat:chit");
    TextDrawFont(LoginTD[4], 4);
    TextDrawLetterSize(LoginTD[4], 0.600000, 2.000000);
    TextDrawTextSize(LoginTD[4], 57.500000, 63.500000);
    TextDrawSetOutline(LoginTD[4], 1);
    TextDrawSetShadow(LoginTD[4], 0);
    TextDrawAlignment(LoginTD[4], 1);
    TextDrawColor(LoginTD[4], 387388762);
    TextDrawBackgroundColor(LoginTD[4], 255);
    TextDrawBoxColor(LoginTD[4], 50);
    TextDrawUseBox(LoginTD[4], 1);
    TextDrawSetProportional(LoginTD[4], 1);
    TextDrawSetSelectable(LoginTD[4], 0);

    LoginTD[5] = TextDrawCreate(390.000000, 193.000000, "ld_beat:chit");
    TextDrawFont(LoginTD[5], 4);
    TextDrawLetterSize(LoginTD[5], 0.600000, 2.000000);
    TextDrawTextSize(LoginTD[5], 48.500000, 54.000000);
    TextDrawSetOutline(LoginTD[5], 1);
    TextDrawSetShadow(LoginTD[5], 0);
    TextDrawAlignment(LoginTD[5], 1);
    TextDrawColor(LoginTD[5], -294256385);
    TextDrawBackgroundColor(LoginTD[5], 255);
    TextDrawBoxColor(LoginTD[5], 50);
    TextDrawUseBox(LoginTD[5], 1);
    TextDrawSetProportional(LoginTD[5], 1);
    TextDrawSetSelectable(LoginTD[5], 0);

    LoginTD[6] = TextDrawCreate(275.000000, 273.000000, "Copyright (c)");
    TextDrawFont(LoginTD[6], 1);
    TextDrawLetterSize(LoginTD[6], 0.229166, 1.649994);
    TextDrawTextSize(LoginTD[6], 298.500000, 75.000000);
    TextDrawSetOutline(LoginTD[6], 0);
    TextDrawSetShadow(LoginTD[6], 1);
    TextDrawAlignment(LoginTD[6], 2);
    TextDrawColor(LoginTD[6], -1);
    TextDrawBackgroundColor(LoginTD[6], 45);
    TextDrawBoxColor(LoginTD[6], 135);
    TextDrawUseBox(LoginTD[6], 0);
    TextDrawSetProportional(LoginTD[6], 1);
    TextDrawSetSelectable(LoginTD[6], 0);

    LoginTD[7] = TextDrawCreate(280.000000, 195.000000, "Digite su clave");
    TextDrawFont(LoginTD[7], 1);
    TextDrawLetterSize(LoginTD[7], 0.229166, 1.649994);
    TextDrawTextSize(LoginTD[7], 298.500000, 75.000000);
    TextDrawSetOutline(LoginTD[7], 0);
    TextDrawSetShadow(LoginTD[7], 1);
    TextDrawAlignment(LoginTD[7], 2);
    TextDrawColor(LoginTD[7], -760727041);
    TextDrawBackgroundColor(LoginTD[7], 45);
    TextDrawBoxColor(LoginTD[7], 135);
    TextDrawUseBox(LoginTD[7], 0);
    TextDrawSetProportional(LoginTD[7], 1);
    TextDrawSetSelectable(LoginTD[7], 0);

    LoginTD[8] = TextDrawCreate(314.000000, 274.000000, "SampOut");
    TextDrawFont(LoginTD[8], 1);
    TextDrawLetterSize(LoginTD[8], 0.229166, 1.649994);
    TextDrawTextSize(LoginTD[8], 298.500000, 75.000000);
    TextDrawSetOutline(LoginTD[8], 0);
    TextDrawSetShadow(LoginTD[8], 1);
    TextDrawAlignment(LoginTD[8], 2);
    TextDrawColor(LoginTD[8], -760727041);
    TextDrawBackgroundColor(LoginTD[8], 45);
    TextDrawBoxColor(LoginTD[8], 135);
    TextDrawUseBox(LoginTD[8], 0);
    TextDrawSetProportional(LoginTD[8], 1);
    TextDrawSetSelectable(LoginTD[8], 0);

    LoginTD[9] = TextDrawCreate(368.000000, 275.000000, "All Rights Reserved");
    TextDrawFont(LoginTD[9], 1);
    TextDrawLetterSize(LoginTD[9], 0.229166, 1.649994);
    TextDrawTextSize(LoginTD[9], 298.500000, 75.000000);
    TextDrawSetOutline(LoginTD[9], 0);
    TextDrawSetShadow(LoginTD[9], 1);
    TextDrawAlignment(LoginTD[9], 2);
    TextDrawColor(LoginTD[9], -1);
    TextDrawBackgroundColor(LoginTD[9], 45);
    TextDrawBoxColor(LoginTD[9], 135);
    TextDrawUseBox(LoginTD[9], 0);
    TextDrawSetProportional(LoginTD[9], 1);
    TextDrawSetSelectable(LoginTD[9], 0);

    LoginTD[10] = TextDrawCreate(312.000000, 290.000000, "Since");
    TextDrawFont(LoginTD[10], 1);
    TextDrawLetterSize(LoginTD[10], 0.229166, 1.649994);
    TextDrawTextSize(LoginTD[10], 298.500000, 75.000000);
    TextDrawSetOutline(LoginTD[10], 0);
    TextDrawSetShadow(LoginTD[10], 1);
    TextDrawAlignment(LoginTD[10], 2);
    TextDrawColor(LoginTD[10], -1);
    TextDrawBackgroundColor(LoginTD[10], 45);
    TextDrawBoxColor(LoginTD[10], 135);
    TextDrawUseBox(LoginTD[10], 0);
    TextDrawSetProportional(LoginTD[10], 1);
    TextDrawSetSelectable(LoginTD[10], 0);

    LoginTD[11] = TextDrawCreate(333.000000, 289.000000, "2021");
    TextDrawFont(LoginTD[11], 1);
    TextDrawLetterSize(LoginTD[11], 0.229166, 1.649994);
    TextDrawTextSize(LoginTD[11], 298.500000, 75.000000);
    TextDrawSetOutline(LoginTD[11], 0);
    TextDrawSetShadow(LoginTD[11], 1);
    TextDrawAlignment(LoginTD[11], 2);
    TextDrawColor(LoginTD[11], -760727041);
    TextDrawBackgroundColor(LoginTD[11], 45);
    TextDrawBoxColor(LoginTD[11], 135);
    TextDrawUseBox(LoginTD[11], 0);
    TextDrawSetProportional(LoginTD[11], 1);
    TextDrawSetSelectable(LoginTD[11], 0);
}
stock CargarClave()
{
    //Textdraws
    ClaveTD[0] = TextDrawCreate(326.000000, 176.000000, "_");
    TextDrawFont(ClaveTD[0], 1);
    TextDrawLetterSize(ClaveTD[0], 0.600000, 10.549996);
    TextDrawTextSize(ClaveTD[0], 298.500000, 169.500000);
    TextDrawSetOutline(ClaveTD[0], 1);
    TextDrawSetShadow(ClaveTD[0], 0);
    TextDrawAlignment(ClaveTD[0], 2);
    TextDrawColor(ClaveTD[0], -1);
    TextDrawBackgroundColor(ClaveTD[0], 255);
    TextDrawBoxColor(ClaveTD[0], 454695679);
    TextDrawUseBox(ClaveTD[0], 1);
    TextDrawSetProportional(ClaveTD[0], 1);
    TextDrawSetSelectable(ClaveTD[0], 0);

    ClaveTD[1] = TextDrawCreate(275.000000, 156.000000, "REGISTRO");
    TextDrawFont(ClaveTD[1], 1);
    TextDrawLetterSize(ClaveTD[1], 0.358332, 1.799996);
    TextDrawTextSize(ClaveTD[1], 298.500000, 75.000000);
    TextDrawSetOutline(ClaveTD[1], 0);
    TextDrawSetShadow(ClaveTD[1], 1);
    TextDrawAlignment(ClaveTD[1], 2);
    TextDrawColor(ClaveTD[1], -1);
    TextDrawBackgroundColor(ClaveTD[1], 45);
    TextDrawBoxColor(ClaveTD[1], 135);
    TextDrawUseBox(ClaveTD[1], 0);
    TextDrawSetProportional(ClaveTD[1], 1);
    TextDrawSetSelectable(ClaveTD[1], 0);

    ClaveTD[2] = TextDrawCreate(382.000000, 156.000000, "Paso  /");
    TextDrawFont(ClaveTD[2], 1);
    TextDrawLetterSize(ClaveTD[2], 0.358332, 1.799996);
    TextDrawTextSize(ClaveTD[2], 298.500000, 75.000000);
    TextDrawSetOutline(ClaveTD[2], 0);
    TextDrawSetShadow(ClaveTD[2], 1);
    TextDrawAlignment(ClaveTD[2], 2);
    TextDrawColor(ClaveTD[2], -1);
    TextDrawBackgroundColor(ClaveTD[2], 45);
    TextDrawBoxColor(ClaveTD[2], 135);
    TextDrawUseBox(ClaveTD[2], 0);
    TextDrawSetProportional(ClaveTD[2], 1);
    TextDrawSetSelectable(ClaveTD[2], 0);

    ClaveTD[3] = TextDrawCreate(393.000000, 157.000000, "1");
    TextDrawFont(ClaveTD[3], 1);
    TextDrawLetterSize(ClaveTD[3], 0.358332, 1.799996);
    TextDrawTextSize(ClaveTD[3], 298.500000, 75.000000);
    TextDrawSetOutline(ClaveTD[3], 0);
    TextDrawSetShadow(ClaveTD[3], 1);
    TextDrawAlignment(ClaveTD[3], 2);
    TextDrawColor(ClaveTD[3], -760727041);
    TextDrawBackgroundColor(ClaveTD[3], 45);
    TextDrawBoxColor(ClaveTD[3], 135);
    TextDrawUseBox(ClaveTD[3], 0);
    TextDrawSetProportional(ClaveTD[3], 1);
    TextDrawSetSelectable(ClaveTD[3], 0);

    ClaveTD[4] = TextDrawCreate(409.000000, 157.000000, "3");
    TextDrawFont(ClaveTD[4], 1);
    TextDrawLetterSize(ClaveTD[4], 0.358332, 1.799996);
    TextDrawTextSize(ClaveTD[4], 298.500000, 75.000000);
    TextDrawSetOutline(ClaveTD[4], 0);
    TextDrawSetShadow(ClaveTD[4], 1);
    TextDrawAlignment(ClaveTD[4], 2);
    TextDrawColor(ClaveTD[4], -1);
    TextDrawBackgroundColor(ClaveTD[4], 45);
    TextDrawBoxColor(ClaveTD[4], 135);
    TextDrawUseBox(ClaveTD[4], 0);
    TextDrawSetProportional(ClaveTD[4], 1);
    TextDrawSetSelectable(ClaveTD[4], 0);

    ClaveTD[5] = TextDrawCreate(326.000000, 176.000000, "_");
    TextDrawFont(ClaveTD[5], 1);
    TextDrawLetterSize(ClaveTD[5], 0.600000, 10.549996);
    TextDrawTextSize(ClaveTD[5], 298.500000, 169.500000);
    TextDrawSetOutline(ClaveTD[5], 1);
    TextDrawSetShadow(ClaveTD[5], 0);
    TextDrawAlignment(ClaveTD[5], 2);
    TextDrawColor(ClaveTD[5], -1);
    TextDrawBackgroundColor(ClaveTD[5], 255);
    TextDrawBoxColor(ClaveTD[5], 454695679);
    TextDrawUseBox(ClaveTD[5], 1);
    TextDrawSetProportional(ClaveTD[5], 1);
    TextDrawSetSelectable(ClaveTD[5], 0);

    ClaveTD[6] = TextDrawCreate(329.000000, 213.000000, "_");
    TextDrawFont(ClaveTD[6], 1);
    TextDrawLetterSize(ClaveTD[6], 0.600000, 2.100003);
    TextDrawTextSize(ClaveTD[6], 298.500000, 155.000000);
    TextDrawSetOutline(ClaveTD[6], 1);
    TextDrawSetShadow(ClaveTD[6], 0);
    TextDrawAlignment(ClaveTD[6], 2);
    TextDrawColor(ClaveTD[6], -1);
    TextDrawBackgroundColor(ClaveTD[6], 255);
    TextDrawBoxColor(ClaveTD[6], 135);
    TextDrawUseBox(ClaveTD[6], 1);
    TextDrawSetProportional(ClaveTD[6], 1);
    TextDrawSetSelectable(ClaveTD[6], 1);

    ClaveTD[7] = TextDrawCreate(385.000000, 189.000000, "ld_beat:chit");
    TextDrawFont(ClaveTD[7], 4);
    TextDrawLetterSize(ClaveTD[7], 0.600000, 2.000000);
    TextDrawTextSize(ClaveTD[7], 57.500000, 63.500000);
    TextDrawSetOutline(ClaveTD[7], 1);
    TextDrawSetShadow(ClaveTD[7], 0);
    TextDrawAlignment(ClaveTD[7], 1);
    TextDrawColor(ClaveTD[7], 387388762);
    TextDrawBackgroundColor(ClaveTD[7], 255);
    TextDrawBoxColor(ClaveTD[7], 50);
    TextDrawUseBox(ClaveTD[7], 1);
    TextDrawSetProportional(ClaveTD[7], 1);
    TextDrawSetSelectable(ClaveTD[7], 0);

    ClaveTD[8] = TextDrawCreate(390.000000, 193.000000, "ld_beat:chit");
    TextDrawFont(ClaveTD[8], 4);
    TextDrawLetterSize(ClaveTD[8], 0.600000, 2.000000);
    TextDrawTextSize(ClaveTD[8], 48.500000, 54.000000);
    TextDrawSetOutline(ClaveTD[8], 1);
    TextDrawSetShadow(ClaveTD[8], 0);
    TextDrawAlignment(ClaveTD[8], 1);
    TextDrawColor(ClaveTD[8], -294256385);
    TextDrawBackgroundColor(ClaveTD[8], 255);
    TextDrawBoxColor(ClaveTD[8], 50);
    TextDrawUseBox(ClaveTD[8], 1);
    TextDrawSetProportional(ClaveTD[8], 1);
    TextDrawSetSelectable(ClaveTD[8], 0);

    ClaveTD[9] = TextDrawCreate(280.000000, 195.000000, "Digite su clave");
    TextDrawFont(ClaveTD[9], 1);
    TextDrawLetterSize(ClaveTD[9], 0.229166, 1.649994);
    TextDrawTextSize(ClaveTD[9], 298.500000, 75.000000);
    TextDrawSetOutline(ClaveTD[9], 0);
    TextDrawSetShadow(ClaveTD[9], 1);
    TextDrawAlignment(ClaveTD[9], 2);
    TextDrawColor(ClaveTD[9], -760727041);
    TextDrawBackgroundColor(ClaveTD[9], 45);
    TextDrawBoxColor(ClaveTD[9], 135);
    TextDrawUseBox(ClaveTD[9], 0);
    TextDrawSetProportional(ClaveTD[9], 1);
    TextDrawSetSelectable(ClaveTD[9], 0);

    ClaveTD[10] = TextDrawCreate(275.000000, 273.000000, "Copyright (c)");
    TextDrawFont(ClaveTD[10], 1);
    TextDrawLetterSize(ClaveTD[10], 0.229166, 1.649994);
    TextDrawTextSize(ClaveTD[10], 298.500000, 75.000000);
    TextDrawSetOutline(ClaveTD[10], 0);
    TextDrawSetShadow(ClaveTD[10], 1);
    TextDrawAlignment(ClaveTD[10], 2);
    TextDrawColor(ClaveTD[10], -1);
    TextDrawBackgroundColor(ClaveTD[10], 45);
    TextDrawBoxColor(ClaveTD[10], 135);
    TextDrawUseBox(ClaveTD[10], 0);
    TextDrawSetProportional(ClaveTD[10], 1);
    TextDrawSetSelectable(ClaveTD[10], 0);

    ClaveTD[11] = TextDrawCreate(314.000000, 274.000000, "SampOut");
    TextDrawFont(ClaveTD[11], 1);
    TextDrawLetterSize(ClaveTD[11], 0.229166, 1.649994);
    TextDrawTextSize(ClaveTD[11], 298.500000, 75.000000);
    TextDrawSetOutline(ClaveTD[11], 0);
    TextDrawSetShadow(ClaveTD[11], 1);
    TextDrawAlignment(ClaveTD[11], 2);
    TextDrawColor(ClaveTD[11], -760727041);
    TextDrawBackgroundColor(ClaveTD[11], 45);
    TextDrawBoxColor(ClaveTD[11], 135);
    TextDrawUseBox(ClaveTD[11], 0);
    TextDrawSetProportional(ClaveTD[11], 1);
    TextDrawSetSelectable(ClaveTD[11], 0);

    ClaveTD[12] = TextDrawCreate(368.000000, 275.000000, "All Rights Reserved");
    TextDrawFont(ClaveTD[12], 1);
    TextDrawLetterSize(ClaveTD[12], 0.229166, 1.649994);
    TextDrawTextSize(ClaveTD[12], 298.500000, 75.000000);
    TextDrawSetOutline(ClaveTD[12], 0);
    TextDrawSetShadow(ClaveTD[12], 1);
    TextDrawAlignment(ClaveTD[12], 2);
    TextDrawColor(ClaveTD[12], -1);
    TextDrawBackgroundColor(ClaveTD[12], 45);
    TextDrawBoxColor(ClaveTD[12], 135);
    TextDrawUseBox(ClaveTD[12], 0);
    TextDrawSetProportional(ClaveTD[12], 1);
    TextDrawSetSelectable(ClaveTD[12], 0);

    ClaveTD[13] = TextDrawCreate(312.000000, 290.000000, "Since");
    TextDrawFont(ClaveTD[13], 1);
    TextDrawLetterSize(ClaveTD[13], 0.229166, 1.649994);
    TextDrawTextSize(ClaveTD[13], 298.500000, 75.000000);
    TextDrawSetOutline(ClaveTD[13], 0);
    TextDrawSetShadow(ClaveTD[13], 1);
    TextDrawAlignment(ClaveTD[13], 2);
    TextDrawColor(ClaveTD[13], -1);
    TextDrawBackgroundColor(ClaveTD[13], 45);
    TextDrawBoxColor(ClaveTD[13], 135);
    TextDrawUseBox(ClaveTD[13], 0);
    TextDrawSetProportional(ClaveTD[13], 1);
    TextDrawSetSelectable(ClaveTD[13], 0);

    ClaveTD[14] = TextDrawCreate(333.000000, 289.000000, "2021");
    TextDrawFont(ClaveTD[14], 1);
    TextDrawLetterSize(ClaveTD[14], 0.229166, 1.649994);
    TextDrawTextSize(ClaveTD[14], 298.500000, 75.000000);
    TextDrawSetOutline(ClaveTD[14], 0);
    TextDrawSetShadow(ClaveTD[14], 1);
    TextDrawAlignment(ClaveTD[14], 2);
    TextDrawColor(ClaveTD[14], -760727041);
    TextDrawBackgroundColor(ClaveTD[14], 45);
    TextDrawBoxColor(ClaveTD[14], 135);
    TextDrawUseBox(ClaveTD[14], 0);
    TextDrawSetProportional(ClaveTD[14], 1);
    TextDrawSetSelectable(ClaveTD[14], 0);
}
stock CargarEmail()
{
    //Textdraws
    EmailTD[0] = TextDrawCreate(326.000000, 176.000000, "_");
    TextDrawFont(EmailTD[0], 1);
    TextDrawLetterSize(EmailTD[0], 0.600000, 10.549996);
    TextDrawTextSize(EmailTD[0], 298.500000, 169.500000);
    TextDrawSetOutline(EmailTD[0], 1);
    TextDrawSetShadow(EmailTD[0], 0);
    TextDrawAlignment(EmailTD[0], 2);
    TextDrawColor(EmailTD[0], -1);
    TextDrawBackgroundColor(EmailTD[0], 255);
    TextDrawBoxColor(EmailTD[0], 454695679);
    TextDrawUseBox(EmailTD[0], 1);
    TextDrawSetProportional(EmailTD[0], 1);
    TextDrawSetSelectable(EmailTD[0], 0);

    EmailTD[1] = TextDrawCreate(275.000000, 156.000000, "REGISTRO");
    TextDrawFont(EmailTD[1], 1);
    TextDrawLetterSize(EmailTD[1], 0.358332, 1.799996);
    TextDrawTextSize(EmailTD[1], 298.500000, 75.000000);
    TextDrawSetOutline(EmailTD[1], 0);
    TextDrawSetShadow(EmailTD[1], 1);
    TextDrawAlignment(EmailTD[1], 2);
    TextDrawColor(EmailTD[1], -1);
    TextDrawBackgroundColor(EmailTD[1], 45);
    TextDrawBoxColor(EmailTD[1], 135);
    TextDrawUseBox(EmailTD[1], 0);
    TextDrawSetProportional(EmailTD[1], 1);
    TextDrawSetSelectable(EmailTD[1], 0);

    EmailTD[2] = TextDrawCreate(382.000000, 156.000000, "Paso  /");
    TextDrawFont(EmailTD[2], 1);
    TextDrawLetterSize(EmailTD[2], 0.358332, 1.799996);
    TextDrawTextSize(EmailTD[2], 298.500000, 75.000000);
    TextDrawSetOutline(EmailTD[2], 0);
    TextDrawSetShadow(EmailTD[2], 1);
    TextDrawAlignment(EmailTD[2], 2);
    TextDrawColor(EmailTD[2], -1);
    TextDrawBackgroundColor(EmailTD[2], 45);
    TextDrawBoxColor(EmailTD[2], 135);
    TextDrawUseBox(EmailTD[2], 0);
    TextDrawSetProportional(EmailTD[2], 1);
    TextDrawSetSelectable(EmailTD[2], 0);

    EmailTD[3] = TextDrawCreate(393.000000, 157.000000, "2");
    TextDrawFont(EmailTD[3], 1);
    TextDrawLetterSize(EmailTD[3], 0.358332, 1.799996);
    TextDrawTextSize(EmailTD[3], 298.500000, 75.000000);
    TextDrawSetOutline(EmailTD[3], 0);
    TextDrawSetShadow(EmailTD[3], 1);
    TextDrawAlignment(EmailTD[3], 2);
    TextDrawColor(EmailTD[3], -760727041);
    TextDrawBackgroundColor(EmailTD[3], 45);
    TextDrawBoxColor(EmailTD[3], 135);
    TextDrawUseBox(EmailTD[3], 0);
    TextDrawSetProportional(EmailTD[3], 1);
    TextDrawSetSelectable(EmailTD[3], 0);

    EmailTD[4] = TextDrawCreate(409.000000, 157.000000, "3");
    TextDrawFont(EmailTD[4], 1);
    TextDrawLetterSize(EmailTD[4], 0.358332, 1.799996);
    TextDrawTextSize(EmailTD[4], 298.500000, 75.000000);
    TextDrawSetOutline(EmailTD[4], 0);
    TextDrawSetShadow(EmailTD[4], 1);
    TextDrawAlignment(EmailTD[4], 2);
    TextDrawColor(EmailTD[4], -1);
    TextDrawBackgroundColor(EmailTD[4], 45);
    TextDrawBoxColor(EmailTD[4], 135);
    TextDrawUseBox(EmailTD[4], 0);
    TextDrawSetProportional(EmailTD[4], 1);
    TextDrawSetSelectable(EmailTD[4], 0);

    EmailTD[5] = TextDrawCreate(326.000000, 176.000000, "_");
    TextDrawFont(EmailTD[5], 1);
    TextDrawLetterSize(EmailTD[5], 0.600000, 10.549996);
    TextDrawTextSize(EmailTD[5], 298.500000, 169.500000);
    TextDrawSetOutline(EmailTD[5], 1);
    TextDrawSetShadow(EmailTD[5], 0);
    TextDrawAlignment(EmailTD[5], 2);
    TextDrawColor(EmailTD[5], -1);
    TextDrawBackgroundColor(EmailTD[5], 255);
    TextDrawBoxColor(EmailTD[5], 454695679);
    TextDrawUseBox(EmailTD[5], 1);
    TextDrawSetProportional(EmailTD[5], 1);
    TextDrawSetSelectable(EmailTD[5], 0);

    EmailTD[6] = TextDrawCreate(329.000000, 213.000000, "_");
    TextDrawFont(EmailTD[6], 1);
    TextDrawLetterSize(EmailTD[6], 0.600000, 2.100003);
    TextDrawTextSize(EmailTD[6], 298.500000, 155.000000);
    TextDrawSetOutline(EmailTD[6], 1);
    TextDrawSetShadow(EmailTD[6], 0);
    TextDrawAlignment(EmailTD[6], 2);
    TextDrawColor(EmailTD[6], -1);
    TextDrawBackgroundColor(EmailTD[6], 255);
    TextDrawBoxColor(EmailTD[6], 135);
    TextDrawUseBox(EmailTD[6], 1);
    TextDrawSetProportional(EmailTD[6], 1);
    TextDrawSetSelectable(EmailTD[6], 1);

    EmailTD[7] = TextDrawCreate(385.000000, 189.000000, "ld_beat:chit");
    TextDrawFont(EmailTD[7], 4);
    TextDrawLetterSize(EmailTD[7], 0.600000, 2.000000);
    TextDrawTextSize(EmailTD[7], 57.500000, 63.500000);
    TextDrawSetOutline(EmailTD[7], 1);
    TextDrawSetShadow(EmailTD[7], 0);
    TextDrawAlignment(EmailTD[7], 1);
    TextDrawColor(EmailTD[7], 387388762);
    TextDrawBackgroundColor(EmailTD[7], 255);
    TextDrawBoxColor(EmailTD[7], 50);
    TextDrawUseBox(EmailTD[7], 1);
    TextDrawSetProportional(EmailTD[7], 1);
    TextDrawSetSelectable(EmailTD[7], 0);

    EmailTD[8] = TextDrawCreate(390.000000, 193.000000, "ld_beat:chit");
    TextDrawFont(EmailTD[8], 4);
    TextDrawLetterSize(EmailTD[8], 0.600000, 2.000000);
    TextDrawTextSize(EmailTD[8], 48.500000, 54.000000);
    TextDrawSetOutline(EmailTD[8], 1);
    TextDrawSetShadow(EmailTD[8], 0);
    TextDrawAlignment(EmailTD[8], 1);
    TextDrawColor(EmailTD[8], -294256385);
    TextDrawBackgroundColor(EmailTD[8], 255);
    TextDrawBoxColor(EmailTD[8], 50);
    TextDrawUseBox(EmailTD[8], 1);
    TextDrawSetProportional(EmailTD[8], 1);
    TextDrawSetSelectable(EmailTD[8], 0);

    EmailTD[9] = TextDrawCreate(280.000000, 195.000000, "Digite su e-mail");
    TextDrawFont(EmailTD[9], 1);
    TextDrawLetterSize(EmailTD[9], 0.229166, 1.649994);
    TextDrawTextSize(EmailTD[9], 298.500000, 75.000000);
    TextDrawSetOutline(EmailTD[9], 0);
    TextDrawSetShadow(EmailTD[9], 1);
    TextDrawAlignment(EmailTD[9], 2);
    TextDrawColor(EmailTD[9], -760727041);
    TextDrawBackgroundColor(EmailTD[9], 45);
    TextDrawBoxColor(EmailTD[9], 135);
    TextDrawUseBox(EmailTD[9], 0);
    TextDrawSetProportional(EmailTD[9], 1);
    TextDrawSetSelectable(EmailTD[9], 0);

    EmailTD[10] = TextDrawCreate(275.000000, 273.000000, "Copyright (c)");
    TextDrawFont(EmailTD[10], 1);
    TextDrawLetterSize(EmailTD[10], 0.229166, 1.649994);
    TextDrawTextSize(EmailTD[10], 298.500000, 75.000000);
    TextDrawSetOutline(EmailTD[10], 0);
    TextDrawSetShadow(EmailTD[10], 1);
    TextDrawAlignment(EmailTD[10], 2);
    TextDrawColor(EmailTD[10], -1);
    TextDrawBackgroundColor(EmailTD[10], 45);
    TextDrawBoxColor(EmailTD[10], 135);
    TextDrawUseBox(EmailTD[10], 0);
    TextDrawSetProportional(EmailTD[10], 1);
    TextDrawSetSelectable(EmailTD[10], 0);

    EmailTD[11] = TextDrawCreate(314.000000, 274.000000, "SampOut");
    TextDrawFont(EmailTD[11], 1);
    TextDrawLetterSize(EmailTD[11], 0.229166, 1.649994);
    TextDrawTextSize(EmailTD[11], 298.500000, 75.000000);
    TextDrawSetOutline(EmailTD[11], 0);
    TextDrawSetShadow(EmailTD[11], 1);
    TextDrawAlignment(EmailTD[11], 2);
    TextDrawColor(EmailTD[11], -760727041);
    TextDrawBackgroundColor(EmailTD[11], 45);
    TextDrawBoxColor(EmailTD[11], 135);
    TextDrawUseBox(EmailTD[11], 0);
    TextDrawSetProportional(EmailTD[11], 1);
    TextDrawSetSelectable(EmailTD[11], 0);

    EmailTD[12] = TextDrawCreate(368.000000, 275.000000, "All Rights Reserved");
    TextDrawFont(EmailTD[12], 1);
    TextDrawLetterSize(EmailTD[12], 0.229166, 1.649994);
    TextDrawTextSize(EmailTD[12], 298.500000, 75.000000);
    TextDrawSetOutline(EmailTD[12], 0);
    TextDrawSetShadow(EmailTD[12], 1);
    TextDrawAlignment(EmailTD[12], 2);
    TextDrawColor(EmailTD[12], -1);
    TextDrawBackgroundColor(EmailTD[12], 45);
    TextDrawBoxColor(EmailTD[12], 135);
    TextDrawUseBox(EmailTD[12], 0);
    TextDrawSetProportional(EmailTD[12], 1);
    TextDrawSetSelectable(EmailTD[12], 0);

    EmailTD[13] = TextDrawCreate(312.000000, 290.000000, "Since");
    TextDrawFont(EmailTD[13], 1);
    TextDrawLetterSize(EmailTD[13], 0.229166, 1.649994);
    TextDrawTextSize(EmailTD[13], 298.500000, 75.000000);
    TextDrawSetOutline(EmailTD[13], 0);
    TextDrawSetShadow(EmailTD[13], 1);
    TextDrawAlignment(EmailTD[13], 2);
    TextDrawColor(EmailTD[13], -1);
    TextDrawBackgroundColor(EmailTD[13], 45);
    TextDrawBoxColor(EmailTD[13], 135);
    TextDrawUseBox(EmailTD[13], 0);
    TextDrawSetProportional(EmailTD[13], 1);
    TextDrawSetSelectable(EmailTD[13], 0);

    EmailTD[14] = TextDrawCreate(333.000000, 289.000000, "2021");
    TextDrawFont(EmailTD[14], 1);
    TextDrawLetterSize(EmailTD[14], 0.229166, 1.649994);
    TextDrawTextSize(EmailTD[14], 298.500000, 75.000000);
    TextDrawSetOutline(EmailTD[14], 0);
    TextDrawSetShadow(EmailTD[14], 1);
    TextDrawAlignment(EmailTD[14], 2);
    TextDrawColor(EmailTD[14], -760727041);
    TextDrawBackgroundColor(EmailTD[14], 45);
    TextDrawBoxColor(EmailTD[14], 135);
    TextDrawUseBox(EmailTD[14], 0);
    TextDrawSetProportional(EmailTD[14], 1);
    TextDrawSetSelectable(EmailTD[14], 0);
}
stock CargarEdad()
{
    //Textdraws
    EdadTD[0] = TextDrawCreate(326.000000, 176.000000, "_");
    TextDrawFont(EdadTD[0], 1);
    TextDrawLetterSize(EdadTD[0], 0.600000, 10.549996);
    TextDrawTextSize(EdadTD[0], 298.500000, 169.500000);
    TextDrawSetOutline(EdadTD[0], 1);
    TextDrawSetShadow(EdadTD[0], 0);
    TextDrawAlignment(EdadTD[0], 2);
    TextDrawColor(EdadTD[0], -1);
    TextDrawBackgroundColor(EdadTD[0], 255);
    TextDrawBoxColor(EdadTD[0], 454695679);
    TextDrawUseBox(EdadTD[0], 1);
    TextDrawSetProportional(EdadTD[0], 1);
    TextDrawSetSelectable(EdadTD[0], 0);

    EdadTD[1] = TextDrawCreate(275.000000, 156.000000, "REGISTRO");
    TextDrawFont(EdadTD[1], 1);
    TextDrawLetterSize(EdadTD[1], 0.358332, 1.799996);
    TextDrawTextSize(EdadTD[1], 298.500000, 75.000000);
    TextDrawSetOutline(EdadTD[1], 0);
    TextDrawSetShadow(EdadTD[1], 1);
    TextDrawAlignment(EdadTD[1], 2);
    TextDrawColor(EdadTD[1], -1);
    TextDrawBackgroundColor(EdadTD[1], 45);
    TextDrawBoxColor(EdadTD[1], 135);
    TextDrawUseBox(EdadTD[1], 0);
    TextDrawSetProportional(EdadTD[1], 1);
    TextDrawSetSelectable(EdadTD[1], 0);

    EdadTD[2] = TextDrawCreate(382.000000, 156.000000, "Paso  /");
    TextDrawFont(EdadTD[2], 1);
    TextDrawLetterSize(EdadTD[2], 0.358332, 1.799996);
    TextDrawTextSize(EdadTD[2], 298.500000, 75.000000);
    TextDrawSetOutline(EdadTD[2], 0);
    TextDrawSetShadow(EdadTD[2], 1);
    TextDrawAlignment(EdadTD[2], 2);
    TextDrawColor(EdadTD[2], -1);
    TextDrawBackgroundColor(EdadTD[2], 45);
    TextDrawBoxColor(EdadTD[2], 135);
    TextDrawUseBox(EdadTD[2], 0);
    TextDrawSetProportional(EdadTD[2], 1);
    TextDrawSetSelectable(EdadTD[2], 0);

    EdadTD[3] = TextDrawCreate(393.000000, 157.000000, "3");
    TextDrawFont(EdadTD[3], 1);
    TextDrawLetterSize(EdadTD[3], 0.358332, 1.799996);
    TextDrawTextSize(EdadTD[3], 298.500000, 75.000000);
    TextDrawSetOutline(EdadTD[3], 0);
    TextDrawSetShadow(EdadTD[3], 1);
    TextDrawAlignment(EdadTD[3], 2);
    TextDrawColor(EdadTD[3], -760727041);
    TextDrawBackgroundColor(EdadTD[3], 45);
    TextDrawBoxColor(EdadTD[3], 135);
    TextDrawUseBox(EdadTD[3], 0);
    TextDrawSetProportional(EdadTD[3], 1);
    TextDrawSetSelectable(EdadTD[3], 0);

    EdadTD[4] = TextDrawCreate(409.000000, 157.000000, "3");
    TextDrawFont(EdadTD[4], 1);
    TextDrawLetterSize(EdadTD[4], 0.358332, 1.799996);
    TextDrawTextSize(EdadTD[4], 298.500000, 75.000000);
    TextDrawSetOutline(EdadTD[4], 0);
    TextDrawSetShadow(EdadTD[4], 1);
    TextDrawAlignment(EdadTD[4], 2);
    TextDrawColor(EdadTD[4], -1);
    TextDrawBackgroundColor(EdadTD[4], 45);
    TextDrawBoxColor(EdadTD[4], 135);
    TextDrawUseBox(EdadTD[4], 0);
    TextDrawSetProportional(EdadTD[4], 1);
    TextDrawSetSelectable(EdadTD[4], 0);

    EdadTD[5] = TextDrawCreate(326.000000, 176.000000, "_");
    TextDrawFont(EdadTD[5], 1);
    TextDrawLetterSize(EdadTD[5], 0.600000, 10.549996);
    TextDrawTextSize(EdadTD[5], 298.500000, 169.500000);
    TextDrawSetOutline(EdadTD[5], 1);
    TextDrawSetShadow(EdadTD[5], 0);
    TextDrawAlignment(EdadTD[5], 2);
    TextDrawColor(EdadTD[5], -1);
    TextDrawBackgroundColor(EdadTD[5], 255);
    TextDrawBoxColor(EdadTD[5], 454695679);
    TextDrawUseBox(EdadTD[5], 1);
    TextDrawSetProportional(EdadTD[5], 1);
    TextDrawSetSelectable(EdadTD[5], 0);

    EdadTD[6] = TextDrawCreate(329.000000, 213.000000, "_");
    TextDrawFont(EdadTD[6], 1);
    TextDrawLetterSize(EdadTD[6], 0.600000, 2.100003);
    TextDrawTextSize(EdadTD[6], 298.500000, 155.000000);
    TextDrawSetOutline(EdadTD[6], 1);
    TextDrawSetShadow(EdadTD[6], 0);
    TextDrawAlignment(EdadTD[6], 2);
    TextDrawColor(EdadTD[6], -1);
    TextDrawBackgroundColor(EdadTD[6], 255);
    TextDrawBoxColor(EdadTD[6], 135);
    TextDrawUseBox(EdadTD[6], 1);
    TextDrawSetProportional(EdadTD[6], 1);
    TextDrawSetSelectable(EdadTD[6], 1);

    EdadTD[7] = TextDrawCreate(385.000000, 189.000000, "ld_beat:chit");
    TextDrawFont(EdadTD[7], 4);
    TextDrawLetterSize(EdadTD[7], 0.600000, 2.000000);
    TextDrawTextSize(EdadTD[7], 57.500000, 63.500000);
    TextDrawSetOutline(EdadTD[7], 1);
    TextDrawSetShadow(EdadTD[7], 0);
    TextDrawAlignment(EdadTD[7], 1);
    TextDrawColor(EdadTD[7], 387388762);
    TextDrawBackgroundColor(EdadTD[7], 255);
    TextDrawBoxColor(EdadTD[7], 50);
    TextDrawUseBox(EdadTD[7], 1);
    TextDrawSetProportional(EdadTD[7], 1);
    TextDrawSetSelectable(EdadTD[7], 0);

    EdadTD[8] = TextDrawCreate(390.000000, 193.000000, "ld_beat:chit");
    TextDrawFont(EdadTD[8], 4);
    TextDrawLetterSize(EdadTD[8], 0.600000, 2.000000);
    TextDrawTextSize(EdadTD[8], 48.500000, 54.000000);
    TextDrawSetOutline(EdadTD[8], 1);
    TextDrawSetShadow(EdadTD[8], 0);
    TextDrawAlignment(EdadTD[8], 1);
    TextDrawColor(EdadTD[8], -294256385);
    TextDrawBackgroundColor(EdadTD[8], 255);
    TextDrawBoxColor(EdadTD[8], 50);
    TextDrawUseBox(EdadTD[8], 1);
    TextDrawSetProportional(EdadTD[8], 1);
    TextDrawSetSelectable(EdadTD[8], 0);

    EdadTD[9] = TextDrawCreate(280.000000, 195.000000, "Digite su edad (OOC)");
    TextDrawFont(EdadTD[9], 1);
    TextDrawLetterSize(EdadTD[9], 0.229166, 1.649994);
    TextDrawTextSize(EdadTD[9], 298.500000, 75.000000);
    TextDrawSetOutline(EdadTD[9], 0);
    TextDrawSetShadow(EdadTD[9], 1);
    TextDrawAlignment(EdadTD[9], 2);
    TextDrawColor(EdadTD[9], -760727041);
    TextDrawBackgroundColor(EdadTD[9], 45);
    TextDrawBoxColor(EdadTD[9], 135);
    TextDrawUseBox(EdadTD[9], 0);
    TextDrawSetProportional(EdadTD[9], 1);
    TextDrawSetSelectable(EdadTD[9], 0);

    EdadTD[10] = TextDrawCreate(275.000000, 273.000000, "Copyright (c)");
    TextDrawFont(EdadTD[10], 1);
    TextDrawLetterSize(EdadTD[10], 0.229166, 1.649994);
    TextDrawTextSize(EdadTD[10], 298.500000, 75.000000);
    TextDrawSetOutline(EdadTD[10], 0);
    TextDrawSetShadow(EdadTD[10], 1);
    TextDrawAlignment(EdadTD[10], 2);
    TextDrawColor(EdadTD[10], -1);
    TextDrawBackgroundColor(EdadTD[10], 45);
    TextDrawBoxColor(EdadTD[10], 135);
    TextDrawUseBox(EdadTD[10], 0);
    TextDrawSetProportional(EdadTD[10], 1);
    TextDrawSetSelectable(EdadTD[10], 0);

    EdadTD[11] = TextDrawCreate(314.000000, 274.000000, "SampOut");
    TextDrawFont(EdadTD[11], 1);
    TextDrawLetterSize(EdadTD[11], 0.229166, 1.649994);
    TextDrawTextSize(EdadTD[11], 298.500000, 75.000000);
    TextDrawSetOutline(EdadTD[11], 0);
    TextDrawSetShadow(EdadTD[11], 1);
    TextDrawAlignment(EdadTD[11], 2);
    TextDrawColor(EdadTD[11], -760727041);
    TextDrawBackgroundColor(EdadTD[11], 45);
    TextDrawBoxColor(EdadTD[11], 135);
    TextDrawUseBox(EdadTD[11], 0);
    TextDrawSetProportional(EdadTD[11], 1);
    TextDrawSetSelectable(EdadTD[11], 0);

    EdadTD[12] = TextDrawCreate(368.000000, 275.000000, "All Rights Reserved");
    TextDrawFont(EdadTD[12], 1);
    TextDrawLetterSize(EdadTD[12], 0.229166, 1.649994);
    TextDrawTextSize(EdadTD[12], 298.500000, 75.000000);
    TextDrawSetOutline(EdadTD[12], 0);
    TextDrawSetShadow(EdadTD[12], 1);
    TextDrawAlignment(EdadTD[12], 2);
    TextDrawColor(EdadTD[12], -1);
    TextDrawBackgroundColor(EdadTD[12], 45);
    TextDrawBoxColor(EdadTD[12], 135);
    TextDrawUseBox(EdadTD[12], 0);
    TextDrawSetProportional(EdadTD[12], 1);
    TextDrawSetSelectable(EdadTD[12], 0);

    EdadTD[13] = TextDrawCreate(312.000000, 290.000000, "Since");
    TextDrawFont(EdadTD[13], 1);
    TextDrawLetterSize(EdadTD[13], 0.229166, 1.649994);
    TextDrawTextSize(EdadTD[13], 298.500000, 75.000000);
    TextDrawSetOutline(EdadTD[13], 0);
    TextDrawSetShadow(EdadTD[13], 1);
    TextDrawAlignment(EdadTD[13], 2);
    TextDrawColor(EdadTD[13], -1);
    TextDrawBackgroundColor(EdadTD[13], 45);
    TextDrawBoxColor(EdadTD[13], 135);
    TextDrawUseBox(EdadTD[13], 0);
    TextDrawSetProportional(EdadTD[13], 1);
    TextDrawSetSelectable(EdadTD[13], 0);

    EdadTD[14] = TextDrawCreate(333.000000, 289.000000, "2021");
    TextDrawFont(EdadTD[14], 1);
    TextDrawLetterSize(EdadTD[14], 0.229166, 1.649994);
    TextDrawTextSize(EdadTD[14], 298.500000, 75.000000);
    TextDrawSetOutline(EdadTD[14], 0);
    TextDrawSetShadow(EdadTD[14], 1);
    TextDrawAlignment(EdadTD[14], 2);
    TextDrawColor(EdadTD[14], -760727041);
    TextDrawBackgroundColor(EdadTD[14], 45);
    TextDrawBoxColor(EdadTD[14], 135);
    TextDrawUseBox(EdadTD[14], 0);
    TextDrawSetProportional(EdadTD[14], 1);
    TextDrawSetSelectable(EdadTD[14], 0);
}