#pragma once
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

// 呪文:fireの設定
void FIRE() {

	sprintf_s(fire->NAME, "fire");
	fire->MP = 3;
}

// 呪文:explosionの設定
void EXPLOSION() {

	sprintf_s(explosion->NAME, "explosion");
	explosion->MP = 8;
}

// 呪文:cureの設定
void CURE() {

	sprintf_s(cure->NAME, "cure");
	cure->MP = 5;
}

// 呪文:ATKupの設定
void ATKUP() {

	sprintf_s(POWup->NAME, "POWup");
	POWup->MP = 5;
}

// 呪文:DEFupの設定
void DEFUP() {

	sprintf_s(DEFup->NAME, "DEFup");
	DEFup->MP = 5;
}

// 呪文:sleepの設定
void SLEEP() {

	sprintf_s(sleep->NAME, "sleep");
	sleep->MP = 8;
	sleep->POW = 50;
}

// 呪文:pandoraの設定
void PANDORA() {

	sprintf_s(pandora->NAME, "pandora");
}

// プレイヤーの残りMP判定
void playerPlaySpell(player* player, spell* spell) {
	if (player->MP < spell->MP) {
		player->playSpell = 1; // 唱えられない
		mvaddstr(xa, ya, "しかしMPが足りなかった！");
		xa = xa + 2;
	}
	else if (player->MP >= spell->MP) {
		player->playSpell = 0; // 唱えられる
	}
}

// 敵の残りMP判定
void enemyPlaySpell(enemy* enemy, spell* spell) {
	if (enemy->MP < spell->MP) {
		enemy->playSpell = 1;
		mvaddstr(xa, ya, "しかしMPが足りなかった！");
		xa = xa + 2;
	}
	else if (enemy->MP >= spell->MP) {
		enemy->playSpell = 0;
	}
}
