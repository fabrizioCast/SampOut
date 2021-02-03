enum EmpresaMeca{
    Jefe,
    Empleado,
    Rangos,
    NombreEmpresa[25],
    ColorEmpresa,
    bool:EnPanel,
    Reparando,
    CajaFuerte
};
new Mecanico[MAX_PLAYERS][EmpresaMeca];
new LocalMecanico;
new Text3D:labelmeca;
new ComprobarReja;
new ComprobarReja2;
new Puerta[3];
new Text:PanelTD[10];
new PlayerText:PlayerTD[MAX_PLAYERS][2];
new IDRango;
new IDCliente;
new cocheid;
new Color_1;
new Color_2;
new PressKey[MAX_PLAYERS];
//////////////////////////////////////////////
enum nivel{
    p_nivel,//guardar
    p_exp,//guardar
    p_loggedin,
    p_minutos,
};
new hora, minutos, segundos, time2;
new Jugador[MAX_PLAYERS][nivel];
new payday[MAX_PLAYERS];
new puedecobrar[MAX_PLAYERS];