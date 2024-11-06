#include <keypadc.h>
#include <compression.h>
#include <graphx.h>
#include <math.h>
#include "gfx/ccsprt.h"
#include "functions.h"
#include "loadSprites.h"

int mouseX = 160;
int mouseY = 120;
int menu = 1;
int inGame = true;
int i;
int shopMenu = 1;
int frames = 0;
float cookies = 0;
float cookiesPerClick = 1;
int clicking = false;
char playerName[] = "Player";
int bakeryNameLength;

float mouseCost = 15;
float mouseMultiplier = 0.1;
int mouseOwned = 0;
float grandmaCost = 100;
float grandmaMultiplier = 1;
int grandmaOwned = 0;
float farmCost = 1100;
float farmMultiplier = 8;
int farmOwned = 0;
float mineCost = 12000;
float mineMultiplier = 47;
int mineOwned = 0;
float factoryCost = 130000;
float factoryMultiplier = 260;
int factoryOwned = 0;
float bankCost = 1400000;
float bankMultiplier = 1400;
int bankOwned = 0;
float templeCost = 20000000;
float templeMultiplier = 7800;
int templeOwned = 0;
float towerCost = 330000000;
float towerMultiplier = 44000;
int towerOwned = 0;
float shipmentCost = 5100000000;
float shipmentMultiplier = 260000;
int shipmentOwned = 0;
float alchemyCost = 75000000000;
float alchemyMultiplier = 1600000;
int alchemyOwned = 0;


//initialize gfx / set up
void initGfx(void) {
    gfx_Begin();
	gfx_SetDrawBuffer();
	//sets palette and transparent color
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
	gfx_SetTransparentColor(0);
	gfx_SetTextTransparentColor(0);
	gfx_SetTextBGColor(0);
	gfx_SetTextConfig(gfx_text_clip);
}


void getInput(void) {
	//scans the keypad, then checks inputs
	kb_Scan();
	if (kb_Data[6] & kb_Clear) {inGame = false;}
	if (kb_Data[7] & kb_Down) {mouseY += 5;}
	if (kb_Data[7] & kb_Up) {mouseY -= 5;}
	if (kb_Data[7] & kb_Left) {mouseX -= 5;}
	if (kb_Data[7] & kb_Right) {mouseX += 5;}
	
	if ((kb_Data[1] & kb_2nd) || (kb_Data[6] & kb_Enter)) {
		if (clicking == false) {
			if (menu == 1) {
				if ((mouseX < 139 && mouseX > 39) && (mouseY < 174 && mouseY > 74)) {
					cookies += cookiesPerClick;
				}
				if (mouseY < 203 && mouseY > 171) {
					if (mouseX < 244 && mouseX > 191) {
						if (shopMenu > 1) {
							shopMenu = shopMenu - 1;
						}
					}
					if (mouseX < 320 && mouseX > 247) {
						if (shopMenu <= 4) {
							shopMenu = shopMenu + 1;
						}
					}
				}
				if (mouseX < 320 && mouseX > 191) { //sees if cursor is by the shop boxes
					if (mouseY < 33 && mouseY > 1) {
						if (shopMenu == 1) {
							if (cookies >= mouseCost) {
								cookies -= mouseCost;
								mouseCost = mouseCost * 1.15;
								mouseOwned += 1;
							}
						}
						if (shopMenu == 2) {
							if (cookies >= bankCost) {
								cookies -= bankCost;
								bankCost = bankCost * 1.15;
								bankOwned += 1;
							}
						}
					}
					if (mouseY < 66 && mouseY > 33) {
						if (shopMenu == 1) {
							if (cookies >= grandmaCost) {
								cookies -= grandmaCost;
								grandmaCost = grandmaCost * 1.15;
								grandmaOwned += 1;
							}
						}
						if (shopMenu == 2) {
							if (cookies >= templeCost) {
								cookies -= templeCost;
								templeCost = templeCost * 1.15;
								templeOwned += 1;
							}
						}
					}
					if (mouseY < 99 && mouseY > 66) {
						if (shopMenu == 1) {
							if (cookies >= farmCost) {
								cookies -= farmCost;
								farmCost = farmCost * 1.15;
								farmOwned += 1;
							}
						}
						if (shopMenu == 2) {
							if (cookies >= towerCost) {
								cookies -= towerCost;
								towerCost = towerCost * 1.15;
								towerOwned += 1;
							}
						}
					}
					if (mouseY < 132 && mouseY > 99) {
						if (shopMenu == 1) {
							if (cookies >= mineCost) {
								cookies -= mineCost;
								mineCost = mineCost * 1.15;
								mineOwned += 1;
							}
						}
						if (shopMenu == 2) {
							if (cookies >= shipmentCost) {
								cookies -= shipmentCost;
								shipmentCost = shipmentCost * 1.15;
								shipmentOwned += 1;
							}
						}
					}
					if (mouseY < 165 && mouseY > 132) {
						if (shopMenu == 1) {
							if (cookies >= factoryCost) {
								cookies -= factoryCost;
								factoryCost = factoryCost * 1.15;
								factoryOwned += 1;
							}
						}
						if (shopMenu == 2) {
							if (cookies >= alchemyCost) {
								cookies -= alchemyCost;
								alchemyCost = alchemyCost * 1.15;
								alchemyOwned += 1;
							}
						}
					}
				}
			}
			clicking = true;
		}
	} else {clicking = false;}
	if (shopMenu == 5) {
		shopMenu = 4;
	}
	if (shopMenu == 0) {
		shopMenu = 1;
	}
}


//renders graphics to screen
void renderWindow(void) {
	//background
	gfx_FillScreen(2);
	gfx_SetColor(4);
	for (i = 0; i < 16; i++) {
		gfx_FillRectangle((40 * i), 0, 20, 240);
	}
	
	//menu 1 = main game window
	if (menu == 1) {
		//big cookie
		if (clicking == false) {
			gfx_TransparentSprite(perfectCookie, 39, 74);
		}
		else {
			if ((mouseX < 139 && mouseX > 39) && (mouseY < 174 && mouseY > 74)) {
				gfx_TransparentSprite(perfectCookieClicked, 39, 74);
			}
			else {
				gfx_TransparentSprite(perfectCookie, 39, 74);
			}
		}
		
		//bakery name rendering
		gfx_SetColor(3);
		gfx_FillCircle(8, 8, 5);
		bakeryNameLength = gfx_GetStringWidth(playerName) + gfx_GetStringWidth("'s Bakery");
		gfx_FillCircle_NoClip(bakeryNameLength+5, 8, 5);
		gfx_FillRectangle_NoClip(8, 3, bakeryNameLength-5, 11);
		gfx_SetTextXY(5, 5);
		gfx_PrintString(playerName);
		gfx_PrintString("'s Bakery");
		
		//total cookies & cookies per second text
		gfx_SetTextXY(5, 23);
		gfx_SetTextFGColor(1);
		gfx_PrintString("Cookies:");
		gfx_SetTextXY(5, 32);
		gfx_PrintInt(round(cookies), 1);
		gfx_SetTextXY(5, 41);
		gfx_PrintString("Cookies per second:");
		gfx_SetTextXY(5, 50);
		gfx_PrintInt(round(mouseOwned*.1 + grandmaOwned*1), 1);
		
		//store menu switch buttons
		for (i = 0; i < 5; i++) {
			gfx_Sprite(shopSlot, 191, (35*i)+1);
		}
		gfx_Sprite(menuSwitchButton, 191, 176);
		gfx_Sprite(menuSwitchButton, 256, 176);
		gfx_SetTextFGColor(1);
		gfx_PrintStringXY("Back", 203, 188);
		gfx_PrintStringXY("Next", 268, 188);
		gfx_SetTextFGColor(6);
		if (shopMenu == 1) {
			gfx_PrintStringXY("Back", 203, 188);
		}
		if (shopMenu == 4) {
			gfx_PrintStringXY("Next", 268, 188);
		}
		
		//shop prices and icons
		gfx_SetTextFGColor(1);
		if (shopMenu == 1) {
			gfx_TransparentSprite(mouseShopIcon, 196, 6);
			gfx_TransparentSprite(grandmaShopIcon, 196, 41);
			gfx_TransparentSprite(farmShopIcon, 196, 76);
			gfx_TransparentSprite(mineShopIcon, 196, 111);
			gfx_TransparentSprite(factoryShopIcon, 196, 145);
			
			gfx_SetTextXY(219, 6);
			gfx_PrintString("x");
			gfx_PrintInt(mouseOwned, 1);
			gfx_SetTextXY(227, 21);
			gfx_PrintInt(round(mouseCost), 1);
			
			gfx_SetTextXY(219, 40);
			gfx_PrintString("x");
			gfx_PrintInt(grandmaOwned, 1);
			gfx_SetTextXY(227, 55);
			gfx_PrintInt(round(grandmaCost), 1);
			
			gfx_SetTextXY(219, 74);
			gfx_PrintString("x");
			gfx_PrintInt(farmOwned, 1);
			gfx_SetTextXY(227, 89);
			gfx_PrintInt(round(farmCost), 1);
			
			gfx_SetTextXY(219, 108);
			gfx_PrintString("x");
			gfx_PrintInt(mineOwned, 1);
			gfx_SetTextXY(227, 123);
			gfx_PrintInt(round(mineCost), 1);
			
			gfx_SetTextXY(219, 142);
			gfx_PrintString("x");
			gfx_PrintInt(factoryOwned, 1);
			gfx_SetTextXY(227, 157);
			gfx_PrintInt(round(factoryCost), 1);
		}
		if (shopMenu == 2) {
			gfx_TransparentSprite(bankShopIcon, 196, 6);
			gfx_TransparentSprite(templeShopIcon, 196, 41m);
			gfx_TransparentSprite(towerShopIcon, 196, 76);
			gfx_TransparentSprite(shipmentShopIcon, 196, 111);
			gfx_TransparentSprite(alchemyShopIcon, 196, 145);
			
			gfx_SetTextXY(219, 6);
			gfx_PrintString("x");
			gfx_PrintInt(mouseOwned, 1);
			gfx_SetTextXY(227, 21);
			gfx_PrintInt(round(mouseCost), 1);
			
			gfx_SetTextXY(219, 40);
			gfx_PrintString("x");
			gfx_PrintInt(grandmaOwned, 1);
			gfx_SetTextXY(227, 55);
			gfx_PrintInt(round(grandmaCost), 1);
			
			gfx_SetTextXY(219, 74);
			gfx_PrintString("x");
			gfx_PrintInt(farmOwned, 1);
			gfx_SetTextXY(227, 89);
			gfx_PrintInt(round(farmCost), 1);
			
			gfx_SetTextXY(219, 108);
			gfx_PrintString("x");
			gfx_PrintInt(mineOwned, 1);
			gfx_SetTextXY(227, 123);
			gfx_PrintInt(round(mineCost), 1);
			
			gfx_SetTextXY(219, 142);
			gfx_PrintString("x");
			gfx_PrintInt(factoryOwned, 1);
			gfx_SetTextXY(227, 157);
			gfx_PrintInt(round(factoryCost), 1);
		}
		
		//version #
		gfx_SetTextXY(5, 201);
		gfx_PrintString("V. B2.0");
		
		gfx_Sprite(panelVertical, 180, 0);
	}
	//function buttons
	gfx_Sprite(panelHorizontal, 0, 212);
	gfx_Sprite(panelHorizontal, 160, 212);
	for(i = 0; i < 5; i++) {
		gfx_TransparentSprite(functionButton, (i * 64) + 1, 224);
	}
	gfx_SetTextFGColor(1);
	gfx_SetTextXY(5, 230);
	gfx_PrintString("CONFIG");
	gfx_SetTextXY(68, 230);
	gfx_PrintString("UPGRADE");
	gfx_SetTextXY(132, 230);
	gfx_PrintString("INFO");
	gfx_SetTextXY(196, 230);
	gfx_PrintString("ASCEND");
	gfx_SetTextXY(260, 230);
	gfx_PrintString("STATS");

	gfx_TransparentSprite(mouse1, mouseX, mouseY);
	gfx_SwapDraw();
}


void timerStuff(void) {
	frames += 1;
	if (frames >= 20) {
		cookies += (mouseOwned*mouseMultiplier + grandmaOwned*grandmaMultiplier + farmOwned*farmMultiplier + mineOwned*mineMultiplier + factoryOwned*factoryMultiplier);
		frames = 0;
	}
}