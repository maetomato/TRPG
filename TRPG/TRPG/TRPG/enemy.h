#pragma once
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "enemySpell.h"
#include "battle.h"

// �G1�̐ݒ�
void enemy1States() { // �U���A�X�s�[�h�^�B�����̓t�@�C�A�̂݁B
	// �\�͒l�Ȃǐݒ�
	sprintf_s(enemy1->NAME, "�h���L�[");
	enemy1->HP = 100;
	enemy1->MP = 20;
	enemy1->DEX = rand() % 10 + 18;
	enemy1->POW = rand() % 20 + 30;
	enemy1->DEF = rand() % 20 + 10;
	// ���݂̔\�͂̍ő�l
	enemy1->iniHP = enemy1->HP;
	enemy1->iniMP = enemy1->MP;
	enemy1->iniPOW = enemy1->POW;
	enemy1->iniDEF = enemy1->DEF;

}

// �G2�̐ݒ�
void enemy2States() { //�h��^�B�����̓L���A�ƃf�B�t�F���X�A�b�v�B
	// �\�͒l�Ȃǐݒ�
	sprintf_s(enemy2->NAME, "�X���C��"); 
	enemy2->HP = 100;
	enemy2->MP = 50;
	enemy2->DEX = rand() % 10 + 3;
	enemy2->POW = rand() % 20 + 30;
	enemy2->DEF = rand() % 20 + 20;
	// ���݂̔\�͂̍ő�l
	enemy2->iniHP = enemy2->HP;
	enemy2->iniMP = enemy2->MP;
	enemy2->iniPOW = enemy2->POW;
	enemy2->iniDEF = enemy2->DEF;

}

// �G3�̐ݒ�
void enemy3States() { //���@�^�B�����̓G�N�X�v���[�W�����ƃL���A�A�X���[�v�B
	// �\�͂Ȃǐݒ�
	sprintf_s(enemy3->NAME, "���h���f�B"); 
	enemy3->HP = 100;
	enemy3->MP = 100;
	enemy3->DEX = rand() % 10 + 10;
	enemy3->POW = rand() % 10 + 30;
	enemy3->DEF = rand() % 10 + 30;
	// ���݂̔\�͂̍ő�l
	enemy3->iniHP = enemy3->HP;
	enemy3->iniMP = enemy3->MP;
	enemy3->iniPOW = enemy3->POW;
	enemy3->iniDEF = enemy3->DEF;

}
