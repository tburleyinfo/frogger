#include <iostream>
#include "gfx3.h"
#include "log.h"
#include <cmath> 
#include <unistd.h>
#include "car.h"
#include <cstdlib>
#include "frog.h"
#include "fin.h"

using namespace std;
const int one = rand()%320+0, two = rand()%320+320; 
const int big = rand()%100+100, small = rand()%50+100; 

int main() { 
	int wd = 740, ht = 740;
	int x = 0, y = 592;
	int frogs = 0; 
	int lives = 3; 
	bool isPlay = false; 
	bool ONLOG = false;
	int x2 = one, x3 = one, x4 = one; // initial position of cars
	int Tx = two, Tx2 = two, Tx3 = two, Tx4 = two; //Initial position of Trailing cars
	int xR = one, yR = 74, xR2 = one, xR3 = one; // initial position of Logs
	int LxR = two, LxR2 = two, LxR3 = two; 
	int frogdX; 
	int podx = 0, pody = 0;
	int randx = 0; 
	char c, e; 
	Frog frg; 
	Car car, trail, car2, trail2, car3, trail3, car4, trail4; 
	Interact log, Ltrail, log2, Ltrail2, log3, Ltrail3;  
	Finish fin1, fin2, fin3, fin4; 	
	gfx_open(wd, ht, "Frogger");

	while(!isPlay)
	{
		//Main Menu
		gfx_text(300, 300, "Welcome to Frogger!");
		gfx_text(300, 350, "Press P to play");
		gfx_text(300, 375, "Press Q to exit");
		gfx_text(0, 740, "Created by Tim Burley (P1) and Pascal Phoa (P2)");

		if(gfx_wait() == 'p')
		{
			isPlay = true;
			break;
		}

		else if(gfx_wait() == 'q') break;
	}

	while (isPlay){
		if(frogs == 4)
		{
			gfx_clear();
			isPlay = false;
			
			while(!isPlay)
			{
				//You Win
				gfx_text(300, 350, "YOU WIN!!!");
				gfx_text(300, 370, "Thank you for this ");
				gfx_text(300, 390, "semester of FUNd comp!");
				gfx_flush();
				usleep(5000000);
				break;
			}
		}

		fin1.spawn(148, pody);
		fin2.spawn(296, pody);
		fin3.spawn(370, pody);
		fin4.spawn(518, pody);

		if(lives == 0 )
		{
			isPlay = false;
			gfx_clear();

			while(!isPlay)
			{
				//You Lose
				gfx_text(300, 350, "Game over... :(");
				gfx_text(300, 370, "Thank you for this ");
				gfx_text(300, 390, "semester of FUNd comp!");
				gfx_flush();
				usleep(5000000);
				break;
			}
		}

		//CREATE FROG
		frg.display(frogdX);	

		//set speeds; 
		car.setDx(5); trail.setDx(5); car.setlen(big); trail.setlen(big); 
		car2.setDx(2); trail2.setDx(2); car2.setlen(small); trail2.setlen(big);
		car3.setDx(10); trail3.setDx(10); car3.setlen(small); trail3.setlen(small); 
		car4.setDx(1); trail4.setDx(1); car4.setlen(small); trail4.setlen(big);

		//set speeds
		log.setdxR(8); Ltrail.setdxR(8); log.setlen(big); Ltrail.setlen(big); 
		log2.setdxR(3); Ltrail2.setdxR(3); log.setlen(small); Ltrail.setlen(big); 
		log3.setdxR(5); Ltrail3.setdxR(5); log.setlen(big); log.setlen(big);

		// CAR 1	
		car.spawn(x, y);
		x += car.getDx();
		if(x > wd) x = -100;

		trail.spawn(Tx, y); 
		Tx += trail.getDx(); 
		if(Tx > wd) Tx = -100; 


		//CAR 2	
		car2.spawn(x2, 518);
		x2 += -car2.getDx();
		if (x2 < -car2.getLen()) x2 = 750;

		trail2.spawn(Tx2, 518); 
		Tx2 += -trail2.getDx(); 
		if(Tx2 < -trail2.getLen()) Tx2 = 750; 

		//CAR3
		car3.spawn(x3, 444);
		x3 += car3.getDx();
		if (x3 > wd) x3 = -100;

		trail3.spawn(Tx3, 444); 
		Tx3 += trail3.getDx(); 
		if(Tx3 > wd) Tx3 = -100; 

		//CAR4
		car4.spawn(x4, 370);
		x4 += -car4.getDx();
		if (x4 < -car4.getLen()) x4 = 750;

		trail4.spawn(Tx4, 370); 
		Tx4 += -trail4.getDx(); 
		if(Tx4 < -trail4.getLen()) Tx4 = 750; 

		//LOGS MOVING 
		log.exist_log(xR, yR); 	
		xR += -log.get_dxR();
		if(xR < -log.getLen()) xR = 750;			

		Ltrail.exist_log(LxR, yR); 	
		LxR += -Ltrail.get_dxR();
		if(LxR < -Ltrail.getLen()) LxR = 750;	

		//LOG2
		log2.exist_log(xR2, 148);
		xR2 += log2.get_dxR();
		if(xR2 > wd) xR2 = -100;

		Ltrail2.exist_log(LxR2, 148); 	
		LxR2 += Ltrail2.get_dxR();
		if(LxR2 > wd) LxR2 = -100;			


		//LOG3
		log3.exist_log(xR3, 222); 
		xR3 += -log3.get_dxR(); 
		if(xR3 < -log3.getLen()) xR3 = 750;

		Ltrail3.exist_log(LxR3, 222); 	
		LxR3 += -Ltrail3.get_dxR();
		if(LxR3 < -Ltrail3.getLen()) LxR3 = 750;			

		//Car collision
		if (frg.getY() == 629)
		{
			if ((((frg.getX() - frg.getRad()) < car.getX() + (car.getLen()/2))
						&& ((frg.getX() - frg.getRad()) > car.getX() - (car.getLen()/2)))
					||
					(((frg.getX() + frg.getRad()) > car.getX() - (car.getLen()/2))
					 && ((frg.getX() + frg.getRad()) < car.getX() + (car.getLen()/2)))) 
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}

		}

		if (frg.getY() == 629)
		{
			if ((((frg.getX() - frg.getRad()) < trail.getX() + (trail.getLen()/2))
						&& ((frg.getX() - frg.getRad()) > trail.getX() - (trail.getLen()/2)))
					||
					(((frg.getX() + frg.getRad()) > trail.getX() - (trail.getLen()/2))
					 && ((frg.getX() + frg.getRad()) < trail.getX() + (trail.getLen()/2)))) 
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}



		}


		//CarLane 2
		if (frg.getY() == 555)
		{
			if ((((frg.getX() - frg.getRad()) < car2.getX() + (car2.getLen()/2))
						&& ((frg.getX() - frg.getRad()) > car2.getX() - (car2.getLen()/2)))
					||
					(((frg.getX() + frg.getRad()) > car2.getX() - (car2.getLen()/2))
					 && ((frg.getX() + frg.getRad()) < car2.getX() + (car2.getLen()/2))))
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}

		}

		if (frg.getY() == 555)
		{
			if ((((frg.getX() - frg.getRad()) < trail2.getX() + (trail2.getLen()/2))
						&& ((frg.getX() - frg.getRad()) > trail2.getX() - (trail2.getLen()/2)))
					||
					(((frg.getX() + frg.getRad()) > trail2.getX() - (trail2.getLen()/2))
					 && ((frg.getX() + frg.getRad()) < trail2.getX() + (trail2.getLen()/2))))
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}
		}
		//CarLane3

		if (frg.getY() == 481)
		{
			if ((((frg.getX() - frg.getRad()) < car3.getX() + (car3.getLen()/2))
						&& ((frg.getX() - frg.getRad()) > car3.getX() - (car3.getLen()/2)))
					||
					(((frg.getX() + frg.getRad()) > car3.getX() - (car3.getLen()/2))
					 && ((frg.getX() + frg.getRad()) < car3.getX() + (car3.getLen()/2))))
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}

		}

		if (frg.getY() == 481)
		{
			if ((((frg.getX() - frg.getRad()) < trail3.getX() + (trail3.getLen()/2))
						&& ((frg.getX() - frg.getRad()) > trail3.getX() - (trail3.getLen()/2)))
					||
					(((frg.getX() + frg.getRad()) > trail3.getX() - (trail3.getLen()/2))
					 && ((frg.getX() + frg.getRad()) < trail3.getX() + (trail3.getLen()/2))))
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}

		}

		//CarLane4
		if (frg.getY() == 407)
		{
			if ((((frg.getX() - frg.getRad()) < car4.getX() + (car4.getLen()/2))
						&& ((frg.getX() - frg.getRad()) > car4.getX() - (car4.getLen()/2)))
					||
					(((frg.getX() + frg.getRad()) > car4.getX() - (car4.getLen()/2))
					 && ((frg.getX() + frg.getRad()) < car4.getX() + (car4.getLen()/2))))
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}

		}

		if (frg.getY() == 407)
		{
			if ((((frg.getX() - frg.getRad()) < trail4.getX() + (trail4.getLen()/2))
						&& ((frg.getX() - frg.getRad()) > trail4.getX() - (trail4.getLen()/2)))
					||
					(((frg.getX() + frg.getRad()) > trail4.getX() - (trail4.getLen()/2))
					 && ((frg.getX() + frg.getRad()) < trail4.getX() + (trail4.getLen()/2))))
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}

		}







		// CHECK LOG COLLISION
		if (frg.getY() == 111)
		{


			if( !( ( ( frg.getX() > log.getX() - (log.getLen()/2) )
							&& ( frg.getX() < log.getX() + (log.getLen()/2) ) )  || ( ( frg.getX() > Ltrail.getX() - (Ltrail.getLen()/2) )
							&& ( frg.getX() < Ltrail.getX() + (Ltrail.getLen()/2) ) ) ) )  
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}
			cout << "Y" << endl;
			if ((((frg.getX() - frg.getRad()) < log.getX() + (log.getLen()/2))
						&& (( frg.getX() - frg.getRad()) > log.getX() - (log.getLen()/2) ) )
					|| 
					(((frg.getX() + frg.getRad()) > log.getX() - (log.getLen()/2))
					 && ((frg.getX() + frg.getRad()) < log.getX() + (log.getLen()/2)))) 


			{ 
				ONLOG = true; 
				cout <<"ON Log" <<endl;
			}



			while (ONLOG == true){	
				cout << "while" << endl; 
				frogdX = frg.getX();
				frogdX += -log.get_dxR();
				frg.setX(frogdX);

				if (c == 'w'|| c == 'a'|| c == 's'|| c == 'd')
				{
					ONLOG = false; 
					frogdX = 0; 	
				}
				else if (frogdX < -log.getLen()) ONLOG = false;
			}
		}


		if (frg.getY() == 111)
		{
			cout << "Y" << endl;
			if ((((frg.getX() - frg.getRad()) < Ltrail.getX() + (Ltrail.getLen()/2))
						&& (( frg.getX() - frg.getRad()) > Ltrail.getX() - (Ltrail.getLen()/2) ) )
					|| 
					(((frg.getX() + frg.getRad()) > Ltrail.getX() - (Ltrail.getLen()/2))
					 && ((frg.getX() + frg.getRad()) < log.getX() + (log.getLen()/2)))) 


			{ 

				ONLOG = true; 
				cout <<"ON Log" <<endl;
			}
		}

		while (ONLOG == true){
			cout << "while" << endl; 
			frogdX = frg.getX();
			frogdX += -Ltrail.get_dxR();
			frg.setX(frogdX);
			if (c == 'w'|| c == 's'||c == 'a' || c == 'd') 
			{
				ONLOG = false; 
				frogdX = 0; 
			}
			else if (frogdX < -Ltrail.getLen()) ONLOG = false;
		}	



		if (frg.getY() == 185)
		{

			if( !( ( ( frg.getX() > log2.getX() - (log2.getLen()/2) )
							&& ( frg.getX() < log2.getX() + (log2.getLen()/2) ) )  || ( ( frg.getX() > Ltrail2.getX() - (Ltrail2.getLen()/2) )
							&& ( frg.getX() < Ltrail2.getX() + (Ltrail2.getLen()/2) ) ) ) )   
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}



			//Collide with Log 2

			cout << "Y" << endl;
			if ((((frg.getX() - frg.getRad()) < log2.getX() + (log2.getLen()/2))
						&& (( frg.getX() - frg.getRad()) > log2.getX() - (log2.getLen()/2) ) )
					||
					(((frg.getX() + frg.getRad()) > log2.getX() - (log2.getLen()/2))
					 && ((frg.getX() + frg.getRad()) < log2.getX() + (log2.getLen()/2))))

			{

				ONLOG = true;
				cout <<"ON Log" <<endl;
			}
		}

		while (ONLOG == true){
			cout << "while" << endl;
			frogdX = frg.getX();
			frogdX += log2.get_dxR();
			frg.setX(frogdX);
			if (c == 'w'||c == 's'||c == 'a' || c == 'd')
			{
				ONLOG = false;
				frogdX = 0;
			}
			else if (frogdX > wd) ONLOG = false;
		}

		if (frg.getY() == 185)
		{
			cout << "Y" << endl;
			if ((((frg.getX() - frg.getRad()) < Ltrail2.getX() + (Ltrail2.getLen()/2))
						&& (( frg.getX() - frg.getRad()) > Ltrail2.getX() - (Ltrail2.getLen()/2) ) )
					||
					(((frg.getX() + frg.getRad()) > Ltrail2.getX() - (Ltrail2.getLen()/2))
					 && ((frg.getX() + frg.getRad()) < Ltrail2.getX() + (Ltrail2.getLen()/2))))

			{

				ONLOG = true;
				cout <<"ON Log" <<endl;
			}
		}

		while (ONLOG == true){
			cout << "while" << endl;
			frogdX = frg.getX();
			frogdX += Ltrail2.get_dxR();
			frg.setX(frogdX);
			if (c == 'w'||c == 's'||c == 'a' || c == 'd')
			{
				ONLOG = false;
				frogdX = 0;
			}
			else if (frogdX > wd) ONLOG = false;
		}


		//collide with log 3
		if (frg.getY() == 259)
		{


			if( !( ( ( frg.getX() > log3.getX() - (log3.getLen()/2) )
							&& ( frg.getX() < log3.getX() + (log3.getLen()/2) ) )  || ( ( frg.getX() > Ltrail3.getX() - (Ltrail3.getLen()/2) )
							&& ( frg.getX() < Ltrail3.getX() + (Ltrail3.getLen()/2) ) ) ) )   
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}

			cout << "Y" << endl;
			if ((((frg.getX() - frg.getRad()) < log3.getX() + (log3.getLen()/2))
						&& (( frg.getX() - frg.getRad()) > log3.getX() - (log3.getLen()/2) ) )
					||
					(((frg.getX() + frg.getRad()) > log3.getX() - (log3.getLen()/2))
					 && ((frg.getX() + frg.getRad()) < log3.getX() + (log3.getLen()/2))))

			{

				ONLOG = true;
				cout <<"ON Log" <<endl;
			}
		}

		while (ONLOG == true){
			cout << "while" << endl;
			frogdX = frg.getX();
			frogdX += -log3.get_dxR();
			frg.setX(frogdX);
			if (c == 'w'|| c == 's'||c == 'a' || c == 'd')
			{
				ONLOG = false;
				frogdX = 0;
			}
			else if (frogdX < -log3.getLen()) ONLOG = false;


		}


		if (frg.getY() == 259)
		{
			cout << "Y" << endl;
			if ((((frg.getX() - frg.getRad()) < log3.getX() + (log3.getLen()/2))
						&& (( frg.getX() - frg.getRad()) > Ltrail3.getX() - (Ltrail3.getLen()/2) ) )
					||
					(((frg.getX() + frg.getRad()) > Ltrail3.getX() - (Ltrail3.getLen()/2))
					 && ((frg.getX() + frg.getRad()) < Ltrail3.getX() + (Ltrail3.getLen()/2))))

			{

				ONLOG = true;
				cout <<"ON Log" <<endl;
			}
		}

		while (ONLOG == true){
			cout << "while" << endl;
			frogdX = frg.getX();
			frogdX += -Ltrail3.get_dxR();
			frg.setX(frogdX);
			if (c == 'w'|| c == 's'||c == 'a' || c == 'd')
			{
				ONLOG = false;
				frogdX = 0;
			}
			else if (frogdX < -Ltrail3.getLen()) ONLOG = false;
		}

		// CHECK COLLISION WITH FINISH
		if ( ( frg.getX() > (fin1.getX() - fin1.getLen()/2) )
				&& ( frg.getX() < (fin1.getX() + fin1.getLen()/2) )
				&& ( frg.getY() < (fin1.getY() + fin1.getWid()/2) ) ){

			if(!fin1.isFilled())
			{
				fin1.setFill(true); 
				frg.setX(37);
				frg.setY(703);
				frogs++;
			}		
			else 
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}
		}

		if ( ( frg.getX() > (fin2.getX() - fin2.getLen()/2) )
				&& ( frg.getX() < (fin2.getX() + fin2.getLen()/2) )
				&& ( frg.getY() < (fin2.getY() + fin2.getWid()/2) ) ){

			if(!fin2.isFilled())
			{
				fin2.setFill(true);
				frg.setX(37);
				frg.setY(703);
				frogs++;
			}
			else
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}

		}

		if ( ( frg.getX() > (fin3.getX() - fin3.getLen()/2) )
				&& ( frg.getX() < (fin3.getX() + fin3.getLen()/2) )
				&& ( frg.getY() < (fin3.getY() + fin3.getWid()/2) ) ){

			if(!fin3.isFilled())
			{
				fin3.setFill(true);
				frg.setX(37);
				frg.setY(703);
				frogs++;
			}
			else
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}

			
		}

		if ( ( frg.getX() > (fin4.getX() - fin4.getLen()/2) )
				&& ( frg.getX() < (fin4.getX() + fin4.getLen()/2) )
				&& ( frg.getY() < (fin4.getY() + fin4.getWid()/2) ) ){

			if(!fin4.isFilled())
			{
				fin4.setFill(true);
				frg.setX(37);
				frg.setY(703);
				frogs++;
			}
			else
			{
				frg.setX(37);
				frg.setY(703);
				lives--;
			}

			
		}


		if( ((e = gfx_event_waiting()) != 0) && ONLOG == false)
		{
			c = gfx_wait(); 

			if (e == 1)
			{
				frg.move(c);
				if(c == 'q') 
				{
					isPlay = false;
					break;	
				}

			}
		}
		usleep(30000);
		gfx_clear();
	}


	return 0; 

}
