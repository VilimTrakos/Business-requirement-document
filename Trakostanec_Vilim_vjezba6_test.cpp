// MD5:RLd3EXNniipMoceEQy26KQ==// Verifikator 5.05// Program:vjezba6// Opis zadatka:vj6// Autor:Vilim Trakoštanec// Poèetno vrijeme:30.4.2021. 14:00:00// Završno vrijeme:30.4.2021. 15:31:28// Identifikatori:tinv,sifra,naziv,vrijednost,godina,main,rb_zapisa,indeks,adresa,dat,ind,izbor,kreiranje,tindeks,unos,slog,brojac_zap,dat.close,brojac_zapisa,odabir,naziv[20],*,indeks.sifra,ind.write,while,odabir[3],radi,pretrazi,nadjeno,brojac,dat.open,cout<<brojac_zapisa<<endl,ind.open// IP:fe80::bcf2:1454:adf8:2959%2 ( 4233 )// #:#include <ctime>[B],#include <iostream>[B],#include<fstream>,#include<string.h>,#include"biblioteka_vrijeme.cc",#include<iomanip>,#include <cstdlib>,// Uspješnih/neuspješnih prevoðenja:66/28#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int br_reda[]={0,23,28,37,40,56,70,91,100,104,124,126,133}; 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=1;f<=12;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: TEST("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if ((br>1)&&(p[i]>1))return;} else br=0;zaglavlje = (int)time(0);
  dat.open("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 12):" << endl; 
  for (f=1;f<=12;f++){dat << f << char(91) << br_reda[f] << char(93) << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include <iostream>
#include<fstream>
#include<string.h>
#include"biblioteka_vrijeme.cc"
#include<iomanip>
#include <cstdlib>
using namespace std;

struct tinv{
int rb_zapisa;
int sifra;
char naziv[20];
float vrijednost;
int godina;
};

struct tindeks{
int sifra;
int adresa;
};

fstream dat,ind;
void kreiranje(){TEST(1);
int izbor;
dat.open("inventar.dat",ios::in|ios::binary);
ind.open("indeks.ind",ios::in|ios::binary);

if(!dat || !ind){TEST(2);
dat.open("inventar.dat",ios::out|ios::binary);
ind.open("indeks.ind",ios::out|ios::binary);
cout<<"Datoteke nisu postojale te su kreirane."<<endl;
dat.close();dat.clear();
ind.close();ind.clear();
return;
}

if(dat && ind){TEST(3);
cout<<"Na disku postoje datoteke, ako ih želite izbrisati i kreirati nove upisite 1, a ako ne upisite 2"<<endl;
cin>>izbor;
TEST(4); switch(izbor)
{
case 1:
dat.open("inventar.dat",ios::out);
ind.open("indeks.ind",ios::out);
dat.close();dat.clear();
ind.close();ind.clear();
cout<<"Datoteke su izbrisane i kreirane."<<endl;
break;
case 2:
return;
}
}
}


void unos(){TEST(5);
tinv slog;
tindeks indeks;
int brojac_zapisa=0;



cout<<brojac_zapisa<<endl;
dat.open("inventar.dat",ios::out|ios::in|ios::ate|ios::binary);
dat.seekg(0,ios::end);
brojac_zapisa=dat.tellg()/sizeof(tinv);
ind.open("indeks.ind",ios::out|ios::in|ios::ate|ios::binary);

int odabir;
do{TEST(6);
brojac_zapisa++;
cout<<"Zapis br. "<<brojac_zapisa<<endl;
slog.rb_zapisa=brojac_zapisa;
cout<<"Sifra: ";cin>>slog.sifra;
cout<<"Naziv inventara: ";unos(slog.naziv);
cout<<"Vrijednost komada: ";cin>>slog.vrijednost;
cout<<"Godina proizvodnje: ";cin>>slog.godina;
cout<<"------------------------"<<endl;
cout<<"Za daljnji unos unesite '1',a za izlaz '0'"<<endl;
cin>>odabir;

dat.write((char *)&slog,sizeof(tinv));
indeks.sifra=slog.sifra;
indeks.adresa=(int)dat.tellp()-sizeof(tinv);
ind.write((char *)&indeks,sizeof(tindeks));
dat.close();dat.clear();
ind.close();ind.clear();
}while(odabir==1);
}

void pretrazi(int sifra){TEST(7);

tinv slog;
tindeks indeks;
bool nadjeno=false;
int brojac=0;
dat.open("inventar.dat",ios::in|ios::binary);
ind.open("indeks.ind",ios::in|ios::binary);

while(1){TEST(8);
ind.read((char *)&indeks,sizeof(tindeks));
brojac++;
if(dat.eof())break;
if(indeks.sifra==sifra){TEST(9);
dat.seekg(indeks.adresa);
dat.read((char *)&slog,sizeof(tinv));
nadjeno =true;
cout<<"Adresa"<<indeks.adresa<<endl;
cout<<"Zapis br."<<slog.rb_zapisa<<endl;
cout<<"Sifra: "<<slog.sifra<<endl;
cout<<"Naziv: "<<slog.naziv<<endl;
cout<<"Vrijednost komada: "<<slog.vrijednost<<endl;
cout<<"Godina proizvodnje: "<<slog.godina<<endl;
break;
}
}
dat.close();dat.clear();
ind.close();ind.clear();
if(!nadjeno) cout<<"Zapis nije pronadjen!"<<endl;

}


int main(){TEST(10);
int izbor,sifra;
do{TEST(11);
cout<<"-------------------------------"<<endl;
cout<<"1. Kreiranje datoteke"<<endl;
cout<<"2. Unos u datoteku(rucno)"<<endl;
cout<<"3.pretrezivanje"<<endl;
cout<<"9. Izlaz"<<endl;
cin>>izbor;
TEST(12); switch(izbor){
case 1: kreiranje();break;
case 2: unos();break;
case 3: cout<<"Unesite sifru koju trazite"<<endl;
cin>>sifra;
pretrazi(sifra);
break;
}

}while(izbor!=9);

  system("PAUSE");
}
  
  
    // Postoci testiranja:  100% 100%// H1:264443430522554444343311021342400334314443000312023411633434343414234310002200123100600312400// H2:666776662660558577673300357506710676666777100464077635621653476777267660030100016000500215600// H3:000000000000000000000000000000000000100000000100000000000000000000000000000001000000000000200// H4:000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100
