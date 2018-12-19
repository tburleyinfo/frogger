#include "frog.h"
#include "gfx3.h"
#include "log.h"
// frog class

// constructor
Frog::Frog()
{       
	rad = 37;
	xFrg = 37;
	yFrg = 703;
	dx = 1; 
}

// destructor
Frog::~Frog()
{ }

// methods
void Frog::display(int dx)
{
	gfx_circle(xFrg+dx, yFrg, rad);
	gfx_flush();
}



void Frog::move(char c)
{
	switch(c)
	{
		case 'w':
			//gfx_clear();
			yFrg -= 74;
			/*display();
			  gfx_flush();*/
			break;

		case 'a':
			//gfx_clear();
			xFrg -= 74;
			/*display();
			  gfx_flush();*/                                                                                                                                                                                 break;

		case 's':
			//gfx_clear();
			yFrg += 74;
			/*display();
			  gfx_flush();*/
			break;

		case 'd':
			//	gfx_clear();
			xFrg += 74;
			/*	display();
				gfx_flush();
				*/	break;

		default:
			break;
	}

	// check boundaries
	if (xFrg < rad) xFrg = rad;
	if (xFrg > 740-rad) xFrg = 740-rad;
	if (yFrg > 740-rad) yFrg = 740-rad;
	if (yFrg < rad) yFrg = rad;


	if ((xFrg > 0 && xFrg < 148) && (yFrg - rad < 74)) yFrg = 111;
	if ((xFrg > 222 && xFrg < 296) && (yFrg - rad < 74)) yFrg = 111;
	if ((xFrg > 444 && xFrg < 518) && (yFrg - rad < 74)) yFrg = 111;
	if ((xFrg > 592 && xFrg < 740) && (yFrg - rad < 74)) yFrg = 111;



}     

int Frog::getX()
{ return xFrg; }

int Frog::getY()
{ return yFrg; }

int Frog::getRad()
{ return rad; }

int Frog::setX(int x)
{ xFrg = x; }

int Frog::setY(int y)
{ yFrg = y; }







