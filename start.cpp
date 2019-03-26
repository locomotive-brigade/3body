#include<thread>
#include<cstdlib>
#include"console/os.h"
using namespace std;
int main(){
	#ifdef WIN_OS
	system("copy save1.txt save.txt");
	#else
    system("cp save1.txt save.txt");
	thread calc([]{
		system("./3b");
	});
	system("./show");
	calc.join();
	#endif
}