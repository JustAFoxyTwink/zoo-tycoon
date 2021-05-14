
output: zoo_tycoon.o functions.o animal.o lemur.o tiger.o black_bear.o zoo.o
	g++ zoo_tycoon.o functions.o animal.o lemur.o tiger.o black_bear.o zoo.o -o output

zoo_tycoon.o: zoo_tycoon.cpp
	g++ -c zoo_tycoon.cpp

functions.o: functions.cpp functions.h
	g++ -c functions.cpp

animal.o: animal.cpp animal.h
	g++ -c animal.cpp

lemur.o: lemur.cpp lemur.h
	g++ -c lemur.cpp

tiger.o: tiger.cpp tiger.h
	g++ -c tiger.cpp

black_bear.o: black_bear.cpp black_bear.h
	g++ -c black_bear.cpp

zoo.o: zoo.cpp zoo.h
	g++ -c zoo.cpp

clean:
	rm *.o output