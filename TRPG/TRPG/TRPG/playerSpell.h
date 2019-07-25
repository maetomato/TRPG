#pragma once
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "struct.h"

// ����:�ʏ�U��
void playerATK(player* player, enemy* enemy) { //�v���C���[�̒ʏ�U��
	mvprintw(xa, ya, " %s(%s) �� %s �ɍU�������I", player->NAME, player->JOB, enemy->NAME);
	xa = xa + 2;
	plusDamage = rand() % 10 - 5;
	if ((player->POW + plusDamage - enemy->DEF) <= 0) {
		enemy->HP = enemy->HP;
		mvprintw(xa, ya, " %s �Ƀ_���[�W��^�����Ȃ������I", enemy->NAME);
		xa = xa + 2;
	}
	else {
		enemy->HP = enemy->HP - (player->POW + plusDamage - enemy->DEF);
		mvprintw(xa, ya, " %s �� %d �̃_���[�W�I", enemy->NAME, (player->POW + plusDamage - enemy->DEF));
		xa = xa + 2;
	}

}

// ����:�Ή�����
void playerFire(player * player, enemy * enemy) { //�v���C���[�̉Ή������U��
	mvprintw(xa, ya, " %s(%s) �� %s ���������I", player->NAME, player->JOB, fire->NAME);
	xa = xa + 2;
	fire->POW = rand() % 20 + 20;
	playerPlaySpell(player, fire); // MP����
	plusDamage = rand() % 10 - 5;
	if (player->playSpell == 0) {
		player->MP = player->MP - fire->MP;
		enemy->HP = enemy->HP - (fire->POW + plusDamage);
		mvprintw(xa, ya, " %s �� %d �̃_���[�W�I", enemy->NAME, fire->POW + plusDamage);
		xa = xa + 2;
	}
}

// ����:�񕜎���
void playerCure(player * playerA, player * playerB) { //�v���C���[�̉񕜎����A�Ώۂ�I��
	mvprintw(xa, ya, " %s(%s) �� %s ���������I", playerA->NAME, playerA->JOB, cure->NAME);
	xa = xa + 2;
	cure->POW = rand() % 20 + 20;
	plusDamage = rand() % 10 - 5;
	playerPlaySpell(playerA, cure);
	if (playerB->dead != 1 && playerA->playSpell == 0) {
		playerA->MP = playerA->MP - cure->MP;
		playerB->HP += (cure->POW + plusDamage);
		if (playerB->HP > playerB->iniPandoraHP) {
			cure->POW = playerB->HP - playerB->iniPandoraHP;
			playerB->HP = playerB->iniPandoraHP;

		}
		mvprintw(xa, ya, " %s(%s) ��HP�� %d �񕜂����I", playerB->NAME, playerB->JOB, cure->POW + plusDamage);
		xa = xa + 2;
	}
	else if (playerA->playSpell == 0) {
		mvprintw(xa, ya, " %s �͎���ł���I", playerB->NAME);
		xa = xa + 2;
	}
}

// ����:�U����up����
void playerPOWup(player * playerA, player * playerB) { //�v���C���[�̍U���͏㏸�����A�Ώۂ�I��
	mvprintw(xa, ya, " %s(%s) �� %s ���������I", playerA->NAME, playerA->JOB, POWup->NAME);
	xa = xa + 2;
	POWup->POW = rand() % 20 + 20;
	plusDamage = rand() % 10 - 5;
	playerPlaySpell(playerA, POWup);
	if (playerA->playSpell == 0) {
		playerA->MP = playerA->MP - POWup->MP;
		int iniPOW = playerB->POW;
		playerB->POW += (POWup->POW + plusDamage);
		double magni = round(((double)playerB->POW / (double)iniPOW) * 10) / 10;
		mvprintw(xa, ya, " %s(%s) �̍U���͂� %.2f�{ �ɂȂ����I", playerB->NAME, playerB->JOB, magni);
		xa = xa + 2;
	}
}

// ����:�h���up����
void playerDEFup(player * playerA, player * playerB) { //�v���C���[�̖h��͏㏸�����A�Ώۂ�I��
	mvprintw(xa, ya, " %s(%s) �� %s ���������I", playerA->NAME, playerA->JOB, DEFup->NAME);
	xa = xa + 2;
	plusDamage = rand() % 10 - 5;
	playerPlaySpell(playerA, DEFup);
	if (playerA->playSpell == 0) {
		DEFup->POW = rand() % 30 + 20;
		playerA->MP = playerA->MP - DEFup->MP;
		int iniDEF = playerB->DEF;
		playerB->DEF += (DEFup->POW + plusDamage);
		double magni = round(((double)playerB->DEF / (double)iniDEF) * 10) / 10;
		mvprintw(xa, ya, " %s(%s) �̖h��͂� %.2f�{ �ɂȂ����I", playerB->NAME, playerB->JOB, magni);
		xa = xa + 2;
	}
}

// ����:�p���h���i�����j
void playerPandora(player * player, enemy * enemy) {
	mvprintw(xa, ya, " %s �� %s ���������I", player->NAME, pandora->NAME);
	xa = xa + 2;
	if (player->MP == 0) {
		mvaddstr(xa, ya, "������MP������Ȃ������I");
		xa = xa + 2;
	}
	else {
		if (player->MP == 1) {
			pandora->MP = 1;
		}
		else {
			pandora->MP = player->MP / 2;
		}
		player->MP -= pandora->MP;
		int judge = rand() % 4 + 1;
		switch (judge) {
		case 1:
			for (int i = 0; i < 3; i++) {
				switch (i) {
				case 0:
					currentPlayer = player1;
					break;
				case 1:
					currentPlayer = player2;
					break;
				case 2:
					currentPlayer = player3;
					break;
				}

				currentPlayer->HP /= 2;
				currentPlayer->iniPandoraHP /= 2;

			}
			mvaddstr(xa, ya, "�p�[�e�B�[��HP�����������I");
			xa = xa + 2;
			break;
		case 2:
			enemy->HP /= 2;
			enemy->iniHP /= 2;
			mvaddstr(xa, ya, "�G��HP�����������I");
			xa = xa + 2;
			break;
		case 3:
			for (int i = 0; i < 3; i++) {
				switch (i) {
				case 0:
					currentPlayer = player1;
					break;
				case 1:
					currentPlayer = player2;
					break;
				case 2:
					currentPlayer = player3;
					break;
				}
				currentPlayer->HP *= 2;
				currentPlayer->iniPandoraHP *= 2;

			}
			mvaddstr(xa, ya, "�p�[�e�B�[��HP���{�������I");
			xa = xa + 2;
			break;
		case 4:
			enemy->HP *= 2;
			enemy->iniHP *= 2;
			break;
		}
	}
}
