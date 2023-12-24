#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tek bir �r�n i�in yap�lacak tekliflerin maksimum say�s�n� belirtir.
#define MAX_TEKLIF_SAYISI 100

// Tek bir teklifin yap�s�n� tan�mlayan struct.
typedef struct {
    char ad[50];          // Teklifi yapan ki�inin ad�.
    float teklif_miktari; // Yap�lan teklif miktar�.
} Teklif;

// Bir �r�n�n yap�s�n� tan�mlayan struct.
typedef struct {
    char urun_adi[100];      // �r�n�n ad�.
    float baslangic_fiyati;  // �r�n�n ba�lang�� fiyat�.
    Teklif teklifler[MAX_TEKLIF_SAYISI]; // �zerine yap�lan tekliflerin listesi.
    int teklif_sayisi;       // �zerine yap�lan toplam teklif say�s�.
} Urun;

// Bir �r�ne yeni bir teklif eklemek i�in kullan�lan fonksiyon.
void teklifEkle(Urun *urun, const char *ad, float miktar) {
    if (urun->teklif_sayisi < MAX_TEKLIF_SAYISI) {
        strcpy(urun->teklifler[urun->teklif_sayisi].ad, ad); // Teklifi yapan ki�inin ad�n� kopyalar.
        urun->teklifler[urun->teklif_sayisi].teklif_miktari = miktar; // Yap�lan teklif miktar�n� kaydeder.
        urun->teklif_sayisi++; // Teklif say�s�n� bir art�r�r.
    } else {
        printf("Maksimum teklif sayisina ulasildi!\n"); // Maksimum teklif say�s�na ula��ld���nda uyar� mesaj�.
    }
}

// Bir �r�n�n bilgilerini ekrana yazd�rmak i�in kullan�lan fonksiyon.
void urunBilgisiGoster(const Urun *urun) {
    printf("Urun Adi: %s\n", urun->urun_adi);
    printf("Baslangic Fiyati: %.2f\n", urun->baslangic_fiyati);
    printf("Teklif Sayisi: %d\n", urun->teklif_sayisi);

    // �zerine yap�lan teklifleri listeleyen d�ng�.
    for (int i = 0; i < urun->teklif_sayisi; i++) {
        printf("%s tarafindan %.2f teklif edildi.\n", urun->teklifler[i].ad, urun->teklifler[i].teklif_miktari);
    }
}

int main() {
    // "bilgisayar" ad�nda bir �r�n olu�turuldu ve ba�lang�� fiyat� belirlendi.
    Urun bilgisayar;
    strcpy(bilgisayar.urun_adi, "Dell Laptop");
    bilgisayar.baslangic_fiyati = 3000.0;
    bilgisayar.teklif_sayisi = 0; // Ba�lang��ta teklif say�s� s�f�r olarak ayarland�.

    // "bilgisayar" �r�n�ne iki farkl� ki�i taraf�ndan teklif yap�ld�.
    teklifEkle(&bilgisayar, "Ahmet", 3100.0);
    teklifEkle(&bilgisayar, "Mehmet", 3150.0);

    // "bilgisayar" �r�n�n�n bilgileri ekrana yazd�r�ld�.
    urunBilgisiGoster(&bilgisayar);

    return 0;
}

