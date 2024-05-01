# include "iGraphics.h"

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
int base_position_x = screenWidth / 2;
int base_position_y = screenHeight / 2 - 50;


int char_x = base_position_x;
int char_y = base_position_y;

int jump_height = 20;
int jump_velocity = jump_height;
int jump_starting_position = char_y;
int move_velocity = 0;

bool jump = false;
bool move_right = false;
bool move_left = false;

void iDraw()
{
	iClear();
	iSetColor(255, 255, 255);
	iLine(0, (screenHeight/2) - 55, screenWidth, (screenHeight/2) - 55);
	//iSetColor(85, 60, 200);
	//iFilledCircle(char_x, char_y, 50);
	//iSetColor(255,255,255);
	//iFilledCircle(char_x-25, char_y+15, 5, 100);

	iShowBMP2(char_x, char_y, "mc2.bmp", 0);

}
void charJump()
{
	char_y += jump_velocity;
	if (char_y < base_position_y) {
		char_y = base_position_y;
	} else {
		jump_velocity--;
	}
}
void moveRight()
{
	if (move_velocity <= 5)
		move_velocity++;
	char_x += move_velocity;
}
void moveLeft()
{
	if (move_velocity <= 5)
		move_velocity++;
	char_x -= move_velocity;
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

void iKeyboard(unsigned char key)
{
	if(key == 'a')
	{
		move_velocity = 0;
		iSetTimer(10, moveLeft);
	}
		
	else if (key == 'd')
	{
		move_velocity = 0;
		iSetTimer(10, moveRight);
	}
	
	else if (key == ' ')
	{
		iSetTimer(10, charJump); 
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


