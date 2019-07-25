#pragma once
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "struct.h"
#include "enemy.h"
#include "player.h"
#include "enemy_pixelArt.h"
#include "player_pixelArt.h"

// ステータス表示
void statusPrint() {
	switch (nextBattle) {
	case 1:
		mvprintw(28, 165, "%s ", enemy1->NAME);
		mvprintw(30, 165, "HP  %d ", enemy1->HP);
		break;
	case 2:
		mvprintw(28, 165, "%s ", enemy2->NAME);
		mvprintw(30, 165, "HP  %d ", enemy2->HP);
		break;
	case 3:
		mvprintw(28, 165, "%s ", enemy3->NAME);
		mvprintw(30, 165, "HP  %d ", enemy3->HP);
		break;
	}
	mvprintw(60, 135, "名前  %s  職業  %s", player1->NAME,player1->JOB);
	mvprintw(60, 165, "名前  %s  職業  %s", player2->NAME, player2->JOB);
	mvprintw(60, 195, "名前  %s  職業  %s", player3->NAME, player3->JOB);
	mvprintw(62, 135, "HP  %d ", player1->HP);
	mvprintw(62, 165, "HP  %d ", player2->HP);
	mvprintw(62, 195, "HP  %d ", player3->HP);
	mvprintw(64, 135, "MP  %d ", player1->MP);
	mvprintw(64, 165, "MP  %d ", player2->MP);
	mvprintw(64, 195, "MP  %d ", player3->MP);
	if (player1->sleep == 0 && player1->dead == 0) {
		mvprintw(66, 135, "状態  正常");
	}
	if (player2->sleep == 0 && player2->dead == 0) {
		mvprintw(66, 165, "状態  正常");
	}
	if (player3->sleep == 0 && player3->dead == 0) {
		mvprintw(66, 195, "状態  正常");
	}
	if (player1->sleep == 1 && player1->dead == 0) {
		mvprintw(66, 135, "状態  睡眠");
	}
	if (player2->sleep == 1 && player2->dead == 0) {
		mvprintw(66, 165, "状態  睡眠");
	}
	if (player3->sleep == 1 && player3->dead == 0) {
		mvprintw(66, 195, "状態  睡眠");
	}
	if (player1->sleep == 0 && player1->dead == 1 || player1->sleep == 1 && player1->dead == 1) {
		mvprintw(66, 135, "状態  死亡");
	}
	if (player2->sleep == 0 && player2->dead == 1 || player2->sleep == 1 && player2->dead == 1) {
		mvprintw(66, 165, "状態  死亡");
	}
	if (player3->sleep == 0 && player3->dead == 1 || player3->sleep == 1 && player3->dead == 1) {
		mvprintw(66, 195, "状態  死亡");
	}

}

// 敵:ムーンビーストの行動パターン
void MoonBeast(enemy* enemy) {
	int attack = rand() % 2 + 1;

	switch (attack) {
	case 1: // 通常攻撃
		selectPlayer();
		enemyATK(enemy, currentPlayer);
		break;
	case 2: // 火炎呪文
		selectPlayer();
		enemyFire(enemy, currentPlayer);
		break;

	}

}

// 敵:イゴローナクの行動パターン
void Ygolonac(enemy* enemy) {
	int attack = rand() % 3 + 1;
	switch (attack) {
	case 1: // 通常攻撃
		selectPlayer();
		enemyATK(enemy, currentPlayer);
		break;
	case 2: // 回復呪文
		enemyCure(enemy);
		break;
	case 3: // 防御力up呪文
		enemyDEFup(enemy);
		break;
	}
}

// 敵:ニャルラトホテプの行動パターン
void Nyarlathotep(enemy* enemy) {
	if (turn == 1) { // 初回行動はsleep呪文で確定
		enemySleep(enemy);
	}
	else {
		int attack = rand() % 4 + 1;
		switch (attack) {
		case 1: // 通常攻撃
			selectPlayer();
			enemyATK(enemy, currentPlayer);
			break;
		case 2: // 爆発呪文
			enemyExplosion();
			break;
		case 3: // 回復呪文
			enemyCure(enemy);
			break;
		case 4: // 催眠呪文
			enemySleep(enemy);
		}
	}
}

// 敵との戦闘処理
void battleEnemy1() {
	turn = 1;

	while (1) {
		dot_x = init_dot_x;
		dot_y = init_dot_y;
		printDot();

		statusPrint();

		dot_x = 160;
		dot_y = 10;
		switch (nextBattle) {
		case 1:
			mvaddstr(0, 0, "--BATTLE1--");
			doraki();
			break;
		case  2:
			mvaddstr(0, 0, "--BATTLE2--");
			suraimu();
			break;
		case 3:
			mvaddstr(0, 0, "--BATTLE3--");
			boss();
			break;
		}

		if (turn == 1) {
			mvprintw(xa, ya, "%sが現れた！", currentEnemy->NAME);
			xa = xa + 2;
		}

		mvprintw(xa, ya, "[%dターン目]", turn);
		xa = xa + 2;
		if (turn == 1) { // 戦闘の初めに行動順を決定
			DexOrder(currentEnemy);
		}
		for (int i = 0; i < 4; i++) {
			switch (attackOrder[i]) {
			case 1: // player1の行動
				mvprintw(xa, ya, "== %sの行動 ==", player1->NAME);
				xa = xa + 2;
				playerTurn(player1, currentEnemy);
				break;
			case 2: // player2の行動
				mvprintw(xa, ya, "== %sの行動 ==", player2->NAME);
				xa = xa + 2;
				playerTurn(player2, currentEnemy);
				break;
			case 3: // player3の行動
				mvprintw(xa, ya, "== %sの行動 ==", player3->NAME);
				xa = xa + 2;
				playerTurn(player3, currentEnemy);
				break;
			case 11: // 敵の行動
				switch (nextBattle) {
				case 1:
					mvprintw(xa, ya, "== %sの行動 ==", enemy1->NAME);
					xa = xa + 2;
					MoonBeast(enemy1);
					break;
				case 2:
					mvprintw(xa, ya, "== %sの行動 ==", enemy2->NAME);
					xa = xa + 2;
					Ygolonac(enemy2);
					break;
				case 3:
					mvprintw(xa, ya, "== %sの行動 ==", enemy3->NAME);
					xa = xa + 2;
					Nyarlathotep(enemy3);
					break;
				}
				break;
			}
			refresh();
		}

		// HPが0未満なら0に設定
		for (int h = 0; h < 3; h++) {
			if (player1->HP < 0) {
				player1->HP = 0;
			}
			if (player2->HP < 0) {
				player2->HP = 0;
			}
			if (player3->HP < 0) {
				player3->HP = 0;
			}

		}


		refresh();
		xa = xa + 2;
		// 残りHP表示
		mvaddstr(xa, ya, "残りHP");
		xa = xa + 2;
		mvprintw(xa, ya, "%s:%d, %s:%d, %s:%d", player1->NAME, player1->HP, player2->NAME, player2->HP, player3->NAME, player3->HP);
		xa = xa + 2;

		// 残りMP表示
		mvaddstr(xa, ya, "残りMP");
		xa = xa + 2;
		mvprintw(xa, ya, "%s:%d, %s:%d, %s:%d", player1->NAME, player1->MP, player2->NAME, player2->MP, player3->NAME, player3->MP);
		xa = xa + 3;

		// 敵の生存判定
		if ((currentEnemy->HP) <= 0) {
			currentEnemy->HP = 0;
			statusPrint();
			mvprintw(xa, ya, "%sの残りHP:%d", currentEnemy->NAME, currentEnemy->HP);
			xa = xa + 2;
			mvprintw(xa, ya, "%sを倒した！", currentEnemy->NAME);
			xa = xa + 4;
			nextBattle++; // 次のバトルへ
			if (nextBattle == 4) {
				xa = xa + 2;
				mvaddstr(xa, ya, "--CLEAR--");
				statusPrint();
				xa = xa + 2;
				refresh();
				break;
			}

			// 敵を倒すと,
			// 気絶者はHPのみ初期値の半分(50)で,それ以外は全回復で復活
			// 生存者は能力値を初期値に戻す
			else {
				napms(1000);
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
					if (currentPlayer->dead == 1) {
						currentPlayer->dead = 0;
						mvprintw(xa, ya, "%sは復活した！", currentPlayer->NAME);
						xa = xa + 2;
						currentPlayer->HP = currentPlayer->iniHP / 2;
						currentPlayer->MP = currentPlayer->iniMP;
						currentPlayer->POW = currentPlayer->iniPOW;
						currentPlayer->DEF = currentPlayer->iniDEF;
					}
					else {
						currentPlayer->HP = currentPlayer->iniHP;
						currentPlayer->MP = currentPlayer->iniMP;
						currentPlayer->POW = currentPlayer->iniPOW;
						currentPlayer->DEF = currentPlayer->iniDEF;
					}

				}
				refresh();
				napms(2000);
				xa = 2;
				break;
			}
		}
		// 敵の残りHP表示
		else {
			mvprintw(xa, ya, "%sの残りHP:%d", currentEnemy->NAME, currentEnemy->HP);
			xa = xa + 2;
		}

		// パーティ全滅
		if ((player1->dead == 1) && (player2->dead == 1) && (player3->dead == 1)) {
			xa = xa + 2;
			mvaddstr(xa, ya, "パーティは全滅した......");
			xa++;
			mvaddstr(xa, ya, "==GAME OVER==");
			statusPrint();
			refresh();
			break;
		}

		turn++;
		xa = 2;

		refresh();
		napms(1500);
		erase();

	}

}
