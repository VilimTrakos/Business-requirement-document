// MD5:81jBu6UG5su9sIBwDDS62Q==// Verifikator 5.05// Program:vj9// Opis zadatka:vj9// Autor:Vilim Trakoštanec// Poèetno vrijeme:28.5.2021. 13:59:55// Završno vrijeme:28.5.2021. 15:01:46// Identifikatori:croba,*,sifra,proizvodac[30],main,cijena,godina,cout<<"Alociram,unos_elementa,izbor,odluka,velicina,indeks,*lista,else,*zadnji,*novi,zadnji,dealokacija_liste,*prethodni,*tekuci,ispis_liste,lista,*polje// IP:fe80::bcf2:1454:adf8:2959%2 ( 4233 )// #:#include <ctime>[B],#include <iostream>[B],#include <cmath>,#include <iomanip>,#include "biblioteka_vrijeme.cc",// Uspješnih/neuspješnih prevoðenja:50/6#include <iostream>
#include <cmath>
#include <iomanip>
#include "biblioteka_vrijeme.cc"
using namespace std;

class croba{

private:
croba* sljedeci;
public:
int sifra;
char proizvodac[30];
float cijena;
int godina;

croba(){cout<<"Alociram element liste"<<endl;sljedeci=NULL;}
~croba(){cout<<"Dealociram: " <<sifra<<endl;}

void unos_elementa(){
croba*zadnji,*novi;
zadnji=this;
while(zadnji->sljedeci)
	zadnji=zadnji->sljedeci;
novi = new croba;
zadnji->sljedeci=novi;
cout<<"-------------------UNOS-------------"<<endl;
cout<<"Sifra: ";cin>>novi->sifra;
cout<<"Proizvodac: ";unos(novi->proizvodac);
cout<<"Cijena: ";cin>>novi->cijena;
cout<<"Godina  proizvodnje: ";cin>>novi->godina;
}

void dealokacija_liste(){
croba*prethodni,*tekuci;
prethodni =this;
tekuci =this->sljedeci;

while(tekuci){
if(prethodni !=this)
	delete prethodni;
prethodni = tekuci;
tekuci = tekuci->sljedeci;
}
delete prethodni;
this->sljedeci=NULL;
}

void ispis_liste(){
croba* tekuci=this->sljedeci;
while(tekuci){
cout<<"Sifra: "<<tekuci->sifra<<endl;
cout<<"Proizvodac: "<<tekuci->proizvodac<<endl;
cout<<"Cijena: "<<setprecision(2)<<fixed<<tekuci->cijena<<endl;
cout<<"Godina proizvodnje:"<<tekuci->godina<<endl;
cout<<"Pokazivac na sljedeci element:"<<int((size_t)tekuci->sljedeci)<<endl;
tekuci =tekuci->sljedeci;
}
}

};

croba *lista=NULL;
croba *polje=NULL;

int main(){

int izbor,odluka,indeks;

do{

cout<<"------------------------------"<<endl;
cout<<"1.Alokacija galve pojedine vezane liste, unos pojedinog elementa"<<endl;
cout<<"2.Ispis svih elemenata liste, upit za dealokaciju vezane liste(glava ostaje)"<<endl;
cout<<"3.Alokacija polja vezanih lista/unos podataka u zadanu listu"<<endl;
cout<<"4.Ispis zadane vezane liste"<<endl;

cin>>izbor;
switch(izbor){
case 1:
if(lista==NULL)
lista=new croba;
lista->unos_elementa();
break;

case 2: cout<<"--------------ISPIS---------------"<<endl;
if(lista==NULL){cout<<"Lista je prazna!"<<endl;break;}
lista->ispis_liste();
cout<<"Ako zelite dealocirati listu(glava ostaje) unesite 1, a ako ne 0"<<endl;
cin>>odluka;
if(odluka==1)
lista->dealokacija_liste();
else break;
break;

case 3:
if(polje == NULL){
polje = new croba[20];
cout<<"Polje ne postoji, alociram polje velicine 20 elemenata"<<endl;}

cout<<"Odaberite u koje polje želite unjeti podatke (0-19)"<<endl;
do{
cin>>indeks;
if(indeks>20||indeks<0)
cout<<"Pogresan unos, ponovite upise željene liste(moguæe 0-19)"<<endl;
}while(indeks>20||indeks<0);
polje[indeks].unos_elementa();
break;


case 4:
if(polje==NULL)
{cout<<"Polje nije alocirano!"<<endl;break;}
cout<<"Odaberite polje (0-19) za ispis:"<<endl;
do{cin>>indeks;
if(indeks<0||indeks>20)
cout<<"Pogrešan unos!"<<endl<<"Ponavljam unos!"<<endl;
}while(indeks>20||indeks<0);
polje[indeks].ispis_liste();
break;
}
}while(izbor!=9);

	system("PAUSE");
}
  
  
  
