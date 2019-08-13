all: ./bin/laboratorio

./bin/laboratorio: ./bin/main.o 
	g++ ./bin/main.o  -o ./bin/laboratorio -O2

./bin/main.o: ./Integracion/test/main.cpp
	g++ -c ./Integracion/test/main.cpp -o ./bin/main.o

