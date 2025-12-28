#include <stdio.h>
#include <string.h> //karakterdizisi icin olan kutuphane.. (olmazsa strleni kullanamazdik..)

int main() {

    char mesaj[100];   // girecegimiz mesaj (100 vermesem  kodlamada hata cikiyor fazla ama sallama bir sayi verelim..)
    int anahtar; //kac girersek girdigimiz seyi o harf sayisi kadar ileri atacak..
    int i;
    int secim; // 1 = sifrele (4.1), 2 = coz (4.2)

    // kullanicidan sifreleme mi cozme mi istedigini ogreniyoruz
    printf("1 - Sifrele\n");
    printf("2 - Coz\n");
    printf("Seciminizi girin: ");
    scanf("%d", &secim);
    getchar(); // scanf sonrasi kalan enter karakterini temizlemek icin

    // oncelikle islem yapacagimiz mesaji isteyip alalim..
    printf("mesaji girin: ");
    fgets(mesaj, sizeof(mesaj), stdin); // fgets ile aldim cunku scanf bosluk koyunca patliyor..

    // simdi ise anahtar degerimizi isteyip alalim..
    printf("anahtar degerini girin: ");
    scanf("%d", &anahtar); // anahtar tek haneli olacagindan fgets kullanmadik../

    // mesajin her karakterini tek tek incelemek icin strlen kullandik..
    for (i = 0; i < strlen(mesaj); i++) {

        // kucuk harf kontrolunu burada hallediyoruz..
        if (mesaj[i] >= 'a' && mesaj[i] <= 'z') {

            // 4.1 sifreleme islemi (+ anahtar)
            if (secim == 1) {
                mesaj[i] = ((mesaj[i] - 'a' + anahtar) % 26) + 'a';
            }

            // 4.2 cozme islemi (- anahtar)
            else if (secim == 2) {
                mesaj[i] = ((mesaj[i] - 'a' - anahtar + 26) % 26) + 'a';
            }
        }

        // buyuk harf kontrolunu burada hallediyoruz..
        else if (mesaj[i] >= 'A' && mesaj[i] <= 'Z') {

            if (secim == 1) {
                mesaj[i] = ((mesaj[i] - 'A' + anahtar) % 26) + 'A';
            }

            else if (secim == 2) {
                mesaj[i] = ((mesaj[i] - 'A' - anahtar + 26) % 26) + 'A';
            }
        }

        // harf degilse (bosluk vb.) ayni kalir, mesela 8 ise sonucumuz yine 8 kalir..
    }

    // yapilan isleme gore sonucu ekrana yazdiriyoruz
    if (secim == 1)
        printf("sifrelenmis mesaj sudur: %s", mesaj);
    else
        printf("cozulmus mesaj sudur: %s", mesaj);

    return 0;
}

