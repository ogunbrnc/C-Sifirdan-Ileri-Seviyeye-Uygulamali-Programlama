#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>



int main(int argc,char **argv){
	
	/*
	printf("%d ",isalpha('A'));//1

	printf("%d ",isdigit('+'));//0

	printf("%d ",isdigit(5));//0

	printf("%d ",isalnum('c'));//1

	printf("%d ",isalnum('$'));//0

	printf("%d ",islower('c'));//1

	printf("%d ",isupper('s'));//0
	
	printf("\n");
	*/
	int sayi=5;
	short int shortSayi;
	long int longSayi;
	long long int longlongSayi;
	float floatSayi=5.34567891234;
	double doubleSayi=1.12361723895512123948423;
	
	printf("shortint kapladigi alan:%u bit\n",8*sizeof(shortSayi));
	printf("longint kapladigi alan:%u bit\n",8*sizeof(longSayi));
	printf("longlongint kapladigi alan:%u bit\n",8*sizeof(longlongSayi));
	printf("int kapladigi alan:%u bit\n",8*sizeof(sayi));
	printf("float kapladigi alan:%u bit\n",8*sizeof(floatSayi));
	printf("double kapladigi alan:%u bit\n",8*sizeof(doubleSayi));
	
	/*
	printf("Float deger:%.12f\n",floatSayi);
	printf("Double deger:%.19f",doubleSayi);
	
	int sayiDonusum=(int)floatSayi;
	printf("Donusturulmus hali:%d\n",sayiDonusum);
	
	float sayiDonusum2=(float)sayi;
	printf("Donusuturulmus hali:%f\n",sayiDonusum2);
	
	printf("Short maksimum aralik:%d\n",SHRT_MAX);
	printf("Short minimum aralik:%d\n",SHRT_MIN);
	
	
	int sayiInt=1234;
	
	printf("SayiInt 10luk taban:%d\n",sayiInt);
	
	HEXADECIMAL:
	1 2 3 4 5 6 7 8 9 A B C D E F
	OCTAL:
	1 2 3 4 5 6 7	
	
	*/
	/*
	printf("SayiInt 16'lik taban:%X\n",sayiInt);//4D2=16^0*2+16^1*13+16^2*4=1234.(DECIMAL)
	printf("SayiInt 8'lik taban:%o\n",sayiInt);//2322=8^0*2+8^1*2+8^2*3+8^3*2=1234(DECIMAL)
	
	
	
	float sayiFloat=1.123456;
	printf("SayiFloat normal hali:%f\n",sayiFloat);
	printf("SayiFloat bilimsel hali:%e\n",sayiFloat);
	printf("SayiFloat bilimsel hali:%E\n",sayiFloat);
	printf("SayiFloat bilimsel hali:%g\n",sayiFloat);
	printf("SayiFloat bilimsel hali:%G\n",sayiFloat);
	
	

	printf("Merhaba Dunya\n");//alt satira gecmek icin.
	printf("Merhaba \t Dunya\n");//bir tab kadarl�k bo�luk b�rak�yor
	printf("Merhaba \bDunya\n");//backspace. bir karakter geriye siler.
	printf("'Merhaba Dunya'\n");//�ift t�rnak izin verilmiyor.tek t�rnak kulln�labilir.
	
	printf("Merhaba \\ Dunya\n");// \ i�areti kullanmak i�in 2 tane yazman�z gereklidir.
	printf("\"Merhaba Dunya\"\n");// "" kullan�m�na izin veriyor.
	printf("Merhaba 5%%7 Dunya\n");// mod ifadesini kullanabilirsiniz.
	
	
	
	char karakter='a';
	char karakterDizisi[]="1234.1234";//string ifade.
	
	printf("%c karakterinin hafizada kapladigi alan:%d byte.\n",karakter,sizeof(karakter));
	printf("%c karakterinin decimal karsiligi:%d, hexadecimal karsiligi:%X\n",karakter,karakter,karakter);
	
	//0 d�nerse ->yanl��, 0 d���nda d�nerse -> do�ru
	printf("karakter icin isalpha sonucu:%d\n",isalpha(karakter));//alfabetik mi de�il mi?
	printf("sayi icin isalpha sonucu:%d\n",isalpha('5'));
	printf("karakter icin isdigit sonucu:%d\n",isdigit(karakter));//rakam m� de�il mi
	printf("sayi icin isdigit sonucu:%d\n",isdigit('5'));
	printf("karakter icin isalnum sonucu:%d\n",isalnum(karakter));//ya alfabetik olmas� gerekiyor ya da rakam, di�er karakterlerde sonu� yanl�� d�ner.
	printf("sayi icin isalnum sonucu:%d\n",isalnum('5'));
	printf("+ icin isalnum sonucu:%d\n",isalnum('+'));
	printf("H icin islower sonucu:%d\n",islower('H'));//k���k harf mi?
	printf("h icin islower sonucu:%d\n",islower('h'));//k���k harf mi?
	printf("H icin isupper sonucu:%d\n",isupper('H'));//b�y�k harf mi?
	printf("h icin isupper sonucu:%d\n",isupper('h'));//b�y�k harf mi?
	printf("h icin toupper sonucu:%c \n",toupper('h'));//b�y��e �evirir
	printf("H icin tolower sonucu:%c \n",tolower('H'));//k���k harfe �evirir
	
	
	int tamSayi;
	float ondalikliSayi;
	
	
	tamSayi=atoi(karakterDizisi);//string ifadeyi tam say�y�ya �evirir
	ondalikliSayi=atof(karakterDizisi);//string ifadeyi floata �evirdi.
	
	printf("Sayi:%d\n",tamSayi);
	printf("Sayi:%.4f",ondalikliSayi);
	
	
*/
	return 0;
}
