#pragma once

#define BUFFSIZE 124

struct player {
	//const char* NAME[15];	//–¼‘O
	//const char* JOB[15];	//E‹Æ
	char NAME[BUFFSIZE];	//–¼‘O
	char JOB[BUFFSIZE];	//E‹Æ
	int HP;            //‘Ì—Í
	int iniHP;
	int iniPandoraHP;
	int MP;
	int iniMP;        //–‚—Í
	int DEX;        //r•q
	int POW;        //˜r—Í
	int iniPOW;
	int DEF;        //–hŒä
	int iniDEF;
	int startPOWupTurn;
	int finishPOWupTurn;
	int startDEFupTurn;
	int finishDEFupTurn;
	int playSpell;
	int sleep = 0;    //–°‚èó‘Ô‚ÌØ‚è‘Ö‚¦
	int dead = 0;    //‰–bó‘Ô‚Ì”»’è
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

extern int nextBattle = 1; // Œ»İ‚Ìƒoƒgƒ‹”•Û
extern int plusDamage = 0; // ƒ_ƒ[ƒW—”(-5 ` +5)
extern int turn = 1; // Œ»İ‚Ìƒ^[ƒ“”‚ğ•Û

extern int xa = 2; // command‚Ìc
extern int ya = 5; // command‚Ì‰¡

extern int n = 100;  //x enemy D‚«‚É‚¢‚¶‚Á‚Ä‚¢‚¢‚æ
extern int m = 40;  //y enemy D‚«‚É‚¢‚¶‚Á‚Ä‚¢‚¢‚æ

extern int a = 0;
extern int i = 0;  //x player ‚¢‚¶‚ç‚È‚¢
extern int j = 0;  //y player ‚¢‚¶‚ç‚È‚¢

extern int init_dot_x = 130;
extern int init_dot_y = 40;
extern int dot_x = 130;
extern int dot_y = 40;
