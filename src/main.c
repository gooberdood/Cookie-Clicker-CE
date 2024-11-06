//libraries n stuff
#include <ti/getcsc.h>
#include <sys/util.h>
#include <compression.h>
#include <graphx.h>
#include <keypadc.h>
#include <time.h>
#include <math.h>
#include "gfx/ccsprt.h"
#include "loadSprites.h"
#include "functions.h"

//frame limit
#define TARGET_FRAMERATE 20
#define TARGET_FRAME_TIME (CLOCKS_PER_SEC / TARGET_FRAMERATE)

//main stuffz
int main(void) {
	
	if (ccsprt_init() == 0) {return 1;}
	initGfx(); //setup / initialization
	decompressSprites(); //decompressing spritezzz
	
	//main loop
	do {
		clock_t frame_start = clock(); //starts frame timer
		
		getInput(); //calls getInput function to, well, get input, and do stuff with said input
		timerStuff(); //does animation related math (particle gravity etc)
		renderWindow(); //graphics rendering :3
		
		//waits until ~1/60th of a second to render frame
		clock_t frame_time = clock() - frame_start;
		do {frame_time = clock() - frame_start;} while (frame_time < TARGET_FRAME_TIME);
		
	} while(inGame == true);
	
	//ends gfx process and frees memory of pesky lil sprites
    gfx_End();
	free(mouse1);
	free(perfectCookie);
	free(perfectCookieClicked);
	free(functionButton);
	free(shopSlot);
	free(menuSwitchButton);
	free(mouseShopIcon);
	free(grandmaShopIcon);
	free(farmShopIcon);
	free(mineShopIcon);
	free(factoryShopIcon);
	free(bankShopIcon);
	free(templeShopIcon);
	free(towerShopIcon);
	free(shipmentShopIcon);
	free(alchemyShopIcon);
	free(panelHorizontal);
    return 0;
}