#include <stdio.h>
#include <math.h>
#include <ctype.h>



int main(int argc,char **argv){
	/*
	int i,sayi,faktoriyel=1;
	printf("Lutfen faktoriyeli hesaplanacak sayiyi giriniz:");
	scanf("%d",&sayi);
	for(i=2;i<=sayi;i++){
		faktoriyel*=i;
	}
	printf("%d!=%d",sayi,faktoriyel);
	
	
	int i,j;
	for(i=2;i<=10;i++){
		for(j=1;j<10;j++){
			int sonuc=pow(i,j);
			printf("%d ",sonuc);
		}
		printf("\n");
	}*/
	
	
	//WHILE DONGUSU
	/*
	int i=0;//dongumun sayaci
	while(1){
		i++;
		if(i==10){
			break;//break g�r�ld��� zaman d�ng� sonlan�r.
		}
		if(i%2==0){
			continue;//alt sat�rlar tamamen atlan�r,d�ng� ba�a d�ner(o iterasyon sonland�r�l�yor)
		}
		printf("i sayisi:%d\n",i);
	}	
	
	//DO-WHILE DONGUSU
	do{
		printf("i sayisi:%d\n",i);
		i++;
	}while(i<0);
	
	int sayi,geciciSayi,basamakSayisi=0;
	printf("Lutfen bir sayi degeri giriniz:");
	scanf("%d",&sayi);
	geciciSayi=sayi;
	printf("Sayinin Tersi:");
	while(geciciSayi!=0){
		printf("%d",geciciSayi%10);
		geciciSayi/=10;
		basamakSayisi++;
	}
	printf("\n%d sayisi %d basamaklidir.\n",sayi,basamakSayisi);
	


	//ASAL SAYI SORGULAMA
	
	int sorgulanacakSayi,i,bolunduMu=0;//bolunurse 1 olacak
	printf("Lutfen sorgulanacak sayiyi giriniz:");
	scanf("%d",&sorgulanacakSayi);
	for(i=2;i<sorgulanacakSayi;i++){
		if(sorgulanacakSayi%i==0){
			bolunduMu=1;
			break;
		}
	}
	
	if(bolunduMu==0){
		printf("%d sayisi asal bir sayidir.",sorgulanacakSayi);
	}
	else{
		printf("%d sayisi asal bir sayi degildir",sorgulanacakSayi);
	}
	
	
	
	//EBOB-EKOK HESAPLAMA
	
	int sayi1,sayi2,EBOB,EKOK;
	int sayac,buyukSayi,kucukSayi;
	
	printf("Lutfen EBOB-EKOK bulunacak iki adet sayi giriniz:");
	scanf("%d%d",&sayi1,&sayi2);
	
	if(sayi1>sayi2){
		buyukSayi=sayi1;
		kucukSayi=sayi2;
	}
	else{
		buyukSayi=sayi2;
		kucukSayi=sayi1;
	}
	
	//EKOK:
	sayac=buyukSayi;
	while(1){
		if(sayac%buyukSayi==0 && sayac%kucukSayi==0){
			EKOK=sayac;
			break;
		}
		sayac++;		
	}
	
	//EBOB:
	sayac=kucukSayi;
	while(1){
		if(buyukSayi%sayac==0 && kucukSayi%sayac==0){
			EBOB=sayac;
			break;
		}
		sayac--;
	}
	printf("%d ve %d sayilarinin EBOB degeri:%d, EKOK degeri:%d",sayi1,sayi2,EBOB,EKOK);

	

	char ch;
	int boslukSayisi=0;
	printf("Lutfen bosluk sayisi belirlenecek cumleyi giriniz.");
	do{
		ch=getchar();//karakter alma.
		if(ch==' '){
			boslukSayisi++;
		}	
	}while(ch!='\n');
	
	printf("Girdiginiz cumlede %d adet bosluk karakteri gecmektedir.\n",boslukSayisi);

	*/
	
	
	//SAYIYI-TERSE �EV�RME
	/*
	int sayi,geciciSayi,sayininTersi=0,kalan;
	
	printf("Lutfen tersi alinacak sayiyi giriniz:");
	scanf("%d",&sayi);
	geciciSayi=sayi;
	
	while(geciciSayi!=0){
		kalan=geciciSayi%10;
		sayininTersi=sayininTersi*10+kalan;
		geciciSayi/=10;
	
	}	
	printf("%d sayinin tersi:%d",sayi,sayininTersi);
	

	
	
	
	//BIT-DUZEYINE CEVIRME(0-1 DUZEYINE)
	
	int sayi,geciciSayi,i=0;
	char bitArray[32];
	
	printf("Lutfen bit duzeyine cevrilecek sayiyi giriniz:");
	scanf("%d",&sayi);
	geciciSayi=sayi;
	
	while(geciciSayi!=0){
		if(geciciSayi%2==0){
			bitArray[i]='0';
		}
		else{
			bitArray[i]='1';
		}
		i++;
		geciciSayi/=2;
	}

	printf("%d sayisinin bit karsiligi:",sayi);
	while(i>=0){
		printf("%c",bitArray[i]);
		i--;
	}
	*/

//�DEV SORULARI	
/*
	1.Soru->*               ******          ***********			    *1
			** 				*****			*********			   ***3
			***				****			*******				  *****5  
			****			***				*****			     *******7 
			*****			**				***	                *********9
			******          *   			*                  ***********11
	2.Soru->�ifre Sorgulama.Kullan�c�dan d�ng� i�inde karakterler al�p �ifre uygunlu�u sorgulama(Bo�luk sayma �rne�inde yapt���m�z gibi.)
		-B�y�k harf k���k harf kullan�lmas� gerek.
		-Say� kullan�lm�� olmas� gerek.
		-�ifrenin 8 karakterden uzun olmu� olmas� gerek.
		-�ifrenin 16 karakterden k�sa olmas� gerek.
	3.Soru->Kullan�c�dan bir adet say� al�n�p say�n�n m�kemmel say� olup olmad��� sorgulanacak.
		M�kemmel Say�= Kendisi hari� b�t�n pozitif b�len say�lar� toplad���n�z zaman kendisini veren say�!
			�rne�in 6 say�s�: 3 +2 +1=6.
		NOT:Ekstra olarak, 1 ile 1000 aras�ndaki t�m m�kemmel say�lar� yazd�rmaya �al��abilirsiniz	
	4.Soru-> Kullan�c�dan bir de�er aral��� al�p o aral�ktaki t�m asal say�lar� yazd�ran program yap�n�z(Asal say� sorgulamay� derste g�rm��t�k)
	5.Soru-> Girilen bir say�n�n Armstrong say�s� olup olmad���n� sorgulay�n.
		Armstrong Say�= Say� basamaklar�n�n ayr� ayr� k�pleri al�n�p topland���nda kendisini veren say�
		�rne�in 371 say�s�: 3^3+7^3+1^3=371
		NOT:Ekstra olarak, 1 ile 1000 aras�ndaki t�m Armstrong say�lar�n� yazd�rmaya �al��abilirsiniz	
	6.Soru-> 3.Soruda yapt���m�z m�kemmel say� sorgusunu d�ng� �art� kullanmay�p sadece break ve continue ile yap�n�z.	

*/
//1.SORU		
/*	
	int piramitLimit,i,j;
	printf("Lutfen piramit limitini giriniz:");
	scanf("%d",&piramitLimit);
	
	for(i=1;i<=piramitLimit;i++){
		for(j=0;j<i;j++){
			printf("*");
		}
		printf("\n");
	}
	
	for(i=0;i<piramitLimit;i++){
		for(j=piramitLimit-i;j>0;j--){
			printf("*");
		}
		printf("\n");
	}
	
	for(i=0;i<piramitLimit;i+=2){
		for(j=piramitLimit-i;j>0;j--){
			printf("*");
		}
		printf("\n");
	}
	
	for(i=1;i<=piramitLimit;i+=2){
		for(j=0;j<(piramitLimit-i)/2;j++){
			printf(" ");
		}
		for(j=0;j<i;j++){
			printf("*");
		}
		for(j=0;j<(piramitLimit-i)/2;j++){
			printf(" ");
		}
		printf("\n");
	}
*/	
	
	//2.SORU
/*
	int kucukHarfSorgu=0,buyukHarfSorgu=0,sayiSorgu=0,karakterSayisi=0;
	char ch;
	printf("Lutfen bir sifre giriniz:");
	do{
		ch=getchar();
		if(kucukHarfSorgu==0){
			if(islower(ch)){
				kucukHarfSorgu=1;
			}
		}
		if(buyukHarfSorgu==0){
			if(isupper(ch)){
				buyukHarfSorgu=1;
			}
		}
		if(sayiSorgu==0){
			if(isdigit(ch)){
				sayiSorgu=1;
			}
		}
		karakterSayisi++;
	}while(ch!='\n');
	
	if(kucukHarfSorgu && buyukHarfSorgu && sayiSorgu && karakterSayisi>=8 && karakterSayisi<=16){
		printf("Sifreniz kabul edilmistir.");
	}
	else{
		printf("Sifreniz kabul edilmemistir.");
	}
*/	
	
	
	//3.SORU
/*	
	int sayi,toplam,i,j;
	/*printf("Lutfen sorgulanacak olan sayiyi giriniz:");
	scanf("%d",&sayi);
	for(i=1;i<sayi;i++){
		if(sayi%i==0){
			toplam+=i;
		}
	}
	if(toplam==sayi){
		printf("%d sayisi mukemmel bir sayidir.",sayi);
	}
	else{
		printf("%d sayisi mukemmel bir sayi degildir.",sayi);
	}
	for(i=2;i<=10000000000;i++){
		toplam=0;
		for(j=1;j<i;j++){
			if(i%j==0){
				toplam+=j;
			}
		}
		if(i==toplam){
			printf("%d sayisi mukemmel bir sayidir.\n",i);
		}	
	}
*/	
	//4.SORU
/*	
	int altLimit,ustLimit,bolunmeSorgusu;
	int i,j;
	
	printf("Lutfen alt ve ust limit bilgilerini giriniz:");
	scanf("%d%d",&altLimit,&ustLimit);
	
	for(i=altLimit;i<=ustLimit;i++){
		bolunmeSorgusu=0;
		for(j=2;j<i;j++){
			if(i%j==0){
				bolunmeSorgusu=1;
				break;//geriye kalani kontrol etmeye gerek yok.
			}
		}
		if(!bolunmeSorgusu){
			printf("%d ",i);
		}
	}
	
*/	
	//5.SORU
/*	
	int sayi,geciciSayi,toplam=0,basamak;
	int i;
	
	/*printf("Lutfen kontrol edilecek sayiyi giriniz:");
	scanf("%d",&sayi);
	geciciSayi=sayi;
	
	while(geciciSayi!=0){
		basamak=geciciSayi%10;//1,7,3
		toplam+=pow(basamak,3);//1+7^3+27
		geciciSayi/=10;
	}
	
	if(toplam==sayi){
		printf("%d sayisi bir Armstrong sayisidir.\n",sayi);
	}
	else{
		printf("%d sayisi bir Armstrong sayisi degildir.\n",sayi);
	}
	
	
	for(i=1;i<=1000;i++){
		geciciSayi=i;
		toplam=0;
		while(geciciSayi!=0){
			basamak=geciciSayi%10;
			toplam+=pow(basamak,3);
			geciciSayi/=10;	
		}
		if(i==toplam){
			printf("%d sayisi bir Armstrong sayisidir.\n",i);
		}	
	}
	
*/
	//6.SORU
/*	
	int sayi,i=1,toplam=0;
	
	printf("Lutfen sorgulanacak sayiyi giriniz:");
	scanf("%d",&sayi);
	//6,1 2 3 4 5
	while(1){
		if(i==sayi){
			break;
		}
		if(sayi%i==0){
			toplam+=i;
		}
		i++;	
	}
	
	if(toplam==sayi){
		printf("%d sayisi mukemmel bir sayidir.\n",sayi);
	}
	else{
		printf("%d sayisi mukemmel bir sayi degildir.\n",sayi);
	}
*/	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


	
	return 0;
}
