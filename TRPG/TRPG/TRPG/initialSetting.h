#pragma once
#include "spell.h"
#include "player_PixelArt.h"
#include "job.h"

// �e���@�̏����ݒ�
void spellInit() {
	FIRE();
	EXPLOSION();
	CURE();
	ATKUP();
	DEFUP();
	SLEEP();
	PANDORA();
}

void playerInit() {
	// player1�̖�E
	if (strcmp(player1->JOB, "��m") == 0) {
		soldier(player1);
		senshi();
	}
	else if (strcmp(player1->JOB, "���@�g��") == 0) {
		wizard(player1);
		mahoutukai();
	}
	else if (strcmp(player1->JOB, "�m��") == 0) {
		monk(player1);
		souryo();
	}
	else if (strcmp(player1->JOB, "������") == 0) {
		martial(player1);
		butouka();
	}
	else if (strcmp(player1->JOB, "�V�ѐl") == 0) {
		playful(player1);
		asobinin();
	}
	dot_x = dot_x + 30;

	// player2�̖�E
	if (strcmp(player2->JOB, "��m") == 0) {
		soldier(player2);
		senshi();
	}
	else if (strcmp(player2->JOB, "���@�g��") == 0) {
		wizard(player2);
		mahoutukai();
	}
	else if (strcmp(player2->JOB, "�m��") == 0) {
		monk(player2);
		souryo();
	}
	else if (strcmp(player2->JOB, "������") == 0) {
		martial(player2);
		butouka();
	}
	else if (strcmp(player2->JOB, "�V�ѐl") == 0) {
		playful(player2);
		asobinin();
	}
	dot_x = dot_x + 30;

	// player3�̖�E
	if (strcmp(player3->JOB, "��m") == 0) {
		soldier(player3);
		senshi();
	}
	else if (strcmp(player3->JOB, "���@�g��") == 0) {
		wizard(player3);
		mahoutukai();
	}
	else if (strcmp(player3->JOB, "�m��") == 0) {
		monk(player3);
		souryo();
	}
	else if (strcmp(player3->JOB, "������") == 0) {
		martial(player3);
		butouka();
	}
	else if (strcmp(player3->JOB, "�V�ѐl") == 0) {
		playful(player3);
		asobinin();
	}
	dot_x = dot_x + 30;
}
