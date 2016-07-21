#include "LCD.h" // Header File, import this anywhere you wish to use LCD functions
#pragma systemFile // Remove unreferenced function warnings

// --- Init LCD Screen ---
void LCDInit() {
	LCD.count = 0;
	LCD.line0 = "";
	LCD.line1 = "";
	LCD.autoPosition = 0;
	for (int i = 0; i < MAX_AUTO_COMMANDS; i++ ) {
		LCD.auto[i] = "None";
	}
}

// --- LCD Button Functions ---
bool LCDIsLeftButtonPressed() {
	if (nLCDButtons == 4) {
		return true;
	}
	return false;
}

bool LCDIsRightButtonPressed() {
	if (nLCDButtons == 1) {
		return true;
	}
	return false;
}

bool LCDIsCenterButtonPressed() {
	if (nLCDButtons == 2) {
		return true;
	}
	return false;
}

// --- Clearing Functions ---
// Clears the top line
void LCDClear0() {
	clearLCDLine(0);
	LCD.line0 = "";
}

// Clears the bottom line
void LCDClear1() {
	clearLCDLine(1);
	LCD.line1 = "";
}

// Clears line in param
void LCDClear(int line) {
	if (line == 0) {
		LCDClear0();
	}else if (line == 1) {
		LCDClear1();
	}
}

// Clears both lines
void LCDClear() {
	LCDClear0();
	LCDClear1();
}

// --- Setting Functions ---
// Set 1st param to top line and 2nd param to bottom line
void LCDSetLine01(char* newLine0, char* newLine1) {
	LCD.line0 = newLine0;
	LCD.line1 = newLine1;
	displayLCDCenteredString(0, newLine0);
	displayLCDCenteredString(1, newLine1);
}

// Set 1st param to bottom line and 2nd param to top line
void LCDSetLine10(char*  newLine1, char*  newLine0) {
	LCD.line0 = newLine0;
	LCD.line1 = newLine1;
	displayLCDCenteredString(0, newLine0);
	displayLCDCenteredString(1, newLine1);
}

// Set top line
void LCDSetLine0(char*  newLine0) {
	LCD.line0 = newLine0;
	displayLCDCenteredString(0, newLine0);
}

// Set bottom line
void LCDSetLine1(char*  newLine1) {
	LCD.line1 = newLine1;
	displayLCDCenteredString(1, newLine1);
}

// --- Waiting Functions ---
// Will pause whatever task until any button/buttons is/are pressed
void LCDWaitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(25);
}

// Will pause whatever task until no buttons are being pressed
void LCDWaitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(25);
}

// --- Animation Functions --
// The old texts goes off the top and the new text comes in from the bottom
void LCDAnimateFromBottom(char* newLine0, char* newLine1) {
	LCDSetLine01(LCD.line1, " ");
	wait1Msec(250);
	LCDSetLine01(" ", newLine0);
	wait1Msec(250);
	LCDSetLine01(newLine0, newLine1);
}

// The old texts goes off the buttom and the new text comes in from the top
void LCDAnimateFromTop(char* newLine0, char* newLine1) {
	LCDSetLine01(" ", LCD.line0);
	wait1Msec(250);
	LCDSetLine01(newLine1, " ");
	wait1Msec(250);
	LCDSetLine01(newLine0, newLine1);
}

// --- Auto Functions ---
// Use to add text to auto
void LCDAddAuto( char* autoText ) {
	LCD.auto[LCD.autoPosition] = autoText;
	LCD.autoPosition++;
}
