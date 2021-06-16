#include "include/SGL.h"
#include <SDL2/SDL_ttf.h>


#define WINDOW_TITLE "SGL Development Window Test"
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 700

void init();
void update(); 
void destroy();



SDL_Window *window = NULL;
SDL_Event event;
SDL_Renderer *renderer = NULL;
SDL_Color background_color = {255,255,255,255};
SGL_EvEngine evEngine;
    
SGL_Panel panel;

int main(int argc, const char **argv) {
    
    
    init();
    panel = SGL_CreatePanel("something",100,100,400,400,renderer,&evEngine);
    panel.border = false;
    update();
    destroy();
    return 0;
}

void init() {
    SGL_Init();
    window = SDL_CreateWindow(
        WINDOW_TITLE,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );
    
    if(window == NULL) {
        SDL_Log("failed to create window: %s",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    renderer = SDL_CreateRenderer(
        window,-1,SDL_RENDERER_ACCELERATED
    );
    
    if(renderer == NULL) {
        SDL_Log("failed to create renderer: %s",SDL_GetError());
        exit(EXIT_FAILURE);
    }

    
    
    evEngine = SGL_CreateEvEngine();
}




void update() {
    
    while(!evEngine.exit_requested) {
        
        SGL_EvEngineRefresh(&evEngine);
        SGL_SetRenderDrawColor(renderer,&background_color);
                               
        SDL_RenderClear(renderer);
            
        SGL_PanelShow(&panel);
        
        SDL_RenderPresent(renderer);
        SDL_UpdateWindowSurface(window);
    }
}

void destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SGL_Quit();
}
