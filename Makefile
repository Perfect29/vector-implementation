

CPP = g++

Exec = .
Source = .

Libs =

Options = -std=c++20 -Wall -pedantic -pedantic-errors

# Linking:

$(Exec)/main : $(Source)/vector.o $(Source)/main.o
	$(CPP) $(Options) -o $(Exec)/main $(Source)/vector.o $(Source)/main.o $(Libs)

# Compiling the source files:

$(Source)/vector.o : $(Source)/vector.cpp $(Source)/vector.h
	$(CPP) -c $(Options) $(Source)/vector.cpp -o $(Source)/vector.o

$(Source)/main.o : $(Source)/main.cpp $(Source)/vector.h
	$(CPP) -c $(Options) $(Source)/main.cpp -o $(Source)/main.o

