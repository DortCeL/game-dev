# include <iostream>
# include "iGraphics.h"
# include "LevelThree.h"

#define screenWidth 1280
#define screenHeight 720
using namespace std;


int level = 3;
int gameState = 0;
/* gamestate =	-1  -> main menu
				0.1  -> LEVEL 1 PROLOGUE   ( play click korle gameState 0 hoy, but tokhoni 0.1 kore dewa hoise; space chaple 0 hobe, level 1 ashbe;
				0   -> level 1
				0.2 -> level 1 Completed Victory screen
				0.3 -> level 1 epilogue
				0.8 -> pause
				0.9 -> death screen
*/





void iDraw()
{
	iClear();
	level_3();
}

void iPassiveMouse(int mx, int my)
{
	
}

void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}


void iKeyboard(unsigned char key)
{
	
	if (gameState == 0 && level == 3) {

		// RESTART
		if (key == 'r') {
			RESTART();
		}





		if (key == 'q')
		{
			if (!punch) {
				punch = true;
				boss_takes_damage();
			}
		}
		else if (key == 'e')
		{
			if (!kick1)
			kick1 = true;
		}
		else if (key == 'f')
		{
			if (!kick2)
			kick2 = true;
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



void three_hundred(){

	if (gameState == 0 && level == 3) {
		boss_move_generator_function();
	}
}





int main()
{
	srand(time(NULL));

	iSetTimer(250, three_hundred);

	iInitialize(screenWidth, screenHeight, "JoHn wEaK");

	iStart();

	return 0;
}

