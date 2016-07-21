#include "LCD.c"
#define ARRAYSIZE(a) (sizeof(a)/sizeof(a[0]))

typedef enum {
	MainMenu = 0,
	StartingPositionMenu = 1,
	AutoSelector = 2,
	MakeYourOwnAutoPosition = 3,
	MakeYourOwnAutoShootingLocation = 4,
} LCDMenuType;
string textForMenu[] = {"Select Auto","EarLobe"};
string textForStartingPositionMenu[] = {"Red Inside", "Blue Inside", "Red Outside", "Blue Outside"};
string textForAutoSelector[] = {"The Norm", "Defense", "Do Nothing", "Make Your Own"};
string textForMakeYourOwnAutoPosition[] = {"R1", "R2", "R3", "M1", "M2", "B1", "B2", "B3", "Done"};
string textForMakeYourOwnAutoShooting[] = {"Default", "Center", "Goal"};
bool goLeftNextTime = false;
void findCorrectMenu(LCDMenuType type) {
	string array[20];
	switch(type) {
	case MainMenu:
		array = textForMenu;
		break;
	case AutoSelector:
		array = textForAutoSelector;
		break;
	case MakeYourOwnAutoPosition:
		array = textForMakeYourOwnAutoPosition;
		break;
	case MakeYourOwnAutoShootingLocation:
		array = textForMakeYourOwnAutoShooting;
		break;
	case StartingPositionMenu:
		array = textForStartingPositionMenu;
		break;
	default:
		break;
	}
	if (goLeftNextTime) {
		LCDAnimateFromTop(array[LCD.count], "/\   Enter   \/" );
	}else {
		LCDAnimateFromBottom(array[LCD.count], "/\   Enter   \/" );
	}
	LCDWaitForPress();
	if ( LCDIsLeftButtonPressed() ) {
		writeDebugStreamLine("LeFT");
		goLeftNextTime = true;
		LCDWaitForRelease();
		if ( LCD.count == 0 ) {
			// Find the loop around if left at 0
			for(int i = 0; i < ARRAYSIZE(array); i++ ) {
				if (array[i] == "") {

				}else {
					LCD.count = i;
				}
			}
		}else {
			LCD.count--;
		}
	}else if ( LCDIsRightButtonPressed() ) {
		goLeftNextTime = false;
		LCDWaitForRelease();
		if ( LCD.count == ARRAYSIZE(array) ) {
				LCD.count = 0;
		}else if ( array[LCD.count + 1] == "" ) {
				LCD.count = 0;
				writeDebugStreamLine("TEXT");
		}else {
			LCD.count++;
		}
	}
}



void LCDRunMakeYourOwnAutoMenu() {
	bool running = true;
	while ( running ) {
		LCDAnimateFromBottom("Choose A Position", "<     Enter    >" );
		while( !LCDIsCenterButtonPressed() )	{
				findCorrectMenu(MakeYourOwnAutoPosition);
		}
		LCDWaitForRelease();
		if ( strcmp( LCD.line0, "Done" ) ) {
			running = false;
		}else {
			LCDAnimateFromBottom( "Where to shoot from?", "<     Enter    >"  );
			LCDAddAuto( LCD.line0 );
			while( !LCDIsCenterButtonPressed() )	{
				findCorrectMenu(MakeYourOwnAutoShootingLocation);
			}
			LCDWaitForRelease();
			if ( strcmp(LCD.line0, "Done") ) {
				running = false;
			}	else {
				LCDAddAuto( LCD.line0 );
			}
		}
	}
	LCDAnimateFromBottom( "I HOPE AUTO MAKES IT!", "GOOD LUCK!");
}

void LCDRunAutoSelector() {
	while( !LCDIsCenterButtonPressed() )	{
			findCorrectMenu(StartingPositionMenu);
	}

	LCDWaitForRelease();
	while( !LCDIsCenterButtonPressed() )	{
			findCorrectMenu(AutoSelector);
	}
	LCDWaitForRelease();
	// Respond to selection (use strcmp instead of count because order may change later in season)
	if ( strcmp(LCD.line0, "The Norm") ) {
		LCDAddAuto( "M1" );
		LCDAddAuto( "R1" );
		LCDAddAuto( "B1" );
	}else if ( strcmp(LCD.line0, "Defense") ) {
		LCDAddAuto( "Defense" );
	}else if ( strcmp(LCD.line0, "Make Your Own") ) {
		LCDRunMakeYourOwnAutoMenu();
	}
}

void LCDRunMainMenu() {
	while( !LCDIsCenterButtonPressed() )	{
		findCorrectMenu(MainMenu);
	}
	LCDWaitForRelease();
	// Respond to selection (use strcmp instead of count because order may change later in season)
	if ( strcmp(LCD.line0, "Select Auto") ) {
		LCDRunAutoSelector();
	}else {
		LCDRunAutoSelector();
	}
}

void 	LCDRunIntroScreen() {
	LCDAnimateFromBottom("WELCOME!", "TEAM 3309");
	wait1Msec(250);
	LCDAnimateFromBottom("MAIN MENU" , ":)");
	wait1Msec(250);
}

task runLCD(){
	LCDRunIntroScreen();
	LCDRunMainMenu();
}
