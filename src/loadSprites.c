#include <compression.h>
#include <graphx.h>
#include "gfx/ccsprt.h"

gfx_sprite_t *mouse1;
gfx_sprite_t *perfectCookie;
gfx_sprite_t *perfectCookieClicked;
gfx_sprite_t *functionButton;
gfx_sprite_t *shopSlot;
gfx_sprite_t *menuSwitchButton;
gfx_sprite_t *panelHorizontal;
gfx_sprite_t *panelVertical;

gfx_sprite_t *mouseShopIcon;
gfx_sprite_t *grandmaShopIcon;
gfx_sprite_t *farmShopIcon;
gfx_sprite_t *mineShopIcon;
gfx_sprite_t *factoryShopIcon;

gfx_sprite_t *bankShopIcon;
gfx_sprite_t *templeShopIcon;
gfx_sprite_t *towerShopIcon;
gfx_sprite_t *shipmentShopIcon;
gfx_sprite_t *alchemyShopIcon;



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
	
	templeShopIcon = gfx_MallocSprite(templeShopIcon_width, templeShopIcon_height);
	zx0_Decompress(templeShopIcon, templeShopIcon_compressed);
	
	towerShopIcon = gfx_MallocSprite(towerShopIcon_width, towerShopIcon_height);
	zx0_Decompress(towerShopIcon, towerShopIcon_compressed);
	
	shipmentShopIcon = gfx_MallocSprite(shipmentShopIcon_width, shipmentShopIcon_height);
	zx0_Decompress(shipmentShopIcon, shipmentShopIcon_compressed);
	
	alchemyShopIcon = gfx_MallocSprite(bankShopIcon_width, bankShopIcon_height);
	zx0_Decompress(alchemyShopIcon, alchemyShopIcon_compressed);
	
	panelVertical = gfx_MallocSprite(panelVertical_width, panelVertical_height);
	zx0_Decompress(panelVertical, panelVertical_compressed);
	
	panelHorizontal = gfx_MallocSprite(panelHorizontal_width, panelHorizontal_height);
	zx0_Decompress(panelHorizontal, panelHorizontal_compressed);
}