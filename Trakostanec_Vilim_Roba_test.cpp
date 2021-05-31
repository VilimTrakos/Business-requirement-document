// MD5:T9TXMuwcHzJEpRZ0of5anQ==// Verifikator 5.02// Program:Roba// Opis zadatka:Vezana lista- roba// Autor:Vilim Trako�tanec// Po�etno vrijeme:26.3.2021. 13:57:03// Zavr�no vrijeme:26.3.2021. 15:25:07// Identifikatori:zbroj_kljuceva,troba,sifra,naziv[30],skladiste,cijena,vrijeme,main,*sljedeci,izbor,*lista,lista,kraj_liste,*novi,*zadnji,zadnji,broj_elemenata,ispis,*tekuci,pretr,brisi,*brisi,najveci// IP:fe80::bcf2:1454:adf8:2959%2 ( 4233 )// #:#include <ctime>[B],#include <iostream>[B],#include"biblioteka_vrijeme.cc",#include<iostream>,#include<cmath>,#include<ctime>,// Uspje�nih/neuspje�nih prevo�enja:48/26#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void TEST(int i){fstream dat;dat.clear(); 
  static int p[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  static int suma=0;static int zag=0;static int zaglavlje=0;static int br=0;p[i]++;suma++;int f,s=0;char c;
  for (f=0;f<60;f++)s=s+p[f];if (s!=suma){cout<<"Neispravna suma brojaca. Poziv: TEST("<<i<<")"<<endl;cin>>c;return;} 
  zag=(int)time(0);if (zag==zaglavlje){br++;if ((br>1)&&(p[i]>1))return;} else br=0;zaglavlje = (int)time(0);
  dat.open("testiranje.txt",ios::out);
  dat << zaglavlje << endl <<"Rezultati testiranja (test N = 13):" << endl; 
  for (f=0;f<60;f++){if (p[f]>0) dat << f << char(58) << p[f] << endl;} 
  dat.close();dat.clear(); 
}; 
 #include<iostream>
#include<cmath>
#include<ctime>
#include"biblioteka_vrijeme.cc"
using namespace std;
int broj_elemenata=0;

struct troba{
int sifra;
char naziv[30];
int skladiste;
float cijena;
int vrijeme=0;
troba *sljedeci;
};

void kraj_liste(troba*lista)
{TEST(1); 
  
  
  
  troba *novi,*zadnji;
  zadnji = lista;
  
  while(zadnji->sljedeci)
  {TEST(2);
    zadnji=zadnji->sljedeci;
  }
  
  
    novi=new troba;
    zadnji->sljedeci=novi;
    novi->sljedeci=NULL;
    vrijeme_pocetak();
    cout<<"Sifra robe: "<<endl;
    cin>>novi->sifra;
    cout<<"Naziv robe: "<<endl;
    unos(novi->naziv);
    cout<<"Broj skladista: "<<endl;
    cin>>novi->skladiste;
    cout<<"Cijena robe:"<<endl;
    cin>>novi->cijena;
    vrijeme_kraj();
    novi->vrijeme =vrijeme_proteklo()/1000;
    broj_elemenata++;
    
  
};

void ispis(troba*lista)
{TEST(3);
troba *tekuci =lista->sljedeci;
cout<<"ISPIS"<<endl;

while(tekuci)
{TEST(4);
cout<<"Adresa elementa"<<int((size_t)tekuci)<<endl;
cout<<"Sifra robe:"<<tekuci->sifra<<endl;
cout<<"Naziv robe:"<<tekuci->naziv<<endl;
cout<<"Broj skladista:"<<tekuci->skladiste<<endl;
cout<<"Cijena robe:"<<tekuci->cijena<<endl;
cout<<"Vrijeme potrebno za unos:"<<tekuci->vrijeme<<"sekundi"<<endl;
cout<<"Adresa sljedeceg elementa:"<<int((size_t)tekuci->sljedeci)<<endl;
cout<<"------------------------"<<endl;
tekuci =tekuci->sljedeci;
}
};

void pretr(troba*lista,int sifra)
{TEST(5);
troba*tekuci=lista->sljedeci;
cout<<"PRETRAZIVANJE:"<<endl;
while(tekuci)
{TEST(6);
if(tekuci->sifra == sifra)
{TEST(7);
cout<<"Adresa elementa"<<int((size_t)tekuci)<<endl;
cout<<"Sifra robe:"<<tekuci->sifra<<endl;
cout<<"Naziv robe:"<<tekuci->naziv<<endl;
cout<<"Broj skladista:"<<tekuci->skladiste<<endl;
cout<<"Cijena robe:"<<tekuci->cijena<<endl;
cout<<"Vrijeme potrebno za unos:"<<tekuci->vrijeme<<endl;
cout<<"Adresa sljedeceg elementa"<<int((size_t)tekuci->sljedeci)<<endl;
cout<<"------------------------"<<endl;
return;
}
tekuci=tekuci->sljedeci;
}
cout<<"Element nije pronaden!"<<endl;
};

void brisi(troba*lista, int sifra){TEST(8);

troba*brisi=lista->sljedeci,*prethodni=lista;
cout<<"BRISANJE"<<endl;
while(brisi)
{TEST(9);
if(brisi->sifra==sifra)
{TEST(10);
prethodni->sljedeci=brisi->sljedeci;
delete brisi;
cout<<"Element je izbrisan iz vezane liste"<<endl;
return;
}
prethodni =brisi;
brisi= brisi->sljedeci;
}
cout<<"Element za brisanje nije prona�en!"<<endl;
};

int main(){TEST(11);

int izbor, sifra;
troba *lista =new troba;
lista->sljedeci=NULL;

do{TEST(12);

cout<<"Odaberite program koji zelite izvrsiti:"<<endl;
cout<<"1.Unos novog elementa vezane liste(samo jedan na kraj liste)"<<endl;
cout<<"2.Ispis sadr�aja vezane liste zajedno s ukupnom vrijednosti robe"<<endl;
cout<<"3.Pretra�ivanje vezane liste(prema nazivu robe)"<<endl;
cout<<"4.Delokacija cijele liste(glava ostaje)"<<endl;
cout<<"9.Izlaz iz programa"<<endl;
cout<<"---------------"<<endl;
cin>>izbor;
cout<<"---------------"<<endl;

TEST(13); switch(izbor)
{
case 1:kraj_liste(lista);break;
case 2:ispis(lista);break;
case 3:cout<<"Unesite sifru za pretragu"<<endl;
cin>>sifra;break;
pretr(lista,sifra);break;
case 4:cout<<"Uensite sifru za brisanje"<<endl;
cin>>sifra;break;
brisi(lista,sifra);break;
case 9: break;
default:
cout<<"Pogresan unos!"<<endl;break;
}

}while(izbor!=9);

  system("PAUSE");
}  // Postoci testiranja:  0% 33% 46%// H1:6323204344344411032320341041500032413513334120101221342220000001333340126453416405031433000// H2:7666015777667660567734660064660065676477777670567675776140000001036554665466645104063750000// H3:000000000000000000000000000000000000000000000000000000000!00000B00AaC0000000000L0000g00A000// H4:000000B0000000000000000000C000000000000000000DG0B0000000B0000000000000000000000000000000000
