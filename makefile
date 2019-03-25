3body:3b show start
3b:3b.cpp
	g++ 3b.cpp -o 3b -Wall -g
show:show.cpp
	g++ show.cpp -o show -lcurses -Wall -g
start:start.cpp
	g++ start.cpp -o start -Wall -g
release:
	g++ 3b.cpp -o 3b -O3
	g++ show.cpp -o show -O3
	g++ start.cpp -o start -O3
clean:
	rm 3b show start