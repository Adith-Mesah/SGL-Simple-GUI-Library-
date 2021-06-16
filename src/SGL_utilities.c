#include "../include/SGL_utilities.h"
#include "../include/SGL_label.h"


inline void SGL_SetRenderDrawColor(SDL_Renderer *renderer, SDL_Color *color) {
    SDL_SetRenderDrawColor(renderer,
                           color->r,
                           color->g,
                           color->b,
                           color->a);
} 

float PercentToValue(unsigned int total,unsigned int percent) {
    return (total*percent)/100;
}

inline SGL_Bool point_inside(SDL_Rect *rect,int x,int y) {
    if(x > rect->x && x < (rect->x+rect->w)) {
        if(y > rect->y && y < (rect->y+rect->h)) {
            return true;
        }
    }
    return false;
}

inline void dragRectProcess(SDL_Rect *rect,SGL_DragProp *dp,SGL_Bool mouse_pressed,int x,int y) {
    if(mouse_pressed) {
        if(point_inside(rect,x,y)) {
            dp->mouse_dragging = true;
            if(!dp->hold) {
                dp->xoffset = x - rect->x;
                dp->yoffset = y - rect->y;
                dp->hold = true;
            }
        }
    }
    
    else {
        dp->hold = false;
        dp->mouse_dragging = false;
    }
    if(dp->mouse_dragging) {
     
        rect->x = x - dp->xoffset;
        rect->y = y - dp->yoffset;
    }

}


void SGL_Init() {
    if(SDL_Init(SDL_INIT_EVERYTHING)<0) {
        SDL_Log("failed to initialize SDL2: %s",SDL_GetError());
        exit(EXIT_FAILURE);
    }  

    if(TTF_Init()<0) {
        SDL_Log("failed to initialize TTF: %s",TTF_GetError());
        exit(EXIT_FAILURE);
    }

    default_font = TTF_OpenFont("res/hack.ttf",LABEL_FONT_SIZE);   
    if(default_font == NULL) {
        SDL_Log("failed to create font: %s",TTF_GetError());
        exit(EXIT_FAILURE);
    }
}

void SGL_Quit() {

    TTF_CloseFont(default_font);
    TTF_Quit();
    SDL_Quit();
}