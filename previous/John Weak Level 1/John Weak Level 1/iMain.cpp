#include "iGraphics.h"
#define screen_width 1280
#define screen_height 720


char bg[] = "img\\bg.bmp";
char weak[] = "img\\weak.bmp";
char muzzle[] = "img\\muzzle.bmp";
char soldier_run[9][50] = { "img\\soldier_idle.bmp", "img\\soldier_run_1.bmp", "img\\soldier_run_2.bmp", "img\\soldier_run_3.bmp",
	"img\\soldier_run_4.bmp", "img\\soldier_run_5.bmp", "img\\soldier_run_6.bmp", "img\\soldier_run_7.bmp", 
	"img\\soldier_run_8.bmp"  };
int soldier_run_index = 0;
int soldier_x = 1300, soldier_y = 180; // second lane er soldier dhorlam

const int max_lane = 3;
int lane = 1;
int lane_offset;
int weak_y;
int weak_x = 150;
bool fire = false;
// bool fire_sound = false;
int fire_timer = 0;


void iDraw()
{
	iClear();
	iShowBMP(0,0,bg);
	if (lane == 1) { weak_y = 80; lane_offset = 90; }
	else if (lane == 2) { weak_y = 150; lane_offset = 45; }
	else if (lane == 3) { weak_y = 230; lane_offset = 0; }


	iShowBMP2(soldier_x , soldier_y, soldier_run[soldier_run_index], 255);

	iShowBMP2(weak_x + lane_offset ,weak_y,weak,255);
	if (fire) {


		/*
		if (fire_sound) {
			PlaySound("audio\\ak47.wav", NULL, SND_ASYNC);
			fire_sound = false;
		}
		*/


		if (++fire_timer < 10)
			iShowBMP2(weak_x+lane_offset + 150, weak_y+148, muzzle, 255);	// muzzle flash position ta HARD-CODED
		else if (fire_timer == 10) {
			fire = false;
			fire_timer = 0;
		}
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

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}
void iKeyboard(unsigned char key)
{
	if (key == 'w')
	{
		if (lane != 3)
			lane++;
	}
	else if (key == 's')
	{
		if (lane != 1) 
				lane--;
	}
	else if (key == ' ') {
		fire = true;
		// fire_sound = true;
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

void hundred_miliseconds() {
	if (soldier_x <= 900) {
		soldier_run_index = 0;
	}
	else {
		soldier_run_index++;
		if (soldier_run_index >= 8) soldier_run_index = 1;
		soldier_x -= 20;
	}
}

int main()
{
	// iSetTimer(500, half_second);
	iSetTimer(100, hundred_miliseconds);

	iInitialize(screen_width, screen_height, "Level 01");
	iStart();
}
