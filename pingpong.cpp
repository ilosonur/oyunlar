#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>
using namespace std;
float velocityX=0;
float velocityY=0;
int ballX,ballY;
int lineX;
int lineY;
int lineLen=30;
int height=35,width=120;
int controller=0;
int powerUpX;
int powerUpY;
bool game=true;
char direction;
float score=0;
void Setup(){
  srand(time(NULL));
  ballX=width/2;
  ballY=height/2;
  lineX=(width-lineLen)/2;
  lineY=height-1;
  velocityY=2;
  velocityX=2;
  powerUpY=rand()%(height-3)+1;
  powerUpX=rand()%(width-3)+1;
}
void Draw(){
  system("clear");
  if(lineX<=0){
    lineX=1;
  }
  for(int i=0;i<width+1;i++){
    cout << "#";
  }
  cout << endl;
  for(int i = 0;i < height+1; i++){
    for(int j = 0;j < width+1;j++){
      if(controller){
        controller--;
        continue;
      }
      if(j==0 || j==width || i==height){
        cout << "#";
      }
      else if(j==powerUpY && i==powerUpX ){
        cout << "P";
      }
      else if(j==ballX && i==ballY){
        cout << "0";
      }
      else if(j==lineX && i==lineY){
        for(int k = 0;k<lineLen; k++){
          cout << "-";
        }
        controller=lineLen-1;
      }

      else{
        cout << " ";
      }
    }
    cout << endl;
  }
}
char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}
void Logic(){
  if(powerUpY==ballY && powerUpX==ballX){
    score+=15;
    velocityY--;
    velocityX++;
  }
  if(rand()%20>18){
    velocityX*=1.2;
  }
  if(rand()%20>18){
    velocityY*=1.2;
  }
  if(rand()%30>28){
    velocityX/=1.2;
  }
  if(rand()%30>28){
    velocityY/=1.2;
  }
  if((velocityX<1 && velocityX>=0) || (velocityX>-1 && velocityX<0)){
    velocityX=1;
  }
  if((velocityY<1 && velocityY>=0) || (velocityY>-1 && velocityY<0)){
    velocityY=1;
  }
  direction=getch();
  if(direction=='1'){
    return;
  }
  ballX+=velocityX;
  if(ballX>=width){
    ballX=width-1;
    velocityX*=-1;
  }
  else if(ballX<=0){
    ballX=1;
    velocityX*=-1;
  }
  ballY+=velocityY;
  if(ballY>=height){
    if(ballX>=lineX && ballX<=(lineX+lineLen)){
    int diff=ballY-height+2;
    ballY=height-diff;
    velocityY*=-1;
    score+=3+(velocityY*3)/5.0;
  }
  else{
    game=false;
    return;
  }
  }
  else if(ballY<=0){
    ballY=1;
    velocityY*=-1;
  }
  if((direction=='A' || direction=='a') && lineX>1){
    lineX-=5;
  }
  if((direction=='D'|| direction=='d') && (lineX+lineLen)<width){
    lineX+=5;
  }



  if(rand()%12>10){
    powerUpY=rand()%(height-1)+1;
    powerUpX=rand()%(width-1)+1;
  }
}
int main(){
  Setup();
  while(game){
  Draw();
  Logic();
  sleep(0.2);
  }
  Draw();
  cout << "your score is: " << score << endl;
  return 0;
}
