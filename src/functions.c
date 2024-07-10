#include <keypadc.h>
#include <compression.h>
#include <graphx.h>
#include "gfx/ccsprt.h"
#include "functions.h"

int mouseX = 160;
int mouseY = 120;
int menu = 1;
int inGame = true;
int i;
int clickTextObjs[30] = {0, 240, -50, 0, 240, -50, 0, 240, -50, 0, 240, -50, 0, 240, -50, 0, 240, -50, 0, 240, -50, 0, 240, -50, 0, 240, -50, 0, 240, -50}; //x, y, x, y...
const int clickTextStartVelocity = 10;
unsigned int cookies = 0;
unsigned int cookiesPerClick = 1;
int clicking = false;
char playerName[] = "Player";
int bakeryNameLength;
gfx_sprite_t *mouse1;
gfx_sprite_t *perfectCookie;
gfx_sprite_t *perfectCookieClicked;
gfx_sprite_t *functionButton;


//initialize gfx / set up
void initGfx(void) {
    gfx_Begin();
	gfx_SetDrawBuffer();
	//sets palette and transparent color
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
	gfx_SetTransparentColor(0);
	gfx_SetTextTransparentColor(0);
	gfx_SetTextBGColor(0);
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
}


void getInput(void) {
	//scans the keypad, then checks inputs
	kb_Scan();
	if (kb_Data[6] & kb_Clear) {inGame = false;}
	if (kb_Data[7] & kb_Down) {mouseY += 3;}
	if (kb_Data[7] & kb_Up) {mouseY -= 3;}
	if (kb_Data[7] & kb_Left) {mouseX -= 3;}
	if (kb_Data[7] & kb_Right) {mouseX += 3;}
	
	if (kb_Data[1] & kb_2nd) {
		if (clicking == false) {
			if (menu == 1) {
				if ((mouseX < 104 && mouseX > 9) && (mouseY < 169 && mouseY > 74)) {
					cookies += cookiesPerClick;
					//click text particle
					for (i = 0; i < 1; i++) {
						if (clickTextObjs[(i*3)+1] == 240) {
							clickTextObjs[i*3] = mouseX;
							clickTextObjs[(i*3)+1] = mouseY;
							clickTextObjs[(i*3)+2] = clickTextStartVelocity;
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
		
		//version #
		gfx_SetTextXY(5, 211);
		gfx_PrintString("V. 1.0");
		
		//function buttons
		for(i = 0; i < 5; i++) {
			gfx_TransparentSprite(functionButton, (i * 64) + 1, 224);
		}
		//click text particle
		gfx_SetTextFGColor(5);
		for (i = 0; i < 10; i++) {
			gfx_SetTextXY(clickTextObjs[i*3], clickTextObjs[(i*3)+1]);
			gfx_PrintString("+");
			gfx_PrintUInt(cookiesPerClick, 1);
		}
		gfx_SetTextFGColor(1);
	}
	gfx_TransparentSprite(mouse1, mouseX, mouseY);
	gfx_SwapDraw();
}


void animationTiming(void) {
	//click text particle
	for (i = 0; i < 10; i++) {
		if (clickTextObjs[(i*3)+1] <= 180) {
			clickTextObjs[(i*3)+1] -= clickTextObjs[(i*3)+2];
			if (clickTextObjs[(i*3)+2] > -50) {
				clickTextObjs[(i*3)+2] -= 1;
			}
		}
		if (clickTextObjs[(i*3)+1] > 180) {
			clickTextObjs[i*3] = 0;
			clickTextObjs[(i*3)+1] = 240;
			clickTextObjs[(i*3)+2] = -50;
		}
	}
}