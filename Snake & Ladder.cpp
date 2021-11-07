#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<math.h>
#include<GL/glut.h>
#include<cstdlib>
#define maxx 10
#define maxy 10
#define dx 70   // y size of each box 
#define dy 70   // x size of each box
#define x0 350  // inital positon of the box  
#define y2 30   // initial postion in y direction
#define speed 2
GLfloat x[maxx+1]={0},y[maxy+1]={0};
char mess[4];
char roll1[4];
int width,height;
int x_pos=370; // intial positon of x and y
int y_pos = 40;
int x2_pos=370;
int y2_pos = 40;
int x_dis = 0;  // intial score of x and y
int y_dis =0 ;
int clk = 0;
int clk1=0;
int newx1=1;


int fina1=0; // needed to check if the value has reached 100, was getting decreased by 5 on next timmer.
int fina2 =0;
int p =0;
int p1=0;
int fina11=0;
int fina22=0;





int cg=0;
int cg2=0; //
int cg1=0;
int cg11=0;//
int row=0; // where the player was when it took snake or ladder
int row1=0;
int gb=0;
int gb1=0;
int chnc=2; // chance of which player
int r = 1 ; // number of steps
int stflg =0;


int s=0;
int k1=0; // 
int k2=0; //where sake was when it left


int snk[4]= {35,68,87,99};
int lad[4]= {9,19,49,63}; 
int state =1;
int state1 =1;
using namespace std;

void pawn1(int d1,int f1,int d2,int f2,int d3, int f3,int d4,int f4)
{
	/
	glColor3f(1.0,1.0,0.0);
		glBegin(GL_POLYGON);
        glVertex2f(d1,f1);
        glVertex2f(d2,f2);
        glVertex2f(d3,f3);
        glVertex2f(d4,f4);
	glEnd();


}
void pawn2(int d1,int f1,int d2,int f2,int d3, int f3,int d4,int f4)
{
	glColor3f(0.5,1.0,0.0);

		glBegin(GL_POLYGON);
        glVertex2f(d1,f1);
        glVertex2f(d2,f2);
        glVertex2f(d3,f3);
        glVertex2f(d4,f4);
	glEnd();
	
	

}


int calux(int x)
{
	int xi;
	int bh;
	bh= x/10;

  if (bh%2==0)

  {
  	
  	xi= abs(x%10-1);

	xi = xi*70+370;
	
  	
  }
	
	else if(bh/2!=0)
	{
	bh=10-x%10;
	xi= bh;
	xi = xi*70+370;
	

	}
	return xi;


}
int caluy(int x)
{
	int yi;
	yi= x/10;
	yi = yi*70+40;
	return yi;


}





int snake(int num)
{
	switch(num)
	{
		case 35:
		return 7;
		break;



		case 68:
		return 29;
		break;

		case 87:
		return 47;
		break;
		case 99:
		return 21;
		break;
	}
}


int ladder(int num)
{
	switch(num)
	{
		case 9:
		return 28;
		break;



		case 19:
		return 44;
		break;

		case 49:
		return 67;
		break;
		case 63:
		return 85;
		break;
	}
}


int check(int x , int y)   // checks if the snake or ladder is present at that positon
{

  int calx;
  int caly;
  int numbp;
  int sn=0;
  int ld=0;
 
  calx= ((x-370)/70)+1;
  caly= ((y-40)/70);

 
  numbp= 10*caly+calx;
 
  for(int i=0; i<4;i++)
  {
  	if(numbp==snk[i])
  	{
  		sn=1;
  	}
  	if(numbp==lad[i])
  	{
  		ld=1;
  	}
  }

  if(sn==1)
  {
  	return (100+numbp);
  }
  else if(ld==1)
  {
  	return (200+numbp);
  }
  else{
  	return 0;
  }
  


}
int check1(int x , int y)   // checks if the snake or ladder is present at that positon
{

  int calx;
  int caly;
  int numbp;
  int sn=0;
  int ld=0;
  
  calx= ((x-370)/70)+1;
  calx = 11-calx;
  caly= ((y-40)/70);

 
  numbp= 10*caly+calx;

 
  for(int i=0; i<4;i++)
  {
  	if(numbp==snk[i])
  	{
  		sn=1;
  	}
  	if(numbp==lad[i])
  	{
  		ld=1;
  	}
  }

  if(sn==1)
  {
  	return (100+numbp);
  }
  else if(ld==1)
  {
  	return (200+numbp);
  }
  else{
  	return 0;
  }
  


}



void Draw_lad(int x , int y , int x1 , int y1)
{

	glBegin(GL_LINES);  
	glColor3f(0.0,0.0,0.0);
	

        	glVertex2f(x,y);
        	glVertex2f(x1,y1);
        	glVertex2f(x1+20,y1+20);
        	glVertex2f(x+20,y+20);
        	

        	glEnd();
        	



}
void Draw_lad1(int x , int y , int x1 , int y1)
{
glLineWidth(2.5);
	glBegin(GL_LINES);  
	glColor3f(0.0,0.0,0.0);
	

        	glVertex2f(x,y);
        	glVertex2f(x1,y1);
        	 glVertex2f(x1+30,y1-10);
        	 glVertex2f(x+30,y-10);
        	

        	glEnd();
        	



}

void drlad()
{
	Draw_lad(940,50,870,190);
	Draw_lad1(590,370,430,150);
	Draw_lad(940,330,790,460);
	Draw_lad1(510,460,650,600);

}


/*
void drsnk()
{

	//SNake 1 from 35-7
	glBegin(GL_QUADS);  
	glColor3f(0.0,0.0,0.0);
      glVertex2f(,y);
       glVertex2f(x1,y1);
        glVertex2f(x1+30,y1-10);
         glVertex2f(x+30,y-10);
        	/*int k = abs(y-y1);
        	k= k/10;
        	for(int i=2; i<k; i++)
        	{
        		glVertex2f((x1-x)/i,
        	}


        	glEnd()

}*/
#define DEG2RAD 3.14159/180.0
void DrawEllipse(float radiusX, float radiusY)
{
    int i;
    glColor3f(0.5,0.7,0);
    glBegin(GL_LINE_LOOP);
    for(i=0;i<360;i++) // creates the outer loop for ellipse
    {
        float rad = i*DEG2RAD;
        glVertex2f(cos(rad)*radiusX,sin(rad)*radiusY);
    }
    glEnd();
    
    glColor3f(0.5,0.6,0);
    glBegin(GL_POLYGON);  // fills the color inside using polygon
    for(i=0;i<360;i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f(cos(rad)*radiusX,sin(rad)*radiusY);
    }
    glEnd();
}
void drsnk()
{   
	GLfloat xsnake[]={390,930,782,784},ysnake[]={230,210,370,70},lcarr[]={0.3,-0.25,0.70,-0.20,0.45,-0.15,0.55,-0.2,0.70,-0.25,0.80,-0.35,0.9};
	GLint i;
	GLint j,lc=0,reploop[]={70,35,35,35,35,35,35,35,35,35,35,25,70}; // size of twists 
	GLint snakeLc[]={12,7,6,5}; //NUmber of twists in snake
	for(j=0;j<4;j++)
	{
		glColor3f(0.5,0.6,0);
		//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glPointSize(18.0);
		lc=0;
		glBegin(GL_TRIANGLES);  // Tail of snake
				glVertex2f(xsnake[j]- 9,ysnake[j]-9);
				glVertex2f(xsnake[j],ysnake[j]-36);
				glVertex2f(xsnake[j]+10,ysnake[j]-10);;
        	glEnd();
		while(lc<snakeLc[j])
		{

			for(i=0;i<reploop[lc];i++)
			{
				glBegin(GL_POINTS);
   					glVertex2i(xsnake[j],ysnake[j]); // plots the body of snake point by 
				glEnd();
				ysnake[j]++;
				if(j%2==0)
                   xsnake[j]+=lcarr[lc]; // drgree of twists how much snake should be twisted
				else
					xsnake[j]-=lcarr[lc];
			}
			lc++;
		}
		glPushMatrix();
        		glTranslatef(xsnake[j],ysnake[j],18); //translate same head to all snakes
        		glColor3f(255/255.0, 51/255.0, 0);
        		glPointSize(3.0);
       			glBegin(GL_POINTS);
        			glVertex3f(-12.5,7.5,20); // eyes of snake
        			glVertex3f(12.5,7.5,20);
       	 		glEnd();
        		glBegin(GL_POLYGON);
            			glVertex2f(0,-1);  // teeths of snake
            			glVertex2f(-4,-13);
            			glVertex2f(-4,-1);
            			glVertex2f(4,-1);
            			glVertex2f(4,-13);
       			glEnd();
        		DrawEllipse(25,15);
        	glPopMatrix();
	}
}





void glutBitmapString(const char *str)
{
	int i=0;
	while(str[i]!='\0')
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i++]); // prints the string in this format with times font
}


void display3()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0,1.0,1.0,1.0);
    int i;
    glColor3f(1.0,0.0,0.0);
    glRasterPos3f(600,380,10);
	if(chnc==1)
        glutBitmapString("PLAYER 1 WINS");
    else
	glutBitmapString("PLAYER 2 WINS");
    glutSwapBuffers();
}











int  chance(int a)
{
	return a;

}
void play()
{
int d11,f11,d12,d13,d14,f12,f13,f14;
int d21,f21,d22,d23,d24,f22,f23,f24;


	d11=x_pos  ; f11=y_pos+ 40;
	d12=x_pos + 10 ; f12=y_pos+ 50;
	d13=x_pos + 20 ; f13=y_pos+ 40;
	d14=x_pos + 10 ; f14=y_pos+ 30;

	d21=x2_pos;      f21= y2_pos +20 ;
	d22=x2_pos + 10; f22=y2_pos+ 30;
	d23=x2_pos + 20; f23=y2_pos+ 20;
	d24=x2_pos + 10; f24=y2_pos+ 10;





	pawn1(d11,f11,d12,f12,d13,f13,d14,f14);
	pawn2(d21,f21,d22,f22,d23,f23,d24,f24);
	





}



void Timer(int n)
{
	
	int chnc1=0;
	

	glutPostRedisplay();
	glutTimerFunc(1000/60,Timer, 0);

	 
	

if(stflg==1)
{
	chnc1=chnc;


}



switch(chnc1)
{



case 1:


    
	switch(state)
	{

		
		case 1:

			if(x_pos<1000 && newx1<=r)
			{
				if(p==0)
              {
	             newx1=newx1+1;
                }
             p=p+1;
				
				if(clk!=14)
				   {
				   	x_pos = x_pos + 5;
				    clk=clk+1;  
				  
					
				 	
				    }
				if(clk==14){
					
					newx1=newx1+1;
					clk=0;

				    }

				}
			  

			  
		     if(newx1==r+1)
						{ 
							if(check(x_pos,y_pos)>0)
							{
								
							state=3;
							row=1;
							newx1==1;


						    }
						    else{
						    	break;
						    }
						}
			  
			 else if(x_pos==1000)
			 {
			 	if(newx1<r)

			 	{
			 		
			 		state=2;
                   y_pos=y_pos+70;
                  
			       newx1=newx1+1;

			 	}
			 }
			else{
				break;
				

			}
			break;
		case 2:
		  
		   if( (x_pos - (r)*70) < 370 && (y_pos==670) && fina1== fina2 )
		   {
		   	
		   	break;
		   } 



		   if(x_pos>370 && newx1<=r)
			{
			
			    fina2=1;
				
				if(clk!=14)
				   {
				   	x_pos = x_pos - 5;
				    clk=clk+1;  
				    
					
				 	
				    }

				if(clk==14){
					
					newx1=newx1+1;
				
					clk=0;

				    }
			   
	
			   }
                        if(newx1==r+1)
						{ 
					       	if(y_pos==670 && x_pos==370)
			 				{
			 					
			 		
			 						glutDisplayFunc(display3);
			 						glClearColor(0.0,1.0,1.0,1.0);
                  				  glutPostRedisplay();
			 	
			 					}
							if(check1(x_pos,y_pos)>0)
							{
								
							state=3;
							row=2;
							newx1=1;
							
						    }
						    else{
						    	break;
						    }
						}
			 else if(x_pos==370)
			 {
			 

			 	if(newx1<r)

			 	{
			 		
			 		state=1;
                   y_pos=y_pos+70;
                 
			       newx1=newx1+1;

			 	}
			 	if(newx1==r)
			 	{
			 		break;
			 	}
			 }
		 
			else{
				break;
			}
			break;
	    case 3:
	         
	         int lk=0;
	         int sn1;
	         int ld1;
	         if(row==1 && gb==0){
	         lk =check(x_pos,y_pos);}
	         if(row==2 && gb==0){lk =check1(x_pos,y_pos); }
	         
	         if(lk>100 && lk < 200)
	         { 
               sn1= snake(lk-100);
               
               cg = calux(sn1);
               cg1= caluy(sn1);
              
               if((sn1/10)%2==0)
	         	{
	         		k1=1;
	         	}
	         	if((sn1/10)%2!=0)
	         	{
	         		k1=2;
	         	}

	         }
	         else if(lk>200)
	         {
	         	ld1=ladder(lk-200);
	         	if((ld1/10)%2==0)
	         	{
	         		k1=1;
	         	}
	         	if((ld1/10)%2!=0)
	         	{
	         		k1=2;
	         	}
	         	
	         	cg = calux(ld1);
              
	         	cg1= caluy(ld1);
	         	
	         }
	         if(x_pos<cg)
	         {
	         	x_pos=x_pos+10;
	         	gb=1;
	         }
	         else if(x_pos>cg)
	         {
	         	x_pos=x_pos-10;
	         	gb=1;

	         }
	         else
	         {
	         	
	         }
	         if(y_pos<cg1)
	         {
	         	y_pos=y_pos+10;
	         	gb=1;
	         }
	         else if(y_pos>cg1)
	         {
	         	y_pos=y_pos-10;
	         	gb=1;
	         }
	         else
	         { 
	         }
	         if(x_pos==cg && y_pos==cg1)
	         {
	         	state = k1;
	         	gb=0;
	         	
	         	r=0;
	         }
	    }

		
 break;
case 2:

     
    
	switch(state1)
	{

		
		case 1:
		  

			if(x2_pos<1000 && newx1<=r)
			{
				if(p1==0){
	             newx1=newx1+1;
                }
             p1=p1+1;
				
				
				if(clk1!=14)
				   {
				   	x2_pos = x2_pos + 5;
				    clk1=clk1+1;  
				    
					
				 	
				    }
				if(clk1==14){
					
					newx1=newx1+1;
					clk1=0;

				    }
				    
				}
			  

			  
		     if(newx1==r+1)
						{ 
							if(check(x2_pos,y2_pos)>0)
							{
								
							state1=3;
							row1=1;
							newx1=1;

						    }
						    else{
						    	break;
						    }
						}
			  
			 else if(x2_pos==1000)
			 {
			 	if(newx1<r)

			 	{
			 		
			 		state1=2;
                   y2_pos=y2_pos+70;
                  
			       newx1=newx1+1;

			 	}
			 }
			 
			else{
				break;
			

			}
			break;
		case 2:

			 if( (x2_pos - (r)*70) < 370 && (y2_pos==670) && fina11== fina22 ) // check if crossed 100
		   {
		   	break;
		   }
		   if(x2_pos>370 && newx1<=r)
			{
				fina22=1;
				if(clk1!=14)
				   {
				   	x2_pos = x2_pos - 5;
				    clk1=clk1+1;  	 	
				    }

				if(clk1==14){
					newx1=newx1+1;
					clk1=0;
				    }
			     }
                        if(newx1==r+1)
						{ 
					        if(y2_pos==670 && x2_pos==370)
			 				{
			 					
			 		
			 						glutDisplayFunc(display3);
			 						glClearColor(0.0,1.0,1.0,1.0);
                  				   glutPostRedisplay();
			 	
			 				}
						    
							if(check1(x2_pos,y2_pos)>0)
							{
								
							state1=3;
							row1=2;
							newx1=1;
						   }
							
						    else{
						    	break;
						    }
						}
			 else if(x2_pos==370)
			 {
			 	if(newx1<r)

			 	{
			 		
			 		state1=1;
                   y2_pos=y2_pos+70;
                  
			       newx1=newx1+1;

			 	}
			 	if(newx1==r)
			 	{
			 		break;
			 	}
			 }
		 
			else{
				break;
			}
			break;
	    case 3:
	         
	         int lk=0;
	         int sn1;
	         int ld1;
	         if(row1==1 && gb1==0){
	         lk =check(x2_pos,y2_pos);}
	         if(row1==2 && gb1==0){lk =check1(x2_pos,y2_pos); }
	        
	         if(lk>100 && lk < 200)
	         {
               sn1= snake(lk-100);
               
               cg2 = calux(sn1);
               cg11= caluy(sn1);
              
               if((sn1/10)%2==0)
	         	{
	         		k2=1;
	         	}
	         	if((sn1/10)%2!=0)
	         	{
	         		k2=2;
	         	}

	         }
	         else if(lk>200)
	         {
	         	ld1=ladder(lk-200);
	         	
	         	cg2 = calux(ld1);
               
	         	cg11= caluy(ld1);
	         	
	         	if((ld1/10)%2==0)
	         	{
	         		k2=1;
	         	}
	         	if((ld1/10)%2!=0)
	         	{
	         		k2=2;
	         	}
	         }
	         if(x2_pos<cg2)
	         {
	         	x2_pos=x2_pos+10;
	         	gb1=1;
	         }
	         else if(x2_pos>cg2)
	         {
	         	x2_pos=x2_pos-10;
	         	gb1=1;

	         }
	        
	         if(y2_pos<cg11)
	         {
	         	y2_pos=y2_pos+10;
	         	gb1=1;
	         }
	         else if(y2_pos>cg11)
	         {
	         	y2_pos=y2_pos-10;
	         	gb1=1;
	         }
	         
	         if(x2_pos==cg2 && y2_pos==cg11)
	         {
	         	state1 = k2;
	         	gb1=0;
	         
	         	r=0;
	         }


	}

		

	

    break;
}
}




void mouse(int btn,int state,int x,int y)

{
	   
	   	if(x>=(1117) && y>=(398) && x<=(1187) && y<=(448))
		{
            if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
        		{
                	
    				newx1=1;r=1;
        			
           			if(newx1 ==r && chnc == 2)//&&alt==0)
                		{
                			r =((rand()%6)+1);
                			
                			if(r>6)
                			{
                				r=r-1;
                			}
                			
                			
                            fina1 = r;
                            fina2 =r;
                            
                			chnc=1;
                			stflg=1;
                    			
                		}
                    
                		
					else if(newx1 ==r && chnc == 1)
                    			{
                        			r =((rand()%3 + rand()%3)+2);
                        			
                        			if(r>6)
                					{
                						r=r-1;
                					}
                					 fina11 = r;
                                     fina22 =r;

                					
                			       chnc=2;
                			       stflg=1;
                    			}


                		
            		}
	    	}
	}















void rect()
{
	int i,j;
	x[-1]=x0; 
	y[-1]=y2;
	for( i=0;i<=maxx;i++)
	{
		x[i]=x0+i*dx; // array of coordinates in x direction // creation of array
	}
	for( j=0;j<=maxy;j++)
	{
		y[j]=y2+j*dy; // array of coordinates in y direction
	}
	
	
	int count=1;
	int temp=1;
	i=0;
	for(j=0;j<maxy;j++)  // creation of inner boxes
	{
		while(1)
		{
			if(temp<0)
			{
				if(i<0)
					break;
			}
			else
			{
				if(i>maxx-1)
					break;
			}
			glColor3f(0.1,0.8,0.0);
			glBegin(GL_LINE_LOOP);                // creation of boxes 
                		glVertex2f(x[i],y[j]);
                		glVertex2f(x[i],y[j+1]);
                		glVertex2f(x[i+temp],y[j+1]);
                		glVertex2f(x[i+temp],y[j]);
			glEnd();
			i=i+temp;
		}
		
		if(temp>0)
		{
			temp=-1;
		}
		else
		{
			temp=1;
		}
		i+=temp;
	}
	glColor3f(0.7,0.2,0.1);
	
	glBegin(GL_QUADS);  
	     // creation of outer box
	        
        	glVertex2f(x0,y2);
        	glVertex2f(x[maxx],y2);
        	glVertex2f(x[maxx],y[maxy]);
        	glVertex2f(x0,y[maxy]);
	glEnd();
}
void prinn()
{int i,j;
	int count=1;
	int temp=1;
	i=0;
	for(j=0;j<maxy;j++)  // creation of inner boxes
	{
		while(1)
		{
			if(temp<0)
			{
				if(i<0)
					break;
			}
			else
			{
				if(i>maxx-1)
					break;
			}
			glColor3f(1.0,1.0,1.0);
			glRasterPos2f(x[i]+10,y[j]+10); // postion of text in boxes, add 10 to postion of x and y of current boxes
			int k=0;
			sprintf(mess,"%d",count); // stores data in buffer mess as string i.e. converts the count into string
			if(count==100)
				strcpy(mess,"END");
			glutBitmapString(mess); // passes the string to the function
			count++;
			i=i+temp;
		}
		
		if(temp>0)
		{
			temp=-1;
		}
		else
		{
			temp=1;
		}
		i+=temp;
	}
}

void player()
{
	string a;
	//string b ;
	char b[4];
	sprintf(b,"%d",chnc);
	//b = char(chnc);
	//a = "PLAYER "+ b + " turn";
	//cout<<a<<endl;
	glColor3f(1.0,(128.0/255.0),0.0);
    glRasterPos2f(50.0,600.0);
    glutBitmapString("PLAYER 1 : ");
    glRasterPos2f(50.0,550.0);
    glutBitmapString("PLAYER 2 :");


     glRasterPos2f(1150, 500 );
    glutBitmapString("PLAYER : ");
    glRasterPos2f(1250, 500 );
    glutBitmapString(b);
    //glRasterPos2f(1190, 500 );
    //glutBitmapString("TURN");


	glColor3f(1.0,0.2,0.0);
glBegin(GL_QUADS);
        glVertex2f(1170,400.0);
        glVertex2f(1170,470.0);
        glVertex2f(1240,470.0);
        glVertex2f(1240,400.0);
    glEnd();





	sprintf(roll1,"%d",r);
     glColor3f(1.0,1.0,1.0);
    glRasterPos3f(1200,427,20);
    glutBitmapString(roll1);


    glColor3f(0.5,1.0,0.0);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<100;i++)
    {
        float theta=2.0*3.142*float(i)/float(100); //get the current angle
        float x=40*cos(theta);
        float y=40*sin(theta);
        glVertex2f(x+1200,y+300);
    }
    glEnd();


    glColor3f(1.0,(128.0/255.0),0.0);
	glRasterPos3f(1170,306,20);
	glutBitmapString("Click");
	glRasterPos3f(1170,276,20);
	glutBitmapString(" Here");

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_QUADS);
        glVertex2f(200.0,600.0);
        glVertex2f(210.0,610.0);
        glVertex2f(200.0,620.0);
        glVertex2f(190.0,610.0);
    glEnd();

    glColor3f(0.5,1.0,0.0);
    
    glBegin(GL_QUADS);
        glVertex2f(200.0,550.0);
        glVertex2f(210.0,560.0);
        glVertex2f(200.0,570.0);
        glVertex2f(190.0,560.0);
	glEnd();



	

}



void display2()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,0.8,1.0);

	

	
	play();    //sequemce of function calling determines the depth i,e which fun will be over drawn over other.
	
	player();
	
	drlad();
	prinn();  // PRINT NUMBER IN BOXES
	drsnk();
     
	rect();   // CREATE BOXES
    
	
	
	
	
	
	
	glutSwapBuffers();
}




void myReshape(int w,int h)
{
	    width=w;height=h;
    	glViewport(0,0,w,h);
    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
        glOrtho(0.0,1367.0,0.0,767.0, -180.0,180.0);
        glMatrixMode(GL_MODELVIEW);
        glClearColor(1.0,1.0,0.8,1.0);
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1366,768);
	glEnable(GL_POLYGON_SMOOTH);
	
	
	glutCreateWindow("Demo");
	 
	glutDisplayFunc(display2);
	
    glEnable(GL_DEPTH_TEST);
	
	glutMouseFunc(mouse);
	glutReshapeFunc(myReshape);
	glutTimerFunc(0,Timer,0);
	
	glutMainLoop();
	
}
