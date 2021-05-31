// MD5:jhhu7YgRiRG1bP9dKuqiHw==// Verifikator 5.05// Program:vjezba7// Opis zadatka:vj7// Autor:Vilim Trakoštanec// Poèetno vrijeme:7.5.2021. 14:02:58// Završno vrijeme:7.5.2021. 15:30:56// Identifikatori:dat,troba,rb_zapisa,sifra,naziv[25],proizvodac[20],godina,main,troba_lista,*sljedeci,izbor,kreiraj,slog,*lista,int,else,lista,return,break,unos,brojac_zapisa,dat.close,*,kopiranje,*novi,*zadnji,if,zadnji// IP:fe80::bcf2:1454:adf8:2959%2 ( 4233 )// #:#include <ctime>[B],#include <iostream>[B],#include <fstream>,#include <cstdlib>,#include "biblioteka_vrijeme.cc",#include<string.h>,// Uspješnih/neuspješnih prevoðenja:43/30#include <iostream>
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

void kreiraj(){

troba_lista *lista;
lista =new troba_lista;
lista->sljedeci=NULL;

char izbor;

dat.open("Roba.dat",ios::in|ios::binary);
if(!dat){
cout<<"Datoteka nije postojala na disku te je kreirana, kao i glava vezane liste!"<<endl;
dat.open("Roba.dat",ios::out|ios::binary);
dat.close();dat.clear();
troba_lista *lista =new troba_lista;
return;
}
else
{
dat.seekg(0,ios::end);
cout<<"Datoteka postoji na disku i njezina je velicina="<<dat.tellg()<<"bajtova"<<endl;
cout<<"Zelite li kreirati novu datoteku (d/n)"<<endl;
dat.close();dat.clear();
cin>>izbor;
switch(izbor){
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

void unos(){
troba slog;
int brojac_zapisa;

dat.open("Roba.dat",ios::in|ios::binary);
if(!dat){
brojac_zapisa=0;
cout<<"Datoteka ne postoji na disku, prvo ju kreirajte kod opcije 1!"<<endl;
dat.close();dat.clear();
return;
}
else {
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

void kopiranje(){

troba slog;
troba_lista *novi, *zadnji=lista;
if(!lista)
{
cout<<"Lista ne postoji,nije moguce kopiranje trebate ju kreirati!"<<endl;
return;
}
dat.open("Roba.dat",ios::in|ios::binary);
while(1)
{
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



int main(){


int izbor;
do{
cout<<"1.Kreiranje datoteke i alokacija glave vezane liste"<<endl;
cout<<"2.Rucni unos u datoteku"<<endl;
cout<<"3.Kopiranje sadrzaja datoteke u vezanu listu"<<endl;
cout<<"9.Izlaz"<<endl;
cout<<"-------------------------------------------"<<endl;
cin>>izbor;
switch(izbor){
case 1: kreiraj();
break;
case 2: unos();break;
case 3: kopiranje();break;

}
}while(izbor!=9);
	system("PAUSE");
}
  
  
