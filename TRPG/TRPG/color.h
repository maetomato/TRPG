#pragma once

void color() {

	init_color(11, 700, 392, 56);
	init_color(9, 700, 684, 668);// 
	init_color(12, 1000, 500, 0);
	init_color(13, 1000, 816, 612);
	init_color(14, 408, 0, 816);
	init_color(15, 612, 204, 0);
	init_color(16, 1000, 1000, 0);
	init_pair(1, COLOR_RED, COLOR_RED);	// 赤
	init_pair(2, COLOR_BLACK, COLOR_BLACK);	// 黒
	init_pair(3, COLOR_BLUE, COLOR_BLUE);	//  青
	init_pair(4, COLOR_YELLOW, COLOR_YELLOW);	//  暗い黄
	init_pair(5, COLOR_GREEN, COLOR_GREEN);	//  緑
	init_pair(6, COLOR_CYAN, COLOR_CYAN);	//  水色
	init_pair(7, 14, 14);	//  紫
	init_pair(8, COLOR_WHITE, COLOR_WHITE);	//  白
	init_pair(9, 9, 9);//灰色
	init_pair(10, COLOR_WHITE, COLOR_BLACK);	// 色10 は白文字
	init_pair(11, 11, 11);//茶色
	init_pair(12, 12, 12);//オレンジ
	init_pair(13, 13, 13);//肌色
	init_pair(15, 15, 15);

	bkgd(COLOR_PAIR(10));
}
