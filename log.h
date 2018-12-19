#include <iostream> 
//interact.h
//
//

const int SIZE = 400; 




using namespace std;

class Interact { 

	public:
		Interact(); 
		~Interact(); 
		void exist_log(int, int);
		void sim_square(int, int, int);
		int getLen(); 
		int getWid(); 
		float get_dxR(); 			
		float setdxR(int); 	
		float setlen(int); 
		int getX(); 
		int getY();
				 	
	private:
		int ln;
		int wd;
		float dxR;
		int xLog; 
		int yLog; 

}; 

