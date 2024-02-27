#define WIDTH 1280
#define HEIGHT 960

typedef struct main_Perso {
    int x;
    int y;
    int height;
    int width;
    int speed;
    SDL_Texture* texture;
    int is_right;
} Main_Perso;

Main_Perso* create_perso();
