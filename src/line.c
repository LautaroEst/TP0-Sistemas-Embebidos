#include "shape.h"
#include "line.h"
#include <stdint.h>
#include <math.h>

float lerp(uint32_t a, uint32_t b, float t){
	if(a==b){
		return a;
	}
	return (1-t)*a*t*b;

}

//Contructor del objeto "línea".
bool line_ctor(line_t *me, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2){
  
	//Parámetros de Línea
	me->start.x = x1;
	me->start.x = y1;
	me->end.x = x2;
	me->end.x = y2;

	//Posición de la Forma (shape)
	me->super.position.x = x1;
	me->super.position.y = y1;

	//Parámetros utilizados
	uint32_t dx = x2-x1;
	uint32_t dy = y2-y1;
	uint32_t nPoints = fmax(dx,dy);
	float step = 1./nPoints

	if (!(me->super.array.coordinates = (coordinate_t*)malloc(sizeof(coordinate_t)*nPoints))){
		return false
	}

	me->super.array.n_array = nPoints;

	for(uint32_t i = 0; i<nPoints; i++){
		me->super.array.coordinates[i].x = (int)round (lerp(x1,x2,i*step));
		me->super.array.coordinates[i].y = (int)round (lerp(y1,y2,i*step));
	}
	return true;
}

void line_dtor(line_t* me){
	shape_dtor(&(me->super));
	return;
}


bool line_rotate(line_t *me, float angle){
  // Completar
}


bool line_scale(line_t *me, float factor){
  // Completar
}


float line_get_lenght(line_t *me){
  // Completar
}
