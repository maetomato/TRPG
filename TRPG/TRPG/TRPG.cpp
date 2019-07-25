// TRPG.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//



// いーごさん（敵2）が固すぎて永遠に終わらん可能性がある．


//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <curses.h>
#include "struct.h"
#include "proto.h"
#include "job.h"
#include "enemy.h"
#include "spell.h"
#include "playerAction.h"
#include "enemyAction.h"
#include "battle.h"
#include "enemyPicture.h"
#include "playerPicture.h"
#include "IO.h"
#include "color.h"

#define CHARBUFF 124
#define OUTPUTBUFF 1024

player* player1 = new player;
player* player2 = new player;
player* player3 = new player;
player* currentPlayer = NULL;

enemy* enemy1 = new enemy;
enemy* enemy2 = new enemy;
enemy* enemy3 = new enemy;
enemy* currentEnemy = NULL;

spell* fire = new spell;
spell* explosion = new spell;
spell* cure = new spell;
spell* POWup = new spell;
spell* DEFup = new spell;
spell* sleep = new spell;
spell* pandora = new spell;

int a = 0;
int i = 0;  //x player いじらない
int j = 0;  //y player いじらない
int n = 0;  //x enemy 好きにいじっていいよ
int m = 0;  //y enemy 好きにいじっていいよ


int nextBattle = 1; // 現在のバトル数保持
int plusDamage = 0; // ダメージ補正
int DEXOrder[4] = { player1->DEX, player2->DEX, player3->DEX, 0 };
int attackOrder[4] = { 1,2,3,0 };
int turn = 1;


int main() {
	srand((unsigned)time(NULL));

	// プレイヤーの役職仮設定
	wizard(player1);
	martial(player2);
	soldier(player3);

	// 魔法初期設定
	spellInit();

	// 敵の初期設定
	enemy1States();
	enemy2States();
	enemy3States();

	// プレイヤー名仮設定
	sprintf_s(player1->NAME, "player1");
	sprintf_s(player2->NAME, "player2");
	sprintf_s(player3->NAME, "player3");

	//fprintf_s(stdout, "\n%d,%d,%d\n", player1->iniHP, player2->iniHP, player3->iniHP);

	if (nextBattle == 1) {
		currentEnemy = enemy1;
		fprintf_s(stdout, "\n--BATTLE1--\n");
		battleEnemy1();
	}
	if (nextBattle == 2) {
		currentEnemy = enemy2;
		fprintf_s(stdout, "\n--BATTLE2--\n");
		battleEnemy1();
	}
	if (nextBattle == 3) {
		currentEnemy = enemy3;
		fprintf_s(stdout, "\n--BATTLE3--\n");
		battleEnemy1();
	}

	while (1);
	return 0;
}

