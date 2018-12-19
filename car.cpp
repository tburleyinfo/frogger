#include <iostream>
#include <cmath>
#include <cstdlib>
#include "car.h"
#include "gfx3.h"

// constructor
Car::Car()
{
	len = 148;
	wid = 74;
	dx = 1;
}

// destructor
Car::~Car()
{ }

// methods
void Car::spawn(int x, int y)
{
	gfx_rectangle(x, y, len, wid);
	xCar = x +(len/2);
	yCar = y +(wid/2); 
}

int Car::getDx()
{return dx;}

int Car::getLen()
{return len;}

int Car::setlen(int x)
{return len = x;} 

int Car::setDx(int x)
{return dx = x;}

int Car::getX()
{ return xCar; }

int Car::getY()
{ return yCar; }

int Car::getWid()
{ return wid; }
