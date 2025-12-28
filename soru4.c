#include <stdio.h>
#include <string.h> //karakterdizisi icin olan kutuphane.. (olmazsa strleni kullanamazdik..)

int main() {

    char mesaj[100];   // girecegimiz mesaj (100 vermesem  kodlamada hata cikiyor fazla ama sallama bir sayi verelim..)
    int anahtar; //kac girersek girdigimiz seyi o harf sayisi kadar ileri atacak..
    int i;

    // oncelikle sifrelemek istedigimiz mesaji isteyip alalim..
    printf("sifrelemek istediginiz mesaji girin: ");
    fgets(mesaj, sizeof(mesaj), stdin); // fgets ile aldim cunku scanf bosluk koyunca patliyor..

    // simdi ise anahtar degerimizi isteyip alalim..
    printf("anahtar degerini girin: ");
    scanf("%d", &anahtar); // anahtar tek haneli olacagindan fgets kullanmadik../

    // mesajin her karakterini tek tek incelemek icin strlen kullandik..
    for (i = 0; i < strlen(mesaj); i++) {

        // kucuk harf kontrolunu burada hallediyoruz..
        if (mesaj[i] >= 'a' && mesaj[i] <= 'z') {
            mesaj[i] = ((mesaj[i] - 'a' + anahtar) % 26) + 'a'; //alfabeyi asarsa %26 ile basa saracak..mesela arda yazarsam anahtar sayisina ise 26 yazarsam sonucum arda olacak..
        }

        // buyuk harf kontrolunu burada hallediyoruz..
        else if (mesaj[i] >= 'A' && mesaj[i] <= 'Z') {
            mesaj[i] = ((mesaj[i] - 'A' + anahtar) % 26) + 'A';
       }

        // harf degilse (bosluk vb.) ayni kalir, mesela 8 ise sonucumuz yine 8 kalir..
    }

    printf("sifrelenmis mesaj sudur: %s", mesaj); // anahtar sayisi kadar one giden sifrelemenin son hali..

    return 0;
}
