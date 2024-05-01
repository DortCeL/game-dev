# include "iGraphics.h"
# include "variables.h"
# include "LevelOne.h"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
	iClear();
	if (gameState == -1){
		//homeMenu
		iShowBMP(0, 0, bg);
		for (int i = 0; i < 3; i++)
		{
			iShowBMP2(bCordinate[i].x, bCordinate[i].y, buttons[i], 0);
		}
	}
	else if (gameState == 0) {
		// play
		level_1();
	}

	else if (gameState == 1){
		// options
		iShowBMP(200, 200, sc2);
	}

	else if (gameState == 2){
		// exit
		exit(0);
	}
	

}



void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// *********************** MENU *************************** //
		for (int i = 0; i < 3; i++){
			if (mx >= bCordinate[i].x && mx <= bCordinate[i].x + 220 && my >= bCordinate[i].y && my <= bCordinate[i].y + 75){
				// button width 220, height 75;
				gameState = i;
			}
		}
		
	}
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'x')
		gameState = -1;

	if (gameState == 0) {
		if (key == 'w')
			if (lane != 3) lane++;

		else if (key == 's')
			if (lane != 1)	lane--;

		else if (key == ' ')
			fire = true;

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

void two_hundred_miliseconds() {
	if (gameState == 0) {
		for (int i = 0; i<3; i++) {
			if (soldier_x[i] <= soldier_stop_position[i]) {
				soldier_run_index = 0;
			} else {
				soldier_run_index++;
				if (soldier_run_index >= 7) soldier_run_index = 1;
				soldier_x[i] -= 20;
			}
		}
	}
}

void menu_buttons(){
	
}

int main()
{
	iSetTimer(100, two_hundred_miliseconds);

	int sum = 250;
	for (int i = 2; i >= 0; i--){
		bCordinate[i].x = 50;
		bCordinate[i].y = sum;
		sum += 150;
	}

	iInitialize(1280, 720, "John wEAK");
	
	iStart();
	return 0;
}