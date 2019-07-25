#pragma once
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "struct.h"
#include "playerSpell.h"
#include "battle.h"

extern int DEXOrder[4] = { player1->DEX, player2->DEX, player3->DEX, 0 }; // 行動順並び替え用配列
extern int attackOrder[4] = { 1,2,3,0 }; // 行動順を保持（DEXが大きい順）

// 対象選択
// 死亡しているプレイヤーが対象とならないようにする
void selectPlayer() {
	int select1 = rand() % 3;
	int select2;
	if (select1 == 0) {
		if (player1->dead == 0) {
			currentPlayer = player1;
		}
		else if (player1->dead == 1) {
			select2 = rand() % 2;
			if (select2 == 0) {
				if (player2->dead == 0) {
					currentPlayer = player2;
				}
				else if (player2->dead == 1) {
					currentPlayer = player3;
				}
			}
			else if (select2 == 1) {
				if (player3->dead == 0) {
					currentPlayer = player3;
				}
				else if (player3->dead == 1) {
					currentPlayer = player2;
				}
			}
		}
	}
	else if (select1 == 1) {
		if (player2->dead == 0) {
			currentPlayer = player2;
		}
		else if (player2->dead == 1) {
			select2 = rand() % 2;
			if (select2 == 0) {
				if (player1->dead == 0) {
					currentPlayer = player1;
				}
				else if (player1->dead == 1) {
					currentPlayer = player3;
				}
			}
			else if (select2 == 1) {
				if (player3->dead == 0) {
					currentPlayer = player3;
				}
				else if (player3->dead == 1) {
					currentPlayer = player1;
				}
			}
		}
	}
	if (select1 == 2) {
		if (player3->dead == 0) {
			currentPlayer = player3;
		}
		else if (player3->dead == 1) {
			select2 = rand() % 2;
			if (select2 == 0) {
				if (player1->dead == 0) {
					currentPlayer = player1;
				}
				else if (player1->dead == 1) {
					currentPlayer = player2;
				}
			}
			else if (select2 == 1) {
				if (player2->dead == 0) {
					currentPlayer = player2;
				}
				else if (player2->dead == 1) {
					currentPlayer = player1;
				}
			}
		}
	}
}

// 死亡判定
void DEAD(player* player) {
	if (player->HP <= 0) {
		player->dead = 1;
		mvprintw(xa, ya, " %s(%s) は力尽きている...", player->NAME, player->JOB);
		xa = xa + 2;
	}

}

// 行動順並び替え（DEXが大きい順）
void DexOrder(enemy* enemy) {
	DEXOrder[0] = player1->DEX;
	DEXOrder[1] = player2->DEX;
	DEXOrder[2] = player3->DEX;
	DEXOrder[3] = enemy->DEX;

	attackOrder[0] = 1;
	attackOrder[1] = 2;
	attackOrder[2] = 3;
	attackOrder[3] = 11;
	for (int i = 0; i < 4; i++) {
		int DEXTmp = 0;
		int attackTmp = 0;
		for (int j = i + 1; j < 4; j++) {
			if (DEXOrder[i] <= DEXOrder[j]) {
				DEXTmp = DEXOrder[j];
				DEXOrder[j] = DEXOrder[i];
				DEXOrder[i] = DEXTmp;
				attackTmp = attackOrder[j];
				attackOrder[j] = attackOrder[i];
				attackOrder[i] = attackTmp;
			}
		}
	}

}

// 戦士の行動パターン
void Solder(player* player, enemy* enemy) {
	playerATK(player, enemy); // 通常攻撃

}

// 武闘家の行動パターン
void Martial(player* player, enemy* enemy) {
	playerATK(player, enemy); // 通常攻撃

}

// 魔法使いの行動パターン
void Wizzard(player* player, enemy* enemy) {
	int attack = rand() % 3 + 1;

	switch (attack) {
	case 1: // 通常攻撃
		playerATK(player, enemy);
		break;
	case 2: // 火炎呪文
		playerFire(player, enemy);
		break;
	case 3: // 攻撃力up呪文
		selectPlayer();
		playerPOWup(player, currentPlayer);
		break;

	}
}

// 僧侶の行動パターン
void Monk(player* player, enemy* enemy) {
	int attack = rand() % 3 + 1;

	switch (attack) {
	case 1: // 通常攻撃
		playerATK(player, enemy);
		break;
	case 2: // 回復呪文
		selectPlayer();
		playerCure(player, currentPlayer);
		break;
	case 3: // 防御力up呪文
		selectPlayer();
		playerDEFup(player, currentPlayer);
		break;

	}

}

// 遊び人の行動パターン
void Playful(player* player, enemy* enemy) {
	int attack = rand() % 10 + 1;

	switch (attack) {
	case 1:
	case 5:
	case 7: // 通常攻撃
		playerATK(player, enemy);
		break;
	case 2:
	case 6:
	case 10: // 回復呪文
		selectPlayer();
		playerCure(player, currentPlayer);

		break;
	case 3: // Pandora（発動率低め）
		playerPandora(player, enemy);
		break;
	case 4:
	case 8:
	case 9: // 火炎呪文
		playerFire(player, enemy);
		break;
	}

}

// 起きるかどうか判定
void GetUp(player* player) {

	int sleepRate = rand() % 100;

	if (sleep->POW > sleepRate) {
		player->sleep = 0;
		mvprintw(xa, ya, " %s(%s) は目を覚ました！", player->NAME, player->JOB);
		xa = xa + 2;
	}
	else {
		player->sleep = 1;
		mvprintw(xa, ya, " %s(%s) は眠っている...", player->NAME, player->JOB);
		xa = xa + 2;
	}

}

// 味方の行動処理
void playerTurn(player* player, enemy* enemy) {
	DEAD(player); // 死亡判定

	if (player->dead == 0) {
		if (player->sleep == 1) { // 寝てたら起きる判定
			GetUp(player);
		}
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
