// INCLUDES

#include "lib/render.c/shape.c"
#include "organism.c"
#include "random.c"

// SIM LOOP

void sim(int org_count, int elim_min, int elim_max){
	struct canvas surface = new_canvas(40,20);
	surface = reset_canvas(surface);
	struct organism_list list;
	for(int i = 0; i < org_count; i++){
		list = new_org(list, rando(1,39), rando(1,19), rando(-1,1), rando(-1,1));
	}
	printf("%i", rando(1,2));
	printf(" ");
	printf("%i", rando(1,2));
	while(1 == 0){
		system("clear");
		surface = reset_canvas(surface);
		for(int i = 0; i < EOA(list); i++){
			surface = plot(surface, '#', list.organisms[i].x, list.organisms[i].y);
		}
		render_canvas(surface);
	}
}
