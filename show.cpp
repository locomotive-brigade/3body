#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
#define hpi asin(1)
void goto_(int x,int y){
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos={x,y};
    SetConsoleCursorPosition(hOut,pos);
}
struct node{
    double x,y;
    double vx,vy;
}a,b,c;
void color(int a){//改变输出的颜色，比system("color x")快得多
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
/*
<span style="white-space:pre">	</span>字 
	1	深蓝色
	2	深绿色
	3	深青色 
	4	深红色
	5	深粉色
	6	黄色
	7	深白色
	8	灰色
	9	浅蓝色
	10	浅绿色 
	11	浅青色 
	12	浅红色 
	13	浅粉色 
	14	浅黄色 
	15	浅白色 
	
	背景
	1~15		黑色 
	16~31		深蓝色 
	32~47		深绿色
	48~63		深青色
	64~79		深红色
	80~95		深粉色
	96~111		深黄色
	112~127 	深白色
	128~143 	灰色
	144~159 	浅蓝色
	160~175 	浅绿色
	176~191 	浅青色
	192~207 	浅红色
	208~223 	浅粉色
	224~239 	浅黄色
	240~255 	浅白色
*/
}
void out(int x,int y,char c){
    goto_(x,y);
    putchar(c);
//  goto_(x,y+1);
//  putchar(c);
//  goto_(x,y-1);
//  putchar(c);
//  goto_(x+1,y+1);
//  putchar(c);
//  goto_(x+1,y);
//  putchar(c);
//  goto_(x+1,y-1);
//  putchar(c);
//  goto_(x-1,y+1);
//  putchar(c);
//  goto_(x-1,y);
//  putchar(c);
//  goto_(x-1,y-1);
//  putchar(c);
}
double v;
int ax[10001],ay[10001];
int main(){
    int i,j,k,n,m,x,y;
    int t;
    ifstream fin("save.txt");
 //   cin>>k;
 	int f=0;
    while(1){
    	fin>>x>>y>>t>>k;
    	if(x==-1){
			break;
		}
    	ax[++f]=x;
    	ay[f]=y;
    	if(f>1000){
			out(ax[f-1000],ay[f-1000],' ');
		}
    	if(k==1)color(14);
    	else if(k==2) color(10);
    	else color(11);
    	out(x,y,'O');
    	Sleep(t/800);
	}
	fin.close();
	
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
