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