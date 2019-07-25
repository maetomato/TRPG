#pragma once
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

// ����:fire�̐ݒ�
void FIRE() {

	sprintf_s(fire->NAME, "fire");
	fire->MP = 3;
}

// ����:explosion�̐ݒ�
void EXPLOSION() {

	sprintf_s(explosion->NAME, "explosion");
	explosion->MP = 8;
}

// ����:cure�̐ݒ�
void CURE() {

	sprintf_s(cure->NAME, "cure");
	cure->MP = 5;
}

// ����:ATKup�̐ݒ�
void ATKUP() {

	sprintf_s(POWup->NAME, "POWup");
	POWup->MP = 5;
}

// ����:DEFup�̐ݒ�
void DEFUP() {

	sprintf_s(DEFup->NAME, "DEFup");
	DEFup->MP = 5;
}

// ����:sleep�̐ݒ�
void SLEEP() {

	sprintf_s(sleep->NAME, "sleep");
	sleep->MP = 8;
	sleep->POW = 50;
}

// ����:pandora�̐ݒ�
void PANDORA() {

	sprintf_s(pandora->NAME, "pandora");
}

// �v���C���[�̎c��MP����
void playerPlaySpell(player* player, spell* spell) {
	if (player->MP < spell->MP) {
		player->playSpell = 1; // �������Ȃ�
		mvaddstr(xa, ya, "������MP������Ȃ������I");
		xa = xa + 2;
	}
	else if (player->MP >= spell->MP) {
		player->playSpell = 0; // ��������
	}
}

// �G�̎c��MP����
void enemyPlaySpell(enemy* enemy, spell* spell) {
	if (enemy->MP < spell->MP) {
		enemy->playSpell = 1;
		mvaddstr(xa, ya, "������MP������Ȃ������I");
		xa = xa + 2;
	}
	else if (enemy->MP >= spell->MP) {
		enemy->playSpell = 0;
	}
}
