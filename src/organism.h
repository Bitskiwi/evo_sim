// HEADER GUARD

#ifndef ORGANISM_H
#define ORGANISM_H

// ORGANISM STRUCTURE

struct organism {
	int x;
	int y;
	int task_x;
	int task_y;
	int init;
};

// ORGANISM LIST

struct organism_list {
	struct organism organisms[100];
};

// ORGANISM CONSTRUCTOR

struct organism_list add_org(int x, int y, int task_x, int task_y);

#endif
