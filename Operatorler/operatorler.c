#include <stdio.h>
#include <math.h>
#define pi 3.14


int main(int argc,char **argv){
	//AR�TMET�K OPERAT�RLER
	/*
	int sayi=55,sayi2=2;//atama operat�r�
	printf("%d+%d=%d\n",sayi,sayi2,sayi+sayi2);//toplama operat�r�
	printf("%d-%d=%d\n",sayi,sayi2,sayi-sayi2);//cikarma operat�r�
	printf("%d*%d=%d\n",sayi,sayi2,sayi*sayi2);//carpma operat�r�
	printf("%d/%d=%d\n",sayi,sayi2,sayi/sayi2);//bolme operat�r�
	printf("%d%%%d=%d\n",sayi,sayi2,sayi%sayi2);//mod alma operat�r�
	
	//atama operat�r� ile kullan�m
	int sonuc=1;
	sonuc*=4;//sonuc=sonuc*4;=4
	sonuc*=3;//sonuc=sonuc*3=12
	sonuc*=2;//24
	printf("Sonuc:%d\n",sonuc);
	
	int i=5;
	printf("i degeri:%d\n",++i);//�nce artt�rma, sonra yazd�rma
	printf("i degeri:%d\n",i++);//�nce yazd�rma, sonra artt�rma
	
	//BIT DUZEYINDE ISLEMLER.
	
	int bitDuzeyi=64;
	printf("Sola kaydirilmis sonuc:%d\n",bitDuzeyi<<1);//2 ile carpma anlam�na geliyor
	printf("Saga kaydirilmis sonuc:%d\n",bitDuzeyi>>1);//2 e b�lme anlam�na geliyor.
	*/
	
	//MANTIKSAL OPERAT�RLER-�L��K�SEL OPERAT�RLER
	/*int sayi1=15,sayi2=25;
	printf("Ilk sayi:%d,ikinci sayi:%d,sorgu sonucu(0 veya 1):%d\n",sayi1,sayi2,sayi1>sayi2);//buyuktur
	printf("Ilk sayi:%d,ikinci sayi:%d,sorgu sonucu(0 veya 1):%d\n",sayi1,sayi2,sayi1<sayi2);//kucuktur
	printf("Ilk sayi:%d,ikinci sayi:%d,sorgu sonucu(0 veya 1):%d\n",sayi1,sayi2,sayi1==sayi2);//esittir
	printf("Ilk sayi:%d,ikinci sayi:%d,sorgu sonucu(0 veya 1):%d\n",sayi1,sayi2,sayi1!=sayi2);//esit degildir
	printf("Ilk sayi:%d,ikinci sayi:%d,sorgu sonucu(0 veya 1):%d\n",sayi1,sayi2,sayi1>=sayi2);//buyuk esittir.
	printf("Ilk sayi:%d,ikinci sayi:%d,sorgu sonucu(0 veya 1):%d\n",sayi1,sayi2,sayi1<=sayi2);//kucuk esittir.
	printf("Ilk sayi:%d,ikinci sayi:%d,sorgu sonucu(0 veya 1):%d\n",sayi1,sayi2,!(sayi1==sayi2));//unlem terse �evirdi
	printf("Ilk sayi:%d,ikinci sayi:%d,sorgu sonucu(0 veya 1):%d\n",sayi1,sayi2,(sayi1==sayi2)&&(sayi1<sayi2));//iki taraf da 1 olmal�=1
	printf("Ilk sayi:%d,ikinci sayi:%d,sorgu sonucu(0 veya 1):%d\n",sayi1,sayi2,(sayi1==sayi2)||(sayi1>sayi2));//bir taraf 1 ise=1
	
	//BIT DUZEYINDEKI MANTIKSAL OPERAT�RLER
	int bitDuzeyi=10;//0100 0000
	int bitDuzeyi2=13;//0010 0000
	
	printf("Ve operatoru sonuc:%d\n",bitDuzeyi & bitDuzeyi2);
	
	printf("Veya operatoru sonuc:%d\n",bitDuzeyi | bitDuzeyi2);
	
	VE
	64= 0100 0000
	32= 0010 0000
	s=	0000 0000	=0
	
	VEYA
	64= 0100 0000
	32= 0010 0000
	s=	0110 0000=2^6*1+2^5*1=64+32=96
	*/

	//1.SORU
	/*
	int paraMiktari;
	printf("Lutfen bir para miktari giriniz:");
	scanf("%d",&paraMiktari);//de�i�kenin adresine yaz.
	
	printf("%d adet 200 TL bulunmaktadir\n",paraMiktari/200);
	paraMiktari%=200;
	printf("%d adet 100 TL bulunmaktadir\n",paraMiktari/100);
	paraMiktari%=100;
	printf("%d adet 50 TL bulunmaktadir\n",paraMiktari/50);
	paraMiktari%=50;
	printf("%d adet 20 TL bulunmaktadir\n",paraMiktari/20);
	paraMiktari%=20;
	printf("%d adet 10 TL bulunmaktadir\n",paraMiktari/10);
	paraMiktari%=10;
	printf("%d adet 1 TL bulunmaktadir\n",paraMiktari);
	
	1480TL=7 adet 200 TL bulunmakt�r.
	80TL=0 adet 100 TL bulunmaktad�r.
	80TL=1 adet 50 TL bulunmaktad�r.
	30TL=1 adet 20TL bulunmakad�r.
	10TL=1 adet 10TL bulunmaktad�r.
	0TL
	

	//2.SORU
	int sayi,geciciSayi;
	printf("Lutfen 3 basamakli tersi alinacak sayiyi girin:");
	scanf("%d",&sayi);
	printf("Duz hali:%d ",sayi);
	printf("Ters hali:");
	geciciSayi=sayi;//123
	printf("%d",geciciSayi%10);//3 yazd�rd�
	geciciSayi/=10;//12
	printf("%d",geciciSayi%10);//2 yazd�rd�
	geciciSayi/=10;//1 
	printf("%d",geciciSayi%10);//1 yazd�rd�
	geciciSayi/=10;//0

	*/
	
	
	
	//�DEV SORULARI
/*
	
	delta=b^2-4*a*c
	daire cevresi=2*pi*r
	daire alani=pi*r^2
	
	1.SORU->Kullan�c�dan a,b,c de�erleri alarak delta hesaplamas� ve deltan�n 0dan b�y�k m� k���k m� oldu�unun sorgusunu yapan program yaz�n�z.
	2.SORU->Kullan�c�dan vize,final notlar�n� y�zdeleriyle birlikte alarak ortalama hesab� yap�n�z,dersin �an de�erine g�re dersi ge�iyorsa 1
	ge�emiyorsa 0 yazd�r�n�z.
	3.SORU->Kullan�c�dan yar��ap al�p dairenin �evresini ve alan�n� hesaplay�n�z.
	
*/
	
	//1.SORU
	/*int a,b,c;
	float deltaSonucu;
	printf("Lutfen sirasiyla a,b,c degerlerini giriniz:");
	scanf("%d%d%d",&a,&b,&c);
	printf("Girdiginiz degerler sirasiyla:%d %d %d\n",a,b,c);
	//deltaSonucu=b*b-4*a*c;
	deltaSonucu=pow(b,2)-4*a*c;
	printf("Delta sonucunuz:%.2f\n",deltaSonucu);
	printf("Delta karsilastirma sonucunuz:%d",deltaSonucu>=0);
	
	*/
	
	//2.SORU
/*
	int vizeNotu,finalNotu,vizeYuzdesi,canDegeri=60;
	float ogrenciOrtalamasi;
	printf("Lutfen sirasiyla vize notunuzu ve vize yuzdenizi giriniz:");
	scanf("%d%d",&vizeNotu,&vizeYuzdesi);
	printf("Lutfen final notunuzu giriniz:");
	scanf("%d",&finalNotu);
	printf("Vize Notunuz:%d(Yuzdesi:%d),Final Notunuz:%d(Yuzdesi:%d)\n",vizeNotu,vizeYuzdesi,finalNotu,100-vizeYuzdesi);
	ogrenciOrtalamasi=(vizeNotu*vizeYuzdesi+finalNotu*(100-vizeYuzdesi))/100;
	printf("Ders Ortalamaniz:%.2f\n",ogrenciOrtalamasi);
	printf("Ders Gecme Durumunuz(1->Gectiniz,0->Kaldiniz):%d",ogrenciOrtalamasi>=canDegeri);
	
*/
	
	//3.SORU
/*
	float yaricap,cevre,alan;
	printf("Lutfen bir yaricap degeri giriniz:");
	scanf("%f",&yaricap);
	printf("Girdiginiz yaricap degeri:%.2f\n",yaricap);
	cevre=2*pi*yaricap;
	alan=pi*pow(yaricap,2);
	printf("Cevre:%.2f Alan:%.2f",cevre,alan);
*/
	
	
	int a, b = 5, c = 8; 
 	a = b != c; 
	printf("%d", a); 
	
	
	
	
	return 0;
}
