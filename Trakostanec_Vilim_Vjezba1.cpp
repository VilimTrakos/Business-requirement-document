// MD5:cfDiV+EZUNRVhmXHGR7fyA==// Verifikator 5.01// Program:Vjezba1// Opis zadatka:Vjezba 1 svi zadaci// Autor:Vilim Trakoštanec// Poèetno vrijeme:19.3.2021. 13:58:03// Završno vrijeme:19.3.2021. 15:12:26// Identifikatori:main,odabir,polje,*,suma,i,funkcija,a,b,povtr,pov,stra,strb,taparat,sifra,naziv,godina,struktura,aparat,pomvar,naziv[10],cout<<"Vas,mjerenje,c,s,razlika,naziv[13]// IP:fe80::bcf2:1454:adf8:2959%2 ( 4233 )// #:#include <ctime>[B],#include <iostream>[B],#include<cstring>,#include<cmath>,#include"biblioteka_vrijeme.cc",#include<ctime>,#include<cstdlib>,#include<iomanip>,// Uspješnih/neuspješnih prevoðenja:50/29#include <iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include"biblioteka_vrijeme.cc"
#include<ctime>
#include<iomanip>
using namespace std;



void polje(){
	float suma;
	float* polje=new float[4]{3.56,7.17,5.12,4.21};
	for(int i=0;i<4;i++)
	{
		cout<<polje[i]<<endl;
		suma+=polje[i];
	}	
	cout<<"Zbroj clanova polja je:"<<suma<<endl;
	
}

float pov(float stra, float strb)
{
	float pov;
	pov=(stra*strb)/2;
	return pov;
	
}

void funkcija(){

	float a=0,b=0;

	cout<<"Unesite vrijednost stranice a"<<endl;
	cin>>a;
	cout<<"Unesite vrijednost stranice b"<<endl;
	cin>>b;
	if(a<0)
		a=-a;
		if(b<0)
		b=-b;
	cout<<"povrsina trokuta je: "<<pov(a,b)<<endl;

}



struct taparat{
	
	int sifra;
	char naziv[13];
	int godina;

};
void struktura()
{
		taparat aparat,pomvar;
		aparat.sifra=1271;
		strcpy(aparat.naziv, "Hladnjak_xwo");
		aparat.godina=2018;
		
		memcpy(&pomvar,&aparat,sizeof(taparat));
		cout<<"Vas aparat:"<<endl<<endl;
		
		cout<<"Sifra:    "<<pomvar.sifra<<endl
		<<"Naziv:    "<<pomvar.naziv<<endl
		<<"Godina proizvodnje:     "<<pomvar.godina<<endl<<endl;
		
}



void mjerenje(){
	

	float a,b,c;
	float s,pov;
	
	do{
		cout<<"Unesite duzine stranica trokuta:"<<endl;
		vrijeme_pocetak();
		cin>>a>>b>>c;
		vrijeme_kraj();
		s=(a+b+c)/2;
		
	}while(a<0 || b<0 ||c<0 ||a>s ||b>s||c>s);
	
	cout<<"Trebalo vam je: "<<vrijeme_proteklo()<<"tisucinki sekunde" <<endl;	
	
	pov=sqrt(s*(s-a)*(s-b)*(s-c));
	
	cout<<"Povrsina vaseg trokuta je: "<<setprecision(2)<<pov<<endl;

}




int main(){

	int odabir;
	do{
	cout<<endl;
	cout<<"Odaberite program:"<<endl;
	cout<<"1.Polje"<<endl
	<<"2.Funkcija"<<endl
	<<"3.Struktura"<<endl
	<<"4.Mjerenje vremena"<<endl
	<<"9.Izlaz iz programa"<<endl;
	cin>>odabir;
		switch(odabir)
		{
			case 1:polje();break;
			case 2:funkcija();break;
			case 3:struktura();break;
			case 4:mjerenje();break;
			case 9: break;
			
			default:
				cout<<"Pogresan unos"<<endl;
			
		}
	cout<<endl;
	
	}while(odabir!=9);

	system("PAUSE");
	return 0;
}
  
  
  
