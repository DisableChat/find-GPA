inbetween.o: inbetween.cc inbetween.h student.h
	g++ -g -Wall -c inbetween.cc
clean:
	rm -rf *.o