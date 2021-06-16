#ifndef SGL_UTILITIES_INCLUDED
#define SGL_UTILITIES_INCLUDED

#include "SGL_externals.h"
typedef bool SGL_Bool;

typedef struct SGL_Vector2 {
    int x, y;
}SGL_Vector2;

typedef struct SGL_Vector2f {
    float x, y;
}SGL_Vector2f;


typedef struct SGL_DragProp {
    int xoffset, yoffset;
    int xcaptured, ycaptured;
    SGL_Bool hold;
    SGL_Bool mouse_dragging;
}SGL_DragProp;


void SGL_Init();
void SGL_Quit();

void SGL_SetRenderDrawColor(SDL_Renderer *renderer, SDL_Color *color);
float PercentToValue(unsigned int total,unsigned int percent);
void dragRectProcess(SDL_Rect *rect,SGL_DragProp *dp,SGL_Bool mouse_pressed,int x,int y);
SGL_Bool point_inside(SDL_Rect *rect,int x,int y);



#endif // SGL_utilities.h
