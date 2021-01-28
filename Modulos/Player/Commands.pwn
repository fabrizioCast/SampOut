//==COMANDOS DE ROL==///
CMD:g(playerid, params[])
{
  new string[128], texto[128];
  if(!sscanf(params, "s[128]", texto))
  {
    
    format(string, sizeof(string), "%s grita: %s", NombreJugador(playerid), texto);
    ProxDetector(15.0, playerid, string,-1,-1,-1,-1,-1);
  } else ShowInfoForPlayer(playerid, "~r~ COMANDO SYNTAX : /g [GRITO]", 3000);
  return 1;
}
CMD:s(playerid, params[])
{
  new string[128], texto[128];
  if(!sscanf(params, "s[128]", texto))
  {
    
    format(string, sizeof(string), "%s susurra: %s", NombreJugador(playerid), texto);
    ProxDetector(3.0, playerid, string,-1,-1,-1,-1,-1);
  } else ShowInfoForPlayer(playerid, "~r~ COMANDO SYNTAX : /s [SUSURRO]", 3000);
  return 1;
}
CMD:e(playerid, params[])
{
  new string[128], texto[128];
  if(!sscanf(params, "s[128]", texto))
  {
    
    format(string, sizeof(string), "{8700ce}%s (%s)", texto, NombreJugador(playerid));
    ProxDetector(5.0, playerid, string,-1,-1,-1,-1,-1);
  } else ShowInfoForPlayer(playerid, "~r~ COMANDO SYNTAX : /e [ENTORNO]", 3000);
  return 1;
}
CMD:me(playerid, params[])
{
  new string[128], texto[128];
  if(!sscanf(params, "s[128]", texto))
  {
    
    format(string, sizeof(string), "{006666}%s %s",NombreJugador(playerid), texto);
    ProxDetector(5.0, playerid, string,-1,-1,-1,-1,-1);
  } else ShowInfoForPlayer(playerid, "~r~ COMANDO SYNTAX : /me [ACCION]", 3000);
  return 1;
}
CMD:b(playerid, params[])
{
  new string[128], texto[128];
  if(!sscanf(params, "s[128]", texto))
  {
    
    format(string, sizeof(string), "{006666}[OOC] %s dice: %s", NombreJugador(playerid), texto);
    ProxDetector(5.0, playerid, string,-1,-1,-1,-1,-1);
  } else ShowInfoForPlayer(playerid, "~r~ COMANDO SYNTAX : /b [OCC TEXTO]", 3000);
  return 1;
}