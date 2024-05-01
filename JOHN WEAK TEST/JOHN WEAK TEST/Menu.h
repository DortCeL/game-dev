

void draw_menu() {
	// Main Menu
	iShowBMP(0, 0, bg);
	for (int i = 0; i < 3; i++)
	{
		iShowBMP2(bCordinate[i].x, bCordinate[i].y, buttons[i], 0);
	}
}

void place_menu_buttons() {
	int sum = 250;
	for (int i = 2; i >= 0; i--){
		bCordinate[i].x = 50;
		bCordinate[i].y = sum;
		sum += 150;
	}
}