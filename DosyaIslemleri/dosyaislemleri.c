#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_KARAKTER_SAYISI 50

/*Dosya Tipleri:
1.Metin Dosyalarý:ASCII tabloya göre,byte düzeyinde,geriye dönük ekleme yapýlamýyor, satýr düzeyinde.
2.Ýkili Dosyalarý:0-1 bit karþýlýðýna, geriye dönük ekleme yapabiliyor olmam.

*/

/* Ýsimize yarayacak fonksiyonlar:

1. feof(FILE POINTER)-->>dosyanýn sonuna gelip gelinmediðini söyler.Dosyanýn sonuna gelindiði zaman 0'dan farklý bir deger donuyor, aksi halde 0.
			
2. rewind(FILE POINTER)-->dosyanýn en baþýna dönmemizi saðlar.

3. fseek(FILE POINTER,KAÇ BYTE,NEREDEN ÝTÝBAREN)--->imleci dosyanýn belirli yerlerine götürmemizi saðlar.

		(0)SEEK_SET-->dosyanýn baþýndan itibaren 
		(1)SEEK_CUR->en son kalýnan yerden itibaren.
		(2)SEEK_END->sondan itibaren
		
		- > geriye doðru anlamýna.
		
4. ftell(FILE POINTER)-->kaçýncý byte deðerinde olduðumuzu söyler.

*/

int main(){
	
	char adSoyad[MAX_KARAKTER_SAYISI],bolumBilgisi[MAX_KARAKTER_SAYISI];
	float ortalama;
	FILE *dosya=fopen("deneme.txt","r");//okuma modu
	FILE *dosya2=fopen("deneme2.txt","w");//yazma modu
	
	
	if(dosya!=NULL && dosya2!=NULL){
		printf("Iki dosyaniz da basariyla acildi.\n");
		while(!feof(dosya)){
			fscanf(dosya,"%s%f%s",&adSoyad,&ortalama,&bolumBilgisi);
			printf("Ad Soyad:%s\n Ortalamasi:%.2f\n Bolumu:%s\n",adSoyad,ortalama,bolumBilgisi);
			fprintf(dosya2,"Ad Soyad:%s\nOrtalamasi:%.2f\nBolumu:%s\n\n---------------------\n",adSoyad,ortalama,bolumBilgisi);	
		}
		//rewind(dosya);//dosyanin en basina donmemizi saðlýyor.
		printf("Sonuncu karakter:%d byte degerinde\n",ftell(dosya));
		fseek(dosya,5,0);//baþtan itibaren 5byte
		fseek(dosya,5,1);//kaldýgým yerden itibaren 5byte
		fseek(dosya,-1,2);//sondan bir önceki karaktere getir dedim.
		printf("%d byte degerinde.",ftell(dosya));//kacýncý byte degerinde oldugunu soyluyor.
	}
	else{
		printf("Dosyalar acilirken hata meydana geldi.");
	}

	int kapandiMi;//kapandi kontrolu yapabillmek icin kullanýcam
	kapandiMi=fclose(dosya);//kapandiysa 0 donuyor, kapanmadiysa 0dan farkli bir deger donuyor.
	if(kapandiMi==0){
		printf("Dosya basarili bir sekilde kapatilmistir.\n");
	}	
	else{
		printf("Dosya kapatilirken bir hata meydana geldi");
	}
	kapandiMi=fclose(dosya2);//kapandiysa 0 donuyor, kapanmadiysa 0dan farkli bir deger donuyor.
	if(kapandiMi==0){
		printf("Yazilacak olan dosya basarili bir sekilde kapatilmistir.\n");
	}	
	else{
		printf("Dosya kapatilirken bir hata meydana geldi");
	}
	
	return 0;
}






//////////////////////////////////////////ÝKÝ DOSYANIN ÝÇERÝKLERÝNÝ KARÞILAÞTIRMA.////////////////////////////

int dosyalariKarsilastir(FILE *dosya,FILE *ikinciDosya){
	int karakterSayisi,karakterSayisi2;
	fseek(dosya,0,SEEK_END);//ikisini de dosyanin sonuna gonderdim
	fseek(ikinciDosya,0,SEEK_END);
	karakterSayisi=ftell(dosya);//son karakter kaçýncý byte onu öðrendim, yani karakter sayýsý
	karakterSayisi2=ftell(ikinciDosya);
	printf("Ilk dosya %d adet karakter iceriyor.\n",karakterSayisi);
	printf("Ikinci dosya %d adet karakter iceriyor.\n",karakterSayisi2);
	if(karakterSayisi>karakterSayisi2){
		printf("Ilk dosyanizin boyutu ikinci dosyanizdan daha buyuktur\n");
		return;
	}
	else if(karakterSayisi<karakterSayisi2){
		printf("Ikinci dosyanizin boyutu ilk dosyanizdan daha buyuktur\n");
		return;
	}
	else{
		rewind(dosya);//en bastan karsilastirma yapabilmek icin.
		rewind(ikinciDosya);
		int ch,ch2;
		while(1){
			ch=fgetc(dosya);
			ch2=fgetc(ikinciDosya);
			printf("Dosya1'in karakteri:%c\n'",ch);
			printf("Dosya2'nin karakteri:%c\n'",ch2);
			if(ch==EOF && ch2==EOF){
				break;
			}
			if(ch!=ch2){
				return 0;//karakterler farkli.
			}	
		}
	}
	return 1;//tum karakterler ayni.
}
int main(void){
	FILE *ilkDosya=fopen("deneme.txt","r");
	FILE *ikinciDosya=fopen("deneme2.txt","r");
	if(ilkDosya!=NULL&& ikinciDosya!=NULL){
		int sonuc=dosyalariKarsilastir(ilkDosya,ikinciDosya);
		if(sonuc==1){
			printf("Iki dosya tamamen birbirinin aynisidir.");
		}
		else if(sonuc==0){
			printf("Iki dosya birbirinden farklidir.");
		}
	}

	
	return 0;
}





///////////////////////////////TÜM KARAKTERLERÝ BÜYÜK HARFE ÇEVÝREREK BAÞKA DOSYAYA AKTARMA/////////////////

void buyukHarfeCevir(FILE *dosya,FILE *dosya2){
	int ch;//EOF int deger oldugu.
	while(1){//sonsuz döngü
		ch=fgetc(dosya);
		if(ch==EOF){
			break;//tum harfler buyuk harfe cevrildi.Cikis yapiliyor.
		}
		fputc(toupper(ch),dosya2);
	}
	printf("Donusturme tamamlandi.");
}


int main(void){
	FILE *ilkDosya=fopen("deneme.txt","r");
	FILE *ikinciDosya=fopen("deneme3.txt","r");	
	
	if(ilkDosya==NULL || ikinciDosya==NULL){
		fprintf(stderr,"Dosyalar acilirken bir hata meydana geldi.");
		exit(0);//cikis kodumuz.
	}
	
	buyukHarfeCevir(ilkDosya,ikinciDosya);
	fclose(ilkDosya);
	fclose(ikinciDosya);

	return 0;
}



////////////////////////////////DOSYA ÝCERÝKLERÝNÝ BASKA DOSYAYA TERS AKTARMA//////////////////////////

void tersAktar(FILE *dosya, FILE *ikinciDosya){
	int karakterSayisi,i;
	fseek(dosya,0,SEEK_END);//dosya sonuna geldik.
	karakterSayisi=ftell(dosya);//kaç karakter var öðrendik.
	printf("Karakter Sayisi:%d\n",karakterSayisi);
	fseek(dosya,-1,SEEK_END);//son harfimdeyim.
	for(i=2;i<=karakterSayisi+1;i++){
		int ch=fgetc(dosya);
		printf("%c ",ch);
		fputc(ch,ikinciDosya);
		fseek(dosya,-(i),SEEK_END);
	}
	printf("Tum icerik basariyla aktarildi.");
}

void NKarakteriTersAktar(int N,FILE *dosya,FILE *ikinciDosya){
	char *geciciDizi;//dinamik oluþturulacak.
	int karakterSayisi,i;
	fseek(dosya,0,SEEK_END);
	karakterSayisi=ftell(dosya);//dosyada kac karakter var.
	if(karakterSayisi>=N){
		rewind(dosya);//sondan basa donduk.
		geciciDizi=(char*)malloc(sizeof(char)*N);
		for(i=0;i<N;i++){
			geciciDizi[i]=fgetc(dosya);
			printf("%c ",geciciDizi[i]);	
		}
		for(i=N-1;i>=0;i--){
			fputc(geciciDizi[i],ikinciDosya);
		}
		printf("%d adet karakter aktarildi",N);	
	}
	else{
		printf("N sayisi karakter sayisindan buyuk olamaz.");
	}
}


int main(void){
	
	FILE *ilkDosya=fopen("deneme.txt","r");
	FILE *ikinciDosya=fopen("deneme2.txt","w");
	if(ilkDosya==NULL || ikinciDosya==NULL){
		fprintf(stderr,"Dosyalar acilirken bir hata meydana geldi.");
		exit(0);
	}
	//tersAktar(ilkDosya,ikinciDosya);
	NKarakteriTersAktar(7,ilkDosya,ikinciDosya);
	fclose(ilkDosya);
	fclose(ikinciDosya);
	return 0;
}




//////////////////////////////OGRENCÝ NOT PROGRAMI SÝSTEMÝ////////////////////////////
typedef struct{
	char adSoyad[20],harfNotu;
	int vizeNotu,finalNotu;
	double ortalama;
}ogrenciBilgileri;
double ortalamaHesapla(int vizeNotu,int finalNotu){
	return vizeNotu*0.35+finalNotu*0.65;
}
char harfNotuHesapla(double ortalama){
	if(ortalama>=90){
		return 'A';
	}
	else if(ortalama>=80 && ortalama<90){
		return 'B';
	}
	else if(ortalama>=65 && ortalama<80){
		return 'C';
	}
	else if(ortalama>=50 && ortalama<65){
		return 'D';
	}
	else{
		return 'F';
	}
}
void sonDurumHesapla(FILE *ilkDosya,FILE *ikinciDosya){
	while(!feof(ilkDosya)){
		ogrenciBilgileri ogrenci;
		fscanf(ilkDosya,"%s %d %d",&ogrenci.adSoyad,&ogrenci.vizeNotu,&ogrenci.finalNotu);
		ogrenci.ortalama=ortalamaHesapla(ogrenci.vizeNotu,ogrenci.finalNotu);
		ogrenci.harfNotu=harfNotuHesapla(ogrenci.ortalama);
		if(ogrenci.harfNotu!='F'){
			fprintf(ikinciDosya,"%s\t%d\t%d\t%lf\t%c\t%s\n",ogrenci.adSoyad,ogrenci.vizeNotu,ogrenci.finalNotu,ogrenci.ortalama,ogrenci.harfNotu,"Gectiniz.");
		}
		else{
			fprintf(ikinciDosya,"%s\t%d\t%d\t%lf\t%c\t%s\n",ogrenci.adSoyad,ogrenci.vizeNotu,ogrenci.finalNotu,ogrenci.ortalama,ogrenci.harfNotu,"Kaldiniz.");
		}
	}
	
}


int main(void){
	
	FILE *ilkDosya=fopen("deneme.txt","r");
	FILE *ikinciDosya=fopen("deneme2.txt","w");
	if(ilkDosya==NULL || ikinciDosya==NULL){
		fprintf(stderr,"Dosyalar acilirken hata meydana geldi.");
		exit(0);
	}
	sonDurumHesapla(ilkDosya,ikinciDosya);
	printf("Hesaplama tamamlandi..");
	fclose(ilkDosya);
	fclose(ikinciDosya);

	
	

	return 0;
}




































//ÖDEV SORULARI
/*

1.SORU->Bir dosyadaki kelime sayýsýný sayan fonksiyon yazýnýz ve main kýsýmda bunu test ediniz.

2.SORU->Kullanýcýnýn girdigi bir kelimenin sizin dosyanýzda olup olmadýðýný dönen bir fonksiyon yazýnýz ve main kýsýmda test ediniz.

3.SORU->Cümle baþlarýndaki harfleri büyük harfe çeviren bir program yazýnýz.Ýkinci bir dosyaya yazýnýz.

4.SORU->Dinamik bir þekilde film listesi oluþturunuz,kullanýcýnýn girdiði film isimlerini alýp bunlarý dosyanýza yazdýrýnýz.

*/

//1.SORU
/*
int kelimeSayisiHesapla(FILE *dosya){
	
	int kelimeSayisi=0,ch;
	do{
		ch=fgetc(dosya);
		if(ch==' '|| ch=='.'){
			kelimeSayisi+=1;
		}
	}while(ch!=EOF);
	return kelimeSayisi;
	//ogun birinci su an bu dersi cekiyor.Ýzlemenizi tavsiye ederim.
}

int main(void){
	
	FILE *dosya=fopen("deneme.txt","r");
	if(dosya==NULL){
		fprintf(stderr,"Dosya acilirken bir hata meydana geldi.");
		exit(0);
	}
	int kelimeSayisi=kelimeSayisiHesapla(dosya);
	printf("Dosya %d adet kelime icermektedir.",kelimeSayisi);
	
	
	return 0;
}*/


//2.SORU
/*
int kelimeArama(FILE *dosya,char *str){
	char kelime[20];
	int kelimeSayisi=0;
	while(!feof(dosya)){
		fscanf(dosya,"%s",&kelime);
		kelimeSayisi+=1;
		if(strcmp(kelime,str)==0){
			return kelimeSayisi;
		}	
	}
	return -1;
}


int main(void){
	char arananKelime[20];
	FILE *dosya=fopen("deneme.txt","r");
	if(dosya==NULL){
		fprintf(stderr,"Dosya acilirken hata meydana geldi.");
		exit(0);
	}
	puts("Hangi kelimeyi aradiginizi giriniz:");
	gets(arananKelime);
	int index=kelimeArama(dosya,arananKelime);
	if(index!=-1){
		printf("%s kelimesi dosyanin %d.kelimesi",arananKelime,index);
	}
	else{
		printf("%s kelimesi dosyada bulunamadi.",arananKelime);
	}
	

	return 0;
}
*/


//3.SORU
/*
void buyukHarfeCevir(FILE *dosya, FILE *dosya2){
	int ch;
	ch=fgetc(dosya);// dosyanin ilk harfini elle büyük yapýp , dosya2 e yazdýk.
	fputc(toupper(ch),dosya2);
	while(1){
		ch=fgetc(dosya);
		if(ch==EOF){
			break;
		}
		fputc(ch,dosya2);
		if(ch=='.'){//okudugum karakter nokta ise bir sonraki karakteri büyültüp dosya2'e  yaz.
			ch=fgetc(dosya);
			if(ch==EOF){
				break;
			}
			fputc(toupper(ch),dosya2);
		}	
	}
}

int main(void){
	
	FILE *ilkDosya=fopen("deneme.txt","r");
	FILE *ikinciDosya=fopen("deneme2.txt","w");
	if(ilkDosya==NULL || ikinciDosya==NULL){
		fprintf(stderr,"Dosyalar acilirken bir hata meydana geldi.");
		exit(0);
	}
	buyukHarfeCevir(ilkDosya,ikinciDosya);
	fclose(ilkDosya);
	fclose(ikinciDosya);
	
	return 0;
}

*/


//4.SORU
/*
int main(void){
	int i;
	char *filmListesi[5];
	char film[20];
	FILE *filmDosyasi;
	if((filmDosyasi=fopen("filmDosyasi.txt","w"))==NULL){
		fprintf(stderr,"Dosya acilirken bir hata meydana geldi.");
		exit(0);
	}
	for(i=0;i<5;i++){
		puts("Lutfen istediginiz dizi-film adini girin:");
		gets(film);
		filmListesi[i]=(char*)malloc(sizeof(char)*strlen(film)+1);
		strcpy(filmListesi[i],film);
	}
	for(i=0;i<5;i++){
		fprintf(filmDosyasi,"Film-Dizi Adi:%s\n",filmListesi[i]);
	}
	fclose(filmDosyasi);
	
	return 0;
}*/


