#include <stdio.h>
#include <stdlib.h>
#include <time.h> //rastgele deger icin ekledigimiz kutuphanr..

int main() {
    int ciro[12]; //12 ay icin 12 tane ciro..
    int i, j;//iki for icin iki deger..
    int max = 0;//en fazla yildiz degerimiz..

    srand(time(NULL)); //ciromuzu rastgele uretecek (her calistirdigimizda rastgeledeger atacak..)

    // 12 aylik ciro uretecegiz.. (1–10 arasi)
    for (i = 0; i < 12; i++) { // bu dongu 12 ay icin 1 ile 10 arasnida rastgele ciro degerleri üretecek..
        ciro[i] = rand() % 10 + 1; //ciro degeri 0 olmasin diye +1i ekledik... (boylece 1-10 oldu..)
        if (ciro[i] > max)
            max = ciro[i];
    }

    // ciro dizimizi ekrana yazdiriyoruz..
    printf("startup girisimimizdeki aylik ciro degerlerimiz..\n");
    for (i = 0; i < 12; i++) {
        printf("%2d. ay: %dk\n", i + 1, ciro[i]);
    }

    // yatay bar grafigimiz (cirolar aylar sekilde)
    printf("yillik ciromuz (aylara bolunmus ve yatay sekilde)\n");
    for (i = 0; i < 12; i++) {
        printf("%2d: ", i + 1);
        for (j = 0; j < ciro[i]; j++) {
            printf("* ");
        }
        printf("\n"); // yataya donduren printfimiz..
    }

    // dikey bar grafihimiz..
    printf("yillik ciromuz (aylara bolunmus ve dikey sekilde)\n");

    for (i = max; i > 0; i--) {
        for (j = 0; j < 12; j++) {
            if (ciro[j] >= i)
                printf(" * ");
            else
                printf("   ");
        }
        printf("\n"); // dikeye donduren printfimiz..
    }

    // dikey barin altindaki ay numaralari..
    for (i = 0; i < 12; i++) {
        printf("%2d ", i + 1); //dogru hizalansin diye ekledigimiz %2d.. (eklemeyince ay numaralarimiz cok solda duruyo ve dikey grafigimizle uyusmuyor..
    }

    return 0;
}
