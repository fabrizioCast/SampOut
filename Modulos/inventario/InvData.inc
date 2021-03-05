
#define MAX_OBJETOS_WORDl 2000
#define MAX_INV 15 //Lo maximo que puedes llevar en el inventario (Tiene que ir en corelacion al textdraw)
#define MAX_OBJETOS 17 //Maximo de objetos creados
#define IZQ 1 //Mano izquierda
#define DER 0 // Mano derecha


//________Objetos________//
#define NADA            0
#define HIERRO          1
#define MADERA          2
#define MINADEHIERRO    3
#define RADIO           4
#define BATERIA         5
#define PICO            6
#define MOTOSIERRA      7
#define BOTELLADEAGUA   8
#define HAMBURGESA      9
#define GUN9MM          10
#define DEAGLE          11
#define MP5             12
#define M4              13
#define AMMOM4          14
#define AMMO9MM         15
#define AMMODK          16
#define CANDADO         17


//___________[LOOT]_____________//
#define TYPE_BASIC 1
#define TYPE_MILITAR 2


new O_infloor; // Contador de objetos en el server.


enum Inventory{
    bool:inmenu,
    Inv[16],
    Mano[2],
    Selected,
    weapon[4],
    ammo[4],
    usosder,
    usosizq
};
new VE[MAX_PLAYERS][Inventory];


enum ObjetosEnum{
    itemid,
    model,
    name[40],
    bool:tirar,
    Float:paramsizq[9],
    Float:paramsder[9],
    TypeObject,
    Descripcion[50],
    usos
};

enum ObjetosWordl{
    itemid,
    modelid,
    Text3D:dtext,
    objeto,
    balas,
    Float:pos[3],
    usos
};
new ObjetosPiso[MAX_OBJETOS_WORDl][ObjetosWordl];


new Objetos[][ObjetosEnum] =
{
//================================================================================================[ITEM BASICOS]====================================================================================================================//
//--ID      ModelID     Nombre                  Uso                                     POSICION MANO DER                                                                                                        POS MANO IZQ                                                       TYPE                    Descripcion
    {0,     19382,      "Nada",                 false,      {0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000}},                                                                    
    {1,     19809,      "Hierro",               true,       {0.068999, 0.030000, -0.032000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000},                {0.051999, 0.014999, 0.012000, -13.499937, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000},                0,                 "Lingote de hierro, puedes fabricar varias cosas",              1},
    {2,     19793,      "Madera",               true,       {0.071999, 0.045999, -0.019999, 0.000000, -115.900077, 26.700002, 0.842999, 0.759000, 0.666999},            {0.074999, 0.029999, -0.016999, 0.000000, -86.600021, 168.099975, 0.842999, 0.759000, 0.666999},             1,                 "Un tronco de madera",                                          1},                
    {3,     1304,       "Mina Hierro",          true,       {0.155999, 0.028000, 0.008000, 0.000000, -107.200096, 26.700002, 0.678000, 0.759000, 0.514000},             {0.150999, 0.035000, 0.043999, 0.000000, -107.200096, 26.700002, 0.678000, 0.759000, 0.514000},              1,                 "Puedes fundirlo para obtener hierro",                          1},
    {4,     19942,      "Radio",                true,       {0.092999, 0.036999, -0.013999, 0.000000, -107.200096, 26.700002, 0.678000, 0.759000, 0.643999},            {0.074999, 0.036999, 0.025000, 0.000000, -107.200096, 26.700002, 0.678000, 0.759000, 0.643999},              1,                 "Te permite comunicarte con otros refugiados",                  1},
    {5,     19897,      "Baterias",             true,       {0.092999, 0.036999, -0.013999, 0.000000, -107.200096, 26.700002, 0.678000, 0.759000, 0.643999},            {0.074999, 0.036999, 0.025000, 0.000000, -107.200096, 26.700002, 0.678000, 0.759000, 0.643999},              1,                 "Permite recargar tus componentes electronicos",                1},
    {6,     18634,      "Pico",                 true,       {0.071999, 0.045999, -0.019999, 0.000000, -115.900077, 26.700002, 0.842999, 0.759000, 0.666999},            {0.062999, 0.065999, -0.002999, 0.000000, -86.600021, -166.700027, 0.842999, 0.759000, 0.666999},            1,                 "Podras minar varios materiales con el",                        1},
    {7,     341,        "Moto Sierra",          true,       {0.032999, 0.031000, -0.043999, 172.299972, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000},              {0.018999, 0.003999, 0.036000, -4.300058, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000},                 1,                 "Podras cortar madera de los arboles con el",                   1},
    {8,     2683,       "Botella de Agua",      true,       {0.089999, 0.032999, -0.032999, 0.000000, -89.200004, 4.800000, 1.000000, 1.000000, 1.000000},              {0.064999, 0.032999, 0.020000, 0.000000, -89.200004, 4.800000, 1.000000, 1.000000, 1.000000},                1,                 "Una botella de agua, aun en buen estado",                      1},
    {9,     2768,       "Hamburguesa",          true,       {0.0, 0.0, 0.0, 0.000000, 0.0000, 0.000000, 1.000000, 1.000000, 1.000000},                                  {0.064999, 0.032999, 0.020000, 0.000000, -89.200004, 4.800000, 1.000000, 1.000000, 1.000000},                1,                 "Una hamburgesa, aun en buen estado",                           1},
    {10,    346,        "9mm",                  true,       {0.056999, 0.051000, -0.023000, 161.199935, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000},              {0.049999, -0.000999, 0.005999, 4.099944, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000},                 2,                 "Pistola de bajo calibre 9mm",                                  1},
    {11,    348,        "D.Eagle",              true,       {0.005999, 0.047999, -0.004000, 161.199935, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000},              {-0.012000, 0.004999, -0.011000, 4.299956, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000},                2,                 "Arma Desert Eagle",                                            1},
    {12,    353,        "MP5",                  true,       {0.022000, 0.050999, 0.013000, 164.699996, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000},               {0.003999, 0.004999, 0.004000, -3.200038, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000},                 2,                 "Fusil MP5.",                                                   1},
    {13,    356,        "M4",                   true,       {0.032999, 0.031000, -0.043999, 172.299972, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000},              {0.018999, 0.003999, 0.036000, -4.300058, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000},                 2,                 "Fusil de alto calibre.",                                       1},
    {14,    3013,       "Ammo M4",              true,       {0.064999, 0.032999, 0.020000, 0.000000, -89.200004, 4.800000, 1.000000, 0.600000, 0.600000},               {0.064999, 0.032999, 0.020000, 0.000000, -89.200004, 4.800000, 1.000000, 0.600000, 0.600000},                2,                 "Municion para la M4.",                                         1},
    {15,    19995,      "Ammo 9mm",             true,       {0.064999, 0.032999, 0.020000, 0.000000, -89.200004, 4.800000, 1.000000, 0.600000, 0.600000},               {0.064999, 0.032999, 0.020000, 0.000000, -89.200004, 4.800000, 1.000000, 0.600000, 0.600000},                2,                 "Municion para la 9mm",                                         1},
    {16,    19995,      "Ammo Eagle",           true,       {0.064999, 0.032999, 0.020000, 0.000000, -89.200004, 4.800000, 1.000000, 0.600000, 0.600000},               {0.064999, 0.032999, 0.020000, 0.000000, -89.200004, 4.800000, 1.000000, 0.600000, 0.600000},                2,                 "Municion para la D.Eagle",                                     1},
    {17,    19804,      "Candado",              true,       {0.068999, 0.030000, -0.032000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000},                {0.051999, 0.014999, 0.012000, -13.499937, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000},                0,                 "Usalo para proteger tus puertas o rejas!",                     1}
};

//__________________R A D I O___________________//
enum Radiof{
    GetRadio,
    Baterias,
    RadioTimer
};
new Radio[MAX_PLAYERS][Radiof];


//_____________TextDraw_______________//
new Text:inventari[14];
new PlayerText:PlayerTDI[MAX_PLAYERS][15];
new PlayerText:infoobjeto[MAX_PLAYERS];
new PlayerText:names[MAX_PLAYERS];
new PlayerText:showpreview[MAX_PLAYERS];
new PlayerText:tirard[MAX_PLAYERS];
new PlayerText:sacard[MAX_PLAYERS];
new PlayerText:usard[MAX_PLAYERS];
new PlayerText:infocantidad[MAX_PLAYERS];
new PlayerText:infodes[MAX_PLAYERS];
new PlayerText:showskin[MAX_PLAYERS];

//___________EXTRAS______________//
new bool:Puedetirar[MAX_PLAYERS];
new bool:ObjetosTimer[MAX_PLAYERS];
new timerobjetos[MAX_PLAYERS];


//________TEMPORALES_______________//
new temp_tirar[MAX_PLAYERS];