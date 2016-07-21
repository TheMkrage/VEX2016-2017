
void armManual() {
	motor[armTopMiddle] = vexRT[Ch2Xmtr2];
	motor[armBottom] = vexRT[Ch2Xmtr2];
}

task armAuto()
{
	while(true) {

	}
}

task armTeleop()
{
	while(true) {
		armManual();
	}
}
