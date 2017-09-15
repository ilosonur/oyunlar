#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <vector>
const char heart[] = "\xe2\x99\xa8";
const char flag[] = "\xe2\x98\x85";
const char notOpened[] = "\xf0\x9f\x9d\x95";
const int len=10;
using namespace std;
int mineArray[len][len][2];
int coordinates[2][8]={ {0,1,1,-1,-1, 0,-1, 1} ,
                        {1,0,1,-1, 0,-1, 1,-1} };

int randomize(){
  return rand()%10;
}

void setup(){
  int a,b;
  for(int y=0;y<len;y++){
    for(int x=0;x<len;x++){
        if(randomize()>7){
          mineArray[y][x][0]=-1;
          mineArray[y][x][1]='M';
        }
        else{
          mineArray[y][x][0]=0;

        }
    }
  }
  for(int y=0;y<len;y++){
    for(int x=0;x<len;x++){
      if(mineArray[y][x][1]=='M'){
        for(int i=0;i<8;i++){
          a=y+coordinates[0][i];
          b=x+coordinates[1][i];
          if(a>=0 && b>=0 && a<20 && b<20 && mineArray[a][b][1]!='M'){
            mineArray[a][b][0]+=1;
          }
        }
      }
    }
  }
}
void draw(){
  for(int y=0;y<len+1;y++){
    if(y>0){
      cout<<y-1<<' ';
    }
    else{
      cout<<"  ";
    }
    for(int x=0;x<len;x++){
        if(y==0){
          cout<<x<<" ";
        }
        else if(mineArray[y][x][0]==-1 && mineArray[y][x][1]=='D'){
          cout<<'M'<<" ";
        }
        else if(mineArray[y][x][1]=='F'){
          cout<<flag<<" ";
        }
        else if(mineArray[y][x][1]=='D'){
          cout<<mineArray[y][x][0]<<" ";
        }
        else{
          cout<<notOpened<<" ";
        }
    }
    if(y==0 || y==len+1){
      cout<<endl;
      continue;
    }
    cout<<endl<<endl;
  }
}
void drawEnding(){
  for(int y=0;y<len;y++){
    for(int x=0;x<len;x++){
        if(mineArray[y][x][0]==-1){
          cout<<'M'<<' ';
        }
        else{
          cout<<mineArray[y][x][0]<<' ';
        }
    }
    cout<<endl<<endl;
  }
}
int input(){
  int no;
  cin>>no;
  return no;
}
void ending(){
  system("clear");
  cout<<"Dude u ded."<<endl;
}

int main(){
  int x,y;
  char flag;
  srand(time(NULL));
  setup();
  while(1){
    system("clear");
    draw();
    cout<<"Flag? (y/n) :";
    cin>>flag;
    if(flag=='y'){
      cout<<"x:";
      x=input();
      cout<<"y:";
      y=input();
      mineArray[y][x][1]='F';
      continue;
    }
    cout<<"x:";
    x=input();
    cout<<"y:";
    y=input();
    mineArray[y][x][1]='D';
    if(mineArray[y][x][0]==-1){
      draw();
      sleep(5);
      break;
    }
  }
  ending();
  sleep(3);
  drawEnding();
  return 0;

}
