#include <graphx.h>
#include "gfx/ccsprt.h"
#ifndef GET_INPUT_H
#define GET_INPUT_H

extern int mouseX;
extern int mouseY;
extern int clicking;
extern int i;
extern const int clickTextStartVelocity;
extern unsigned int cookies;
extern unsigned int cookiesPerClick;
extern int inGame;
extern int menu;
extern int clickTextObjs[];
extern char playerName[];
extern gfx_sprite_t *mouse1;
extern gfx_sprite_t *perfectCookie;
extern gfx_sprite_t *perfectCookieClicked;
extern gfx_sprite_t *functionButton;

void getInput(void);
void renderWindow(void);
void decompressSprites(void);
void initGfx(void);
void animationTiming(void);

#endif