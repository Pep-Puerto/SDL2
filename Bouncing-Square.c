//gcc game_00.c -lm -lSDL2 -lSDL2main -o game_00
#include <SDL2/SDL.h>
#include <math.h>

#define true     1
#define false    0

//Screen dimension in pixels
#define _W 900
#define _H 900

typedef struct object{
     SDL_Rect rect;
     double x;
     double y;
     double v;
     double vx;
     double vy;
     double ax;
     double ay;
    double angle;
} t_object;

float dt;

void   _init_aleat();
int    _aleat(int n);

int main(int argc, char ** argv)
{
    int quit = false;
    SDL_Event event;
   
    t_object object;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow("SDL2 Bouncing Square ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _W, _H, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);


    _init_aleat();
    dt = 1;
    object.rect.w = 10;
    object.rect.h = 10;
    object.v = 2;
    object.angle = 0.5;
    object.x = _W / 2;
    object.y = _H / 2;
    object.vx = object.v * cos(object.angle);
    object.vy = object.v * sin(object.angle);
    object.rect.x = (int) object.x;
    object.rect.y = (int) object.y;
    while (!quit)
    {
          if (( SDL_PollEvent(&event) ) && (event.type == SDL_QUIT )) quit = true;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                object.x = object.x + object.vx * dt;
                if (( object.x >= _W ) || ( object.x <=0 )) object.vx = -object.vx;
                object.y = object.y + object.vy * dt;
                if (( object.y >= _H ) || ( object.y <=0 )) object.vy = -object.vy;
                object.rect.x = (int) object.x;
                object.rect.y = (int) object.y;
                SDL_RenderDrawRect(renderer, &(object.rect));
                SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

void    _init_aleat(){srand(time(NULL));}
int    _aleat(int n){return rand() % n;}