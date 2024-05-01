char bg2[] = "img\\level_2_bg.bmp";
char crosshair[] = "img\\crosshair1.bmp";
char hand[] = "img\\haat.bmp";
char goon[][100] = { "img\\goon1.bmp", "img\\goon2.bmp", "img\\goon3.bmp" };

int cross_x = 1280 / 2;
int cross_y = 720 / 2;

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
		dead = false;
		killtxt = false;
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


void level_2() {

	// ****************** background ***************** //
	iShowBMP(0, 0, bg2);
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


		if (enemy[i].dead == false)
		{
			iShowBMP2(enemy[i].goon_x, enemy[i].goon_y, goon[i], 255);

		}
	}

	// ****************** GOONS ********************** //
	if (!tlimit && dedcount == target_score){
		gameState = 3.1;
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


