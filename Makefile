CMP = g++ -std=c++11
CLASS = log
CLASS2 = car
CLASS3 = frog
CLASS4 = fin
MAIN = frog_main
EXEC = Frogger

$(EXEC): $(CLASS).o $(CLASS2).o $(CLASS3).o $(CLASS4).o $(MAIN).o
	 $(CMP) $(CLASS).o $(CLASS2).o $(CLASS3).o $(CLASS4).o $(MAIN).o gfx3.o -lX11 -o $(EXEC)

$(CLASS).o : $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp -o $(CLASS).o

$(CLASS2) : $(CLASS2).cpp $(CLASS2).h
	$(CMP) -c $(CLASS2).cpp -o $(CLASS2).o

$(CLASS3) : $(CLASS3).cpp $(CLASS3).h
	$(CMP) -c $(CLASS3).cpp -o $(CLASS3).o

$(CLASS4) : $(CLASS4).cpp $(CLASS4).h
	$(CMP) -c $(CLASS4).cpp -o $(CLASS4).o



$(MAIN).o : $(MAIN).cpp $(CLASS).h
	$(CMP) -c $(MAIN).cpp -o $(MAIN).o

lean:
	rm $(EXEC)
	rm $(MAIN).o
	rm $(CLASS).o


