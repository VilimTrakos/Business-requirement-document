// MD5:XMFDe7SF3XP8/+7acI93XA==// Verifikator 5.05// Program:vjezba7// Opis zadatka:vj7// Autor:Vilim Trakoštanec// Poèetno vrijeme:7.5.2021. 14:02:58// Završno vrijeme:7.5.2021. 15:30:56// Identifikatori:dat,troba,rb_zapisa,sifra,naziv[25],proizvodac[20],godina,main,troba_lista,*sljedeci,izbor,kreiraj,slog,*lista,int,else,lista,return,break,unos,brojac_zapisa,dat.close,*,kopiranje,*novi,*zadnji,if,zadnji// IP:fe80::bcf2:1454:adf8:2959%2 ( 4233 )// #:#include <ctime>[B],#include <iostream>[B],#include <fstream>,#include <cstdlib>,#include "biblioteka_vrijeme.cc",#include<string.h>,// Uspješnih/neuspješnih prevoðenja:43/30#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int br_reda[]={0,33,42,50,56,79,84,90,107,112,118,138,142,149}; 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=1;f<=13;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: TEST("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if ((br>1)&&(p[i]>1))return;} else br=0;zaglavlje = (int)time(0);
  dat.open("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 13):" << endl; 
  for (f=1;f<=13;f++){dat << f << char(91) << br_reda[f] << char(93) << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include <iostream>
#include <fstream>
#include <cstdlib>
#include "biblioteka_vrijeme.cc"
#include <fstream>
#include<string.h>
using namespace std;
fstream dat;

struct troba{

int rb_zapisa;
int sifra;
char naziv[25];
char proizvodac[20];
int godina;

};

struct troba_lista{

int rb_zapisa;
int sifra;
char naziv[25];
char proizvodac[20];
int godina;
troba_lista *sljedeci;

};

troba_lista *lista;

void kreiraj(){TEST(1);

troba_lista *lista;
lista =new troba_lista;
lista->sljedeci=NULL;

char izbor;

dat.open("Roba.dat",ios::in|ios::binary);
if(!dat){TEST(2);
cout<<"Datoteka nije postojala na disku te je kreirana, kao i glava vezane liste!"<<endl;
dat.open("Roba.dat",ios::out|ios::binary);
dat.close();dat.clear();
troba_lista *lista =new troba_lista;
return;
}
else
{TEST(3);
dat.seekg(0,ios::end);
cout<<"Datoteka postoji na disku i njezina je velicina="<<dat.tellg()<<"bajtova"<<endl;
cout<<"Zelite li kreirati novu datoteku (d/n)"<<endl;
dat.close();dat.clear();
cin>>izbor;
TEST(4); switch(izbor){
case 'd':

dat.open("Roba.dat",ios::out);
dat.close();dat.clear();

lista =new troba_lista;

break;
case 'n': 
cout<<"Vracanje"<<endl;
dat.close();dat.clear();
break;

}
}
if(lista->sljedeci)
cout<<"Vezana lista nije prazna"<<endl;
else
cout<<"Vezana lista je prazna"<<endl;
dat.close();dat.clear();
}

void unos(){TEST(5);
troba slog;
int brojac_zapisa;

dat.open("Roba.dat",ios::in|ios::binary);
if(!dat){TEST(6);
brojac_zapisa=0;
cout<<"Datoteka ne postoji na disku, prvo ju kreirajte kod opcije 1!"<<endl;
dat.close();dat.clear();
return;
}
else {TEST(7);
dat.seekg(0,ios::end);
brojac_zapisa=dat.tellg()/sizeof(troba);
dat.close();dat.clear();
dat.open("Roba.dat",ios::in|ios::out|ios::ate|ios::binary);
}
brojac_zapisa++;
cout<<"Zapis br."<<brojac_zapisa<<endl;
slog.rb_zapisa=brojac_zapisa;
cout<<"Sifra: ";cin>>slog.sifra;
cout<<"Naziv: ";unos(slog.naziv);
cout<<"Proizvodac: ";unos(slog.proizvodac);
cout<<"Godina proizvodnje: ";cin>>slog.godina;
dat.write((char*)&slog,sizeof(troba));
dat.close();dat.clear(); 
}

void kopiranje(){TEST(8);

troba slog;
troba_lista *novi, *zadnji=lista;
if(!lista)
{TEST(9);
cout<<"Lista ne postoji,nije moguce kopiranje trebate ju kreirati!"<<endl;
return;
}
dat.open("Roba.dat",ios::in|ios::binary);
while(1)
{TEST(10);
dat.read((char*)&slog,sizeof(troba));
if(dat.eof())break;
novi=new troba_lista;
zadnji->sljedeci=novi;
novi->sljedeci=NULL;
novi->rb_zapisa=slog.rb_zapisa;
novi->sifra=slog.sifra;
cout<<"Primarni kljuc zapisa no."<<slog.rb_zapisa<<" je: "<<slog.sifra<<endl;
strcpy(novi->naziv,slog.naziv);
strcpy(novi->proizvodac,slog.proizvodac);
novi->godina=slog.godina;
zadnji=novi;
}
dat.close();dat.clear();

};



int main(){TEST(11);


int izbor;
do{TEST(12);
cout<<"1.Kreiranje datoteke i alokacija glave vezane liste"<<endl;
cout<<"2.Rucni unos u datoteku"<<endl;
cout<<"3.Kopiranje sadrzaja datoteke u vezanu listu"<<endl;
cout<<"9.Izlaz"<<endl;
cout<<"-------------------------------------------"<<endl;
cin>>izbor;
TEST(13); switch(izbor){
case 1: kreiraj();
break;
case 2: unos();break;
case 3: kopiranje();break;

}
}while(izbor!=9);
  system("PAUSE");
}
  
    // Postoci testiranja:  100% 100% 92%// H1:33464544300023332152063320432123000040530554544424453401013004200041313343133420030100330// H2:77687776505607545557663552766346001030430477777547772504357014550060206741676750660100330// H3:00100000000000000000000000001000000000000000000000000000000000000000100000000001000000000// H4:00000000000000000000000010000000000000000000000000000000000000000000000000000000000000000
