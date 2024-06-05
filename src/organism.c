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

// MAKE NEW ORGANISM

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

// ORGANISM MOVEMENT

struct organism move_org(struct organism org, int max_x, int max_y){
	int dest_x = org.x + org.task_x;
	int dest_y = org.y + org.task_y;
	if(dest_x < max_x){
		if(dest_x >= 0){
			org.x += org.task_x;
		}
	}
	if(dest_y < max_y){
		if(dest_y >= 0){
			org.y += org.task_y;
		}
	}
	return org;
}
