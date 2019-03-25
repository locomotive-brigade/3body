#include<iostream>
#include<fstream>
#include<cmath>
#include<ctime>
using namespace std;
#define hpi asin(1)
struct node{
    double x,y;
    double vx,vy;
}a,b,c;
double v;
void force(){
	double k,d,f,x,y;
	x=(a.x-b.x);y=(a.y-b.y);
	d=sqrt(x*x+y*y);
	f=10/(d*d)/v;
	a.vx-=f*x/d;
	a.vy-=f*y/d;
	b.vx+=f*x/d;
	b.vy+=f*y/d;
	
	x=(a.x-c.x);y=(a.y-c.y);
	d=sqrt(x*x+y*y);
	f=10/(d*d)/v;
	a.vx-=f*x/d;
	a.vy-=f*y/d;
	c.vx+=f*x/d;
	c.vy+=f*y/d;
	
	x=(c.x-b.x);y=(c.y-b.y);
	d=sqrt(x*x+y*y);
	f=10/(d*d)/v;
	c.vx-=f*x/d;
	c.vy-=f*y/d;
	b.vx+=f*x/d;
	b.vy+=f*y/d;
}
int main(){
    int i,j,k,n,m;
    srand(time(0));
	ofstream fout("save1.txt");
	a.x=rand()%100+150;
	a.y=rand()%100;
	b.x=rand()%200+150;
	b.y=rand()%200;
	c.x=rand()%100+150;
	c.y=rand()%100;
    a.vx=rand()%73-36;
    a.vy=rand()%73-36;
    c.vx=rand()%73-36;
    c.vy=rand()%73-36;
    b.vx=rand()%73-36;
    b.vy=rand()%73-36;
//	a.x=200;
//	a.y=100;
//	b.x=300;
//	b.y=100;
//	c.x=250;
//	c.y=100;
//	a.vx=0;
//	a.vy=16;
//	c.vx=0;
//	c.vy=0;
//	b.vx=0;
//	b.vy=-16;
    double TIME;
    ifstream fin("time.txt");
    fin>>TIME;
    fin.close();
    double t=0,time=0;
    double fx,fy;
    int x,y,cx,cy,bx,by;
    int kkk=200000000;
	auto first=clock();
    while(1){
//		fx=(750-a.x-b.x-c.y)/3;
//		fy=(300-a.y-b.y-c.y)/3;
//		a.x+=fx;
//		a.y+=fy;
//		b.x+=fx;
//		b.y+=fy;
//		c.x+=fx;
//		c.y+=fy;
		v=10/sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2))+10/sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2))+10/sqrt(pow(c.x-b.x,2)+pow(c.y-b.y,2))+1;
//		x=a.x;y=a.y;
		v*=v;
		v*=50;
//		out(x,y,' ');
		a.x+=a.vx*0.0001/v;
		a.y+=a.vy*0.0001/v;
		if((int)a.x!=x||(int)a.y!=y){
			x=a.x;y=a.y;
			fout<<x<<" "<<y<<" "<<(int)t<<" "<<0<<endl;
			t=0;
			kkk--;
		}
//		color(11);
//		out(x,y,2);
//		a.d+=0.1;
		if(x>500||x<1)a.vx*=-1;
		if(y>200||y<1)a.vy*=-1;
		
		cx=c.x;cy=c.y;
//		out(bx,by,' ');
		c.x+=c.vx*0.0001/v;
		c.y+=c.vy*0.0001/v;
//		c.x=200;
//		c.y=100;
		if((int)c.x!=cx||(int)c.y!=cy){
			cx=c.x;cy=c.y;
			fout<<cx<<" "<<cy<<" "<<(int)t<<" "<<1<<endl;
			t=0;
			kkk--;
		}
//		cx=c.x;cy=c.y;
//		color(6);
//		out(cx,cy,2);
		if(cx>500||cx<1)c.vx*=-1;
		if(cy>200||cy<1)c.vy*=-1;
		
		bx=b.x,by=b.y;
//		out(bx,by,' ');
		b.x+=b.vx*0.0001/v;
		b.y+=b.vy*0.0001/v; 
//		b.x=300;
//		b.y=100;
//		color(10);
//		out(bx,by,2);
		if((int)b.x!=bx||(int)b.y!=by){
			bx=b.x;by=b.y;
			fout<<bx<<" "<<by<<" "<<(int)t<<" "<<2<<endl;
			t=0;
			kkk--;
		}
		if(bx>500||bx<1)b.vx*=-1;
		if(by>200||by<1)b.vy*=-1;
		force();
		t+=100/v;
		time+=100/v;
//        if(abs(a.vx)+abs(a.vy)>400)return 0;
//        if(abs(b.vx)+abs(b.vy)>400)return 0;
//        if(abs(c.vx)+abs(c.vy)>400)return 0;
    	if((clock()-first)*1000.0/CLOCKS_PER_SEC>min(max(TIME/1000,(double)10000),(double)100000))break;
	}
    fout<<"-1 -1 -1";
    fout.close();
    fout.open("time.txt");
    fout<<time<<endl;
    fout.close();
    return 0;
}
/*

	ifstream fin(s);
	char c[300];
	for(int i=1;i<=100;i++){
		fin>>c;
		for(int j=0;j<=242;j++){
			h[i].g[j]=c[j]-'0';
		}
	}
	fin.close();
	
	
	ofstream fout(s);
	for(int i=1;i<=100;i++){
		for(int j=0;j<=242;j++){
			fout<<h[i].g[j];
		}
		fout<<endl;
	}
	fout.close();
	*/
