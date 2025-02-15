// INCLUDES

#include "organism.h"
#include "random.c"

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

// REMOVE ORGANISM

struct organism_list del_org(struct organism_list list, int index){
	for(int i = index; list.organisms[i].init != 0; i++){
		list.organisms[i] = list.organisms[i + 1];
	}
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

// NATURAL SELECTION

struct organism_list nat_select(struct organism_list list, int zone_p1, int zone_p2){
	for(int i = 0; i < EOA(list); i++){
		if(list.organisms[i].x >= zone_p1){
			if(list.organisms[i].x <= zone_p2){
				list = del_org(list, i);
			}
		}
	}
	return list;
}

// ORGANISM REPRODUCTION

struct organism_list repro_org(struct organism_list list, int max_x){
	struct organism_list list_copy = list;
	for(int i = 0; i < EOA(list_copy); i++){
		int x = list.organisms[i].x;
		int y = list.organisms[i].y;
		int task_x = list.organisms[i].task_x;
		int task_y = list.organisms[i].task_y;
		int dest_x = list.organisms[i].x + 1;
		x += rando(-1, 1);
		y += rando(-1, 1);
		if(rando(0, 2) == 0){
			task_x = rando(-1, 1);
			task_y = rando(-1, 1);
		}
		list = new_org(list, x, y, task_x, task_y);
	}
	return list;
}
