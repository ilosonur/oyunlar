#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>
using namespace std;
#include "Question.h"
#define CREATEQUESTION QuestionArr[ii].setQuestion(question,A,B,C,D,answer);
#define ASKQUESTION QuestionArr[j].askQuestion(QuestionArr[j])//random atmak lazim.
int ii=0;
int totalPoint=0;
int birdX,birdY;
int height=35,width=100;
int obstacle1X=(width/5)*3;//will be decremented by width/10 each sec.
int obstacle2X=(width/5)*4;
int velocity,gravity;
int obsRange11,obsRange12;
char goUp;
bool game=true;
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
bool Randomize(){

  obsRange11=rand()%(height-1)+1;
  obsRange12=rand()%(height-1)+1;
  if(obsRange12>obsRange11){
    int temp=obsRange12;
    obsRange12=obsRange11;
    obsRange11=temp;
  }
  if((obsRange11-obsRange12)<=13 || (obsRange11-obsRange12)>=20){
    return true;
  }
  return false;

}
void Setup(){
  srand(time(NULL));
  birdX=(width/5)*1.5;
  birdY=height/2;
  gravity=6;
  velocity=0;
  obstacle1X=(width/5)*3;
  while(Randomize());


}
void Draw(){
  system("clear");
  for(int i = 0; i < height + 1;i++){
    for(int j = 0;j< width +1 ; j++){
      if(j==0 || j==width || i==0 || i==height){
         cout << "#";
       }
       else if(j==birdX && i==birdY){
         cout << "\xe2\x99\xa5";
       }
     else if(j==obstacle1X && (i<=obsRange12 || i>=obsRange11)){
       cout << "|";
     }

      else{
        cout << " ";
      }
    }
    cout << endl;

  }


}
void Logic(){
  if(birdY>=height){
    game=false;
    return;
  }
   goUp=getch();
  if(birdY>=height){
    game=false;
    return;
  }
  /*if((birdY>=obsRange11 || birdY<=obsRange12)&& birdX==obstacle1X){
    game=false;
    return;
  }*/
  if(goUp=='X' || goUp=='x'){
    velocity=-13;
    do {

      birdY+=(velocity+gravity);
      if(birdY<=1){
        birdY=1;
      }
      if(birdY>=height){
        game=false;
        return;
      }
      /*if((birdY>=obsRange11 || birdY<=obsRange12)&& birdX==obstacle1X){
        game=false;
        return;
      }*/
      Draw();

      velocity+=4;
      sleep(0.9);
    } while(velocity!=-1 );
  }
  else{
    birdY+=(velocity+gravity);
  }
  birdY+=(velocity+gravity);
  obstacle1X-=10;
  if(obstacle1X==0){
    obstacle1X=60;
  }
  if((birdY>=obsRange11 || birdY<=obsRange12)&& birdX==obstacle1X){
    game=false;
    return;
  }
  obstacle1X-=10;
  if(obstacle1X==0){
    obstacle1X=60;
  }



}
void gameOn(){
    Setup();
    while(game){
      Draw();
      Logic();
      sleep(1);

  } Draw();
    sleep(1);
    system("clear");
    sleep(0.7);
      game=true;
}
void Acilis(){
  system("clear");
  cout << "HELLOO MY LOVE. THIS LITTLE GAME IS CREATED BY.." << endl;
  sleep(5);
  cout << "Bu resmiyetle devam edicem sandin dimi asjdfakdfjf. "<< endl;
  sleep(7);
  cout <<"Ozledim dediginde yaninda olmuyorsam bunun tek bi sebebi vardirrr :))).."<<endl;
  sleep(7);
  system("clear");
  cout <<"Bugun sana yalan soyledigim icinn ozur dilerimm. Hayir temizlik yapmadim asdfjdfjk." << endl;
  sleep(5);
  cout <<"Biraz da mesajlasamadikk ama worth olacak bencee <3" << endl;
  sleep(10);
  system("clear");
  cout <<"Bitanem su an birbirimizden uzak oldugumuz icin bu oyunun sana iyi hissettirecegini dusundum."<< endl;
  sleep(8);
  cout <<"En azindan birazcik da olsa beni yaninda hissedersinn belkii <3"<< endl;
  sleep(6);
  cout <<"bu kucuk love note'larin ve bilgilendirmelerin arasinda tusa basmazsan sevinirim cunku bir bug var ve cozemedim sanirim asdfjakd."<<endl;
  sleep(8);
  cout <<"bi sure beklersen kendisi gececektirr zaten <3\nO zaman oyuna baslayalimmm"<<endl;
  sleep(9);
  system("clear");
  cout << "You should press X" << endl;
  sleep(9);
  cout<<"to move the bird.I mean the heart of the bird."<< endl;
  sleep(5);
  cout << "Askim su an degil,daha ortada kus bile yok......Hem aralarda tusa basma dememis miydim..." << endl;
  sleep(25);
  cout <<"Evet kucuk trollumu farkettin su an .. 25 saniye beklemek bile zor geliyo dimi askim :)))(hayir aglamiyorum) " << endl;
  sleep(5);
  cout << "Neyse esprime devam ediyim ben en iyisi adfdjfkdjfkd." << endl;
  sleep(6);
  system("clear");
  cout << "You should press X to move the bird.I mean the heart of the bird."<< endl;
  sleep(5);
  cout <<"No no,it was something with heart...."<< endl;
    sleep(9);
  Setup();
  cout<< "Indeed, It is a heart shaped box.I mean bird.Heart shaped bird"<< endl;
  sleep(10);
  Draw();
  cout << "The game is not started yet. You should wait a little bit.."<<endl;
  sleep(7);
  system("clear");
  cout << "Kisaca oyunu anlatiyim bitanemm. Oyun bildigin flappy bird." << endl;
  sleep(5);
  cout << "Ama benim tanimimla lovely bird." << endl;
  sleep(3);
  cout << "LOVELY BIRD IS NOW AVAILABLE ON GOOGLE PLAY.YOU CAN BUY IT BY 10 KISSES" << endl;
  sleep(7);
  cout <<"Ayy reklam icin ozur dilerim askimm. Istersen yalnizca 5 opucuk karsiligi";
  cout <<" addblock alabilirsin. :))" << endl;
  sleep(15);
  system("clear");
  cout <<" evet bu cirkin espri ekranda kalmasin diye clear attim asjdfasjkf. " << endl;
  sleep(5);
  system("clear");
  cout <<"oyunun kahramani kucuk tatlis kus.. Ya da buna bi isim bulalim.." << endl;
  sleep(4);
  cout <<"Ismin mavis olsun. O kadaaarrr sevgi dolmus ki sevgilisinin yanina gitmek icin"<<endl;
  sleep(2);
  cout <<"yola dusmus. Hem de bu yolda bazi engellerle karsilasacagini bilmeden ..." << endl;
  sleep(4);
  cout <<"the creator of this universe (bir yandan ceylan ertem dinlerken :)) ).." << endl;
  sleep(5);
  cout <<"demis ki madem bu kus aski ugruna yola dusmus ben de ona yardim edeyim.. " << endl;
  sleep(12);
  system("clear");
  cout <<"kus her engele carptiginda veya yere dustugunde ona bi sans daha verilecek." << endl;
  sleep(7);
  cout <<"Kucuk bir testten gecmek zorundaa. Peki ya gecemezse?" << endl;
  sleep(3);
  cout <<"Gecemezse de yoluna devam edecek cunku aski o kadar buyuk ki..... "<< endl;
  sleep(2);
  cout <<"Bi de olur da yanlis cevap verirsen tum bunlari tekrar okumak zorunda kalasin istemiyorum djfd. " << endl;
  sleep(10);
  system("clear");
  cout << "Oyun 3 saniye icinde baslayacak. Hazirr miyizzz bitanem :)) "<< endl;
  sleep(1);
  cout <<"3"<<endl;
  sleep(1);
  cout <<"2"<<endl;
  sleep(1);
  cout <<"1"<<endl;
  sleep(2);
  system("clear");
  cout <<"Sey askim tabi ki sen bi tusa basmazsan kus hareket etmeyecek ajdsfkasjdf." << endl;
  sleep(4);
  cout <<"o yuzden kusu yukari hareket ettirmek icin X'e asagi hareket ettirmek icin herhangi bir tusa basabilirsin"<<endl;
  sleep(5);
  cout <<" Artik oyunaa baslayabilirizzzzz :)))"<< endl;
  cout <<" Loading... " << endl;
  sleep(2.4);
  system("clear");
  for(int i=0;i<25/4;i++){
    cout << "\xe2\x99\xa5" << " ";//heart unicode.
  }
  for(int i=25/4;i<25;i++){
    cout <<"."<< " ";
  }
  cout << endl;
  sleep(4);
  system("clear");
  for(int i=0;i<25/2;i++){
    cout << "\xe2\x99\xa5" << " ";//heart unicode.
  }
  for(int i=25/2;i<25;i++){
    cout <<"."<< " ";
  }
  cout << endl;
  sleep(2);
  system("clear");
  for(int i=0;i<75/4;i++){
    cout << "\xe2\x99\xa5" << " ";//heart unicode.
  }
  for(int i=75/4;i<25;i++){
    cout <<"."<< " ";
  }
  cout << endl;
  sleep(4);
  system("clear");
  for(int i=0;i<25;i++){
    cout << "\xe2\x99\xa5" << " ";//heart unicode.
  }
  for(int i=25;i<25;i++){
    cout <<"."<< " ";
  }
  cout << endl;

  sleep(5);
  cout <<"The game loaded successfully." << endl;
  sleep(3);
  system("clear");

}
void Kapanis(){
  system("clear");
  cout <<"Bircok engellerle karsilassa da kus engelleri asmayi basarmis..." << endl;
  sleep(3);
  cout <<"Ve sevdigine kavusmusturr :)))))"<< endl;
  sleep(4);
  system("clear");
  cout <<"Bu uzun yolculukta bir seyin farkina varmistirr...." << endl;
  sleep(3);
  cout <<"Hissetmek icin her zaman dokunmak gerekmez..<3" << endl;
  sleep(3);
  cout<<"Yeri gelir kucuk bir sey bile yeterli olur :)))" << endl;
  sleep(3);
  cout <<"Bazen tatlii bir foti, bazen guzel bir soz, bazen de kucuk bir oyun :)"<<endl;
  sleep(5);
  system("clear");
  cout <<"Bazen de o kadar seversin ki kendi kendine... " << endl;
  sleep(4);
  cout <<"Sevgim mesafelerden cok daha buyuk.. " << endl;
  sleep(2);
  cout <<"..ve sevgimi hissettirmemek icin hicbir sebebim yok dersin :)))" << endl;
  sleep(14);
  system("clear");
  cout <<"Su an sana yaaa temizlik bitti de kod yaziyodum sana yazmayi unuttum dedim.. " << endl;
  sleep(6);
  cout <<"Biliyorum uzuldun ama bu oyun bittiginde inanilmaz mutlu olacagini dusunuyorum <3"<< endl;
  sleep(5);
  cout <<"Biraz da benim olayim bu biliyosun :))))" << endl;
  sleep(5);
  cout <<"Cok daha fazla sey yazmak isterdim ama zamanim kisitli :))" << endl;
  sleep(2);
  cout <<"O yuzdenn uzulerek oyunumuzun sonuna geldigini soylemek istiyorumm :((("<<endl;
  sleep(4);
  cout <<"Basima gelen en guzel seysin. Varligini bilmek bile.."<< endl;
  sleep(3);
  cout <<"Beni her seyden cok mutlu ediyo <33 Iyi Ki Benimlesin :)))" << endl;
  sleep(10);
  system("clear");
  cout<<"Seninle olmak bana umut veriyo..";
  sleep(2);
  cout <<"ve Seni ozlemek bile o kadar guzel ki <3"<< endl;
  sleep(3);
  cout <<"Hayatta bu kadar deger verilmeyi hak eden.. "<<endl;
  sleep(1);
  cout<<"bi seye sahip olmak da.."<<endl;
  sleep(3);
  cout<<".. bi o kadar guzel :))"<<endl;
  sleep(12);
  system("clear");
  cout <<"Peki nerden mi biliyorum.." << endl;
  sleep(2);
  cout <<"cunku ben dunyanin en guzel seyine sahibim "<< endl;
  sleep(3);
  cout <<"ve ona hayatimdaki her seyden daha cok deger veriyorum";
  cout << "\xe2\x99\xa5"<<" "<<endl;

  sleep(13);
  system("clear");
  cout<<"Su an 500. satirima gelmek uzereyim.."<<endl;
  sleep(1);
  cout<<"ve yazdigim her satirda seni hissettim :))"<<endl;
  sleep(3);
  cout<<"umarim senin de beni yaninda hissetmeni saglayabilmisimdirr <3"<<endl;
  sleep(8);
  system("clear");
  cout <<"SENI"<<endl;
  sleep(1);
  system("clear");
  cout <<"HER SEYDEN"<<endl;
  sleep(1);
  system("clear");
  cout<<"COK SEVIYORUM.."<<endl;
  sleep(1.4);

  system("clear");
  sleep(2);
  cout<<"bu arada oyunda bir bugda vardi umarim farketmemissindir adsjdfjd." << endl;
  sleep(3);
  cout <<"bazen oyun kendi kendine bi seyler basiyo :/"<<endl;
  sleep(2.5);
  cout <<"bazen de"<<endl;
  sleep(1);
  cout<<"infinite"<<endl;
  sleep(1.3);
  cout<<"loo"<<endl;
  sleep(1);
  system("clear");
  for(int l=0;;l++){
    for(int t=0;t<5;t++){
      if(t==2){
        cout << "\xe2\x99\xa5"<<" ";
      }
      cout <<"Seni Seviyorum!    ";
    }
    cout << "\xe2\x99\xa5" <<endl;
    sleep(0.2);
  }


}
int main(){
  system("clear");
  cout <<"TUM OYUNU CAPS LOCK ACIK OYNAMALISINIZ." << endl;
  sleep(3);
  cout <<"TUS SPAMLAMANIZ TESTTE HATAYA YOL ACACAKTIR!"<< endl;
  sleep(4);
  cout<<"NE TESTI.."<<endl;
  sleep(2);
  cout<<"TESTI NERDEN CIKTI NEYSE..."<<endl;
  sleep(3);
  system("clear");
  gameOn();
 Acilis();
 char temp;
 int sorusayisi;
 string question="NA";
 string A="NA";
 string B="NA";
 string C="NA";
 string D="NA";
 char answer='A';
 Question *QuestionArr=new Question[100];
  gameOn();
  cout <<"Crazy mechanics huh.guess,there is nothing much to do with this game."<<endl;
  cout <<"Ve hayir istedigin sorudan baslayamazsin ajdsfkdjfk. "<<endl;
  sleep(9);
  question="Ilos ve onurun cikmaya basladiklari ay";
  A="HAZIRAN";
  B="Mayis";
  C="Temmuz";
  D="NA";
  answer='B';
  CREATEQUESTION
  //Question 2
  question="peki ya gunu?";
  A="28";
  B="18";
  C="11i aksami";
  D="10u aksami";
  answer='C';
  CREATEQUESTION
  //Question 3
  question="peki gunu?";
  A="Carsamba";
  B="Carsamba ama aksami";
  C="Persembe";
  D="Persembe ama aksami";
  answer='D';
  CREATEQUESTION
  for(int j=0;j<3;j++){
    ASKQUESTION;
  }
  system("clear");
  cout << "O zaman oyuna devam edelimmm <3"<<endl;
  sleep(3);
  gameOn();
  cout <<"Engeller asilmak icindir dimi askim :)" << endl;
  sleep(4);
  system("clear");
  //Question 4
  question="Cikmaya basladigimiz gun nerdeydik?";
  A="Devrim cimleri";
  B="Ceng 1. kat";
  C="Ceng 2. kat";
  D="Devrim stadyum";
  answer='B';
  CREATEQUESTION
  //Question 5
  question="En etkili cikma teklifini seciniz";
  A="Iliskimiz hakkinda ne dusunuyosun";
  B="Iliskiler hakkinda ne dusunuyosun";
  C="Iliskilere bakisin nedir";
  D="Benimle cikar misin?";
  answer='A';
  CREATEQUESTION
  //Question 6
  question="Peki en guzel cevap";
  A="Hicbir sey dusunmuyorum";
  B="Hic birsey dusunmuyorum";
  C="Bilmem sen ne dusunuyosun";
  D="Bilmem ne dusundugumun onemi var mi";
  answer='C';
  CREATEQUESTION
  //Question 7
  question="Tam da o gun ilosun giydigi ve ayni zamanda\n onurun ilosa verdigi ilk kiyafet";
  A="gri polar";
  B="sort";
  C="Odtu polari";
  D="NA";
  answer='C';
  CREATEQUESTION
  for(int j=3;j<7;j++){
    ASKQUESTION;
  }
  system("clear");
  cout <<"Kus hedefine gittikce yaklasmaktadir.." << endl;
  sleep(3);
  cout <<"nerden baksan bi 5-6 gun falan kalmistirr :)))"<< endl;
  sleep(5);
  gameOn();
  //Question 8
  question="Cikmaya basladiktan hemen sonra senlik esnasinda onur neyini kaybetmisti";
  A="Kredi karti";
  B="Kimlik";
  C="Telefon";
  D="HAYALLERINI";
  answer='A';
  CREATEQUESTION
  //Question 9
  question="Ayni aksam nazdan donerken bindikleri arabanin markasi?";
  A="Skoda";
  B="Renault";
  C="Bunun iliskiyle ne alakasi var";
  D="Ford";
  answer='C';
  CREATEQUESTION
  //Question 10
  question="Bindikleri arabanin soforunun beyni okulda toplam kac kiside vardir";
  A="15-20";
  B="Sadece onda vardir";
  C="4";
  D="5";
  answer='C';
  CREATEQUESTION
  //Question 11
  question="Hangisi senlik aksami(ayni aksam) nazdan alinan ickiler arasinda degildir?";
  A="Jager";
  B="Bira";
  C="Vodka";
  D="NA";
  answer='C';
  CREATEQUESTION
  //Question 12
  question="Peki hangisi o aksam takildigimiz tayfadan biridir";
  A="Azad";
  B="Gunes";
  C="Kaan";
  D="Veysel";
  answer='A';
  CREATEQUESTION
  for(int j=7;j<12;j++){
    ASKQUESTION;
  }
  system("clear");
  cout <<" BACK TO THEEE GAMEE " << endl;
  sleep(0.8);
  gameOn();
  //Question 13
  question="Ilk tartismamizin sebebi nedir?";
  A="Onurun gereksiz bir saka yapip ilosunu uzmesi";
  B="Ilosun saka yapmasi";
  C="Hatali soru ilos ve onur tartismaz.";
  D="Ilosun hediyelere bakip senin aldigin hediyeler anlamsiz demesi.";
  answer='C';
  CREATEQUESTION
  //Question 14
  question="Ilosun iliskiden beklentisini belirtirken soyledigi ilk sey nedir?";
  A="Guven";
  B="Sadakat";
  C="Kiyafetine karisilmamasi";
  D="NA";
  answer='C';
  CREATEQUESTION
  //Queston 15
  question="Saklamayi dusundukleri fakat unuttuklari ilk esya";
  A="Sarap tipasi";
  B="Sinema bileti(wonder woman)";
  C="Ilk alisveris fisi";
  D="NA";
  answer='A';
  CREATEQUESTION
  for(int j=12;j<15;j++){
    ASKQUESTION;
  }
  system("clear");
  cout <<"what is done in love is done well <3"<<endl;
  sleep(3);
  gameOn();
  cout<<"sana bi yalan daha soyledim.." << endl;
  sleep(2);
  cout<<"oyunda skor yok. :)))" << endl;
  sleep(3);
  system("clear");
  //Question 16
  question="Cikmaya basladiktan sonra girdikleri ilk sinav";
  A="Math120";
  B="Phys106";
  C="Phys105";
  D="Ceng140";
  answer='A';
  CREATEQUESTION
  //Question 17
  question="Ilos'un aldigi not";
  A="80";
  B="75";
  C="85";
  D="55";
  answer='A';
  CREATEQUESTION
  //Question 18
  question="Peki ya Onur'un aldigi not";
  A="o da 80 almistir.";
  B="o kadar olmasa da bi 70i var.";
  C="48 de almis olabilir.";
  D="Yok canim 48 almamistir.";
  answer='C';
  CREATEQUESTION
  //Question 19
  question="Peki bunun sebebi???";
  A="sinavdan once kavga etmeleri";
  B="Sinav sabahi ilosun onura aksam annemlerle taniscaksin demesi.";
  C="Onurun sinava yeterince calismis olmamasi.";
  D="Ilosun tum derslere gidip not tutmasi.";
  answer='B';
  CREATEQUESTION
  //Question 20
  question="Peki bunun gercek sebebi";
  A="Onurun calismamis olmasi";
  B="Onurun az calismis olmasi";
  C="Onurun zeki ama calismiyor olmasi.";
  D="Ilosun onur'a 120 calistirmis olmasi";
  answer='D';
  CREATEQUESTION
  for(int j=15;j<19;j++){
    ASKQUESTION;
  }
  system("clear");
  cout <<"Without love, we are birds with broken wings"<<endl;
  sleep(4);
  cout <<"tabi benim caseim icin .."<<endl;
  sleep(3);
  cout <<"there would be no bird :))"<<endl;
  sleep(3);
  cout <<"cunku sen yasama sebebimsin <3"<<endl;
  sleep(4);
  gameOn();
  //Question 21
  question="Quick China'ya ilk gittiklerinde cikan falda ne yaziyordu";
  A="Seneye evleneceksin";
  B="Seneye bosanacaksin";
  C="Seneye sevgilin olacak";
  D="Onur bu notu ilosun gormesine engel olmustur";
  answer='A';
  CREATEQUESTION
  //Question 22
  question="Ilos sade soda veya seftalili dondurma yedigi icin\n ne ile suclanmistir";
  A="cok para harcamakla";
  B="Zevksiz olmakla.";
  C="Sagliksiz beslenmekle";
  D="Vizyonsuz olmakla";
  answer='D';
  CREATEQUESTION
  //Question 23
  question="Onur'un ilosa aldigi ilk hediye?";
  A="Kolye";
  B="Bandana";
  C="Bileklik";
  D="NA";
  answer='B';
  CREATEQUESTION
  for(int j=20;j<23;j++){
    ASKQUESTION;
  }
  system("clear");
  cout<<"Kus hayati boyunca korkmus.." << endl;
  sleep(2);
  cout<<"..uzulmekten,hirpalanmaktan" << endl;
  sleep(2);
  cout <<"ona demisler ki aska ucma kanatlarin yanar.." << endl;
  sleep(4);
  cout <<"O da demis ki.."<<endl;
  sleep(2);
  cout <<"Aska ucmayan kanat neye yarar :))))" << endl;
  sleep(7);
  system("clear");
  cout <<"Kucuk bir mevlana ve yunus emre alintisi yaptim,sssst caktirma :)"<<endl;
  sleep(3);
  system("clear");
  gameOn();
  cout <<"Sira geldi ingilizce sorulara lol." << endl;
  sleep(2);
  cout <<"You must have seen this coming asko :)"<< endl;
  sleep(3);
  system("clear");
  //Question 24
  question="Asagidakilerden hangisi coguldur?";
  A="Person";
  B="Sheep";
  C="People";
  D="Peoples";
  answer='C';
  CREATEQUESTION
  //Question 25
  question="choose the technique used most frequently by onur while preparing a present";
  A="Magic";
  B="Misleading";
  C="Not telling that he has a present to give you";
  D="Obviously,the answer is not C or D.Ups,Didn't mean to mislead you or did I ?";
  answer='B';
  CREATEQUESTION
  //question 26
  question="peki peki,when a clue is given,which word do we prefer to react?";
  A="OH";
  B="WOW";
  C="WHAT";
  D="LEL";
  answer='C';
  CREATEQUESTION
  for(int j=23;j<26;j++){
    ASKQUESTION;
  }
  Kapanis();
  return 0;
}
void Question::setQuestion(string question,string A,string B,string C,string D,char answer){
this->question=question;this->A=A; this->B=B; this->C=C; this->D=D; this->answer=answer;
ii++;
}
bool Question::askQuestion(Question question){
  system("clear");
  char input;
  cout <<"     "<<question.question << endl << endl;
  cout << "     A )" << question.A << endl;
  cout << "     B )" << question.B << endl;
  if(question.C!="NA"){cout << "     C )" << question.C << endl;}
  if(question.D!="NA"){cout << "     D )" << question.D << endl;}
  cout <<"     Askoo cevapp ne :)))  " <<endl<< "     ";
  cin >> input;
  sleep(2);
  cout << endl << endl << endl << endl << endl;
  if(input==question.answer){
    cout << "     Dogru Cevap! Tebrikler Sevgilim<3 " << endl;
    sleep(3.5);
    system("clear");
    for(int l=0;l<5;l++){
      for(int t=0;t<5;t++){
        cout <<"Seni Seviyorum!    ";
      }
      cout << endl;
      sleep(0.2);
    }
    sleep(1);

    return 1;
  }

  cout << "     Yanlis Cevap!\n     Sanirimmm misclick olduu :))\n     Dogru Cevap : " << question.answer<<endl;
  sleep(10);
  system("clear");
  for(int l=0;l<5;l++){
    for(int t=0;t<5;t++){
      cout <<"Seni Cok Seviyorum!    ";
    }
    cout << endl;
    sleep(0.2);
  }
  sleep(1);
  return 0;
}
