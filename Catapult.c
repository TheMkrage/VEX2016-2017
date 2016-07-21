void catapultManualControl() {
	motor[catapultTop] = vexRT[Ch3Xmtr2];
		motor[catapultBottom] = vexRT[Ch3Xmtr2];
		motor[catapultMiddle] = vexRT[Ch3Xmtr2];
}


task catapultAuto()
{
	while (true) {
		// Catapult
		motor[catapultTop] = vexRT[Ch3Xmtr2];
		motor[catapultBottom] = vexRT[Ch3Xmtr2];
		motor[catapultMiddle] = vexRT[Ch3Xmtr2];
	}
}

task catapultTeleop()
{
	while (true) {
		catapultManualControl();
	}
}
