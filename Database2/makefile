
GPP=g++ -std=c++17 -Wall
FLAGS=-g
D=Build

all: dir $D/program

$D/program: $D/main.o $D/Database.o $D/Interconnect.o
	$(GPP) $(FLAGS) $^ -o $@

$D/main.o: main.cpp Database.h Interconnect.h
	$(GPP) $(FLAGS) $< -c -o $@

$D/Database.o: Database.cpp Database.h Interconnect.h
	$(GPP) $(FLAGS) $< -c -o $@

$D/Interconnect.o: Interconnect.cpp Interconnect.h
	$(GPP) $(FLAGS) $< -c -o $@
	
dir:
	[ -d Build ] || mkdir Build
	
run: all
	echo
	@ $D/program

clean:
	rm $D -rf
	
force: clean all


