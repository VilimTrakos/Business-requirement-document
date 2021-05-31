// MD5:cOg/qOvDaxGtP3JmvLSLew==// Verifikator 5.05// Program:vj9// Opis zadatka:vj9// Autor:Vilim Trakoštanec// Poèetno vrijeme:28.5.2021. 13:59:55// Završno vrijeme:28.5.2021. 15:01:50// Identifikatori:croba,*,sifra,proizvodac[30],main,cijena,godina,cout<<"Alociram,unos_elementa,izbor,odluka,velicina,indeks,*lista,else,*zadnji,*novi,zadnji,dealokacija_liste,*prethodni,*tekuci,ispis_liste,lista,*polje// IP:fe80::bcf2:1454:adf8:2959%2 ( 4233 )// #:#include <ctime>[B],#include <iostream>[B],#include <cmath>,#include <iomanip>,#include "biblioteka_vrijeme.cc",// Uspješnih/neuspješnih prevoðenja:51/6#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int br_reda[]={0,17,18,20,34,39,49,51,66,70,79,87,97,102,113,115}; 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=1;f<=15;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: TEST("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if ((br>1)&&(p[i]>1))return;} else br=0;zaglavlje = (int)time(0);
  dat.open("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 15):" << endl; 
  for (f=1;f<=15;f++){dat << f << char(91) << br_reda[f] << char(93) << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include <iostream>
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

croba(){TEST(1);cout<<"Alociram element liste"<<endl;sljedeci=NULL;}
~croba(){TEST(2);cout<<"Dealociram: " <<sifra<<endl;}

void unos_elementa(){TEST(3);
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

void dealokacija_liste(){TEST(4);
croba*prethodni,*tekuci;
prethodni =this;
tekuci =this->sljedeci;

while(tekuci){TEST(5);
if(prethodni !=this)
  delete prethodni;
prethodni = tekuci;
tekuci = tekuci->sljedeci;
}
delete prethodni;
this->sljedeci=NULL;
}

void ispis_liste(){TEST(6);
croba* tekuci=this->sljedeci;
while(tekuci){TEST(7);
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

int main(){TEST(8);

int izbor,odluka,indeks;

do{TEST(9);

cout<<"------------------------------"<<endl;
cout<<"1.Alokacija galve pojedine vezane liste, unos pojedinog elementa"<<endl;
cout<<"2.Ispis svih elemenata liste, upit za dealokaciju vezane liste(glava ostaje)"<<endl;
cout<<"3.Alokacija polja vezanih lista/unos podataka u zadanu listu"<<endl;
cout<<"4.Ispis zadane vezane liste"<<endl;

cin>>izbor;
TEST(10); switch(izbor){
case 1:
if(lista==NULL)
lista=new croba;
lista->unos_elementa();
break;

case 2: cout<<"--------------ISPIS---------------"<<endl;
if(lista==NULL){TEST(11);cout<<"Lista je prazna!"<<endl;break;}
lista->ispis_liste();
cout<<"Ako zelite dealocirati listu(glava ostaje) unesite 1, a ako ne 0"<<endl;
cin>>odluka;
if(odluka==1)
lista->dealokacija_liste();
else break;
break;

case 3:
if(polje == NULL){TEST(12);
polje = new croba[20];
cout<<"Polje ne postoji, alociram polje velicine 20 elemenata"<<endl;}

cout<<"Odaberite u koje polje želite unjeti podatke (0-19)"<<endl;
do{TEST(13);
cin>>indeks;
if(indeks>20||indeks<0)
cout<<"Pogresan unos, ponovite upise željene liste(moguæe 0-19)"<<endl;
}while(indeks>20||indeks<0);
polje[indeks].unos_elementa();
break;


case 4:
if(polje==NULL)
{TEST(14);cout<<"Polje nije alocirano!"<<endl;break;}
cout<<"Odaberite polje (0-19) za ispis:"<<endl;
do{TEST(15);cin>>indeks;
if(indeks<0||indeks>20)
cout<<"Pogrešan unos!"<<endl<<"Ponavljam unos!"<<endl;
}while(indeks>20||indeks<0);
polje[indeks].ispis_liste();
break;
}
}while(izbor!=9);

  system("PAUSE");
}
  
  
    // Postoci testiranja:  100% 100% 100%// H1:224433141242301332031025202320002112123310001221111110114551020// H2:767768677777614777467677736013427514376650003571000630575770030// H3:000000000000000000000000000000000000000000000100011000000000000// H4:000000000000000000000000000000000000000000000000010000000000000
