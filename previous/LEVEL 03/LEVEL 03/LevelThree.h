int munem_x = 300;
int munem_y = 100;
int boss_x = 850;
int boss_y = 100;

bool punch = false;
bool kick1 = false;
bool kick2 = false;
bool idle = true;

int attack_timer = 0;
int boss_move_timer = 0;

int boss_move = 0;
bool boss_punch = false;
bool boss_block = false;
bool boss_idle = true;

bool you_died = false; 


char weak_idle_damage[2][50] = { "img\\level_3\\ralf_idle.bmp", "img\\level_3\\ralf_damage.bmp" };
int weak_idle_damage_index;


char weak_health[][4] = { "100", "90", "80", "70", "60", "50", "40", "30", "20", "10", "00" };
int weak_health_index = 0;



char boss_health[][4] = { "500", "490", "480", "470", "460", "450", "440", "430", "420", "410", "400", "390", "380", "370", "360", "350", "340", "330", "320", "310", "300", "290", "280", "270", "260", "250", "240", "230", "220", "210", "200", "190", "180", "170", "160", "150", "140", "130", "120", "110", "100", "90", "80", "70", "60", "50", "40", "30", "20", "10", "00" };
int boss_health_index = 0;

bool victory = false;


void RESTART() {
	weak_health_index = 0;
	boss_health_index = 0;
	you_died = false;

}

typedef struct OBSTACLE {
	int x;
	int y;

	OBSTACLE(int col) {
		if (col == 1) {
			x = 150;
			y = 800;
		}
		else if (col == 2) {
			x = 550;
			y = 780;
		}
		else if (col == 3) {
			x = 950;
			y = 900;
		}
		
	}
};

OBSTACLE obstacle[3] = { OBSTACLE(1), OBSTACLE(2), OBSTACLE(3) };

void generate_obstacle() {
	for (int i = 0; i < 3; i++) {
		obstacle[i].y -= 5;
		if (obstacle[i].y <= 0)
			obstacle[i].y = 900;
	}
}


void boss_takes_damage() {
	if (munem_x + 200 >= boss_x) {
		boss_health_index++;
		if (boss_health_index >= 50) {
			victory = true;
		}
	}
}




void level_3() {

	if (victory == true) {
		iText(560, 400, "Y O U   W O N!", GLUT_BITMAP_TIMES_ROMAN_24);
		return;
	}



	if (!you_died) {

		

		// BACKGROUND
		iShowBMP(0, 0, "img\\level_3\\level_3_bg.bmp");
		iSetColor(255, 255, 255);

		// OBSTACLES
		generate_obstacle();
		for (int i = 0; i < 3; i++) {
			iShowBMP2(obstacle[i].x, obstacle[i].y, "img\\obstacle.bmp", 255);

			if ( obstacle[i].y == munem_y + 200   && obstacle[i].x >= munem_x && obstacle[i].x <= munem_x+100) {
				weak_health_index++; 
				if (weak_health_index >= 10) {
					you_died = true;
				}
				
			}
	
	
		}

		//*********************** HEALTH BAR *******************************//
		iText(200, 650, "John Weak : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350, 650, weak_health[weak_health_index], GLUT_BITMAP_TIMES_ROMAN_24);

		iText(860, 650, "BOSS : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1000, 650, boss_health[boss_health_index], GLUT_BITMAP_TIMES_ROMAN_24);


		// ******************** BOSS *************************** //

		if (boss_punch) {
			if (++boss_move_timer < 25)
				iShowBMP2(boss_x, boss_y, "img\\level_3\\boss\\punch.bmp", 255);
			else if (boss_move_timer >= 25) {
				boss_punch = false;
				boss_move_timer = 0;
			}
		}
		else if (boss_block) {
			if (++boss_move_timer < 25)
				iShowBMP2(boss_x, boss_y, "img\\level_3\\boss\\block.bmp", 255);
			else if (boss_move_timer >= 25) {
				boss_block = false;
				boss_move_timer = 0;
			}
		}
		else if (!boss_punch && !boss_block) {

			iShowBMP2(boss_x, boss_y, "img\\level_3\\boss\\idle.bmp", 255);
		}

		// ***************** John weak ****************** //

		if (punch) {
			if (++attack_timer < 15)
				iShowBMP2(munem_x, munem_y, "img\\level_3\\ralf_punch.bmp", 255);
			else if (attack_timer >= 15) {
				punch = false;
				attack_timer = 0;
			}

		}
		else if (kick1) {
			if (++attack_timer < 20)
				iShowBMP2(munem_x, munem_y, "img\\level_3\\ralf_low_kick.bmp", 255);
			else if (attack_timer >= 20) {
				kick1 = false;
				attack_timer = 0;
			}

		}

		else if (kick2) {
			if (++attack_timer < 20)
				iShowBMP2(munem_x, munem_y, "img\\level_3\\ralf_high_kick.bmp", 255);
			else if (attack_timer >= 20) {
				kick2 = false;
				attack_timer = 0;
			}

		}

		else if (!punch && !kick1 && !kick2) {
			iShowBMP2(munem_x, munem_y, weak_idle_damage[weak_idle_damage_index], 255);
		}

		/*

		if (boss_punch && munem_x + 100 <= boss_x) {
		iShowBMP2(boss_x, boss_y + 50, "img\\level_3\\muzzle.bmp", 255);
		}

		*/

	}

	else {
		// this is when YOU_DIED is true;
		iText(300, 400, "Y O U    D I E D", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(320, 340, "press R to retry", GLUT_BITMAP_TIMES_ROMAN_24); 
	}
	
}


// 0 idle, 1 move left , 2 punch, 3, move right, 4,5,6 block

void boss_move_generator_function() {

	boss_move++;
	if (boss_move == 6) boss_move = 0;
	if (boss_move == 0) { boss_idle = true; boss_punch = false; boss_block = false; }
	else if (boss_move == 2) { boss_x -= 100; }
	else if (boss_move == 3) {	boss_idle = false; boss_punch = true; boss_block = false;
		if (munem_x + 100 >= boss_x)
		{
			weak_idle_damage_index = 1;
			weak_health_index++;
			if (weak_health_index == 10) {
				you_died = true;
			}
		}
	}
	else if (boss_move == 5) { boss_x += 100; }

	/*

	else if (boss_move == 4 || boss_move == 5) { 
		boss_idle = false; boss_punch = false; boss_block = true;
	}

	*/

	
	
}


