
# include "iGraphics.h"

struct buttonCordinate{

	int x;
	int y;
}bCordinate[3];
int mposx,  mposy;

char buttons[20][20] = { "img\\play.bmp", "img\\options.bmp", "img\\exit.bmp" };
char bg[] = "img\\bg2.bmp";
char sc1[20] = "img\\sc1.bmp";
char sc2[20] = "img\\sc2.bmp";
/*
	function iDraw() is called again and again by the system.
*/

int gameState = -1;
void iDraw()
{
	//place your drawing codes here
	iClear();
	
	if (gameState == -1){
		//homeMenu
		iShowBMP(0, 0, bg);
		for (int i = 0; i < 3; i++)
		{
			iShowBMP2(bCordinate[i].x, bCordinate[i].y,buttons[i], 0);
		}
	}

	else if (gameState == 0){
		iShowBMP(200, 200, sc1);
	}
	else if (gameState == 1){
		iShowBMP(200, 200, sc2);
	}
	else if (gameState == 2){

	}
	else{

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
		for (int i = 0; i < 3; i++){
			if (mx >= bCordinate[i].x && mx <= bCordinate[i].x + 220 && my >= bCordinate[i].y && my <= bCordinate[i].y + 75){
				gameState = i;
			}
		}
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
int main()
{
	//place your own initialization codes here.
	int sum = 250;
	for (int i = 2; i >= 0; i--){
		bCordinate[i].x = 50;
		bCordinate[i].y = sum;
		sum += 150;
	}
	iInitialize(1366, 768, "demooo");
	return 0;
}
