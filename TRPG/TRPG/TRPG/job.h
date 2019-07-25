#pragma once

// íŽm
void soldier(player* player) {

	/*
	hp = 40-80;
	pow = 20-30;
	mp = 0;
	dex = 4-10;
	def = 20-40;*/

	sprintf_s(player->JOB, "íŽm");
	player->HP = rand() % 41 + 40;
	player->POW = rand() % 31 + 30;
	player->MP = 0;
	player->DEX = rand() % 7 + 4;
	player->DEF = rand() % 21 + 20;

	player->iniHP = player->HP;
	player->iniPandoraHP = player->HP; // Žô•¶Pandora‚É‚æ‚éHP•Ï“®‚ðl—¶‚µ‚½HPÅ‘å’l
	player->iniMP = player->MP;
	player->iniPOW = player->POW;
	player->iniDEF = player->DEF;

}

// ‘m—µ
void monk(player* player) {

	//int hp, mp, dex, pow, def;
	/*
	hp = 30-60;
	pow = 5-15;
	mp = 30-50;
	dex = 8-16;
	def = 10-30;*/

	sprintf_s(player->JOB, "‘m—µ");
	player->HP = rand() % 31 + 30;
	player->POW = rand() % 11 + 5;
	player->MP = rand() % 21 + 40;
	player->DEX = rand() % 9 + 8;
	player->DEF = rand() % 21 + 15;

	player->iniHP = player->HP;
	player->iniPandoraHP = player->HP;
	player->iniMP = player->MP;
	player->iniPOW = player->POW;
	player->iniDEF = player->DEF;
}

// –‚–@Žg‚¢
void wizard(player* player) {

	/*
	hp = 30-50;
	pow = 5-10;
	mp = 40-80;
	dex = 8-16;
	def = 10-20;*/

	sprintf_s(player->JOB, "–‚–@Žg‚¢");
	player->HP = rand() % 21 + 30;
	player->POW = rand() % 11 + 5;
	player->MP = rand() % 41 + 40;
	player->DEX = rand() % 11 + 15 ;
	player->DEF = rand() % 11 + 10;

	player->iniHP = player->HP;
	player->iniPandoraHP = player->HP;
	player->iniMP = player->MP;
	player->iniPOW = player->POW;
	player->iniDEF = player->DEF;
}

// •“¬‰Æ
void martial(player* player) {

	/*
	hp = 40-60;
	pow = 20-40;
	mp = 0;
	dex = 12-24;
	def = 10-30;*/

	sprintf_s(player->JOB, "•“¬‰Æ");
	player->HP = rand() % 21 + 40;
	player->POW = rand() % 21 + 30;
	player->MP = 0;
	player->DEX = rand() % 30 + 15;
	player->DEF = rand() % 21 + 10;

	player->iniHP = player->HP;
	player->iniPandoraHP = player->HP;
	player->iniMP = player->MP;
	player->iniPOW = player->POW;
	player->iniDEF = player->DEF;
}

// —V‚Ñl
void playful(player* player) {

	/*
	hp = 30-80;
	pow = 15-25;
	mp = 20-40;
	dex = 10-20;
	def = 15-40;*/

	sprintf_s(player->JOB, "—V‚Ñl");
	player->HP = rand() % 51 + 30;
	player->POW = rand() % 21 + 20;
	player->MP = rand() % 21 + 20;
	player->DEX = rand() % 11 + 10;
	player->DEF = rand() % 26 + 20;

	player->iniHP = player->HP;
	player->iniPandoraHP = player->HP;
	player->iniMP = player->MP;
	player->iniPOW = player->POW;
	player->iniDEF = player->DEF;
}
