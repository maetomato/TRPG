#pragma once

void doraki() {
	color();
	int doraki[16][16] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,3,3,0,0,0,0,3,3,0,0,0,0},
		{0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0},
		{0,3,3,3,0,3,3,3,3,3,3,0,3,3,3,0},
		{3,3,3,3,3,3,2,3,3,2,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
		{0,0,3,0,3,1,3,3,3,3,1,3,0,3,0,0},
		{0,0,0,0,3,3,1,1,1,1,3,3,0,0,0,0},
		{0,0,3,0,0,3,3,1,1,3,3,0,0,3,0,0},
		{0,0,3,0,3,3,3,3,3,3,3,3,0,3,0,0},
		{0,0,0,3,0,0,0,3,0,0,0,0,3,0,0,0},
		{0,0,0,3,3,0,0,3,3,0,0,3,3,0,0,0},
		{0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {

			if (doraki[y][x] == 1) {
				attrset(COLOR_PAIR(1));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 2) {
				attrset(COLOR_PAIR(2));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 3) {
				attrset(COLOR_PAIR(3));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 4) {
				attrset(COLOR_PAIR(4));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 5) {
				attrset(COLOR_PAIR(5));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 6) {
				attrset(COLOR_PAIR(6));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 7) {
				attrset(COLOR_PAIR(7));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 8) {
				attrset(COLOR_PAIR(8));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 9) {
				attrset(COLOR_PAIR(9));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 10) {
				attrset(COLOR_PAIR(10));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 11) {
				attrset(COLOR_PAIR(11));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 12) {
				attrset(COLOR_PAIR(12));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else
				if (doraki[y][x] == 13) {
					attrset(COLOR_PAIR(13));
					mvaddstr(y + m, x + n, " ");
					attrset(0);
				}
				else
					if (doraki[y][x] == 14) {
						attrset(COLOR_PAIR(14));
						mvaddstr(y + m, x + n, " ");
						attrset(0);
					}
					else {
						mvaddstr(y + m, x + n, " ");
					}
		}
	}
	refresh();
	napms(300);


	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {

			if (doraki[y][x] == 1) {
				attrset(COLOR_PAIR(1));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 2) {
				attrset(COLOR_PAIR(2));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 3) {
				attrset(COLOR_PAIR(3));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 4) {
				attrset(COLOR_PAIR(4));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 5) {
				attrset(COLOR_PAIR(5));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 6) {
				attrset(COLOR_PAIR(6));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 7) {
				attrset(COLOR_PAIR(7));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 8) {
				attrset(COLOR_PAIR(8));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 9) {
				attrset(COLOR_PAIR(9));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 10) {
				attrset(COLOR_PAIR(10));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 11) {
				attrset(COLOR_PAIR(11));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (doraki[y][x] == 12) {
				attrset(COLOR_PAIR(12));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else
				if (doraki[y][x] == 13) {
					attrset(COLOR_PAIR(13));
					mvaddstr(y + 1 + m, x + n, " ");
					attrset(0);
				}
				else
					if (doraki[y][x] == 14) {
						attrset(COLOR_PAIR(14));
						mvaddstr(y + 1 + m, x + n, " ");
						attrset(0);
					}
					else {
						mvaddstr(y + 1 + m, x + n, " ");
					}
		}
	}
	refresh();
	napms(300);

}

void suraimu() {
	color();
	int suraimu[16][16] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,6,6,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,6,6,0,0,0,0,0,0,0},
		{0,0,0,0,0,6,6,6,6,6,6,0,0,0,0,0},
		{0,0,0,0,6,8,6,6,6,6,6,6,0,0,0,0},
		{0,0,0,6,8,6,6,6,6,6,6,6,6,0,0,0},
		{0,0,6,8,6,6,8,6,6,6,8,6,6,6,0,0},
		{0,6,6,6,6,8,2,8,6,8,2,8,6,6,6,0},
		{0,6,6,6,6,6,8,6,6,6,8,6,6,6,6,0},
		{0,6,6,6,1,6,6,6,6,6,6,1,6,6,6,0},
		{0,0,6,6,6,1,1,1,1,1,1,6,6,6,0,0},
		{0,0,0,0,6,6,6,6,6,6,6,6,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {

			if (suraimu[y][x] == 1) {
				attrset(COLOR_PAIR(1));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 2) {
				attrset(COLOR_PAIR(2));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 3) {
				attrset(COLOR_PAIR(3));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 4) {
				attrset(COLOR_PAIR(4));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 5) {
				attrset(COLOR_PAIR(5));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 6) {
				attrset(COLOR_PAIR(6));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 7) {
				attrset(COLOR_PAIR(7));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 8) {
				attrset(COLOR_PAIR(8));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 9) {
				attrset(COLOR_PAIR(9));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 10) {
				attrset(COLOR_PAIR(10));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 11) {
				attrset(COLOR_PAIR(11));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 12) {
				attrset(COLOR_PAIR(12));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else
				if (suraimu[y][x] == 13) {
					attrset(COLOR_PAIR(13));
					mvaddstr(y + m, x + n, " ");
					attrset(0);
				}
				else
					if (suraimu[y][x] == 14) {
						attrset(COLOR_PAIR(14));
						mvaddstr(y + m, x + n, " ");
						attrset(0);
					}
					else {
						mvaddstr(y + m, x + n, " ");
					}
		}
	}
	refresh();
	napms(300);

	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {

			if (suraimu[y][x] == 1) {
				attrset(COLOR_PAIR(1));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 2) {
				attrset(COLOR_PAIR(2));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 3) {
				attrset(COLOR_PAIR(3));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 4) {
				attrset(COLOR_PAIR(4));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 5) {
				attrset(COLOR_PAIR(5));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 6) {
				attrset(COLOR_PAIR(6));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 7) {
				attrset(COLOR_PAIR(7));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 8) {
				attrset(COLOR_PAIR(8));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 9) {
				attrset(COLOR_PAIR(9));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 10) {
				attrset(COLOR_PAIR(10));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 11) {
				attrset(COLOR_PAIR(11));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (suraimu[y][x] == 12) {
				attrset(COLOR_PAIR(12));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else
				if (suraimu[y][x] == 13) {
					attrset(COLOR_PAIR(13));
					mvaddstr(y + 1 + m, x + n, " ");
					attrset(0);
				}
				else
					if (suraimu[y][x] == 14) {
						attrset(COLOR_PAIR(14));
						mvaddstr(y + 1 + m, x + n, " ");
						attrset(0);
					}
					else {
						mvaddstr(y + 1 + m, x + n, " ");
					}
		}
	}
	refresh();
	napms(300);
}

void boss() {
	color();
	int boss[16][16] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,4,4,4,4,0,0,0,0,0,0},
		{0,0,0,0,4,4,4,4,4,4,4,4,0,0,0,0},
		{0,0,0,4,4,4,4,5,5,5,5,5,4,0,0,0},
		{0,0,0,4,4,4,5,5,2,5,5,2,5,4,0,0},
		{0,0,4,4,4,5,5,5,8,5,5,8,5,4,0,0},
		{0,0,4,4,4,5,5,5,2,5,5,2,5,4,0,0},
		{0,0,4,4,4,5,5,5,3,5,5,3,5,5,4,0},
		{0,0,4,4,4,5,1,1,5,5,5,5,1,5,4,0},
		{0,4,4,4,4,5,5,5,5,5,5,5,5,5,4,0},
		{0,4,4,4,4,5,5,5,5,5,5,5,5,4,4,0},
		{0,4,4,4,4,4,5,5,5,5,5,5,4,4,4,0},
		{0,0,4,4,4,4,4,4,4,4,4,4,5,5,0,0},
		{0,0,5,5,5,5,4,0,0,0,5,5,5,5,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	init_color(32, 1000, 0, 612);
	init_pair(32, 32, 32);//青
	init_pair(27, 13, 13);//肌色

	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {

			if (boss[y][x] == 1) {//red
				attrset(COLOR_PAIR(1));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 2) {//black
				attrset(COLOR_PAIR(2));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 3) {//blue
				attrset(COLOR_PAIR(32));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 4) {//オレンジ
				attrset(COLOR_PAIR(12));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 5) {//肌色
				attrset(COLOR_PAIR(27));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 6) {
				attrset(COLOR_PAIR(6));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 7) {
				attrset(COLOR_PAIR(7));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 8) {
				attrset(COLOR_PAIR(8));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 9) {
				attrset(COLOR_PAIR(9));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 10) {
				attrset(COLOR_PAIR(10));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 11) {
				attrset(COLOR_PAIR(11));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 12) {
				attrset(COLOR_PAIR(12));
				mvaddstr(y + m, x + n, " ");
				attrset(0);
			}
			else
				if (boss[y][x] == 13) {
					attrset(COLOR_PAIR(13));
					mvaddstr(y + m, x + n, " ");
					attrset(0);
				}
				else
					if (boss[y][x] == 14) {
						attrset(COLOR_PAIR(14));
						mvaddstr(y + m, x + n, " ");
						attrset(0);
					}
					else {
						mvaddstr(y + m, x + n, " ");
					}
		}
	}
	refresh();
	napms(300);

	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {

			if (boss[y][x] == 1) {
				attrset(COLOR_PAIR(1));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 2) {
				attrset(COLOR_PAIR(2));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 3) {
				attrset(COLOR_PAIR(32));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 4) {
				attrset(COLOR_PAIR(12));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 5) {
				attrset(COLOR_PAIR(27));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 6) {
				attrset(COLOR_PAIR(6));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 7) {
				attrset(COLOR_PAIR(7));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 8) {
				attrset(COLOR_PAIR(8));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 9) {
				attrset(COLOR_PAIR(9));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 10) {
				attrset(COLOR_PAIR(10));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 11) {
				attrset(COLOR_PAIR(11));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else if (boss[y][x] == 12) {
				attrset(COLOR_PAIR(12));
				mvaddstr(y + 1 + m, x + n, " ");
				attrset(0);
			}
			else
				if (boss[y][x] == 13) {
					attrset(COLOR_PAIR(13));
					mvaddstr(y + 1 + m, x + n, " ");
					attrset(0);
				}
				else
					if (boss[y][x] == 14) {
						attrset(COLOR_PAIR(14));
						mvaddstr(y + 1 + m, x + n, " ");
						attrset(0);
					}
					else {
						mvaddstr(y + 1 + m, x + n, " ");
					}
		}
	}
	refresh();
	napms(300);
}