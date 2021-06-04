// MD5:o12wFSprkf3gs/Io/LSSfw==// Verifikator 5.05// Program:Vjezba10// Opis zadatka:vj10// Autor:Vilim Trakoštanec// Poèetno vrijeme:4.6.2021. 13:59:10// Završno vrijeme:4.6.2021. 15:24:35// Identifikatori:main,cvrsta_zapis,sifra,naziv[20],tip[20],unos,izbor,ispis,cvrsta,*sljedeci,*zapis,sljedeci,int,void,*novi,*zadnji,zadnji,croba_zapis,redni,sifra_vrste,croba,zapis,*lista_robe,do,odabir,*tekuci,*lista_vrsta,lista_vrsta,kljuc,provjera,pretrazi// IP:fe80::bcf2:1454:adf8:2959%2 ( 4233 )// #:#include <iostream>,#include <cstring>,// Uspješnih/neuspješnih prevoðenja:46/26#include <iostream>
#include <cstring>

using namespace std;

class croba_zapis{
public:
int redni;
int sifra_vrste;
char naziv[20];

void unos(){
cout<<"redni broj:";cin>>redni;
cout<<"Sifra vrste:";cin>>sifra_vrste;
cout<<"Naziv robe:";cin>>naziv;
}
void ispis(){
cout<<"Redni broj:"<<redni<<endl;
cout<<"Sifra: "<<sifra_vrste<<endl;
cout<<"Naziv: "<<naziv<<endl;
}

int kljuc(){

return sifra_vrste;
}

};

class croba{
public:
croba *sljedeci;

croba_zapis zapis;
croba (){sljedeci = NULL; cout<<"Alociram croba"<<endl;}

void unos(){
croba *novi, *zadnji;
zadnji =this;
while(zadnji->sljedeci)
	zadnji = zadnji->sljedeci;
novi = new croba;
zadnji->sljedeci =novi;
novi->zapis.unos();
}

void ispis(){
croba *tekuci =this->sljedeci;
while(tekuci){
tekuci->zapis.ispis();
cout<<"Pokazivac: "<<int((size_t)tekuci->sljedeci)<<endl;
cout<<"-------------------"<<endl;
tekuci=tekuci->sljedeci;
}
cout<<zapis.kljuc();
}

bool provjera(int sifra){
croba *tekuci=this->sljedeci;
while(tekuci){
if(tekuci->zapis.sifra_vrste == sifra)
return true;
tekuci=tekuci->sljedeci;
}
return false;
}

void pretrazi(int sifra){
cout<<sifra<<endl;
croba*tekuci=this->sljedeci;
while(tekuci){
if(sifra==tekuci->zapis.sifra_vrste){
tekuci->zapis.ispis();
cout<<"---------------------"<<endl;
}
else cout<<"Nema tog zapisa"<<endl;
tekuci=tekuci->sljedeci;
}
}



};
croba*lista_robe;


class cvrsta_zapis{
public:
int sifra;
char naziv[20];
char tip[20];

void unos(){
cout<<"Sifra vrste:";cin>>sifra;
cout<<"naziv vrste:";cin>>naziv;
cout<<"Tip vrste:";cin>>tip;
}
void ispis(){
cout<<"-----------------Vrste--------"<<endl;
cout<<"Sifra vrste:"<<sifra<<endl;
cout<<"Naziv vrste:"<<naziv<<endl;
cout<<"Tip vrste:"<<tip<<endl;
}
int kljuc(){
cout<<"Ovo je kljuc cvrsta_zapis"<<endl;
return sifra;
}

};

class cvrsta{
public:
cvrsta *sljedeci;

cvrsta_zapis *zapis;

cvrsta(){
sljedeci =NULL;
cout<<"Alociram crvsta"<<endl;
zapis = new cvrsta_zapis;
}
void unos(){
cvrsta *novi,*zadnji;
zadnji=this;
while(zadnji->sljedeci)
	zadnji=zadnji->sljedeci;
novi = new cvrsta;
zadnji->sljedeci =novi;
novi->zapis->unos();

if(!lista_robe->provjera(novi->zapis->kljuc())){
cout<<"Ne postoji takav predmet u listi!"<<endl;
zadnji->sljedeci=NULL;
delete novi;
}
}
void ispis(){
cvrsta *tekuci =this->sljedeci;
while(tekuci){
tekuci->zapis->ispis();
cout<<"Pokazivac: "<<int((size_t)tekuci->sljedeci)<<endl;
cout<<"-----------------"<<endl;
tekuci=tekuci->sljedeci;
}
}


void pretrazi(int sifra){
cvrsta *tekuci = this->sljedeci;
while(tekuci){
if(sifra == tekuci->zapis->sifra)
{
tekuci ->zapis->ispis();
cout<<tekuci->sljedeci<<endl;
}
tekuci=tekuci->sljedeci;
}
}


};

cvrsta *lista_vrsta;


int main(){
int izbor,odabir,sifra;

lista_robe = new croba;
lista_vrsta =new cvrsta;
do{
cout<<"-----------------------------------------"<<endl;
cout<<"1.Unos vrsta robe na kraj liste"<<endl;
cout<<"2.Unos robe na kraj odgovarajuæe liste"<<endl;
cout<<"3.Ispis cijele liste vrsta, ispis cijele liste robe"<<endl;
cout<<"4.Popis roba zadane vrste"<<endl;
cin>>izbor;
switch(izbor){
case 1:do{lista_robe->unos();
cout<<"Zelite li jos unositi (da-1, ne -0)"<<endl;
cin>>odabir;
}while(odabir==1);
break;
case 2:
lista_vrsta->unos();
break;

case 3: 
lista_robe->ispis();
cout<<"----------------------------------"<<endl;
lista_vrsta->ispis();
break;

case 4: 
cout<<"Sifra robe:"<<endl; cin>>sifra;
lista_vrsta->pretrazi(sifra);
lista_robe->pretrazi(sifra);

}

}while(izbor!=9);

	system("PAUSE");
	return 0;
}
