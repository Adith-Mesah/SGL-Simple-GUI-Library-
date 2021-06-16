#include "../include/SGL_utilities.h"


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
