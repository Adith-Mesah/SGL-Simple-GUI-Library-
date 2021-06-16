#ifndef SGL_LABEL_INCLUDED
#define SGL_LABEL_INCLUDED

#include "../include/SGL_externals.h"
#include "../include/SGL_utilities.h"

#define LABEL_FONT_SIZE 10
#define LABEL_FONT_COLOR (SDL_Color){0,0,0,255}

extern TTF_Font *default_font;
extern SDL_Color default_font_color;

typedef struct SGL_Label {
    const char *text;
    SGL_Vector2 position;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Texture *texture;

    SDL_Rect *src_rect;
    SDL_Rect *des_rect;
}SGL_Label;

void SGL_LabelShow(SGL_Label *label);
SGL_Label SGL_CreateLabel(const char *text,SGL_Vector2 position,SDL_Renderer *renderer);
void SGL_DestroyLabel(SGL_Label *label);

#endif // SDL_label.h