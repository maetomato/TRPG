#pragma once
#include "spell.h"
#include "player_PixelArt.h"
#include "job.h"

// äeñÇñ@ÇÃèâä˙ê›íË
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
	// player1ÇÃñêE
	if (strcmp(player1->JOB, "êÌém") == 0) {
		soldier(player1);
		senshi();
	}
	else if (strcmp(player1->JOB, "ñÇñ@égÇ¢") == 0) {
		wizard(player1);
		mahoutukai();
	}
	else if (strcmp(player1->JOB, "ëmóµ") == 0) {
		monk(player1);
		souryo();
	}
	else if (strcmp(player1->JOB, "ïêì¨â∆") == 0) {
		martial(player1);
		butouka();
	}
	else if (strcmp(player1->JOB, "óVÇ—êl") == 0) {
		playful(player1);
		asobinin();
	}
	dot_x = dot_x + 30;

	// player2ÇÃñêE
	if (strcmp(player2->JOB, "êÌém") == 0) {
		soldier(player2);
		senshi();
	}
	else if (strcmp(player2->JOB, "ñÇñ@égÇ¢") == 0) {
		wizard(player2);
		mahoutukai();
	}
	else if (strcmp(player2->JOB, "ëmóµ") == 0) {
		monk(player2);
		souryo();
	}
	else if (strcmp(player2->JOB, "ïêì¨â∆") == 0) {
		martial(player2);
		butouka();
	}
	else if (strcmp(player2->JOB, "óVÇ—êl") == 0) {
		playful(player2);
		asobinin();
	}
	dot_x = dot_x + 30;

	// player3ÇÃñêE
	if (strcmp(player3->JOB, "êÌém") == 0) {
		soldier(player3);
		senshi();
	}
	else if (strcmp(player3->JOB, "ñÇñ@égÇ¢") == 0) {
		wizard(player3);
		mahoutukai();
	}
	else if (strcmp(player3->JOB, "ëmóµ") == 0) {
		monk(player3);
		souryo();
	}
	else if (strcmp(player3->JOB, "ïêì¨â∆") == 0) {
		martial(player3);
		butouka();
	}
	else if (strcmp(player3->JOB, "óVÇ—êl") == 0) {
		playful(player3);
		asobinin();
	}
	dot_x = dot_x + 30;
}
