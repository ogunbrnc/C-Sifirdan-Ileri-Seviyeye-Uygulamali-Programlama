#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(){
	
	int dizi[20];//10 tane eleman*4=40byte.
	printf("%d",sizeof(dizi));//kaç byte 
	baslangic_adresi=malloc();//alan ayirmak icin
	realloc();
	calloc();
	free();//alani geri bosaltmak icin.
	
	
	int *ptr;//baslangic adresini tutabilmek icin.
	ptr=(int *)malloc(sizeof(int));//baslangic adresini döner.
	*ptr=15;
	int *ptr2;
	ptr2=(int *)malloc(sizeof(int));
	*ptr2=350;
	*ptr=*ptr2;//burada yaptigim deger esitlemesi
	ptr=ptr2;//adres eþitlemesi PTR PTR2NÝN GÖSTEDÝGÝ YERÝ GÖSTERÝR.
	free(ptr2);
	printf("%#X\n",ptr);
	printf("%d\n",*ptr);
	printf("%#X\n",ptr2);
	printf("%d\n",*ptr2);
	free(ptr);
	free(ptr2);
	
	int elemanSayisi;
	srand(time(NULL));
	printf("Lutfen kac adet eleman gerektigini giriniz:");
	scanf("%d",&elemanSayisi);
	int *dizi=(int*)malloc(sizeof(int)*elemanSayisi);
	int *ptr;//dizinin hafizadaki baslangic adresini
	for(ptr=dizi;ptr<=dizi+elemanSayisi-1;ptr++){
		(*ptr)=rand()%100;
	}
	for(ptr=dizi;ptr<=dizi+elemanSayisi-1;ptr++){
		printf("%d ",*ptr);
	}
	printf("\nTersten hali:\n");
	for(ptr=dizi+elemanSayisi-1;ptr>=dizi;ptr--){
		printf("%d ",*ptr);
	}
	free(dizi);*/
	/
	for(i=0;i<elemanSayisi;i++){
		dizi[i]=i;
	}
	for(i=0;i<elemanSayisi;i++){
		printf("%d\n",dizi[i]);
	}
	
	
	//pointerTopointer
	
	int kullaniciSayisi=123;
	int *ptr=&kullaniciSayisi;
	int **ptr2ptr=&ptr;
	
	printf("%d\n",kullaniciSayisi);
	printf("%d\n",*ptr);
	printf("%d\n",**ptr2ptr);
	
	
				ptr2ptr  ----->>>           ptr    ---->>>        kullaniciSayisi
																	
	DEÐERLER:   #A12345				            #A1234			    			123
	ADRES:		#A123456						#A12345							#A1234
				*#A12345=#A1234						    	*A1234=123
				*#A1234=123
	
	
	int **ikiBoyutluDizi;
	int satirSayisi,sutunSayisi;
	int i,j;
	srand(time(NULL));
	printf("Satir sayisi:");
	scanf("%d",&satirSayisi);
	printf("Sutun sayisi:");
	scanf("%d",&sutunSayisi);
	
	
	//DÝNAMÝK ÞEKÝLDE DÝZÝ OLUÞTURMA.
	ikiBoyutluDizi=(int **)malloc(sizeof(int *)* satirSayisi);
	for(i=0;i<satirSayisi;i++){
		ikiBoyutluDizi[i]=(int *)malloc(sizeof(int)*sutunSayisi);
	}
	

	//DEÐER ATAMA.
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			ikiBoyutluDizi[i][j]=rand()%100;
		}
	}
	//YAZDIRMA KISMI
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			printf("%d ",ikiBoyutluDizi[i][j]);
		}
		printf("\n");
	}
	//GERÝ ÝADE KISMI.
	for(i=0;i<satirSayisi;i++){
		free(ikiBoyutluDizi[i]);
	}
	free(ikiBoyutluDizi);
	
	
	
	//calloc=clear and allocation
	//realloc=reallocation
	
	
	int elemanSayisi;
	puts("Lutfen eleman sayisini giriniz:");
	scanf("%d",&elemanSayisi);
	int *dizi=(int*)calloc(elemanSayisi,sizeof(int));//baslangic adresi.
	int *ptr;//islemlerin hepsini ptr üzerinden yapýcam
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++){
		*ptr=10;
		printf("%d ",*ptr);
	}
	
	puts("Eleman sayisini kaca yukseltmek istersiniz:");
	scanf("%d",&elemanSayisi);
	dizi=realloc(dizi,elemanSayisi*sizeof(int));	
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++){
		*ptr=20;
		printf("%d ",*ptr);
	}
	free(dizi);//bitti isim al sen kullan.

	return 0;
}



//DÝZÝ-SIRALAMA&ARAMA ÝÞLEMLERÝYLE ÝLGÝLÝ KODLAR
void diziyiDoldur(int *dizi,int elemanSayisi){
	srand(time(NULL));
	int *ptr;//BASLANGÝC ADRESÝNÝ TUTACAK VE TÜM ÝÞLEMLER BUNUN ÜZERÝNDEN GERÇEKLEÞECEK.
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++){
		*ptr=rand()%100;
	}
}

void diziyiYazdir(int *dizi,int elemanSayisi){
	int *ptr;//BASLANGÝC ADRESÝNÝ TUTACAK VE TÜM ÝÞLEMLER BUNUN ÜZERÝNDEN GERÇEKLEÞECEK.
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++){
		printf("%d ",*ptr);
	}
	printf("\n");
}
void secmeliSirala(int *dizi,int elemanSayisi){
	
	int *ptr,*ptr2,*enKucukSayi;
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++){
		enKucukSayi=dizi+elemanSayisi-1;
		for(ptr2=ptr;ptr2<dizi+elemanSayisi;ptr2++){
			if(*ptr2<*enKucukSayi){
				enKucukSayi=ptr2;
			}
		}
		int gecici=*enKucukSayi;
		*enKucukSayi=*ptr;
		*ptr=gecici;
	}
}
void ikiliArama(int *dizi,int elemanSayisi,int arananSayi){
	int *ptrSol=dizi;//baslangicini
	int *ptrSag=dizi+elemanSayisi-1;//sonunu
	int *ptrOrtanca;
	int bulunduMu=0;
	while(ptrSol<=ptrSag){
		ptrOrtanca=ptrSol+(ptrSag-ptrSol)/2;//ortanca deðeri, kaç byte ilerde olmasý gerektiðine göre.
		if(*ptrOrtanca==arananSayi){
			bulunduMu=1;
			break;
		}
		else if(*ptrOrtanca>arananSayi){
			ptrSag=ptrOrtanca-1;
		}
		else{
			ptrSol=ptrOrtanca+1;
		}
	}
	if(bulunduMu){
		printf("%d sayisi bulundu",arananSayi);
	}
	else{
		printf("%d sayisi bulunamadi",arananSayi);
	}
}

int main(){

	
	int elemanSayisi;
	int arananDeger;
	puts("Lutfen dizinin eleman sayisini giriniz:");
	scanf("%d",&elemanSayisi);
	int *dizi=(int*)malloc(sizeof(int)*elemanSayisi);//dinamik bir array oluþturduk.
	diziyiDoldur(dizi,elemanSayisi);
	diziyiYazdir(dizi,elemanSayisi);
	secmeliSirala(dizi,elemanSayisi);//siraladik
	diziyiYazdir(dizi,elemanSayisi);
	printf("Lutfen aramak istediginiz degeri giriniz:");
	scanf("%d",&arananDeger);
	ikiliArama(dizi,elemanSayisi,arananDeger);//deger var mi yok mu kontrol.
	return 0;
	
}




//DÝZÝLERLE ÝLGÝLÝ ÝÞLEMLER-MAÝN KISMIYLA BÝRLÝKTE
void diziyiDoldur(int **ikiBoyutluDizi,int satirSayisi,int sutunSayisi){
	int i,j;
	srand(time(NULL));
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			ikiBoyutluDizi[i][j]=rand()%5;
		}
	}
}
void diziyiYazdir(int **ikiBoyutluDizi,int satirSayisi,int sutunSayisi){
	int i,j;
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			printf("%d ",ikiBoyutluDizi[i][j]);
		}
		printf("\n");
	}
	
}
void matrisToplami(int **ilkMatris,int **ikinciMatris,int **sonucMatrisi,int satirSayisi,int sutunSayisi){
	int i,j;
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			sonucMatrisi[i][j]=ilkMatris[i][j]+ikinciMatris[i][j];
		}		
	}	
}
void birimMatrisOlusturma(int satirSayisi,int sutunSayisi){
	int **birimMatris;
	int i,j;
	birimMatris=(int**)calloc(satirSayisi,sizeof(int*));//DÝNAMÝK DÝZÝ OLUSTURMA
	for(i=0;i<satirSayisi;i++){
		birimMatris[i]=(int*)calloc(sutunSayisi,sizeof(int));
	}
	puts("Birim Matris Olmadan Onceki Hali:");
	diziyiYazdir(birimMatris,satirSayisi,sutunSayisi);
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			if(i==j){
				birimMatris[i][j]=1;
			}
		}
	}
	puts("Birim Matris Olusturulmus Hali:");
	diziyiYazdir(birimMatris,satirSayisi,sutunSayisi);
	for(i=0;i<satirSayisi;i++){
		free(birimMatris[i]);//serbest býrakma
	}
	free(birimMatris);	
}
void transpozYazdirma(int **ikiBoyutluDizi,int satirSayisi,int sutunSayisi){
	int i,j;
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			printf("%d ",ikiBoyutluDizi[j][i]);
		}
		printf("\n");
	}

}

int main(int argc,char **argv){
	
	//1.Matris Toplama	
	//2.Birim Matris
	//3.Transpoz Yazdirma
	int satirSayisi,sutunSayisi;
	int **ilkMatris,**ikinciMatris,**sonucMatrisi;
	int i;
	puts("Lutfen satir ve sutun sayisini sirayla giriniz:");
	scanf("%d%d",&satirSayisi,&sutunSayisi);
	birimMatrisOlusturma(satirSayisi,sutunSayisi);//BÝRÝM MATRÝS
	
	ilkMatris=(int**)malloc(sizeof(int*)*satirSayisi);
	ikinciMatris=(int**)malloc(sizeof(int*)*satirSayisi);
	sonucMatrisi=(int**)calloc(satirSayisi,sizeof(int*));//hem dinamik oldu, hem 0 atandý.
	
	for(i=0;i<satirSayisi;i++){
		ilkMatris[i]=(int*)malloc(sizeof(int)*sutunSayisi);
		ikinciMatris[i]=(int*)malloc(sizeof(int)*sutunSayisi);
		sonucMatrisi[i]=(int*)calloc(sutunSayisi,sizeof(int));	
	}
	diziyiDoldur(ilkMatris,satirSayisi,sutunSayisi);
	diziyiDoldur(ikinciMatris,satirSayisi,sutunSayisi);
	puts("Ilk Matris:");
	diziyiYazdir(ilkMatris,satirSayisi,sutunSayisi);
	puts("Ikinci Matris:");
	diziyiYazdir(ikinciMatris,satirSayisi,sutunSayisi);
	puts("Toplam Matrisinin toplamadan onceki hali:");
	diziyiYazdir(sonucMatrisi,satirSayisi,sutunSayisi);
	matrisToplami(ilkMatris,ikinciMatris,sonucMatrisi,satirSayisi,sutunSayisi);
	puts("Toplam Matrisinin toplamadan sonraki hali:");
	diziyiYazdir(sonucMatrisi,satirSayisi,sutunSayisi);
	puts("Toplam Matrisinin Transpoz Hali:");
	transpozYazdirma(sonucMatrisi,satirSayisi,sutunSayisi);
		
	for(i=0;i<satirSayisi;i++){//KULLANDIGIMIZ ALANI GERÝ VERDÝK
		free(ilkMatris[i]);
		free(ikinciMatris[i]);
		free(sonucMatrisi[i]);
	}	
	free(ilkMatris);//free yaptik
	free(ikinciMatris);
	free(sonucMatrisi);


	return 0;
}




//ÖDEV SORULARI
/*
	1.Soru->Kullanýcýdan alacaginiz 2 adet stringin birbirinin anagramý olup olmadýðýný kontrol ediniz, ancak bu sefer bunu yaparken
	harflerin frekanslarýný iki adet dizide tutarak yapýnýz(dizi oluþturma esnasýnda calloc fonksiyonunu kullanarak yapýnýz).
	
		kalem kelam-anagram
		26lýk 26lýk
	
	2.Soru->Kullanýcýdan alacaðýnýz satir ve sutun sayisina gore bir adet iki boyutlu diziyi dinamik þekilde oluþturunuz. Deðerleri kullanýcýdan 
	alarak matrisin	içeriðini doldurup bir kere matrisi yazdýrýnýz. En son matrisin simetrik olup olmadýðýný karþýlaþtýrýnýz.
		1 2 3
		2 1 1
		3 1 3
	
	3.Soru->Kullanýcýdan alacaginiz satir ve sutun sayisina gore iki adet iki boyutlu diziyi dinamik þekilde oluþturunuz. Ýki diziyi rastgele
	deðerler ile doldurup ikisini de yazdýrýnýz. En son ikinci girilen matrisi birinciden çýkararak sonuç matrisini yazdýrýnýz.(Derste kullandýðýmýz
	matris toplama fonksiyonunu kullanabilirsiniz, ancak bunu yapmadan önce ikinci matris üzerinde deðiþiklik yapmanýz gerekir.Burayý size
	býrakýyoruz.)
	
	4.Soru->Kullanýcýdan alacaðýnýz eleman sayisi ile bir adet dinamik dizi oluþturunuz. Oluþturduðunuz diziye rastgele elemanlar atayýp bir kere
	diziyi yazdýrýnýz. Son olarak diziyi ARAYA SOKMA algoritmasý ile sýralayýp yazdýrýnýz.
	
	5.Soru->4.soruda sýralamýþ olduðunuz dizinin üzerinde kullanýcýdan aldýðýnýz deðeri ARDIÞIL ARAMA(Linear search) ALGORÝTMASI ÝLE arayýnýz.

*/

//1.SORU
/*int anagramKontrol(char *str, char *str2){
	
	int *frekansDizisi,*frekansDizisi2;
	char *ptr=str,*ptr2=str2;
	int i;
		
	if(strlen(str)!=strlen(str2)){
		return 0;//anagram degildir.
	}
	
	frekansDizisi=(int*)calloc(26,sizeof(int));
	frekansDizisi2=(int*)calloc(26,sizeof(int));
	
	while(*ptr!='\0'&& *ptr2!='\0'){
		int indeks=*ptr-'a';
		frekansDizisi[indeks]+=1;
		indeks=*ptr2-'a';
		frekansDizisi2[indeks]+=1;	
		ptr++;
		ptr2++;	
	}
	for(i=0;i<26;i++){
		printf("%d ",frekansDizisi[i]);	
	}
	printf("\n");
	for(i=0;i<26;i++){
		printf("%d ",frekansDizisi2[i]);	
	}
	
	for(i=0;i<26;i++){
		if(frekansDizisi[i]!=frekansDizisi2[i]){
			return 0;//anagram degillerdir.
		}
		
	}
	return 1;//anagramdir.
	
	
}

int main(){
	
	if(anagramKontrol("eczane","cenaze")){
		puts("Girdiginiz iki string birbirinin anagramidir.");
	}
	else{
		puts("Girdiginiz iki string birbirinin anagrami degildir.");
	}	
	return 0;
}*/

//2.SORU
/*void diziyiDoldur(int **matris,int satirSayisi,int sutunSayisi){
	int i,j;
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			printf("Lutfen [%d][%d] degerini giriniz:",i,j);
			scanf("%d",&matris[i][j]);
		}
	}
}
void diziyiYazdir(int **matris,int satirSayisi,int sutunSayisi){
	int i,j;
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			printf("%d ",matris[i][j]);
		}
		printf("\n");
	}
}
int simetrikKontrol(int **matris,int satirSayisi,int sutunSayisi){
	
	int i,j;
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			if(matris[i][j]!=matris[j][i]){
				return 0;//simetrik degildir.
			}
		}	
	}
	return 1;//simetriktir.	
}
//3.SORU
void matrisToplami(int **ilkMatris,int **ikinciMatris,int **sonucMatrisi,int satirSayisi,int sutunSayisi){
	int i,j;
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			sonucMatrisi[i][j]=ilkMatris[i][j]+ikinciMatris[i][j];
		}		
	}	
}
void negatifeCevir(int **matris,int satirSayisi,int sutunSayisi){
	int i,j;
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			matris[i][j]*=-1;//her degeri eksi 1 ile carptik
		}
	}
}

int main(){
	
	int satirSayisi,sutunSayisi;
	int **ikiBoyutluMatris,**ikinciMatris,**sonucMatrisi;//dinamik array için
	int i;
	puts("Lutfen sirasiyla satir ve sutun sayisini giriniz:");
	scanf("%d%d",&satirSayisi,&sutunSayisi);
	//DÝNAMÝK OLUSTURMA
	ikiBoyutluMatris=(int**)malloc(sizeof(int)*satirSayisi);//satirlar icin yer ayirmistik
	ikinciMatris=(int**)malloc(sizeof(int)*satirSayisi);//satirlar icin yer ayirmistik
	sonucMatrisi=(int**)malloc(sizeof(int)*satirSayisi);//satirlar icin yer ayirmistik
	for(i=0;i<satirSayisi;i++){
		ikiBoyutluMatris[i]=(int*)malloc(sizeof(int)*sutunSayisi);//sütun kadarlýk yer ayýrdýk.
		ikinciMatris[i]=(int*)malloc(sizeof(int)*sutunSayisi);//sütun kadarlýk yer ayýrdýk.
		sonucMatrisi[i]=(int*)malloc(sizeof(int)*sutunSayisi);//sütun kadarlýk yer ayýrdýk.
	}
	
	
	puts("Ilk Matris:");
	diziyiDoldur(ikiBoyutluMatris,satirSayisi,sutunSayisi);
	diziyiYazdir(ikiBoyutluMatris,satirSayisi,sutunSayisi);
	puts("Ikinci Matris:");
	diziyiDoldur(ikinciMatris,satirSayisi,sutunSayisi);
	diziyiYazdir(ikinciMatris,satirSayisi,sutunSayisi);
	
	negatifeCevir(ikinciMatris,satirSayisi,sutunSayisi);//cikarma islemi icin negatife cevirdik.
	matrisToplami(ikiBoyutluMatris,ikinciMatris,sonucMatrisi,satirSayisi,sutunSayisi);
	
	puts("Cikarma islemi sonucu:");
	diziyiYazdir(sonucMatrisi,satirSayisi,sutunSayisi);
	
	
	
	if(simetrikKontrol(ikiBoyutluMatris,satirSayisi,sutunSayisi)){
		puts("Simetriktir.");
	}
	else{
		puts("Simetrik degildir.");
	}
	

	//FREE ÝSLEMÝ
	for(i=0;i<satirSayisi;i++){
		free(ikiBoyutluMatris[i]);
		free(ikinciMatris[i]);
		free(sonucMatrisi[i]);
	}
	free(ikiBoyutluMatris);
	free(ikinciMatris);
	free(sonucMatrisi);
	

}*/




//4.SORU-5.SORU
/*
void diziyiDoldur(int *dizi,int elemanSayisi){
	int *ptr;//baslangic adresinden sona kadar gidecek.
	srand(time(NULL));
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++){
		*ptr=rand()%100;
	}
}
void diziyiYazdir(int *dizi,int elemanSayisi){
	int *ptr;//baslangic adresinden sona kadar gidecek.
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++){
		printf("%d ",*ptr);
	}
	printf("\n");	
}
void arayaSokma(int *dizi,int elemanSayisi){
	
	int *ptr,*ptr2,arayaSokulacakEleman;
	for(ptr=dizi+1;ptr<dizi+elemanSayisi;ptr++){
		arayaSokulacakEleman=*ptr;
		for(ptr2=ptr-1;ptr2>=dizi && arayaSokulacakEleman <=*ptr2;ptr2--){
			*(ptr2+1)=*ptr2;
		}
		*(ptr2+1)=arayaSokulacakEleman;
	}
}
int ardisilArama(int *dizi,int elemanSayisi,int arananSayi){
	int *ptr;
	for(ptr=dizi;ptr<dizi+elemanSayisi;ptr++){
		if(*ptr==arananSayi){
			return 1;
		}	
	}
	return 0;
}
int main(){
	int elemanSayisi;
	int arananSayi;
	puts("Lutfen dizinin eleman sayisini giriniz:");
	scanf("%d",&elemanSayisi);
	int *dizi=(int*)malloc(sizeof(int)*elemanSayisi);//DÝNAMÝK TEK BOYUTLU DÝZÝ OLUÞTURMA.
	puts("Sirasiz Hali:");
	diziyiDoldur(dizi,elemanSayisi);
	diziyiYazdir(dizi,elemanSayisi);
	arayaSokma(dizi,elemanSayisi);
	puts("Sirali Hali:");
	diziyiYazdir(dizi,elemanSayisi);
	puts("Aramak istediginiz degeri giriniz:");
	scanf("%d",&arananSayi);
	if(ardisilArama(dizi,elemanSayisi,arananSayi)){
		puts("Aradiginiz deger dizide bulundu.");
	}
	else{
		puts("Aradiginiz deger dizide bulunamadi.");
	}
	
	free(dizi);//serbest biraktik

	return 0;
}
*/
















