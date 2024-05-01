#include "iGraphics.h"

#define screen_height 600
#define screen_width 800


char bg[20] = "img\\bg.bmp";
char obstacle[] = "img\\obstacle.bmp";
char ded[] = "img\\mc\\run\\ded.bmp";

char running[10][50] = {  "img\\mc\\run\\run2.bmp", "img\\mc\\run\\run3.bmp", 
						  "img\\mc\\run\\run4.bmp", 
						  "img\\mc\\run\\run5.bmp", "img\\mc\\run\\run6.bmp", 
						  "img\\mc\\run\\run7.bmp", "img\\mc\\run\\run8.bmp", 
						  "img\\mc\\run\\run9.bmp", "img\\mc\\run\\run10.bmp",
						  "img\\mc\\run\\run1.bmp" };

char running_L[10][50] = {"img\\mc\\run\\run2_L.bmp", "img\\mc\\run\\run3_L.bmp", 
						  "img\\mc\\run\\run4_L.bmp", 
						  "img\\mc\\run\\run5_L.bmp", "img\\mc\\run\\run6_L.bmp", 
						  "img\\mc\\run\\run7_L.bmp", "img\\mc\\run\\run8_L.bmp", 
						  "img\\mc\\run\\run9_L.bmp", "img\\mc\\run\\run10_L.bmp",
						  "img\\mc\\run\\run1_L.bmp" };

int run_index = 0;

int base_height = 70;
int char_x = 100;
int char_y = base_height;
bool jump = false;
bool move_left = false;
bool move_right = false;


double jump_vel = 6;
double move_vel = 1;


bool over = false;
bool standing = true;
bool right = true;
bool left = false;


void iDraw()
{
	iClear();
	iShowBMP(0,0, bg);

	// obstacle
	
	if (char_x >= 630 && char_x <= 640)
	{
		standing = true;
		move_left = false;
		move_right = false;
		iSetColor(255, 255, 0);
		over = true;
	}
	
	if (jump && !over)						   // only  for jump
	{
		standing = false;
		char_y += jump_vel;
		jump_vel -= 0.1;
		if (char_y <= base_height)
		{
			char_y = base_height;
			jump = false;
			standing = true;
			jump_vel = 5;				// global jump_vel er shathe connected      
		}

	}

	if (move_right && !over)
	{
		standing = false;
		char_x += move_vel;
	}

	else if (move_left && !over)
	{
		standing = false;
		char_x -= move_vel;
	}

	if (over) {
		iShowBMP2(char_x, char_y, ded, 255);
		iShowBMP2(150, 300, "img\\game_over.bmp", 255);
	}
	else if (right)
		iShowBMP2(char_x, char_y, running[run_index], 255);
	else if (left)
		iShowBMP2(char_x, char_y, running_L[run_index], 255);

	iShowBMP2(650, base_height, obstacle, 255);

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
	if (key == 'r')
	{
		move_left = false;
		move_right = false;
		char_x = 100;
		char_y = 100;
		jump = true;
		over = false;
		standing = true;
	}
	else if (key == 'd')
	{
		move_left = false;
		move_right = true;

		right = true;
		left = false;
	}
	else if (key == 'a')
	{
		move_right = false;
		move_left = true;

		left = true;
		right = false;
	}
	
	else if (key == ' ' && !jump)
	{
		jump = true;
	}
	else if (key == 's')
	{
		standing = true;
		move_right = false;
		move_left = false;
	}
	
}

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

void runF()
{
	if ( !standing )
	{
		run_index++;
		if (run_index >= 9 ) run_index = 0;
	}
	else run_index = 0;
	
}

int main()
{

	iSetTimer(100, runF);	// 110 chilo

	iInitialize(800, 600, "Assignment");

	iStart();
	
	return 0;
}