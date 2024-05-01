void initiate_level_1 () {
	//*********************** BACKGROUND ********************//

	iShowBMP(0,0, bg);

	//*********************** JUMP ********************//
	if (jump && !over)						  
	{
		standing = false;
		char_y += jump_vel;
		jump_vel -= 0.3;
		if (char_y <= base_height)
		{
			char_y = base_height;
			jump = false;
			standing = true;
			jump_vel = JUMP_VEL;		  
		}

	}


	//*********************** MOVEMENT ***********************//
	if (move_right && !over)
	{
		standing = false;
		char_x += move_vel;
	}

	else if (move_left && !over)
	{
		standing = false;
		char_x -= move_vel;
	}


	// **************************** DEATH SCREEN LMAO ****************************//
	if (over) {
		iShowBMP2(char_x, char_y, ded, 255);
		iShowBMP2(150, 300, "img\\game_over.bmp", 255);
	}
	else if (right)
		iShowBMP2(char_x, char_y, running[run_index], 255);
	else if (left)
		iShowBMP2(char_x, char_y, running_L[run_index], 255);



	// enemy
	iShowBMP2(enemy_x, enemy_y, "img\\enemy.bmp", 255);


	// ************************* BULLET ************************* //
	if (shoot_right || shoot_left) {
		shooting = true;
		if (shoot_right && !shoot_left)
			bullet_x += bullet_vel;
		else if (shoot_left && !shoot_right)
			bullet_x -= bullet_vel;
		
		if (bullet_x >= screen_width || bullet_x <= 0) {
			bullet_visible = false;
			shoot_right = false;
			shoot_left = false;
			shooting = false;
		}
	}
	if ( bullet_visible)
		if (right)
			iShowBMP2(bullet_x, bullet_y, bullet, 255);
		else if (left)
			iShowBMP2(bullet_x, bullet_y, bullet_L, 255);

}