#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Ogrenci{
	char isim[20];
	char soyisim[20];
	float ortalama;
};//veri tipi tanýmýný yaptým.

int main(){
	
	
	//int x;//deðiþken oluþturma.(VERÝ TÝPÝ: ýnt, DEÐÝÞKEN ÝSMÝ: x)
    struct Ogrenci ogr1={"Ogun","Birinci",3.74};//deðiþken oluþturma( VERÝ TÝPÝ: STRUCT Ogrenci, DEÐÝÞKEN ÝSMÝ: ogr1)
	struct Ogrenci ogr2;
	
	strcpy(ogr2.isim,"Duygu");//char cinsinden olduðu için atamalar eþitlik ile yapýlamaz.
	strcpy(ogr2.soyisim,"Keydal");
	ogr2.ortalama=3.70;//eþitlik operatörü ile atadýk.
	
	printf("Ogr1 Degiskeninin ismi:%s\n",ogr1.isim);//degerlere erisim saðladým  ( . operatörü ile eriþim saðladým)
	printf("Ogr1 Degiskeninin soyismi:%s\n",ogr1.soyisim);
	printf("Ogr1 Degiskeninin ortalamasi:%.2f\n",ogr1.ortalama);
	
	printf("\nOgr2 Degiskeninin ismi:%s\n",ogr2.isim);//degerlere erisim saðladým  ( . operatörü ile eriþim saðladým)
	printf("Ogr2 Degiskeninin soyismi:%s\n",ogr2.soyisim);
	printf("Ogr2 Degiskeninin ortalamasi:%.2f\n",ogr2.ortalama);*/
	
	
	//DÝZÝLERLE BÝRLÝKTE KULLANIM
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
	
	
	//ÝÞARETÇÝLERLE BÝRLÝKTE KULLANIM
	
	struct Ogrenci ogr;//degisken tanimlamasi yaptik.
	struct Ogrenci *ogrPtr;//isaretci degiskeni tanimlamasi yaptik
	struct Ogrenci *ogrPtr2;
	ogrPtr=&ogr;//ogrPtr ogr'nin adresini tutuyor,onu iþaret ediyor.
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
	

	
	//DÝNAMÝK BELLEK YÖNETÝMÝYLE BÝRLÝKTE KULLANIM
	int elemanSayisi,i;
	printf("Lutfen ogrenci sayisini giriniz:");
	scanf("%d",&elemanSayisi);
	
	struct Ogrenci *ogrPtr;// malloctan dönen baþlangýç adresini tutar.
	ogrPtr=(struct Ogrenci*)malloc(sizeof(struct Ogrenci)*elemanSayisi);//dinamik bir þekilde deðiþken oluþturdum
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

	free(ogrPtr);//serbest býrakýyoruz, geri veriyoruz.

	return 0;
}

//FONKSÝYONLARLA BÝRLÝKTE KULLANIM
typedef struct{
	char isim[20];//20 byte kaplýyor
	char soyisim[30];//30 byte yer kaplýyor
	float ortalama;	//6 byte.
}Ogrenci;//veri tipi tanýmýný yaptým


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



//ENUMERATÝON KISMI
typedef enum{
	pzt=1,sali=2,crs=3,prs=4,cuma=5,cts=6,pzr=7
}haftaninGunleri;

typedef enum{
	acemi=1,ortaseviye=2,ileriseviye=3,prof=4
}oyunSeviyeleri;

int main(){
	haftaninGunleri gunler;//deðiþken
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
	
	oyunSeviyeleri seviyeler;//deðiþken oluþturdum
	puts("Lutfen oyundaki level karsiligini giriniz:");
	scanf("%d",&seviyeler);
	if(seviyeler==acemi){//sayilardan kurtulmak icin enum yapýyoruz.
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




//UNÝON KISMI
typedef union{
	int intSayi;//4byte
	float floatSayi;//4byte
	double doubleSayi;//8byte/////MAKSÝMUM BYTE SEVÝYESÝNE GÖRE BELÝRLENDÝ
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

///////////////////////SAAT ÇEVÝRME///////////////////////

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



//////////////////////////////URUN BÝLGÝSÝ-EKLEME-OKUMA///////////////////////////////////
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
	urunlerListesi=(urunBilgileri*)calloc(urunSayisi,sizeof(urunBilgileri));//dinamik þekilde ürün deposu oluþturduk
	
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
	Nokta koordinat[4];//N0-->x ve y alýndý N1---->x ve y aldým N2--->x ve y aldým N3--->x ve y aldým
}dikdortgen;

float alanHesapla(dikdortgen kullaniciGirisi){
	float x_kenar,y_kenar;
	x_kenar=kullaniciGirisi.koordinat[1].x-kullaniciGirisi.koordinat[0].x;
	y_kenar=kullaniciGirisi.koordinat[3].y-kullaniciGirisi.koordinat[0].y;
	return x_kenar*y_kenar;
	
}



int main(){
		
	dikdortgen hesaplanacakDortgen;//deðiþken oluþturdum.
	int i;//dongu icin
	for(i=0;i<4;i++){
		printf("Lutfen  N%d koordinati icin sirasiyla x ve y degerlerini giriniz:",i);
		scanf("%d%d",&hesaplanacakDortgen.koordinat[i].x,&hesaplanacakDortgen.koordinat[i].y);
	}
	
	float sonuc=alanHesapla(hesaplanacakDortgen);
	printf("Girdiginiz x-y degerlerine karsilik alan degeri:%.2f",sonuc);
	

	
	return 0;	
}



//ÖDEV SORULARI

/*
1.Soru-> Bir adet kompleks sayi yapýsý oluþturunuz, içinde gerçek ve sanal kýsmý olacak. Oluþturduðunuz bu yapýdan 2 adet deðiþken oluþturup bunlarýn
toplamýný hesaplayacak bir fonksiyon yazýp main kýsýmda sonucu bastýrýnýz.
	(3+4i)+(-8+12i)=-5+16i


2.Soru->Derste de benzerini yaptýðýmýz gibi bir adet saat yapýsý oluþturunuz, içinde saat dakika saniye deðiþkeleri bulunacak. Oluþturduðunuz bu
yapýdan 2 adet deðiþken oluþturup kullanýcýdan deðer okumasý yapýnýz. En son girilen 2 saatin farkýný hesaplayacak bir program yazýp sonucu 
bastýrýnýz.
				16:53:81
				13:21:32


3.Soru->Bir adet kitaplýk projesi yapmanýzý istiyorum,bir adet kitapBilgileri yapýsý oluþturunuz, yapýnýz içinde kitapAdi,kitapYazari,sayfaSayisi,
yayinEvi gibi bilgiler içersin. Main kýsýmda kullanýcýdan alacaðýnýz kitap sayýsýna göre bir dinamik array oluþturup kitaplarý orada saklayýn.
Kitap Ekle, Kitap Ara, Tum Kitaplarý goruntule fonksiyonlarý yazýnýz ve bunlarý main kýsýmda deneyiniz.


4.Soru->3.Soruda yaptýðýnýz kitaplýk projesindeki kitap ekle fonksiyonuna enum yapýsýný kullanarak bir kýsýtlama getirin.2 adet yetki olacak.
Eðer yetkiniz ogrenci ise kitap ekleme yapamayacaksýnýz, eðer ki yetkiniz calisan ise kitap ekleyebilirsiniz.


*/

//1.SORU
/*

typedef struct{
	float gercekKisim;//gerçek sayý 
	float sanalKisim;//i li olan kýsým 
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
		if(kitapDizisi[i].sayfaSayisi==0){//kitapligin o indeksi boþ.
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
		i++;//bir sonraki indeksten boþ yer aramaya devam ediyoruz.
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
			return i;//kitabý buldugum indeks deðerini dönüyorum.
		}
	}
	return -1;
}
*/

//4.SORU
/*
int main(void){
	int kitapSayisi;
	kitapBilgileri *kitaplik;//dinamik þekilde oluþturulan kitapBilgileri dizim.
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










