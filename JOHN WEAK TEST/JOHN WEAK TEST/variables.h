char buttons[20][50] = { "img\\menu\\play.bmp", "img\\menu\\options.bmp", "img\\menu\\exit.bmp" };
char bg[] = "img\\menu\\bg2.bmp";
char sc1[] = "img\\menu\\sc1.bmp";
char sc2[] = "img\\menu\\sc2.bmp";

struct buttonCordinate{
	int x;
	int y;
}bCordinate[3];


double gameState = -1;

char bg_1[] = "img\\bg.bmp";
char weak[] = "img\\weak.bmp";
char muzzle[] = "img\\muzzle.bmp";
char soldier_run[8][50] = { "img\\level_1\\zombie\\zombie_1.bmp", "img\\level_1\\zombie\\zombie_2.bmp",
"img\\level_1\\zombie\\zombie_3.bmp", "img\\level_1\\zombie\\zombie_4.bmp", "img\\level_1\\zombie\\zombie_5.bmp",
"img\\level_1\\zombie\\zombie_6.bmp", "img\\level_1\\zombie\\zombie_7.bmp", "img\\level_1\\zombie\\zombie_8.bmp" };
int soldier_run_index = 0;



const int max_lane = 3;
int lane = 1;
int lane_offset;
int weak_y;
int weak_x = 150;
bool fire = false;
// bool fire_sound = false;
int fire_timer = 0;





int soldier_x[3] = { 1500, 1400, 1300 };
int soldier_y[3] = { 100, 180, 250 };
int soldier_stop_position[3] = { 1000, 910, 820 };
bool soldier_visible[3] = { true, true, true };
bool soldier_health_bar_visible[3] = { false, false, false };
bool soldier_health[3] = { 100, 100, 100 };
bool soldier_running_into_screen = true;
// second lane = 180