void driveManual() {
	int throttle = vexRT[Ch3];
	int turn = vexRT[Ch1];
	int strafe = vexRT[Ch4];
	motor[driveFrontLeft] = throttle + turn + strafe;
	motor[driveFrontRight] = throttle - turn - strafe;
	motor[driveBackRight] = throttle - turn + strafe;
	motor[driveBackLeft] = throttle + turn - strafe;
}

void gyroDrive() {

}

void waitForDrive() {

}

task driveAuto()
{

}

task driveTeleop()
{
	while(true)
	{
		driveManual();
	}
}
