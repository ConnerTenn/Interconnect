
GPP=g++ -std=c++17 -Wall
D=Build

all: dir $D/program

$D/program: $D/main.o $D/Database.o $D/Interconnect.o
	$(GPP) $^ -o $@

$D/main.o: main.cpp Database.h Interconnect.h
	$(GPP) $< -c -o $@

$D/Database.o: Database.cpp Database.h Interconnect.h
	$(GPP) $< -c -o $@

$D/Interconnect.o: Interconnect.cpp Interconnect.h
	$(GPP) $< -c -o $@
	
dir:
	[ -d Build ] || mkdir Build
	
run: all
	$D/program

clean:
	rm $D -rf
	
force: clean all


