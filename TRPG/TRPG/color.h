#pragma once

void color() {

	init_color(11, 700, 392, 56);
	init_color(9, 700, 684, 668);// 
	init_color(12, 1000, 500, 0);
	init_color(13, 1000, 816, 612);
	init_color(14, 408, 0, 816);
	init_color(15, 612, 204, 0);
	init_color(16, 1000, 1000, 0);
	init_pair(1, COLOR_RED, COLOR_RED);	// ��
	init_pair(2, COLOR_BLACK, COLOR_BLACK);	// ��
	init_pair(3, COLOR_BLUE, COLOR_BLUE);	//  ��
	init_pair(4, COLOR_YELLOW, COLOR_YELLOW);	//  �Â���
	init_pair(5, COLOR_GREEN, COLOR_GREEN);	//  ��
	init_pair(6, COLOR_CYAN, COLOR_CYAN);	//  ���F
	init_pair(7, 14, 14);	//  ��
	init_pair(8, COLOR_WHITE, COLOR_WHITE);	//  ��
	init_pair(9, 9, 9);//�D�F
	init_pair(10, COLOR_WHITE, COLOR_BLACK);	// �F10 �͔�����
	init_pair(11, 11, 11);//���F
	init_pair(12, 12, 12);//�I�����W
	init_pair(13, 13, 13);//���F
	init_pair(15, 15, 15);

	bkgd(COLOR_PAIR(10));
}
