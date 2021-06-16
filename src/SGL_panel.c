#include "../include/SGL_panel.h"


SGL_Panel SGL_CreatePanel(const char *title,float x, float y,
                          float width,float height,
                          SDL_Renderer *renderer,
                          SGL_EvEngine *evEngine) {
    SGL_Panel panel = {
        title,(SGL_Vector2f){x,y},
        (SGL_Vector2f){width,height},
        evEngine,
        renderer,
        (SDL_Rect){x,y,width,height},
        (SDL_Rect){x,y,width,(unsigned int)PercentToValue(height,PANEL_TITLE_HEIGHT)},
        (SDL_Rect){x,y+PANEL_TITLE_HEIGHT,width,height-PANEL_TITLE_HEIGHT},
        (SDL_Rect){x-PANEL_BORDER_SIZE,y-PANEL_BORDER_SIZE,width+PANEL_BORDER_SIZE*2,height+PANEL_BORDER_SIZE*2},
        PANEL_BACKGROUND_COLOR,PANEL_TITLE_COLOR,
        PANEL_BORDER_COLOR,
        PANEL_BORDER_SIZE,
        true,PANEL_TITLE_HEIGHT,
        (unsigned int)PercentToValue(height,PANEL_TITLE_HEIGHT),
        (SGL_DragProp){
            0,0,0,0,false,false}
    };
    return panel;
}


void __SGL_PanelRealignRect(SGL_Panel *panel) {
    
    panel->container_rect.x = panel->title_rect.x;
    panel->container_rect.y = panel->title_rect.y;
    
    panel->title_rect.w = panel->container_rect.w;
    panel->title_rect.h = panel->title_height;
    
    panel->content_rect.x = panel->container_rect.x;
    panel->content_rect.y = panel->container_rect.y+panel->title_height;
    panel->content_rect.w = panel->container_rect.w;
    panel->content_rect.h = panel->container_rect.h-panel->title_height;
    
    panel->border_rect.x = panel->container_rect.x-panel->border_size;
    panel->border_rect.y = panel->container_rect.y-panel->border_size;
    panel->border_rect.w = panel->container_rect.w+panel->border_size*2;
    panel->border_rect.h = panel->container_rect.h+panel->border_size*2;
}

void SGL_PanelSetBorderSize(SGL_Panel *panel, unsigned int border_size) {
   panel->border_size = border_size;
   __SGL_PanelRealignRect(panel);
}

void SGL_PanelShow(SGL_Panel *panel) {
    
    dragRectProcess(&panel->title_rect,&panel->dp,
                    (panel->evEngine->event.button.button==SDL_BUTTON_LEFT)?true:false,
                    panel->evEngine->mouse_position.x,panel->evEngine->mouse_position.y);
    if(panel->dp.mouse_dragging) {
        __SGL_PanelRealignRect(panel);
    }
    
    if(panel->border) {
        SGL_SetRenderDrawColor(panel->renderer,&panel->border_color);
        SDL_RenderFillRect(panel->renderer,
                        &panel->border_rect);
    }
    
    SGL_SetRenderDrawColor(panel->renderer,&panel->background_color);
    SDL_RenderFillRect(panel->renderer,
                       &panel->content_rect);
    
    SGL_SetRenderDrawColor(panel->renderer,&panel->title_color);
    SDL_RenderFillRect(panel->renderer,
                       &panel->title_rect);
    
}
