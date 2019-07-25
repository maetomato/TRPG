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

extern int nextBattle = 1; // ���݂̃o�g�����ێ�
extern int plusDamage = 0; // �_���[�W����(-5 �` +5)
extern int turn = 1; // ���݂̃^�[������ێ�

extern int xa = 2; // command�̏c
extern int ya = 5; // command�̉�

extern int n = 100;  //x enemy �D���ɂ������Ă�����
extern int m = 40;  //y enemy �D���ɂ������Ă�����

extern int a = 0;
extern int i = 0;  //x player ������Ȃ�
extern int j = 0;  //y player ������Ȃ�

extern int init_dot_x = 130;
extern int init_dot_y = 40;
extern int dot_x = 130;
extern int dot_y = 40;
