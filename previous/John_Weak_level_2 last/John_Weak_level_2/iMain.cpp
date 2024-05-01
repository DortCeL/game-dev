# include "iGraphics.h"
# include <ctime>
# include <iostream>


#define screen_height 720
#define screen_width 1280


char bg[] = "img\\level_2_bg.bmp";
char crosshair[] = "img\\crosshair1.bmp";
char hand[] = "img\\haat.bmp";
char goon[][100] = { "img\\goon1.bmp", "img\\goon2.bmp", "img\\goon3.bmp" };

int cross_x = screen_width / 2;
int cross_y = screen_height / 2;

int target_score = 30;
int target_time = 30;



typedef struct Enemy {
	
	
	int goon_x;
	int goon_y;
	bool dead;
	int column;
	bool killtxt;
	Enemy(int column){
		this->column = column;
		if (column == 1){
			goon_x = 280; goon_y = 100;
		}
		else if (column == 2){
			goon_x = 640; goon_y = 100;
		}
		else{
			goon_x = 1000; goon_y = 100;
		}
		dead =false;
		killtxt=false;
	}

}Enemy;
Enemy enemy[3] = { Enemy(1), Enemy(2), Enemy(3) };


bool tcount = true;
bool tlimit = false;
int timeindex = 0;
char timelmt[][3] = { "30", "29", "28", "27", "26", "25", "24", "23", "22", "21", "20", "19", "18", "17", "16", "15", "14", "13", "12", "11", "10", "9", "8", "7", "6", "5", "4", "3", "2", "1", "0" };
char killkount[][3] = { "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30" };
int dedcount = 0;


int killtxt_timer = 0;

void iDraw()
{
	iClear();

	// ****************** background ***************** //
	iShowBMP(0,0,bg);
	//****************** TIME AND TEXT *********//

	if (tcount && !tlimit)
	{
	iText(1200, 680, timelmt[timeindex], GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else
	{
		iText(650, 550, "TIME'S UP!", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	iText(60, 680, "KILLS :", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(160, 680, killkount[dedcount], GLUT_BITMAP_TIMES_ROMAN_24);
	
	if (tlimit) {
		iText(640, 480, "YOU HAVE DIED", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(620, 400, "Press \"R\" to retry.", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	

	for (int i = 0; i <= 2; i++){

		if (enemy[i].killtxt) {
			
			if (++killtxt_timer < 12)
				iText(enemy[i].goon_x + 30, enemy[i].goon_y + 350, "KILL++", GLUT_BITMAP_TIMES_ROMAN_24);
			else if (killtxt_timer == 12) {
				enemy[i].killtxt = false;
				killtxt_timer = 0;
			}
		}


	if (enemy[i].dead==false)
	{
		iShowBMP2(enemy[i].goon_x , enemy[i].goon_y, goon[i], 255);
		
	}
	}

	// ****************** GOONS ********************** //
	if (!tlimit && dedcount == target_score){
		iText(500, 530, "LEVEL 02 COMPLETE!", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	// ************************* SHIELD ************************** //
	iShowBMP2(280, 65, "img\\shield.bmp", 255);
	iShowBMP2(640, 65, "img\\shield.bmp", 255);
	iShowBMP2(1000, 65, "img\\shield.bmp", 255);



	// ****************** HANDS ************************ //
	if (!tlimit) {
		iShowBMP2(cross_x * 0.05, cross_y * 0.005, hand, 255);

	// ****************** crosshair ******************* //
		iShowBMP2(cross_x - 40, cross_y - 40, crosshair, 255);
	}
}

void iMouseMove(int mx, int my) 
{
	
}
void iPassiveMouseMove(int mx, int my)
{
	cross_x = mx;
	cross_y = my;
}


void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		if (!tlimit)
		{
			for (int i = 0; i < 1; i++)
			{
			if ((mx >= 310 && mx <= 410) && (my >= 330 && my <= 390)   && !enemy[i].dead)
			{
				enemy[i].dead = true;
				enemy[i].killtxt = true;
				dedcount++;


			}
			else if ((mx >= 670 && mx <= 770) && (my >= 330 && my <= 390)    && !enemy[i+1].dead)
			{
				enemy[i+1].dead = true;
				enemy[i+1].killtxt = true;
				dedcount++;


			}
			else if ((mx >= 1030 && mx <= 1130) && (my >= 330 && my <= 390)    && !enemy[i+2].dead)
			{
				enemy[i+2].dead = true;
				enemy[i+2].killtxt = true;
				dedcount++;

			}
			}
		}
		
		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

void iKeyboard(unsigned char key)
{
	if (tlimit) {
		if (key == 'r')
		{
			timeindex = 0;
			tlimit = false;
			dedcount = 0;
			iSetColor(255, 255, 255);

		}
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

void timecount()
{
	if (tcount && dedcount != target_score)
	{
		timeindex++;
	}

	
	if (timeindex >= target_time)
	{
		tlimit = true;
		enemy[0].dead = false;
		enemy[1].dead = false;
		enemy[2].dead = false;
	}
	
}

void popup() {
	if(!tlimit && dedcount != target_score){
		int random = rand() % 3;
		enemy[random].dead = enemy[random].dead ? false : true;
	}
}


int main()
{
	srand(time(NULL));

	iSetTimer(1000, timecount);
	iSetTimer(750, popup);
	iInitialize(screen_width, screen_height, "Level 02");

	iStart();
	
	return 0;
}