void death_screen() {
	iSetColor(255, 255, 255);
	iText(580, 350, "TASK FAILED", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(530, 320, "You could not protect her", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(240, 30, 0);
	iText(570, 100, "press X to return to main menu", GLUT_BITMAP_TIMES_ROMAN_24);
}

void pause(){
	iSetColor(255, 255, 255);
	iText(580, 350, "P A U S E D", GLUT_BITMAP_TIMES_ROMAN_24);
}