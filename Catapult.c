void catapultManualControl() {
	motor[catapultA] = vexRT[Ch3Xmtr2];
		motor[catapultB] = vexRT[Ch3Xmtr2];
		motor[catapultC] = vexRT[Ch3Xmtr2];
}

task catapultAuto()
{
	while (true) {
		// Catapult
		motor[catapultA] = vexRT[Ch3Xmtr2];
		motor[catapultB] = vexRT[Ch3Xmtr2];
		motor[catapultC] = vexRT[Ch3Xmtr2];
	}
}

task catapultTeleop()
{
	while (true) {
		catapultManualControl();
	}
}
