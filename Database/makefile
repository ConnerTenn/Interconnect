
GPP=g++ -std=c++17 -Wall
D=Build

all: $D/Run.exe

$D/Run.exe: $D/Main.o
	$(GPP) $D/Main.o -o $D/Run.exe

$D/Main.o: Main.cpp Interconnect.h
	$(GPP) Main.cpp -c -o $D/Main.o
	
run: all
	$D/run.exe

clean:
	rm $D/* -f
	
force: clean all


