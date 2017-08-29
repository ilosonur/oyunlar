#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <vector>
using namespace std;
int onur=0;
int x,y;
int height=10,width=20;
char dir='X';// it will be either W A S D
int tailX[100];
int tailY[100];
int tailLen=1;
int fruitX,fruitY;
bool game=true;
int score=0;
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
void Setup(){
srand(time(NULL));
 x=width/2;
 y=height/2;
 tailX[0]=x;
 tailY[0]=y;
fruitX=rand()%(width-1)+1;
fruitY=rand()%(height-1)+1;
}

void Show(){
  system("clear");
  for(int i=0;i<width+1;i++){
    cout << "_";
  }
  cout << endl;
  for(int i =0; i < height+1; i++ ){

    for(int j = 0; j < width+1; j++){
      int flag=0;
      if(j==0 || j==width){
        cout << "|";
        continue;
      }
      if(i==y && j==x){
        cout << "$";
        continue;
      }
      for(int k=0;k<tailLen;k++){
        if(tailX[k]==j && tailY[k]==i){
          flag=1;
          cout << ".";
        }
      }
      if(flag){ continue;}
      if(i==fruitY && j==fruitX){
        cout << "0";
        continue;
      }
      if(i==height ){
      cout << "_";
      continue;
    }
    cout << " ";
    }
    cout << endl;
  }
}

void Game(){
  int temp1x=tailX[0];
  int temp1y=tailY[0];
  int temp2x,temp2y;

  tailX[0]=x;
  tailY[0]=y;
  for(int i=1;i<tailLen;i++){
    temp2x=tailX[i];
    temp2y=tailY[i];
    tailX[i]=temp1x;
    tailY[i]=temp1y;
    temp1x=temp2x;
    temp1y=temp2y;

  }
  char temp=dir;
  dir=getch();
  if(temp=='A' && dir=='D'){game=false;return;}
  if(temp=='D' && dir=='A'){game=false;return;}
  if(temp=='S' && dir=='W'){game=false;return;}
  if(temp=='W' && dir=='S'){game=false;return;}
  if(dir=='W' || dir=='w'){y--; }
  if(dir=='A' || dir=='a'){ x--;}
  if(dir=='S' || dir=='s'){y++; }
  if(dir=='D' || dir=='d'){ x++; }
  if(x==fruitX && y==fruitY){
    int flag=1;
    score++;
    tailLen++;
    while(flag){// fruit snake'in ustunde cikmamali.
      flag=0;
      fruitX=rand()%(width-1)+1;
      fruitY=rand()%(height-1)+1;
      if(fruitY==y && fruitX==x){flag=1;}
      for(int j=0;j<tailLen;j++){
        if(fruitY==tailY[j] && fruitX==tailX[j]){
          flag=1;
        }
      }
    }
  }
  for(int i=0;i<tailLen;i++){
    if(tailY[i]==y && tailX[i]==x){
      game=false;
    }
  }
  if(x==width){x=1;}
  if(x==0){x=width-1;}
  if(y==-1){y=height-1;}
  if(y==height+1){y=1;}

}


int main(){
  cout << "Enter Width: " << endl;
  cin >> width;
  cout << "Enter Height: "<< endl;
  cin >> height;
  Setup();
  while(game){
    onur++;
    Show();
    Game();
    if(!game){
      system("clear");
    }
    sleep(0.5);
  }
  cout << "The game is over." << endl;
  cout << "Your score is " << score << endl;
  return 0;
}
