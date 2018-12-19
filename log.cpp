#include <iostream> 
#include "gfx3.h" 
#include "log.h"
//#include "frog.h"

using namespace std; 

Interact::Interact(){

ln = 142; 
wd = 74; 
dxR= 1;

}

Interact::~Interact(){};

//void Interact::Interact() {}
void Interact::exist_log(int a, int b)
{

gfx_rectangle(a, b, ln, wd);  
xLog = a + (ln/2); 
yLog = a + (wd/2);
}

int Interact::getX()
{return xLog;} 

int Interact::getY()
{return yLog;} 

int Interact::getLen()
{return ln;}

int Interact::getWid()
{return wd;}

float Interact::get_dxR() 
{ return dxR;}

float Interact::setdxR(int x) 
{ return dxR = x; } 

float Interact::setlen(int x)
{return ln = x;}







/*
void Interact::Left()
{ 

Interact a; 
a.exist_log();

float dx = 1, dy = 1; 

float xc = SIZE; 
float yc = SIZE/2; 
float r = SIZE/4;

sim_square(xc, yc, r);
xc += dx;   

float wd = 1600, ht = 900;


if (xc > wd-r) dx = -dx;
if (xc < r) dx = -dx;
if (yc > ht-r) dy = -dy;
if (yc < r) dy = -dy;

}
 */
