#include <graphx.h>
#include <math.h>
#include "gfx/ccsprt.h"
#ifndef GET_INPUT_H
#define GET_INPUT_H

extern int mouseX;
extern int mouseY;
extern int clicking;
extern int i;
extern int shopMenu;
extern unsigned int cookies;
extern unsigned int cookiesPerClick;
extern int inGame;
extern int menu;
extern int frames;
extern char playerName[];

extern gfx_sprite_t *mouse1;
extern gfx_sprite_t *perfectCookie;
extern gfx_sprite_t *perfectCookieClicked;
extern gfx_sprite_t *functionButton;
extern gfx_sprite_t *shopSlot;
extern gfx_sprite_t *menuSwitchButton;
extern gfx_sprite_t *mouseShopIcon;
extern gfx_sprite_t *grandmaShopIcon;
extern gfx_sprite_t *farmShopIcon;
extern gfx_sprite_t *mineShopIcon;
extern gfx_sprite_t *factoryShopIcon;
extern gfx_sprite_t *bankShopIcon;

extern unsigned int mouseCost;
extern int mouseOwned;
extern unsigned int grandmaCost;
extern int grandmaOwned;

void getInput(void);
void renderWindow(void);
void decompressSprites(void);
void initGfx(void);
void timerStuff(void);

#endif