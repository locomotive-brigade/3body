3body:3b show start
3b:3b.cpp
	g++ 3b.cpp -o 3b -Wall -g
show:show.cpp
	g++ show.cpp -o show -Lconsole -lconsole -lcurses -Wall -g
start:start.cpp
	g++ start.cpp -o start -lpthread -Wall -g
clean:
	rm 3b show start
linux:
	git submodule update --init --recursive
	make linux -C console
	g++ 3b.cpp -o 3b -O3
	g++ show.cpp -o show -Lconsole -lconsole -lcurses -O3
	g++ start.cpp -o start -lpthread -O3
windows_msvc:
	git submodule update --init --recursive
	cd console
	nmake windows_msvc
	cd ..
	cl 3b.cpp /EHsc
	cl show.cpp /EHsc
	cl start.cpp
windows_mingw:
	git submodule update --init --recursive
	make windows_mingw -C console
	g++ 3b.cpp -o 3b -O3
	g++ show.cpp -o show -Lconsole -lconsole -O3
	g++ start.cpp -o start -O3