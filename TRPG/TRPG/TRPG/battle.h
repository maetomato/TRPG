#pragma once
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "struct.h"
#include "enemy.h"
#include "player.h"
#include "enemy_pixelArt.h"
#include "player_pixelArt.h"

// �X�e�[�^�X�\��
void statusPrint() {
	switch (nextBattle) {
	case 1:
		mvprintw(28, 165, "%s ", enemy1->NAME);
		mvprintw(30, 165, "HP  %d ", enemy1->HP);
		break;
	case 2:
		mvprintw(28, 165, "%s ", enemy2->NAME);
		mvprintw(30, 165, "HP  %d ", enemy2->HP);
		break;
	case 3:
		mvprintw(28, 165, "%s ", enemy3->NAME);
		mvprintw(30, 165, "HP  %d ", enemy3->HP);
		break;
	}
	mvprintw(60, 135, "���O  %s  �E��  %s", player1->NAME,player1->JOB);
	mvprintw(60, 165, "���O  %s  �E��  %s", player2->NAME, player2->JOB);
	mvprintw(60, 195, "���O  %s  �E��  %s", player3->NAME, player3->JOB);
	mvprintw(62, 135, "HP  %d ", player1->HP);
	mvprintw(62, 165, "HP  %d ", player2->HP);
	mvprintw(62, 195, "HP  %d ", player3->HP);
	mvprintw(64, 135, "MP  %d ", player1->MP);
	mvprintw(64, 165, "MP  %d ", player2->MP);
	mvprintw(64, 195, "MP  %d ", player3->MP);
	if (player1->sleep == 0 && player1->dead == 0) {
		mvprintw(66, 135, "���  ����");
	}
	if (player2->sleep == 0 && player2->dead == 0) {
		mvprintw(66, 165, "���  ����");
	}
	if (player3->sleep == 0 && player3->dead == 0) {
		mvprintw(66, 195, "���  ����");
	}
	if (player1->sleep == 1 && player1->dead == 0) {
		mvprintw(66, 135, "���  ����");
	}
	if (player2->sleep == 1 && player2->dead == 0) {
		mvprintw(66, 165, "���  ����");
	}
	if (player3->sleep == 1 && player3->dead == 0) {
		mvprintw(66, 195, "���  ����");
	}
	if (player1->sleep == 0 && player1->dead == 1 || player1->sleep == 1 && player1->dead == 1) {
		mvprintw(66, 135, "���  ���S");
	}
	if (player2->sleep == 0 && player2->dead == 1 || player2->sleep == 1 && player2->dead == 1) {
		mvprintw(66, 165, "���  ���S");
	}
	if (player3->sleep == 0 && player3->dead == 1 || player3->sleep == 1 && player3->dead == 1) {
		mvprintw(66, 195, "���  ���S");
	}

}

// �G:���[���r�[�X�g�̍s���p�^�[��
void MoonBeast(enemy* enemy) {
	int attack = rand() % 2 + 1;

	switch (attack) {
	case 1: // �ʏ�U��
		selectPlayer();
		enemyATK(enemy, currentPlayer);
		break;
	case 2: // �Ή�����
		selectPlayer();
		enemyFire(enemy, currentPlayer);
		break;

	}

}

// �G:�C�S���[�i�N�̍s���p�^�[��
void Ygolonac(enemy* enemy) {
	int attack = rand() % 3 + 1;
	switch (attack) {
	case 1: // �ʏ�U��
		selectPlayer();
		enemyATK(enemy, currentPlayer);
		break;
	case 2: // �񕜎���
		enemyCure(enemy);
		break;
	case 3: // �h���up����
		enemyDEFup(enemy);
		break;
	}
}

// �G:�j�������g�z�e�v�̍s���p�^�[��
void Nyarlathotep(enemy* enemy) {
	if (turn == 1) { // ����s����sleep�����Ŋm��
		enemySleep(enemy);
	}
	else {
		int attack = rand() % 4 + 1;
		switch (attack) {
		case 1: // �ʏ�U��
			selectPlayer();
			enemyATK(enemy, currentPlayer);
			break;
		case 2: // ��������
			enemyExplosion();
			break;
		case 3: // �񕜎���
			enemyCure(enemy);
			break;
		case 4: // �Ö�����
			enemySleep(enemy);
		}
	}
}

// �G�Ƃ̐퓬����
void battleEnemy1() {
	turn = 1;

	while (1) {
		dot_x = init_dot_x;
		dot_y = init_dot_y;
		printDot();

		statusPrint();

		dot_x = 160;
		dot_y = 10;
		switch (nextBattle) {
		case 1:
			mvaddstr(0, 0, "--BATTLE1--");
			doraki();
			break;
		case  2:
			mvaddstr(0, 0, "--BATTLE2--");
			suraimu();
			break;
		case 3:
			mvaddstr(0, 0, "--BATTLE3--");
			boss();
			break;
		}

		if (turn == 1) {
			mvprintw(xa, ya, "%s�����ꂽ�I", currentEnemy->NAME);
			xa = xa + 2;
		}

		mvprintw(xa, ya, "[%d�^�[����]", turn);
		xa = xa + 2;
		if (turn == 1) { // �퓬�̏��߂ɍs����������
			DexOrder(currentEnemy);
		}
		for (int i = 0; i < 4; i++) {
			switch (attackOrder[i]) {
			case 1: // player1�̍s��
				mvprintw(xa, ya, "== %s�̍s�� ==", player1->NAME);
				xa = xa + 2;
				playerTurn(player1, currentEnemy);
				break;
			case 2: // player2�̍s��
				mvprintw(xa, ya, "== %s�̍s�� ==", player2->NAME);
				xa = xa + 2;
				playerTurn(player2, currentEnemy);
				break;
			case 3: // player3�̍s��
				mvprintw(xa, ya, "== %s�̍s�� ==", player3->NAME);
				xa = xa + 2;
				playerTurn(player3, currentEnemy);
				break;
			case 11: // �G�̍s��
				switch (nextBattle) {
				case 1:
					mvprintw(xa, ya, "== %s�̍s�� ==", enemy1->NAME);
					xa = xa + 2;
					MoonBeast(enemy1);
					break;
				case 2:
					mvprintw(xa, ya, "== %s�̍s�� ==", enemy2->NAME);
					xa = xa + 2;
					Ygolonac(enemy2);
					break;
				case 3:
					mvprintw(xa, ya, "== %s�̍s�� ==", enemy3->NAME);
					xa = xa + 2;
					Nyarlathotep(enemy3);
					break;
				}
				break;
			}
			refresh();
		}

		// HP��0�����Ȃ�0�ɐݒ�
		for (int h = 0; h < 3; h++) {
			if (player1->HP < 0) {
				player1->HP = 0;
			}
			if (player2->HP < 0) {
				player2->HP = 0;
			}
			if (player3->HP < 0) {
				player3->HP = 0;
			}

		}


		refresh();
		xa = xa + 2;
		// �c��HP�\��
		mvaddstr(xa, ya, "�c��HP");
		xa = xa + 2;
		mvprintw(xa, ya, "%s:%d, %s:%d, %s:%d", player1->NAME, player1->HP, player2->NAME, player2->HP, player3->NAME, player3->HP);
		xa = xa + 2;

		// �c��MP�\��
		mvaddstr(xa, ya, "�c��MP");
		xa = xa + 2;
		mvprintw(xa, ya, "%s:%d, %s:%d, %s:%d", player1->NAME, player1->MP, player2->NAME, player2->MP, player3->NAME, player3->MP);
		xa = xa + 3;

		// �G�̐�������
		if ((currentEnemy->HP) <= 0) {
			currentEnemy->HP = 0;
			statusPrint();
			mvprintw(xa, ya, "%s�̎c��HP:%d", currentEnemy->NAME, currentEnemy->HP);
			xa = xa + 2;
			mvprintw(xa, ya, "%s��|�����I", currentEnemy->NAME);
			xa = xa + 4;
			nextBattle++; // ���̃o�g����
			if (nextBattle == 4) {
				xa = xa + 2;
				mvaddstr(xa, ya, "--CLEAR--");
				statusPrint();
				xa = xa + 2;
				refresh();
				break;
			}

			// �G��|����,
			// �C��҂�HP�̂ݏ����l�̔���(50)��,����ȊO�͑S�񕜂ŕ���
			// �����҂͔\�͒l�������l�ɖ߂�
			else {
				napms(1000);
				for (int i = 0; i < 3; i++) {
					switch (i) {
					case 0:
						currentPlayer = player1;
						break;
					case 1:
						currentPlayer = player2;
						break;
					case 2:
						currentPlayer = player3;
						break;
					}
					if (currentPlayer->dead == 1) {
						currentPlayer->dead = 0;
						mvprintw(xa, ya, "%s�͕��������I", currentPlayer->NAME);
						xa = xa + 2;
						currentPlayer->HP = currentPlayer->iniHP / 2;
						currentPlayer->MP = currentPlayer->iniMP;
						currentPlayer->POW = currentPlayer->iniPOW;
						currentPlayer->DEF = currentPlayer->iniDEF;
					}
					else {
						currentPlayer->HP = currentPlayer->iniHP;
						currentPlayer->MP = currentPlayer->iniMP;
						currentPlayer->POW = currentPlayer->iniPOW;
						currentPlayer->DEF = currentPlayer->iniDEF;
					}

				}
				refresh();
				napms(2000);
				xa = 2;
				break;
			}
		}
		// �G�̎c��HP�\��
		else {
			mvprintw(xa, ya, "%s�̎c��HP:%d", currentEnemy->NAME, currentEnemy->HP);
			xa = xa + 2;
		}

		// �p�[�e�B�S��
		if ((player1->dead == 1) && (player2->dead == 1) && (player3->dead == 1)) {
			xa = xa + 2;
			mvaddstr(xa, ya, "�p�[�e�B�͑S�ł���......");
			xa++;
			mvaddstr(xa, ya, "==GAME OVER==");
			statusPrint();
			refresh();
			break;
		}

		turn++;
		xa = 2;

		refresh();
		napms(1500);
		erase();

	}

}
