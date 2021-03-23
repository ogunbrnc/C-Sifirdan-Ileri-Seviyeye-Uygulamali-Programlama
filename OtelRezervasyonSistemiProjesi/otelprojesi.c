#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ODA_SAYISI 100

typedef struct{
	char *musteriAdi;
	char *musteriSoyadi;
}musteriBilgileri;

typedef struct{
	int gun;
	int ay;
	int yil;
}tarihBilgileri;

typedef struct{
	int kisiSayisi;
	int odaDurumu;//doluysa 1, bossa 0.
	int odaNumarasi;//1-100 arasýnda.
	double fiyatBilgisi;
	musteriBilgileri musteri;
	tarihBilgileri girisTarihi;
	tarihBilgileri cikisTarihi;
}odaBilgileri;

typedef enum{
	musteri=0,personel=1
}yetkiSeviyeleri;

int gunFarkiHesapla(tarihBilgileri girisTarihi, tarihBilgileri cikisTarihi){
	if(girisTarihi.gun>cikisTarihi.gun){
		cikisTarihi.ay-=1;
		cikisTarihi.gun+=30;
	}
	if(girisTarihi.ay>cikisTarihi.ay){
		cikisTarihi.yil-=1;
		cikisTarihi.ay+=12;	
	}
	tarihBilgileri tarihFarki;
	tarihFarki.gun=cikisTarihi.gun-girisTarihi.gun;
	tarihFarki.ay=cikisTarihi.ay-girisTarihi.ay;
	tarihFarki.yil=cikisTarihi.yil-girisTarihi.yil;
	
	int gunFarki=tarihFarki.yil*365+tarihFarki.ay*30+tarihFarki.gun;
	return gunFarki;

}


double fiyatHesaplama(odaBilgileri *odalar,int odaNumarasi){
	int gunFarki=gunFarkiHesapla(odalar[odaNumarasi-1].girisTarihi,odalar[odaNumarasi-1].cikisTarihi);
	printf("Kalacaginiz gun sayisi:%d\n",gunFarki);
	return gunFarki*150*odalar[odaNumarasi-1].kisiSayisi;
}


void rezervasyonTemizle(odaBilgileri *odalar,int odaNumarasi){
	odalar[odaNumarasi-1].odaDurumu=0;//odayi bosalttik
	free(odalar[odaNumarasi-1].musteri.musteriAdi);//musteri adi ve soyadi icin ayrilan alanlar bosalildi.
	free(odalar[odaNumarasi-1].musteri.musteriSoyadi);
	printf("%d numarali odanin cikis/iptal islemi tamamlanmistir.\n",odaNumarasi);
}

void doluOdaBilgileriYazdirma(odaBilgileri *odalar){
	int i;
	for(i=0;i<ODA_SAYISI;i++){
		if(odalar[i].odaDurumu!=0){//1 ise oda dolu,0 ise bos.
			printf("-------------------------------------------------------------------------\n");
			printf("Oda Numarasi:%d\n",odalar[i].odaNumarasi);
			printf("Musteri Adi-Soyadi:%s %s\n",odalar[i].musteri.musteriAdi,odalar[i].musteri.musteriSoyadi);
			printf("Kisi Sayisi:%d\n",odalar[i].kisiSayisi);
			printf("Fiyat Bilgisi:%.2lf\n",odalar[i].fiyatBilgisi);
			printf("Giris Tarihi:%d:%d:%d\n",odalar[i].girisTarihi.gun,odalar[i].girisTarihi.ay,odalar[i].girisTarihi.yil);
			printf("Cikis Tarihi:%d:%d:%d\n",odalar[i].cikisTarihi.gun,odalar[i].cikisTarihi.ay,odalar[i].cikisTarihi.yil);	
		}
	}
}

void yeniMusteriEkleme(odaBilgileri *odalar){
	
	int sorgulanacakOda;
	char musteriAdi[20],musteriSoyadi[20],ch;
	
	printf("Lutfen kayit olmak istediginiz odayi giriniz:");
	scanf("%d",&sorgulanacakOda);
	
	if(odalar[sorgulanacakOda-1].odaDurumu!=0){
		printf("Maalesef.Kayit yaptirmak istediginiz oda %d:%d:%d tarihine kadar doludur.",odalar[sorgulanacakOda-1].cikisTarihi.gun,odalar[sorgulanacakOda-1].cikisTarihi.ay,odalar[sorgulanacakOda-1].cikisTarihi.yil);
		return;
	}	
	
	odalar[sorgulanacakOda-1].odaNumarasi=sorgulanacakOda;//ODA NUMARASI ATANDI
	
	printf("Lutfen ad ve soyad bilgilerinizi sirasiyla giriniz:");
	scanf("%s%s",&musteriAdi,&musteriSoyadi);
	
	odalar[sorgulanacakOda-1].musteri.musteriAdi=(char*)malloc(sizeof(char)*strlen(musteriAdi)+1);
	odalar[sorgulanacakOda-1].musteri.musteriSoyadi=(char*)malloc(sizeof(char)*strlen(musteriSoyadi)+1);
	strcpy(odalar[sorgulanacakOda-1].musteri.musteriAdi,musteriAdi);
	strcpy(odalar[sorgulanacakOda-1].musteri.musteriSoyadi,musteriSoyadi);
	
	printf("Lutfen kac kisi olacaginizi giriniz:");
	scanf("%d",&odalar[sorgulanacakOda-1].kisiSayisi);
	
	printf("Lutfen giris tarihi bilgisini (gun:ay:yil) seklinde giriniz:");
	scanf("%d:%d:%d",&odalar[sorgulanacakOda-1].girisTarihi.gun,&odalar[sorgulanacakOda-1].girisTarihi.ay,&odalar[sorgulanacakOda-1].girisTarihi.yil);
	
	printf("Lutfen cikis tarihi bilgisini (gun:ay:yil) seklinde giriniz:");
	scanf("%d:%d:%d",&odalar[sorgulanacakOda-1].cikisTarihi.gun,&odalar[sorgulanacakOda-1].cikisTarihi.ay,&odalar[sorgulanacakOda-1].cikisTarihi.yil);
	
	odalar[sorgulanacakOda-1].fiyatBilgisi=fiyatHesaplama(odalar,sorgulanacakOda);
	printf("Odemeniz gereken total tutar:%.2lfTL\n",odalar[sorgulanacakOda-1].fiyatBilgisi);
	printf("Onayliyor musunuz(E-H):");
	fflush(stdin);
	ch=getchar();
	if(ch=='H'){
		rezervasyonTemizle(odalar,sorgulanacakOda);
		return;
	}
	odalar[sorgulanacakOda-1].odaDurumu=1;// yani odamýz doldu.
}
void odaBilgisiSorgulama(odaBilgileri *odalar,int odaNumarasi){
	if(odalar[odaNumarasi-1].odaDurumu!=0){//yani doluysa.0 bos 1 dolu
		printf("%d numarali oda %d:%d:%d tarihine kadar doludur.\n",odaNumarasi,odalar[odaNumarasi-1].cikisTarihi.gun,odalar[odaNumarasi-1].cikisTarihi.ay,odalar[odaNumarasi-1].cikisTarihi.yil);
	}
	else{
		printf("%d numarali oda su an bos durumdadir\n",odaNumarasi);
	}
}
void fiyatBilgisiYazdirma(){
	int kisiSayisi;
	double toplamTutar=0.0;
	tarihBilgileri girisTarihi,cikisTarihi;
	
	printf("Lutfen kac kisi olacaginizi giriniz:");
	scanf("%d",&kisiSayisi);
	printf("Lutfen giris tarihi bilgisini (gun:ay:yil) seklinde giriniz:");
	scanf("%d:%d:%d",&girisTarihi.gun,&girisTarihi.ay,&girisTarihi.yil);
	
	printf("Lutfen cikis tarihi bilgisini (gun:ay:yil) seklinde giriniz:");
	scanf("%d:%d:%d",&cikisTarihi.gun,&cikisTarihi.ay,&cikisTarihi.yil);
	
	toplamTutar=gunFarkiHesapla(girisTarihi,cikisTarihi)*kisiSayisi*150;//150->1gunluk 1 kisinin ücreti.
	printf("Odemeniz gereken toplam tutar:%.2lf",toplamTutar);
}

void yedekKayitAlma(odaBilgileri *odalar){
	int i;
	FILE *otelKayitlari=fopen("otelKayitlari.txt","a");
	if(otelKayitlari==NULL){
		fprintf(stderr,"Yedek kayit alinirken bir hata meydana geldi.");
		exit(1);
	}
	for(i=0;i<ODA_SAYISI;i++){
		if(odalar[i].odaDurumu!=0){
			fprintf(otelKayitlari,"-----------------------------------------------------------------------------\n");
			fprintf(otelKayitlari,"Oda Numarasi:%d\n",odalar[i].odaNumarasi);
			fprintf(otelKayitlari,"Musterinin Adi-Soyadi:%s %s\n",odalar[i].musteri.musteriAdi,odalar[i].musteri.musteriSoyadi);
			fprintf(otelKayitlari,"Kisi Sayisi:%d\n",odalar[i].kisiSayisi);
			fprintf(otelKayitlari,"Toplam Tutar:%.2lfTL\n",odalar[i].fiyatBilgisi);
			fprintf(otelKayitlari,"Giris Tarihi:%d:%d:%d\n",odalar[i].girisTarihi.gun,odalar[i].girisTarihi.ay,odalar[i].girisTarihi.yil);
			fprintf(otelKayitlari,"Cikis Tarihi:%d:%d:%d\n",odalar[i].cikisTarihi.gun,odalar[i].cikisTarihi.ay,odalar[i].cikisTarihi.yil);
		}
	}
	fclose(otelKayitlari);
}

int main(){
	int belirlenenSifre=123456,kullanicininGirdigiSifre,odaNumarasi;
	yetkiSeviyeleri kullaniciYetkisi;
	char ch;
	odaBilgileri *odaDizisi;//tum bilgiler burada tutulacak.
	odaDizisi=(odaBilgileri*)calloc(ODA_SAYISI,sizeof(odaBilgileri));//dinamik þekilde oluþurduk.
	printf("\t\t\t\tOtel Rezervasyon sistemine hosgeldiniz...\n");
	printf("Lutfen burada calisiyorsaniz sifrenizi giriniz:");
	scanf("%d",&kullanicininGirdigiSifre);
	if(belirlenenSifre==kullanicininGirdigiSifre){//kullanici otelin bir calisani, yetkisi personel
		kullaniciYetkisi=personel;
	}
	else{//yetkisi musteri.
		kullaniciYetkisi=musteri;
	}
	do{
		printf("1.Yeni musteri girisi yapmak istiyorsaniz 'E'\n2.Oda bilgisi sorgulamak istiyorsaniz 'S'\n3.Dolu oda bilgilerini goruntulemek istiyorsaniz 'G'\n4.Fiyat sorgusu yapmak istiyorsaniz 'F'\n");
		printf("5.Musteri cikisi gerceklestirmek istiyorsaniz 'C'\n6.Sistemden cikis yapmak istiyorsaniz 'Q' tuslayiniz:");
		fflush(stdin);
		ch=getchar();
		switch(ch){
			case 'E':
			case 'e':
				if(kullaniciYetkisi==personel){
					yeniMusteriEkleme(odaDizisi);
				}
				else{
					printf("Bu alan sadece calisanlar tarafindan kullanilabilir.");
				}
				break;
			case 'S':
			case 's':
				printf("Lutfen sorgulanacak olan odanin numarasini giriniz:");
				scanf("%d",&odaNumarasi);
				odaBilgisiSorgulama(odaDizisi,odaNumarasi);			
				break;
			case 'G':
			case 'g':
				if(kullaniciYetkisi==personel){
					doluOdaBilgileriYazdirma(odaDizisi);
				}
				else{
					printf("Bu alan sadece calisanlar tarafindan kullanilabilir.");
				}
				break;
			case 'C':
			case 'c':
				if(kullaniciYetkisi==personel){
					printf("Cikis yapmak istediginiz odanin numarasini giriniz:");
					scanf("%d",&odaNumarasi);
					rezervasyonTemizle(odaDizisi,odaNumarasi);//daha onceden kulllandýgýmýz rezervasyontemizle fonksiyonu.
				}
				else{
					printf("Bu alan sadece calisanlar tarafindan kullanilabilir.");
				}
				break;
			case 'F':
			case 'f':
				fiyatBilgisiYazdirma();
				break;
			case 'Q':
			case 'q':
				yedekKayitAlma(odaDizisi);
				break;
			default:	
				break;
		}
	}while(ch!='Q');
	return 0;
}
