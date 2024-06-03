// INCLUDES

#include <stdlib.h>
#include <time.h>
#include "random.h"

int rando(int min, int max){
	srand(time(0));
	int r =((rand() / RAND_MAX) * (max - min + 1)) + min;
	return r;
}
