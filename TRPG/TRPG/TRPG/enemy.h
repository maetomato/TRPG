#pragma once
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "enemySpell.h"
#include "battle.h"

// 敵1の設定
void enemy1States() { // 攻撃、スピード型。呪文はファイアのみ。
	// 能力値など設定
	sprintf_s(enemy1->NAME, "ドラキー");
	enemy1->HP = 100;
	enemy1->MP = 20;
	enemy1->DEX = rand() % 10 + 18;
	enemy1->POW = rand() % 20 + 30;
	enemy1->DEF = rand() % 20 + 10;
	// 現在の能力の最大値
	enemy1->iniHP = enemy1->HP;
	enemy1->iniMP = enemy1->MP;
	enemy1->iniPOW = enemy1->POW;
	enemy1->iniDEF = enemy1->DEF;

}

// 敵2の設定
void enemy2States() { //防御型。呪文はキュアとディフェンスアップ。
	// 能力値など設定
	sprintf_s(enemy2->NAME, "スライム"); 
	enemy2->HP = 100;
	enemy2->MP = 50;
	enemy2->DEX = rand() % 10 + 3;
	enemy2->POW = rand() % 20 + 30;
	enemy2->DEF = rand() % 20 + 20;
	// 現在の能力の最大値
	enemy2->iniHP = enemy2->HP;
	enemy2->iniMP = enemy2->MP;
	enemy2->iniPOW = enemy2->POW;
	enemy2->iniDEF = enemy2->DEF;

}

// 敵3の設定
void enemy3States() { //魔法型。呪文はエクスプロージョンとキュア、スリープ。
	// 能力など設定
	sprintf_s(enemy3->NAME, "ワドルディ"); 
	enemy3->HP = 100;
	enemy3->MP = 100;
	enemy3->DEX = rand() % 10 + 10;
	enemy3->POW = rand() % 10 + 30;
	enemy3->DEF = rand() % 10 + 30;
	// 現在の能力の最大値
	enemy3->iniHP = enemy3->HP;
	enemy3->iniMP = enemy3->MP;
	enemy3->iniPOW = enemy3->POW;
	enemy3->iniDEF = enemy3->DEF;

}
