#include <stdio.h>
 

int main()
{
    //degiskeninTipi degiskeninAdi=degiskeninDegeri;
    int sayi,sayi2=9;//tam sayilar icin
    float sayi3=5.7;
    double sayi4=2.8;
    char karakter='x';
    
    sayi=5;
    printf("%d %i %.1f %.1lf %c\n",sayi,sayi2,sayi3,sayi4,karakter);
    printf("%#X %#X %#X %#X %#X\n",&sayi,&sayi2,&sayi3,&sayi4,&karakter);
    
    
    int _2sayi;
    //isimlendirme kurallar�
    /*
    int sayi2;//tekrar tan�mlama yap�lamaz.
    int for;keyword kullan�lamaz.
    int say�;turkce karakter kullan�lamaz
    int say� 5;bosluk karakteri kullan�lamaz
    int 2say�;sayi ile baslayamayiz.
    */
    int s;
    int sayfaNo;
    
    return 0;
}
