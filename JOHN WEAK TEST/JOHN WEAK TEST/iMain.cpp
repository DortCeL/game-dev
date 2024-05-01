# include <iostream>
# include "iGraphics.h"
# include "variables.h"
# include "LevelOne.h"
# include "LevelTwo.h"
# include "LevelThree.h"
# include "Menu.h"
# include "deathScreen.h"
# include <ctime>

using namespace std;


int level = 1;
/* gamestate =	-1  -> main menu
				0.1  -> LEVEL 1 PROLOGUE   ( play click korle gameState 0 hoy, but tokhoni 0.1 kore dewa hoise; space chaple 0 hobe, level 1 ashbe;
				0   -> level 1
				0.2 -> level 1 Completed Victory screen
				0.3 -> level 1 epilogue
				0.8 -> pause
				0.9 -> death screen
				3.9 level 3 death
*/


#define screenWidth 1280
#define screenHeight 720


void RESTART(int lvl) {

	if (lvl == 1) {
		
		soldier[0].x = 1400;
		soldier[1].x = 1350;
		soldier[2].x = 1300;
		for (int i = 0; i < 3; i++) {
			soldier[i].dead = false;
			soldier[i].health = 12;
		}

		kill_index = 0;
		fire_timer = 0;
		fire = false;
	}
	else if (lvl == 2) {
		timeindex = 0;
		tlimit = false;
		dedcount = 0;
	}

	else if (lvl == 3) {
		weak_health_index = 0;
		boss_health_index = 0;
		you_died = false;
		victory = false;
	}

}

void iDraw()
{
	iClear();

	if (gameState == -1){
		draw_menu();
	}
	else if (gameState == 0.1) {
		// LEVEL 1 prologue 1
		iShowBMP(0, 0, "img\\cutscene\\level_1_prologue_1.bmp");
	}
	else if (gameState == 0.2) {
		// LEVEL 1 prologue 2
		iShowBMP(0, 0, "img\\cutscene\\level_1_prologue_2.bmp");
	}
	else if (gameState == 0.3) {
		// LEVEL 1 prologue 3
		iShowBMP(0, 0, "img\\cutscene\\level_1_prologue_3.bmp");
	}
	else if (gameState == 0.4) {
		// LEVEL 1 prologue 4
		iShowBMP(0, 0, "img\\cutscene\\level_1_prologue_4.bmp");
	}

	else if (gameState == 2.1) {
		iShowBMP(0, 0, "img\\cutscene\\level_2_prologue_1.bmp");
	}
	else if (gameState == 2.2) {
		iShowBMP(0, 0, "img\\cutscene\\level_2_prologue_2.bmp");
	}


	else if (gameState == 3.1) {
		iShowBMP(0, 0, "img\\cutscene\\level_3_prologue_1.bmp");
	}
	else if (gameState == 3.2) {
		iShowBMP(0, 0, "img\\cutscene\\level_3_victory.bmp");
	}
	else if (gameState == 3.9) {
		iText(300, 400, "Y O U    D I E D", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(320, 340, "press R to retry", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	


	else if (gameState == 0){
		// GAMEPLAY
		if (level == 1)
			level_1();	// Play	Button
		else if (level == 2)
			level_2();
		else if (level == 3)
			level_3();
	}

	else if (gameState == 0.9) {
		death_screen();
	}
	else if (gameState == 0.8) {
		pause();
	}
	

	else if (gameState == 1){
		iShowBMP(0, 0, sc2); // controls Button
	}

	else if (gameState == 2){
		exit(0);	// Quit Button
	}
}

void iPassiveMouse(int mx, int my)
{
	if (gameState == 0 && level == 2) {
		cross_x = mx;
		cross_y = my;
	}
}

void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		if (gameState == -1) {
			// *********************** MENU Buttons Click Logic *************************** //
			for (int i = 0; i < 3; i++){
				if (mx >= bCordinate[i].x && mx <= bCordinate[i].x + 220 && my >= bCordinate[i].y && my <= bCordinate[i].y + 75){
					// button width = 220, height = 75
					gameState = i;
					if (gameState == 0) gameState = 0.1;    															// *************************************** EITA PLAY BUTTON
				}
			}

		}
		else if (gameState == 0 && level == 2) {
			if (!tlimit)
			{
				for (int i = 0; i < 1; i++)
				{
					if ((mx >= 310 && mx <= 410) && (my >= 330 && my <= 390) && !enemy[i].dead)
					{
						enemy[i].dead = true;
						enemy[i].killtxt = true;
						dedcount++;


					}
					else if ((mx >= 670 && mx <= 770) && (my >= 330 && my <= 390) && !enemy[i + 1].dead)
					{
						enemy[i + 1].dead = true;
						enemy[i + 1].killtxt = true;
						dedcount++;


					}
					else if ((mx >= 1030 && mx <= 1130) && (my >= 330 && my <= 390) && !enemy[i + 2].dead)
					{
						enemy[i + 2].dead = true;
						enemy[i + 2].killtxt = true;
						dedcount++;

					}
				}
			}
		}

		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}

bool pause_bool = false;

void iKeyboard(unsigned char key)
{
	if (key == 'p') {
		double temp = 0;
		if (!pause_bool)
		{
			temp = gameState;
			pause_bool = pause_bool ? false : true;
			gameState = 0.8;
		}
		else if (pause_bool) {
			pause_bool = false;
			gameState = temp;

		}

	}
	if (key == 'x') {
		gameState = -1;
		RESTART(1);
		RESTART(2);
		RESTART(3);
	}
	if (gameState == 0.1) {
		if (key == 'g')
			gameState = 0.2;
	}
	else if (gameState == 0.2) {
		if (key == 'g') gameState = 0.3;
	}
	else if (gameState == 0.3) {
		if (key == 'g') gameState = 0.4;
	}
	else if (gameState == 0.4) {

		if (key == ' ') {
			gameState = 0;
			level = 1;
		}
	}
	else if (gameState == 0.4) {

		if (key == ' ') {
			gameState = 2.1;
			level = 2;
		}
	}
	else if (gameState == 2.1) {

		if (key == 'g') {
			gameState = 2.2;
		}
	}

	else if (gameState == 2.2) {

		if (key == ' ') {
			gameState = 0;
			level = 2;
		}
	}


	else if (gameState == 3.1) {

		if (key == ' ') {
			gameState = 0;
			level = 3;
		}
	}

	else if (gameState == 3.9) {

		if (key == 'r') {
			gameState = 0;
			level = 3;
			RESTART(3);
		}
	}


	
	else if (gameState == 0 && level == 1) {
		if (key == 'w')
		{
			if (lane != 3)
				lane++;
		}
		else if (key == 's')
		{
			if (lane != 1)
				lane--;
		}
		else if (key == ' ') {
			PlaySound("audio\\gun.wav", NULL, SND_ASYNC);
			fire = true;
			collision(lane);
		}

	}
	else if (gameState == 0 && level == 2) {
		if (tlimit) {
			if (key == 'r')
			{
				timeindex = 0;
				tlimit = false;
				dedcount = 0;
				iSetColor(255, 255, 255);

			}
		}
	}

	else if (gameState == 0 && level == 3) {
		if (key == 'q')
		{
			if (!punch) {
				punch = true;
				boss_takes_damage();
			}
		}
		else if (key == 'e')
		{
			if (!kick1) {
				kick1 = true;
				boss_takes_damage();
			}
		}
		else if (key == 'f')
		{
			if (!kick2) {
				kick2 = true;
				boss_takes_damage();
			}
		}
		else if (key == 'a')
		{
			
			munem_x -= 60;
		}
		else if (key == 'd')
		{
			
			munem_x += 60;
		}
	}
}


void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
}


void hundred_fifty_miliseconds() {
	if (gameState == 0 && level == 1) {
		soldier_running_function();
	}

}

void half_second(){
	if (gameState == 0 && level == 3) {
		boss_move_generator_function();
	}
}


void timecount()
{
	if (gameState == 0 && level == 2) {
		if (tcount && dedcount != target_score)
		{
			timeindex++;
		}


		if (timeindex >= target_time)
		{
			tlimit = true;
			enemy[0].dead = false;
			enemy[1].dead = false;
			enemy[2].dead = false;
		}
	}

}

void popup() {

	if (gameState == 0 && level == 2) {
		if (!tlimit && dedcount != target_score){
			int random = rand() % 3;
			enemy[random].dead = enemy[random].dead ? false : true;
		}
	}
}




int main()
{
	srand(time(NULL));

	iSetTimer(150, hundred_fifty_miliseconds);
	iSetTimer(1000, timecount);
	iSetTimer(750, popup);
	iSetTimer(500, half_second);

	place_menu_buttons();

	iInitialize(screenWidth, screenHeight, "JoHn wEaK");

	iStart();

	return 0;
}

