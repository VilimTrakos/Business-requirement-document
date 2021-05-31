// MD5:eHOWMJrR9ARr1eedz6WD1A==// Verifikator 5.05// Program:Vjezba8// Opis zadatka:vj8// Autor:Vilim Trakoštanec// Poèetno vrijeme:14.5.2021. 13:59:31// Završno vrijeme:14.5.2021. 15:10:49// Identifikatori:ctrokut,b_trokuta,id_trokuta,a,b,c,main,s,povrsina,izbor,unos,*pok,ispis,i,else,*polje,broj_elemenata// IP:fe80::bcf2:1454:adf8:2959%2 ( 4233 )// #:#include <ctime>[B],#include <iostream>,#include <cmath>,#include "cvrijeme.cc",// Uspješnih/neuspješnih prevoðenja:26/22#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int br_reda[]={0,17,23,34,50,57,65,66,71,78,83}; 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=1;f<=10;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: TEST("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if ((br>1)&&(p[i]>1))return;} else br=0;zaglavlje = (int)time(0);
  dat.open("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 10):" << endl; 
  for (f=1;f<=10;f++){dat << f << char(91) << br_reda[f] << char(93) << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include <iostream>
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
float povrsina(){TEST(1);
if(sqrt(s*(s-a)*(s-b)*(s-c))<0)
  return -1;
return sqrt(s*(s-a)*(s-b)*(s-c));
};

void unos(){TEST(2);

cout<<"---------Unos------------"<<endl;
cout<<"Unesite podatke o trokutu:"<<endl;
cout<<"Sifra trokuta: ";cin>>id_trokuta;
cout<<"Duljina stranice a: ";cin>>a;
cout<<"Duljina stranice b: ";cin>>b;
cout<<"Duljina stranice c: ";cin>>c;
s=(a+b+c)/2;
};

void ispis(){TEST(3);
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

int main(){TEST(4);



ctrokut::b_trokuta=0;
int broj_elemenata;
int izbor,i;
do{TEST(5);
cout<<"--------------------------"<<endl;
cout<<"1.Dinamièka alokacija objekta i unos podataka o trokutu"<<endl;
cout<<"2.Ispis podataka o unesenom trokutu"<<endl;
cout<<"3.Dinamièka alokacija polja trokuta i unos podataka o pojedninom trokutu u polje"<<endl;
cout<<"4.Ispis podataka iz polja o trokutima"<<endl;
cout<<"9. izlaz"<<endl;
cin>>izbor;
TEST(6); switch(izbor){
case 1: if(pok==NULL){TEST(7);
cout<<"Alociram ne postojeci objekt..."<<endl;
pok=new ctrokut;
}
else 
{TEST(8);
cout<<"Objekt postoji slijedi unos:"<<endl;
pok->unos();break;
}break;

case 2: pok->ispis();break;

case 3: if(polje==0){TEST(9);
cout<<"Treba alocirati velicinu polja!"<<endl<<"Unesite broj elemenata polja:"<<endl;
cin>>broj_elemenata;
polje = new ctrokut[broj_elemenata];
}
else {TEST(10);
polje[ctrokut::b_trokuta].unos();ctrokut::b_trokuta++;break;
}
case 4:
for(i=0;i<ctrokut::b_trokuta;i++)polje[i].ispis();break;
}
}while(izbor!=9);
  system("PAUSE");
}
    // Postoci testiranja:  100% 100%// H1:344305253304144341332506442006334453000005531035231202512010000056010011// H2:776547656705076657677506765007658650001006570067533600766010000003010003// H3:000100000000000010000000000000010000000000000000000000000000000000000000// H4:000000000000000000000000000000000000000000000000000000000000000000000000
