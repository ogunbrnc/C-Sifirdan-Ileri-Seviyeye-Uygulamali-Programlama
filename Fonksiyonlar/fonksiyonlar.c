#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*void diziyiYazdir(int [], int );
void diziyiSirala(int [], int );
void diziyiDoldur(int [], int);
void stringSirala(char [],int );
void anagramKontrol(char [], char[]);

int main(int argc, char **argv){
	char kullaniciGirisi[20],kullaniciGirisi2[20];
	puts("Lutfen ilk stringi giriniz:");
	gets(kullaniciGirisi);
	puts("Lutfen ikinci stringi giriniz:");
	gets(kullaniciGirisi2);
	anagramKontrol(kullaniciGirisi,kullaniciGirisi2);
	return 0;	
}
void stringSirala(char kullaniciGirisi[],int karakterSayisi){
	int i,eleman,j;
	for(i=1;i<karakterSayisi;i++){
			eleman=kullaniciGirisi[i];
			for(j=i-1;j>=0 && eleman<=kullaniciGirisi[j];j--){
				kullaniciGirisi[j+1]=kullaniciGirisi[j];
			}
			kullaniciGirisi[j+1]=eleman;
		}
}
void anagramKontrol(char kullaniciGirisi[], char kullaniciGirisi2 []){
	int i,j,eleman,sorgu=1;//eðer ki eþitlik bozulursa sorgu=0 olacak.
	int karakterSayisi,karakterSayisi2;
	
	karakterSayisi=strlen(kullaniciGirisi);
	karakterSayisi2=strlen(kullaniciGirisi2);
	
	if(karakterSayisi!=karakterSayisi2){
		puts("Anagram degiller.");
	}
	
	else{
		stringSirala(kullaniciGirisi,karakterSayisi);
		stringSirala(kullaniciGirisi2,karakterSayisi2);
		for(i=0;i<karakterSayisi;i++){
			if(kullaniciGirisi[i]!=kullaniciGirisi2[i]){
				sorgu=0;//anagram degil.
				break;
			}					
		}
		if(sorgu){
			puts("Anagram.");
		}
		else{
			puts("Anagram degil.");
		}	
	}
}

void diziyiYazdir(int dizi[], int elemanSayisi){
	int i;
	for(i=0;i<elemanSayisi;i++){
		printf("%d ",dizi[i]);
	}	
}
void diziyiSirala(int dizi[], int elemanSayisi){
	int i,j,indexKucukSayi,enKucukSayi;
	for(i=0;i<elemanSayisi-1;i++){
		enKucukSayi=dizi[elemanSayisi-1];
		indexKucukSayi=elemanSayisi-1;
		for(j=i;j<elemanSayisi-1;j++){
			if(dizi[j]<enKucukSayi){
				enKucukSayi=dizi[j];
				indexKucukSayi=j;
			}
		}
		printf("%d sayisi ile %d sayisi yer degisitirildi.\n",enKucukSayi,dizi[i]);
		dizi[indexKucukSayi]=dizi[i];
		dizi[i]=enKucukSayi;
	}	
}
void diziyiDoldur(int dizi[],int elemanSayisi){
	int i;
	srand(time(NULL));
	for(i=0;i<elemanSayisi;i++){
		dizi[i]=rand()%100;
	}
}
*/
/*
void diziyiYazdir(int [], int );
void diziyiSirala(int [], int );
void diziyiDoldur(int [], int);
int enBuyukNDeger(int [],int,int);
int enKucukNDeger(int [],int,int);
int main(int argc,char**argv){
	int elemanSayisi=15,kullaniciGirisi;
	int dizi[elemanSayisi];
	int buyukN,kucukN;
	diziyiDoldur(dizi,elemanSayisi);
	diziyiYazdir(dizi,elemanSayisi);
	puts("\nLutfen en buyuk ve en kucuk kacinci sayiyi istediginizi giriniz:");
	scanf("%d",&kullaniciGirisi);
	buyukN=enBuyukNDeger(dizi,elemanSayisi,kullaniciGirisi);
	kucukN=enKucukNDeger(dizi,elemanSayisi,kullaniciGirisi);
	printf("Dizinin en buyuk %d. degeri : %d",kullaniciGirisi,buyukN);
	printf("Dizinin en kucuk %d. degeri : %d",kullaniciGirisi,kucukN);
	

	return 0;
}
void diziyiSirala(int dizi[], int elemanSayisi){
	int i,j,indexKucukSayi,enKucukSayi;
	for(i=0;i<elemanSayisi-1;i++){
		enKucukSayi=dizi[elemanSayisi-1];
		indexKucukSayi=elemanSayisi-1;
		for(j=i;j<elemanSayisi-1;j++){
			if(dizi[j]<enKucukSayi){
				enKucukSayi=dizi[j];
				indexKucukSayi=j;
			}
		}
		dizi[indexKucukSayi]=dizi[i];
		dizi[i]=enKucukSayi;
	}	
}
void diziyiDoldur(int dizi[],int elemanSayisi){
	int i;
	srand(time(NULL));
	for(i=0;i<elemanSayisi;i++){
		dizi[i]=rand()%100;
	}
}
void diziyiYazdir(int dizi[], int elemanSayisi){
	int i;
	for(i=0;i<elemanSayisi;i++){
		printf("%d ",dizi[i]);
	}	
}
int enBuyukNDeger(int dizi[],int elemanSayisi,int NDeger){
	diziyiSirala(dizi,elemanSayisi);
	diziyiYazdir(dizi,elemanSayisi);
	return dizi[elemanSayisi-NDeger];
	
	
}
int enKucukNDeger(int dizi[],int elemanSayisi,int NDeger){
	diziyiSirala(dizi,elemanSayisi);
	return dizi[NDeger-1];
	
}
*/

/*void unluSayisiBelirleme(char []);

int main(int argc,char **argv){
	char kullaniciGirisi[20];
	puts("Lutfen unlu sayisi sayilacak stringi giriniz:");
	gets(kullaniciGirisi);
	unluSayisiBelirleme(kullaniciGirisi);
	return 0;
		
}
void unluSayisiBelirleme(char kullaniciGirisi[]){
	int i=0,j;//unluHARF sayacým.;
	char unluHarfler[]={'a','e','i','u','o','\0'};
	int unluHarfSayilari[]={0,0,0,0,0};
	while(kullaniciGirisi[i]!='\0'){
		for(j=0;j<5;j++){
			if(kullaniciGirisi[i]==unluHarfler[j]){
				break;
			}
		}
		unluHarfSayilari[j]+=1;
		i++;//UNUTMAYIN.
	}
	for(i=0;i<5;i++){
		printf("%c karakteri %d adet gecmektedir.\n",unluHarfler[i],unluHarfSayilari[i]);
	}	
}*/


/*int fibonacciRecursive(int);
int ikiliArama(int [],int,int,int);


int main(int argc,char **argv){
	
	/*int i,ustLimit;
	puts("Lutfen seri icin bir ust limit giriniz!");
	scanf("%d",&ustLimit);
	for(i=0;i<ustLimit;i++){
		printf("%d ",fibonacciRecursive(i));
	}
	
	int dizi[]={1,5,12,18,23,43,52,82,102,121};
	int sonuc=ikiliArama(dizi,0,9,41);
	if(sonuc!=-1){
		printf("Aranan deger bulundu.");
	}
	else{
		printf("Aranan deger bulunamadi.");
	}

	return 0;
}
int fibonacciRecursive(int sayi){
	if(sayi==0 || sayi==1){
		return sayi;
	}
	else{
		return fibonacciRecursive(sayi-1)+fibonacciRecursive(sayi-2);
	}
}
int ikiliArama(int dizi[],int sol_index,int sag_index,int arananDeger){
	
	if(sag_index>=sol_index){
		int ortanca_index=(sol_index+sag_index)/2;	
		if(dizi[ortanca_index]==arananDeger){
			return 1;
		}
		if(dizi[ortanca_index]>arananDeger){
			return ikiliArama(dizi,sol_index,ortanca_index-1,arananDeger);
		}
		return ikiliArama(dizi,ortanca_index+1,sag_index,arananDeger);
	
	}
	return -1;//bulunamadi anlamina geliyor.	
}*/




//ÖDEV SORULARI
/*
1.Soru->Dizide kaç adet karakter geçiyor(karakter sayýsý anlamýnda olmayacak) bunu sayan bir fonksiyon yazýn.
Örneðin stringimiz
	Su an bu dersi dinliyorum.-> ( S,u,a,n,b,d,e,r,s,i,l,y,o,m). Yani bir kere saydýðýmýz karakteri bir daha saymayacaðýz.
2.Soru->Recursive þekilde OBEB-OKEK fonksiyonu.
	GCD
3.Soru->Kullanýcýdan dizi alýp diagonallerindeki deðerlerin çarpýmýný yapan fonksiyon yazýnýz.
	1 2 3
	4 5 6
	7 8 9    1*5*9=45.
4.Soru->3.Soruda yaptýðýmýz iþlemi bu sefer sað üst köþeden sol alt köþeye yapan bir fonksiyon yazalým ve 3.Sorudaki fonksiyon ile ayný sonucu
veriyorsa true, deðilse false döndürsün.
	1 2 3 
	4 5 6
	7 8 9	3*5*7=105.False
5.Soru->Kullanýcýdan bir dizi alýp dizinin satir ve sutunlarýnýn toplamýný hesaplayýp yazdýran bir fonksiyon yazýnýz.
	1 2 3
	4 5 6
	7 8 9
	1.Satýr toplamý:6
	2.Satýr toplamý:15
	3.Satýr toplamý:24
	1.Sutun toplamý:12
	2.Sutun toplamý:15
	3.Sutun toplamý:18
*/

//1.SORU
/*int diziKarakterSay(char kullaniciGirisi[]){
	char karakterler[26];// max kullanabilecek karakterleri.
	int i,j;//i ilk döngüm(kullaniciGirisi),j ikinci döngüm (karakterler icin)
	for(i=0;i<26;i++){
		karakterler[i]='$';// bos mu degil mi bunu sorgulamak icin.
	}
	i=0;//0a çektik.
	while(kullaniciGirisi[i]!='\0'){
		j=0;//ikinci.
		while(1){
			if(karakterler[j]=='$'){
				karakterler[j]=kullaniciGirisi[i];
				break;
			}
			else if(karakterler[j]==kullaniciGirisi[i]){
				break;
			}
			j++;
		}
		i++;	
	}
	for(i=0;i<26;i++){
		if(karakterler[i]=='$'){
			break;
		}
	}
	return i;
}
int main(){
	int ozelKarakterler=diziKarakterSay("ogunbirinci");
	printf("Gonderdiginiz string %d adet ozel karakter icermektedir.",ozelKarakterler);
	return 0;
}*/

//2.SORU
/*
int recursiveOBEB(int x,int y){
	if(y==0){
		return x;
	}
	return recursiveOBEB(y,x%y);
}
int recursiveOKEK(int x,int y){
	return x*y/recursiveOBEB(x,y);
}
int main(){
	printf("OBEB:%d\n",recursiveOBEB(12,3));
	printf("OKEK:%d",recursiveOKEK(12,3));
	return 0;
}
/*
	12,3---->3,0
		----->return 3.	OBEB=3.
	36/3=12.
*/


//3.SORU-4.SORU
/*
void diziyiDoldur(int fonkDizi[][5],int satirSayisi,int sutunSayisi){
	int i,j;
	srand(time(NULL));
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			fonkDizi[i][j]=rand()%5+1;
		}
	}
}
void diziyiYazdir(int fonkDizi[][5],int satirSayisi,int sutunSayisi){
	int i,j;
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			printf("%d ",fonkDizi[i][j]);
		}
		printf("\n");
	}
}
int diagonalCarpimi(int fonkDizi[][5],int satirSayisi,int sutunSayisi){
	int i,j;
	int carpimSonucu=1;
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			if(i==j){
				carpimSonucu*=fonkDizi[i][j];
			}
		}
	}
	return carpimSonucu;
}
int sagdanDiagonalCarpimi(int fonkDizi[][5],int satirSayisi,int sutunSayisi){
	int i,j;
	int carpimSonucu=1;
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			if(i+j==satirSayisi-1){
				carpimSonucu*=fonkDizi[i][j];
			}
		}
	}
	printf("Sagdan diagonal carpimi:%d\n",carpimSonucu);
	if(carpimSonucu==diagonalCarpimi(fonkDizi,satirSayisi,sutunSayisi)){
		return 1;
	}
	else{
		return 0;
	}
	
}

//5.SORU
void satirSutunToplami(int fonkDizi[][5],int satirSayisi,int sutunSayisi){
	int i,j;
	for(i=0;i<satirSayisi;i++){
		int satirToplam=0;
		int sutunToplam=0;
		for(j=0;j<sutunSayisi;j++){
			satirToplam+=fonkDizi[i][j];
			sutunToplam+=fonkDizi[j][i];//sutun toplamina eristik.	
		}
		printf("%d.satirin toplami:%d\n",i+1,satirToplam);
		printf("%d.sutunun toplami:%d\n",i+1,sutunToplam);
	}
}
int main(int argc,char **argv){
	int satirSayisi=5,sutunSayisi=5;
	int dizi[satirSayisi][sutunSayisi];
	diziyiDoldur(dizi,satirSayisi,sutunSayisi);
	diziyiYazdir(dizi,satirSayisi,sutunSayisi);
	printf("Diagonal carpimlari:%d\n",diagonalCarpimi(dizi,satirSayisi,sutunSayisi));
	int sonuc=sagdanDiagonalCarpimi(dizi,satirSayisi,sutunSayisi);
	if(sonuc){
		printf("Sagdan ve soldan diagonal carpimlari esittir");
	}
	else{
		printf("Degildir.\n");
	}
	satirSutunToplami(dizi,satirSayisi,sutunSayisi);
	return 0;
	
}
*/



















