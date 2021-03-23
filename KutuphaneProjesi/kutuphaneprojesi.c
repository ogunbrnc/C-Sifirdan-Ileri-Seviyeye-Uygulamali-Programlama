#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_KISI_SAYISI 50
#define MAX_KITAP_SAYISI 50

typedef enum{
	ogrenci=0,calisan=1
}kisiYetkiSeviyeleri;

typedef struct{
	char *kisiAdi;
	char *kisiSoyadi;
	int kutuphaneID;
	int sifre;
	kisiYetkiSeviyeleri kisiYetkisi;
}kisiBilgileri;

typedef struct{
	char *kitapAdi;
	char *kitapYazarAdi;
	char *kitapYazarSoyadi;
	char *yayinEvi;
	int sayfaSayisi;
	int kitapDurumu;
}kitapBilgileri;
int kisiSorgula(kisiBilgileri *uyeListesi,int ID){
	int i;
	for(i=0;i<MAX_KISI_SAYISI;i++){
		if(uyeListesi[i].kutuphaneID==ID){
			return ID;//bu ID daha önce kullanýldý.
		}
	}
	return -1;//bu ID daha önce hiç kullanýlmadý.	
}

int kayitOl(kisiBilgileri *uyeListesi){
	
	int i,kayitYapilacakIndex,ID;
	char kisiAdi[20],kisiSoyadi[20],ch;
	
	srand(time(NULL));//ID FARKLILIÐI ÝÇÝN
	for(i=0;i<MAX_KISI_SAYISI;i++){
		if(uyeListesi[i].kutuphaneID==0){
			kayitYapilacakIndex=i;
			break;
		}
	}
	ID=rand()%100000+1;
	if(kisiSorgula(uyeListesi,ID)!=-1){
		printf("Bu ID degeri daha once kullanilmistir...Kayit yapilamiyor.\n");
		exit(1);	
	}
	printf("ID numaraniz %d olarak belirlenmistir.",ID);
	uyeListesi[kayitYapilacakIndex].kutuphaneID=ID;
	
	printf("Lutfen sirasiyla ad-soyad bilginizi giriniz:");
	scanf("%s%s",&kisiAdi,&kisiSoyadi);
	
	uyeListesi[kayitYapilacakIndex].kisiAdi=(char*)malloc(sizeof(char)*(strlen(kisiAdi)+1));
	uyeListesi[kayitYapilacakIndex].kisiSoyadi=(char*)malloc(sizeof(char)*(strlen(kisiSoyadi)+1));
	strcpy(uyeListesi[kayitYapilacakIndex].kisiAdi,kisiAdi);
	strcpy(uyeListesi[kayitYapilacakIndex].kisiSoyadi,kisiSoyadi);
	
	printf("Lutfen ogrenciyseniz 'O' calisansaniz 'C' giriniz:");
	fflush(stdin);
	ch=getchar();
	if(ch=='O'){
		uyeListesi[kayitYapilacakIndex].kisiYetkisi=ogrenci;
	}
	else{
		uyeListesi[kayitYapilacakIndex].kisiYetkisi=calisan;
	}
	
	printf("Lutfen sifrenizi giriniz:");
	scanf("%d",&uyeListesi[kayitYapilacakIndex].sifre);
	
	return uyeListesi[kayitYapilacakIndex].kisiYetkisi;	
}


void kitaplariGoruntule(kitapBilgileri *kitaplik){
	int i;
	for(i=0;i<MAX_KITAP_SAYISI;i++){
		if(kitaplik[i].sayfaSayisi!=0){
			printf("Kitap Adi:%s\n",kitaplik[i].kitapAdi);
			printf("Kitap Yazari:%s %s\n",kitaplik[i].kitapYazarAdi,kitaplik[i].kitapYazarSoyadi);
			printf("Kitap Yayinevi:%s\n",kitaplik[i].yayinEvi);
			printf("Kitap Sayfa Sayisi:%d\n",kitaplik[i].sayfaSayisi);
			if(kitaplik[i].kitapDurumu==0){
				printf("Bu kitap su an raftadir.\n");
			}
			else{
				printf("Bu kitap su an baskasi tarafindan alinmistir.\n");
			}
			printf("--------------------------------------------------------------------------------------\n");
		}
		else{
			return;
		}
	}
}

void kitapAra(kitapBilgileri *kitaplik){
	int i=0;
	char kitapAdi[30];
	
	printf("Lutfen aramak istediginiz kitabin adini giriniz:");
	scanf("%s",&kitapAdi);
	
	while(i<MAX_KITAP_SAYISI && kitaplik[i].sayfaSayisi!=0){
		if(strcmp(kitaplik[i].kitapAdi,kitapAdi)==0){
			printf("Kitap Adi:%s\n",kitaplik[i].kitapAdi);
			printf("Kitap Yazari:%s %s\n",kitaplik[i].kitapYazarAdi,kitaplik[i].kitapYazarSoyadi);
			printf("Kitap Yayinevi:%s\n",kitaplik[i].yayinEvi);
			printf("Kitap Sayfa Sayisi:%d\n",kitaplik[i].sayfaSayisi);	
			return;	
		}
		i++;
	}
	printf("Maalesef...Aradiginiz kitap kutuphanemizde bulunmuyor.\n");
}

void kitapEkle(kitapBilgileri *kitaplik){
	int sayfaSayisi,i;
	char kitapAdi[30],yayinEvi[30],yazarAdi[30],yazarSoyadi[30];
	printf("Lutfen kitap adini giriniz:");
	scanf("%s",&kitapAdi);
	printf("Lutfen kitap yayinevi bilgisini giriniz:");
	scanf("%s",&yayinEvi);
	printf("Lutfen kitabin yazar adini ve soyadini sirasiyla giriniz:");
	scanf("%s %s",&yazarAdi,&yazarSoyadi);
	printf("Lutfen kitabin sayfa sayisini giriniz:");
	scanf("%d",&sayfaSayisi);
	
	for(i=0;i<MAX_KITAP_SAYISI;i++){
		if(kitaplik[i].sayfaSayisi==0){
			kitaplik[i].kitapAdi=(char*)malloc(sizeof(char)*(strlen(kitapAdi)+1));
			kitaplik[i].yayinEvi=(char*)malloc(sizeof(char)*(strlen(yayinEvi)+1));
			kitaplik[i].kitapYazarAdi=(char*)malloc(sizeof(char)*(strlen(yazarAdi)+1));
			kitaplik[i].kitapYazarSoyadi=(char*)malloc(sizeof(char)*(strlen(yazarSoyadi)+1));
			strcpy(kitaplik[i].kitapAdi,kitapAdi);
			strcpy(kitaplik[i].kitapYazarAdi,yazarAdi);
			strcpy(kitaplik[i].kitapYazarSoyadi,yazarSoyadi);
			strcpy(kitaplik[i].yayinEvi,yayinEvi);
			kitaplik[i].sayfaSayisi=sayfaSayisi;
			break;	
		}
	}	
}

void uyeleriGoruntule(kisiBilgileri *uyeListesi){
	int i=0;
	while(i<MAX_KISI_SAYISI && uyeListesi[i].kutuphaneID!=0){
		printf("Uye Adi-Soyadi:%s %s\n",uyeListesi[i].kisiAdi,uyeListesi[i].kisiSoyadi);
		printf("Uye ID Bilgisi:%d\n",uyeListesi[i].kutuphaneID);
		if(uyeListesi[i].kisiYetkisi==1){
			printf("Uye Durumu: Calisan\n");
		}
		else{
			printf("Uye Durumu: Ogrenci\n");
		}
		printf("--------------------------------------------------------------------------------------\n");
		i++;	
	}	
}





int girisYap(kisiBilgileri *uyeListesi){
	int ID,sifre,i;
	printf("Lutfen kutuphane ID bilginizi giriniz:");
	scanf("%d",&ID);
	printf("Lutfen kutuphane sifre bilginizi giriniz:");
	scanf("%d",&sifre);
	for(i=0;i<MAX_KISI_SAYISI;i++){
		if(uyeListesi[i].kutuphaneID==ID){
			if(uyeListesi[i].sifre==sifre){
				printf("ID-Sifre dogru...Giris Basarili.\n");
				return uyeListesi[i].kisiYetkisi;
			}
			return -1;//sifre yanlis girildi.giris basarisiz.	
		}	
	}
	return -2;//O ID DEÐERÝNE AÝT KÝMSE BULUNAMADI.	
}

void uyeleriAktar(kisiBilgileri *uyeListesi){
	FILE *uyeKayitlari;
	int i;
	char ad[20],soyad[20];
	
	uyeKayitlari=fopen("uyeListesi.txt","r");
	if(uyeKayitlari==NULL){
		fprintf(stderr,"Uye listesine ulasilirken bir hata meydana geldi.\n");
		exit(1);
	}
	
	while(!feof(uyeKayitlari)){
		for(i=0;i<MAX_KISI_SAYISI;i++){
			if(uyeListesi[i].kutuphaneID==0){
				fscanf(uyeKayitlari,"%s\t%s\t%d\t%d\t%d\n",ad,soyad,&uyeListesi[i].kisiYetkisi,&uyeListesi[i].kutuphaneID,&uyeListesi[i].sifre);
				uyeListesi[i].kisiAdi=(char*)malloc(sizeof(char)*(strlen(ad)+1));
				uyeListesi[i].kisiSoyadi=(char*)malloc(sizeof(char)*(strlen(soyad)+1));
				strcpy(uyeListesi[i].kisiAdi,ad);
				strcpy(uyeListesi[i].kisiSoyadi,soyad);
				break;	
			}
			
		}
	}
	fclose(uyeKayitlari);
}

void kitaplariAktar(kitapBilgileri *kitaplik){
	char kitapAdi[30],yazarAdi[30],yayinEvi[30],yazarSoyadi[30];
	FILE *kitapKayitlari;
	int i;
	
	kitapKayitlari=fopen("kitapListesi.txt","r");
	if(kitapKayitlari==NULL){
		fprintf(stderr,"Kitap listesine ulasilirken bir hata meydana geldi.\n");
		exit(1);
	}
	
	while(!feof(kitapKayitlari)){
		for(i=0;i<MAX_KITAP_SAYISI;i++){
			if(kitaplik[i].sayfaSayisi==0){
				fscanf(kitapKayitlari,"%s\t%s\t%s\t%s\t%d\t%d\n",kitapAdi,yayinEvi,yazarAdi,yazarSoyadi,&kitaplik[i].kitapDurumu,&kitaplik[i].sayfaSayisi);
				kitaplik[i].kitapAdi=(char*)malloc(sizeof(char)*(strlen(kitapAdi)+1));
				kitaplik[i].kitapYazarAdi=(char*)malloc(sizeof(char)*(strlen(yazarAdi)+1));
				kitaplik[i].kitapYazarSoyadi=(char*)malloc(sizeof(char)*(strlen(yazarSoyadi)+1));
				kitaplik[i].yayinEvi=(char*)malloc(sizeof(char)*(strlen(yayinEvi)+1));
				strcpy(kitaplik[i].kitapAdi,kitapAdi);
				strcpy(kitaplik[i].kitapYazarAdi,yazarAdi);
				strcpy(kitaplik[i].kitapYazarSoyadi,yazarSoyadi);
				strcpy(kitaplik[i].yayinEvi,yayinEvi);
				break;
	
			}
		}	
	}
	fclose(kitapKayitlari);
}
void kitaplariYedekle(kitapBilgileri *kitaplik){
	FILE *kitapKayitlari;
	int i=0;
	
	kitapKayitlari=fopen("kitapListesi.txt","w");
	if(kitapKayitlari==NULL){
		fprintf(stderr,"Kitap listesine ulasilirken bir hata meydana geldi.\n");
		exit(1);
	}
	
	while(i<MAX_KITAP_SAYISI && kitaplik[i].sayfaSayisi!=0){
		fprintf(kitapKayitlari,"%s\t%s\t%s\t%s\t%d\t%d\n",kitaplik[i].kitapAdi,kitaplik[i].yayinEvi,kitaplik[i].kitapYazarAdi,kitaplik[i].kitapYazarSoyadi,kitaplik[i].kitapDurumu,kitaplik[i].sayfaSayisi);
		i++;	
	}
	fclose(kitapKayitlari);
}
void uyeleriYedekle(kisiBilgileri *uyeListesi){
	FILE *uyeKayitlari;
	int i=0;
	
	uyeKayitlari=fopen("uyeListesi.txt","w");
	if(uyeKayitlari==NULL){
		fprintf(stderr,"Uye listesine ulasilirken bir hata meydana geldi.\n");
		exit(1);
	}
	while(i<MAX_KISI_SAYISI&& uyeListesi[i].kutuphaneID!=0){
		fprintf(uyeKayitlari,"%s\t%s\t%d\t%d\t%d\n",uyeListesi[i].kisiAdi,uyeListesi[i].kisiSoyadi,uyeListesi[i].kisiYetkisi,uyeListesi[i].kutuphaneID,uyeListesi[i].sifre);
		i++;
	}
	fclose(uyeKayitlari);	
}

int main(void){	
	kitapBilgileri *kitaplik;
	kisiBilgileri *uyeListesi;
	kisiYetkiSeviyeleri uyeYetkisi;
	int girisDurumu;
	char ch;
	
	kitaplik=(kitapBilgileri*)calloc(MAX_KITAP_SAYISI,sizeof(kitapBilgileri));
	uyeListesi=(kisiBilgileri*)calloc(MAX_KISI_SAYISI,sizeof(kisiBilgileri));
	
	uyeleriAktar(uyeListesi);//kitaplik ve üyelistesi arraylerine aktarým saðlandý.
	kitaplariAktar(kitaplik);
	
	///KAYIT OL-GÝRÝÞ YAP
	printf("\t\t\tMerhaba,Kutuphane sistemimize hosgeldiniz\n");
	printf("1.Sisteme kayit  olmak istiyorsaniz 'K'\n2.Sisteme giris yapmak istiyorsaniz 'G' tuslayiniz:");
	fflush(stdin);
	ch=getchar();
	if(ch=='K'||ch=='k'){
		girisDurumu=kayitOl(uyeListesi);//ogrenci mi,yoksa calisan mi.
	}
	else if(ch=='G'||ch=='g'){
		girisDurumu=girisYap(uyeListesi);//ogrenci mi,yoksa calisan mi.
		if(girisDurumu==-1){
			printf("Sifrenizi yanlis girdiniz...Giris yapilamiyor.\n");
			exit(1);
		}
		else if(girisDurumu==-2){
			printf("Boyle bir ID degeri sistemde kayitli degil...Giris yapilamiyor.\n");
			exit(1);
		}
	}
	else{
		printf("Yanlis bir tuslama yaptiniz...Sistemden cikiliyor.\n");
		exit(1);
	}
	
	/////UYENIN YETKÝSÝNÝ BELÝRLEME
	if(girisDurumu==1){
		uyeYetkisi=calisan;
	}
	else{
		uyeYetkisi=ogrenci;
	}
	
	if(uyeYetkisi==ogrenci){
		do{
			printf("1.Tum kitaplari goruntulemek icin 'G' tuslayiniz\n2.Kitap aramak icin 'A' tuslayiniz\n3.Cikis yapmak icin 'Q' tuslayiniz:");
			fflush(stdin);
			ch=getchar();
			switch(ch){
				case 'G':
				case 'g':
					kitaplariGoruntule(kitaplik);
					break;
				case 'A':
				case 'a':
					kitapAra(kitaplik);	
					break;
				case 'Q':
				case 'q':
					kitaplariYedekle(kitaplik);//cikis yapilirken, tüm kitaplar ve üye bilgileri dosyaya kaydediliyor.
					uyeleriYedekle(uyeListesi);
					printf("Cikis yapiliyor...");
					break;
				default:
					printf("Hatali bir tuslama yaptiniz");
					break;	
			}
		}while(ch!='Q');		
	}
	else{
		do{
			printf("1.Kitap eklemek istiyorsaniz 'E' tuslayiniz\n2.Tum uyeleri goruntulemek istiyorsaniz 'U' tuslayiniz\n3.Cikis yapmak istiyorsaniz 'Q' tuslayiniz:");
			fflush(stdin);
			ch=getchar();
			switch(ch){
				case 'E':
				case 'e':
					kitapEkle(kitaplik);
					break;
				case 'U':
				case 'u':
					uyeleriGoruntule(uyeListesi);
					break;
				case 'Q':
				case 'q':
					uyeleriYedekle(uyeListesi);
					kitaplariYedekle(kitaplik);
					printf("Cikis yapiliyor...\n");
					break;
				default:
					printf("Yanlis bir tuslama yaptiniz.\n");
					break;
			}
	
		}while(ch!='Q');
	}
	return 0;
}

