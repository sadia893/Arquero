#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED



//Screen
int screenWidth =900;
int screenHeight =600;
//variable for loading images in menu bar
int Background;
int PlayBackground;
int CreditBackground;
int HighScoreBackground;
int InstructionBackground;
int EnterNameBackground;
int LevelTwoBackground;
int level3background;
int obstacle;

//variable for choosing option in menu bar
int ChoiceOption=0;
int Mode=0;
int r=255;
int gr=255;
int b=255;
//input name variable
char InputName[20];
char OutputName[20];
int IndexNumber=0;
//file function

void setname(char name);

//function for showing image in menu bar
void background();
void playbackground();
void creditbackground();
void highscorebackground();
void instructionbackground();
void enternamebackground();
void player();
void enemy();
void obstaclemove();
//mouse varibale for menu
int MouseX;
int MouseY;
//function for mouse in menu
void menumousecollision();

//variable for loading character images
int Player;
int Enemy;
int EnemyBow;
int PlayerBow;
int PlayerX=20;
int PlayerY=100;
int playerHeight=120;
int playerWidth=180;

//variables for arrow_player
int Arrow;
double ArrowX=60;
double ArrowY=165;
int ArrowHeight=65;
int ArrowWidth= 40;
int player_pivotX=55;
int player_pivotY=177;

//variables for bow_player
int p_BowX=42;
int p_BowY=162;
int p_BowHeight=70;
int p_BowWidth=50;

//variable for player movement
int speed=5;
bool goLeft= false;
bool goRight= false;

//variables for enemy
int EnemyMove;
int EnemyX= 740;
int EnemyY= 100;
int EnemyH=100;
int EnemyW=80;
//variables for arrow_enemy
int Enemy_Arrow;
double eArrowX=4;
double eArrowY= 63;
int eArrowHeight=48;
int eArrowWidth=37;

//variables for bow_enemy
int e_BowX=13;
int e_BowY=62;
int e_BowHeight=70;
int e_BowWidth=50;

//variables for obstacle
int obstacleX=400;
int obstacleY=100;
int obstacleHeight=180;
int obstacleWide=50;
int obS=13;
// projectile code
using namespace std;
#define g 9.8/100
#define G 9.8
#define PI 3.14159265
//int xCircle;
//int yCircle;
//int radius=80;
double qeta=0;
double qeta2=180;
//int xLine = xCircle+(radius+30)*cos(qeta*PI/180);
//int yLine = yCircle+(radius+30)*sin(qeta*PI/180);
//int xBall = xCircle;
//int yBall = yCircle;
int radiusBall=5;
//int xAxisDraw;
//int yAxisDraw;

int v=10;	
int vx= v*cos(qeta*PI/180);
int vy= v*sin(qeta*PI/180);
double tita;

int p;
int mposx, mposy;
int flag =0;
int curveCenterX = 250+100;
int curveCenterY =100;
int diameter;
int screenRadius=250;
int ballDown=0;
int i=0;
int iCheck=0;
int timeChange=1;
int timeMax;
int rMax;
int xBox=500, yBox=0;

double tanX;
double tanY;

int ArrowOption=0;
double theta;

int X;
int Y;
char buff[20];
//for level
char level[20];
int lvl=0;
int score=0;
int finalScore=0;

//for highscore
int temp;
int ar;
int numb;

int scr[15];
void sort();
void enemyrestart();
void enemyshoot();
void arrow_shoot();
int s;
int m;

int j;
//variables for shooting_enemy
int enemy_pivotX=715;
int enemy_pivotY= 177;
double alfa;
double delta;
int e_tanX;
double e_tanY;
int timechange1=1;
int max;
//damage
int damage=0;
int go;
int length=50,width=20;
int GameOver=0;
#endif // !VARIABLES_H_INCLUDED