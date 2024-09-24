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
extern float cookies;
extern float cookiesPerClick;
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
extern gfx_sprite_t *templeShopIcon;
extern gfx_sprite_t *towerShopIcon;
extern gfx_sprite_t *shipmentShopIcon;
extern gfx_sprite_t *alchemyShopIcon;

extern float mouseCost;
extern float mouseMultiplier;
extern int mouseOwned;
extern float grandmaCost;
extern float grandmaMultiplier;
extern int grandmaOwned;
extern float farmCost;
extern float farmMultiplier;
extern int farmOwned;
extern float mineCost;
extern float mineMultiplier;
extern int mineOwned;
extern float factoryCost;
extern float factoryMultiplier;
extern int factoryOwned;
extern float bankCost;
extern float bankMultiplier;
extern int bankOwned;
extern float templeCost;
extern float templeMultiplier;
extern int templeOwned;
extern float towerCost;
extern float towerMultiplier;
extern int towerOwned;
extern float shipmentCost;
extern float shipmentMultiplier;
extern int shipmentOwned;
extern float alchemyCost;
extern float alchemyMultiplier;
extern int alchemyOwned;

void getInput(void);
void renderWindow(void);
void decompressSprites(void);
void initGfx(void);
void timerStuff(void);

#endif