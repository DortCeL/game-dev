#include "iGraphics.h"
#include "variables.h"
using namespace std;
#define screen_width 1280
#define screen_height 720

int level = 1;
const int obstacle_1_starting_position = screen_width + 100;
const int obstacle_2_starting_position = screen_width + 500;
int obstacle_1_x = obstacle_1_starting_position;
int obstacle_2_x = obstacle_2_starting_position;

void iDraw()
{
	iClear();
	if (level == 1) 
	{
		//*********************** BACKGROUND ********************//
		iShowBMP(0,0, bg1);


		// ********************** MOVING OBSTACLE ******************* //
		iShowBMP2(obstacle_1_x, base_height, obstacle[0], 255);
		iShowBMP2(obstacle_2_x, base_height, obstacle[1], 255);

		//************************** JUMP *************************//
		if (jump && !over)						  
		{
			standing = false;
			char_y += jump_vel;
			jump_vel -= 0.3;
			if (char_y <= base_height)
			{
				char_y = base_height;
				jump = false;
				standing = true;
				jump_vel = JUMP_VEL;		  
			}

		}


		//*********************** MOVEMENT ***********************//
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


		// **************************** DEATH SCREEN LMAO ****************************//
		if (over) {
			iShowBMP2(char_x, char_y, ded, 255);
			iShowBMP2(150, 300, "img\\game_over.bmp", 255);
		}
		else if (right)
			iShowBMP2(char_x, char_y, running[run_index], 255);
		else if (left)
			iShowBMP2(char_x, char_y, running_L[run_index], 255);


		// ************************* BULLET ************************* //
		if (shoot_right || shoot_left) {
			shooting = true;
			if (shoot_right && !shoot_left)
				bullet_x += bullet_vel;
			else if (shoot_left && !shoot_right)
				bullet_x -= bullet_vel;
		
			if (bullet_x >= screen_width || bullet_x <= 0) {
				bullet_visible = false;
				shoot_right = false;
				shoot_left = false;
				shooting = false;
			}
		}
		if ( bullet_visible)
			if (right)
				iShowBMP2(bullet_x, bullet_y, bullet, 255);
			else if (left)
				iShowBMP2(bullet_x, bullet_y, bullet_L, 255);
		}
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

		bullet_x = char_x + 10;
		bullet_y = char_y + 50;
		
		if (right) {
			shoot_right = true;
			shoot_left = false;
		}
		else if (left) {
			shoot_left = true;
			shoot_right = false;
		}
			
		bullet_visible = true;
		
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

void hundred_miliseconds()
{
	if ( !standing )
	{
		run_index++;
		if (run_index >= 9 ) run_index = 0;
	}
	else run_index = 0;
}

void twenty_miliseconds() {
	obstacle_1_x -= 5;
	if (obstacle_1_x <= 0) {
		obstacle_1_x = obstacle_1_starting_position;
	}
	obstacle_2_x -= 5;
	if (obstacle_2_x <= 0) {
		obstacle_2_x = obstacle_2_starting_position;
	}
}


int main()
{

	iSetTimer(100, hundred_miliseconds);	
	iSetTimer(20, twenty_miliseconds);

	iInitialize(screen_width, screen_height, "JOHN WEAK");

	iStart();
	
	return 0;
}


// ENEMY ADD KORSI KAJ KORE NA BALSAL