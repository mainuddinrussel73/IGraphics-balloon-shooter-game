#include <windows.h>
# include "iGraphics.h"
# include "gl.h"
#include <math.h>
#include<stdlib.h>
bool flag=1;
bool bmp=0,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
bool card1=1,card2=1,card3=1,card4=1,card5=1,card6=1,card7=1,card8=1,card9=1,turn1=1,turn2=1,turn3=1,turn4=1,turn5=1,turn6=1,turn7=1,turn8=1,turn9=1;
int ballon_x[9],ballon_y[9],t=0;
int pic_x=300,pic_y=600,dx1,x,y,cloud_x_move=11;
int c=12,d=24,diff=c/2+2,score_a[100]={0,0,0,0,0},n,l=0;
int cloud_width=297,cloud_height=165;
int height_inc=1,s,count=0,testx,testy;//for testing mouse point
int j,time2=0,score=0,live=10;//ballon_changer
double arrow_x=0,arrow_y=10,arrow_throw=0,arrow_x_move[43],arrow_y_move[43],vx1=100,vy1=100; 
double time1;
int S,load_gamex1=134,load_gamex2=303,load_gamey1=537,load_gamey2=579,new_gamex1=135,new_gamey1=473,new_gamex2=302,new_gamey2=522,score_gamex1=134,score_gamey1=402,score_gamey2=448,score_gamex2=303,ins_gamex1=134,ins_gamex2=303,ins_gamey1=332,ins_gamey2=379;//this is for front pages selection
int exit_gamex1=514,exit_gamex2=647,exit_gamey1=321,exit_gamey2=377,mouse_movex,mouse_movey;
int abs_(int a,int b)
{
	return (a>b)?(a-b):(b-a);
}
void ballon_groupsx(void)
{
	int i;
	char flag;
	int color_x,color_y,color_z;
	color_x=(int)rand()%256;
	color_y=(int)rand()%256;
	color_z=(int)rand()%256;
	*ballon_x=((int)rand()+j)%794;
	//for x axis:
	*(ballon_x+1)=((int)rand()+j)%794;
	while((abs_(ballon_x[1],0)<(c/2))||(abs_(ballon_x[1],ballon_x[0])<diff)){
		*(ballon_x+1)=((int)rand()+j)%794;
	}
	*(ballon_x+2)=((int)rand()+j)%794;
	while((abs_(ballon_x[2],0)<(c/2))||(abs_(ballon_x[2],ballon_x[0])<diff)||(abs_(ballon_x[2],ballon_x[1])<diff)){
		*(ballon_x+2)=((int)rand()+j)%794;
	}
	*(ballon_x+3)=((int)rand()+j)%794;
	while((abs_(ballon_x[3],0)<(c/2))||(abs_(ballon_x[3],ballon_x[0])<diff)||(abs_(ballon_x[2],ballon_x[3])<diff)||(abs_(ballon_x[3],ballon_x[1])<diff)){
		*(ballon_x+3)=((int)rand()+j)%794;
	}
	flag=0;
	*(ballon_x+4)=((int)rand()+j)%794;
	for(i=0;i<4;i++)if((abs_(ballon_x[4],0)<(c/2))||abs_(*(ballon_x+4),*(ballon_x+i))<diff){
		flag=1;
		break;
	}
	while(flag){
		flag=0;
		*(ballon_x+4)=((int)rand()+j)%794;
		for(i=0;i<4;i++)if((abs_(ballon_x[4],0)<(c/2))||abs_(*(ballon_x+4),*(ballon_x+i))<diff){
		flag=1;
		break;
	}	
	}
	flag=0;
	*(ballon_x+5)=((int)rand()+j)%794;
	for(i=0;i<5;i++)if((abs_(ballon_x[5],0)<(c/2))||abs_(*(ballon_x+5),*(ballon_x+i))<diff){
		flag=1;
		break;
	}
	while(flag){
		flag=0;
		*(ballon_x+5)=((int)rand()+j)%794;
		for(i=0;i<5;i++)if((abs_(ballon_x[5],0)<(c/2))||abs_(*(ballon_x+5),*(ballon_x+i))<diff){
		flag=1;
		break;
	}	
	}
	flag=0;
	*(ballon_x+6)=((int)rand()+j)%794;
	for(i=0;i<6;i++)if((abs_(ballon_x[6],0)<(c/2))||abs_(*(ballon_x+6),*(ballon_x+i))<diff){
		flag=1;
		break;
	}
	while(flag){
		flag=0;
		*(ballon_x+6)=((int)rand()+j)%794;
		for(i=0;i<6;i++)if((abs_(ballon_x[6],0)<(c/2))||abs_(*(ballon_x+6),*(ballon_x+i))<diff){
		flag=1;
		break;
	}	
	}
	flag=0;
	*(ballon_x+7)=((int)rand()+j)%794;
	for(i=0;i<7;i++)if((abs_(ballon_x[7],0)<(c/2))||abs_(*(ballon_x+7),*(ballon_x+i))<diff){
		flag=1;
		break;
	}
	while(flag){
		flag=0;
		*(ballon_x+7)=((int)rand()+j)%794;
		for(i=0;i<7;i++)if((abs_(ballon_x[7],0)<(c/2))||abs_(*(ballon_x+7),*(ballon_x+i))<diff){
		flag=1;
		break;
	}	
	}
	flag=0;
	*(ballon_x+8)=((int)rand()+j)%794;
	for(i=0;i<8;i++)if((abs_(ballon_x[8],0)<(c/2))||abs_(*(ballon_x+8),*(ballon_x+i))<diff){
		flag=1;
		break;
	}
	while(flag){
		flag=0;
		*(ballon_x+8)=((int)rand()+j)%794;
		for(i=0;i<8;i++)if((abs_(ballon_x[8],0)<(c/2))||abs_(*(ballon_x+8),*(ballon_x+i))<diff){
		flag=1;
		break;
	}	
	}
}
void ballon_groupsy(void)
{
	*ballon_y=((int)rand()+j)%400;
	*(ballon_y+1)=((int)rand()+j)%400;
	*(ballon_y+2)=((int)rand()+j)%400;
	*(ballon_y+3)=((int)rand()+j)%400;
	*(ballon_y+4)=((int)rand()+j)%400;
	*(ballon_y+5)=((int)rand()+j)%400;
	*(ballon_y+6)=((int)rand()+j)%400;
	*(ballon_y+7)=((int)rand()+j)%400;
	*(ballon_y+8)=((int)rand()+j)%400;
}
void ballon_x_update(void)
{
	int i;
	for(i=0;i<9;i++)if(ballon_y[i]<800)break;
	if((flag)|(i==9)){
		if(j<200000)j+=13;
		else j=13;
		ballon_groupsx();
		ballon_groupsy();
		flag=!flag;
	}
}
void ballon_y_update(void)
{
	int i=0;
	for(i=0;i<9;i++)ballon_y[i]+=height_inc;
}
void cloud_position()
{
	if((pic_x+cloud_width+cloud_x_move)>800)cloud_x_move=-5;
	else if((pic_x+cloud_x_move)<210)cloud_x_move=5;
	pic_x+=cloud_x_move;
}
void move_arrow(void)
{
	if(arrow_throw){
		if(arrow_x<=400){
			arrow_x+=5;
			arrow_y=56+sqrt(4*16*arrow_x);
			time1=arrow_x;
		}
		else if(arrow_x>400 && arrow_x<=805){
			arrow_y=56+sqrt(4*16*time1);
			time1-=5;
			arrow_x+=5;
		}
	}
	else{
		arrow_throw = 0;
	}
}
void front_page()
{
	iShowBMP(0,0,"29180-2560x1600-[DesktopNexus.com]2.bmp");
	iShowBMP2(300,500,"ballon.bmp",0);
}
void tones()
{
	srand(time(NULL));
	PlaySound( "82121__gniffelbaf__balloon-burst-07.wav", NULL,SND_ASYNC );
}
void tone2()
{
	srand(time(NULL));
	PlaySound( "Beautiful Chinese Music - Chinese Zither and Bamboo Flute.wav", NULL,SND_ASYNC );
}
void iDraw()
{
	if(flag1==0 && flag2==0 && flag3==0 && flag4==0 )
	{
		tone2();
		front_page();
	}
	else if(flag2==1)
	{
		iShowBMP(0,0,"29180-2560x1600-[DesktopNexus.com]1.bmp");
	}
	else if(flag1==1)
	{
		iClear();
		iSetColor(255,255,255);
		iFilledRectangle(0,0,800,800);
		iShowBMP(0,0,"White-Background-Wallpapers-HD.bmp");
		iSetColor(200,100,100);
		iText(30,470,"SCORE : ",GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(pic_x,pic_y,"cloud-md.bmp",0);
		iShowBMP2(pic_x,pic_y-400,"5TRKGopTa.bmp",0);
		iShowBMP2(0,70,"155-pistol-vector-clipart-free-download-l.bmp",0);
		/////////////
		iSetColor(10,10,10);
		iFilledCircle(arrow_x,arrow_y,5);
		if(live==10)
		{
			iSetColor(10,10,10);
			iRectangle(30,500,130,10);
			iFilledRectangle(30,500,130,10);
		}
		if(live==9)
		{
			iSetColor(10,10,10);
			iRectangle(30,500,130,10);
			iFilledRectangle(30,500,110,10);
		}
		if(live==8)
		{
			iSetColor(10,10,10);
			iRectangle(30,500,130,10);
			iFilledRectangle(30,500,100,10);
		}
		if(live==7)
		{
			iSetColor(10,10,10);
			iRectangle(30,500,130,10);
			iFilledRectangle(30,500,90,10);
		}
		if(live==6)
		{
			iSetColor(10,10,10);
			iRectangle(30,500,130,10);
			iFilledRectangle(30,500,80,10);
		}
		if(live==5)
		{
			iSetColor(10,10,10);
			iRectangle(30,500,130,10);
			iFilledRectangle(30,500,70,10);
		}
		if(live==4)
		{
			iSetColor(10,10,10);
			iRectangle(30,500,130,10);
			iFilledRectangle(30,500,60,10);
		}
		if(live==3)
		{
			iSetColor(10,10,10);
			iRectangle(30,500,130,10);
			iFilledRectangle(30,500,50,10);
		}
		if(live==2)
		{
			iSetColor(10,10,10);
			iRectangle(30,500,130,10);
			iFilledRectangle(30,500,40,10);
		}
		if(live==1)
		{
			iSetColor(10,10,10);
			iRectangle(30,500,130,10);
			iFilledRectangle(30,500,30,10);
		}
		if(live==0)
		{
			iSetColor(10,10,10);
			iRectangle(30,500,130,10);
			iFilledRectangle(30,500,0,10);
		}
		/////////////
		iSetColor(110,200,50);
		if(score==0)iText(140,470,"0",GLUT_BITMAP_TIMES_ROMAN_24);
		if(score==10)iText(140,470,"10",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==20)iText(140,470,"20",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==30)iText(140,470,"30",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==40)iText(140,470,"40",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==50)iText(140,470,"50",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==60)iText(140,470,"60",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==70)iText(140,470,"70",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==80)iText(140,470,"80",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==90)iText(140,470,"90",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==100)iText(140,470,"100",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==110)iText(140,470,"110",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==120)iText(140,470,"120",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==130)iText(140,470,"130",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==140)iText(140,470,"140",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==150)iText(140,470,"150",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==160)iText(140,470,"160",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==170)iText(140,470,"170",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==180)iText(140,470,"180",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==190)iText(140,470,"190",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==200)iText(140,470,"200",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==210)iText(140,470,"210",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==220)iText(140,470,"220",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==230)iText(140,470,"230",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==240)iText(140,470,"240",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==250)iText(140,470,"250",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==260)iText(140,470,"260",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==270)iText(140,470,"270",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==280)iText(140,470,"280",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==290)iText(140,470,"290",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(score==300)iText(140,470,"300",GLUT_BITMAP_TIMES_ROMAN_24);
		if(((arrow_x+5)>=(ballon_x[0]-16))&&((arrow_x+5)<=(ballon_x[0]+16))&&(((arrow_y+5)>=(ballon_y[0]-22))&&((arrow_y)+5<=(ballon_y[0]+22))))
		{
			card1=0;
		}
		if(card1==0&&turn1!=0)
		{
			iShowBMP2(ballon_x[0],ballon_y[0],"boom.bmp",0);
			score+=10;
			tones();
			turn1=0;
		}
		else if(card1!=0&&turn1!=0)
		{
			//iShowBMP2(ballon_x[0],ballon_y[0],"img-thing_burned.bmp",0);
			iSetColor(20,20,10);
			iFilledEllipse(ballon_x[0]+time2,ballon_y[0],c,d);
			iSetColor(0,0,0);
			iFilledCircle(ballon_x[0]+time2,ballon_y[0]-24,2);
			iLine(ballon_x[0]+time2,ballon_y[0]-20,ballon_x[0]+time2,ballon_y[0]-38);
		}
		if(((arrow_x+5)>=(ballon_x[1]-16))&&((arrow_x+5)<=(ballon_x[1]+16))&&(((arrow_y+5)>=(ballon_y[1]-22))&&(arrow_y+5<=(ballon_y[1]+22))))
		{
			card2=0;
		}
		if (card2==0&&turn2!=0)
		{
			iShowBMP2(ballon_x[1],ballon_y[1],"boom.bmp",0);
			score+=10;
			tones();
			turn2=0;
		}
		else if(card2!=0&&turn2!=0)
		{
			//iShowBMP2(ballon_x[0],ballon_y[0],"img-thing_burned.bmp",0);
			iSetColor(200,200,200);
			iFilledEllipse(ballon_x[1]+time2,(ballon_y[1]),c,d);
			iSetColor(0,0,0);
			iFilledCircle(ballon_x[1]+time2,ballon_y[1]-24,2);
			iLine(ballon_x[1]+time2,ballon_y[1]-20,ballon_x[1]+time2,ballon_y[1]-38);
		}
		if(((arrow_x+5)>=(ballon_x[2]-16))&&((arrow_x+5)<=(ballon_x[2]+16))&&(((arrow_y+5)>=(ballon_y[2]-22))&&(arrow_y+5<=(ballon_y[2]+22))))
		{
			card3=0;
		}
		if(card3==0&&turn3!=0)
		{
			iShowBMP2(ballon_x[2],ballon_y[2],"boom.bmp",0);
			score+=10;
			tones();
			turn3=0;
		}
		else if(card3!=0&&turn3!=0)
		{
			//iShowBMP2(ballon_x[0],ballon_y[0],"img-thing_burned.bmp",0);
			iSetColor(150,20,10);
			iFilledEllipse(ballon_x[2]+time2,(ballon_y[2]),c,d);
			iSetColor(0,0,0);
			iFilledCircle(ballon_x[2]+time2,ballon_y[2]-24,2);
			iLine(ballon_x[2]+time2,ballon_y[2]-20,ballon_x[2]+time2,ballon_y[2]-38);
		}
		if(((arrow_x+5)>=(ballon_x[3]-16))&&((arrow_x+5)<=(ballon_x[3]+16))&&(((arrow_y+5)>=(ballon_y[3]-22))&&(arrow_y+5<=(ballon_y[3]+22))))
		{
			card4=0;
		}
		if(card4==0&&turn4!=0)
		{
			iShowBMP2(ballon_x[3],ballon_y[3],"boom.bmp",0);
			score+=10;
			tones();
			turn4=0;
		}
		else if(card4!=0&&turn4!=0)
		{
			//iShowBMP2(ballon_x[0],ballon_y[0],"img-thing_burned.bmp",0);
			iSetColor(10,180,100);
			iFilledEllipse(ballon_x[3]+time2,(ballon_y[3]),c,d);
			iSetColor(0,0,0);
			iFilledCircle(ballon_x[3]+time2,ballon_y[3]-24,2);
			iLine(ballon_x[3]+time2,ballon_y[3]-20,ballon_x[3]+time2,ballon_y[3]-38);
		}
		if(((arrow_x+5)>=(ballon_x[4]-16))&&((arrow_x+5)<=(ballon_x[4]+16))&&(((arrow_y+5)>=(ballon_y[4]-22))&&(arrow_y+5<=(ballon_y[4]+22))))
		{
			card5=0;
		}
		if(card5==0&&turn5!=0)
		{
			iShowBMP2(ballon_x[4],ballon_y[4],"boom.bmp",0);
			score+=10;
			tones();
			turn5=0;
		}
		else if(card5!=0&&turn5!=0)
		{
			//iShowBMP2(ballon_x[0],ballon_y[0],"img-thing_burned.bmp",0);
			iSetColor(120,190,10);
			iFilledEllipse(ballon_x[4]+time2,(ballon_y[4]),c,d);
			iSetColor(0,0,0);
			iFilledCircle(ballon_x[4]+time2,ballon_y[4]-24,2);
			iLine(ballon_x[4]+time2,ballon_y[4]-20,ballon_x[4]+time2,ballon_y[4]-38);
		}
		if(((arrow_x+5)>=(ballon_x[5]-16))&&((arrow_x+5)<=(ballon_x[5]+16))&&(((arrow_y+5)>=(ballon_y[5]-22))&&(arrow_y+5<=(ballon_y[5]+22))))
		{
			card6=0;
		}
		if(card6==0&&turn6!=0)
		{
			iShowBMP2(ballon_x[5],ballon_y[5],"boom.bmp",0);
			score+=10;
			tones();
			turn6=0;
		}
		else if(card6!=0&&turn6!=0)
		{
			//iShowBMP2(ballon_x[0],ballon_y[0],"img-thing_burned.bmp",0);
			iSetColor(100,10,200);
			iFilledEllipse(ballon_x[5]+time2,(ballon_y[5]),c,d);
			iSetColor(0,0,0);
			iFilledCircle(ballon_x[5]+time2,ballon_y[5]-24,2);
			iLine(ballon_x[5]+time2,ballon_y[5]-20,ballon_x[5]+time2,ballon_y[5]-38);
		}
		if(((arrow_x+5)>=(ballon_x[6]-16))&&((arrow_x+5)<=(ballon_x[6]+16))&&(((arrow_y+5)>=(ballon_y[6]-22))&&(arrow_y+5<=(ballon_y[6]+22))))
		{
			card7=0;
		}
		if(card7==0&&turn7!=0)
		{
			iShowBMP2(ballon_x[6],ballon_y[6],"boom.bmp",0);
			score+=10;
			tones();
			turn7=0;
		}
		else if(card7!=0&&turn7!=0)
		{
			//iShowBMP2(ballon_x[0],ballon_y[0],"img-thing_burned.bmp",0);
			iSetColor(200,101,100);
			iFilledEllipse(ballon_x[6]+time2,(ballon_y[6]),c,d);
			iSetColor(0,0,0);
			iFilledCircle(ballon_x[6]+time2,ballon_y[6]-24,2);
			iLine(ballon_x[6]+time2,ballon_y[6]-20,ballon_x[6]+time2,ballon_y[6]-38);
		}
		if(((arrow_x+5)>=(ballon_x[7]-16))&&((arrow_x+5)<=(ballon_x[7]+16))&&(((arrow_y+5)>=(ballon_y[7]-22))&&(arrow_y+5<=(ballon_y[7]+22))))
		{
			card8=0;
		}
		if(card8==0&&turn8!=0)
		{
			iShowBMP2(ballon_x[7],ballon_y[7],"boom.bmp",0);
			score+=10;
			tones();
			turn8=0;
		}
		else if(card8!=0&&turn8!=0)
		{
			//iShowBMP2(ballon_x[0],ballon_y[0],"img-thing_burned.bmp",0);
			iSetColor(108,190,140);
			iFilledEllipse(ballon_x[7]+time2,(ballon_y[7]),c,d);
			iSetColor(0,0,0);
			iFilledCircle(ballon_x[7]+time2,ballon_y[7]-24,2);
			iLine(ballon_x[7]+time2,ballon_y[7]-20,ballon_x[7]+time2,ballon_y[7]-38);
		}
		if(((arrow_x+5)>=(ballon_x[8]-16))&&((arrow_x+5)<=(ballon_x[8]+16))&&(((arrow_y+5)>=(ballon_y[8]-22))&&(arrow_y+5<=(ballon_y[8]+22))))
		{
			card9=0;
		}
		if(card9==0&&turn9!=0)
		{
			iShowBMP2(ballon_x[8],ballon_y[8],"boom.bmp",0);
			score+=10;
			tones();
			turn9=0;
		}
		else if(card9!=0&&turn9!=0)
		{
			//iShowBMP2(ballon_x[0],ballon_y[0],"img-thing_burned.bmp",0);
			iSetColor(200,190,100);
			iFilledEllipse(ballon_x[8]+time2,(ballon_y[8]),c,d);
			iSetColor(100,0,0);
			iFilledCircle(ballon_x[8]+time2,ballon_y[8]-24,2);
			iLine(ballon_x[8]+time2,ballon_y[8]-23,ballon_x[8]+time2,ballon_y[8]-38);
		}time2+=2;
		if(ballon_y[0]>=818){card1=1;turn1=1;}
		if(ballon_y[1]>=818){card2=1;turn2=1;}
		if(ballon_y[2]>=818){card3=1;turn3=1;}
		if(ballon_y[3]>=818){card4=1;turn4=1;}
		if(ballon_y[4]>=818){card5=1;turn5=1;}
		if(ballon_y[5]>=818){card6=1;turn6=1;}
		if(ballon_y[6]>=818){card7=1;turn7=1;}
		if(ballon_y[7]>=818){card8=1;turn8=1;}
		if(ballon_y[8]>=818){card9=1;turn9=1;}
		if(time2>2)time2=-2;
		if(live==0){
			flag1=0;
		}
	}
	else if(flag3==1)
	{
		int temp=0;
		iShowBMP(0,0,"17927808-Illustration-of-a-boy-inside-a-leafy-frame-Stock-Vector-frame-clipart-border.bmp");
		iSetColor(110,200,50);
		for(int o=1;score_a[o]!=-1;o++)
		{
			printf("%d\n",score_a[o-1]);
			if((score_a[o-1]>score_a[o])&&score_a[o]!=-1) temp=score_a[o-1];
		}
		if(temp==0)iText(300,600,"0",GLUT_BITMAP_TIMES_ROMAN_24);
		if(temp==10)iText(300,600,"10",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==20)iText(300,600,"20",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==30)iText(300,600,"30",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==40)iText(300,600,"40",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==50)iText(300,600,"50",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==60)iText(300,600,"60",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==70)iText(300,600,"70",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==80)iText(300,600,"80",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==90)iText(300,600,"90",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==100)iText(300,600,"100",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==110)iText(300,600,"110",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==120)iText(300,600,"120",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==130)iText(300,600,"130",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==140)iText(300,600,"140",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==150)iText(300,600,"150",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==160)iText(300,600,"160",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==170)iText(300,600,"170",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==180)iText(300,600,"180",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==190)iText(300,600,"190",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==200)iText(300,600,"200",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==210)iText(300,600,"210",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==220)iText(300,600,"220",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==230)iText(300,600,"230",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==240)iText(300,600,"240",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==250)iText(300,600,"250",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==260)iText(300,600,"260",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==270)iText(300,600,"270",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==280)iText(300,600,"280",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==290)iText(300,600,"290",GLUT_BITMAP_TIMES_ROMAN_24);
		else if(temp==300)iText(300,600,"300",GLUT_BITMAP_TIMES_ROMAN_24);
	}
}
void iMouseMove(int testx, int testy)
{
	printf("%d %d",testx,testy);
}
void iMouse(int button, int state, int mx, int my)
{
	mouse_movex=mx;
	mouse_movey=my;

	if(mouse_movex >= new_gamex1 && mouse_movex <= new_gamex2 && mouse_movey >= new_gamey1 && mouse_movey <= new_gamey2){
		live=10;
		flag1=1;
		flag2=0;
		flag3=0;
		flag4=0;
		flag5=0;
		score_a[l]=score;
		score_a[l+1]=-1;
		score=0;
		l++;
	}

	if(mouse_movex >= ins_gamex1 && mouse_movey >= ins_gamey1 && mouse_movex <=ins_gamex2 && mouse_movey <= ins_gamey2)
	{
		flag2=1;
		flag1=0;
		flag3=0;
		flag4=0;
		flag5=0;
	}
	if(mouse_movex >= score_gamex1 && mouse_movey >= score_gamey1 && mouse_movex <=score_gamex2 && mouse_movey <= score_gamey2)
	{
		flag3=1;
		flag2=0;
		flag1=0;
		flag4=0;
		flag5=0;
	}
	if(mouse_movex >= load_gamex1 && mouse_movey >= load_gamey1 && mouse_movex <=load_gamex2 && mouse_movey <= load_gamey2)
	{
		flag3=0;
		flag2=0;
		flag1=1;
		flag4=0;
		flag5=1;
	}
	if(mouse_movex >= exit_gamex1 && mouse_movey >= exit_gamey1 && mouse_movex <= exit_gamex2 && mouse_movey <= exit_gamey2)
	{
		flag4=1;
		flag5=0;
		score=0;
		exit(0);
		flag2=0;
		flag1=0;
		flag3=0;
	}
}
void iKeyboard(unsigned char key)
{
	if(key == 'e')
	{
		flag1=0;
	}
	if(key == 'r')
	{
		flag5=0;
		flag2=0;
		flag3=0;
		score_a[l]=score;
		score_a[l+1]=-1;
	}
	if(key == 's')
	{
		if(arrow_x>=805){
			live--;
			arrow_x=0;
			arrow_y=10;
			arrow_throw=1;
		}
		else {
			arrow_throw=1;
		}
	}
	//place your codes for other keys here
}
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		
	}
	if(key == GLUT_KEY_LEFT)
	{
		//do nothing
	}
	if(key == GLUT_KEY_RIGHT)
	{
		//move_arrow();
	}
	//place your codes for other keys here
}
void main(void)
{
	//place your own initialization codes here. 
	iSetTimer(.1,cloud_position);
	iSetTimer(1,move_arrow);
	iSetTimer(1, ballon_x_update);
	iSetTimer(1, ballon_y_update);
	iInitialize(800, 800, "SHOTTING BALLONS");
}	