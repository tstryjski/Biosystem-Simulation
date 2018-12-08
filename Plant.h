/*
Authors: Andrew Yoder, Thomas Stryjski, Zachary O'Brien
Email: aby7159@rit.edu, tgs9181@rit.edu, zjo5244@rit.edu
Date: 12/8/18
Class: EEEE-346-01
Assignment: Project 3

Purpose: derived class for macroorganisms; herbivore?
*/

#include "MacroOrganism.h"
#include <cmath>
#pragma once


class Plant : public MacroOrganism {
protected:
	double sunlight;
	double co2 = 0;
	double o2 = 1;
	double fertility;

public:
	//constructors
	Plant(double x, double y);

	//getters
	double get_o2();

	//setters
	void set_co2(double x);
	void set_sunlight();
	void set_fertility(); //determines reproduction values as a function of temperature and sunlight

	//other
	void reproduce();
	void aged(int AGE);
	double fRand(double fMin, double fMax);
};