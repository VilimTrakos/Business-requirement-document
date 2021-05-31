// MD5:bAgcUjbtF9Wx1Ww2Vn4ung==// Verifikator 5.04// Program:vjezba5// Opis zadatka:vjezba 5// Autor:Vilim Trakoštanec// Poèetno vrijeme:23.4.2021. 14:01:07// Završno vrijeme:23.4.2021. 15:13:09// Identifikatori:main,izbor,vd,troba,rb_zap,sifra,naziv[20],proizv[20],godina,provjera,prost,j,kreiraj,slog,i,prost_broj,prosti,x,rb_zapisa,dat,*,dat.close,brojac_zapisa,unos,slog2,rbz,adresa,cout<<"Adresa,unosim,while,1,slog.rb_zapisa,do,cout<<"Nova,if// IP:fe80::bcf2:1454:adf8:2959%2 ( 4233 )// #:#include <ctime>[B],#include <iostream>[B],#include <cstdlib>[B],#include<cmath>,#include<fstream>,#include<cstring>,#include"biblioteka_tel_imenik.cc",// Uspješnih/neuspješnih prevoðenja:36/24#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int br_reda[]={0,18,23,32,34,36,37,45,56,65,95,106,109,116}; 
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
#include<cmath>
#include<fstream>
#include<cstring>
#include"biblioteka_tel_imenik.cc"
using namespace std;

struct troba{

int rb_zapisa;
int sifra;
char naziv[20];
char proizv[20];
int godina;
};
int prost_broj;
fstream dat;
int provjera(int vd){TEST(1);
bool prost =true;
for(int j=2; j<=sqrt(vd) && prost;j++)
if(vd%j==0 && vd<100 &&vd>10)return vd;
while(prost)
{TEST(2);
cout<<"Pogrešno unesen broj!"<<endl;
cin>>vd;
for(int j=2; j<=sqrt(vd) && prost;j++)
if(vd%j==0 && vd<100 &&vd>10)prost =false;
}
return vd;
};

int prosti(int x){TEST(3);
int i,j,prost;
for(i=x-1;i>1;i--){TEST(4);
prost=1;
for(j=2;j<=sqrt(i);j++){TEST(5);
if(i%j==0){TEST(6);prost=0;break;}
}
if(prost) return i;
}
return 0;
}


void kreiraj(int vd){TEST(7);

troba slog;
int i;
slog.sifra=0;
slog.naziv[0]='\0';
slog.proizv[0]='\0';
slog.godina=0;
prost_broj = prosti(vd);
cout<<"Prvi manji prosti broj je:"<<prost_broj<<endl;
dat.open("datoteka.dat",ios::out|ios::binary);
for(i=0;i<vd;i++){TEST(8);
slog.rb_zapisa=i;
dat.write((char *)&slog,sizeof(troba));
}
dat.close();dat.clear();
}

int brojac_zapisa;
void unosim()
{TEST(9);
dat.open("datoteka.dat",ios::in|ios::binary);

dat.seekg(0,ios::end);
brojac_zapisa=dat.tellg()/sizeof(troba);
dat.close();dat.clear();
dat.open("datoteka.dat",ios::out|ios::app|ios::binary);

troba slog,slog2;
int rbz;
int adresa;
cout<<"Sifra robe:"<<endl;
cin>>slog.sifra;
cout<<"Naziv robe:"<<endl;
unos(slog.naziv);
cout<<"Proizvodac:"<<endl;
unos(slog.proizv);
cout<<"Godina proizvodnje:"<<endl;
cin>>slog.godina;
rbz = slog.sifra%prost_broj;
cout<<"--------------------------------"<<endl;
cout<<"Redni broj zapisa:"<<rbz<<endl;
cout<<"--------------------------------"<<endl;
adresa = rbz*sizeof(troba);
cout<<"Adresa zapisa:"<<adresa<<endl;
cout<<"--------------------------------"<<endl;
dat.open("datoteka.dat",ios::in|ios::out|ios::binary);
dat.seekg(rbz*sizeof(troba));
dat.close();dat.clear();

do{TEST(10);
dat.read((char *)&slog2,sizeof(troba));
}while(slog2.sifra>0);
rbz =(dat.tellg()/sizeof(troba))-1;
dat.seekp(rbz*sizeof(troba));
slog.rb_zapisa=slog2.rb_zapisa;
dat.write((char *)&slog,sizeof(troba));
dat.close();dat.clear();

}

int main(){TEST(11);

int izbor,vd;
do{TEST(12);
cout<<"-----------------------------------------"<<endl;
cout<<"1. kreiranje datoteke s praznim zapisima i racunanje prostog broja"<<endl;
cout<<"2.Unos podataka u datoteku(uvažavajuæi duplikate)"<<endl;
cout<<"9. Izlaz"<<endl;
cin>>izbor;

TEST(13); switch(izbor)
{

case 1:cout<<"Uensite velicinu datoteke u broju zapisa"<<endl;
cin>>vd;
vd = provjera(vd);
kreiraj(vd);
break;
case 2: 
unosim();break;
}

}while(izbor!=9);
  system("PAUSE");
}  // Postoci testiranja:  100% 100% 100%// H1:0343310031534023240323322112340000020224435521100001003431020314310103332// H2:0775570065767525465766746556774403070677667776703500005775070646400006660// H3:000000000000000000!00000000000!B0000000000000000!00B00000D00C000Mic0000Fg// H4:000000000B0000000C00000000A000000000000000000000000000000000000G000000000
