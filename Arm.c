
void armManual() {
	motor[climberA] = vexRT[Ch2Xmtr2];
	motor[climberB] = vexRT[Ch2Xmtr2];
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
