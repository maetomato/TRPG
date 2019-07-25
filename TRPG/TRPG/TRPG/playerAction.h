#pragma once

// 呪文を唱えられるかを判定
void playerPlaySpell(player* player, spell* spell) {
	if (player->MP < spell->MP) {
		player->playSpell = 1;
		fprintf_s(stdout, "\nしかしMPが足りなかった！\n");
	}
	else if (player->MP >= spell->MP) {
		player->playSpell = 0;
	}
}

// 通常攻撃
void playerATK(player* player, enemy* enemy) { //プレイヤーの通常攻撃
	fprintf_s(stdout, "\n %s(%s) は %s に攻撃した！\n", player->NAME, player->JOB, enemy->NAME);
	plusDamage = rand() % 10 - 5;
	if (player->POW + plusDamage - enemy->DEF <= 0) {
		enemy->HP = enemy->HP;
		fprintf_s(stdout, " %s にダメージを与えられなかった！\n", enemy->NAME);
	}
	else {
		enemy->HP = enemy->HP - (player->POW + plusDamage - enemy->DEF);
		fprintf_s(stdout, " %s に %d のダメージ！\n", enemy->NAME, (player->POW + plusDamage - enemy->DEF));
	}

}

// 魔法:火炎
void playerFire(player* player, enemy* enemy) { //プレイヤーの火炎呪文攻撃
	fprintf_s(stdout, "\n %s(%s) は %s を唱えた！\n", player->NAME, player->JOB, fire->NAME);
	fire->POW = rand() % 10 + 10;
	playerPlaySpell(player, fire);
	plusDamage = rand() % 10 - 5;
	if (player->playSpell == 0) {
		player->MP = player->MP - fire->MP;
		enemy->HP = enemy->HP - (fire->POW + plusDamage);
		fprintf_s(stdout, " %s に %d のダメージ！\n", enemy->NAME, fire->POW + plusDamage);
	}
}

// 魔法:回復
void playerCure(player* playerA, player* playerB) { //プレイヤーの回復呪文、対象を選択
	fprintf_s(stdout, "\n %s(%s) は %s を唱えた！\n", playerA->NAME, playerA->JOB, cure->NAME);
	cure->POW = rand() % 30 + 10;
	plusDamage = rand() % 10 - 5;
	playerPlaySpell(playerA, cure);
	if (playerB->dead != 1 && playerA->playSpell == 0) {
		playerA->MP = playerA->MP - cure->MP;
		playerB->HP += (cure->POW + plusDamage);
		if (playerB->HP > playerB->iniHP) {
			cure->POW = playerB->HP - playerB->iniHP;
			playerB->HP = playerB->iniHP;

		}
		fprintf_s(stdout, " %s(%s) はHPが %d 回復した！\n", playerB->NAME, playerB->JOB, cure->POW);
	}
	else {
		fprintf_s(stdout, " %s は死んでいる！\n", playerB->NAME);
	}
}

// 魔法:攻撃力up
void playerPOWup(player* playerA, player* playerB) { //プレイヤーの攻撃力上昇呪文、対象を選択
	fprintf_s(stdout, "\n %s(%s) は %s を唱えた！\n", playerA->NAME, playerA->JOB, POWup->NAME);
	POWup->POW = rand() % 30 + 10;
	plusDamage = rand() % 10 - 5;
	playerPlaySpell(playerA, POWup);
	if (playerA->playSpell == 0) {
		playerA->MP = playerA->MP - POWup->MP;
		int iniPOW = playerB->POW;
		playerB->POW += (POWup->POW + plusDamage);
		double magni = round((playerB->POW / iniPOW) * 10) / 10;
		fprintf_s(stdout, " %s(%s) の攻撃力が %.2f倍 になった！\n", playerB->NAME, playerB->JOB, magni);
	}
}

// 魔法:防御up
void playerDEFup(player* playerA, player* playerB) { //プレイヤーの防御力上昇呪文、対象を選択
	fprintf_s(stdout, "\n %s(%s) は %s を唱えた！\n", playerA->NAME, playerA->JOB, DEFup->NAME);
	plusDamage = rand() % 10 - 5;
	playerPlaySpell(playerA, DEFup);
	if (playerA->playSpell == 0) {
		DEFup->POW = rand() % 20 + 10;
		playerA->MP = playerA->MP - DEFup->MP;
		int iniDEF = playerB->DEF;
		playerB->DEF += (DEFup->POW + plusDamage);
		double magni = round((playerB->DEF / iniDEF) * 10) / 10;
		fprintf_s(stdout, " %s(%s) の防御力が %.2f倍 になった！\n", playerB->NAME, playerB->JOB, magni);
	}
}

// 魔法:パンドラ
void playerPandora(player* player, enemy* enemy) {
	fprintf_s(stdout, "\n %s は %s を唱えた！\n", player->NAME, pandora->NAME);
	if (player->MP == 0) {
		fprintf_s(stdout, "\nしかしMPが足りなかった！\n");
	}
	else {
		pandora->MP = player->MP / 2;
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
			fprintf_s(stdout, "パーティーのHPが半減した！\n");
			break;
		case 2:
			enemy->HP /= 2;
			enemy->iniHP /= 2;
			fprintf_s(stdout, "敵のHPが半減した！\n");
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
			fprintf_s(stdout, "パーティーのHPが倍増した！\n");
			break;
		case 4:
			enemy->HP *= 2;
			enemy->iniHP *= 2;
			fprintf_s(stdout, "敵のHPが倍増した！\n");
			break;
		}
	}
}

// 戦士
void Solder(player* player, enemy* enemy) {
	playerATK(player, enemy);
	//HPが少なくなれば防御するメソッドも追加かも

}

// 武闘家
void Martial(player* player, enemy* enemy) {
	playerATK(player, enemy);
	//防御メソッド

}

// 魔法使い
void Wizzard(player* player, enemy* enemy) {
	int attack = rand() % 3 + 1;
	int judge;
	switch (attack) {
	case 1:
		playerATK(player, enemy);
		break;
	case 2:
		playerFire(player, enemy);
		break;
	case 3:
		selectPlayer();
		playerPOWup(player, currentPlayer);


		break;

	}

}

// 僧侶
void Monk(player* player, enemy* enemy) {
	int attack = rand() % 3 + 1;
	int judge;
	switch (attack) {
	case 1:
		playerATK(player, enemy);
		break;
	case 2:
		selectPlayer();
		playerCure(player, currentPlayer);
		break;
	case 3:
		selectPlayer();
		playerDEFup(player, currentPlayer);


		break;

	}

}

// 遊び人
void Playful(player* player, enemy* enemy) {
	int attack = rand() % 10 + 1;
	int judge;
	switch (attack) {
	case 1:
	case 5:
	case 7:
		playerATK(player, enemy);
		break;
	case 2:
	case 6:
	case 10:
		selectPlayer();
		playerCure(player, currentPlayer);

		break;
	case 3:
		playerPandora(player, enemy);
		break;
	case 4:
	case 8:
	case 9:
		playerFire(player, enemy);
		break;
	}

}

void playerTurn(player* player, enemy* enemy) {
	DEAD(player);
	if (player->sleep == 1 && player->dead == 0) {
		GetUp(player);
	}
	if (player->dead == 0) {
		if (player->sleep == 0) {
			if (strcmp(player->JOB, "戦士") == 0) {
				Solder(player, enemy);
			}
			else if (strcmp(player->JOB, "魔法使い") == 0) {
				Wizzard(player, enemy);
			}
			else if (strcmp(player->JOB, "僧侶") == 0) {
				Monk(player, enemy);
			}
			else if (strcmp(player->JOB, "武闘家") == 0) {
				Martial(player, enemy);
			}
			else if (strcmp(player->JOB, "遊び人") == 0) {
				Playful(player, enemy);
			}
		}
	}

}

