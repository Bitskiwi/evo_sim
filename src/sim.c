// INCLUDES

#include <string.h>
#include "lib/render.c/shape.c"
#include "organism.c"
#include "random.c"

// SIM LOOP

void sim(int org_count, int elim_min, int elim_max){                                     // create a function for the simulation loop
	struct canvas surface = new_canvas(40,20);                                           // create a canvas to draw the simulation onto
	surface = reset_canvas(surface, '.');                                                // initialize the canvas
	struct organism_list list;                                                           // initialize a list for the organisms
	init_rand();
	int cycles = 0;
	int cycle_skips = 0;
	for(int i = 0; i < org_count; i++){                                                  // iterate 
		list = new_org(list, rando(1,39), rando(1,19), rando(-1,1), rando(-1,1));
	}
	printf("press ENTER to continue...");
	getchar();
	while(1){
		cycles++;
		system("clear");
		surface = reset_canvas(surface, '.');
		for(int i = 0; i < EOA(list); i++){
			surface = plot(surface, '#', list.organisms[i].x, list.organisms[i].y);
		}
		render_canvas(surface);
		printf("Cycle: %i", cycles, "\n");
		printf("\n/q (quit)\n/j (jump (n) cycles)\n");
		if(cycle_skips == 0){
			char cmd[100];
			scanf("%s", &cmd);
			if(strcmp(cmd, "/q") == 0){
				break;
			}
			if(strcmp(cmd, "/j") == 0){
				printf("How many cycles to jump? ");
				scanf("%i", &cycle_skips);
			}
		} else {
			cycle_skips--;
		}
	}
}
