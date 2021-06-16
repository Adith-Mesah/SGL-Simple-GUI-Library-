#include "../include/SGL_event_engine.h"


SGL_EvEngine SGL_CreateEvEngine() {
    SGL_EvEngine evEngine;
    evEngine.mouse_position = (SGL_Vector2){0,0};
    evEngine.exit_requested = false;
    return evEngine;
}

void SGL_EvEngineRefresh(SGL_EvEngine *evEngine) {
    while(SDL_PollEvent(&evEngine->event)>0) {
        switch(evEngine->event.type) {
            case SDL_QUIT:
                evEngine->exit_requested = true;
                break;
            case SDL_MOUSEMOTION:
                evEngine->mouse_position.x = evEngine->event.motion.x;
                evEngine->mouse_position.y = evEngine->event.motion.y;
                break;
        }
    }
   
}
