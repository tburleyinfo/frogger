#include <iostream>
#include <cmath>
#include "fin.h"
#include "gfx3.h"
using namespace std;

Finish::Finish()
{
        len = 74;
        wid = 74;
	xFin = 1; 
	yFin = 1;
	fill = false; 
}

Finish::~Finish()
{ }


void Finish::spawn(int x, int y)
{
	if (isFilled()) gfx_circle(xFin, yFin, 37); 
        gfx_rectangle(x, y, len, wid);
        xFin = x + (len/2);
        yFin = y + (wid/2);
}


int Finish::getX()
{ return xFin; }

int Finish::getY()
{ return yFin; }

int Finish::getLen()
{ return len; }

int Finish::getWid()
{ return wid; }

void Finish::setFill(bool tf)
{ fill = tf; }

bool Finish::isFilled()
{ return fill; }


