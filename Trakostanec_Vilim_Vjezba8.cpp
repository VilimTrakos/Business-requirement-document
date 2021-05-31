// MD5:WeMsf7UMtD7Rwbn70snBHA==// Verifikator 5.05// Program:Vjezba8// Opis zadatka:vj8// Autor:Vilim Trakoštanec// Poèetno vrijeme:14.5.2021. 13:59:31// Završno vrijeme:14.5.2021. 15:10:45// Identifikatori:ctrokut,b_trokuta,id_trokuta,a,b,c,main,s,povrsina,izbor,unos,*pok,ispis,i,else,*polje,broj_elemenata// IP:fe80::bcf2:1454:adf8:2959%2 ( 4233 )// #:#include <ctime>[B],#include <iostream>,#include <cmath>,#include "cvrijeme.cc",// Uspješnih/neuspješnih prevoðenja:25/22#include <iostream>
#include <cmath>
#include "cvrijeme.cc"
using namespace std;

class ctrokut{

public:
static int b_trokuta;
long id_trokuta;
double a,b,c;

private:
float s;

public:
float povrsina(){
if(sqrt(s*(s-a)*(s-b)*(s-c))<0)
	return -1;
return sqrt(s*(s-a)*(s-b)*(s-c));
};

void unos(){

cout<<"---------Unos------------"<<endl;
cout<<"Unesite podatke o trokutu:"<<endl;
cout<<"Sifra trokuta: ";cin>>id_trokuta;
cout<<"Duljina stranice a: ";cin>>a;
cout<<"Duljina stranice b: ";cin>>b;
cout<<"Duljina stranice c: ";cin>>c;
s=(a+b+c)/2;
};

void ispis(){
cout<<"----------------ISPIS------------"<<endl;
cout<<"Trokut: "<<id_trokuta<<endl;
cout<<"a="<<a<<endl<<"b="<<b<<endl<<"c="<<c<<endl;
if(povrsina()!=-1)
cout<<"Povrsina trokuta je: "<<povrsina()<<endl;
else
cout<<"Stranice trokuta ne cine trokut!"<<endl;
};

};

int ctrokut::b_trokuta;
ctrokut *pok=NULL;
ctrokut *polje=0;

int main(){



ctrokut::b_trokuta=0;
int broj_elemenata;
int izbor,i;
do{
cout<<"--------------------------"<<endl;
cout<<"1.Dinamièka alokacija objekta i unos podataka o trokutu"<<endl;
cout<<"2.Ispis podataka o unesenom trokutu"<<endl;
cout<<"3.Dinamièka alokacija polja trokuta i unos podataka o pojedninom trokutu u polje"<<endl;
cout<<"4.Ispis podataka iz polja o trokutima"<<endl;
cout<<"9. izlaz"<<endl;
cin>>izbor;
switch(izbor){
case 1: if(pok==NULL){
cout<<"Alociram ne postojeci objekt..."<<endl;
pok=new ctrokut;
}
else 
{
cout<<"Objekt postoji slijedi unos:"<<endl;
pok->unos();break;
}break;

case 2: pok->ispis();break;

case 3: if(polje==0){
cout<<"Treba alocirati velicinu polja!"<<endl<<"Unesite broj elemenata polja:"<<endl;
cin>>broj_elemenata;
polje = new ctrokut[broj_elemenata];
}
else {
polje[ctrokut::b_trokuta].unos();ctrokut::b_trokuta++;break;
}
case 4:
for(i=0;i<ctrokut::b_trokuta;i++)polje[i].ispis();break;
}
}while(izbor!=9);
	system("PAUSE");
}
  
