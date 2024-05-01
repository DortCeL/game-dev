#include "iGraphics.h"

#define screen_height 1280
#define screen_width 720


char bg[] = "img\\level_2_bg.bmp";
char crosshair[] = "img\\crosshair.bmp";
char kingpin[] = "img\\kingpin.bmp";
char haat[] = "img\\haat.bmp";

char goon[] = "img\\goon.bmp";


int cross_x = screen_height / 2;
int cross_y = screen_width / 2;


void iDraw()
{
	iClear();

	// ****************** background ***************** //
	iShowBMP(0,0, bg);

	// ****************** KINGPIN ********************* //
	iShowBMP2(screen_height/2 - 150, screen_width/2 - 150, kingpin, 255);

	// ****************** GOONS ********************** //
	iShowBMP2(50, 150, goon, 255);

	// ****************** HANDS ************************ //
	iShowBMP2(cross_x * 0.05, cross_y * 0.05, haat, 255);

	// ****************** crosshair ******************* //
	iShowBMP2(cross_x - 60, cross_y - 60, crosshair, 255);

}

void iMouseMove(int mx, int my) 
{
	
}
void iPassiveMouseMove(int mx, int my)
{
	cross_x = mx;
	cross_y = my;
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
	if (key == 'r')
	{


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

int main()
{

	iInitialize(screen_height, screen_width, "Level 02");

	iStart();
	
	return 0;
}