#pragma once
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <math.h>
#include "struct.h"
#include "spell.h"

// 敵:通常攻撃
void enemyATK(enemy* enemy, player* player) { //敵の通常攻撃、対象を選択
	if (strcmp(enemy->NAME, enemy1->NAME) == 0) { // 敵1の場合
		mvprintw(xa, ya, " %s は %s(%s) に槍を投げた！", enemy->NAME, player->NAME, player->JOB);
		xa = xa + 2;
	}
	else if (strcmp(enemy->NAME, enemy2->NAME) == 0) { // 敵2の場合
		mvprintw(xa, ya, " %s は %s(%s) に噛みついた！", enemy->NAME, player->NAME, player->JOB);
		xa = xa + 2;
	}
	else if (strcmp(enemy->NAME, enemy3->NAME) == 0) { // 敵3の場合
		mvprintw(xa, ya, " %s は %s(%s) に矢を数発放った！", enemy->NAME, player->NAME, player->JOB);
		xa = xa + 2;
	}
	plusDamage = rand() % 10 - 5;

	if ((enemy->POW + plusDamage - player->DEF) <= 0) {
		player->HP = player->HP;
		mvprintw(xa, ya, " %s(%s) にダメージを与えられなかった！", player->NAME, player->JOB);
		xa = xa + 2;
	}
	else {
		player->HP = player->HP - (enemy->POW + plusDamage - player->DEF);
		mvprintw(xa, ya, " %s(%s) に %d のダメージ！", player->NAME, player->JOB, (enemy->POW + plusDamage - player->DEF));
		xa = xa + 2;
	}

	// 攻撃で死んだ場合
	if (player->HP <= 0) {
		player->dead = 1;
		mvprintw(xa, ya, " %s(%s) は力尽きてしまった！", player->NAME, player->JOB);
		xa = xa + 2;
	}

}

// 敵:火炎呪文
void enemyFire(enemy * enemy, player * player) { //敵の火炎呪文攻撃、対象を選択
	fire->POW = rand() % 20 + 10;
	mvprintw(xa, ya, " %s は %s を唱えた！", enemy->NAME, fire->NAME);
	xa = xa + 2;
	enemyPlaySpell(enemy, fire); // MP判定
	plusDamage = rand() % 10 - 5;
	if (enemy->playSpell == 0) {
		enemy->MP = enemy->MP - fire->MP;
		player->HP = player->HP - (fire->POW + plusDamage);
		mvprintw(xa, ya, " %s(%s) に %d のダメージ！", player->NAME, player->JOB, fire->POW + plusDamage);
		xa = xa + 2;
		if (player->HP <= 0) {
			player->dead = 1;
			mvprintw(xa, ya, " %s(%s) は力尽きてしまった！", player->NAME, player->JOB);
			xa = xa + 2;
		}
	}
}

// 敵:爆発呪文
void enemyExplosion() { //敵の爆発呪文の全体攻撃
	mvprintw(xa, ya, " %s は %s を唱えた！", enemy3->NAME, explosion->NAME);
	xa = xa + 2;
	explosion->POW = rand() % 20 + 10;
	plusDamage = rand() % 10 - 5;
	enemyPlaySpell(enemy3, explosion);
	if (enemy3->playSpell == 0) {
		// 味方1体ごとにダメージ計算
		enemy3->MP = enemy3->MP - explosion->MP;
		explosion->POW = rand() % 20 + 10;
		player1->HP -= (explosion->POW + plusDamage);
		if (player1->dead == 0) {
			mvprintw(xa, ya, " %s(%s) に %d のダメージ！", player1->NAME, player1->JOB, explosion->POW + plusDamage);
			xa = xa + 2;
			if (player1->HP <= 0) {
				player1->dead = 1;
				mvprintw(xa, ya, " %s(%s) は力尽きてしまった！", player1->NAME, player1->JOB);
				xa = xa + 2;
			}
		}
		explosion->POW = rand() % 20 + 10;
		plusDamage = rand() % 10 - 5;
		player2->HP -= (explosion->POW + plusDamage);
		if (player2->dead == 0) {
			mvprintw(xa, ya, " %s(%s) に %d のダメージ！", player2->NAME, player2->JOB, explosion->POW + plusDamage);
			xa = xa + 2;
			if (player2->HP <= 0) {
				player2->dead = 1;
				mvprintw(xa, ya, " %s(%s) は力尽きてしまった！", player2->NAME, player2->JOB);
				xa = xa + 2;
			}
		}
		explosion->POW = rand() % 20 + 10;
		plusDamage = rand() % 10 - 5;
		player3->HP -= (explosion->POW + plusDamage);
		if (player3->dead == 0) {
			mvprintw(xa, ya, " %s(%s) に %d のダメージ！", player3->NAME, player3->JOB, explosion->POW + plusDamage);
			xa = xa + 2;
			if (player3->HP <= 0) {
				player3->dead = 1;
				mvprintw(xa, ya, " %s(%s) は力尽きてしまった！", player3->NAME, player3->JOB);
				xa = xa + 2;
			}
		}
	}
}

// 敵:回復呪文
void enemyCure(enemy * enemy) { //敵の回復呪文
	mvprintw(xa, ya, " %s は %s を唱えた！", enemy->NAME, cure->NAME);
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
		mvprintw(xa, ya, " %s はHPが %d 回復した！", enemy->NAME, cure->POW + plusDamage);
		xa = xa + 2;
	}
}

// 敵:防御力up呪文
void enemyDEFup(enemy * enemy) {
	mvprintw(xa, ya, " %s は %s を唱えた！", enemy->NAME, DEFup->NAME);
	xa = xa + 2;
	DEFup->POW = rand() % 20;
	plusDamage = rand() % 10 - 5;
	enemyPlaySpell(enemy, DEFup);
	if (enemy->playSpell == 0) {
		enemy->MP = enemy->MP - DEFup->MP;
		int iniDEF = enemy->DEF;
		enemy->DEF += (DEFup->POW + plusDamage);
		double magni = round(((double)enemy->DEF / (double)iniDEF) * 10) / 10;
		mvprintw(xa, ya, " %s の防御力が %.2f倍 になった！", enemy->NAME, magni);
		xa = xa + 2;
	}
}

// 敵:催眠呪文
void enemySleep(enemy * enemy) {
	mvprintw(xa, ya, "  %s は %s を唱えた！", enemy->NAME, sleep->NAME);
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
				mvprintw(xa, ya, " %s(%s) は眠ってしまった！", currentPlayer->NAME, currentPlayer->JOB);
				xa = xa + 2;

			}
			else {
				currentPlayer->sleep = 0;
				mvprintw(xa, ya, " %s(%s) には効かなかった！", currentPlayer->NAME, currentPlayer->JOB);
				xa = xa + 2;
			}

		}
	}
}
