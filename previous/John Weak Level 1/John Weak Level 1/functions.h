#include "variables.h"

void runF()
{
	if ( !standing )
	{
		run_index++;
		if (run_index >= 9 ) run_index = 0;
	}
	else run_index = 0;
	
}