#pragma once
// このヘッダは魔法の名前と消費MPの初期設定を行う

void FIRE() {

	sprintf_s(fire->NAME, "fire");
	fire->MP = 3;
}


void EXPLOSION() {

	sprintf_s(explosion->NAME, "explosion");
	explosion->MP = 8;
}

void CURE() {

	sprintf_s(cure->NAME, "cure");
	cure->MP = 5;
}

void ATKUP() {

	sprintf_s(POWup->NAME, "POWup");
	POWup->MP = 5;
}

void DEFUP() {

	sprintf_s(DEFup->NAME, "DEFup");
	DEFup->MP = 5;
}

void SLEEP() {

	sprintf_s(sleep->NAME, "sleep");
	sleep->MP = 8;
	sleep->POW = 50;
}

void PANDORA() {

	sprintf_s(pandora->NAME, "pandora");
}

// 各魔法の初期設定
void spellInit() {
	FIRE();
	EXPLOSION();
	CURE();
	ATKUP();
	DEFUP();
	SLEEP();
	PANDORA();
}