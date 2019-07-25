#pragma once
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <math.h>
#include "struct.h"
#include "spell.h"

// �G:�ʏ�U��
void enemyATK(enemy* enemy, player* player) { //�G�̒ʏ�U���A�Ώۂ�I��
	if (strcmp(enemy->NAME, enemy1->NAME) == 0) { // �G1�̏ꍇ
		mvprintw(xa, ya, " %s �� %s(%s) �ɑ��𓊂����I", enemy->NAME, player->NAME, player->JOB);
		xa = xa + 2;
	}
	else if (strcmp(enemy->NAME, enemy2->NAME) == 0) { // �G2�̏ꍇ
		mvprintw(xa, ya, " %s �� %s(%s) �Ɋ��݂����I", enemy->NAME, player->NAME, player->JOB);
		xa = xa + 2;
	}
	else if (strcmp(enemy->NAME, enemy3->NAME) == 0) { // �G3�̏ꍇ
		mvprintw(xa, ya, " %s �� %s(%s) �ɖ�𐔔��������I", enemy->NAME, player->NAME, player->JOB);
		xa = xa + 2;
	}
	plusDamage = rand() % 10 - 5;

	if ((enemy->POW + plusDamage - player->DEF) <= 0) {
		player->HP = player->HP;
		mvprintw(xa, ya, " %s(%s) �Ƀ_���[�W��^�����Ȃ������I", player->NAME, player->JOB);
		xa = xa + 2;
	}
	else {
		player->HP = player->HP - (enemy->POW + plusDamage - player->DEF);
		mvprintw(xa, ya, " %s(%s) �� %d �̃_���[�W�I", player->NAME, player->JOB, (enemy->POW + plusDamage - player->DEF));
		xa = xa + 2;
	}

	// �U���Ŏ��񂾏ꍇ
	if (player->HP <= 0) {
		player->dead = 1;
		mvprintw(xa, ya, " %s(%s) �͗͐s���Ă��܂����I", player->NAME, player->JOB);
		xa = xa + 2;
	}

}

// �G:�Ή�����
void enemyFire(enemy * enemy, player * player) { //�G�̉Ή������U���A�Ώۂ�I��
	fire->POW = rand() % 20 + 10;
	mvprintw(xa, ya, " %s �� %s ���������I", enemy->NAME, fire->NAME);
	xa = xa + 2;
	enemyPlaySpell(enemy, fire); // MP����
	plusDamage = rand() % 10 - 5;
	if (enemy->playSpell == 0) {
		enemy->MP = enemy->MP - fire->MP;
		player->HP = player->HP - (fire->POW + plusDamage);
		mvprintw(xa, ya, " %s(%s) �� %d �̃_���[�W�I", player->NAME, player->JOB, fire->POW + plusDamage);
		xa = xa + 2;
		if (player->HP <= 0) {
			player->dead = 1;
			mvprintw(xa, ya, " %s(%s) �͗͐s���Ă��܂����I", player->NAME, player->JOB);
			xa = xa + 2;
		}
	}
}

// �G:��������
void enemyExplosion() { //�G�̔��������̑S�̍U��
	mvprintw(xa, ya, " %s �� %s ���������I", enemy3->NAME, explosion->NAME);
	xa = xa + 2;
	explosion->POW = rand() % 20 + 10;
	plusDamage = rand() % 10 - 5;
	enemyPlaySpell(enemy3, explosion);
	if (enemy3->playSpell == 0) {
		// ����1�̂��ƂɃ_���[�W�v�Z
		enemy3->MP = enemy3->MP - explosion->MP;
		explosion->POW = rand() % 20 + 10;
		player1->HP -= (explosion->POW + plusDamage);
		if (player1->dead == 0) {
			mvprintw(xa, ya, " %s(%s) �� %d �̃_���[�W�I", player1->NAME, player1->JOB, explosion->POW + plusDamage);
			xa = xa + 2;
			if (player1->HP <= 0) {
				player1->dead = 1;
				mvprintw(xa, ya, " %s(%s) �͗͐s���Ă��܂����I", player1->NAME, player1->JOB);
				xa = xa + 2;
			}
		}
		explosion->POW = rand() % 20 + 10;
		plusDamage = rand() % 10 - 5;
		player2->HP -= (explosion->POW + plusDamage);
		if (player2->dead == 0) {
			mvprintw(xa, ya, " %s(%s) �� %d �̃_���[�W�I", player2->NAME, player2->JOB, explosion->POW + plusDamage);
			xa = xa + 2;
			if (player2->HP <= 0) {
				player2->dead = 1;
				mvprintw(xa, ya, " %s(%s) �͗͐s���Ă��܂����I", player2->NAME, player2->JOB);
				xa = xa + 2;
			}
		}
		explosion->POW = rand() % 20 + 10;
		plusDamage = rand() % 10 - 5;
		player3->HP -= (explosion->POW + plusDamage);
		if (player3->dead == 0) {
			mvprintw(xa, ya, " %s(%s) �� %d �̃_���[�W�I", player3->NAME, player3->JOB, explosion->POW + plusDamage);
			xa = xa + 2;
			if (player3->HP <= 0) {
				player3->dead = 1;
				mvprintw(xa, ya, " %s(%s) �͗͐s���Ă��܂����I", player3->NAME, player3->JOB);
				xa = xa + 2;
			}
		}
	}
}

// �G:�񕜎���
void enemyCure(enemy * enemy) { //�G�̉񕜎���
	mvprintw(xa, ya, " %s �� %s ���������I", enemy->NAME, cure->NAME);
	xa = xa + 2;
	cure->POW = rand() % 30 + 20;
	plusDamage = rand() % 10 - 5;
	enemyPlaySpell(enemy, cure);
	if (enemy->playSpell == 0) {
		enemy->MP = enemy->MP - cure->MP;
		enemy->HP += (cure->POW + plusDamage);
		if (enemy->HP > enemy->iniHP) {
			cure->POW = enemy->HP - enemy->iniHP;
			enemy->HP = enemy->iniHP;

		}
		mvprintw(xa, ya, " %s ��HP�� %d �񕜂����I", enemy->NAME, cure->POW + plusDamage);
		xa = xa + 2;
	}
}

// �G:�h���up����
void enemyDEFup(enemy * enemy) {
	mvprintw(xa, ya, " %s �� %s ���������I", enemy->NAME, DEFup->NAME);
	xa = xa + 2;
	DEFup->POW = rand() % 20;
	plusDamage = rand() % 10 - 5;
	enemyPlaySpell(enemy, DEFup);
	if (enemy->playSpell == 0) {
		enemy->MP = enemy->MP - DEFup->MP;
		int iniDEF = enemy->DEF;
		enemy->DEF += (DEFup->POW + plusDamage);
		double magni = round(((double)enemy->DEF / (double)iniDEF) * 10) / 10;
		mvprintw(xa, ya, " %s �̖h��͂� %.2f�{ �ɂȂ����I", enemy->NAME, magni);
		xa = xa + 2;
	}
}

// �G:�Ö�����
void enemySleep(enemy * enemy) {
	mvprintw(xa, ya, "  %s �� %s ���������I", enemy->NAME, sleep->NAME);
	xa = xa + 2;
	enemyPlaySpell(enemy, sleep);
	if (enemy->playSpell == 0) {
		enemy->MP -= sleep->MP;
		sleep->POW = 50;
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
			int sleepRate = rand() % 100;
			if (sleep->POW <= sleepRate) {
				currentPlayer->sleep = 1;
				mvprintw(xa, ya, " %s(%s) �͖����Ă��܂����I", currentPlayer->NAME, currentPlayer->JOB);
				xa = xa + 2;

			}
			else {
				currentPlayer->sleep = 0;
				mvprintw(xa, ya, " %s(%s) �ɂ͌����Ȃ������I", currentPlayer->NAME, currentPlayer->JOB);
				xa = xa + 2;
			}

		}
	}
}
