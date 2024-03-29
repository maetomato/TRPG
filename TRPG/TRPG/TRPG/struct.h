#pragma once

#define BUFFSIZE 124

struct player {
	//const char* NAME[15];	//名前
	//const char* JOB[15];	//職業
	char NAME[BUFFSIZE];	//名前
	char JOB[BUFFSIZE];	//職業
	int HP;            //体力
	int iniHP;
	int iniPandoraHP;
	int MP;
	int iniMP;        //魔力
	int DEX;        //俊敏
	int POW;        //腕力
	int iniPOW;
	int DEF;        //防御
	int iniDEF;
	int startPOWupTurn;
	int finishPOWupTurn;
	int startDEFupTurn;
	int finishDEFupTurn;
	int playSpell;
	int sleep = 0;    //眠り状態の切り替え
	int dead = 0;    //脂肪状態の判定
};

struct enemy {
	//const char NAME[BUFFSIZE];
	char NAME[BUFFSIZE];
	int HP;
	int iniHP;
	int MP;
	int iniMP;
	int DEX;
	int POW;
	int iniPOW;
	int DEF;
	int iniDEF;
	int startPOWupTurn;
	int finishPOWupTurn;
	int startDEFupTurn;
	int finishDEFupTurn;
	int playSpell;
};

struct spell {
	//const char* NAME[15];
	char NAME[BUFFSIZE];
	int MP;
	int POW;
};

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

extern int nextBattle = 1; // 現在のバトル数保持
extern int plusDamage = 0; // ダメージ乱数(-5 〜 +5)
extern int turn = 1; // 現在のターン数を保持

extern int xa = 2; // commandの縦
extern int ya = 5; // commandの横

extern int n = 100;  //x enemy 好きにいじっていいよ
extern int m = 40;  //y enemy 好きにいじっていいよ

extern int a = 0;
extern int i = 0;  //x player いじらない
extern int j = 0;  //y player いじらない

extern int init_dot_x = 130;
extern int init_dot_y = 40;
extern int dot_x = 130;
extern int dot_y = 40;
