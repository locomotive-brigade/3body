#include<thread>
#include<cstdlib>
#include"console/os.h"
using namespace std;
int main(){
	#ifdef WIN_OS
	system("copy save1.txt save.txt");
	#else
    system("cp save1.txt save.txt");
	#endif
	thread calc([]{
		#ifdef WIN_OS
		system("3b");
		#else
		system("./3b");
		#endif
	});
		#ifdef WIN_OS
		system("show");
		#else
		system("./show");
		#endif
	calc.join();
}