// ------------------------------------------------------------------------------------------------

struct _move_core
{
    int (*damage_calculator)(int stats[7]);
    // target (struct probably)    
};

// ------------------------------------------------------------------------------------------------

struct _move
{
    struct _move_core* Base;
    int cost;
};
typedef struct _move Move;

// ------------------------------------------------------------------------------------------------

struct _ultimate
{
    struct _move_core* Base;
};
typedef struct _ultimate Ultimate;

// ------------------------------------------------------------------------------------------------

struct _passive
{
    struct _move_core* Base;
};
typedef struct _passive Passive;
