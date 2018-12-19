// frog class prototype
//
//

class Frog{
	public:
		Frog();
		~Frog();

		// methods
		void display(int);
		void move(char);
		int getX();
		int getY();
		int getRad();
		int setX(int);
		int setY(int);
		


	private:
		int rad;
		int xFrg;
		int yFrg;
		int dx;

};













