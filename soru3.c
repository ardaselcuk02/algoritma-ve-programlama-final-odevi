#include <stdio.h>
//amacimiz ucharfli tum kombinasyonlari gezegenbobun verdigi kurallara gore tanimlamak..

// harf unlu mu diye kontrol eden fonksiyonu burada tanimladik..
int unlumu(char c) { // fonksiyon yazdik kodtekrari olmasin..
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'); //unlu harfleri tanimladik
}

// sayi asal mi diye kontrol eden fonksiyonu ise burada tanimladik..
int asalmi(int n) { // ayni sekilde kod trkrari olmasin diyr burada da fonksiyon tanimladik..
    if (n < 2)
        return 0;

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {//fonkSiYONLARIMIZI burada kullancaz..

    char a, b, c;
    int sayac = 0; // geccerli isim sayisi..

    // adan zye kadar tum 3 harfli kelime kombinasyyonlari..
    for (a = 'a'; a <= 'z'; a++) { // bu dongu ismin birinci harfinin adan zye kadar olan tum olasiliklarini gezer..
        for (b = 'a'; b <= 'z'; b++) { // bu dongu ismin ikinci harfinin adan zye kadar olan tum olasiliklarini gezer..

            for (c = 'a'; c <= 'z'; c++) { // bu dongu ismin ucuncu harfinin adan zye kadar olan tum olasiliklarini gezer. bu uc dongu ile aaa ile zzzarasi uc tane harf urettik..


                if (a != c) // gezegen boba gore 1. ve 3. harf ayni olmak zorunda.. continue kullandim ki ayni olmadigi anda bir sonraki uclemeye gecsin..
                    continue;

                // unlu-unlu-unlu veya unsuz-unsuz-unsuz istemiyoruz
                // sadece: unlu-unsuz-unlu veya unsuz-unlu-unsuz olacak..
                if ( (unlumu(a) && !unlumu(b) && unlumu(c)) ||
                     (!unlumu(a) && unlumu(b) && !unlumu(c)) ) {

                    // asci degerlerini topluyoruz
                    int toplam = a + b + c; //dogrudan harfleri girerek asci toplamini uyguladik..

                    // toplam asal mi kontrolunu yapiyoruz..
                    if (asalmi(toplam)==1) { // gezegene gore uc harfin ascii sayinin da toplami asal olmali..
                        printf("%c%c%c\n", a, b, c);
                        sayac++; // ucleme uyuyorsa ekrana yazdirip sayaci 1 arttiriyoruz..
                    }
                }
            }
        }
    }

    // toplam gecerli isim sayisi
    printf("toplam gecerli isim sayisi: %d\n", sayac);

    return 0;
}
