#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Motor,  port1,           driveFrontLeft, tmotorVex393TurboSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           driveFrontRight, tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           driveBackLeft, tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           driveBackRight, tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           climberA,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           climberB,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           catapultA,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           catapultB,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           catapultC,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Drive.c"
#include "Catapult.c"
#include "Arm.c"

#include "LCDTask.c"
#pragma systemFile

// Necessary File For Vex Competition
#include "Vex_Competition_Includes.c"

void pre_auton()
{

}

task autonomous()
{
	writeDebugStreamLine("Starting Auto");
	startTask(driveAuto);
	startTask(catapultAuto);
	startTask(armAuto);
	while(true)
	{

	}
}

task usercontrol()
{
	startTask(runLCD);
	writeDebugStreamLine("Starting Teleop");
	startTask(driveTeleop);
	startTask(catapultTeleop);
	startTask(armTeleop);
	while (true)
	{

	}
}
