#include <keypadc.h>
#include <compression.h>
#include <graphx.h>
#include <math.h>
#include "gfx/ccsprt.h"
#include "functions.h"

int mouseX = 160;
int mouseY = 120;
int menu = 1;
int inGame = true;
int i;
int shopMenu = 1;
int frames = 0;
unsigned int cookies = 0;
unsigned int cookiesPerClick = 1;
int clicking = false;
char playerName[] = "Player";
int bakeryNameLength;

gfx_sprite_t *mouse1;
gfx_sprite_t *perfectCookie;
gfx_sprite_t *perfectCookieClicked;
gfx_sprite_t *functionButton;
gfx_sprite_t *shopSlot;
gfx_sprite_t *menuSwitchButton;
gfx_sprite_t *mouseShopIcon;
gfx_sprite_t *grandmaShopIcon;
gfx_sprite_t *farmShopIcon;
gfx_sprite_t *mineShopIcon;
gfx_sprite_t *factoryShopIcon;
gfx_sprite_t *bankShopIcon;

unsigned int mouseCost = 15;
int mouseOwned = 0;
unsigned int grandmaCost = 100;
int grandmaOwned = 0;


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


//decompresses sprites
void decompressSprites(void) {
	mouse1 = gfx_MallocSprite(mouse1_width, mouse1_height);
	zx0_Decompress(mouse1, mouse1_compressed);
	
	perfectCookie = gfx_MallocSprite(perfectCookie_width, perfectCookie_height);
	zx0_Decompress(perfectCookie, perfectCookie_compressed);
	
	perfectCookieClicked = gfx_MallocSprite(perfectCookieClicked_width, perfectCookieClicked_height);
	zx0_Decompress(perfectCookieClicked, perfectCookieClicked_compressed);
	
	functionButton = gfx_MallocSprite(functionButton_width, functionButton_height);
	zx0_Decompress(functionButton, functionButton_compressed);
	
	shopSlot = gfx_MallocSprite(shopSlot_width, shopSlot_height);
	zx0_Decompress(shopSlot, shopSlot_compressed);
	
	menuSwitchButton = gfx_MallocSprite(menuSwitchButton_width, menuSwitchButton_height);
	zx0_Decompress(menuSwitchButton, menuSwitchButton_compressed);
	
	mouseShopIcon = gfx_MallocSprite(mouseShopIcon_width, mouseShopIcon_height);
	zx0_Decompress(mouseShopIcon, mouseShopIcon_compressed);
	
	grandmaShopIcon = gfx_MallocSprite(grandmaShopIcon_width, grandmaShopIcon_height);
	zx0_Decompress(grandmaShopIcon, grandmaShopIcon_compressed);
	
	farmShopIcon = gfx_MallocSprite(farmShopIcon_width, farmShopIcon_height);
	zx0_Decompress(farmShopIcon, farmShopIcon_compressed);
	
	mineShopIcon = gfx_MallocSprite(mineShopIcon_width, mineShopIcon_height);
	zx0_Decompress(mineShopIcon, mineShopIcon_compressed);
	
	factoryShopIcon = gfx_MallocSprite(factoryShopIcon_width, factoryShopIcon_height);
	zx0_Decompress(factoryShopIcon, factoryShopIcon_compressed);
	
	bankShopIcon = gfx_MallocSprite(bankShopIcon_width, bankShopIcon_height);
	zx0_Decompress(bankShopIcon, bankShopIcon_compressed);
}


void getInput(void) {
	//scans the keypad, then checks inputs
	kb_Scan();
	if (kb_Data[6] & kb_Clear) {inGame = false;}
	if (kb_Data[7] & kb_Down) {mouseY += 4;}
	if (kb_Data[7] & kb_Up) {mouseY -= 4;}
	if (kb_Data[7] & kb_Left) {mouseX -= 4;}
	if (kb_Data[7] & kb_Right) {mouseX += 4;}
	
	if ((kb_Data[1] & kb_2nd) or (kb_Data[6] & kb_Enter)) {
		if (clicking == false) {
			if (menu == 1) {
				if ((mouseX < 104 && mouseX > 9) && (mouseY < 169 && mouseY > 74)) {
					cookies += cookiesPerClick;
				}
				if ((mouseX < 244 && mouseX > 191) && (mouseY < 203 && mouseY > 171)) {
					if (shopMenu > 1) {
						shopMenu = shopMenu - 1;
					}
				}
				if (mouseX < 320 && mouseX > 191) { //sees if cursor is by the shop boxes
					if (mouseY < 33 && mouseY > 1) {
						if (shopMenu == 1) {
							if (cookies >= mouseCost) {
								cookies -= mouseCost;
								mouseCost = ceil(mouseCost * 1.15);
								mouseOwned += 1;
							}
						}
					}
					if (mouseY < 66 && mouseY > 33) {
						if (shopMenu == 1) {
							if (cookies >= grandmaCost) {
								cookies -= grandmaCost;
								grandmaCost = ceil(grandmaCost * 1.15);
								grandmaOwned += 1;
							}
						}
					}
				}
			}
			clicking = true;
		}
	} else {clicking = false;}
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
			gfx_TransparentSprite(perfectCookie, 9, 74);
		}
		else {
			if ((mouseX < 104 && mouseX > 9) && (mouseY < 169 && mouseY > 74)) {
				gfx_TransparentSprite(perfectCookieClicked, 9, 74);
			}
			else {
				gfx_TransparentSprite(perfectCookie, 9, 74);
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
		gfx_PrintUInt(cookies, 1);
		gfx_SetTextXY(5, 41);
		gfx_PrintString("Cookies per second:");
		gfx_SetTextXY(5, 50);
		gfx_PrintInt(round(mouseOwned*.1 + grandmaOwned*1), 1);
		
		//shop stuff
		for (i = 0; i < 5; i++) {
			gfx_Sprite(shopSlot, 191, (34*i)+1);
		}
		
		//store menu switch buttons
		gfx_Sprite(menuSwitchButton, 191, 171);
		gfx_Sprite(menuSwitchButton, 256, 171);
		gfx_SetTextFGColor(1);
		gfx_PrintStringXY("Back", 203, 183);
		gfx_PrintStringXY("Next", 268, 183);
		gfx_SetTextFGColor(6);
		if (shopMenu == 1) {
			gfx_PrintStringXY("Back", 203, 183);
		}
		if (shopMenu == 4) {
			gfx_PrintStringXY("Next", 268, 183);
		}
		
		//shop prices and icons
		gfx_SetTextFGColor(1);
		if (shopMenu == 1) {
			gfx_TransparentSprite(mouseShopIcon, 196, 6);
			gfx_TransparentSprite(grandmaShopIcon, 196, 40);
			gfx_TransparentSprite(farmShopIcon, 196, 74);
			gfx_TransparentSprite(mineShopIcon, 196, 108);
			gfx_TransparentSprite(factoryShopIcon, 196, 142);
			gfx_SetTextXY(227, 21);
			gfx_PrintInt(mouseCost, 1);
			gfx_SetTextXY(227, 54);
			gfx_PrintInt(grandmaCost, 1);
		}
		
		//version #
		gfx_SetTextXY(5, 211);
		gfx_PrintString("V. B1.0");
		
		//function buttons
		for(i = 0; i < 5; i++) {
			gfx_TransparentSprite(functionButton, (i * 64) + 1, 224);
		}
		gfx_SetTextFGColor(1);
	}
	gfx_TransparentSprite(mouse1, mouseX, mouseY);
	gfx_SwapDraw();
}


void timerStuff(void) {
	frames += 1;
	if (frames >= 30) {
		cookies += (round(mouseOwned*.1 + grandmaOwned*1));
		frames = 0;
	}
}