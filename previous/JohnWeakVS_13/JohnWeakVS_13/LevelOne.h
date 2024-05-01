#include "iGraphics.h"
#include "variables.h"


void level_1() {

	iShowBMP(0, 0, bg_1);
	if (lane == 1) { weak_y = 80; lane_offset = 100; }	// 90 chilo
	else if (lane == 2) { weak_y = 150; lane_offset = 50; }	// 45 chilo
	else if (lane == 3) { weak_y = 230; lane_offset = 0; }	// 0 chilo

	// ******************* SOLDIERS ************************* //
	for (int i = 2; i >= 0; i--) {
		iShowBMP2(soldier_x[i], soldier_y[i], soldier_run[soldier_run_index], 255);
	}

	// ****************** HITBOX *************************** //
	// 100, 180, 250 soldier er lane;


	iShowBMP2(weak_x + lane_offset, weak_y, weak, 255);
	if (fire) {

		if (++fire_timer < 10)
			iShowBMP2(weak_x + lane_offset + 150, weak_y + 148, muzzle, 255);	// muzzle flash position ta HARD-CODED
		else if (fire_timer == 10) {
			fire = false;
			fire_timer = 0;
		}
	}
}