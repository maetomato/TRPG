#pragma once
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <math.h>
#include "struct.h"
#include "spell.h"

// “G:’ÊíUŒ‚
void enemyATK(enemy* enemy, player* player) { //“G‚Ì’ÊíUŒ‚A‘ÎÛ‚ð‘I‘ð
	if (strcmp(enemy->NAME, enemy1->NAME) == 0) { // “G1‚Ìê‡
		mvprintw(xa, ya, " %s ‚Í %s(%s) ‚É‘„‚ð“Š‚°‚½I", enemy->NAME, player->NAME, player->JOB);
		xa = xa + 2;
	}
	else if (strcmp(enemy->NAME, enemy2->NAME) == 0) { // “G2‚Ìê‡
		mvprintw(xa, ya, " %s ‚Í %s(%s) ‚ÉŠš‚Ý‚Â‚¢‚½I", enemy->NAME, player->NAME, player->JOB);
		xa = xa + 2;
	}
	else if (strcmp(enemy->NAME, enemy3->NAME) == 0) { // “G3‚Ìê‡
		mvprintw(xa, ya, " %s ‚Í %s(%s) ‚É–î‚ð””­•ú‚Á‚½I", enemy->NAME, player->NAME, player->JOB);
		xa = xa + 2;
	}
	plusDamage = rand() % 10 - 5;

	if ((enemy->POW + plusDamage - player->DEF) <= 0) {
		player->HP = player->HP;
		mvprintw(xa, ya, " %s(%s) ‚Éƒ_ƒ[ƒW‚ð—^‚¦‚ç‚ê‚È‚©‚Á‚½I", player->NAME, player->JOB);
		xa = xa + 2;
	}
	else {
		player->HP = player->HP - (enemy->POW + plusDamage - player->DEF);
		mvprintw(xa, ya, " %s(%s) ‚É %d ‚Ìƒ_ƒ[ƒWI", player->NAME, player->JOB, (enemy->POW + plusDamage - player->DEF));
		xa = xa + 2;
	}

	// UŒ‚‚ÅŽ€‚ñ‚¾ê‡
	if (player->HP <= 0) {
		player->dead = 1;
		mvprintw(xa, ya, " %s(%s) ‚Í—Ís‚«‚Ä‚µ‚Ü‚Á‚½I", player->NAME, player->JOB);
		xa = xa + 2;
	}

}

// “G:‰Î‰ŠŽô•¶
void enemyFire(enemy * enemy, player * player) { //“G‚Ì‰Î‰ŠŽô•¶UŒ‚A‘ÎÛ‚ð‘I‘ð
	fire->POW = rand() % 20 + 10;
	mvprintw(xa, ya, " %s ‚Í %s ‚ð¥‚¦‚½I", enemy->NAME, fire->NAME);
	xa = xa + 2;
	enemyPlaySpell(enemy, fire); // MP”»’è
	plusDamage = rand() % 10 - 5;
	if (enemy->playSpell == 0) {
		enemy->MP = enemy->MP - fire->MP;
		player->HP = player->HP - (fire->POW + plusDamage);
		mvprintw(xa, ya, " %s(%s) ‚É %d ‚Ìƒ_ƒ[ƒWI", player->NAME, player->JOB, fire->POW + plusDamage);
		xa = xa + 2;
		if (player->HP <= 0) {
			player->dead = 1;
			mvprintw(xa, ya, " %s(%s) ‚Í—Ís‚«‚Ä‚µ‚Ü‚Á‚½I", player->NAME, player->JOB);
			xa = xa + 2;
		}
	}
}

// “G:”š”­Žô•¶
void enemyExplosion() { //“G‚Ì”š”­Žô•¶‚Ì‘S‘ÌUŒ‚
	mvprintw(xa, ya, " %s ‚Í %s ‚ð¥‚¦‚½I", enemy3->NAME, explosion->NAME);
	xa = xa + 2;
	explosion->POW = rand() % 20 + 10;
	plusDamage = rand() % 10 - 5;
	enemyPlaySpell(enemy3, explosion);
	if (enemy3->playSpell == 0) {
		// –¡•û1‘Ì‚²‚Æ‚Éƒ_ƒ[ƒWŒvŽZ
		enemy3->MP = enemy3->MP - explosion->MP;
		explosion->POW = rand() % 20 + 10;
		player1->HP -= (explosion->POW + plusDamage);
		if (player1->dead == 0) {
			mvprintw(xa, ya, " %s(%s) ‚É %d ‚Ìƒ_ƒ[ƒWI", player1->NAME, player1->JOB, explosion->POW + plusDamage);
			xa = xa + 2;
			if (player1->HP <= 0) {
				player1->dead = 1;
				mvprintw(xa, ya, " %s(%s) ‚Í—Ís‚«‚Ä‚µ‚Ü‚Á‚½I", player1->NAME, player1->JOB);
				xa = xa + 2;
			}
		}
		explosion->POW = rand() % 20 + 10;
		plusDamage = rand() % 10 - 5;
		player2->HP -= (explosion->POW + plusDamage);
		if (player2->dead == 0) {
			mvprintw(xa, ya, " %s(%s) ‚É %d ‚Ìƒ_ƒ[ƒWI", player2->NAME, player2->JOB, explosion->POW + plusDamage);
			xa = xa + 2;
			if (player2->HP <= 0) {
				player2->dead = 1;
				mvprintw(xa, ya, " %s(%s) ‚Í—Ís‚«‚Ä‚µ‚Ü‚Á‚½I", player2->NAME, player2->JOB);
				xa = xa + 2;
			}
		}
		explosion->POW = rand() % 20 + 10;
		plusDamage = rand() % 10 - 5;
		player3->HP -= (explosion->POW + plusDamage);
		if (player3->dead == 0) {
			mvprintw(xa, ya, " %s(%s) ‚É %d ‚Ìƒ_ƒ[ƒWI", player3->NAME, player3->JOB, explosion->POW + plusDamage);
			xa = xa + 2;
			if (player3->HP <= 0) {
				player3->dead = 1;
				mvprintw(xa, ya, " %s(%s) ‚Í—Ís‚«‚Ä‚µ‚Ü‚Á‚½I", player3->NAME, player3->JOB);
				xa = xa + 2;
			}
		}
	}
}

// “G:‰ñ•œŽô•¶
void enemyCure(enemy * enemy) { //“G‚Ì‰ñ•œŽô•¶
	mvprintw(xa, ya, " %s ‚Í %s ‚ð¥‚¦‚½I", enemy->NAME, cure->NAME);
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
		mvprintw(xa, ya, " %s ‚ÍHP‚ª %d ‰ñ•œ‚µ‚½I", enemy->NAME, cure->POW + plusDamage);
		xa = xa + 2;
	}
}

// “G:–hŒä—ÍupŽô•¶
void enemyDEFup(enemy * enemy) {
	mvprintw(xa, ya, " %s ‚Í %s ‚ð¥‚¦‚½I", enemy->NAME, DEFup->NAME);
	xa = xa + 2;
	DEFup->POW = rand() % 20;
	plusDamage = rand() % 10 - 5;
	enemyPlaySpell(enemy, DEFup);
	if (enemy->playSpell == 0) {
		enemy->MP = enemy->MP - DEFup->MP;
		int iniDEF = enemy->DEF;
		enemy->DEF += (DEFup->POW + plusDamage);
		double magni = round(((double)enemy->DEF / (double)iniDEF) * 10) / 10;
		mvprintw(xa, ya, " %s ‚Ì–hŒä—Í‚ª %.2f”{ ‚É‚È‚Á‚½I", enemy->NAME, magni);
		xa = xa + 2;
	}
}

// “G:Ã–°Žô•¶
void enemySleep(enemy * enemy) {
	mvprintw(xa, ya, "  %s ‚Í %s ‚ð¥‚¦‚½I", enemy->NAME, sleep->NAME);
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
				mvprintw(xa, ya, " %s(%s) ‚Í–°‚Á‚Ä‚µ‚Ü‚Á‚½I", currentPlayer->NAME, currentPlayer->JOB);
				xa = xa + 2;

			}
			else {
				currentPlayer->sleep = 0;
				mvprintw(xa, ya, " %s(%s) ‚É‚ÍŒø‚©‚È‚©‚Á‚½I", currentPlayer->NAME, currentPlayer->JOB);
				xa = xa + 2;
			}

		}
	}
}
