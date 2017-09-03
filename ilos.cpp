
#include<ctime>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>
//oyuna random yerlerde text cikma ozelligi eklenebilir
using namespace std;
int TIME;
string text[100];//bu asil text
string text_temp[100];//bu da temp


void esitle(){
  for(int i=0;i<96;i++){
    text_temp[i]=text[i];//text degistigi icin sonda basmak icin temp lazim
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

int main( ){
  setTime();
  setText();
  esitle();
  int i=0;
  double second;
  char dir;
  time_t timer1;
  time(&timer1);
  time_t  timer2;
    for(i = 0;i<100000000000;){
      system("clear");
      int a=second;//second double olunca (TIME-a)%60 hata veriyo.
      cout <<"KALAN SURE : " << (TIME-a)/60 <<" Dakika "<<(TIME-a)%60<< " Saniye"<<endl;
      cout<<"         |"<<endl;
      cout<<"         |"<<endl;
      cout<<"         |"<<endl;
      if(second>=TIME){// sure bitti
        break;
      }
      cout<<"         |"<<endl;
      cout << "         "<<text[i] << endl;
      cout << endl << endl << endl;
      dir=getch();
    while(text[i].length() && dir==text[i][0]){
      system("clear");
      time(&timer2);
      second = difftime(timer2,timer1);

    text[i]=text[i].substr(1);
    dir='A';// eger art arda iki ayni harf varsa loopta kaliyor.o yuzden dir degisiyor.
              }
      if(text[i].length()==0){
        i++;
      }
      dir='A';
}
  system("clear");
    for(int k=0;k<i+1;k++){//i yaptigin dogru sayisi
      cout <<"   "<< text_temp[k] << endl;
    }

    return 0;
}
