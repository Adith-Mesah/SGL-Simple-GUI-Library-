#ifndef SGL_EVENT_ENGINE_INCLUDED
#define SGL_EVENT_ENGINE_INCLUDED

#include "../include/SGL_utilities.h"
typedef struct SGL_EvEngine {
    SDL_Event  event;
    SGL_Vector2 mouse_position;
    SGL_Bool exit_requested;
}SGL_EvEngine;

SGL_EvEngine SGL_CreateEvEngine();
void SGL_EvEngineRefresh(SGL_EvEngine *evEngine);


#endif
