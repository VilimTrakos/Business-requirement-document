// MD5:RApdnYz65+bMD781+8KH0Q==// Verifikator 5.04// Program:vjezba5// Opis zadatka:vjezba 5// Autor:Vilim Trakoštanec// Poèetno vrijeme:23.4.2021. 14:01:07// Završno vrijeme:23.4.2021. 15:13:05// Identifikatori:main,izbor,vd,troba,rb_zap,sifra,naziv[20],proizv[20],godina,provjera,prost,j,kreiraj,slog,i,prost_broj,prosti,x,rb_zapisa,dat,*,dat.close,brojac_zapisa,unos,slog2,rbz,adresa,cout<<"Adresa,unosim,while,1,slog.rb_zapisa,do,cout<<"Nova,if// IP:fe80::bcf2:1454:adf8:2959%2 ( 4233 )// #:#include <ctime>[B],#include <iostream>[B],#include <cstdlib>[B],#include<cmath>,#include<fstream>,#include<cstring>,#include"biblioteka_tel_imenik.cc",// Uspješnih/neuspješnih prevoðenja:35/24#include <iostream>
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
int provjera(int vd){
bool prost =true;
for(int j=2; j<=sqrt(vd) && prost;j++)
if(vd%j==0 && vd<100 &&vd>10)return vd;
while(prost)
{
cout<<"Pogrešno unesen broj!"<<endl;
cin>>vd;
for(int j=2; j<=sqrt(vd) && prost;j++)
if(vd%j==0 && vd<100 &&vd>10)prost =false;
}
return vd;
};

int prosti(int x){
int i,j,prost;
for(i=x-1;i>1;i--){
prost=1;
for(j=2;j<=sqrt(i);j++){
if(i%j==0){prost=0;break;}
}
if(prost) return i;
}
return 0;
}


void kreiraj(int vd){

troba slog;
int i;
slog.sifra=0;
slog.naziv[0]='\0';
slog.proizv[0]='\0';
slog.godina=0;
prost_broj = prosti(vd);
cout<<"Prvi manji prosti broj je:"<<prost_broj<<endl;
dat.open("datoteka.dat",ios::out|ios::binary);
for(i=0;i<vd;i++){
slog.rb_zapisa=i;
dat.write((char *)&slog,sizeof(troba));
}
dat.close();dat.clear();
}

int brojac_zapisa;
void unosim()
{
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

while(1){
dat.read((char*)&slog2,sizeof(troba));
if(dat.eof())break;
if(slog2.sifra == slog.sifra)
cout<<"Radi se o duplikatu"<<endl;
}

do{
dat.read((char *)&slog2,sizeof(troba));
}while(slog2.sifra>0);
rbz =(dat.tellg()/sizeof(troba))-1;
dat.seekp(rbz*sizeof(troba));
slog.rb_zapisa=slog2.rb_zapisa;
dat.write((char *)&slog,sizeof(troba));
dat.close();dat.clear();

}

int main(){

int izbor,vd;
do{
cout<<"-----------------------------------------"<<endl;
cout<<"1. kreiranje datoteke s praznim zapisima i racunanje prostog broja"<<endl;
cout<<"2.Unos podataka u datoteku(uvažavajuæi duplikate)"<<endl;
cout<<"9. Izlaz"<<endl;
cin>>izbor;

switch(izbor)
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
}
