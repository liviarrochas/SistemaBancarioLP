CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: SistemaBancario

SistemaBancario: sistema-bancario.o Classes.o
	$(CXX) $(CXXFLAGS) -o SistemaBancario sistema-bancario.o Classes.o

sistema-bancario.o: sistema-bancario.cpp Classes.h
	$(CXX) $(CXXFLAGS) -c sistema-bancario.cpp

Classes.o: Classes.cpp Classes.h
	$(CXX) $(CXXFLAGS) -c Classes.cpp

clean:
	rm -f *.o SistemaBancario