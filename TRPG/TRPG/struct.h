#pragma once
#define BUFFSIZE 124

struct player {
	//const char* NAME[15];	//���O
	//const char* JOB[15];	//�E��
	char NAME[BUFFSIZE];	//���O
	char JOB[BUFFSIZE];	//�E��
	int HP;            //�̗�
	int iniHP;
	int iniPandoraHP;
	int MP;
	int iniMP;        //����
	int DEX;        //�r�q
	int POW;        //�r��
	int iniPOW;
	int DEF;        //�h��
	int iniDEF;
	int startPOWupTurn;
	int finishPOWupTurn;
	int startDEFupTurn;
	int finishDEFupTurn;
	int playSpell;
	int sleep = 0;    //�����Ԃ̐؂�ւ�
	int dead = 0;    //���b��Ԃ̔���
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