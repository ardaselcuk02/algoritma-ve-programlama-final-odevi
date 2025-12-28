#include <stdio.h>

#define boyut 5

// labirenti burada tanimliyoruz..
// 1 gidilebilir yol, 0 engel demek..
int labirent[boyut][boyut] = {
    {1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1}
};

// cozumu gostermek icin ayri bir dizi kullaniyoruz..
int yol[boyut][boyut] = {0};

// bu fonksiyon verdigimiz konum gecerli mi diye bakiyor..
int gecerlimi(int x, int y) {
    // sinirlar icindeyse ve yolsa true doner..
    if (x >= 0 && x < boyut && y >= 0 && y < boyut && labirent[x][y] == 1)
        return 1;

    return 0;
}

// labirenti cozmek icin rekursif fonksiyon yazdik..
int labirentcoz(int x, int y) {

    // cikis noktasina ulastiysak ..
    if (x == boyut - 1 && y == boyut - 1) {
        yol[x][y] = 1;
        return 1;
    }

    // bulundugumuz yer uygunsa..
    if (gecerlimi(x, y)) {

        // bu hucreyi yolun parcasi olarak isaretliyoruz..
        yol[x][y] = 1;

        // saga gitmeyi deniyoruz..
        if (labirentcoz(x, y + 1))
            return 1;

        // asagi gitmeyi deniyoruz..
        if (labirentcoz(x + 1, y))
            return 1;

        // sola gitmeyi deniyoruz..
        if (labirentcoz(x, y - 1))
            return 1;

        // yukari gitmeyi deniyoruz..
        if (labirentcoz(x - 1, y))
            return 1;

        // hicbir yol olmazsa geri donuyoruz..
        yol[x][y] = 0;
        return 0;
    }

    return 0;
}

// cozumu ekrana bastiran fonksiyon..
void yoluyazdir() {
    for (int i = 0; i < boyut; i++) {
        for (int j = 0; j < boyut; j++) {
            printf("%d ", yol[i][j]);
        }
        printf("\n");
    }
}

int main() {

    // baslangic noktasi (0,0)..
    if (labirentcoz(0, 0)) {
        printf("cikis yolu bulundu:\n");
        yoluyazdir();
    }
    else {
        printf("cikis yolu bulunamadi..\n");
    }

    return 0;
}
