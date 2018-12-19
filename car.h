const int wd = 740, ht = 740;


class Car {



	public:
		// constructor/destructor
		Car();
		~Car();

		// methods
		void spawn(int xCar, int yCar);
		int getDx();
		int setDx(int);
		int getLen();
		void lefttrail(int, int, int);
		void righttrail(int, int); 
		void rand_spawn(int, int);  		
		int setlen(int); 
		int getX();
		int getY();
		int getWid();

	private:

		// car private data
		int len;
		int wid;
		int dx;
		int randx;
		int xCar;
		int yCar; 
};




