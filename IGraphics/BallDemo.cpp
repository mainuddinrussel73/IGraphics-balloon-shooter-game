# include "iGraphics.h"
# include "gl.h"
#include <math.h>
int ballon_x, ballon_y;
int ballonx[29],ballony[29];;
int pic_x,pic_y,dx1,x,y;
int dx, dy,s,count=0,i;
double mx1,my1,vx1=100,vy1=100;
double x1=0,y2=0;
int S;
void ballon_groups1()
{
	
   int i, n=29,c1,c2;
   int x=dx,y=dy;
   time_t t;   
   /* Intializes random number generator */
   srand((unsigned) time(&t));
   for(i=0;i<n;i++){
	   c1=(rand() % 800);
	   c2=(rand() % 800);
	   if(c1-c2>=12)ballonx[i]==c1;
   }
   for(i=0;i<n;i++){
	   if((x1+16)==ballonx[i]||(y2+2)==ballony[i])iEllipse((x+ballon_x),(y+ballon_y),12,25);
	   else iFilledEllipse((ballonx[i]+ballon_x),(ballony[i]+ballon_y),12,25);
   }
}
//void ballon_groups2()
//{
//	int i=0,x=dx,y=dy;
//		iFilledEllipse((x+120+ballon_x),(y+ballon_y),12,25);
//		iFilledEllipse((x+180+ballon_x),(y+20+ballon_y),12,25);
//		iFilledEllipse((x+210+ballon_x),(y+40+ballon_y),12,25);
//}
//void ballon_groups3()
//{
//	int i=0,x=dx,y=dy;
//		iFilledEllipse((x+250+ballon_x),(y+ballon_y),12,25);
//		iFilledEllipse((x+280+ballon_x),(y+20+ballon_y),12,25);
//		iFilledEllipse((x+320+ballon_x),(y+40+ballon_y),12,25);
//}
void move_arrow()
{
	if(x1<400){
		x1=x1+5;
		y2=y2+7;
		iFilledRectangle(x1,(int)y2,(16),(int)(2));
	}
	else if(x1>=400){
		x1+=12;
		y2=y2-3;
		iFilledRectangle(x1,(int)y2,(16),(int)(2));
	}
}
void iDraw()
{
	//place your drawing codes here	
	iClear();
	//iSetColor(255,255,255);
	//iFilledRectangle(0,0,800,800);
	iShowBMP2(0,0,"white-background-wallpapers-hd.bmp",255);
	iShowBMP2(pic_x, pic_y, "cloud-md.bmp",255);
	/*iShowBMP2(ballon_x,ballon_y,"2dRS3vT.bmp",255);
	iShowBMP2(ballon_x+80,ballon_y,"9V060AG.bmp",255);
	iShowBMP2(ballon_x+150,ballon_y,"img-thing (12).bmp",255);*/
	//iShowBMP(0,600,"partly_cloudy_or_partly_sunny_weather_icon_0515-1011-0603-3222_smu.bmp");
	iShowBMP2(0,60,"bow-and-arrow-hi.bmp",255);
	//iShowBMP(40+500,50,"Oack_Tree_PNG_Clipart_Picture.bmp");
	iSetColor(200,100,150);
	ballon_groups1();
	//ballon_groups2();
	//ballon_groups3();
	iSetColor(0,0,0);
	move_arrow();
	//iClear();
}

void iMouseMove(int mx, int my)
{
	//place your codes here
}
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
	if(key == 's')
	{
		x1=0;
		y2=0;
		move_arrow();
	}
	//place your codes for other keys here
}
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key == GLUT_KEY_LEFT)
	{
		//move_arrow();
	}
	if(key == GLUT_KEY_RIGHT)
	{
		//move_arrow();
	}
	//place your codes for other keys here
}


void ballonChangeing()
{

}
void ballonChange(){
	if(s!=1){
		vx1=100;
		vy1=100;
		ballon_y+=dy;
		pic_x+=dx1;
		if(pic_x>=800)pic_x=300;
		if(ballon_y>=800){
			ballon_y=0;
			ballon_x+=dx;
			if(ballon_x>=800)ballon_x=50;
		}	
	}
	else{
		vx1=vx1+mx1;
		vy1=vy1+my1;
		if(vx1>=800){
			count=0;
			s=0;
			vx1=100;
			vy1=100;
		}
		ballon_y+=dy;
		pic_x+=dx1;
		if(pic_x>=800)pic_x=300;
		if(ballon_y>=800){
			ballon_y=0;
			ballon_x+=dx;
			if(ballon_x>=800)ballon_x=50;
		}	
	}
}

int main()
{
	//place your own initialization codes here. 
	iSetTimer(30, ballonChange);
	ballon_x=150;
	ballon_y=0;
	mx1=10/3;
	my1=((10/3));
	vx1=100;
	vy1=100;
	pic_x=300;
	pic_y=600;
	dx1=5;
	dx = 200;
	dy = 7;
	x1+=2;
	iInitialize(800, 800, "Ball Demo");
	return 0;
}	