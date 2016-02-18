#include "Vector.h"
#include <Math.h>

Vector::Vector(float magnitude, float angle): magnitude(magnitude), angle(angle) {
	while(angle >= 2 * M_PI) {
		angle -= 2 * M_PI;
	}

	while(angle <= 0) {
		angle += 2 * M_PI;
	}
}

Vector Vector::operator+(Vector& v){
	if (magnitude == 0){
		return v;
	}else if (v.magnitude == 0){
		return Vector(magnitude, angle);
	}
	float a = sqrt(magnitude*magnitude+v.magnitude*v.magnitude-2*magnitude*v.magnitude*cos(angle+M_PI-v.angle));
	float angleA = asin(a*sin(angle)/magnitude);
	return Vector(a, angleA);
}
