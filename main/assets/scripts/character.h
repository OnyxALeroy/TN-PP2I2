#include "move.h"

struct _playable_character{
    char* name;
    int Atk;
    int Def;
    int ER;
    int EB;
    int Spe;
    int MaxPV;
    int PV;
};
typedef struct _playable_character PC;

struct _Movepool{
    Move* move1;
    Move* move2;
};
typedef struct _Movepool Movepool;
