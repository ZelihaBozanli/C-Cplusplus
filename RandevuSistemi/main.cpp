#include <iostream> // cout,cin vs. için
#include <conio.h> //getch(); fonksiyonu için
#include <fstream> // dosyalama iþlemleri için
#include <string> // string türü için
#include <windows.h> //komut ekranýna renk vermek için
#include <clocale> // Türkçe karakter için
#include <iomanip> //setw() için eklenen kütüphane
#include <stdio.h>

using namespace std;
class bilgiler{
public:
    string ad;
    string soyad;
    string eposta;
    string telefon;
};
class ogrenci: public bilgiler{
    public:
    string numara;
    string bolum;
    string kayitYili;


};

class akademisyen: public bilgiler{
    public:
    string sicilNumara;
    string anabilim;
    string unvan;
};

class randevu:public ogrenci,akademisyen{
    public:
    string tarih;
    string baslamasaat;
    string bitissaat;

};

int main()
{
    int islem;
    int secim;
    ogrenci o;
    akademisyen a;
    randevu r;
    string ogrNo;
    char cevap;
    do{
 cout<<"1- Ogrenci kayýt ekleme"<<endl; //Menümüz
 cout<<"2- Akademisyen kayit ekleme"<<endl;
 cout<<"3- Ogrenci silme"<<endl;
 cout<<"4- Randevu alma"<<endl;
 cout<<"5- Randevu silme"<<endl;
 cout<<"6- Randevu güncelleme"<<endl;
 cout<<"7- Hasta sorgulama"<<endl;
 cout<<"8- Hasta listesi alma"<<endl;
 cout<<"9- Hasta muayene kaydý"<<endl;
 cout<<"Yapmak istediginiz islemi seciniz:"<<endl;
 cin>>secim;

 switch(secim) //Seçim yapýyoruz
 {
 case 1:
 {

 cout<<"1- Ogrenci kayit ekleme"<<endl; //Menüden numara seçerken önce kayýt ekleme yapýyoruz

 ofstream DosyaYaz;
 DosyaYaz.open("ogrenci.txt",ios::app);
 do
 {
 cout<<"\n No :"; cin>>o.numara;
 cout<<"\n Adi :"; cin>>o.ad;
 cout<<"\n Soyadi :"; cin>>o.soyad;
 cout<<"\n Eposta :"; cin>>o.eposta;
 cout<<"\n Telefon :"; cin>>o.telefon;
 cout<<"\n Bolum :"; cin>>o.bolum;
 cout<<"\n Kayit Yili :"; cin>>o.kayitYili;

 DosyaYaz<<o.numara<<" "<<o.ad<<' '<<o.soyad<<' ' <<o.eposta<<' '<<o.telefon<<' ' <<o.bolum<<' ' <<o.kayitYili<<endl;
 cout<<"\n Baska kayit yapacak misiniz?(e/E) (h/H) ";cin>>cevap;

 }while(cevap=='e' || cevap=='E');

 DosyaYaz.close();
 cout<< "Dosyaya yazim tamamlandi."<<endl;

 break;
 }

  case 2:
 {

 cout<<"2- Akademisyen kayit ekleme"<<endl; //Menüden numara seçerken önce kayýt ekleme yapýyoruz

 ofstream DosyaYaz;
 DosyaYaz.open("akademisyen.txt",ios::app);
 do
 {
 cout<<"\n Sicil No :"; cin>>a.sicilNumara;
 cout<<"\n Adi :"; cin>>a.ad;
 cout<<"\n Soyadi :"; cin>>a.soyad;
 cout<<"\n Eposta :"; cin>>a.eposta;
 cout<<"\n Telefon :"; cin>>a.telefon;
 cout<<"\n Ana Bilim Dali :"; cin>>a.anabilim;
 cout<<"\n Unvan :"; cin>>a.unvan;

 DosyaYaz<<a.sicilNumara<<" "<<a.ad<<' '<<a.soyad<<' ' <<a.eposta<<' '<<a.telefon<<' ' <<a.anabilim<<' ' <<a.unvan<<endl;
 cout<<"\n Baska kayit yapacak misiniz?(e/E) (h/H) ";cin>>cevap;

 }while(cevap=='e' || cevap=='E');

 DosyaYaz.close();
 cout<< "Dosyaya yazim tamamlandi."<<endl;

 break;
 }
/*case 2:
 {
 cout<<"2- Ogrenci kaydý düzeltme"<<endl;
 ifstream DosyaOku;
 DosyaOku.open("ogrenci.txt",ios::app);
 cout<< "\n Ogrenci Bilgileri \n";
 cout<<"Ogrenci no :";
 cin>>ogrNo;
 if(o.numara==ogrNo)
 {
 DosyaOku.close();
 ofstream DosyaYaz;
 DosyaYaz.open("ogrenci.txt",ios::app);
 cout<<"\n Adi :"; cin>>o.ad;
 cout<<"\n Soyadi :"; cin>>o.soyad;
 cout<<"\n Eposta :"; cin>>o.eposta;
 cout<<"\n Telefonu :"; cin>>o.telefon;
 cout<<"\n Kayit Yili :"; cin>>o.kayitYili;

 DosyaYaz.close();
 }
 else
 cout<<"Kimlik Numarasý bulunamadý"<<endl;
 break;
 }*/
 /*
 case 3:
 {
 cout<<"3- Hasta silme"<<endl;
 ifstream DosyaOku;
 DosyaOku.open("Hasta.txt");
 cout<<"TC no:";
 cin>>TcNo;
 if(TC==TcNo)
 {
 remove("Hasta.txt");
 }
 break;
 }*/
 case 4:

 {
 cout<<"4- Randevu alma"<<endl;

 cout<<" Ogrenci No :";cin>>o.numara;

 ifstream DosyaOku("ogrenci.txt");
 while(!DosyaOku.eof())
 {
 DosyaOku>>o.numara>>o.ad>>o.soyad>>o.eposta>>o.telefon>>o.kayitYili;
 cout<<endl;
 if(o.numara==ogrNo)
 {
 cout<< "\n Ogrenci Bilgileri \n";
 cout<<" no :"<<ogrNo<<endl;
 cout<<"Adi :"<<o.ad<<endl;
 cout<<"Soyadi :"<<o.soyad<<endl;
 cout<<"Eposta :"<<o.eposta<<endl;
 cout<<"Telefonu :"<<o.telefon<<endl;
 cout<<"Kayit Yili:"<<o.kayitYili<<endl;
 cout<<"Randevu istiyor mu? (e/h)"<<endl;
 cin>>cevap;

 if (cevap=='e'|| cevap=='E')
 {
 DosyaOku.close();
 ofstream DosyaYaz;
 DosyaYaz.open("randevu.txt",ios::app);

 cout<<"\n Randevu Bilgileri \n";
 cout<<"\n Akademisyen Adi :"; cin>>r.ad;
 cout<<"\n Tarih :"; cin>>r.tarih;
 cout<<"\n Baslama Saati :"; cin>>r.baslamasaat;
 cout<<"\n Bitis Saati :"; cin>>r.bitissaat;

 DosyaYaz <<ogrNo<<" "<<r.ad<<' '<<r.tarih<<' ' <<r.baslamasaat<<' '<r.bitissaat<<"\n";
 DosyaYaz.close();
 }
 }
 }
 break;
 }

 /*case 5:
 {
 cout<<"5- Randevu silme"<<endl;
 break;
 }*/
 /*
 case 6:
 {
 cout<<"6- Randevu güncelleme"<<endl;


 ifstream DosyaOku("Hasta.txt",ios::in);
 cout<<"TC no:";
 cin>>TcNo;
 if(TC==TcNo)
 {
 cout<< "\n Hasta Bilgileri \n";
 cout<<"TC no :"<<TcNo<<endl;
 cout<<"Adý :"<<HastaAdi<<endl;
 cout<<"Soyadý :"<<HastaSoyadi<<endl;
 cout<<"Yaþý :"<<HastaYas<<endl;
 cout<<"Telefonu :"<<Telefon<<endl;
 cout<<"Cinsiyeti:"<<HastaCinsiyet<<endl;

 ofstream DosyaYaz;
 DosyaYaz.open("Muayene.txt",ios::app);
 {
 cout<<"\n Randevu Bilgileri \n";
 cout<<"\n Tarih :"; cin>>Tarih;
 cout<<"\n Doktor Adi :"; cin>>DoktorAdi;
 cout<<"\n Teshis :"; cin>>Teshis;
 cout<<"\n Muayene Ucreti :"; cin>>Ucret;

 DosyaYaz.close();
 ofstream DosyaYaz;
 }
 DosyaOku.close();
 ifstream DosyaOku;

 }
 else
 cout<<"Böyle bir kiþi bulunmamaktadýr.";

 break;
 }*/
 /*
 case 7:
 {
 cout<<"7- Hasta sorgulama"<<endl;

 cout<<" Hasta TC :";cin>>TC;
 ifstream DosyaOku("Hasta.txt");
 while(!DosyaOku.eof())
 {
 DosyaOku>>TcNo>>HastaAdi>>HastaSoyadi>>HastaYas>>Telefon>>HastaCinsiyet;
 if(TC==TcNo)
 {
 cout<< "\n Hasta Bilgileri \n";
 cout<<"TC no :"<<TcNo<<endl;
 cout<<"Adý :"<<HastaAdi<<endl;
 cout<<"Soyadý :"<<HastaSoyadi<<endl;
 cout<<"Yaþý :"<<HastaYas<<endl;
 cout<<"Telefonu :"<<Telefon<<endl;
 cout<<"Cinsiyeti:"<<HastaCinsiyet<<endl;
 TC=TcNo;

 DosyaOku.close();
 ofstream DosyaYaz;
 DosyaOku.open("Muayene.txt",ios::in);
 cout<<" randevu bilgileri \n"<<endl; cout<<setw(11)<<" TC "<<setw(10)<<" Tarih "<<setw(12)<<" Doktor Adi "<<setw(10)<<" Teshis "<<setw(6)<<" Ucret"<<endl;
 while(!DosyaOku.eof())
 {

 DosyaOku>>TcNo>>Tarih>>DoktorAdi>>Teshis>>Ucret;

 if(TC==TcNo)
 {
 cout<<setw(11)<< TcNo<<setw(10)<<Tarih<<setw(12)<< DoktorAdi<<setw(10)<< Teshis<<setw(6)<< Ucret<<endl;
 }
 }
 DosyaYaz.close();


 }
 }


 break;
 }*/
 /*
 case 8:
 {
 cout<<"8- Hasta listesi alma"<<endl;
 ifstream DosyaOku;
 DosyaOku.open("Hasta.txt",ios::in);

 while(!DosyaOku.eof())
 {
 DosyaOku>>TcNo>>HastaAdi>>HastaSoyadi>>HastaYas>>Telefon>>HastaCinsiyet;
 cout<<"\n Hasta Bilgileri \n";
 cout<<"TC no :"<<TcNo<<endl;
 cout<<"Adý :"<<HastaAdi<<endl;
 cout<<"Soyadý :"<<HastaSoyadi<<endl;
 cout<<"Yaþý :"<<HastaYas<<endl;
 cout<<"Telefonu :"<<Telefon<<endl;
 cout<<"Cinsiyeti:"<<HastaCinsiyet<<endl;

 DosyaOku.close();
 }
 break;
 }*/
 /*

 case 9:
 {
 cout<<"9- Hasta muayene kaydý"<<endl;
 ifstream DosyaOku;
 DosyaOku.open("Hasta.txt",ios::in);


 {

 do{
 if(DosyaOku.eof()) break;
 else
 DosyaOku>>TcNo>>DoktorAdi>>Teshis>>Tahliller>>Ilac;
 cout<<"\n Hasta Bilgileri \n";
 cout<<"\n Doktor Adý :"<<DoktorAdi;
 cout<<"\n Teþhis:"<<Teshis;
 cout<<"\n Tahlil Bilgileri :"<<Tahliller;
 cout<<"\n Ýlaç :"<<Ilac;
 }while(true);


 do{
 if(DosyaOku.eof()) break;

 else

 DosyaOku>>TcNo>>HastaAdi>>HastaSoyadi>>HastaYas>>Telefon>>HastaCinsiyet;
 cout<<"\n Hasta Bilgileri \n";
 cout<<"TC no :"<<TcNo<<endl;
 cout<<"Adý :"<<HastaAdi<<endl;
 cout<<"Soyadý :"<<HastaSoyadi<<endl;
 cout<<"Yaþý :"<<HastaYas<<endl;
 cout<<"Telefonu :"<<Telefon<<endl;
 cout<<"Cinsiyeti:"<<HastaCinsiyet<<endl;

 }while(true);


 ofstream DosyaYaz;
 DosyaYaz.open("Randevu.txt",ios::app);
 DosyaYaz.close();
 }
 DosyaOku.close();

 break;
 }*/
 }


 cout<<"Ýslem yapmaya devam etmek istiyor musunuz? (e/E) (h/H)";
 cin>>islem;
 }while(islem=='e' || islem=='E'); //Ýþlemi yaptýktan sonra karþýmýza tekrar menü
 cout<<endl; //çýkmasýný saðlýyor
 getch();

 }

