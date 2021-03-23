#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
	/*//ayný tip
	//bütün halinde
	//sýralý þekilde
	0000->baþlangýç adresi(1.eleman)(0.indeks)
	0004->(2.eleman)(1.indeks)
	0008->(3.eleman)(3.indeks)
	
		->(N.eleman)(N-1.ideks)
*/
/*
int main(){
	
	int sayiDizisi[10];
	srand(time(NULL));
	//4byte*10=40byte
	
	printf("Dizinin kapladigi alan:%d byte\n",sizeof(sayiDizisi));
	printf("Dizinin 1.elemaninin adresi:%#X ve degeri:%d\n",&sayiDizisi[0],sayiDizisi[0]);
	printf("Dizinin 2.elemaninin adresi:%#X ve degeri:%d\n",&sayiDizisi[1],sayiDizisi[1]);
	printf("Dizinin 3.elemaninin adresi:%#X ve degeri:%d\n",&sayiDizisi[2],sayiDizisi[2]);
	printf("Dizinin 4.elemaninin adresi:%#X ve degeri:%d\n",&sayiDizisi[3],sayiDizisi[3]);
	printf("Dizinin 5.elemaninin adresi:%#X ve degeri:%d\n",&sayiDizisi[4],sayiDizisi[4]);
	
	
	int toplam=0,ortalama,i,enBuyuk,enKucuk;
	int kullaniciGirisi;
	printf("Lutfen bir sayi giriniz:");
	scanf("%d",&kullaniciGirisi);
	
	
	for(i=0;i<10;i++){
		sayiDizisi[i]=rand()%100;
		printf("%d ",sayiDizisi[i]);
	}
	enBuyuk=sayiDizisi[0];
	enKucuk=sayiDizisi[0];
	printf("\n");
	for(i=0;i<10;i++){
		if(sayiDizisi[i]>enBuyuk){
			enBuyuk=sayiDizisi[i];
		}
		if(sayiDizisi[i]<enKucuk){
			enKucuk=sayiDizisi[i];
		}	
		toplam+=sayiDizisi[i];
		printf("%d.eleman eklendi ve yeni toplam:%d\n",i+1,toplam);	
	}
	ortalama=toplam/10;
	printf("Dizinin ortalamasi:%d\n",ortalama);
	printf("Dizinin en buyuk elemani:%d\n",enBuyuk);
	printf("Dizinin en kucuk elemani:%d\n",enKucuk);
	for(i=0;i<10;i++){
		if(sayiDizisi[i]>=ortalama){
			printf("%d sayisi dizinin ortalamasindan buyuk esittir\n",sayiDizisi[i]);
		}
		else{
			printf("%d sayisi dizinin ortalamasindan kucuktur\n",sayiDizisi[i]);
		}	
	}
	for(i=0;i<10;i++){			
		if(sayiDizisi[i]%kullaniciGirisi==0){
			printf("%d sayisi kullanicinin girdigi sayinin bir katidir.\n",sayiDizisi[i]);
		}
	}
	
	//satir sayisi bos gecilebilir,sutun sayisi gecilemez.
	int ikiBoyutluDizi[10][10];
	int i,j;
	printf("Hafizada kapladigi alan:%d byte\n",sizeof(ikiBoyutluDizi));
	
	/*  A00 A01 A02 A03 ... A09
     	A10 A11 A12 A13 ... A19
     	A20 A21 A22 A23 ... A29
	.
	.
	.
  		A90 A91 A92 A93 ... A99*/
  	//i=satirlari temsil ediyor.
  	/*
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			ikiBoyutluDizi[i][j]=i*j;
		}
	}*/
	/*
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(i==j){
				ikiBoyutluDizi[i][j]=1;
			}
			else{
				ikiBoyutluDizi[i][j]=0;
			}
		}
	}*/
	/*
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(i<=j){
				ikiBoyutluDizi[i][j]=1;
			}
			else{
				ikiBoyutluDizi[i][j]=0;
			}
		}
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(i%2==0){
				ikiBoyutluDizi[i][j]=1;
			}
			else{
				ikiBoyutluDizi[i][j]=0;
			}
		}
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			printf("%d ",ikiBoyutluDizi[i][j]);
		}
		printf("\n");
	}
	
	int ucBoyutluDizi[10][10][10];
	printf("Kapladigi alan:%d",sizeof(ucBoyutluDizi));
	

		
	return 0;
}
*/



/*

int main(){
	//MATRÝS TOPLAMA KODU
	int ilkMatris[5][5],ikinciMatris[5][5],toplamMatris[5][5],i,j;
	srand(time(NULL));
	printf("Ilk Matris:\n");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			ilkMatris[i][j]=rand()%10;
			ikinciMatris[i][j]=rand()%10;
			printf("%d\t",ilkMatris[i][j]);
		}
		printf("\n");
	}
	printf("Ikinci Matris:\n");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d\t",ikinciMatris[i][j]);
		}
		printf("\n");
	}
	printf("Toplam Matris:\n");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			toplamMatris[i][j]=ilkMatris[i][j]+ikinciMatris[i][j];
			printf("%d\t",toplamMatris[i][j]);
		}
		printf("\n");
	}
	
	
	
	//TRANSPOZ ALMA KODU
	
	int ilkMatris[5][5],transpozMatris[5][5],i,j;
	srand(time(NULL));
	printf("Ilk Matris:\n");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			ilkMatris[i][j]=rand()%10;
			printf("%d\t",ilkMatris[i][j]);
		}
		printf("\n");
	}
	printf("Transpoz Matris:\n");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			transpozMatris[i][j]=ilkMatris[j][i];
			printf("%d\t",transpozMatris[i][j]);
		}
		printf("\n");
	}
	
	
	
	//DÝZÝDE ARAMA KODU
	
	int dizi[10],i,arananDeger,bulunduMu=0;
	srand(time(NULL));
	printf("Dizi:");
	for(i=0;i<10;i++){
		dizi[i]=rand()%100;
		printf("%d ",dizi[i]);
	}
	printf("\nLutfen aranacak olan degeri giriniz:");
	scanf("%d",&arananDeger);
	for(i=0;i<10;i++){
		if(dizi[i]==arananDeger){
			bulunduMu=1;
			break;
		}
	}
	if(bulunduMu){
		printf("Degerimiz bulundu.");
	}
	else{
		printf("Bulunamadi");
	}
	
	
	
	//DÝZÝ SIRALAMA KODU-1
	int dizi[10],i,j,eleman;
	srand(time(NULL));
	printf("Dizi:\n");
	for(i=0;i<10;i++){
		dizi[i]=rand()%100;
		printf("%d ",dizi[i]);
	}
	printf("\nSirali dizi:\n");
	for(i=0;i<10;i++){
		eleman=dizi[i];
		for(j=i-1;j>=0 && eleman<=dizi[j];j--){
			dizi[j+1]=dizi[j];
		}
		dizi[j+1]=eleman;
	}
	for(i=0;i<10;i++){
		printf("%d ",dizi[i]);
	}
	
	
	
	//DÝZÝ SIRALAMA KODU-2(DÝZÝYE DEÐER ATAMA VE YAZDIRMA KISMI YUKARDA. BURADA DÝZÝ SIRALANIP YAZDIRILACAK.)
	for(i=0;i<9;i++){
		for(j=0;j<9-i;j++){
			if(dizi[j]>dizi[j+1]){
				int gecici=dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=gecici;
			}
		}
	}
	printf("\nSirali Dizi:\n");
	for(i=0;i<10;i++){
		printf("%d ",dizi[i]);
	}
	

	return 0;
}






*/








