// TRPG.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <curses.h>
#include <String.h>
#include <math.h>
#include <time.h>
#include "struct.h"
#include "job.h"
#include "enemy.h"
#include "player.h"
#include "spell.h"
#include "enemySpell.h"
#include "playerSpell.h"
#include "battle.h"
#include "initialSetting.h"

#define CHARBUFF 124
#define BUFFSIZE 1024

void getGurrentDirectory(char* currentDirectory);
void InPut();
void OutPut();

const char* p1job;
const char* p2job;
const char* p3job;
const char* p1name;
const char* p2name;
const char* p3name;

int main() {
	srand((unsigned)time(NULL));

	InPut();
	initscr();

	// 色の準備
	start_color();

	// プレイヤー初期設定
	playerInit();


	// 魔法初期設定
	spellInit();

	// 敵の初期設定
	enemy1States();
	enemy2States();
	enemy3States();

	if (nextBattle == 1) { // Battle1
		currentEnemy = enemy1;
		mvaddstr(0, 0, "--BATTLE1--");
		battleEnemy1();
	}
	erase();
	if (nextBattle == 2) { // Battle2
		currentEnemy = enemy2;
		mvaddstr(0, 0, "--BATTLE2--");
		battleEnemy1();
	}
	erase();
	if (nextBattle == 3) { // Battle3
		currentEnemy = enemy3;
		mvaddstr(0, 0, "--BATTLE3--");
		battleEnemy1();
	}

	OutPut();

	while (1);
	return 0;
}

void getGurrentDirectory(char* currentDirectory) {
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}

// iniファイル読み込み
void InPut() {
	char currentDirectory[CHARBUFF];
	getGurrentDirectory(currentDirectory);
	char section[CHARBUFF];
	sprintf_s(section, "player1");
	char keyWord[CHARBUFF];
	sprintf_s(keyWord, "プレーヤー名");
	char keyJob[CHARBUFF];
	sprintf_s(keyJob, "職業");
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\setting.ini", currentDirectory);
	GetPrivateProfileString(section, keyWord, "none", keyWord, CHARBUFF, settingFile);
	GetPrivateProfileString(section, keyJob, "none", keyJob, CHARBUFF, settingFile);
	p1job = keyJob;
	p1name = keyWord;
	sprintf_s(player1->JOB, keyJob);
	sprintf_s(player1->NAME, keyWord);

	char section2[CHARBUFF];
	sprintf_s(section2, "player2");
	char keyWord2[CHARBUFF];
	sprintf_s(keyWord2, "プレーヤー名");
	char keyJob2[CHARBUFF];
	sprintf_s(keyJob2, "職業");
	GetPrivateProfileString(section2, keyWord2, "none", keyWord2, CHARBUFF, settingFile);
	GetPrivateProfileString(section2, keyJob2, "none", keyJob2, CHARBUFF, settingFile);
	p2job = keyJob2;
	p2name = keyWord2;
	sprintf_s(player2->JOB, keyJob2);
	sprintf_s(player2->NAME, keyWord2);

	char section3[CHARBUFF];
	sprintf_s(section3, "player3");
	char keyWord3[CHARBUFF];
	sprintf_s(keyWord3, "プレーヤー名");
	char keyJob3[CHARBUFF];
	sprintf_s(keyJob3, "職業");
	GetPrivateProfileString(section3, keyWord3, "none", keyWord3, CHARBUFF, settingFile);
	GetPrivateProfileString(section3, keyJob3, "none", keyJob3, CHARBUFF, settingFile);
	p3job = keyJob3;
	p3name = keyWord3;
	sprintf_s(player3->JOB, keyJob3);
	sprintf_s(player3->NAME, keyWord3);

}

// 結果出力
void OutPut() {

	FILE* fp;

	char s[BUFFSIZE];
	errno_t error;
	error = fopen_s(&fp, "結果.txt", "w");
	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {
		if (enemy1->HP > 0) {
			sprintf_s(s, "[結果]\nBattle1で敗北\n");
			fputs(s, fp);
		}
		else if (enemy2->HP > 0) {
			sprintf_s(s, "[結果]\nBattle2で敗北\n");
			fputs(s, fp);
		}
		else if (enemy3->HP > 0) {
			sprintf_s(s, "[結果]\nBattle3で敗北\n");
			fputs(s, fp);
		}
		else {
			sprintf_s(s, "[結果]\n全ての敵を倒した！\n");
			fputs(s, fp);
		}

		fputs("\n<Player1>\n", fp);
		sprintf_s(s, "名前:%s\n職業:%s\n", player1->NAME, player1->JOB);
		fputs(s, fp);
		sprintf_s(s, "残りHP:%d\n", player1->HP);
		fputs(s, fp);

		fputs("\n<Player2>\n", fp);
		sprintf_s(s, "名前:%s\n職業:%s\n", player2->NAME, player2->JOB);
		fputs(s, fp);
		sprintf_s(s, "残りHP:%d\n", player2->HP);
		fputs(s, fp);

		fputs("\n<Player3>\n", fp);
		sprintf_s(s, "名前:%s\n職業:%s\n", player3->NAME, player3->JOB);
		fputs(s, fp);
		sprintf_s(s, "残りHP:%d\n", player3->HP);
		fputs(s, fp);

		fclose(fp);
	}

}
