#include <mircea.h>
#include <iostream>
#include <windows.h>
#include <graphics.h>
#include <cmath>
#include <fstream>
#include <alta.h>
using namespace std;
HDC fer;
void explozie(int x,int y)
{
          //300x240
          HDC explo=incarcare("C://bib//explozie.bmp",fer);
          for(int a=0;a<5;a++)
          for(int b=0;b<4;b++)
          TransparentBlt(fer,x-150,y-120,300,240,explo,b*300,a*240,300,240,RGB(0,0,0)),Sleep(40);
}
int main()
{
          fer=initializare("nu");
          while(1){
          HDC ce=incarcare("C://bib//12.bmp",fer);
          HDC ce2=incarcare("C://bib//12a.bmp",fer);
          HDC ce3=incarcare("C://bib//12c.bmp",fer);
          HDC neg=incarcare("C://bib//negru.bmp",fer);
          HDC cev=incarcare("C://bib//12b.bmp",fer);
          HDC ceva=incarcare("C://bib//po.bmp",fer);
          HDC urm=incarcare("C://bib//12v.bmp",fer);
          HDC ceva2=incarcare("C://bib//po2.bmp",fer);
          HDC pwu=incarcare("C://bib//pwrup_slow.bmp",fer);
          HDC nr[10];
          nr[0]=incarcare("C://bib//0.bmp",fer);
          nr[1]=incarcare("C://bib//1.bmp",fer);
          nr[2]=incarcare("C://bib//2.bmp",fer);
          nr[3]=incarcare("C://bib//3.bmp",fer);
          nr[4]=incarcare("C://bib//4.bmp",fer);
          nr[5]=incarcare("C://bib//5.bmp",fer);
          nr[6]=incarcare("C://bib//6.bmp",fer);
          nr[7]=incarcare("C://bib//7.bmp",fer);
          nr[8]=incarcare("C://bib//8.bmp",fer);
          nr[9]=incarcare("C://bib//9.bmp",fer);
          int c=20,m=GetSystemMetrics(SM_CXSCREEN)/20;
          int spatiu=20,n=GetSystemMetrics(SM_CYSCREEN)/20,scor[30];
          for(int a=n-1;a>=0;a--,c-=rand()%3-1)
          {
                    c=max(1,c);c=min(m-1,c);
                    for(int b=0;b<=c;b++)
                    afisare(cev,ce,b*20,a*20,20,20);
                    for(int b=c+spatiu;b<m;b++)
                    afisare(cev,ce,b*20,a*20,20,20);
                    afisare(cev,ce2,c*20,a*20,20,20);
                    afisare(cev,ce3,(c+spatiu-1)*20,a*20,20,20);
          }
          if(rand()%2)
          afisare(fer,cev,0,20,m*20,n*20);
          SetCursorPos(m*10,n*20-20);
          Sleep(333);
          afisare(fer,ceva,mousex()-25,mousey()-25,50,50);
          Sleep(333);
          int timp=clock(),ped=0;
          int cat=0,h=0;
          int directie=1;//1-sus -1-jos
          int v[70];
          cleardevice();
          for(int a=1;a<=10;a++)scor[a]=0;
          timp=clock();
          int peri=0,pwx,pwy,slaw=0,cnx,cny;
          while(1)
          {
                    if(rand()%1000==0 && clock()-peri>3000)
                    {
                              afisaretr(cev,pwu,(c+spatiu/2)*20-15,20,30,30,RGB(255,255,255));
                              pwx=(c+spatiu/2)*20;pwy=20+15;
                              peri=clock();
                    }
                    int varia=(clock()-timp)/1000;
                    afisare(fer,nr[varia/60],m*20/2-30,0,20,20);
                    afisare(fer,nr[(varia%60)/10],m*20/2,0,20,20);
                    afisare(fer,nr[(varia%60)%10],m*20/2+20,0,20,20);
                    for(int a=m-10;a<m;a++)
                    afisare(fer,nr[scor[1+a-m+10]],a*20,0,20,20);
                    if(c<5 || c>=m-2)ped=0;
                    if(!ped)
                    if(rand()%2)
                    ped=rand()%7;
                    else ped=-rand()%7;
                    if(c<5)ped=rand()%7;
                    if(c>m-spatiu-1)ped=-rand()%7;
                    if(clock()-timp>60000 && !cat){c=v[n];directie*=-1;if(!h)h=20*(n-1);else h=0;cat=1;}
                    spatiu=20-(clock()-timp)/10000;
                    for(int b=0;b<m;b++)
                    afisare(cev,neg,b*20,h,20,20);
                    for(int b=0;b<=c;b++)
                    afisare(cev,ce,b*20,h,20,20);
                    for(int b=c+spatiu;b<m;b++)
                    afisare(cev,ce,b*20,h,20,20);
                    afisare(cev,ce2,c*20,h,20,20);
                    afisare(cev,ce3,(c+spatiu-1)*20,h,20,20);
                    COLORREF a1,a2,a3,a4,a5,a6,a7=RGB(237,28,36);
                    Sleep(2);
                    a1=GetPixel(cev,mousex()-6,mousey()-25-20);
                    a2=GetPixel(cev,mousex()-20,mousey()-25);
                    a3=GetPixel(cev,mousex()-23,mousey()+25-25) ;
                    a4=GetPixel(cev,mousex()+6,mousey()-25-20) ;
                    a5=GetPixel(cev,mousex()+20,mousey()-25) ;
                    a6=GetPixel(cev,mousex()+23,mousey()+25-25);
                    if((a1 && abs(mousex()-6-pwx)<=15 && abs(mousey()-25-20-pwy)<=15)||
                    (a2 && abs(mousex()-20-pwx)<=15 && abs(mousey()-25-pwy)<=15)||
                    (a3 && abs(mousex()-23-pwx)<=15 && abs(mousey()+25-25-pwy)<=15)||
                    (a4 && abs(mousex()+6-pwx)<=15 && abs(mousey()-25-20-pwy)<=15)||
                    (a5 && abs(mousex()+20-pwx)<=15 && abs(mousey()-25-pwy)<=15)||
                    (a6 && abs(mousex()+23-pwx)<=15 && abs(mousey()+25-25-pwy)<=15))
                    {
                              slaw=100;
                              afisare(cev,neg,pwx-15,pwy-15,30,30);
                              goto POI;
                    }
                    if(slaw)Sleep(spatiu),slaw--;
                    afisare(fer,cev,0,20,m*20,n*20);
                    if(directie>0)
                    afisaretr(fer,ceva,mousex()-25,mousey()-25,50,50,RGB(0,0,0));
                    else
                    afisaretr(fer,ceva2,mousex()-25,mousey()-25,50,50,RGB(0,0,0));
                    cnx=mousex();cny=mousey();
                    if(directie>0)
                    {
                              afisare(cev,urm,mousex()-5-2,mousey()-10,3,20);
                              afisare(cev,urm,mousex()+5-2,mousey()-10,3,20);
                    }
                    else
                    {
                              afisare(cev,urm,mousex()-5-2,mousey()-35,3,20);
                              afisare(cev,urm,mousex()+5-2,mousey()-35,3,20);
                    }
                    if((a1 && a1!=a7)||(a2 && a2!=a7)||(a3 && a3!=a7)||(a4 && a4!=a7)||(a5 && a5!=a7)||(a6 && a6!=a7)){explozie(cnx,cny);afisare(fer,cev,0,20,m*20,n*20);getch();goto POIN;}
                    if(ped>0)c++,ped--;
                    else
                    if(ped<0)c--,ped++;
                    for(int a=69;a>1;a--)
                    v[a]=v[a-1];
                    v[1]=c;
                    afisare(cev,cev,0,20*directie,m*20,n*20);
                    if(clock()-timp>58000)
                    Sleep(spatiu/2);
                    Sleep(spatiu);
                    scor[10]+=69;
                    for(int a=10;a>=1;a--)
                    scor[a-1]+=scor[a]/10,scor[a]%=10;
                    pwy+=20;
                    POI:;
          }
          POIN:;
          }
}
