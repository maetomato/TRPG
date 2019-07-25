#pragma once
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "struct.h"
#include "playerSpell.h"
#include "battle.h"

extern int DEXOrder[4] = { player1->DEX, player2->DEX, player3->DEX, 0 }; // �s�������ёւ��p�z��
extern int attackOrder[4] = { 1,2,3,0 }; // �s������ێ��iDEX���傫�����j

// �ΏۑI��
// ���S���Ă���v���C���[���ΏۂƂȂ�Ȃ��悤�ɂ���
void selectPlayer() {
	int select1 = rand() % 3;
	int select2;
	if (select1 == 0) {
		if (player1->dead == 0) {
			currentPlayer = player1;
		}
		else if (player1->dead == 1) {
			select2 = rand() % 2;
			if (select2 == 0) {
				if (player2->dead == 0) {
					currentPlayer = player2;
				}
				else if (player2->dead == 1) {
					currentPlayer = player3;
				}
			}
			else if (select2 == 1) {
				if (player3->dead == 0) {
					currentPlayer = player3;
				}
				else if (player3->dead == 1) {
					currentPlayer = player2;
				}
			}
		}
	}
	else if (select1 == 1) {
		if (player2->dead == 0) {
			currentPlayer = player2;
		}
		else if (player2->dead == 1) {
			select2 = rand() % 2;
			if (select2 == 0) {
				if (player1->dead == 0) {
					currentPlayer = player1;
				}
				else if (player1->dead == 1) {
					currentPlayer = player3;
				}
			}
			else if (select2 == 1) {
				if (player3->dead == 0) {
					currentPlayer = player3;
				}
				else if (player3->dead == 1) {
					currentPlayer = player1;
				}
			}
		}
	}
	if (select1 == 2) {
		if (player3->dead == 0) {
			currentPlayer = player3;
		}
		else if (player3->dead == 1) {
			select2 = rand() % 2;
			if (select2 == 0) {
				if (player1->dead == 0) {
					currentPlayer = player1;
				}
				else if (player1->dead == 1) {
					currentPlayer = player2;
				}
			}
			else if (select2 == 1) {
				if (player2->dead == 0) {
					currentPlayer = player2;
				}
				else if (player2->dead == 1) {
					currentPlayer = player1;
				}
			}
		}
	}
}

// ���S����
void DEAD(player* player) {
	if (player->HP <= 0) {
		player->dead = 1;
		mvprintw(xa, ya, " %s(%s) �͗͐s���Ă���...", player->NAME, player->JOB);
		xa = xa + 2;
	}

}

// �s�������ёւ��iDEX���傫�����j
void DexOrder(enemy* enemy) {
	DEXOrder[0] = player1->DEX;
	DEXOrder[1] = player2->DEX;
	DEXOrder[2] = player3->DEX;
	DEXOrder[3] = enemy->DEX;

	attackOrder[0] = 1;
	attackOrder[1] = 2;
	attackOrder[2] = 3;
	attackOrder[3] = 11;
	for (int i = 0; i < 4; i++) {
		int DEXTmp = 0;
		int attackTmp = 0;
		for (int j = i + 1; j < 4; j++) {
			if (DEXOrder[i] <= DEXOrder[j]) {
				DEXTmp = DEXOrder[j];
				DEXOrder[j] = DEXOrder[i];
				DEXOrder[i] = DEXTmp;
				attackTmp = attackOrder[j];
				attackOrder[j] = attackOrder[i];
				attackOrder[i] = attackTmp;
			}
		}
	}

}

// ��m�̍s���p�^�[��
void Solder(player* player, enemy* enemy) {
	playerATK(player, enemy); // �ʏ�U��

}

// �����Ƃ̍s���p�^�[��
void Martial(player* player, enemy* enemy) {
	playerATK(player, enemy); // �ʏ�U��

}

// ���@�g���̍s���p�^�[��
void Wizzard(player* player, enemy* enemy) {
	int attack = rand() % 3 + 1;

	switch (attack) {
	case 1: // �ʏ�U��
		playerATK(player, enemy);
		break;
	case 2: // �Ή�����
		playerFire(player, enemy);
		break;
	case 3: // �U����up����
		selectPlayer();
		playerPOWup(player, currentPlayer);
		break;

	}
}

// �m���̍s���p�^�[��
void Monk(player* player, enemy* enemy) {
	int attack = rand() % 3 + 1;

	switch (attack) {
	case 1: // �ʏ�U��
		playerATK(player, enemy);
		break;
	case 2: // �񕜎���
		selectPlayer();
		playerCure(player, currentPlayer);
		break;
	case 3: // �h���up����
		selectPlayer();
		playerDEFup(player, currentPlayer);
		break;

	}

}

// �V�ѐl�̍s���p�^�[��
void Playful(player* player, enemy* enemy) {
	int attack = rand() % 10 + 1;

	switch (attack) {
	case 1:
	case 5:
	case 7: // �ʏ�U��
		playerATK(player, enemy);
		break;
	case 2:
	case 6:
	case 10: // �񕜎���
		selectPlayer();
		playerCure(player, currentPlayer);

		break;
	case 3: // Pandora�i��������߁j
		playerPandora(player, enemy);
		break;
	case 4:
	case 8:
	case 9: // �Ή�����
		playerFire(player, enemy);
		break;
	}

}

// �N���邩�ǂ�������
void GetUp(player* player) {

	int sleepRate = rand() % 100;

	if (sleep->POW > sleepRate) {
		player->sleep = 0;
		mvprintw(xa, ya, " %s(%s) �͖ڂ��o�܂����I", player->NAME, player->JOB);
		xa = xa + 2;
	}
	else {
		player->sleep = 1;
		mvprintw(xa, ya, " %s(%s) �͖����Ă���...", player->NAME, player->JOB);
		xa = xa + 2;
	}

}

// �����̍s������
void playerTurn(player* player, enemy* enemy) {
	DEAD(player); // ���S����

	if (player->dead == 0) {
		if (player->sleep == 1) { // �Q�Ă���N���锻��
			GetUp(player);
		}
		if (strcmp(player->JOB, "��m") == 0) {
			Solder(player, enemy);
		}
		else if (strcmp(player->JOB, "���@�g��") == 0) {
			Wizzard(player, enemy);
		}
		else if (strcmp(player->JOB, "�m��") == 0) {
			Monk(player, enemy);
		}
		else if (strcmp(player->JOB, "������") == 0) {
			Martial(player, enemy);
		}
		else if (strcmp(player->JOB, "�V�ѐl") == 0) {
			Playful(player, enemy);
		}
	}

}
