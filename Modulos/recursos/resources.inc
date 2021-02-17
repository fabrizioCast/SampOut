#include <YSI\y_hooks>

#define MAX_LOOT_MADERA 200
#define MAX_LOOT_HIERRO 200



enum LootMadera{
    M_ID,
    M_ModelID,
    Float:M_Pos[3],
    bool:M_Talado,
    Text3D:M_Text,
    M_Create
};
new MaderaLoot[MAX_LOOT_MADERA][LootMadera];
new countwood;

enum LootHierro{
    H_ID,
    H_ModelID,
    Float:H_Pos[3],
    bool:H_Minado,
    Text3D:H_Text,
    H_Create
};
new HierroLoot[MAX_LOOT_HIERRO][LootHierro];
new counthierro;



CMD:recurso(playerid, params[1])
{
    if(sscanf(params, "d", params[0])) return ShowInfoForPlayer(playerid, "Uso: /recurso [tipo]", 3000);
    CreateResourse(playerid, params[0]);
    return 1;
}
hook:OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_NO))
    {
        for(new i; i <= countwood; i++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 5.0, MaderaLoot[i][M_Pos][0], MaderaLoot[i][M_Pos][1], MaderaLoot[i][M_Pos][2]))
            {
                if(MaderaLoot[i][M_Talado] == false)
                {
                    ShowProgressMessage(playerid, KEY_CROUCH, "Preciona ~r~C ~w~rapidamente para talar el arbol", 0, i);
                    ApplyAnimation(playerid, "CHAINSAW", "WEAPON_CSAW", 4.1, 1, 0, 0, 1, 0);
                }
            }
        }
        for(new i; i <= counthierro; i++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 5.0, HierroLoot[i][H_Pos][0], HierroLoot[i][H_Pos][1], HierroLoot[i][H_Pos][2]))
            {
                if(HierroLoot[i][H_Minado] == false)
                {
                    ShowProgressMessage(playerid, KEY_CROUCH, "Preciona ~r~C ~w~rapidamente para minar el hierro", 1, i);
                    ApplyAnimation(playerid, "BASEBALL", "BAT_4", 4.1, 1, 0, 0, 1, 0);
                }
            }
        }
    }
}
stock CreateResourse(playerid, type)
{
    if(type == 0)
    {
        if(countwood < MAX_LOOT_MADERA)
        {
            for(new i = 1; i < MAX_LOOT_MADERA; i++)
            {
                if(MaderaLoot[i][M_ID] == 0)
                {
                    new Float:posp[3];
                    GetPlayerPos(playerid, posp[0], posp[1], posp[2]);
                    MaderaLoot[i][M_ID] = i;
                    MaderaLoot[i][M_Pos][0] = posp[0]-2;
                    MaderaLoot[i][M_Pos][1] = posp[1];
                    MaderaLoot[i][M_Pos][2] = posp[2]-0.95;
                    MaderaLoot[i][M_Talado] = false;
                    countwood++;
                    new arbolrnd = random(2);
                    switch(arbolrnd)
                    {
                        case 0: MaderaLoot[i][M_ModelID] = CreateObject(664, MaderaLoot[i][M_Pos][0], MaderaLoot[i][M_Pos][1], MaderaLoot[i][M_Pos][2], 0.0, 0.0, 0.0, 250.0);
                        case 1: MaderaLoot[i][M_ModelID] = CreateObject(671, MaderaLoot[i][M_Pos][0], MaderaLoot[i][M_Pos][1], MaderaLoot[i][M_Pos][2], 0.0, 0.0, 0.0, 250.0);
                        case 2: MaderaLoot[i][M_ModelID] = CreateObject(672, MaderaLoot[i][M_Pos][0], MaderaLoot[i][M_Pos][1], MaderaLoot[i][M_Pos][2], 0.0, 0.0, 0.0, 250.0);
                    }
                    printf("Arbol creado con la ID: %d", MaderaLoot[i][M_ID]);
                    MaderaLoot[i][M_Text] = Create3DTextLabel("Preciona {D54028}[N] {ffffff}para comenzar a talar este arbol", -1, MaderaLoot[i][M_Pos][0], MaderaLoot[i][M_Pos][1], MaderaLoot[i][M_Pos][2], 5.0, 0);
                    MaderaLoot[i][M_Create] = GetObjectModel(MaderaLoot[i][M_ModelID]);
                    new handle = SQL::Open(SQL::INSERT, "madera");
                    SQL::WriteInt(handle, "ID", MaderaLoot[i][M_ID]);
                    SQL::WriteFloat(handle, "PosX", MaderaLoot[i][M_Pos][0]);
                    SQL::WriteFloat(handle, "PosY", MaderaLoot[i][M_Pos][1]);
                    SQL::WriteFloat(handle, "PosZ", MaderaLoot[i][M_Pos][2]);
                    SQL::WriteInt(handle, "ModelID", MaderaLoot[i][M_Create]);
                    SQL::Close(handle);
                    break;
                }
            }
        } else return ShowInfoForPlayer(playerid, "~r~Maximo de loot de madera alcanzado", 3000);
    }
    if(type == 1)
    {
        if(counthierro < MAX_LOOT_HIERRO)
        {
            for(new i = 1; i < MAX_LOOT_HIERRO; i++)
            {
                if(HierroLoot[i][H_ID] == 0)
                {
                    new Float:posh[3];
                    GetPlayerPos(playerid, posh[0], posh[1], posh[2]);
                    HierroLoot[i][H_ID] = i;
                    HierroLoot[i][H_Pos][0] = posh[0]-2;
                    HierroLoot[i][H_Pos][1] = posh[1];
                    HierroLoot[i][H_Pos][2] = posh[2]-1;
                    HierroLoot[i][H_Minado] = false;
                    HierroLoot[i][H_ModelID] = CreateObject(1304, HierroLoot[i][H_Pos][0], HierroLoot[i][H_Pos][1], HierroLoot[i][H_Pos][2], 0.0, 0.0, 0.0, 250.00); 
                    HierroLoot[i][H_Text] = Create3DTextLabel("Preciona {D54028}[N] {ffffff}para comenzar a minar hierro", -1, HierroLoot[i][H_Pos][0], HierroLoot[i][H_Pos][1], HierroLoot[i][H_Pos][2], 5.0, 0);
                    HierroLoot[i][H_Create] = GetObjectModel(HierroLoot[i][H_ModelID]);
                    counthierro++;
                    new handle = SQL::Open(SQL::INSERT, "hierro");
                    SQL::WriteInt(handle, "ID", HierroLoot[i][H_ID]);
                    SQL::WriteFloat(handle, "PosX", HierroLoot[i][H_Pos][0]);
                    SQL::WriteFloat(handle, "PosY", HierroLoot[i][H_Pos][1]);
                    SQL::WriteFloat(handle, "PosZ", HierroLoot[i][H_Pos][2]);
                    SQL::WriteInt(handle, "ModelID", HierroLoot[i][H_Create]);
                    SQL::Close(handle);
                    break;
                }
            }
        } else return ShowInfoForPlayer(playerid, "~r~Maximo de loot de hierro alcanzado", 3000);
    }
    return 1;
}

stock DestroyResource(type, id)
{
    if(type == 0)
    {
        if(MaderaLoot[id][M_ID] >= 1)
        {
           MaderaLoot[id][M_Talado] = true;
           Delete3DTextLabel(MaderaLoot[id][M_Text]);
           DestroyObject(MaderaLoot[id][M_ModelID]);
           SetTimerEx("RespawnResource", 15000, false, "dd", type, MaderaLoot[id][M_ID]); 
           return 1;
        }
    }
    if(type == 1)
    {
        if(HierroLoot[id][H_ID] >= 1)
        {
            HierroLoot[id][H_Minado] = true;
            Delete3DTextLabel(HierroLoot[id][H_Text]);
            DestroyObject(HierroLoot[id][H_ModelID]);
            SetTimerEx("RespawnResource", 15000, false, "dd", type, HierroLoot[id][H_ID]);
        }
    }
    return 1;
}
forward RespawnResource(type, id);
public RespawnResource(type, id)
{
    if(type == 0)
    {
        MaderaLoot[id][M_Talado] = false;
        new arbolrnd = random(2);
        switch(arbolrnd)
        {
            case 0: MaderaLoot[id][M_ModelID] = CreateObject(664, MaderaLoot[id][M_Pos][0], MaderaLoot[id][M_Pos][1], MaderaLoot[id][M_Pos][2], 0.0, 0.0, 0.0, 250.0);
            case 1: MaderaLoot[id][M_ModelID] = CreateObject(671, MaderaLoot[id][M_Pos][0], MaderaLoot[id][M_Pos][1], MaderaLoot[id][M_Pos][2], 0.0, 0.0, 0.0, 250.0);
            case 2: MaderaLoot[id][M_ModelID] = CreateObject(672, MaderaLoot[id][M_Pos][0], MaderaLoot[id][M_Pos][1], MaderaLoot[id][M_Pos][2], 0.0, 0.0, 0.0, 250.0);
        }
        MaderaLoot[id][M_Text] = Create3DTextLabel("Preciona {D54028}[N] {ffffff}para comenzar a talar este arbol", -1, MaderaLoot[id][M_Pos][0], MaderaLoot[id][M_Pos][1], MaderaLoot[id][M_Pos][2], 5.0, 0);
    }
    if(type == 1)
    {
        HierroLoot[id][H_Minado] = false;
        HierroLoot[id][H_ModelID] = CreateObject(1304, HierroLoot[id][H_Pos][0], HierroLoot[id][H_Pos][1], HierroLoot[id][H_Pos][2], 0.0, 0.0, 0.0, 250.00); 
        HierroLoot[id][H_Text] = Create3DTextLabel("Preciona {D54028}[N] {ffffff}para comenzar a minar hierro", -1, HierroLoot[id][H_Pos][0], HierroLoot[id][H_Pos][1], HierroLoot[id][H_Pos][2], 5.0, 0);
    }
    return 1;
}

stock CargarRecursos()
{
    for(new i; i < MAX_LOOT_MADERA; i++)
    {
        new hand = SQL::Open(SQL::MTREAD, "madera");
        new pia;
        SQL::ReadInt(hand, "ID", pia, i);
        MaderaLoot[pia][M_ID] = pia;
        SQL::ReadFloat(hand, "PosX", MaderaLoot[pia][M_Pos][0], i);
        SQL::ReadFloat(hand, "PosY", MaderaLoot[pia][M_Pos][1], i);
        SQL::ReadFloat(hand, "PosZ", MaderaLoot[pia][M_Pos][2], i);
        SQL::ReadInt(hand, "ModelID", MaderaLoot[pia][M_Create], i);
        countwood = SQL::Close(hand);
        MaderaLoot[pia][M_ModelID] = CreateObject(MaderaLoot[pia][M_Create], MaderaLoot[pia][M_Pos][0], MaderaLoot[pia][M_Pos][1], MaderaLoot[pia][M_Pos][2], 0.0, 0.0, 0.0, 250.00);
        MaderaLoot[pia][M_Text] = Create3DTextLabel("Preciona {D54028}[N] {ffffff}para comenzar a talar este arbol", -1, MaderaLoot[pia][M_Pos][0], MaderaLoot[pia][M_Pos][1], MaderaLoot[pia][M_Pos][2], 5.0, 0);
    }
    printf("[Arboles Cargados]: %d", countwood);
    for(new i; i < MAX_LOOT_HIERRO; i++)
    {
        new hand = SQL::Open(SQL::MTREAD, "hierro");
        new pia;
        SQL::ReadInt(hand, "ID", pia, i);
        HierroLoot[pia][H_ID] = pia;
        SQL::ReadFloat(hand, "PosX", HierroLoot[pia][H_Pos][0], i);
        SQL::ReadFloat(hand, "PosY", HierroLoot[pia][H_Pos][1], i);
        SQL::ReadFloat(hand, "PosZ", HierroLoot[pia][H_Pos][2], i);
        SQL::ReadInt(hand, "ModelID", HierroLoot[pia][H_Create], i);
        counthierro = SQL::Close(hand);
        HierroLoot[pia][H_ModelID] = CreateObject(HierroLoot[pia][H_Create], HierroLoot[pia][H_Pos][0], HierroLoot[pia][H_Pos][1], HierroLoot[pia][H_Pos][2], 0.0, 0.0, 0.0, 250.00);
        HierroLoot[pia][H_Text] = Create3DTextLabel("Preciona {D54028}[N] {ffffff}para comenzar a minar hierro", -1, HierroLoot[pia][H_Pos][0], HierroLoot[pia][H_Pos][1], HierroLoot[pia][H_Pos][2], 5.0, 0);
    }
    printf("[Hierros Cargados]: %d", counthierro);
    new total = counthierro + countwood;
    printf("[Recursos Total]: %d", total);
    return 1;
}