#pragma once

void enemyPlaySpell(enemy* enemy, spell* spell) {
	if (enemy->MP < spell->MP) {
		enemy->playSpell = 1;
		fprintf_s(stdout, "\nしかしMPが足りなかった！\n");
	}
	else if (enemy->MP >= spell->MP) {
		enemy->playSpell = 0;
	}
}

// 敵:通常攻撃
void enemyATK(enemy* enemy, player* player) { //敵の通常攻撃、対象を選択
	if (strcmp(enemy->NAME, enemy1->NAME) == 0) {
		fprintf_s(stdout, "\n %s は %s(%s) に槍を投げた！\n", enemy->NAME, player->NAME, player->JOB);
	}
	else if (strcmp(enemy->NAME, enemy2->NAME) == 0) {
		fprintf_s(stdout, "\n %s は %s(%s) に噛みついた！\n", enemy->NAME, player->NAME, player->JOB);
	}
	else if (strcmp(enemy->NAME, enemy3->NAME) == 0) {
		fprintf_s(stdout, "\n %s は %s(%s) に矢を数発放った！\n", enemy->NAME, player->NAME, player->JOB);
	}
	plusDamage = rand() % 10 - 5;

	if (enemy->POW + plusDamage - player->DEF <= 0) {
		player->HP = player->HP;
		fprintf_s(stdout, " %s(%s) にダメージを与えられなかった！\n", player->NAME, player->JOB);
	}
	else {
		player->HP = player->HP - (enemy->POW + plusDamage - player->DEF);
		fprintf_s(stdout, " %s(%s) に %d のダメージ！\n", player->NAME, player->JOB, (enemy->POW - player->DEF));
	}


	if (player->HP <= 0) {
		player->dead = 1;
		fprintf_s(stdout, " %s(%s) は力尽きてしまった！\n", player->NAME, player->JOB);
	}

}

// 敵魔法:火炎
void enemyFire(enemy* enemy, player* player) { //敵の火炎呪文攻撃、対象を選択
	fire->POW = rand() % 20 + 10;
	fprintf_s(stdout, "\n %s は %s を唱えた！\n", enemy->NAME, fire->NAME);
	enemyPlaySpell(enemy, fire);
	plusDamage = rand() % 10 - 5;
	if (enemy->playSpell == 0) {
		enemy->MP = enemy->MP - fire->MP;
		player->HP = player->HP - (fire->POW + plusDamage);
		fprintf_s(stdout, " %s(%s) に %d のダメージ！\n", player->NAME, player->JOB, fire->POW + plusDamage);
		if (player->HP <= 0) {
			player->dead = 1;
			fprintf_s(stdout, " %s(%s) は力尽きてしまった！\n", player->NAME, player->JOB);
		}
	}
}


// 敵魔法:エクスプロージョン
void enemyExplosion() { //敵の爆発呪文の全体攻撃
	fprintf_s(stdout, "\n %s は %s を唱えた！\n", enemy3->NAME, explosion->NAME);
	explosion->POW = rand() % 20 + 10;
	plusDamage = rand() % 10 - 5;
	enemyPlaySpell(enemy3, explosion);
	if (enemy3->playSpell == 0) {
		enemy3->MP = enemy3->MP - explosion->MP;
		explosion->POW = rand() % 20 + 10;
		player1->HP -= (explosion->POW + plusDamage);
		fprintf_s(stdout, " %s(%s) に %d のダメージ！\n", player1->NAME, player1->JOB, explosion->POW + plusDamage);
		if (player1->HP <= 0) {
			player1->dead = 1;
			fprintf_s(stdout, " %s(%s) は力尽きてしまった！\n", player1->NAME, player1->JOB);
		}
		explosion->POW = rand() % 20 + 10;
		plusDamage = rand() % 10 - 5;
		player2->HP -= (explosion->POW + plusDamage);
		fprintf_s(stdout, " %s(%s) に %d のダメージ！\n", player2->NAME, player2->JOB, explosion->POW + plusDamage);
		if (player2->HP <= 0) {
			player2->dead = 1;
			fprintf_s(stdout, " %s(%s) は力尽きてしまった！\n", player2->NAME, player2->JOB);
		}
		explosion->POW = rand() % 20 + 10;
		plusDamage = rand() % 10 - 5;
		player3->HP -= (explosion->POW + plusDamage);
		fprintf_s(stdout, " %s(%s) に %d のダメージ！\n", player3->NAME, player3->JOB, explosion->POW + plusDamage);
		if (player3->HP <= 0) {
			player3->dead = 1;
			fprintf_s(stdout, " %s(%s) は力尽きてしまった！\n", player3->NAME, player3->JOB);
		}
	}
}


// 敵魔法:回復
void enemyCure(enemy* enemy) { //敵の回復呪文
	fprintf_s(stdout, "\n %s は %s を唱えた！\n", enemy->NAME, cure->NAME);
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
		fprintf_s(stdout, " %s はHPが %d 回復した！\n", enemy->NAME, cure->POW);
	}
}

// 敵魔法:防御up
void enemyDEFup(enemy* enemy) {
	fprintf_s(stdout, "\n %s は %s を唱えた！\n", enemy->NAME, DEFup->NAME);
	DEFup->POW = rand() % 20 + 20;
	plusDamage = rand() % 10 - 5;
	enemyPlaySpell(enemy, DEFup);
	if (enemy->playSpell == 0) {
		enemy->MP = enemy->MP - DEFup->MP;
		int iniDEF = enemy->DEF;
		enemy->DEF += (DEFup->POW + plusDamage);
		double magni = round((enemy->DEF / iniDEF) * 10) / 10;
		fprintf_s(stdout, " %s の防御力が %.2f倍 になった！\n", enemy->NAME, magni);
	}
}

// 敵の眠り呪文
void enemySleep(enemy* enemy) {
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
				fprintf_s(stdout, " %s(%s) は眠ってしまった！\n", currentPlayer->NAME, currentPlayer->JOB);

			}
			else {
				currentPlayer->sleep = 0;
				fprintf_s(stdout, " %s(%s) には効かなかった！\n", currentPlayer->NAME, currentPlayer->JOB);
			}

		}
	}
}

// 敵:ムーンビースト
void MoonBeast(enemy* enemy) {
	int attack = rand() % 2 + 1;
	int judge;
	switch (attack) {
	case 1:

		selectPlayer();
		enemyATK(enemy, currentPlayer);
		break;
	case 2:

		selectPlayer();
		enemyFire(enemy, currentPlayer);
		break;

	}

}

// 敵:イゴローナク
void Ygolonac(enemy* enemy) {
	//srand((unsigned)time(NULL));
	int attack = rand() % 3 + 1;
	switch (attack) {
	case 1:
		selectPlayer();
		enemyATK(enemy, currentPlayer);
		break;
	case 2:
		enemyCure(enemy);
		break;
	case 3:
		enemyDEFup(enemy);
		break;
	}
}

// ニャルラトホテプ
void Nyarlathotep(enemy* enemy, int turn) {
	//srand((unsigned)time(NULL));

	if (turn == 1) {
		enemySleep(enemy);
	}
	else {
		int attack = rand() % 4 + 1;
		switch (attack) {
		case 1:
			selectPlayer();
			enemyATK(enemy, currentPlayer);
			break;
		case 2:
			enemyExplosion();
			break;
		case 3:
			enemyCure(enemy);
			break;
		case 4:
			enemySleep(enemy);
		}
	}
}