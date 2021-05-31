// MD5:QEpmVREgjDS/9snPlzuL4A==// Verifikator 5.02// Program:vjezba3// Opis zadatka:vjezba3// Autor:Vilim Trakoštanec// Poèetno vrijeme:2.4.2021. 13:55:15// Završno vrijeme:2.4.2021. 15:27:16// Identifikatori:trac,sifra,naziv[20],proizvodac[20],main,godina,vrijeme,*prethodni,*sljedeci,izbor,*lista,lista,kraj,*novi,*zadnji,novi,*tekuci,pocetak,*,brisi,*brisi// IP:fe80::bcf2:1454:adf8:2959%2 ( 4233 )// #:#include <ctime>[B],#include <iostream>[B],#include "biblioteka_vrijeme.cc",#include<cstring>,// Uspješnih/neuspješnih prevoðenja:56/2#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=0;f<60;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: TEST("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if ((br>1)&&(p[i]>1))return;} else br=0;zaglavlje = (int)time(0);
  dat.open("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 12):" << endl; 
  for (f=0;f<60;f++){if (p[f]>0) dat << f << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include <iostream>
#include "biblioteka_vrijeme.cc"
#include<cstring>
using namespace std;

struct trac{
int sifra;
char naziv[20];
char proizvodac[20];
int godina;
long vrijeme;
trac*prethodni;
trac*sljedeci;
};

void kraj(trac*lista){TEST(1);

trac*novi,*zadnji;
zadnji=lista;
while(zadnji->sljedeci)
  zadnji=zadnji->sljedeci;
novi=new trac;
novi->prethodni=zadnji;
novi->sljedeci=NULL;
zadnji->sljedeci=novi;
cout<<"-------------UPIS NA KRAJ-----------"<<endl;
vrijeme_pocetak();
cout<<"Sifra racunala: "<<endl;
cin>>novi->sifra;
cout<<"Naziv racunala: "<<endl;
unos(novi->naziv);
cout<<"Naziv proizvodaca: "<<endl;
unos(novi->proizvodac);
cout<<"godina proizvodnje: "<<endl;
cin>>novi->godina;
vrijeme_kraj();
novi->vrijeme = vrijeme_proteklo();

cout<<"------------ISPIS OD KRAJA--------------"<<endl;
trac*tekuci=lista->sljedeci;
while(tekuci->sljedeci)
tekuci=tekuci->sljedeci;

while(tekuci!=lista){TEST(2);
cout<<"Adresa elementa="<<int((size_t)tekuci)<<endl;
cout<<"sifra racunala:"<<tekuci->sifra<<endl;
cout<<"naziv racunala:"<<tekuci->naziv<<endl;
cout<<"naziv proizvodaca:"<<tekuci->proizvodac<<endl;
cout<<"godina proizvodnje:"<<tekuci->godina<<endl;
cout<<"vrijeme potrebtno za unos: "<<tekuci->vrijeme<<" tisucinki"<<endl;
cout<<"Adresa sljedeceg: "<<int((size_t)tekuci->sljedeci)<<endl;
cout<<"Adresa prethodnog: "<<int((size_t)tekuci->prethodni)<<endl;
tekuci =tekuci->prethodni;
cout<<"---------------------------"<<endl;
}

};

void pocetak(trac*lista){TEST(3);

if(!lista->sljedeci){TEST(4);
kraj(lista);
return;
}

cout<<"------------ISPIS OD POCETKA--------------"<<endl;
trac*tekuci=lista->sljedeci;


while(tekuci)
{TEST(5);
cout<<"Adresa elementa="<<int((size_t)tekuci)<<endl;
cout<<"Sifra racunala: "<<tekuci->sifra<<endl;
cout<<"Naziv racunala: "<<tekuci->naziv<<endl;
cout<<"Naziv proizvodaca: "<<tekuci->naziv<<endl;
cout<<"Godina proizvodnje: "<<tekuci->godina<<endl;
cout<<"Vrijeme potrebno za unos: "<<tekuci->vrijeme<<endl;
cout<<"Adresa sljedeceg: "<<((size_t)tekuci->sljedeci)<<endl;
cout<<"Adresa prethodnog: "<<((size_t)tekuci->sljedeci)<<endl;
cout<<"----------------------"<<endl;
tekuci=tekuci->sljedeci;
}

trac *novi,*sljedeci;
sljedeci=lista->sljedeci;
novi=new trac;
novi->prethodni=lista;
novi->sljedeci=sljedeci;
lista->sljedeci=novi;
sljedeci->prethodni=novi;
cout<<"-----------UNOS NA PCOETAK-----------"<<endl;
vrijeme_pocetak();
cout<<"Sifra racunala: "<<endl;
cin>>novi->sifra;
cout<<"Naziv racunala: "<<endl;
unos(novi->naziv);
cout<<"Naziv proizvodaca: "<<endl;
unos(novi->proizvodac);
cout<<"godina proizvodnje: "<<endl;
cin>>novi->godina;
vrijeme_kraj();
novi->vrijeme = vrijeme_proteklo();

};

void brisi(trac*lista,int sifra){TEST(6);

trac*brisi=lista->sljedeci,*prethodni=lista,*sljedeci=lista;
char izbor;
while(brisi)
{TEST(7);
if(brisi->sifra==sifra)
{TEST(8);
cout<<"Pronadeni element:"<<endl;
cout<<"Sifra:"<<brisi->sifra<<endl;
cout<<"Naziv racunala: "<<brisi->naziv<<endl;
cout<<"Naziv proizvodaca: "<<brisi->proizvodac<<endl;
cout<<"Godina proizvodnje: "<<brisi->godina<<endl;
cout<<"Vrijeme potretbo za unos:"<<brisi->vrijeme<<endl;
cout<<"----------------------------"<<endl;
cout<<"Za brisanje upisite D a za nastavak N"<<endl;
cin>> izbor;
TEST(9); switch(izbor){
case 'D':
prethodni->sljedeci=brisi->sljedeci;
sljedeci->prethodni=brisi->prethodni;
delete brisi;
return;

case 'N':
return;
}
}
prethodni=brisi;
brisi=brisi->sljedeci;
}
cout<<"----------------ELEMENT NIJE PRONADJEN----------------"<<endl;
}

int main(){TEST(10);

int izbor;
int sifra;
trac*lista =new trac;
lista->sljedeci=NULL;
lista->prethodni=NULL;
do{TEST(11);
cout<<"--------------------"<<endl;
cout<<"1.dodavanje elementa na kraj dvostruko vezane liste"<<endl;
cout<<"2.Dodavanje elementa na pocetak dvostruko vezane liste"<<endl;
cout<<"3.Birsanje elementa dvostrukovezane liste"<<endl;
cout<<"4.binarno stablo"<<endl;
cout<<"9.Izlaz iz programa"<<endl;
cin>>izbor;
TEST(12); switch(izbor){
case 1: kraj(lista);break;
case 2: pocetak(lista);break;
case 3: cout<<"Unesite sifru koju zelite obristai"<<endl;
cin>>sifra;
brisi(lista,sifra);
break;
}
}while(izbor!=9);

  system("PAUSE");
}
     
    // Postoci testiranja:  100% 100%// H1:1134521003332443003332004131200133010134014446423040100213000253444312020001001000000000010000// H2:6666787007767777567876606566656856030076776688657040200650000477768777065001001100000000000000// H3:000000000000000000000!B00A00000000!00D0000000000!00B00000aa0000000000000B000000000000000000000// H4:000000000000000000000000000DJ000EC00B000000000C0000000000000000000000EC00000000000000000000000
