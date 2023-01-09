#include "iGraphics.h"
#include "bitmap_loader.h"
#include<string.h>
#include<math.h>
#include "variables.h"

void sort();
void change();

struct info{
		char name1[100];
		int score1;
	};
typedef struct info P;
P players[10];

void iDraw()
{
	iClear();
	
	if(Mode==0){
	enternamebackground();
	if(ChoiceOption==1)
		{
			r=255;
			gr=0;
			b=0;
			iText(505,206, InputName, GLUT_BITMAP_TIMES_ROMAN_24);
		
		}
	iSetColor(r,g,b);
	iRectangle(492,185,336,56);
		
	}

	if(ChoiceOption==2)
	{	
		playbackground();
		
	}
	if(ChoiceOption==3)
	{
			if(score<6)
			{iSetColor(0,0,0);

			lvl=1;
			background();
			player();
			enemy();

		
			}
			else if(score<11)
			{lvl=2;
				iShowImage(0,0,screenWidth,screenHeight,LevelTwoBackground);
				player();
				enemy();
				sprintf(buff,"SCORE : %d ",score);
	            iSetColor(0,0,0);
                iText(5,500,buff,GLUT_BITMAP_TIMES_ROMAN_24);
                sprintf(level,"LEVEL : %d ",lvl);
            	iSetColor(0,0,0);
                iText(200,500,level,GLUT_BITMAP_TIMES_ROMAN_24);
				iRectangle(5,460,50,20);
	            iFilledRectangle(5,460,length,width);
			}
			else
			{lvl=3;
			

				iShowImage(0,0,screenWidth,screenHeight,level3background);
				iShowImage(obstacleX,obstacleY,obstacleWide,obstacleHeight,obstacle);
				player();
				enemy();
				sprintf(buff,"SCORE : %d ",score);
	            iSetColor(0,0,0);
                iText(5,500,buff,GLUT_BITMAP_TIMES_ROMAN_24);
                sprintf(level,"LEVEL : %d ",lvl);
            	iSetColor(0,0,0);
                iText(200,500,level,GLUT_BITMAP_TIMES_ROMAN_24);

				iRectangle(5,460,50,20);
	            iFilledRectangle(5,460,length,width);

			}
			iSetColor(255,0,0);
	
			iSetColor(255,255,255);

			iSetColor(0,0,255);

			iSetColor(0,255,0);

			if(damage==10)
         	{	finalScore=score;
	     	iShowImage(0,0,screenWidth, screenHeight,go);
			sprintf(buff,"YOUR SCORE : %d",finalScore);
			iText(200,200,buff, GLUT_BITMAP_TIMES_ROMAN_24);
		
        	}

	}
	else if(ChoiceOption==4)
	{
		highscorebackground();

	}
	else if(ChoiceOption==5)
	{
		instructionbackground();
	}
	else if(ChoiceOption==6)
	{
		creditbackground();
	}
	}




void iPassiveMouse(int mx, int my)
{
	MouseX=mx;
	MouseY=my;
}




void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && ChoiceOption==3&&flag!=1){
			double a1 = mx-100;
			double b1 = my-100;
			qeta=atan2(b1,a1)*180/PI;
	}
	

	vx=v*cos(qeta*PI/180);
	vy=v*sin(qeta*PI/180)-g*timeChange;



	diameter = curveCenterX + (screenRadius)*cos(qeta*PI/180);
	diameter= diameter/2;

	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		if((MouseX>492 && MouseX<492+334)&&(MouseY>185 && MouseY<185+56)&& Mode!=2)
		{
			ChoiceOption=1;//enter name box
		}
		else if(ChoiceOption==2)
		{

			if((MouseX>485 && MouseX<485+70)&&(MouseY>260 && MouseY<260+40))
			{
				ChoiceOption=3;//play
			}
			else if((MouseX>485 && MouseX<485+160)&&(MouseY>210 && MouseY<210+40))
			{
				ChoiceOption=4;//highscore
			}
			else if((MouseX>485 && MouseX<485+170)&&(MouseY>160 && MouseY<160+40))
			{
				ChoiceOption=5;//Instruction
			}
			else if((MouseX>485 && MouseX<485+90)&&(MouseY>110 && MouseY<110+40))
			{
				ChoiceOption=6;//Credit
			}
			else if((MouseX>485 && MouseX<485+60)&&(MouseY>60 && MouseY<60+40))
			{
				exit(0);
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		ArrowOption=1;
		flag=1;

	}
}

void iKeyboard(unsigned char key)
{
	if(ChoiceOption==3 && key==' ')
	{
		ArrowOption=1;
		flag=1;
	}

	if(ChoiceOption==1)
	{
		if(key!='\b'&& key!='\r')
		{
			InputName[IndexNumber] = key;
			IndexNumber++;
			InputName[IndexNumber] = '\0';
		}
		else if(key=='\b')
		{
			if(IndexNumber<=0)
				IndexNumber=0;
			else
				IndexNumber--;

			InputName[IndexNumber] = '\0';
		}
		else if(key =='\r')
		{   Mode=2;
			ChoiceOption=2;
			printf("%s", &InputName);
		}
	}

	FILE *fp = fopen("Name.bin","wb");

	fwrite(&InputName, sizeof(InputName), 1, fp);
	fclose(fp);

	fp=fopen("Name.bin","rb");
	fread(&OutputName, sizeof(OutputName),1,fp);
	fclose(fp);
	
	if(key=='b'&& Mode!=0)
	{
		ChoiceOption=2;
		damage=0;
		
	}
}

void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_RIGHT){
		PlayerX+=10;
		p_BowX+=10;
		ArrowX+=10;
		player_pivotX+=10;
		X=ArrowX;
		if(PlayerX>=200 && p_BowX>=222&&ArrowX>=240&&player_pivotX>=235){
			ArrowX=240;
			p_BowX=222;
			PlayerX=200;
			player_pivotX=235;
			
		}
		
	}

	if(key== GLUT_KEY_LEFT){


		p_BowX-=10;
		PlayerX-=10;
		ArrowX-=10;
		player_pivotX-=10;
		printf("%d\n",player_pivotX);
		if(PlayerX<=20 && p_BowX<=42&&ArrowX<=60 && player_pivotX<=55){

			ArrowX=60;
			p_BowX=42;
			PlayerX=20;
			player_pivotX=55;

		}
	}
	
}
void Enemy_Move(){

	if(score>5){

		EnemyY+= speed;
		Y= EnemyY;
		if(EnemyY>500|| EnemyY<0 )
		speed=-speed;
	}
}
void obstaclemove(){
	if(score>3){
	obstacleY+=obS;
	if(obstacleY>520 ||obstacleY<5)
		obS=-obS;
	}
}

int main()

{
		char c[10];

	FILE *info;
	info = fopen("info.txt", "w");
	
	P player2;

	int a;
	for(int j=0; j<3; j++)
	{
		for( int k=0; k<3-j; k++){
			if(players[j].score1<players[j+1].score1)
			{
				a=players[j].score1;
				player2=players[j];
				players[j]=players[j+1];
				players[j+1].score1 =a;
				players[j+1]=player2;

			}
			
		}
	}
	
	for(int j=0; j<3; j++)
	{
		fprintf(info, "%s %d\n", players[j].name1, players[j].score1);
	}
	fclose(info);

	char ab[1000];
	info = fopen("info.txt", "r");
	
	while(!feof(info)){
		fgets(ab,1000,info);
		printf("%s\n", ab);
	}

	fclose(info);


	p=iSetTimer(.01,change);
	s= iSetTimer(23,enemyshoot);
    EnemyMove= iSetTimer(23,Enemy_Move);
	m= iSetTimer(17,obstaclemove);
	int enemyArrow=iSetTimer(50,enemyshoot);

	iInitialize(screenWidth, screenHeight, "Arquero The Game");
	Background= iLoadImage("images/Background.jpg");
	InstructionBackground= iLoadImage("images/InstructionBackground.jpg");
	CreditBackground= iLoadImage("images/CreditBackground.jpg");
	PlayBackground= iLoadImage("images/PlayBackground.jpg");
	HighScoreBackground= iLoadImage("images/HighScoreBackground.jpg");
	EnterNameBackground=iLoadImage("images/EnterNameBackground.jpg");
	Player = iLoadImage("images/Player.png");
	PlayerBow = iLoadImage("images/PlayerBow.png");
	Arrow= iLoadImage("images/Arrow.png");
	Enemy= iLoadImage("images/Enemy.png");
	EnemyBow= iLoadImage("images/EnemyBow.png");
	LevelTwoBackground=iLoadImage("images/LevelTwoBackground.jpg");
	Enemy_Arrow= iLoadImage("images/Enemy_Arrow.png");
	level3background= iLoadImage("images/level3background.jpg");
	obstacle= iLoadImage("images/obstacle.jpg");
	go= iLoadImage("images/GameOver.jpg");

	iStart();
	
	return 0;
}
void background()
{iShowImage(0,0,screenWidth, screenHeight,Background);
	sprintf(buff,"SCORE : %d ",score);
	iSetColor(0,0,0);
iText(5,500,buff,GLUT_BITMAP_TIMES_ROMAN_24);
sprintf(level,"LEVEL : %d ",lvl);
	iSetColor(0,0,0);
iText(200,500,level,GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(5,460,50,20);
	iFilledRectangle(5,460,length,width);

}
void playbackground()
{
	iShowImage(0,0,screenWidth, screenHeight,PlayBackground);
}
void creditbackground()
{
	iShowImage(0,0,screenWidth, screenHeight,CreditBackground);
}
void highscorebackground()
{
	iShowImage(0,0,screenWidth, screenHeight,level3background);
	sprintf(buff,"HIGHSCORE : %d\n",scr[8]);
	iText(200,150,buff,GLUT_BITMAP_TIMES_ROMAN_24);
}
void instructionbackground()
{
	iShowImage(0,0,screenWidth, screenHeight,InstructionBackground);
}
void enternamebackground()
{
	iShowImage(0,0,screenWidth, screenHeight,EnterNameBackground);
}

void player()
{
	iShowImage(PlayerX, PlayerY, 80,100, Player);
			
			
			//shooting arrow for player
			if(ArrowOption==0)
			{

				iRotate(player_pivotX, player_pivotY, qeta);
				iShowImage(p_BowX, p_BowY, p_BowHeight,p_BowWidth, PlayerBow);
				iShowImage(ArrowX, ArrowY, ArrowHeight,ArrowWidth, Arrow);
				iUnRotate();
			}
			else if(ArrowOption==1)
			{
				iShowImage(p_BowX, p_BowY, p_BowHeight,p_BowWidth, PlayerBow);
				iRotate(ArrowX+32, ArrowY+20, tita);
				iShowImage(ArrowX, ArrowY, ArrowHeight,ArrowWidth, Arrow);
				iUnRotate();

			}
	
	
}
void enemy()
{
	
	iShowImage(EnemyX, EnemyY,EnemyW,EnemyH,Enemy);

	
	iShowImage(EnemyX-eArrowX,EnemyY+eArrowY,eArrowHeight,eArrowWidth, Enemy_Arrow);
		
			iShowImage(EnemyX-e_BowX, EnemyY+e_BowY,e_BowHeight,e_BowWidth,EnemyBow);

			}


void change()
{
	if(flag==1)
	{
		tanX=v*cos(qeta*PI/180)*timeChange;
		tanY= ArrowX*tan(qeta*PI/180)-0.5*g*ArrowX*ArrowX/(v*cos(qeta*PI/180))/(v*cos(qeta*PI/180));
		ArrowX=X+tanX;
		ArrowY=150+tanY;

		

		tita=atan2(tanY, ArrowX)*180/PI;
		
		if(timeChange!=timeMax)
			timeChange++;

		if((EnemyX-eArrowX+eArrowHeight>PlayerX && EnemyX-eArrowX+eArrowHeight<80+PlayerX)&&(EnemyY+eArrowY+eArrowWidth>PlayerY && EnemyY+eArrowY+eArrowWidth<PlayerY+100)){
			damage++;
			length-=5;
			
			timeChange=1;
			flag=0;
			timeMax=0;
			ArrowOption=0;
			ArrowX=45+ PlayerX;
			ArrowY=65+PlayerY;
			printf("%d",damage);
			
			if(damage==3)
         	{	finalScore=score;
			iShowImage(0,0,screenHeight, screenWidth, Arrow);
	     	iShowImage(0,0,screenWidth, screenHeight,go);
			FILE *ptr=(fopen("writescore.txt","a"));
			fprintf(ptr,"%d\n",finalScore);
			fclose(ptr);	
        	}
			
		}


		if(ArrowY<0|| ArrowY>600 || ArrowX>screenWidth)
		{
			timeChange=1;
			timeMax=0;
			flag=0;
			ArrowX=45+PlayerX;
		    ArrowY=65+ PlayerY;
			ArrowOption=0;
			
		}
		if((ArrowX+ArrowHeight>EnemyX && ArrowX+ArrowHeight<EnemyX+EnemyW)&&(ArrowY+ArrowWidth>EnemyY && ArrowY+ArrowWidth<EnemyY+EnemyH))
		{
			timeChange=1;
			timeMax=0;
			flag=0;
			ArrowX=45+PlayerX;
		    ArrowY=65+ PlayerY;
			ArrowOption=0;
			enemyrestart();
			score++;
			printf("%d\n", score);

		}
		if(score>11){
		if((ArrowX+ArrowHeight>obstacleX && ArrowX+ArrowHeight<obstacleX+obstacleWide)&&(ArrowY+ArrowWidth>obstacleY && ArrowY+ArrowWidth<obstacleY+obstacleHeight))
		{
			timeChange=1;
			timeMax=0;
			flag=0;
			ArrowX=45+PlayerX;
		    ArrowY=65+ PlayerY;
			ArrowOption=0;
			printf("%d\n", score);

		}
		}
	}
}
void enemyrestart(){

	EnemyX=480+rand()%(screenWidth-575);
	EnemyY=100+rand()%(screenHeight-300);
	
}

void enemyshoot(){
	{
		e_tanX= v*cos(alfa*PI/180)*timeChange;
		e_tanY= eArrowX*(alfa*PI/180)-0.5*g* eArrowX*eArrowX/(v*cos(alfa*PI/180))/(v*cos(alfa*PI/180));
		eArrowX= e_tanX;
		eArrowY= 63+e_tanY;
				delta= atan2(e_tanY,eArrowX)*180/PI;
	}

	
}void sort(){
	FILE *ptr=fopen("writescore.txt","r");
	

for( i=0;i<15-1;i++){

	for( j=0;j<=15-i;j++)
	{
		if(scr[j]>scr[j+1]){
temp=scr[j];
		scr[j]=scr[j+1];
		numb=scr[j];
		scr[j+1]=temp;
		}
	}
	
		}

fclose(ptr);
}
