//gcc game_00.c -lm -lSDL2 -lSDL2main -o game_00
#include <SDL2/SDL.h>
#include <math.h>

#define true     1
#define false     0

//Screen dimension in pixels
#define _W 900
#define _H 900

typedef struct punt{
    int x;
    int y;
} t_punt;

void    _init_aleat();
int    _aleat(int n);

int main(int argc, char ** argv)
{
    int quit = false;
    SDL_Event event;
   
     t_punt punt;
     SDL_Rect rect = {100,100,100,100};

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow("SDL2 Chaos Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _W, _H, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

    _init_aleat();
    while (!quit)
    {
          if (( SDL_PollEvent(&event) ) && (event.type == SDL_QUIT )) quit = true;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                rect.x = _aleat(_W);
                rect.y = _aleat(_H);               
                SDL_RenderDrawRect(renderer, &rect);
                SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void    _init_aleat(){srand(time(NULL));}
int    _aleat(int n){return rand() % n;}


