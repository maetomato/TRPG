#pragma once
// ���@
void FIRE();
void EXPLOSION();
void CURE();
void ATKUP();
void DEFUP();
void SLEEP();
void PANDORA();

// �G�̃X�e�[�^�X�ݒ�
void enemy1States();
void enemy2States();
void enemy3States();

// �s��
void enemyATK(enemy* enemy, player* player);
void playerATK(player* player, enemy* enemy);

// �G�̍U��
void enemyFire(enemy* enemy, player* player);
void enemyExplosion();
void enemyCure(enemy* enemy);
void enemyDEFup(enemy* enemy);
void enemySleep(enemy* enemy);

// �����̍U��
void playerFire(player* player, enemy* enemy);
void playerCure(player* playerA, player* playerB);
void playerPOWup(player* playerA, player* playerB);
void playerDEFup(player* playerA, player* playerB);
void playerPandora(player* player, enemy* enemy);
void GetUp();
void DexOrder(enemy* enemy);
void DEAD(player* player);

// �E�ƕ�
void Solder(player* player, enemy* enemy);
void Martial(player* player, enemy* enemy);
void Wizzard(player* player, enemy* enemy);
void Monk(player* player, enemy* enemy);
void Playful(player* player, enemy* enemy);

// �G��
void MoonBeast(enemy* enemy);

// �s������
void playerTurn(player* player, enemy* enemy);
void battleEnemy1();


void spellInit();

// PDCurse�̕`��p
void getGurrentDirectory(char* currentDirectory);
void InPut();
void OutPut();
void doraki();
void suraimu();
void boss();
void senshi();
void mahoutukai();
void souryo();
void butouka();
void asobinin();
void color();
void title();
void player1Put();
void player2Put();
void player3Put();