#include "iGraphics.h"

#define screen_height 1280
#define screen_width 720
int level = 3;


char bg3[] = "img\\level_3_bg.bmp";
char munem[3][50] = { "img\\idle.bmp", "img\\punch.bmp", "img\\kick.bmp" };
int munem_index = 0;

int munem_x = 200;
int munem_y = base_height;
bool punch = false;
bool kick = false;
bool idle = true;

int base_height = 100;



void iDraw()
{
	iClear();

	// ****************** background ***************** //
	iShowBMP(0,0, bg3);

	// ****************** BOSS ********************* //
	//iShowBMP2(screen_height/2 - 150, screen_width/2 - 150, kingpin, 255);

	// ****************** MUNEM ********************** //
	iShowBMP2(munem_x, munem_y, munem[munem_index], 255);

}

void iMouseMove(int mx, int my) 
{
	
}
void iPassiveMouseMove(int mx, int my)
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
	if (key == 'e')
	{
		punch = true;
		kick = false;
		idle = false;
	}
	else if (key == 'q')
	{
		kick = true;
		punch = false;
		idle = false;
	}
	else if (key == 's')
	{
		idle = true;
		punch = false;
		kick = false;
	}
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/

void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
				
	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}


static int function_call = 0;
int call_limit = 1;

void func()
{
	if (level == 3)
	{
		if (function_call == call_limit)
		{
			punch = false;
			kick = false;
			idle = true;
			function_call = 0;
		}
		else if (punch && !kick && !idle)
		{
			munem_index = 1;
			function_call++;
		}
		else if (kick && !punch && !idle)
		{
			munem_index = 2;
			function_call++;
		}
		else if (idle && !punch && !kick)
		{
			munem_index = 0;
			function_call++;
		}
		
	}
}

int main()
{
	iSetTimer(500, func);
	iInitialize(screen_height, screen_width, "Level 03");

	iStart();
	
	return 0;
}