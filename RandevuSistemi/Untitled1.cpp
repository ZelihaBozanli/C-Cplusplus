#include <iostream> // cout,cin vs. için
#include <conio.h> //getch(); fonksiyonu için
#include <fstream> // dosyalama i?lemleri için
#include <string> // string türü için
#include <windows.h> //komut ekranyna renk vermek için
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
    string tarih;
    string ogrNo;
    string no;
    string baslama,bitis;
    char cevap;
    do{
 cout<<"1- Ogrenci Kayit Ekleme"<<endl; //Menümüz
 cout<<"2- Akademisyen Kayit Ekleme"<<endl;
 cout<<"3- Ogrenci Bilgi Guncelleme"<<endl;
 cout<<"4- Akademisyen Bilgi Guncelleme"<<endl;
 cout<<"5- Ogrenci Kayit Silme"<<endl;
 cout<<"6- Akademisyen Kayit Silme"<<endl;
 cout<<"7- Ogrenci Randevu Kaydi"<<endl;
 cout<<"8- Ogrenci Randevu güncelleme"<<endl;
 cout<<"9- Ogrenci Sorgulama"<<endl;
 cout<<"10- Ogrenci Listesi Alma"<<endl;
 cout<<"Yapmak Istediginiz Islemi Seciniz:"<<endl;
 cin>>secim;

 switch(secim) //Seçim yapyyoruz
 {
 case 1:
 {
system("cls");//ekran temizlenir
cout << "******* Ogrenci Kayit Ekleme ******" << endl;
cout << "Eklemesi Yapilacak Ogrencinin Numarasini Giriniz.....:"; cin >> o.numara;//dýþarýdan ogrenci numarasi girilir.
 
 ofstream DosyaYaz;
 DosyaYaz.open("ogrenci.txt",ios::app);
 do
 {

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
 system("pause");
 break;
 }

  case 2:
 {
system("cls");//ekran temizlenir
cout << "******* Akademisyen Kayit Ekleme ******" << endl;
cout << "Eklemesi Yapilacak Akademisyenin Sicil Numarasini Giriniz.....:"; cin >> a.sicilNumara;//dýþarýdan sicil numarasi girdirilir.
 
 ofstream DosyaYaz;
 DosyaYaz.open("akademisyen.txt",ios::app);
 do
 {

 cout<<"\n Adi :"; cin>>a.ad;
 cout<<"\n Soyadi :"; cin>>a.soyad;
 cout<<"\n Eposta :"; cin>>a.eposta;
 cout<<"\n Telefon :"; cin>>a.telefon;
 cout<<"\n Ana Bilim Dali :"; cin>>a.anabilim;
 cout<<"\n Unvan :"; cin>>a.unvan;
 cout<<endl;

 DosyaYaz<<a.sicilNumara<<" "<<a.ad<<' '<<a.soyad<<' ' <<a.eposta<<' '<<a.telefon<<' ' <<a.anabilim<<' ' <<a.unvan<<endl;
 cout<<"\n Baska kayit yapacak misiniz?(e/E) (h/H) ";cin>>cevap;

 }while(cevap=='e' || cevap=='E');

 DosyaYaz.close();
 cout<< "Dosyaya yazim tamamlandi."<<endl;
 system("pause");

 break;
 }
 
  case 3:
 	{
 		

string ogrNo;
system("cls"); //Ekran temizleme komutu
 
cout << "****** 3- Ogrenci Kayit Duzenleme ******" << endl;
 
ifstream DosyaOku("ogrenci.txt"); //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.
ofstream DosyaYaz("gecici.tmp");//Gecici bir dosya açýlýr
// DosyaYaz.open("gecici.tmp",ios::app); //gecici.tmp adýmda dosya oluþturup dosya ekleme modunda açtým
 
cout << "Duzenlenecek Ogrencinin Numarasi...:"; cin >> ogrNo; //düzenlenecek ogrenci numarasini sorgulattým.
 
int gcc=0;
while (!(DosyaOku.eof())) //DosyaOku da belirttiðim ogrenci.txt dosyasýný sonuna kadar okuttum.
{
DosyaOku >> o.numara >> o.ad >> o.soyad >> o.eposta >> o.telefon >> o.bolum>>o.kayitYili;//ogrenci.txt dosyasýndaki kayýtlar okunur
 
if (ogrNo == o.numara)//Sorgulanan ogrenci numarasi varsa bilgilerini gösterir.
{
cout << "========== Ogrenci Bilgileri ==========" << endl << endl;//ogrenci bilgieri yazdýrýlýr.
 
cout << " Numara :" << o.numara << endl;
cout << " Adi :" << o.ad << endl;
cout << " Soyadi :" << o.soyad << endl;
cout << " Eposta :" << o.eposta << endl;
cout << " Telefon Numarasi :" << o.telefon << endl;
cout << " Bolum :" <<o.bolum << endl ;
cout << " Kayit Yili :" <<o.kayitYili<< endl << endl;
cout << "Ogrenci Bilgilerini Yenileyiniz..." << endl << endl;//ogrencibilgilerini dýþardan girdirilir

cout << "\n Ogrenci Adi Giriniz :"; cin >> o.ad;
cout << "\n Ogrenci Soyadi Giriniz. :"; cin >> o.soyad;
cout << "\n Ogrenci Dogum Tarihini Giriniz :"; cin >> o.eposta;
cout << "\n Ogrenci Telefon Numarasi :"; cin >> o.telefon;
cout << "\n Ogrenci Bolum :"; cin >> o.bolum;
cout << "\n Ogrenci Kayit Yili:"; cin >> o.kayitYili;
 
DosyaYaz << "\n" << o.numara << " " << o.ad << " " << o.soyad << " " << o.eposta << " " << o.telefon << " " << o.bolum <<" "<<o.kayitYili;//Düzenlenen dosya bilgileri yazdýrýlýr.
 
gcc=1;
}
else
{
DosyaYaz << "\n" << o.numara << " " << o.ad << " " << o.soyad << " " << o.eposta << " " << o.telefon << " " << o.bolum<< " "<<o.kayitYili;
}

}
if(gcc==0)
cout << "Boyle Bir Kayit Bulunamamistir..." << endl;
 
DosyaYaz.close();
DosyaOku.close();
remove("ogrenci.txt");// ogrenci.txt dosyasý silinirken
rename("gecici.tmp", "ogrenci.txt");//gecici.tmp dosyasý ogrenci.txt dosyasý olarak deðiþtirirlir.

 break;
	 }
	 
	 
	 
	 
 case 4:
 	{
 		

string ogrNo;
system("cls"); //Ekran temizleme komutu
 
cout << "****** 4- Akademisyen Kayit Duzenleme ******" << endl;
 
ifstream DosyaOku("akademisyen.txt"); //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.
ofstream DosyaYaz("gecici.tmp");//Gecici bir dosya açýlýr
// DosyaYaz.open("gecici.tmp",ios::app); //gecici.tmp adýmda dosya oluþturup dosya ekleme modunda açtým
 
cout << "Duzenlenecek Akademisyenin Sicil Numarasi...:"; cin >> no; //düzenlenecek Sicil numarsini sorgulattým.
 
int gcc=0;
while (!(DosyaOku.eof())) //DosyaOku da belirttiðim ogrenci.txt dosyasýný sonuna kadar okuttum.
{
DosyaOku >>a.sicilNumara >> a.ad >> a.soyad >> a.eposta >> a.telefon>> a.anabilim>>a.unvan;//ogrenci.txt dosyasýndaki kayýtlar okunur
 
if (no == a.sicilNumara)//Sorgulanan ogrenci numarasý varsa ogrenci bilgilerini gösterir.
{
cout << "========== Akademisyen Bilgileri ==========" << endl << endl;//ogrenci bilgileri yazdýrýlýr.
 
cout << " Numara :" << a.sicilNumara << endl;
cout << " Adi :" << a.ad << endl;
cout << " Soyadi :" << a.soyad << endl;
cout << " Eposta :" << a.eposta << endl;
cout << " Telefon:" << a.telefon << endl;
cout << " Ana Bilim :" <<a.anabilim << endl << endl;
cout << " Unvan :" <<a.unvan<< endl << endl;
cout << "Akademisyen Bilgilerini Yenileyiniz..." << endl << endl;//ogrenci bilgilerini dýþardan girdirilir

cout << "\n Akademisyen Adi Giriniz :"; cin >> a.ad;
cout << "\n Akademisyen Soyadi Giriniz. :"; cin >> a.soyad;
cout << "\n Akademisyen Eposta Giriniz :"; cin >> a.eposta;
cout << "\n Akademisyen Telefon Numarasi :"; cin >> a.eposta;
cout << "\n Akademisyen Ana Bilim Dali :"; cin >> a.anabilim;
cout << "\n Akademisyen Unvan :"; cin >> a.unvan;
 
DosyaYaz << "\n" << a.sicilNumara << " " << a.ad << " " << a.soyad << " " << a.eposta << " " << a.telefon << " " << a.anabilim <<" "<<a.unvan;//Düzenlenen dosya bilgileri yazdýrýlýr.
 
gcc=1;
}
else
{
DosyaYaz << "\n" << a.sicilNumara << " " << a.ad << " " << a.soyad << " " << a.eposta << " " << a.telefon << " " << a.anabilim <<" "<<a.unvan;
}
}
if(gcc==0)
cout << "Boyle Bir Kayit Bulunamamistir..." << endl;
 
DosyaYaz.close();
DosyaOku.close();
remove("akademisyen.txt");// ogrenci.txt dosyasý silinirken
rename("gecici.tmp", "akademisyen.txt");//gecici.tmp dosyasý ogrenci.txt dosyasý olarak deðiþtirirlir.

 break;
	 }
 
 
 
 case 5:
 	{

system("cls"); //Console ekraný temizlenir.
cout << "****** 5- Ogrenci Kaydi Silme ****** " << endl;
string silhas_TC;
cout << "Silinecek Ogrenci Numarasini Giriniz :"; cin >> ogrNo;
 
ifstream DosyaOku("ogrenci.txt");
ofstream DosyaYaz("gecici.tmp");//Gecici bir dosya açýlýr
 
while (!(DosyaOku.eof())) //DosyaOku da belirttiðim ogrenci.txt dosyasýný sonuna kadar okuttum.
{
DosyaOku >> o.numara >> o.ad >> o.soyad >> o.eposta >> o.telefon >> o.bolum>>o.kayitYili;
 
if (o.numara == ogrNo)//Girilen ogrenci numarasi kayýtlarda var ise ogrenci kaydýný görüntüler.
{
 
cout << "========== Ogrenci Bilgileri ==========" << endl << endl;
 
cout << " Ogrenci Numara :" << ogrNo << endl;
cout << "Ogrenci Adi :" << o.ad << endl;
cout << "Ogrenci Soyadi :" << o.soyad<< endl;
cout << "Ogrenci Eposta :" << o.eposta << endl;
cout << "Ogrenci Telefon Numarasi :" <<o.telefon << endl;
cout << "Ogrenci Bolum :" << o.bolum << endl;
cout << "Ogrenci Kayit Yili :" << o.kayitYili<< endl;"\n"; //Eðer Koþulu Saðlayan Kullanici Varsa Onu Ekranda Gösterir
cout << "Silme Isleminiz Gerceklesmistir..." << endl;
break;
}
else
DosyaYaz << "\n" <<o.numara << " " << o.ad << " " <<o.soyad << " " << o.eposta << " " << o.telefon << " " << o.bolum<< " "<<o.kayitYili;
}
 
DosyaYaz.close();
DosyaOku.close();
 
remove("ogrenci.txt");//dosyayi sildim.
rename("gecici.tmp", "ogrenci.txt");//Gecici dosyalar kayýt silindikten tmp dosyasi txt dosyasina aktarýlýr.
 break;
}
 
 
 case 6:
 	{

system("cls"); //Console ekraný temizlenir.
cout << "****** 6- Akademisyen Kaydi Silme ****** " << endl;
string silhas_TC;
cout << "Silinecek Akademisyen Sicil Numarasini Giriniz :"; cin >> no;
 
ifstream DosyaOku("akademisyen.txt");
ofstream DosyaYaz("gecici.tmp");//Gecici bir dosya açýlýr
 
while (!(DosyaOku.eof())) //DosyaOku da belirttiðim akademisyen.txt dosyasýný sonuna kadar okuttum.
{
DosyaOku >> a.sicilNumara >> a.ad >> a.soyad >> a.eposta >> a.telefon >> a.anabilim>>a.unvan;
 
if (a.sicilNumara == no)//Girilen akademisyen sicil numarasý  kayýtlarda var ise akademisyen kaydýný görüntüler.
{
 
cout << "========== Akademisyen Bilgileri ==========" << endl << endl;
 
cout << " Akademisyen Numara :" << no << endl;
cout << "Akademisyen Adi :" << a.ad << endl;
cout << "Akademisyen Soyadi :" << a.soyad<< endl;
cout << "Akademisyen Eposta :" << a.eposta << endl;
cout << "Akademisyen Telefon Numarasi :" <<a.telefon << endl;
cout << "Akademisyen Ana Bilim :" << a.anabilim << endl;
cout << "Akademisyen Unvan :" << a.unvan<< endl;"\n"; //Eðer Koþulu Saðlayan Kullanici Varsa Onu Ekranda Gösterir
cout << "Silme Isleminiz Gerceklesmistir..." << endl;
break;
}
else
DosyaYaz << "\n" <<a.sicilNumara<< " " << a.ad << " " <<a.soyad << " " << a.eposta << " " << a.telefon << " " << a.anabilim<< " "<<a.unvan;
}
 
DosyaYaz.close();
DosyaOku.close();
 
remove("akademisyen.txt");//dosyayi sildim.
rename("gecici.tmp", "akademisyen.txt");//Gecici dosyalar kayýt silindikten tmp dosyasi txt dosyasina aktarýlýr.
 break;
}
 

 
 case 7:

 {
 cout<<"7- Randevu alma"<<endl;

 cout<<" Ogrenci No :";cin>>ogrNo;

 ifstream DosyaOku("ogrenci.txt");
 while(!DosyaOku.eof())
 {
 DosyaOku>>o.numara>>o.ad>>o.soyad>>o.eposta>>o.telefon>>o.kayitYili;
 cout<<endl;
 if(ogrNo==o.numara)
 {
 cout<< "\n Ogrenci Bilgileri \n";
 cout<<" no :"<<o.numara<<endl;
 cout<<"Adi :"<<o.ad<<endl;
 cout<<"Soyadi :"<<o.soyad<<endl;
 cout<<"Eposta :"<<o.eposta<<endl;
 cout<<"Telefonu :"<<o.telefon<<endl;
 cout<<"Kayit Yili:"<<o.kayitYili<<endl;
 cout<<"Devam etmek istiyor mu? (e/h)"<<endl;
 cin>>cevap;

 if (cevap=='e'|| cevap=='E')
 {
 DosyaOku.close();
 
 
  cout<<"\n Akademisyen SicilNo :"; cin>>no;
  ifstream DosyaOku2("akademisyen.txt");
 while(!DosyaOku2.eof())
 {
 DosyaOku2>>a.sicilNumara>>a.ad>>a.soyad>>a.eposta>>a.telefon>>a.anabilim>>a.unvan;
 cout<<endl;
 if(no==a.sicilNumara)
 {
 cout<< "\n Akademisyen Bilgileri \n";
 cout<<"no :"<<a.sicilNumara<<endl;
 cout<<"Adi :"<<a.ad<<endl;
 cout<<"Soyadi :"<<a.soyad<<endl;
 cout<<"Eposta :"<<a.eposta<<endl;
 cout<<"Telefonu :"<<a.telefon<<endl;
 cout<<"Ana Bilim:"<<a.anabilim<<endl;
  cout<<"Unvan:"<<a.unvan<<endl;
 cout<<"Randevu istiyor mu? (e/h)"<<endl;
 cin>>cevap;

 if (cevap=='e'|| cevap=='E')
 {
 DosyaOku2.close();
 
   cout<<"\n Akademisyen SicilNo :"; cin>>no;
     cout<<"\n Tarih: :"; cin>>tarih;
     cout<<"\n baslama saati: :"; cin>>baslama;
    cout<<"\n bitis saati: :"; cin>>bitis;
    
 
  fstream DosyaOku2("randevu.txt");
 while(!DosyaOku2.eof())
 {
 	
 DosyaOku2>>r.tarih>>r.baslamasaat>>r.bitissaat;
 cout<<endl;
  //DosyaYaz <<no<<" "<<no;
 
 if(tarih!=r.tarih){
 	 DosyaOku2 <<r.tarih<<" ";
 	 if(r.baslamasaat<baslama && baslama>r.bitissaat)
 	 {
 	 	DosyaOku2 <<r.baslamasaat<<" "<<r.bitissaat;
 	 	
	  }
 }

   



}


// DosyaYaz <<o.numara<<" "<<a.sicilNumara<<' '<<r.tarih<<' ' <<r.baslamasaat<<' '<<r.bitissaat<<"\n";
 cout<<o.numara<<" numarali ogrenci ile"<<a.sicilNumara<<" numarali akademisyen randevusu basarili olusturulmustur"<<endl;
 
 DosyaOku2.close();break;
}

 
 }
 else
 {
 	cout<<"akademisyen bulunamadi"<<endl;
 }
 }
}
}
else
{
	cout<<"ogrenci bulunamadi"<<endl;
}
 }
 break;
 }
 
 
 
 
 
 
 case 8:
 	{
 		

string ogrNo;
system("cls"); //Ekran temizleme komutu
 
cout << "****** 7- Ogrenci Randevu Guncelleme ******" << endl;
 
ifstream DosyaOku("ogrenci.txt"); //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.
ofstream DosyaYaz("gecici.tmp");//Gecici bir dosya açýlýr
// DosyaYaz.open("gecici.tmp",ios::app); //gecici.tmp adýmda dosya oluþturup dosya ekleme modunda açtým
 
cout << "Duzenlenecek Ogrencinin Numarasi...:"; cin >> ogrNo; //düzenlenecek ogrenci numarasýný sorgulattým.
 
int gcc=0;
while (!(DosyaOku.eof())) //DosyaOku da belirttiðim ogrenci.txt dosyasýný sonuna kadar okuttum.
{
DosyaOku >> o.numara >> o.ad >> o.soyad >> o.eposta >> o.telefon >> o.bolum>>o.kayitYili;//ogrenci.txt dosyasýndaki kayýtlar okunur
 
if (ogrNo == o.numara)//Sorgulanan ogrenci numarasý varsa ogrenci bilgilerini gösterir.
{
cout << "========== Hasta Bilgileri ==========" << endl << endl;//ogrenci bilgieri yazdýrýlýr.
 
cout << " Numara :" << o.numara << endl;
cout << " Adi :" << o.ad << endl;
cout << " Soyadi :" << o.soyad << endl;
cout << " Eposta :" << o.eposta << endl;
cout << " Telefon Numarasi :" << o.telefon << endl;
cout << " Bolum :" <<o.bolum << endl << endl;
cout << " Kayit Yili :" <<o.kayitYili<< endl << endl;
cout << "Ogrenci Bilgilerini Yenileyiniz..." << endl << endl;//ogrenci bilgilerini dýþardan girdirilir

cout << "\n Ogrenci Adi Giriniz :"; cin >> o.ad;
cout << "\n Ogrenci Soyadi Giriniz. :"; cin >> o.soyad;
cout << "\n Ogrenci Dogum Tarihini Giriniz :"; cin >> o.eposta;
cout << "\n Ogrenci Telefon Numarasi :"; cin >> o.telefon;
cout << "\n Ogrenci Kayit Numarasi :"; cin >> o.bolum;
cout << "\n Ogrenci Kayit Numarasi :"; cin >> o.kayitYili;
 
DosyaYaz << "\n" << o.numara << " " << o.ad << " " << o.soyad << " " << o.eposta << " " << o.telefon << " " << o.bolum <<" "<<o.kayitYili;//Düzenlenen dosya bilgileri yazdýrýlýr.
 
gcc=1;
}
else
{
DosyaYaz << "\n" << o.numara << " " << o.ad << " " << o.soyad << " " << o.eposta << " " << o.telefon << " " << o.bolum<< " "<<o.kayitYili;
}
}
if(gcc==0)
cout << "Boyle Bir Kayit Bulunamamistir..." << endl;
 
DosyaYaz.close();
DosyaOku.close();
remove("ogrenci.txt");// ogrenci.txt dosyasý silinirken
rename("gecici.tmp", "ogrenci.txt");//gecici.tmp dosyasý ogrenci.txt dosyasý olarak deðiþtirirlir.

 break;
	 }
 
 case 9:
 	
{
 
system("cls");//ekran temizlenir
cout << "******* Ogrenci Sorgulama ******" << endl;
cout << "Sorgusu Istenen Ogrencini Numarasini Giriniz.....:"; cin >> ogrNo;//dýþarýdan numara girdirilir.
 
int gcc1=0, gcc2=0;
ifstream DosyaOku("ogrenci.txt");//ogrenci.txt dosyasý DosyaOku modunda tanýmlanýr.
while (!(DosyaOku.eof()))// Dosya sonuna kadar okunur.
{
DosyaOku >> o.numara >> o.ad >> o.soyad >> o.eposta >> o.telefon>> o.bolum>>o.kayitYili;
 
if (o.numara == ogrNo)
{
cout << " ========== Ogrenci Bilgileri ========== " << endl;
 
cout << "Ogrenci Numarasi:" << o.numara << endl;
cout << "Ogrenci  Adi :" << o.ad << endl;
cout << "Ogrenci  Soyadi : " << o.soyad << endl;
cout << "Ogrenci Eposta :" << o.eposta << endl;
cout << "Ogrenci  Telefon Numarasi :" << o.telefon << endl;
cout << "Ogrenci  Bolum:" << o.bolum << endl;
cout << "Ogrenci Kayit Yili:" << o.kayitYili << "\n";
 
DosyaOku.close();
gcc1=1;
break;
}
}
 
ifstream DosyaOku2("randevu.txt"); //randevu.txt dosyasý DosyaOku modunda tanýmlanýr.
 
while (!(DosyaOku2.eof()))// Dosya sonuna kadar okunur.
{
DosyaOku2 >> o.numara >> a.ad >> r.tarih>> r.baslamasaat >> r.bitissaat;
if (o.numara == ogrNo)
{
cout << "========== Randevu Bilgileri ===========" << endl;
 
cout << "Ogrenci Numara :" << o.numara << endl;
cout << "Akademisyen Adi :" << a.sicilNumara<< "\n";
cout << "Randevu Tarihi :" << r.tarih << endl;
cout << "Randevu Baslama Saati :" << r.baslamasaat << endl;
cout << "Randevu Bitis Saati :" << r.bitissaat<< "\n";


 
gcc2=1; //eðer dosya okuma iþlemi olduysa gcc deðiþkeninin deðerini 1 yapýyorum.
o.numara+=1; //Döngü en sonda tekrarlamamasý için numara deðerini deðiþtiriyorum.
}
}
DosyaOku2.close();
if(gcc1==0) //eðer dosya okuma iþlemi olmadýysa gcc deðeri 0 dýr ve ekrana uyarý verir.
cout << "Hasta Kayidi Bulunmamaktadir..." << endl;
if(gcc2==0)
cout << "Randevu Kayidi Bulunmamaktadir..." << endl;
}
 
system("pause");
 

 
 
break;
 
 
case 10:
{
system("cls"); //console ekranýný temizledim.
cout << "****** Ogrenci Listesi ******" << endl << endl;
ifstream DosyaOku("ogrenci.txt");
while (!(DosyaOku.eof())) //DosyaOku da belirttiðim ogrenci.txt dosyasýný sonuna kadar okuttum.
{
DosyaOku >> o.numara >> o.ad >> o.soyad >> o.eposta >> o.telefon >> o.bolum>>o.kayitYili;
cout << "=========== Ogrenci Bilgileri ==========" << endl;
cout << "Ogrenci Numara:" << o.numara << endl;
cout << "Ogrenci Adi :" << o.ad << endl;
cout << "Ogrenci Soyadi :" << o.soyad << endl;
cout << "Ogrenci Telefon Numarasi :" << o.telefon << endl;
}
DosyaOku.close(); //dosya okumayý kapattým.
break;
}
}


 cout<<"Islem yapmaya devam etmek istiyor musunuz? (e/E) (h/H)";
 cin>>islem;
 }while(islem=='e' || islem=='E'); //Islemi yaptyktan sonra karýsmyza tekrar menü
 cout<<endl; //çýkmasýný sagliyor
 getch();

 }


