
/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/9/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: Implementation of derived class for small fungi.
*/

#include "Fungus.h"
#include "Miscellaneous.h"
#include <cmath>

Fungus::Fungus(double x, double y, double z) {
	consumption_amount = 2;
	consumption_time = 5;
	reproduction_amount = 2;
	reproduction_time = 4;
	reproduction_counter = reproduction_time;
	consumption_food_counter = consumption_amount;
	consumption_time_counter = consumption_time;
	age = 0;
	movement = 2;
	spawn_distance = 4;
	visibility = 1;
	fertility = 2;
	setLocation(x, y, z);
}

//getters
double Fungus::get_fertility() {
	return fertility;
}

//setters
void Fungus::set_fertility() {
	double temper = exp((-1/200) * pow((temperature - 25), 2));
	fertility = 2 * temper * (1 + temper);
}

//other




void Fungus::reproduce(Fungus *O, double x_max, double y_max, double z_max) {
	
	double theta, phi, x, y, z;

	do {
		theta = fRand(0, 2 * 3.14159265);
		phi = fRand(0, 2 * 3.14159265);


    x = spawn_distance * cos(phi) * cos(theta);
		y = spawn_distance * cos(phi) * sin(theta);
		z = spawn_distance * sin(phi);
	} while((x > x_max) || (x < -(x_max)) || (y > y_max) || (y < -(y_max)) || (z > z_max) || (z < -(z_max)));
	O->setLocation(x, y, z);

}
void Fungus::aged() {
	age++;
	movement = movement - (age/20); //decereases movement the older the cell is, although this is scaled by the constant 10. Accumulates
	spawn_distance = 4 - (age / 100);//decreases spawn distance as the cell gets older, scaled by the constant 100. Acculmulates
}
Fungus Fungus::operator+(Bacteria *b) {
	Point_3D newLocation = b->getLocation();
	this->setLocation(newLocation);
	dec_con_food_counter();
	//	delete b;
	return *this;
}


