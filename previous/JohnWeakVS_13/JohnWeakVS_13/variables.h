#include "iGraphics.h"

int gameState = -1;

// NOMAN begin

struct buttonCordinate{
	int x;
	int y;
}bCordinate[3];
int mposx, mposy;

char buttons[20][50] = { "img\\menu\\play.bmp", "img\\menu\\options.bmp", "img\\menu\\exit.bmp" };
char bg[] = "img\\menu\\bg2.bmp";
char sc1[] = "img\\menu\\sc1.bmp";
char sc2[] = "img\\menu\\sc2.bmp";

// NOMAN end

char bg_1[] = "img\\bg.bmp";
char weak[] = "img\\weak.bmp";
char muzzle[] = "img\\muzzle.bmp";
char soldier_run[7][50] = { "img\\soldier_idle.bmp", "img\\soldier_run_1.bmp", "img\\soldier_run_2.bmp", "img\\soldier_run_3.bmp",
"img\\soldier_run_4.bmp", "img\\soldier_run_5.bmp", "img\\soldier_run_6.bmp" };
int soldier_run_index = 0;

int soldier_x[3] = { 1500, 1400, 1300 };
int soldier_y[3] = { 100, 180, 250 };
int soldier_stop_position[3] = { 1000, 910, 820 };
// second lane = 180

const int max_lane = 3;
int lane = 1;
int lane_offset;
int weak_y;
int weak_x = 150;
bool fire = false;
// bool fire_sound = false;
int fire_timer = 0;