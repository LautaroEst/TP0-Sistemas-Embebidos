
#include "shape.h"
#include "image.h"
#include "math.h"

bool shape_ctor(shape_t *me, coordinates_array_t *array, uint32_t position_x, uint32_t position_y){
	
	nPoints = array->n_array;

	if (!(me->array.coordinates = (coordinate_t*)malloc(sizeof(coordinate_t)*nPoints))){
		return false
	}
	
	//Ubicación de la figura
	me->position.x = position_x;
	me->position.y = position_y;

	//Copio la forma
	me->array = &array;

	return true;
}

void shape_dtor(shape_t *me){

	free(me->array.coordinates);
}

bool shape_move(shape_t *me, uint32_t dx, uint32_t dy){
	me->position.x = me->position.x + dx;
	me->position.y = me->position.y + dy;
}

float shape_distance_from(shape_t *me, shape_t *shape){
	dx = me->position.x - shape->position.x;
	dy = me->position.y - shape->position.y;
	return sqrt(pow(dx,2)+pow(dy,2));
}

bool shape_plot(shape_t *me, image_t *image){
	// Completar
}