# include "iGraphics.h"
#include <iostream>


#define screenWidth 1000
#define screenHeight 600


/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/


int mposx,  mposy;
int char_x = screenWidth / 2;
int char_y = screenHeight / 2;
int char_movement_speed = 2;



void iDraw()
{
	iClear();
	iSetColor(255, 255, 255);
	// iLine(0, (screenHeight/2) - 60, screenWidth, (screenHeight/2) - 60);
	iSetColor(85, 60, 200);
	iFilledCircle(char_x, char_y, 50);

}

void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

int jump_height = 20;
int jump_velocity = jump_height;
int jump_starting_position = char_y;


void charJumpFunction()
{
	char_y += jump_velocity;
	jump_velocity--;
	if (char_y <= jump_starting_position)
	{
		jump_starting_position--;
		jump_velocity = jump_height;
	}
	
}




void charJump()
{
	iSetTimer(10, charJumpFunction);
}

// movement variables balsal
int move_velocity = 0;	// this has to reset after movement button is altered ..................... KEMNEE KORE BAAAAAL DAAAA
int movement_start;

int move_count = 1;

void moveRightFunction()
{
	movement_start = char_x;
	char_x += move_velocity;
	
	// acceleration er part ........
	if (char_x - movement_start <= 10)
			move_velocity++;
	

}

void moveLeftFunction()
{
	movement_start = char_x;
	char_x -= move_velocity;
	
	// acceleration er part ........
	if (movement_start - char_x >= 10)
			move_velocity++;
}


void moveRight()
{
	move_count++;
	if (move_count %2 != 0)
		move_velocity = 0;
	iSetTimer(10, moveRightFunction);
}

void moveLeft()
{ 
	iSetTimer(10, moveLeftFunction);
}


void iKeyboard(unsigned char key)
{
	if(key == 'd')
	{
		moveRight();

	}
		
	else if (key == 'a')
	{
		moveLeft();
			
	}
	
	else if (key == ' ')
	{
		charJump();
	}

	else if (key == 'r')
	{
		char_x = screenWidth / 2;
		char_y = screenHeight / 2;
	}
	
}

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}


int main()
{
	iInitialize(screenWidth,  screenHeight, "GayMe");
	return 0;
}


