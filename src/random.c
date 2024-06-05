// INCLUDES

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "random.h"

// RANDOM INIT

void init_rand(){
	srand(time(NULL));
}

// RANDOM FUNCTION

int rando(int min, int max){
	int r = rand() % (max + 1);
	return r;
}
