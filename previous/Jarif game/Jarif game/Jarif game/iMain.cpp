# include "iGraphics.h"
#define upperbackgroundspeed 10
#define lowerbackgroundspeed 12
#define screenwidth 1200
#define screenheight 800
int mposx,  mposy;

char  backgroundImage[4];
struct backgroundCoordinate{
	int x;
	int y;
};
backgroundCoordinate bg[4];


void iDraw()
{
	//place your drawing codes here
	iClear();
	for (int i = 0; i<4; i++){
		iShowImage(bg[i].x, bg[i].y, 600, 800, backgroundImage[i]);
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
	if(key == 'q')
	{
		//do something with 'q'
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

void setAll(){
	int sum = -100;
	for (int i = 0; i<4; i++){
		bg[i].y = 0;
		bg[i].x = sum;
		sum += 600;
	}
}
void bGround(){
	for (int i = 0; i<4; i++){
		bg[i].x -= 10;
		if (bg[i].x <= -700)
			bg[i].x = 1700;
	}
}



int main()
{

	setAll();
	//iSetTimer(1000,planechangeindex);
	iSetTimer(25, bGround);
	iInitialize(screenwidth, screenheight, "demooo");



	backgroundImage[0] = iLoadImage("images//background 1.png");
	backgroundImage[1] = iLoadImage("images//background 2.png");
	backgroundImage[2] = iLoadImage("images//background 3.png");
	backgroundImage[3] = iLoadImage("images//background 4.png");


	iStart();


	
	return 0;
}
