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
void color(int a){//�ı��������ɫ����system("color x")��ö�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
/*
<span style="white-space:pre">	</span>�� 
	1	����ɫ
	2	����ɫ
	3	����ɫ 
	4	���ɫ
	5	���ɫ
	6	��ɫ
	7	���ɫ
	8	��ɫ
	9	ǳ��ɫ
	10	ǳ��ɫ 
	11	ǳ��ɫ 
	12	ǳ��ɫ 
	13	ǳ��ɫ 
	14	ǳ��ɫ 
	15	ǳ��ɫ 
	
	����
	1~15		��ɫ 
	16~31		����ɫ 
	32~47		����ɫ
	48~63		����ɫ
	64~79		���ɫ
	80~95		���ɫ
	96~111		���ɫ
	112~127 	���ɫ
	128~143 	��ɫ
	144~159 	ǳ��ɫ
	160~175 	ǳ��ɫ
	176~191 	ǳ��ɫ
	192~207 	ǳ��ɫ
	208~223 	ǳ��ɫ
	224~239 	ǳ��ɫ
	240~255 	ǳ��ɫ
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
