// INCLUDES

#include "lib/render.c/shape.c"
#include "organism.c"
#include "random.c"

// SIM LOOP

void sim(int org_count, int elim_min, int elim_max){                                     // create a function for the simulation loop
	struct canvas surface = new_canvas(40,20);                                           // create a canvas to draw the simulation onto
	surface = reset_canvas(surface);                                                     // initialize the canvas
	struct organism_list list;                                                           // initialize a list for the organisms
	init_rand();
	for(int i = 0; i < org_count; i++){                                                  // iterate 
		list = new_org(list, rando(1,39), rando(1,19), rando(-1,1), rando(-1,1));
	}
	while(1){
		system("clear");
		surface = reset_canvas(surface);
		for(int i = 0; i < EOA(list); i++){
			surface = plot(surface, '#', list.organisms[i].x, list.organisms[i].y);
		}
		render_canvas(surface);
	}
}
