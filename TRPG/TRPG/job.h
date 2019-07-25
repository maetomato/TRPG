#pragma once
// ƒvƒŒƒCƒ„[‚Ì

/*
struct Player {
	int hp = 0;
	int mp = 0;
	int pow = 0;
	int def = 0;
	int dex = 0;
};

Player p1, p2, p3, p4, p5;
*/


void soldier(player* player) {

	//int hp, mp, dex, pow, def;
	/*hp = 40 - 80;
	pow = 20 - 30;
	mp = 0;
	dex = 4-10;
	def = 20-40;*/
	sprintf_s(player->JOB, "íŽm");
	player->HP = rand() % 41 + 40;
	player->POW = rand() % 11 + 20;
	player->MP = 0;
	player->DEX = rand() % 7 + 4;
	player->DEF = rand() % 21 + 20;

	player->iniHP = player->HP;
	player->iniPandoraHP = player->HP;
	player->iniMP = player->MP;
	player->iniPOW = player->POW;
	player->iniDEF = player->DEF;

}

void monk(player* player) {
	//int hp, mp, dex, pow, def;
	/*hp = 20-40;
	pow = 5-15;
	mp = 30-50;
	dex = 8 - 16;
	def = 10-30;*/
	sprintf_s(player->JOB, "‘m—µ");
	player->HP = rand() % 21 + 20;
	player->POW = rand() % 11 + 5;
	player->MP = rand() % 21 + 30;
	player->DEX = rand() % 9 + 8;
	player->DEF = rand() % 21 + 10;

	player->iniHP = player->HP;
	player->iniPandoraHP = player->HP;
	player->iniMP = player->MP;
	player->iniPOW = player->POW;
	player->iniDEF = player->DEF;
}

void wizard(player* player) {
	//int hp, mp, dex, pow, def;
	/*hp = 15-30;
	pow = 5 - 10;
	mp = 40-80;
	dex = 8 - 16;
	def = 10 - 20;*/

	sprintf_s(player->JOB, "–‚–@Žg‚¢");
	player->HP = rand() % 16 + 15;
	player->POW = rand() % 6 + 5;
	player->MP = rand() % 41 + 40;
	player->DEX = rand() % 9 + 8;
	player->DEF = rand() % 11 + 10;

	player->iniHP = player->HP;
	player->iniPandoraHP = player->HP;
	player->iniMP = player->MP;
	player->iniPOW = player->POW;
	player->iniDEF = player->DEF;
}

void martial(player* player) {
	//int hp, mp, dex, pow, def;
	/*hp = 40 - 60;
	pow = 20 - 40;
	mp = 0;
	dex = 12 - 24;
	def = 10 - 30;*/

	sprintf_s(player->JOB, "•“¬‰Æ");
	player->HP = rand() % 21 + 40;
	player->POW = rand() % 21 + 20;
	player->MP = 0;
	player->DEX = rand() % 13 + 12;
	player->DEF = rand() % 21 + 10;

	player->iniHP = player->HP;
	player->iniPandoraHP = player->HP;
	player->iniMP = player->MP;
	player->iniPOW = player->POW;
	player->iniDEF = player->DEF;
}

void playful(player* player) {
	//int hp, mp, dex, pow, def;
	/*hp = 30 - 50;
	pow = 15 - 25;
	mp = 20 - 40;
	dex = 10 - 20;
	def = 15 - 40;*/

	sprintf_s(player->JOB, "—V‚Ñl");
	player->HP = rand() % 21 + 30;
	player->POW = rand() % 11 + 15;
	player->MP = rand() % 21 + 20;
	player->DEX = rand() % 11 + 10;
	player->DEF = rand() % 26 + 15;

	player->iniHP = player->HP;
	player->iniPandoraHP = player->HP;
	player->iniMP = player->MP;
	player->iniPOW = player->POW;
	player->iniDEF = player->DEF;
}

//////////////////


