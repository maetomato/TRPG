#pragma once
// 入出力用メソッド

#define CHARBUFF 124

void getGurrentDirectory(char* currentDirectory) {
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}

void InPut() {


	char currentDirectory[CHARBUFF];
	getGurrentDirectory(currentDirectory);
	char section[CHARBUFF];
	sprintf_s(section, "player1");
	char keyWord[CHARBUFF];
	sprintf_s(keyWord, "プレーヤー名");
	char keyJob[CHARBUFF];
	sprintf_s(keyJob, "職業");
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\setting.ini", currentDirectory);
	GetPrivateProfileString(section, keyWord, "none", keyWord, CHARBUFF, settingFile);
	GetPrivateProfileString(section, keyJob, "none", keyJob, CHARBUFF, settingFile);
	//fprintf(stdout, "%s  %s\n", keyWord, keyJob);
	sprintf_s(player1->JOB , keyJob);
	sprintf_s(player1->NAME , keyWord);


	char section2[CHARBUFF];
	sprintf_s(section2, "player2");
	char keyWord2[CHARBUFF];
	sprintf_s(keyWord2, "プレーヤー名");
	char keyJob2[CHARBUFF];
	sprintf_s(keyJob2, "職業");
	GetPrivateProfileString(section2, keyWord2, "none", keyWord2, CHARBUFF, settingFile);
	GetPrivateProfileString(section2, keyJob2, "none", keyJob2, CHARBUFF, settingFile);
	//fprintf(stdout, "%s  %s\n", keyWord2, keyJob2);

	sprintf_s(player2->JOB, keyJob2);
	sprintf_s(player2->NAME, keyWord2);

	char section3[CHARBUFF];
	sprintf_s(section3, "player3");
	char keyWord3[CHARBUFF];
	sprintf_s(keyWord3, "プレーヤー名");
	char keyJob3[CHARBUFF];
	sprintf_s(keyJob3, "職業");
	GetPrivateProfileString(section3, keyWord3, "none", keyWord3, CHARBUFF, settingFile);
	GetPrivateProfileString(section3, keyJob3, "none", keyJob3, CHARBUFF, settingFile);
	//fprintf(stdout, "%s  %s\n", keyWord3, keyJob3);

	sprintf_s(player3->JOB, keyJob3);
	sprintf_s(player3->NAME, keyWord3);

}

void OutPut() {

	FILE* fp;

	char s[BUFFSIZE];
	errno_t error;
	error = fopen_s(&fp, "結果.txt", "w");
	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {
		/*fputs("hogehoge\n", fp);
		fputs("foofoo\n", fp);
		fputs("barbar\n", fp);
		fclose(fp);*/
	}

}