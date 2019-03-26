#include<fstream>
#include<queue>
#include<cstdint>
#include"console/console.h"
using namespace std;
int main(){
	ifstream fin("save.txt");
	queue<pair<int32_t,int32_t>> Q;
	Console con;
	con.cursor_set(false);
	Console::Color red(Console::Color::red,Console::Color::Default),green(Console::Color::green,Console::Color::Default),blue(Console::Color::blue,Console::Color::Default);
	while(1){
		int x,y,t,k;
		fin>>x>>y>>t;
		if(x==-1)
			break;
		fin>>k;
		Q.push({x,y});
		if(Q.size()>1000){
			con.mvprint(Q.front().first,Q.front().second," ");
			Q.pop();
		}
		Console::Color *p;
		switch(k){
			case 1:
				p=&red;
				break;
			case 2:
				p=&green;
				break;
			default:
				p=&blue;
		}
		con.mvprint(y,x,*p,"O");
		con.flush();
		con.sleep(t/800);
	}
	con.cursor_set(true);
	return 0;
}