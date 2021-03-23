#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 10


int main(int argc, char *argv[]) {
	
	int sayi=5;
	//direkt eriþim:deðiþken ismiyle eriþim
	//dolayli erisim:adresiyle eriþim saðlýyoruz.
	//int *ptr=&sayi;
	int *p1,*p2;//tanýmladým.Ýlk tanýmlama esnasýnda , * isareti pointer anlamýna gelir.
	p1=&sayi;//atama yaptým.& iþareti adres anlamýna gelir.
	p2=&sayi;
	*p2=8;//p2nin gösterdiði yerin degerini 8e cevirdim.
	*p1=12;
	printf("Pointer kullanarak sayi degiskeninin adresi: %#X \n",p1);
	printf("Pointer kullanmadan sayi degiskenin adresi:%#X \n",&sayi);
	printf("Pointer kullanmadan sayi degiskeninin degeri:%d\n",sayi);
	printf("Pointer kullanarak sayi degiskeninin degeri:%d",*p1);//DEGERÝ ANLAMÝNA GELÝYOR.
	
	//p1 sayiyi isaret ediyor.Adresini gösteriyor.
	//p1 sayinin adresini tutuyor.*/
	
	
	
	int dizi[10];
	int *ptr=&dizi[0];//birinci atama tarzi
	int *ptr2=dizi;//ikinci atama tarzi.
	printf("Dizinin baslangic adresi:%#X\n",ptr);
	printf("Dizinin baslangic adresi:%#X\n",ptr2);
	int i;
	srand(time(NULL));
	for(i=0;i<10;i++){
		printf("Dizinin %d.indeksinin adresi:%#X\n",i+1,ptr+i);
		*(ptr+i)=rand()%100;
		//dizi[0]=0
		//dizi[1]=1
		//dizi[9]=9
	}//int -> 4 byte.Sirali.
		
	for(;ptr!=dizi+10;ptr++){
		printf("Adres:%#Xve degeri:%d\n",ptr,*ptr);
	}
	int *p=dizi;
	
	printf("%d\n",(*p)++);
					//dizi[0].elemanýnýn deðerini yazdýr.Sonra o deðeri 1 arttýr.
	printf("%d\n",*(p++));
					//dizinin[0].elemanýný yazdýrmýþ.sonra dizinin[1].elemanýna geçmiþ
	
	printf("%d\n",*(++p));
					//dizinin[2].elemanýna geç,sonra deðeri yazdýr.
	
	printf("%d\n",++(*p));
					//dizninin[2].elemanýnýn deðerini arttýr sonra da yaz.
					
					//0.eleman
					//0.elemanýn bir fazlasý
					//2.eleman
					//2.elemanýn bir fazlasý
		
	char *kullaniciGirisi[]={"Ogun Birinci","Duygu Keydal","Eda Deniz","Burak Ikinci","Omer Selvi"};
	char *ptr;
	ptr=kullaniciGirisi;
	int i;
	// char kullaniciGirisi[]="Ogun Birinci";
	
	while(*kullaniciGirisi!='\0'){
		printf("%#X adresinde tutulan deger :%c\n ",kullaniciGirisi,*kullaniciGirisi);
		kullaniciGirisi++;
	}
	
	printf("%#X adreesinde tutulan deger:%c\n",kullaniciGirisi,*kullaniciGirisi);
	printf("Baslangic adresi:%#X",ptr);
	
	for(i=0;i<5;i++){
		printf("%s\n",kullaniciGirisi[i]);
	}
	
	return 0;
}*/


//ÝKÝ SAYININ DEÐERLERÝNÝ DEÐÝÞTÝRME KODU
void sayiDegistir(int,int);
void sayiDegistirPointer(int *,int *);
int main(){
	int a=5,b=12;
	printf("A sayisinin degeri :%d , B sayisinin degeri :%d\n",a,b);
	sayiDegistir(a,b);//isimleri yani deðerleriyle gönderiyorum. CALL BY VALUE.
	printf("A sayisinin degeri:%d B sayisinin degeri:%d\n",a,b);
	sayiDegistirPointer(&a,&b);// adresleriyle yani. CALL BY REFERENCE.
	printf("A sayisinin degeri:%d B sayisinin degeri:%d\n",a,b);

	
	return 0;
	
}
void sayiDegistir(int fonkA,int fonkB){//fonkA=a deðeri atanýyor.
	int geciciSayi;
	geciciSayi=fonkB;// b degeri kaybolmasin.
	fonkB=fonkA;
	fonkA=geciciSayi;
	printf("Fonksiyon icinde A'nin degeri :%d Fonksiyon icinde B'nin degeri:%d\n",fonkA,fonkB);
}
//sayiDegistir fonksiyonu bittigi an fonkA ve fonkB kayboluyor.
void sayiDegistirPointer(int *fonkA,int *fonkB){//fonkB=&b fonkA=&a
	int geciciSayi;
	geciciSayi=*fonkB;
	*fonkB=*fonkA;
	*fonkA=geciciSayi;
}



//function pointer kýsmý
void sonucHesapla(int a,int b){
	printf("Sonuc:%d\n",a*2+b*3);
	//3*2+5*3=6+15=21
	//2*2+8*3=4+24=28
}
void sonucHesapla2(int a,int b){
	printf("Sonuc:%d\n",(a+2)*(b-5));
	//4*7=28
}
void sonucHesapla3(int a,int b){
	printf("Sonuc:%d\n",a*3+b*2);
	//3*3+5*2=19
}

int hesapla(void (*ptr)(int,int),int a,int b){
	ptr(a,b);
}

int main(){
	void (*fonkPtr[3])(int,int);
	fonkPtr[0]=sonucHesapla3;
	fonkPtr[1]=sonucHesapla2;
	fonkPtr[2]=sonucHesapla;

	(*fonkPtr[0])(3,5);//19.bastýrdý.
	(*fonkPtr[1])(2,12);
	(*fonkPtr[2])(2,8);
	
	hesapla(sonucHesapla,3,5);
}



//DÝZÝLERLE ÝLGÝLÝ ÝÞLEMLER-MAÝN KISMIYLA BÝRLÝKTE
void diziyiDoldur(int *dizi,int elemanSayisi){
	srand(time(NULL));
	int *ptr;
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++){//int oldugu icin 4 byte anlamýna geliyor.
		*ptr=rand()%100;
	}
}
void diziyiYazdir(int *dizi,int elemanSayisi){
	int *ptr;
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++){
		printf("%d ",*ptr);	
	}
	printf("\n");
}
void maxMinBul(int *dizi,int elemanSayisi,int *max,int *min){
	int *ptr=dizi;//ptr=1.eleman ptr=dizi[0]
	*max=*ptr;
	*min=*ptr;
	ptr++;//2.elemana geç diyorum.

	for(;ptr<dizi+elemanSayisi;ptr++){
		if(*ptr>*max){
			*max=*ptr;//max deðeri güncellendi
		}
		else if(*ptr<*min){
			*min=*ptr;
		}
	}
}
void topOrtHesapla(int *dizi,int elemanSayisi,int *ort,int *top){
	int *ptr;//dizinin baslangic adresinden baslayacak.
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++){
		*top+=*ptr;
	}
	*ort=*top/elemanSayisi;	
}
int main(){
	int dizi[10];
	int max,min;
	int ort=0,top=0;
	diziyiDoldur(dizi,10);
	diziyiYazdir(dizi,10);
	maxMinBul(dizi,10,&max,&min);
	printf("Dizinin en buyuk elemani:%d dizinin en kucuk elemani:%d\n",max,min);	
	topOrtHesapla(dizi,10,&ort,&top);
	printf("Dizinin toplami:%d , ortalamasi:%d ",top,ort);
	
	
	
	
	return 0;
}*/







//FONKSÝYON ÝÞARETÇÝLERÝNÝN BAÞKA FONKSÝYONA ARGÜMAN OLARAK GÝTMESÝ-MAÝN KISMIYLA BÝRLÝKTE
void MerhabaDunya(){
	printf("Merhaba Dunya\n");
}
void helloWorld(){
	printf("Hello World\n");
}
void halloWelt(){
	printf("Hallo Welt\n");
}
void belirlemeFonksiyonu(void (*fonkPtr[3])(),int sayi){
	switch (sayi){
		case 1:
			(*fonkPtr[0])();
			break;
		case 2:
			(*fonkPtr[1])();
			break;
		case 3:
			(*fonkPtr[2])();
			break;
		default:
			printf("Girdiginiz degere ait bir fonksiyon bulunmaktadir.");
	}
}
int main(){
	void(*fonkPtr[3])(void);
	fonkPtr[0]=MerhabaDunya;
	fonkPtr[1]=helloWorld;
	fonkPtr[2]=halloWelt;
	
	int i;
	for(i=1;i<=3;i++){
		belirlemeFonksiyonu(fonkPtr,i);
	}

	return 0;
}



//Stringteki bosluk karakterleri sayma.
//Stringin tersini yazdýrma.
//Kendi strlen() ve strcmp() fonksiyonlarýmýzý yazýcaz.

void boslukKarakterSay(char *str,int *boslukSayisi){
	char *ptr=str;
	while(*ptr!='\0'){
		if(*ptr==' '){
			*boslukSayisi+=1;
		}	
		ptr++;//adres arttýrma iþlemi,bir sonraki karakter için.
	}
}
void myStrlen(char *str,int *karakterSayisi){
	char *ptr=str;
	while(*ptr!='\0'){
		*karakterSayisi+=1;
		ptr++;//adres arttýrma.
	}
}
void tersiniYazdirma(char *str){
	int karakterSayisi=0;
	myStrlen(str,&karakterSayisi);
	printf("String %d adet karakter icermektedir.\n",karakterSayisi);
	char *ptr=str+karakterSayisi-1;
	while(ptr>=str){
		printf("%c",*ptr);
		ptr--;
	}	
}
int myStrCmp(char *str,char *str2){
	char *p1=str;
	char *p2=str2;
	while(*p1!='\0'&&*p2!='\0'){
		if(*p1==*p2){
			p1++;
			p2++;
		}
		else if(*p1>*p2){
			return 1;//alfabetik olarak p1 deðerim p2den sonra geliyor.
		}
		else{
			return 2;
		}
	}
	
	if(strlen(p1)==strlen(p2)){
		return 0;//stringler birbirleriyle tamamen ayni.
	}
	else if(strlen(p1)>strlen(p2)){
		return 1;////alfabetik olarak p1 deðerim p2den sonra geliyor.
	}
	else{
		return 2;
	}	
}


int main(){
	
	char *kullaniciGirisi="ogunn";
	char *kullaniciGirisi2="ogun";
	//int boslukSayisi=0;
	//boslukKarakterSay(kullaniciGirisi,&boslukSayisi);
	//printf("Girdiginiz string %d adet bosluk karakteri icermektedir.\n",boslukSayisi);
	//tersiniYazdirma(kullaniciGirisi);
	
	int sonuc=myStrCmp(kullaniciGirisi,kullaniciGirisi2);
	if(sonuc==0){
		printf("Iki string birbirinin aynisidir.");
	}
	else if(sonuc==1){
		printf("Girilen ilk string ikinciden sonra geliyor.");
	}
	else{
		printf("Girilen ilk string ikinciden once geliyor.");
	}
	
	
	
	
	

	return 0;
	
}


/*
ÖDEV SORULARI

1.Soru->Tek boyutlu bir dizi oluþturup içine deðerler atayýp, önce baþtan sona, sonra da sondan baþa yani terse yazdýrma fonksiyonlarý.
	 1 2 3 4 5 6 7 8 9 
	 9 8 7 6 5 4 3 2 1

2.Soru-> strcat ve strcpy fonksiyonlarýnýn benzerini yapacak bir fonksiyon.
	

3.Soru->Kullanýcýdan bir string ve belirli bir karakter alýp karakterin kaç kere string içinde geçtiðini kontrol ediniz.


4.Soru->Fonksiyon iþaretçileri arrayi oluþturup kullanýcýnýn girdiði sayýya göre toplama-çýkarma-çarpma-bölme iþlemleri yaptýrýnýz.Derste yaptýðýmýz gibi
Bir tane bunlarý yönetecek fonksiyon(bir tane fonksiyon arrayi,bir tane islem sayisi(carpma,bölme),iki tane de sayi alacak).
	islem_sayisi=1(carpma)
	saayi=5
	sayi2=10
	50

*/


//1.SORU
/*void diziyiDoldur(int *dizi){
	srand(time(NULL));
	int *ptr;
	for(ptr=dizi;ptr<dizi+N;ptr++){
		*ptr=rand()%100;
	}	
}
void diziyiYazdir(int *dizi){
	printf("Dizi:");
	int *ptr;
	for(ptr=dizi;ptr<=dizi+N;ptr++){
		printf("%d ",*ptr);
	}
}
void diziyiTerstenYazdir(int *dizi){
	printf("\nDizinin tersten hali:");
	int *ptr=dizi+N;
	for(;ptr>=dizi;ptr--){
		printf("%d ",*ptr);
	}
	
}
*/
//2.SORU
/*void myStrCat(char *str,char *str2){
	
	//int karakterSayisi=strlen(str);
	//char *p1=str+karakterSayisi;
	char *p1=str;
	while(*p1){//*p1!='\0'
		p1++;
	}
	char *p2=str2;
	while(*p2){
		*p1=*p2;
		p1++;
		p2++;
	}
	*p1='\0';	
}
void myStrCpy(char *str,char *str2){
	char *p1=str;
	char *p2=str2;
	while(*p2){
		*p1++=*p2++;	
	}
	*p1='\0';
}

int main(){
	
	/*int dizi[N];
	diziyiDoldur(dizi);
	diziyiYazdir(dizi);
	diziyiTerstenYazdir(dizi);
	
	char kullaniciGirisi[]="ogunnnnnnnnnnnnnnnnn";
	char kullaniciGirisi2[]="duygu";
	//myStrCat(kullaniciGirisi,kullaniciGirisi2);
	myStrCpy(kullaniciGirisi,kullaniciGirisi2);
	puts(kullaniciGirisi);
	
	return 0;
}*/

//3.SORU
/*int kacKereGeciyor(char *str,char arananDeger,char degistirilecekDeger){
	int sayac=0;
	char *ptr=str;
	while(*ptr){
		if(*ptr==arananDeger){
			*ptr=degistirilecekDeger;
			sayac+=1;
		}
		ptr++;//bir sonraki karaktere geçmek icin
	}
	return sayac;

}
*/
//4.SORU
/*

int toplama(int sayi1,int sayi2){
	return sayi1+sayi2;
}
int carpma(int sayi1,int sayi2){
	return sayi1*sayi2;
}
int bolme(int sayi1,int sayi2){
	return sayi1/sayi2;
}
int cikarma(int sayi1,int sayi2){
	return sayi1-sayi2;
}
int hesapla(int(*ptr[4])(int,int),int sayi1,int sayi2,int islem){
	
	if(islem==1){
		(*ptr[0])(sayi1,sayi2);
	}
	else if(islem==2){
		(*ptr[1])(sayi1,sayi2);
	}
	else if(islem==3){
		(*ptr[2])(sayi1,sayi2);
	}
	else if(islem==4){
		(*ptr[3])(sayi1,sayi2);
	}
	
}
int main(){
	char karakterDizisi[]="how i met your mother";
	int sonuc=kacKereGeciyor(karakterDizisi,'h','*');
	printf("Aradiginiz karakter dizide %d kere gecmektedir.\n",sonuc);
	puts(karakterDizisi);
	int sayi1,sayi2;
	int islem;
	int(*ptr[4])(int,int);
	ptr[0]=toplama;
	ptr[1]=cikarma;
	ptr[2]=carpma;
	ptr[3]=bolme;
	printf("Lutfen iki adet sayi giriniz:");
	scanf("%d%d",&sayi1,&sayi2);
	printf("Lutfen yapmak istediginiz islemi seciniz (Toplama icin 1, Cikarma icin 2, Carpma icin 3, Bolme icin 4):");
	scanf("%d",&islem);
	int sonuc=hesapla(ptr,sayi1,sayi2,islem);
	printf("Sonuc:%d",sonuc);
	return 0;
}

*/


















