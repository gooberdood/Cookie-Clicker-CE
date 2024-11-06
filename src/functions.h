#include <graphx.h>
#include <math.h>
#include "gfx/ccsprt.h"
#include "loadSprites.h"
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
void initGfx(void);
void timerStuff(void);

#endif