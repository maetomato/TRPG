#pragma once

void enemyPlaySpell(enemy* enemy, spell* spell) {
	if (enemy->MP < spell->MP) {
		enemy->playSpell = 1;
		fprintf_s(stdout, "\n������MP������Ȃ������I\n");
	}
	else if (enemy->MP >= spell->MP) {
		enemy->playSpell = 0;
	}
}

// �G:�ʏ�U��
void enemyATK(enemy* enemy, player* player) { //�G�̒ʏ�U���A�Ώۂ�I��
	if (strcmp(enemy->NAME, enemy1->NAME) == 0) {
		fprintf_s(stdout, "\n %s �� %s(%s) �ɑ��𓊂����I\n", enemy->NAME, player->NAME, player->JOB);
	}
	else if (strcmp(enemy->NAME, enemy2->NAME) == 0) {
		fprintf_s(stdout, "\n %s �� %s(%s) �Ɋ��݂����I\n", enemy->NAME, player->NAME, player->JOB);
	}
	else if (strcmp(enemy->NAME, enemy3->NAME) == 0) {
		fprintf_s(stdout, "\n %s �� %s(%s) �ɖ�𐔔��������I\n", enemy->NAME, player->NAME, player->JOB);
	}
	plusDamage = rand() % 10 - 5;

	if (enemy->POW + plusDamage - player->DEF <= 0) {
		player->HP = player->HP;
		fprintf_s(stdout, " %s(%s) �Ƀ_���[�W��^�����Ȃ������I\n", player->NAME, player->JOB);
	}
	else {
		player->HP = player->HP - (enemy->POW + plusDamage - player->DEF);
		fprintf_s(stdout, " %s(%s) �� %d �̃_���[�W�I\n", player->NAME, player->JOB, (enemy->POW - player->DEF));
	}


	if (player->HP <= 0) {
		player->dead = 1;
		fprintf_s(stdout, " %s(%s) �͗͐s���Ă��܂����I\n", player->NAME, player->JOB);
	}

}

// �G���@:�Ή�
void enemyFire(enemy* enemy, player* player) { //�G�̉Ή������U���A�Ώۂ�I��
	fire->POW = rand() % 20 + 10;
	fprintf_s(stdout, "\n %s �� %s ���������I\n", enemy->NAME, fire->NAME);
	enemyPlaySpell(enemy, fire);
	plusDamage = rand() % 10 - 5;
	if (enemy->playSpell == 0) {
		enemy->MP = enemy->MP - fire->MP;
		player->HP = player->HP - (fire->POW + plusDamage);
		fprintf_s(stdout, " %s(%s) �� %d �̃_���[�W�I\n", player->NAME, player->JOB, fire->POW + plusDamage);
		if (player->HP <= 0) {
			player->dead = 1;
			fprintf_s(stdout, " %s(%s) �͗͐s���Ă��܂����I\n", player->NAME, player->JOB);
		}
	}
}


// �G���@:�G�N�X�v���[�W����
void enemyExplosion() { //�G�̔��������̑S�̍U��
	fprintf_s(stdout, "\n %s �� %s ���������I\n", enemy3->NAME, explosion->NAME);
	explosion->POW = rand() % 20 + 10;
	plusDamage = rand() % 10 - 5;
	enemyPlaySpell(enemy3, explosion);
	if (enemy3->playSpell == 0) {
		enemy3->MP = enemy3->MP - explosion->MP;
		explosion->POW = rand() % 20 + 10;
		player1->HP -= (explosion->POW + plusDamage);
		fprintf_s(stdout, " %s(%s) �� %d �̃_���[�W�I\n", player1->NAME, player1->JOB, explosion->POW + plusDamage);
		if (player1->HP <= 0) {
			player1->dead = 1;
			fprintf_s(stdout, " %s(%s) �͗͐s���Ă��܂����I\n", player1->NAME, player1->JOB);
		}
		explosion->POW = rand() % 20 + 10;
		plusDamage = rand() % 10 - 5;
		player2->HP -= (explosion->POW + plusDamage);
		fprintf_s(stdout, " %s(%s) �� %d �̃_���[�W�I\n", player2->NAME, player2->JOB, explosion->POW + plusDamage);
		if (player2->HP <= 0) {
			player2->dead = 1;
			fprintf_s(stdout, " %s(%s) �͗͐s���Ă��܂����I\n", player2->NAME, player2->JOB);
		}
		explosion->POW = rand() % 20 + 10;
		plusDamage = rand() % 10 - 5;
		player3->HP -= (explosion->POW + plusDamage);
		fprintf_s(stdout, " %s(%s) �� %d �̃_���[�W�I\n", player3->NAME, player3->JOB, explosion->POW + plusDamage);
		if (player3->HP <= 0) {
			player3->dead = 1;
			fprintf_s(stdout, " %s(%s) �͗͐s���Ă��܂����I\n", player3->NAME, player3->JOB);
		}
	}
}


// �G���@:��
void enemyCure(enemy* enemy) { //�G�̉񕜎���
	fprintf_s(stdout, "\n %s �� %s ���������I\n", enemy->NAME, cure->NAME);
	cure->POW = rand() % 30 + 20;
	plusDamage = rand() % 10 - 5;
	enemyPlaySpell(enemy, cure);
	if (enemy->playSpell == 0) {
		enemy->MP = enemy->MP - cure->MP;
		enemy->HP += (cure->POW + plusDamage);
		if (enemy->HP > enemy->iniHP) {
			cure->POW = enemy->HP - enemy->iniHP;
			enemy->HP = enemy->iniHP;

		}
		fprintf_s(stdout, " %s ��HP�� %d �񕜂����I\n", enemy->NAME, cure->POW);
	}
}

// �G���@:�h��up
void enemyDEFup(enemy* enemy) {
	fprintf_s(stdout, "\n %s �� %s ���������I\n", enemy->NAME, DEFup->NAME);
	DEFup->POW = rand() % 20 + 20;
	plusDamage = rand() % 10 - 5;
	enemyPlaySpell(enemy, DEFup);
	if (enemy->playSpell == 0) {
		enemy->MP = enemy->MP - DEFup->MP;
		int iniDEF = enemy->DEF;
		enemy->DEF += (DEFup->POW + plusDamage);
		double magni = round((enemy->DEF / iniDEF) * 10) / 10;
		fprintf_s(stdout, " %s �̖h��͂� %.2f�{ �ɂȂ����I\n", enemy->NAME, magni);
	}
}

// �G�̖������
void enemySleep(enemy* enemy) {
	enemyPlaySpell(enemy, sleep);
	if (enemy->playSpell == 0) {
		enemy->MP -= sleep->MP;
		sleep->POW = 50;
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
			int sleepRate = rand() % 100;
			if (sleep->POW <= sleepRate) {
				currentPlayer->sleep = 1;
				fprintf_s(stdout, " %s(%s) �͖����Ă��܂����I\n", currentPlayer->NAME, currentPlayer->JOB);

			}
			else {
				currentPlayer->sleep = 0;
				fprintf_s(stdout, " %s(%s) �ɂ͌����Ȃ������I\n", currentPlayer->NAME, currentPlayer->JOB);
			}

		}
	}
}

// �G:���[���r�[�X�g
void MoonBeast(enemy* enemy) {
	int attack = rand() % 2 + 1;
	int judge;
	switch (attack) {
	case 1:

		selectPlayer();
		enemyATK(enemy, currentPlayer);
		break;
	case 2:

		selectPlayer();
		enemyFire(enemy, currentPlayer);
		break;

	}

}

// �G:�C�S���[�i�N
void Ygolonac(enemy* enemy) {
	//srand((unsigned)time(NULL));
	int attack = rand() % 3 + 1;
	switch (attack) {
	case 1:
		selectPlayer();
		enemyATK(enemy, currentPlayer);
		break;
	case 2:
		enemyCure(enemy);
		break;
	case 3:
		enemyDEFup(enemy);
		break;
	}
}

// �j�������g�z�e�v
void Nyarlathotep(enemy* enemy, int turn) {
	//srand((unsigned)time(NULL));

	if (turn == 1) {
		enemySleep(enemy);
	}
	else {
		int attack = rand() % 4 + 1;
		switch (attack) {
		case 1:
			selectPlayer();
			enemyATK(enemy, currentPlayer);
			break;
		case 2:
			enemyExplosion();
			break;
		case 3:
			enemyCure(enemy);
			break;
		case 4:
			enemySleep(enemy);
		}
	}
}