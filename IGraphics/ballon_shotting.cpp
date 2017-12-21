#include "iGraphics.h"
#include "gl.h"
#include <stdio.h>
static int dx=0,dy=0;
static int x=0,y=0;
void iDraw()
{
	iShowBMP(0,0,"White-Background-Wallpapers-HD-Copy.bmp");
	iSetColor(100,100,200);
	iFilledCircle(x+dx,y+dy,5);
}
void iMouseMove(int mx, int my)
{
	
}
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
			
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//shotting();
	}	
}
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}
void main()
{
	iSetTimer(10,iDraw);
	static int i=0;
	for(i=0;)
	dx=dx+10;
	dy=dy+10;
	iInitialize(800,800,"Ballone_shooting");
}