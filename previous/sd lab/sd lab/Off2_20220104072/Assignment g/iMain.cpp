



# include "iGraphics.h"
int mposx,  mposy;
/*
	function iDraw() is called again and again by the system.
*/
char bg[]="bg\\one.bmp";
char ball[4][20]={"item\\ball.bmp","item\\spike.bmp","item\\flat.bmp"};
int x=0;
int flag=0;


void iDraw()
{
	//place your drawing codes here
	iClear();
	iShowBMP(0,0,bg);
	iShowBMP2(600,60,ball[1],255);
	if(x>=570){
		x=570;
		flag=1;
		}
	if(flag)
	{
		iText(250,200,"BALL RUINED",GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(570,60,ball[2],255);
	}
	else
	{
		iShowBMP2(x,60,ball[0],0);
	}

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'd')
	{
		//do something with 'q'
		x=x+5;
	}
	if(key == 'a')
	{
		//do something with 'a'
		x=x-5;
	}
	//place your codes for other keys here
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

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}
//
int main()
{
	//place your own initialization codes here.
	iInitialize(700, 400, "Assignment 2");
	return 0;
}
