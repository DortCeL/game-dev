# include "iGraphics.h"

int mposx,  mposy;
/*
	function iDraw() is called again and again by the system.
*/

char sprite[65][20] = {
		"sprite\\tile000.bmp",
		"sprite\\tile001.bmp",
		"sprite\\tile002.bmp",
		"sprite\\tile003.bmp",
		"sprite\\tile004.bmp",
		"sprite\\tile005.bmp",
		"sprite\\tile006.bmp",
		"sprite\\tile007.bmp",
		"sprite\\tile008.bmp",
		"sprite\\tile009.bmp",
		"sprite\\tile010.bmp",
		"sprite\\tile011.bmp",
		"sprite\\tile012.bmp",
		"sprite\\tile013.bmp",
		"sprite\\tile014.bmp",
		"sprite\\tile015.bmp",
		"sprite\\tile016.bmp",
		"sprite\\tile017.bmp",
		"sprite\\tile018.bmp",
		"sprite\\tile019.bmp",
		"sprite\\tile020.bmp",
		"sprite\\tile021.bmp",
		"sprite\\tile022.bmp",
		"sprite\\tile023.bmp",
		"sprite\\tile024.bmp",
		"sprite\\tile025.bmp",
		"sprite\\tile026.bmp",
		"sprite\\tile027.bmp",
		"sprite\\tile028.bmp",
		"sprite\\tile029.bmp",
		"sprite\\tile030.bmp",
		"sprite\\tile031.bmp",
		"sprite\\tile032.bmp",
		"sprite\\tile033.bmp",
		"sprite\\tile034.bmp",
		"sprite\\tile035.bmp",
		"sprite\\tile036.bmp",
		"sprite\\tile037.bmp",
		"sprite\\tile038.bmp",
		"sprite\\tile039.bmp",
		"sprite\\tile040.bmp",
		"sprite\\tile041.bmp",
		"sprite\\tile042.bmp",
		"sprite\\tile043.bmp",
		"sprite\\tile044.bmp",
		"sprite\\tile045.bmp",
		"sprite\\tile046.bmp",
		"sprite\\tile047.bmp",
		"sprite\\tile048.bmp",
		"sprite\\tile049.bmp",
		"sprite\\tile050.bmp",
		"sprite\\tile051.bmp",
		"sprite\\tile052.bmp",
		"sprite\\tile053.bmp",
		"sprite\\tile054.bmp",
		"sprite\\tile055.bmp",
		"sprite\\tile056.bmp",
		"sprite\\tile057.bmp",
		"sprite\\tile058.bmp",
		"sprite\\tile059.bmp",
		"sprite\\tile060.bmp",
		"sprite\\tile061.bmp",
		"sprite\\tile062.bmp",
		"sprite\\tile063.bmp" };

int charY = 0;
int charX = 0;
int charIndex = 0;



void iDraw()
{
	//place your drawing codes here
	iClear();

	iShowBMP2(charX, charY, sprite[charIndex], 0);

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
//

void change ()
{
	charIndex++;
	if (charIndex >= 63)
		charIndex = 0;
}

int main()
{
	//place your own initialization codes here.
	iSetTimer(5, change);

	iInitialize(1600, 900, "Khanki magi simulator");
	return 0;
}
