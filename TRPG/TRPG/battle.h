
// ���̃w�b�_�͐퓬�����ɂ����Ă̑I���⎀�S����Ȃǂ̊�b�I�ȃ��W�b�N���g�ݍ��܂�Ă���B

// ���S����
void DEAD(player* player) {
	if (player->HP <= 0) {
		player->dead = 1;
		fprintf_s(stdout, "\n %s(%s) �͗͐s���Ă���...\n", player->NAME, player->JOB);
	}

}

// �ΏۑI��
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

// ������Ԃ��痧�����郁�\�b�h
void GetUp(player* player) {
	int sleepRate = rand() % 100;
	if (sleep->POW > sleepRate) {
		player->sleep = 0;
		fprintf_s(stdout, " %s(%s) �͖ڂ��o�܂����I\n", player->NAME, player->JOB);
	}
	else {
		player->sleep = 1;
		fprintf_s(stdout, " %s(%s) �͖����Ă���...\n", player->NAME, player->JOB);
	}
}

// �U�������ёւ�
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

	for (int i = 0; i < 4; i++) {
		//fprintf_s(stdout, "%d,", DEXOrder[i]);
	}
	fprintf_s(stdout, "\n");
	for (int i = 0; i < 4; i++) {
		//fprintf_s(stdout, "%d,", attackOrder[i]);
	}


}

void battleEnemy1() {
	turn = 1;
	fprintf_s(stdout, "\n%s�����ꂽ�I\n", currentEnemy->NAME);
	while (1) {

		// �p�[�e�B�S��
		if ((player1->dead == 1) && (player2->dead == 1) && (player3->dead == 1)) {
			fprintf_s(stdout, "\n�p�[�e�B�͑S�ł���......\n");
			fprintf_s(stdout, "==GAME OVER==\n");
			break;
		}
		fprintf_s(stdout, "\n[%d�^�[����]\n", turn);


		if (turn == 1) {
			DexOrder(currentEnemy);
		}
		for (int i = 0; i < 4; i++) {
			fprintf_s(stdout, "\n[%d]\n", i);
			switch (attackOrder[i]) {
			case 1:
				playerTurn(player1, currentEnemy);
				break;
			case 2:
				playerTurn(player2, currentEnemy);
				break;
			case 3:
				playerTurn(player3, currentEnemy);
				break;
			case 11:
				switch (nextBattle) {
				case 1:
					MoonBeast(enemy1);
					break;
				case 2:
					// �C�S���[�i�N
					Ygolonac(enemy2);
					break;
				case 3:
					// �j�������g�z�e�v
					Nyarlathotep(enemy3, turn);
					break;
				}
				break;
			}
		}

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
		fprintf_s(stdout, "\n�c��HP\n");
		fprintf_s(stdout, "%s:%d, %s:%d, %s:%d\n", player1->NAME, player1->HP, player2->NAME, player2->HP, player3->NAME, player3->HP);
		fprintf_s(stdout, "%s:%d, %s:%d, %s:%d\n", player1->NAME, player1->dead, player2->NAME, player2->dead, player3->NAME, player3->dead);


		if ((currentEnemy->HP) <= 0) {
			currentEnemy->HP = 0;
			fprintf_s(stdout, "\n%s�̎c��HP:%d\n", currentEnemy->NAME, currentEnemy->HP);
			fprintf_s(stdout, "%s��|�����I\n", currentEnemy->NAME);
			nextBattle++;
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
					fprintf_s(stdout, "%s�͕��������I\n", currentPlayer->NAME);
					currentPlayer->HP = currentPlayer->iniHP / 2;
				}
				currentPlayer->MP = currentPlayer->iniMP;
				currentPlayer->POW = currentPlayer->iniPOW;
				currentPlayer->DEF = currentPlayer->iniDEF;
			}
			break;
		}
		else {
			fprintf_s(stdout, "\n%s�̎c��HP:%d\n", currentEnemy->NAME, currentEnemy->HP);
		}
		turn++;
	}

}