#pragma once

// �������������邩�𔻒�
void playerPlaySpell(player* player, spell* spell) {
	if (player->MP < spell->MP) {
		player->playSpell = 1;
		fprintf_s(stdout, "\n������MP������Ȃ������I\n");
	}
	else if (player->MP >= spell->MP) {
		player->playSpell = 0;
	}
}

// �ʏ�U��
void playerATK(player* player, enemy* enemy) { //�v���C���[�̒ʏ�U��
	fprintf_s(stdout, "\n %s(%s) �� %s �ɍU�������I\n", player->NAME, player->JOB, enemy->NAME);
	plusDamage = rand() % 10 - 5;
	if (player->POW + plusDamage - enemy->DEF <= 0) {
		enemy->HP = enemy->HP;
		fprintf_s(stdout, " %s �Ƀ_���[�W��^�����Ȃ������I\n", enemy->NAME);
	}
	else {
		enemy->HP = enemy->HP - (player->POW + plusDamage - enemy->DEF);
		fprintf_s(stdout, " %s �� %d �̃_���[�W�I\n", enemy->NAME, (player->POW + plusDamage - enemy->DEF));
	}

}

// ���@:�Ή�
void playerFire(player* player, enemy* enemy) { //�v���C���[�̉Ή������U��
	fprintf_s(stdout, "\n %s(%s) �� %s ���������I\n", player->NAME, player->JOB, fire->NAME);
	fire->POW = rand() % 10 + 10;
	playerPlaySpell(player, fire);
	plusDamage = rand() % 10 - 5;
	if (player->playSpell == 0) {
		player->MP = player->MP - fire->MP;
		enemy->HP = enemy->HP - (fire->POW + plusDamage);
		fprintf_s(stdout, " %s �� %d �̃_���[�W�I\n", enemy->NAME, fire->POW + plusDamage);
	}
}

// ���@:��
void playerCure(player* playerA, player* playerB) { //�v���C���[�̉񕜎����A�Ώۂ�I��
	fprintf_s(stdout, "\n %s(%s) �� %s ���������I\n", playerA->NAME, playerA->JOB, cure->NAME);
	cure->POW = rand() % 30 + 10;
	plusDamage = rand() % 10 - 5;
	playerPlaySpell(playerA, cure);
	if (playerB->dead != 1 && playerA->playSpell == 0) {
		playerA->MP = playerA->MP - cure->MP;
		playerB->HP += (cure->POW + plusDamage);
		if (playerB->HP > playerB->iniHP) {
			cure->POW = playerB->HP - playerB->iniHP;
			playerB->HP = playerB->iniHP;

		}
		fprintf_s(stdout, " %s(%s) ��HP�� %d �񕜂����I\n", playerB->NAME, playerB->JOB, cure->POW);
	}
	else {
		fprintf_s(stdout, " %s �͎���ł���I\n", playerB->NAME);
	}
}

// ���@:�U����up
void playerPOWup(player* playerA, player* playerB) { //�v���C���[�̍U���͏㏸�����A�Ώۂ�I��
	fprintf_s(stdout, "\n %s(%s) �� %s ���������I\n", playerA->NAME, playerA->JOB, POWup->NAME);
	POWup->POW = rand() % 30 + 10;
	plusDamage = rand() % 10 - 5;
	playerPlaySpell(playerA, POWup);
	if (playerA->playSpell == 0) {
		playerA->MP = playerA->MP - POWup->MP;
		int iniPOW = playerB->POW;
		playerB->POW += (POWup->POW + plusDamage);
		double magni = round((playerB->POW / iniPOW) * 10) / 10;
		fprintf_s(stdout, " %s(%s) �̍U���͂� %.2f�{ �ɂȂ����I\n", playerB->NAME, playerB->JOB, magni);
	}
}

// ���@:�h��up
void playerDEFup(player* playerA, player* playerB) { //�v���C���[�̖h��͏㏸�����A�Ώۂ�I��
	fprintf_s(stdout, "\n %s(%s) �� %s ���������I\n", playerA->NAME, playerA->JOB, DEFup->NAME);
	plusDamage = rand() % 10 - 5;
	playerPlaySpell(playerA, DEFup);
	if (playerA->playSpell == 0) {
		DEFup->POW = rand() % 20 + 10;
		playerA->MP = playerA->MP - DEFup->MP;
		int iniDEF = playerB->DEF;
		playerB->DEF += (DEFup->POW + plusDamage);
		double magni = round((playerB->DEF / iniDEF) * 10) / 10;
		fprintf_s(stdout, " %s(%s) �̖h��͂� %.2f�{ �ɂȂ����I\n", playerB->NAME, playerB->JOB, magni);
	}
}

// ���@:�p���h��
void playerPandora(player* player, enemy* enemy) {
	fprintf_s(stdout, "\n %s �� %s ���������I\n", player->NAME, pandora->NAME);
	if (player->MP == 0) {
		fprintf_s(stdout, "\n������MP������Ȃ������I\n");
	}
	else {
		pandora->MP = player->MP / 2;
		player->MP -= pandora->MP;
		int judge = rand() % 4 + 1;
		switch (judge) {
		case 1:
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

				currentPlayer->HP /= 2;
				currentPlayer->iniPandoraHP /= 2;

			}
			fprintf_s(stdout, "�p�[�e�B�[��HP�����������I\n");
			break;
		case 2:
			enemy->HP /= 2;
			enemy->iniHP /= 2;
			fprintf_s(stdout, "�G��HP�����������I\n");
			break;
		case 3:
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
				currentPlayer->HP *= 2;
				currentPlayer->iniPandoraHP *= 2;

			}
			fprintf_s(stdout, "�p�[�e�B�[��HP���{�������I\n");
			break;
		case 4:
			enemy->HP *= 2;
			enemy->iniHP *= 2;
			fprintf_s(stdout, "�G��HP���{�������I\n");
			break;
		}
	}
}

// ��m
void Solder(player* player, enemy* enemy) {
	playerATK(player, enemy);
	//HP�����Ȃ��Ȃ�Ζh�䂷�郁�\�b�h���ǉ�����

}

// ������
void Martial(player* player, enemy* enemy) {
	playerATK(player, enemy);
	//�h�䃁�\�b�h

}

// ���@�g��
void Wizzard(player* player, enemy* enemy) {
	int attack = rand() % 3 + 1;
	int judge;
	switch (attack) {
	case 1:
		playerATK(player, enemy);
		break;
	case 2:
		playerFire(player, enemy);
		break;
	case 3:
		selectPlayer();
		playerPOWup(player, currentPlayer);


		break;

	}

}

// �m��
void Monk(player* player, enemy* enemy) {
	int attack = rand() % 3 + 1;
	int judge;
	switch (attack) {
	case 1:
		playerATK(player, enemy);
		break;
	case 2:
		selectPlayer();
		playerCure(player, currentPlayer);
		break;
	case 3:
		selectPlayer();
		playerDEFup(player, currentPlayer);


		break;

	}

}

// �V�ѐl
void Playful(player* player, enemy* enemy) {
	int attack = rand() % 10 + 1;
	int judge;
	switch (attack) {
	case 1:
	case 5:
	case 7:
		playerATK(player, enemy);
		break;
	case 2:
	case 6:
	case 10:
		selectPlayer();
		playerCure(player, currentPlayer);

		break;
	case 3:
		playerPandora(player, enemy);
		break;
	case 4:
	case 8:
	case 9:
		playerFire(player, enemy);
		break;
	}

}

void playerTurn(player* player, enemy* enemy) {
	DEAD(player);
	if (player->sleep == 1 && player->dead == 0) {
		GetUp(player);
	}
	if (player->dead == 0) {
		if (player->sleep == 0) {
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

}

