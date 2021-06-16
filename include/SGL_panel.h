#ifndef SGL_PANEL_INCLUDED
#define SGL_PANEL_INCLUDED

#include "SGL_utilities.h"
#include "SGL_event_engine.h"

#define PANEL_TITLE_HEIGHT 5
#define PANEL_BACKGROUND_COLOR (SDL_Color){0,255,0,255}
#define PANEL_TITLE_COLOR (SDL_Color){255,0,0,255}
#define PANEL_BORDER_COLOR (SDL_Color){0,0,255,255}

#define PANEL_BORDER_SIZE 1

typedef struct SGL_Panel {
    const char *title;
    SGL_Vector2f position;
    SGL_Vector2f size;
    
    
    SGL_EvEngine *evEngine;
    SDL_Renderer *renderer;
    
    SDL_Rect container_rect;
    SDL_Rect title_rect;
    SDL_Rect content_rect;
    SDL_Rect border_rect;
    
    SDL_Color background_color;
    SDL_Color title_color;
    SDL_Color border_color;
    
    SGL_Bool border;
    unsigned int border_size;
    unsigned int title_height_percent;
    unsigned int title_height;
    
    SGL_DragProp dp;
}SGL_Panel;


SGL_Panel SGL_CreatePanel(const char *title,float x, float y,
                          float width,float height,
                          SDL_Renderer *renderer,
                          SGL_EvEngine *evEngine
                         );
void SGL_PanelShow(SGL_Panel *panel);
void SGL_PanelSetBorderSize(SGL_Panel *panel, unsigned int border_size);
void __SGL_PanelRealignRect(SGL_Panel *panel);
#endif // SGL_panel.h
