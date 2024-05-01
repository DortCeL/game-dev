// ************************************************************************//
// ************************************************************************//
// ************************************************************************//
// ************************************************************************//
			//	TARGET SCORE 5 DEWA HOISE FOR DEBUGGINIG //

// ************************************************************************//
// ************************************************************************//
// ************************************************************************//


int level_1_target_score = 30;	// change it to 30


typedef struct Soldier {
	int x;
	int y;
	int lane;
	bool dead;
	int health;

	// constructor
	Soldier(int lane) {

		this->lane = lane;

		if (lane == 1) { y = 80; x = 1400; }
		else if (lane == 2) { y = 150; x = 1350; }
		else { y = 230;  x = 1300; }
		dead = false;
		health = 12;

	}
} Soldier;


Soldier soldier[3] = { Soldier(1), Soldier(2), Soldier(3) };




char kills[52][3] = { "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50" };
int kill_index = 0;


void level_1(){
	iShowBMP(0, 0, bg_1);

	iShowBMP2(420, 120, "img\\kid.bmp", 255);

	if (kill_index >= level_1_target_score) {
		gameState = 2.1;
	}

	// ******************** DISPLAY SCORE ************************* //
	iSetColor(255, 255, 255);
	iText(50, 650, "KILLS", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 610, kills[kill_index], GLUT_BITMAP_TIMES_ROMAN_24);

	if (lane == 1) { weak_y = 80; lane_offset = 100; }	// 90 chilo
	else if (lane == 2) { weak_y = 150; lane_offset = 50; }	// 45 chilo
	else if (lane == 3) { weak_y = 230; lane_offset = 0; }	// 0 chilo

	// ******************* SOLDIERS ************************* //
	for (int i = 2; i >= 0; i--) {
		if (soldier[i].dead == false){
			//************** this is for soldier rendering *****************//
			iShowBMP2(soldier[i].x, soldier[i].y, soldier_run[soldier_run_index], 255);
			// ************* health bar rendering + kill confirmed ********************* //
			if (soldier[i].health == 12 && !soldier[i].dead)
				iShowBMP(soldier[i].x, soldier[i].y + 160, "img\\health_bar_3.bmp");
			else if (soldier[i].health == 9 && !soldier[i].dead)
				iShowBMP(soldier[i].x, soldier[i].y + 160, "img\\health_bar_2.bmp");
			else if (soldier[i].health == 6 && !soldier[i].dead)
				iShowBMP(soldier[i].x, soldier[i].y + 160, "img\\health_bar_1.bmp");
			else if (soldier[i].health == 3 && !soldier[i].dead)
				iShowBMP(soldier[i].x, soldier[i].y + 160, "img\\health_bar_0.bmp");
			else {
				// ******************* KILL CONFIRMED HERE *****************//
				soldier[i].x = 1400;
				soldier[i].health = 12;
				// ****************** SCORING SYSTEM EIKHANE THAKBE **************** //
				kill_index++;
			}

			//********************ENEMY COLLIDES WITH LITTLE GIRL*******************  //

			if (soldier[i].x <= 400) {
				gameState = 0.9;
			}
		}
	}
	
	// ****************** John Weak ************************* //
	iShowBMP2(weak_x + lane_offset, weak_y, weak, 255);

	// ****************** Muzzle Flash ********************** //
	if (fire) {
		
		if (++fire_timer < 10)
			iShowBMP2(weak_x + lane_offset + 140, weak_y + 132, muzzle, 255);	// muzzle flash position ta HARD-CODED
		else if (fire_timer == 10) {
			fire = false;
			fire_timer = 0;
		}
	}
}


void collision(int lane) {
	for (int i = 0; i < 3; i++) {
		if (soldier[i].lane == lane) {
			if (soldier[i].health != 0)
				soldier[i].health -= 3;
		}
	}
}


void soldier_running_function() {
	for (int i = 0; i<3; i++) {
			soldier_run_index++;
			if (soldier_run_index >= 7) soldier_run_index = 0;
			soldier[i].x -= 30;
	}
}