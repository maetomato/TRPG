#pragma once

void enemy1States(enemy* enemy) { // �U���A�X�s�[�h�^�B�����̓t�@�C�A�̂݁B

	sprintf_s(enemy->NAME, "MoonBeast");//���[���r�[�X�g
	enemy->HP = 100;
	enemy->MP = 20;
	enemy->DEX = rand() % 10 + 18;
	enemy->POW = rand() % 20 + 30;
	enemy->DEF = rand() % 20 + 10;

	enemy->iniHP = enemy->HP;
	enemy->iniMP = enemy->MP;
	enemy->iniPOW = enemy->POW;
	enemy->iniDEF = enemy->DEF;

	spell enemy = *fire;
}

void enemy2States() { //�h��^�B�����̓L���A�ƃf�B�t�F���X�A�b�v�B
	sprintf_s(enemy2->NAME, "Y=golonac"); //�C�S���[�i�N
	enemy2->HP = 100;
	enemy2->MP = 50;
	enemy2->DEX = rand() % 10 + 3;
	enemy2->POW = rand() % 20 + 30;
	enemy2->DEF = rand() % 20 + 30;

	enemy2->iniHP = enemy2->HP;
	enemy2->iniMP = enemy2->MP;
	enemy2->iniPOW = enemy2->POW;
	enemy2->iniDEF = enemy2->DEF;

	spell enemy2[2] = { *cure, *DEFup }; // ���ꂶ�Ⴂ����C������Dswitch���ł��
}

void enemy3States() { //���@�^�B�����̓G�N�X�v���[�W�����ƃL���A�A�X���[�v�B

	sprintf_s(enemy3->NAME, "Nyarlathotep"); //�j�������g�z�e�v
	enemy3->HP = 100;
	enemy3->MP = 100;
	enemy3->DEX = rand() % 10 + 10;
	enemy3->POW = rand() % 10 + 30;
	enemy3->DEF = rand() % 10 + 50;

	enemy3->iniHP = enemy3->HP;
	enemy3->iniMP = enemy3->MP;
	enemy3->iniPOW = enemy3->POW;
	enemy3->iniDEF = enemy3->DEF;

	spell enemy3[3] = { *explosion, *cure, *sleep }; // ���ꂶ�Ⴂ����C������Dswitch���ł��
}