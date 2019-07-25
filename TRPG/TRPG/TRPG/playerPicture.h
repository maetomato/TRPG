#pragma once

void senshi() {
	color();
	int senshi[16][16] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,9,0,4,0,0,7,7,1,1,7,7,0,0,4,0},
		{0,9,0,4,0,7,7,1,1,1,1,7,7,0,4,0},
		{0,9,0,4,4,1,7,1,7,7,1,7,1,4,4,0},
		{0,9,0,0,0,1,1,1,7,7,1,1,1,0,0,0},
		{0,9,0,0,0,1,13,2,1,1,2,13,1,0,0,0},
		{0,9,0,1,1,1,13,2,13,13,2,13,1,1,1,0},
		{0,13,1,1,1,7,13,13,13,13,13,13,7,1,1,1},
		{0,13,1,1,1,1,1,13,13,13,13,1,1,1,1,1},
		{0,13,13,0,0,1,1,7,7,7,7,1,1,0,13,13},
		{0,0,0,0,0,1,1,1,1,1,1,1,1,0,13,13},
		{0,0,0,0,0,1,1,1,7,7,1,1,1,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0},
		{0,0,0,0,7,7,7,0,0,0,7,7,7,0,0,0},
		{0,0,0,0,7,7,7,0,0,0,7,7,7,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {

			if (senshi[y][x] == 1) {
				attrset(COLOR_PAIR(1));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (senshi[y][x] == 2) {
				attrset(COLOR_PAIR(2));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (senshi[y][x] == 3) {
				attrset(COLOR_PAIR(3));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (senshi[y][x] == 4) {
				attrset(COLOR_PAIR(4));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (senshi[y][x] == 5) {
				attrset(COLOR_PAIR(5));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (senshi[y][x] == 6) {
				attrset(COLOR_PAIR(6));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (senshi[y][x] == 7) {
				attrset(COLOR_PAIR(7));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (senshi[y][x] == 8) {
				attrset(COLOR_PAIR(8));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (senshi[y][x] == 9) {
				attrset(COLOR_PAIR(9));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (senshi[y][x] == 10) {
				attrset(COLOR_PAIR(10));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (senshi[y][x] == 11) {
				attrset(COLOR_PAIR(11));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (senshi[y][x] == 12) {
				attrset(COLOR_PAIR(12));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else
				if (senshi[y][x] == 13) {
					attrset(COLOR_PAIR(13));
					mvaddstr(y + 30, x + 60 * a, " ");
					attrset(0);
				}
				else
					if (senshi[y][x] == 14) {
						attrset(COLOR_PAIR(14));
						mvaddstr(y + 30, x + 60 * a, " ");
						attrset(0);
					}
					else {
						mvaddstr(y + 30, x + 60 * a, " ");
					}
		}
	}
	refresh();
}

void mahoutukai() {

	color();
	int mahoutukai[16][16] = {
		{0,0,0,0,0,0,0,0,0,7,7,7,0,0,0,0},
		{15,15,15,15,0,0,0,0,7,7,0,0,0,0,0,0},
		{0,0,0,15,0,0,0,1,1,1,1,0,0,0,0,0},
		{0,15,15,15,0,7,7,7,7,7,7,7,7,0,0,0},
		{0,15,0,7,7,7,7,7,7,7,7,7,7,7,7,0},
		{0,15,0,0,0,11,11,11,11,11,11,11,11,0,0,0},
		{0,15,0,0,11,11,13,2,13,13,2,13,11,11,0,0},
		{0,15,0,11,11,1,13,2,13,13,2,13,1,11,11,0},
		{0,15,7,7,7,7,13,13,13,13,13,13,7,7,7,0},
		{0,13,7,7,7,7,7,13,13,13,13,7,7,7,7,7},
		{0,13,0,0,7,7,7,7,7,7,7,7,7,0,13,13},
		{0,15,0,0,11,11,11,11,11,11,11,11,11,0,13,13},
		{0,15,0,7,7,7,7,7,7,7,7,7,7,7,0,0},
		{0,15,7,7,7,7,7,7,7,7,7,7,7,7,7,0},
		{0,15,0,0,4,4,4,0,0,0,4,4,4,0,0,0},
		{0,15,0,4,4,4,4,0,0,0,4,4,4,4,0,0}
	};


	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {

			if (mahoutukai[y][x] == 1) {
				attrset(COLOR_PAIR(1));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (mahoutukai[y][x] == 2) {
				attrset(COLOR_PAIR(2));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (mahoutukai[y][x] == 3) {
				attrset(COLOR_PAIR(3));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (mahoutukai[y][x] == 4) {
				attrset(COLOR_PAIR(4));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (mahoutukai[y][x] == 5) {
				attrset(COLOR_PAIR(5));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (mahoutukai[y][x] == 6) {
				attrset(COLOR_PAIR(6));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (mahoutukai[y][x] == 7) {
				attrset(COLOR_PAIR(7));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (mahoutukai[y][x] == 8) {
				attrset(COLOR_PAIR(8));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (mahoutukai[y][x] == 9) {
				attrset(COLOR_PAIR(9));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (mahoutukai[y][x] == 10) {
				attrset(COLOR_PAIR(10));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (mahoutukai[y][x] == 11) {
				attrset(COLOR_PAIR(11));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (mahoutukai[y][x] == 12) {
				attrset(COLOR_PAIR(12));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else
				if (mahoutukai[y][x] == 13) {
					attrset(COLOR_PAIR(13));
					mvaddstr(y + 30, x + 60 * a, " ");
					attrset(0);
				}
				else
					if (mahoutukai[y][x] == 14) {
						attrset(COLOR_PAIR(14));
						mvaddstr(y + 30, x + 60 * a, " ");
						attrset(0);
					}
					else
						if (mahoutukai[y][x] == 15) {
							attrset(COLOR_PAIR(15));
							mvaddstr(y + 30, x + 60 * a, " ");
							attrset(0);
						}
						else {
							mvaddstr(y + 30, x + 60 * a, " ");
						}
		}
	}
	refresh();
}


void souryo() {
	color();
	int souryo[16][16] = {
		{0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
		{0,5,0,0,0,1,5,5,5,5,5,1,0,0,0,0},
		{0,5,0,0,0,1,5,5,1,5,5,1,0,0,0,0},
		{1,8,1,0,0,1,5,1,1,1,5,1,5,0,0,0},
		{1,8,1,0,0,1,5,5,1,5,5,1,5,0,0,0},
		{0,5,0,0,0,1,5,5,5,5,5,1,5,0,0,0},
		{0,8,0,0,0,0,13,2,13,13,2,13,0,0,0,0},
		{0,8,0,0,0,0,13,2,13,13,2,13,0,0,0,0},
		{0,8,5,5,5,1,13,13,13,13,13,13,1,5,5,0},
		{13,13,5,5,1,5,5,13,13,13,13,5,1,5,5,5},
		{13,13,0,1,5,5,5,5,1,5,5,5,5,1,13,13},
		{0,8,0,1,5,5,5,1,1,1,5,5,5,1,13,13},
		{0,5,0,1,5,5,5,5,1,5,5,5,5,1,0,0},
		{0,5,0,1,1,1,1,1,1,1,1,1,1,1,0,0},
		{0,5,0,0,5,5,5,0,0,0,5,5,5,0,0,0},
		{0,8,0,4,4,4,4,0,0,0,4,4,4,4,0,0}
	};
	init_color(21, 1000, 1000, 0);
	init_pair(21, 21, 21);
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {

			if (souryo[y][x] == 1) {
				attrset(COLOR_PAIR(21));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (souryo[y][x] == 2) {
				attrset(COLOR_PAIR(2));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (souryo[y][x] == 3) {
				attrset(COLOR_PAIR(3));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (souryo[y][x] == 4) {
				attrset(COLOR_PAIR(4));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (souryo[y][x] == 5) {
				attrset(COLOR_PAIR(5));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (souryo[y][x] == 6) {
				attrset(COLOR_PAIR(6));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (souryo[y][x] == 7) {
				attrset(COLOR_PAIR(7));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (souryo[y][x] == 8) {
				attrset(COLOR_PAIR(8));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (souryo[y][x] == 9) {
				attrset(COLOR_PAIR(9));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (souryo[y][x] == 10) {
				attrset(COLOR_PAIR(10));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (souryo[y][x] == 11) {
				attrset(COLOR_PAIR(11));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (souryo[y][x] == 12) {
				attrset(COLOR_PAIR(12));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else
				if (souryo[y][x] == 13) {
					attrset(COLOR_PAIR(13));
					mvaddstr(y + 30, x + 60 * a, " ");
					attrset(0);
				}
				else
					if (souryo[y][x] == 14) {
						attrset(COLOR_PAIR(14));
						mvaddstr(y + 30, x + 60 * a, " ");
						attrset(0);
					}
					else
						if (souryo[y][x] == 15) {
							attrset(COLOR_PAIR(15));
							mvaddstr(y + 30, x + 60 * a, " ");
							attrset(0);
						}

						else {
							mvaddstr(y + 30, x + 60 * a, " ");
						}
		}
	}
	refresh();

}

void butouka() {
	color();

	int butouka[16][16] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,3,3,3,3,3,3,0,0,0,0},
		{0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,0},
		{0,0,0,0,0,3,3,3,3,3,3,3,3,0,3,0},
		{0,0,0,0,0,3,13,13,3,3,13,13,3,0,3,0},
		{0,0,0,0,0,3,13,13,3,3,13,13,3,0,3,5},
		{0,0,0,0,0,0,13,2,13,13,2,13,0,0,0,3},
		{0,0,0,0,0,0,13,2,13,13,2,13,0,0,0,0},
		{0,0,0,3,1,1,3,13,13,13,13,3,1,3,13,0},
		{0,0,3,13,3,5,5,3,5,5,3,5,1,5,3,13},
		{0,0,13,13,3,5,5,5,3,3,5,5,5,3,13,13},
		{0,0,13,13,13,13,5,5,5,5,5,5,5,1,0,0},
		{0,0,0,13,13,5,5,5,5,5,5,5,5,1,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0},
		{0,0,0,0,5,5,5,0,0,0,5,5,5,0,0,0},
		{0,0,0,4,4,4,4,0,0,0,4,4,4,4,0,0}
	};
	init_color(21, 1000, 1000, 0);
	init_pair(21, 21, 21);
	init_pair(23, 11, 11);
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {

			if (butouka[y][x] == 1) {
				attrset(COLOR_PAIR(21));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (butouka[y][x] == 2) {
				attrset(COLOR_PAIR(2));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (butouka[y][x] == 3) {
				attrset(COLOR_PAIR(23));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (butouka[y][x] == 4) {
				attrset(COLOR_PAIR(4));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (butouka[y][x] == 5) {
				attrset(COLOR_PAIR(5));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (butouka[y][x] == 6) {
				attrset(COLOR_PAIR(6));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (butouka[y][x] == 7) {
				attrset(COLOR_PAIR(7));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (butouka[y][x] == 8) {
				attrset(COLOR_PAIR(8));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (butouka[y][x] == 9) {
				attrset(COLOR_PAIR(9));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (butouka[y][x] == 10) {
				attrset(COLOR_PAIR(10));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (butouka[y][x] == 11) {
				attrset(COLOR_PAIR(11));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (butouka[y][x] == 12) {
				attrset(COLOR_PAIR(12));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else
				if (butouka[y][x] == 13) {
					attrset(COLOR_PAIR(13));
					mvaddstr(y + 30, x + 60 * a, " ");
					attrset(0);
				}
				else
					if (butouka[y][x] == 14) {
						attrset(COLOR_PAIR(14));
						mvaddstr(y + 30, x + 60 * a, " ");
						attrset(0);
					}
					else
						if (butouka[y][x] == 15) {
							attrset(COLOR_PAIR(15));
							mvaddstr(y + 30, x + 60 * a, " ");
							attrset(0);
						}

						else {
							mvaddstr(y + 30, x + 60 * a, " ");
						}
		}
	}
	refresh();
}

void asobinin() {
	color();

	int asobinin[16][16] = {
		{0,0,0,3,3,3,5,5,0,0,5,5,5,0,0,0},
		{0,0,3,0,3,3,3,5,5,5,3,3,3,5,0,0},
		{0,0,0,5,5,5,3,3,3,3,3,3,3,3,0,0},
		{0,0,5,5,5,3,3,5,5,3,3,5,5,3,5,0},
		{0,0,5,5,3,5,5,4,5,5,5,3,5,5,5,0},
		{0,0,0,5,5,5,2,4,4,2,4,5,5,5,5,0},
		{0,0,0,0,4,4,2,4,4,2,4,4,5,4,0,5},
		{0,0,0,0,0,4,4,4,4,4,4,5,5,4,5,5},
		{0,0,0,0,0,0,3,3,3,3,5,5,5,4,5,0},
		{0,0,0,4,4,4,3,4,3,4,4,4,5,4,5,5},
		{4,4,4,3,4,3,4,4,4,3,3,4,3,4,4,0},
		{4,4,0,0,0,5,3,3,3,3,3,0,0,0,0,0},
		{0,5,0,0,5,3,3,3,3,3,3,3,0,0,0,0},
		{5,5,5,0,5,4,3,3,3,3,4,3,0,0,0,0},
		{5,5,5,0,0,5,5,0,4,4,4,5,0,0,0,0},
		{0,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0}
	};

	init_color(25, 1000, 204, 1000);
	init_pair(24, 13, 13);
	init_pair(25, 25, 25);
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {

			if (asobinin[y][x] == 1) {
				attrset(COLOR_PAIR(1));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (asobinin[y][x] == 2) {
				attrset(COLOR_PAIR(2));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (asobinin[y][x] == 3) {
				attrset(COLOR_PAIR(3));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (asobinin[y][x] == 4) {
				attrset(COLOR_PAIR(24));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (asobinin[y][x] == 5) {
				attrset(COLOR_PAIR(25));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (asobinin[y][x] == 6) {
				attrset(COLOR_PAIR(6));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (asobinin[y][x] == 7) {
				attrset(COLOR_PAIR(7));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (asobinin[y][x] == 8) {
				attrset(COLOR_PAIR(8));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (asobinin[y][x] == 9) {
				attrset(COLOR_PAIR(9));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (asobinin[y][x] == 10) {
				attrset(COLOR_PAIR(10));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (asobinin[y][x] == 11) {
				attrset(COLOR_PAIR(11));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else if (asobinin[y][x] == 12) {
				attrset(COLOR_PAIR(12));
				mvaddstr(y + 30, x + 60 * a, " ");
				attrset(0);
			}
			else
				if (asobinin[y][x] == 13) {
					attrset(COLOR_PAIR(13));
					mvaddstr(y + 30, x + 60 * a, " ");
					attrset(0);
				}
				else
					if (asobinin[y][x] == 14) {
						attrset(COLOR_PAIR(14));
						mvaddstr(y + 30, x + 60 * a, " ");
						attrset(0);
					}
					else
						if (asobinin[y][x] == 15) {
							attrset(COLOR_PAIR(15));
							mvaddstr(y + 30, x + 60 * a, " ");
							attrset(0);
						}

						else {
							mvaddstr(y + 30, x + 60 * a, " ");
						}
		}
	}
	refresh();
}

void title() {
	color();
	attrset(COLOR_PAIR(10));
	refresh();

	player1Put();
	player2Put();
	player3Put();
}

void player1Put() {

	mvaddstr(j + 50, i + 60, player1->NAME);
	mvaddstr(j + 50, i + 65, player1->NAME);
	a = 1;
	if (!strcmp(player1->JOB, "êÌém")) {
		senshi();
	}
	if (!strcmp(player1->JOB, "ñÇñ@égÇ¢")) {
		mahoutukai();
	}
	if (!strcmp(player1->JOB, "ëmóµ")) {
		souryo();
	}
	if (!strcmp(player1->JOB, "ïêì¨â∆")) {
		butouka();
	}
	if (!strcmp(player1->JOB, "óVÇ—êl")) {
		asobinin();
	}
}

void player2Put() {

	mvaddstr(j + 50, i + 120, player1->NAME);
	mvaddstr(j + 50, i + 125, player2->JOB);
	a = 2;
	if (!strcmp(player2->JOB, "êÌém")) {
		senshi();
	}
	if (!strcmp(player2->JOB, "ñÇñ@égÇ¢")) {
		mahoutukai();
	}
	if (!strcmp(player2->JOB, "ëmóµ")) {
		souryo();
	}
	if (!strcmp(player2->JOB, "ïêì¨â∆")) {
		butouka();
	}
	if (!strcmp(player2->JOB, "óVÇ—êl")) {
		asobinin();
	}
}

void player3Put() {

	mvaddstr(j + 50, i + 180, player3->NAME);
	mvaddstr(j + 50, i + 185, player3->JOB);
	a = 3;
	if (!strcmp(player3->JOB, "êÌém")) {
		senshi();
	}
	if (!strcmp(player3->JOB, "ñÇñ@égÇ¢")) {
		mahoutukai();
	}
	if (!strcmp(player3->JOB, "ëmóµ")) {
		souryo();
	}
	if (!strcmp(player3->JOB, "ïêì¨â∆")) {
		butouka();
	}
	if (!strcmp(player3->JOB, "óVÇ—êl")) {
		asobinin();
	}
}