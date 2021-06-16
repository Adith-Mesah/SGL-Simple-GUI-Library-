#include "../include/SGL_label.h"

TTF_Font *default_font = NULL;
SDL_Color default_font_color = LABEL_FONT_COLOR;


void SGL_LabelShow(SGL_Label *label) {

    SDL_RenderCopy(label->renderer,label->texture,NULL,NULL);
}

SGL_Label SGL_CreateLabel(const char *text,SGL_Vector2 position,SDL_Renderer *renderer) {
    SGL_Label label;
    label.text = text;
    label.position = position;
    label.renderer = renderer;
    label.surface = TTF_RenderText_Solid(default_font,text,default_font_color);
    label.texture = SDL_CreateTextureFromSurface(
        renderer,label.surface
    );
}

void SGL_DestroyLabel(SGL_Label *label) {
    SDL_DestroyTexture(label->texture);
    SDL_FreeSurface(label->surface);
}