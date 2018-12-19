class Finish {

	public:
		// constructor/destructor
		Finish();
		~Finish();

		// methods
		void spawn(int x, int y);
		void setFill(bool);
		int getX();
		int getY();
		int getLen();
		int getWid();
		bool isFilled();		


	private:

		// finish pods private data
		int len;
		int wid;
		int xFin;
		int yFin;
		bool fill; 
};


