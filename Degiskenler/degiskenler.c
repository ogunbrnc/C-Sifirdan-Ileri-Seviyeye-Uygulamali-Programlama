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
    //isimlendirme kurallarý
    /*
    int sayi2;//tekrar tanýmlama yapýlamaz.
    int for;keyword kullanýlamaz.
    int sayý;turkce karakter kullanýlamaz
    int sayý 5;bosluk karakteri kullanýlamaz
    int 2sayý;sayi ile baslayamayiz.
    */
    int s;
    int sayfaNo;
    
    return 0;
}
