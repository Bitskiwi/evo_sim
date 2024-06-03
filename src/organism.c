// INCLUDES

#include "organism.h"

// ORGANISM LIST EOA

int EOA(struct organism_list list){                                                     
	for(int i = 0; i < sizeof(list.organisms) / sizeof(list.organisms[0]); i++){
		if(list.organisms[i].init == 0){
			return i;
		}
	}
}

// ORGANISM CONSTRUCTOR

struct organism_list new_org(struct organism_list list, int x, int y, int task_x, int task_y){
	struct organism instance;
	instance.x = x;
	instance.y = y;
	instance.task_x = task_x;
	instance.task_y = task_y;
	instance.init = 1;
	list.organisms[EOA(list)] = instance;
	return list;
}
