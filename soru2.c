#include <stdio.h>

// bolum 1: rekursif hesaplama ..
int ucgensayihesapla(int n) {
    // n 1 olursa ucgen sayisi zaten 1 olacagi icin direk 1 donduruyoruz ..
    if (n == 1) return 1;

    // n ile bir onceki ucgen sayisini toplayarak devam ediyoruz ..
    return n + ucgensayihesapla(n - 1);
}

// bolum 2: duzgun hizalanmis ucgen cizimi ..
void ucgenciz(int n) {
    // burada 2.2 alistirmasi icin ucgen seklini ciziyoruz ..
    printf("\n sekil cizimi (alistirma 2.2) \n");

    // ekrana yazdirilacak sayilari sirayla takip etmek icin sayac kullandim ..
    int sayac = 1;

    // satir sayisi kadar donen ana dongu ..
    for (int i = 1; i <= n; i++) {

        // ucgen gorunumunu ortalamak icin her satirda bosluk birakiyoruz ..
        for (int bosluk = 1; bosluk <= n - i; bosluk++) {
            printf("  "); // sayilar buyudukce kayma olmasin diye iki bosluk bastim ..
        }

        // her satira i kadar sayi yazdiriyoruz ..
        for (int j = 1; j <= i; j++) {
            // %3d kullanarak sayilarin hizali gorunmesini sagladim ..
            printf("%3d ", sayac);
            sayac++; // her yazdirmadan sonra sayaci arttiriyoruz ..
        }

        // her satirdan sonra alt satira geciyoruz ..
        printf("\n");
    }
}

int main() {
    int n;

    // kullanicidan kac tane ucgen sayi istedigini aliyoruz ..
    printf("n degerini giriniz (orn: 10): ");
    scanf("%d", &n);

    // alistirma 2.1 icin ucgen sayi listesini yazdiriyoruz ..
    printf("\n--- ucgen sayi dizisi (2.1) ---\n");
    printf("ilk %d ucgen sayi: ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", ucgensayihesapla(i));
    }
    printf("\n");

    // alistirma 2.2 icin ucgen seklini ciziyoruz ..
    ucgenciz(n);

    return 0;
}
