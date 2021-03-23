#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Ogrenci{
	char isim[20];
	char soyisim[20];
	float ortalama;
};//veri tipi tan�m�n� yapt�m.

int main(){
	
	
	//int x;//de�i�ken olu�turma.(VER� T�P�: �nt, DE���KEN �SM�: x)
    struct Ogrenci ogr1={"Ogun","Birinci",3.74};//de�i�ken olu�turma( VER� T�P�: STRUCT Ogrenci, DE���KEN �SM�: ogr1)
	struct Ogrenci ogr2;
	
	strcpy(ogr2.isim,"Duygu");//char cinsinden oldu�u i�in atamalar e�itlik ile yap�lamaz.
	strcpy(ogr2.soyisim,"Keydal");
	ogr2.ortalama=3.70;//e�itlik operat�r� ile atad�k.
	
	printf("Ogr1 Degiskeninin ismi:%s\n",ogr1.isim);//degerlere erisim sa�lad�m  ( . operat�r� ile eri�im sa�lad�m)
	printf("Ogr1 Degiskeninin soyismi:%s\n",ogr1.soyisim);
	printf("Ogr1 Degiskeninin ortalamasi:%.2f\n",ogr1.ortalama);
	
	printf("\nOgr2 Degiskeninin ismi:%s\n",ogr2.isim);//degerlere erisim sa�lad�m  ( . operat�r� ile eri�im sa�lad�m)
	printf("Ogr2 Degiskeninin soyismi:%s\n",ogr2.soyisim);
	printf("Ogr2 Degiskeninin ortalamasi:%.2f\n",ogr2.ortalama);*/
	
	
	//D�Z�LERLE B�RL�KTE KULLANIM
	struct Ogrenci ogrenciler[3];//direkt atama yapabilirsiniz
	int i;
	for(i=0;i<3;i++){//BILGI ALMA KISMI
		puts("Lutfen ogrencinin adini giriniz:");
		scanf("%s",&ogrenciler[i].isim);
		puts("Lutfen ogrencinin soyadini giriniz:");
		scanf("%s",&ogrenciler[i].soyisim);
		puts("Lutfen ogrencinin ortalamasini giriniz:");
		scanf("%f",&ogrenciler[i].ortalama);
	}
	
	for(i=0;i<3;i++){//BILGI YAZDIRMA KISMI.
		printf("%d. ogrencinin adi-soyadi:%s %s ve ortalamasi:%.2f\n",i+1,ogrenciler[i].isim,ogrenciler[i].soyisim,ogrenciler[i].ortalama);
	}
	
	
	//��ARET��LERLE B�RL�KTE KULLANIM
	
	struct Ogrenci ogr;//degisken tanimlamasi yaptik.
	struct Ogrenci *ogrPtr;//isaretci degiskeni tanimlamasi yaptik
	struct Ogrenci *ogrPtr2;
	ogrPtr=&ogr;//ogrPtr ogr'nin adresini tutuyor,onu i�aret ediyor.
	ogrPtr2=&ogr;
	
	
	strcpy((*ogrPtr).isim,"Ogun");
	strcpy((*ogrPtr).soyisim,"Birinci");
	(*ogrPtr).ortalama=3.74;
	
	strcpy(ogrPtr->isim,"Ogun");
	strcpy(ogrPtr->soyisim,"Birinci");
	ogrPtr->ortalama=3.74;
	
	strcpy(ogrPtr2->isim,"Duygu");
	strcpy(ogrPtr2->soyisim,"Keydal");
	ogrPtr2->ortalama=3.68;
	/*
	                   isim soyisim ortalama
		ogrPtr->>>>ogr	  Duygu Keydal 3.68
		ogrPtr2->>>ogr    Duygu Keydal 3.68
	*/
	

	printf("Adresi:%#X\n",ogrPtr);
	printf("Ogrencinin ismi:%s\n",(*ogrPtr).isim);
	printf("Ogrencinin soy ismi:%s\n",(*ogrPtr).soyisim);
	printf("Ogrencinin ortalamasi:%.2f\n",(*ogrPtr).ortalama);
	

	
	//D�NAM�K BELLEK Y�NET�M�YLE B�RL�KTE KULLANIM
	int elemanSayisi,i;
	printf("Lutfen ogrenci sayisini giriniz:");
	scanf("%d",&elemanSayisi);
	
	struct Ogrenci *ogrPtr;// malloctan d�nen ba�lang�� adresini tutar.
	ogrPtr=(struct Ogrenci*)malloc(sizeof(struct Ogrenci)*elemanSayisi);//dinamik bir �ekilde de�i�ken olu�turdum
	//dizinin baslangic adresini tutacak.
	
	
	for(i=0;i<elemanSayisi;i++){
		puts("Lutfen ogrencinin adini giriniz:");
		scanf("%s",&ogrPtr[i].isim);
		puts("Lutfen ogrencinin soyadini giriniz:");
		scanf("%s",&ogrPtr[i].soyisim);
		puts("Lutfen ogrencinin ortalamasini giriniz:");
		scanf("%f",&ogrPtr[i].ortalama);		
	}
	for(i=0;i<elemanSayisi;i++){
		printf("Ogrencinin ismi:%s\n",ogrPtr[i].isim);
		printf("Ogrencinin soy ismi:%s\n",ogrPtr[i].soyisim);
		printf("Ogrencinin ortalamasi:%.2f\n",ogrPtr[i].ortalama);
	}

	free(ogrPtr);//serbest b�rak�yoruz, geri veriyoruz.

	return 0;
}

//FONKS�YONLARLA B�RL�KTE KULLANIM
typedef struct{
	char isim[20];//20 byte kapl�yor
	char soyisim[30];//30 byte yer kapl�yor
	float ortalama;	//6 byte.
}Ogrenci;//veri tipi tan�m�n� yapt�m


void bilgileriOku(Ogrenci *ogrPtr){
	puts("Lutfen ogrencinin adini giriniz:");
	scanf("%s",&ogrPtr->isim);
	puts("Lutfen ogrencinin soyadini giriniz:");
	scanf("%s",&ogrPtr->soyisim);
	puts("Lutfen ogrencinin ortalamasini giriniz:");
	scanf("%f",&ogrPtr->ortalama);	
}
void bilgileriYazdir(Ogrenci *ogrPtr){
	
	printf("Ogrenci Adi:%s\n",ogrPtr->isim);
	printf("Ogrenci Soyadi:%s\n",ogrPtr->soyisim);
	printf("Ogrenci Ortalamasi:%.2f\n",ogrPtr->ortalama);
}
void ogrenciBilgisiDegistir(Ogrenci *ogr,Ogrenci *ogr2){
	Ogrenci geciciOgrenci;
	
	strcpy(geciciOgrenci.isim,ogr->isim);
	strcpy(geciciOgrenci.soyisim,ogr->soyisim);
	geciciOgrenci.ortalama=ogr->ortalama;
	
	
	strcpy(ogr->isim,ogr2->isim);
	strcpy(ogr->soyisim,ogr2->soyisim);
	ogr->ortalama=ogr2->ortalama;
	
	strcpy(ogr2->isim,geciciOgrenci.isim);
	strcpy(ogr2->soyisim,geciciOgrenci.soyisim);
	ogr2->ortalama=geciciOgrenci.ortalama;

}

int main(int argc,char **argv){
	
	Ogrenci ogr;
	Ogrenci ogr2;
	bilgileriOku(&ogr);
	bilgileriOku(&ogr2);
	puts("Birinci Ogrenci Bilgileri\n");
	bilgileriYazdir(&ogr);
	puts("Ikinci Ogrenci Bilgileri\n");
	bilgileriYazdir(&ogr2);
	
	ogrenciBilgisiDegistir(&ogr,&ogr2);
	puts("Birinci Ogrenci Bilgileri\n");
	bilgileriYazdir(&ogr);
	puts("Ikinci Ogrenci Bilgileri\n");
	bilgileriYazdir(&ogr2);

}



//ENUMERAT�ON KISMI
typedef enum{
	pzt=1,sali=2,crs=3,prs=4,cuma=5,cts=6,pzr=7
}haftaninGunleri;

typedef enum{
	acemi=1,ortaseviye=2,ileriseviye=3,prof=4
}oyunSeviyeleri;

int main(){
	haftaninGunleri gunler;//de�i�ken
	puts("Lutfen haftanin gunlerine karsilik 1-7 arasi bir sayi giriniz:");
	scanf("%d",&gunler);
	
	switch(gunler){
		case pzt:
		case sali:
		case crs:
		case prs:
		case cuma:
			printf("Haftaici.");
			break;
		case cts:
		case pzr:
			printf("Haftasonu.");
			break;
		default:
			printf("Hatali bir tuslama yaptiniz.");	
	}
	
	oyunSeviyeleri seviyeler;//de�i�ken olu�turdum
	puts("Lutfen oyundaki level karsiligini giriniz:");
	scanf("%d",&seviyeler);
	if(seviyeler==acemi){//sayilardan kurtulmak icin enum yap�yoruz.
		printf("Bu gorevi almaya yetkiniz yoktur.");
	}
	else if(seviyeler==ortaseviye || seviyeler==ileriseviye){
		printf("Bu gorevi alabilirsiniz.");
	}
	else if(seviyeler==prof){
		printf("Bu gorevi almak icin seviyeniz cok yuksek.");
	}
	else{
		printf("Hatali level girisi");
	}

	return 0;	
}
*/




//UN�ON KISMI
typedef union{
	int intSayi;//4byte
	float floatSayi;//4byte
	double doubleSayi;//8byte/////MAKS�MUM BYTE SEV�YES�NE G�RE BEL�RLEND�
}Sayi;

int main(){
	
	Sayi sayi;
	sayi.intSayi=12;
	printf("%d\n",sayi.intSayi);
	printf("%f\n",sayi.floatSayi);
	printf("%f\n",sayi.doubleSayi);
	
	sayi.floatSayi=3.85;
	printf("\n");
	printf("%d\n",sayi.intSayi);
	printf("%f\n",sayi.floatSayi);
	printf("%f\n",sayi.doubleSayi);
	
	sayi.doubleSayi=5.89;
	printf("\n");
	printf("%d\n",sayi.intSayi);
	printf("%f\n",sayi.floatSayi);
	printf("%f\n",sayi.doubleSayi);
	
	
	

	return 0;	
}*/

///////////////////////SAAT �EV�RME///////////////////////

typedef struct{
	int saat;
	int dakika;
	double saniye;//saniye+ondalikliKisim(salise)
}saatBilgileri;


saatBilgileri saatiAyir(double kullaniciSaati){
	saatBilgileri donusturulenSaat;
	
	int tamSayiKismi=(int)kullaniciSaati;
	double ondalikliKisim=kullaniciSaati-tamSayiKismi;
	
	donusturulenSaat.saat=tamSayiKismi/3600;//2 saat//7200 saniye
	donusturulenSaat.dakika=(tamSayiKismi%3600)/60;// 2dakika//120 saniye
	donusturulenSaat.saniye=(tamSayiKismi%3600)%60+ondalikliKisim;//30 saniye 

	
	
	return donusturulenSaat;
	
}
int main(void){
	double kullaniciGirisi;
	saatBilgileri kullaniciSaati;
	
	printf("Lutfen gireceginiz saat degerini saniye biciminde giriniz:");
	scanf("%lf",&kullaniciGirisi);
	
	kullaniciSaati=saatiAyir(kullaniciGirisi);
	//saat-dakika-saniye
	printf("%d:%d:%.2lf",kullaniciSaati.saat,kullaniciSaati.dakika,kullaniciSaati.saniye);

	

	return 0;
}



//////////////////////////////URUN B�LG�S�-EKLEME-OKUMA///////////////////////////////////
typedef struct{
	int ID;//4byte
	double fiyatBilgisi;//8byte
	char urunAdiBilgisi[20];//20byte	
}urunBilgileri;

void listeyeUrunEkle(urunBilgileri urunListesi[],int urunID,double urunFiyat,char *urunAdi){
	int bosYer=0;//dongu icin
	while(1){
		if(urunListesi[bosYer].ID==0){//burasi bos buraya yazabilirim.
			urunListesi[bosYer].ID=urunID;
			urunListesi[bosYer].fiyatBilgisi=urunFiyat;
			strcpy(urunListesi[bosYer].urunAdiBilgisi,urunAdi);
			break;
		}
		bosYer++;
	}	
}
int urunBul(int arananID,urunBilgileri urunListesi[],int urunSayisi){
	int i;
	for(i=0;i<urunSayisi;i++){
		if(urunListesi[i].ID==arananID){
			return i;//bulduk ve indeksi i
		}
	}
	return -1;//bulamadik
}
void urunBilgisiGoster(int urunID,urunBilgileri urunListesi[],int urunSayisi){
	
	int urunIndex=urunBul(urunID,urunListesi,urunSayisi);//varsa index geldi yoksa -1 geldi.
	if(urunIndex!=-1){
		printf("Urun ID:%d\n",urunListesi[urunIndex].ID);
		printf("Urun Fiyat:%.2lf\n",urunListesi[urunIndex].fiyatBilgisi);
		printf("Urun Adi:%s",urunListesi[urunIndex].urunAdiBilgisi);
	}
	else{
		printf("Aradiginiz urun kayitli degildir.");
	}
		
}

int main(void){
	
	int urunSayisi,ID,i;
	urunBilgileri *urunlerListesi;
	double urunFiyat;
	char urunAdi[15];
	
	puts("Lutfen kac adet urun girmek istediginizi soyleyin.");
	scanf("%d",&urunSayisi);
	urunlerListesi=(urunBilgileri*)calloc(urunSayisi,sizeof(urunBilgileri));//dinamik �ekilde �r�n deposu olu�turduk
	
	for(i=0;i<urunSayisi;i++){
		puts("Lutfen eklenecek urunun ID bilgisini giriniz:");
		scanf("%d",&ID);
		puts("Lutfen eklenecek urunun fiyat bilgisini giriniz:");
		scanf("%lf",&urunFiyat);
		puts("Lutfen eklenecek urunun adini giriniz:");
		scanf("%s",&urunAdi);
		listeyeUrunEkle(urunlerListesi,ID,urunFiyat,urunAdi);//urunleri ekledik
	}
	
	printf("Lutfen gormek istediginiz urunun ID bilgisini giriniz:");
	scanf("%d",&ID);
	urunBilgisiGoster(ID,urunlerListesi,urunSayisi);

	return 0;

}





/////////////////////ELEMENT SORGULAMA//////////////////////////
typedef struct{
	char sembol[3];//He
	char tamAdi[20];//Helyum;
	int atomNumarasi;	
}element;

void bilgileriGoster(element elementListesi[],char *sembol,int elementSayisi){
	int i;
	int bulunduMu=0;//bulunursa 1 yapacagiz.
	for(i=0;i<elementSayisi;i++){
		if(strcmp(elementListesi[i].sembol,sembol)==0){
			printf("Sembol:%s\n",elementListesi[i].sembol);
			printf("Tam Adi:%s\n",elementListesi[i].tamAdi);
			printf("Atom Numarasi:%d\n",elementListesi[i].atomNumarasi);
			bulunduMu=1;
			break;
		}	
	}
	if(!bulunduMu){
		printf("Aradiginiz element listede bulunamadi\n");
	}

}


int main(){
	element elementListesi[]={{"He","Helyum",2},{"H","Hidrojen",1},{"B","Bor",5},{"F","Flor",9},{"N","Azot",7}};
	char kullaniciArama[5];
	
	while(1){
		printf("Lutfen yazdirmak istediginiz elementin sembolunu giriniz(Cikis icin Q tuslayiniz):");
		scanf("%s",&kullaniciArama);
		if(strcmp(kullaniciArama,"Q")==0){
			break;
		}
		bilgileriGoster(elementListesi,kullaniciArama,5);	
	}

	return 0;
}

////////////////////////////NOKTALARDAN ALAN HESAPLAMA PROGRAM/////////////////////


typedef struct{
	int x;
	int y;
}Nokta;

typedef struct{
	Nokta koordinat[4];//N0-->x ve y al�nd� N1---->x ve y ald�m N2--->x ve y ald�m N3--->x ve y ald�m
}dikdortgen;

float alanHesapla(dikdortgen kullaniciGirisi){
	float x_kenar,y_kenar;
	x_kenar=kullaniciGirisi.koordinat[1].x-kullaniciGirisi.koordinat[0].x;
	y_kenar=kullaniciGirisi.koordinat[3].y-kullaniciGirisi.koordinat[0].y;
	return x_kenar*y_kenar;
	
}



int main(){
		
	dikdortgen hesaplanacakDortgen;//de�i�ken olu�turdum.
	int i;//dongu icin
	for(i=0;i<4;i++){
		printf("Lutfen  N%d koordinati icin sirasiyla x ve y degerlerini giriniz:",i);
		scanf("%d%d",&hesaplanacakDortgen.koordinat[i].x,&hesaplanacakDortgen.koordinat[i].y);
	}
	
	float sonuc=alanHesapla(hesaplanacakDortgen);
	printf("Girdiginiz x-y degerlerine karsilik alan degeri:%.2f",sonuc);
	

	
	return 0;	
}



//�DEV SORULARI

/*
1.Soru-> Bir adet kompleks sayi yap�s� olu�turunuz, i�inde ger�ek ve sanal k�sm� olacak. Olu�turdu�unuz bu yap�dan 2 adet de�i�ken olu�turup bunlar�n
toplam�n� hesaplayacak bir fonksiyon yaz�p main k�s�mda sonucu bast�r�n�z.
	(3+4i)+(-8+12i)=-5+16i


2.Soru->Derste de benzerini yapt���m�z gibi bir adet saat yap�s� olu�turunuz, i�inde saat dakika saniye de�i�keleri bulunacak. Olu�turdu�unuz bu
yap�dan 2 adet de�i�ken olu�turup kullan�c�dan de�er okumas� yap�n�z. En son girilen 2 saatin fark�n� hesaplayacak bir program yaz�p sonucu 
bast�r�n�z.
				16:53:81
				13:21:32


3.Soru->Bir adet kitapl�k projesi yapman�z� istiyorum,bir adet kitapBilgileri yap�s� olu�turunuz, yap�n�z i�inde kitapAdi,kitapYazari,sayfaSayisi,
yayinEvi gibi bilgiler i�ersin. Main k�s�mda kullan�c�dan alaca��n�z kitap say�s�na g�re bir dinamik array olu�turup kitaplar� orada saklay�n.
Kitap Ekle, Kitap Ara, Tum Kitaplar� goruntule fonksiyonlar� yaz�n�z ve bunlar� main k�s�mda deneyiniz.


4.Soru->3.Soruda yapt���n�z kitapl�k projesindeki kitap ekle fonksiyonuna enum yap�s�n� kullanarak bir k�s�tlama getirin.2 adet yetki olacak.
E�er yetkiniz ogrenci ise kitap ekleme yapamayacaks�n�z, e�er ki yetkiniz calisan ise kitap ekleyebilirsiniz.


*/

//1.SORU
/*

typedef struct{
	float gercekKisim;//ger�ek say� 
	float sanalKisim;//i li olan k�s�m 
}kompleksSayi;

void sayiTopla(kompleksSayi sayi1,kompleksSayi sayi2,kompleksSayi *sonuc){
	sonuc->gercekKisim=sayi1.gercekKisim+sayi2.gercekKisim;
	sonuc->sanalKisim=sayi1.sanalKisim+sayi2.sanalKisim;	
}


int main(void){
	
	kompleksSayi sayi1,sayi2,sonuc;
	
	printf("Lutfen ilk sayinin sirasiyla gercek ve sanal kismini giriniz:");
	scanf("%f%f",&sayi1.gercekKisim,&sayi1.sanalKisim);
	
	printf("Lutfen ikinci sayinin sirasiyla gercek ve sanal kismini giriniz:");
	scanf("%f%f",&sayi2.gercekKisim,&sayi2.sanalKisim);
	
	sayiTopla(sayi1,sayi2,&sonuc);
	printf("Sonuc:%.1f+%.1fi",sonuc.gercekKisim,sonuc.sanalKisim);
	
	
	

	return 0;
}

*/

//2.SORU
/*
typedef struct{
	int saat;
	int dakika;
	double saniye;
}saatBilgileri;

saatBilgileri farkiBul(saatBilgileri ilkSaat,saatBilgileri ikinciSaat){
	saatBilgileri saatFarki;//sonuc bunda tutulacak.
	
	double ilkSaatDouble=ilkSaat.saat*3600+ilkSaat.dakika*60+ilkSaat.saniye;
	double ikinciSaatDouble=ikinciSaat.saat*3600+ikinciSaat.dakika*60+ikinciSaat.saniye;
	
	if(ilkSaatDouble>=ikinciSaatDouble){
		if(ilkSaat.saniye<ikinciSaat.saniye){
			ilkSaat.saniye+=60;
			ilkSaat.dakika-=1;
		}
		if(ilkSaat.dakika<ikinciSaat.dakika){
			ilkSaat.dakika+=60;
			ilkSaat.saat-=1;
		}
		saatFarki.saat=ilkSaat.saat-ikinciSaat.saat;
		saatFarki.dakika=ilkSaat.dakika-ikinciSaat.dakika;
		saatFarki.saniye=ilkSaat.saniye-ikinciSaat.saniye;
	}
	else{
		if(ilkSaat.saniye>ikinciSaat.saniye){
			ikinciSaat.saniye+=60;
			ikinciSaat.dakika-=1;
		}
		if(ilkSaat.dakika>ikinciSaat.dakika){
			ikinciSaat.dakika+=60;
			ikinciSaat.saat-=1;
		}
		saatFarki.saat=ikinciSaat.saat-ilkSaat.saat;
		saatFarki.dakika=ikinciSaat.dakika-ilkSaat.dakika;
		saatFarki.saniye=ikinciSaat.saniye-ilkSaat.saniye;

	}
	return saatFarki;
	
}


int main(){
	saatBilgileri kullaniciSaati,kullaniciSaati2;
	saatBilgileri saatFarki;
	
	printf("Lutfen ilk saat bilgisini saat:dakika:saniye seklinde giriniz:");
	scanf("%d:%d:%lf",&kullaniciSaati.saat,&kullaniciSaati.dakika,&kullaniciSaati.saniye);
	
	printf("Lutfen ikinci saat bilgisini saat:dakika:saniye seklinde giriniz:");
	scanf("%d:%d:%lf",&kullaniciSaati2.saat,&kullaniciSaati2.dakika,&kullaniciSaati2.saniye);
	
	saatFarki=farkiBul(kullaniciSaati,kullaniciSaati2);
	printf("%d:%d:%.2lf",saatFarki.saat,saatFarki.dakika,saatFarki.saniye);
		
	return 0;
	
	
}

*/


//3.SORU
/*
typedef struct{
	char kitapYazar[20];
	char kitapAdi[20];
	char yayinEvi[20];
	int sayfaSayisi;
}kitapBilgileri;

typedef enum{
	ogrenci=1,calisan=2
	
}yetkiSeviyeleri;

void kitapEkle(kitapBilgileri *kitapDizisi,int kitapSayisi,yetkiSeviyeleri yetki){
	int i=0;//dongu icin.
	
	if(yetki==ogrenci){
		puts("Uzgunum.Kitap Ekleme yetkisine sahip degilsiniz.Kitap Eklemesi yapamazsiniz.");
		return ;
	}
	
	
	while(1){
		if(i>kitapSayisi){//kitaplik full
			puts("Uzgunum. Daha fazla kitap eklenemez, kitaplik tamamen dolu\n");
			return;
		}
		if(kitapDizisi[i].sayfaSayisi==0){//kitapligin o indeksi bo�.
			printf("Kitap Ismini Giriniz:");
			scanf("%s",&kitapDizisi[i].kitapAdi);
			printf("Kitap Yazarini Giriniz:");
			scanf("%s",&kitapDizisi[i].kitapYazar);
			printf("Kitap YayinEvi Bilgisini Giriniz:");
			scanf("%s",&kitapDizisi[i].yayinEvi);
			printf("Kitap Sayfa Sayisi Bilgisini Giriniz:");
			scanf("%d",&kitapDizisi[i].sayfaSayisi);
			return;
		}
		i++;//bir sonraki indeksten bo� yer aramaya devam ediyoruz.
	}
}
void kitapGoruntule(kitapBilgileri *kitapDizisi,int kitapSayisi){
	int i;
	for(i=0;i<kitapSayisi;i++){
		printf("Kitap Adi:%s\n",kitapDizisi[i].kitapAdi);
		printf("Kitap Yazari:%s\n",kitapDizisi[i].kitapYazar);
		printf("Kitap Yayinevi:%s\n",kitapDizisi[i].yayinEvi);
		printf("Kitap Sayfa Sayisi:%d\n",kitapDizisi[i].sayfaSayisi);
		printf("-----------------------------------------------\n");
	}
}
int kitapAra(kitapBilgileri *kitapDizisi,char *kitapAdi,int kitapSayisi){
	int i;
	for(i=0;i<kitapSayisi;i++){
		if(strcmp(kitapDizisi[i].kitapAdi,kitapAdi)==0){
			return i;//kitab� buldugum indeks de�erini d�n�yorum.
		}
	}
	return -1;
}
*/

//4.SORU
/*
int main(void){
	int kitapSayisi;
	kitapBilgileri *kitaplik;//dinamik �ekilde olu�turulan kitapBilgileri dizim.
	char kullaniciIstegi,kitapAdi[20];
	yetkiSeviyeleri kullaniciYetki;
	
	
	puts("Lutfen kac adet kitap eklemek istediginizi giriniz:");
	scanf("%d",&kitapSayisi);
	
	kitaplik=(kitapBilgileri*)calloc(kitapSayisi,sizeof(kitapBilgileri));
	
	do{
		fflush(stdin);
		puts("Kitap Eklemek istiyorsaniz 'E', tum kitaplari goruntulemek istiyorsaniz 'G', arama yapmak istiyorsaniz 'A', cikis yapmak istiyorsaniz 'Q' tuslayiniz.");
		kullaniciIstegi=getchar();
		switch(kullaniciIstegi){
			case 'E':
				puts("Lutfen ogrenciyseniz 1, calisansaniz 2 tuslayiniz.");
				scanf("%d",&kullaniciYetki);
				kitapEkle(kitaplik,kitapSayisi,kullaniciYetki);
				break;
			case 'A':
				puts("Lutfen aramak istediginiz kitabin adini giriniz:");
				scanf("%s",&kitapAdi);
				int kitap_Index=kitapAra(kitaplik,kitapAdi,kitapSayisi);
				if(kitap_Index==-1){
					printf("Aradiginiz kitap kutuphanede bulunamadi.");
				}
				else{
					printf("Aradiginiz kitap kitapligimizin %c-%d kisminda bulundu.\n",kitapAdi[0],kitap_Index+1);
				}
				break;
			case 'G':
				kitapGoruntule(kitaplik,kitapSayisi);
				break;
			case 'Q':
				puts("Cikis yapiliyor...Tesekkur Ederiz\n");
				break;
			default:
				puts("Yanlis bir tuslama yaptiniz.");
				break;
		}		
	}while(kullaniciIstegi!='Q');
	*/









	return 0;
	
}










