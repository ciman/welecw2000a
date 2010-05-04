/*
 * Gui.h
 *
 *  Created on: 19.02.2010
 *      Author: Robert
 */

#ifndef GUI_H_
#define GUI_H_

#include <stdio.h>
#include <stdlib.h>

#include "DSO_Font.h"
#include "DSO_Screen.h"
#include "DSO_SFR.h"
#include "DSO_FrontPanel.h"

#define MENU_START_X	0
#define MENU_WIDTH		(HLEN)

#define MENU_HEIGHT		(58)
#define MENU_START_Y	(VLEN-MENU_HEIGHT)

#define MENU_LINE_WIDTH		3
#define SUB_MENU_WIDTH

/*
 * Horizontal starting position for a submenu
 */
#define MENU_START_MEN_F1	0
#define MENU_START_MEN_F2	106
#define MENU_START_MEN_F3	213
#define MENU_START_MEN_F4	320
#define MENU_START_MEN_F5	426
#define MENU_START_MEN_F6	533

/*
 * Default bounds for a submenu
 */
#define DEFAULT_BOUNDS_F1	{MENU_START_MEN_F1, MENU_START_Y, 103, MENU_HEIGHT}
#define DEFAULT_BOUNDS_F2	{MENU_START_MEN_F2, MENU_START_Y, 103, MENU_HEIGHT}
#define DEFAULT_BOUNDS_F3	{MENU_START_MEN_F3, MENU_START_Y, 103, MENU_HEIGHT}
#define DEFAULT_BOUNDS_F4	{MENU_START_MEN_F4, MENU_START_Y, 103, MENU_HEIGHT}
#define DEFAULT_BOUNDS_F5	{MENU_START_MEN_F5, MENU_START_Y, 103, MENU_HEIGHT}
#define DEFAULT_BOUNDS_F6	{MENU_START_MEN_F6, MENU_START_Y, 103, MENU_HEIGHT}

#define MENU_COLOR_BG	COLOR_R3G3B3(3,3,3)
#define MENU_COLOR_FG	COLOR_R3G3B3(0,0,0)
#define BG_COLOR 		COLOR_R3G3B3(0,0,0)


#define TITLE_BAR_START_X			0
#define TITLE_BAR_END_X				(HLEN)
#define TITLE_BAR_START_Y			0
#define TITLE_BAR_END_Y				18

#define TITLE_BAR_COLOR_BG		COLOR_R3G3B3(3,3,3)
#define TITLE_BAR_COLOR_FG		COLOR_R3G3B3(0,0,0)

/* Grid defines */
#define GRIDCOLOR COLOR_R3G3B3(3,3,3)

extern uint32_t gridbuffer[VLEN][HLEN/32];

#define GRID_RECT_START_Y	(TITLE_BAR_END_Y+2)
#define GRID_RECT_START_X	(20)
#define GRID_RECT_END_Y		(MENU_START_Y-2)
#define GRID_RECT_END_X		(HLEN-20)

/*
 * Horizontal Positions for items in the titlemenu
 */
enum TITLEMENU
{
	VOLTAGE_CH0 = 80,
	VOLTAGE_CH1 = 200,
	VOLTAGE_CH2 = 320,
	VOLTAGE_CH3 = 440,
	TIMEBASE = 550,
	TRIGGERLEVEL = 150
};

#define SML_TITLE_HEIGHT	25
#define SML_ENTRY_HEIGHT	30
#define	SML_HEIGHT(y)		(SML_TITLE_HEIGHT + (y*SML_ENTRY_HEIGHT))
#define SML_START_POS_Y(x)	(VLEN - MENU_HEIGHT - (SML_HEIGHT((x))))

typedef struct SubMenuList
{
	char *title;
	sRect bounds;

	sRect popup;
	uint32_t size;
	uint32_t selectedIndex;

	void (*smlFunct)(uint32_t selection);
	char *entrys[];
}
sSubMenuList;


typedef struct CheckBox
{
	char *title;
	sRect bounds;

	uint32_t selected;
	void (*cbFunct)(uint32_t selection);
}
sCheckBox;

typedef struct ValueField
{
	char *title;
	sRect bounds;

	int32_t value;
	int32_t maxValue;
	int32_t minValue;

	void (*vfFunct)(uint32_t value);
}
sValueField;

/*
 * Enum to identify a submenu.
 */
enum MENU_TYPE
{
	SUBMENU_LIST,
	CHECKBOX,
	VALUE_FIELD
};

/*
 * Wrapper for all submenu items.
 * So it is possible to add any submenu item to a submenu.
 */
typedef struct SubMenu
{
	enum MENU_TYPE type;
	void *menuItem;
}
sSubMenu;


/*
 * A submenu contains 6 submenu items and a functions wich will be called
 * when a menu gets activated.
 */
typedef struct Menu
{
	sSubMenu *subMenu[6];
	void (*enter_funct)(void);
}
sMenu;

extern sMenu *activeMenu;

void updateMenu(sMenu *menu);

void titleBarInit(void);

void updateTitleBar(enum TITLEMENU type, const char *text);

void onSubMenu(sSubMenu *subMenu);

void actionhandler(void);

void closeSubMenuTime(void);

void vfValueChanged(int32_t diff);



#endif /* GUI_H_ */