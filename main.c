#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tek bir ürün için yapılacak tekliflerin maksimum sayısını belirtir.
#define MAX_TEKLIF_SAYISI 100

// Tek bir teklifin yapısını tanımlayan struct.
typedef struct {
    char ad[50];          // Teklifi yapan kişinin adı.
    float teklif_miktari; // Yapılan teklif miktarı.
} Teklif;

// Bir ürünün yapısını tanımlayan struct.
typedef struct {
    char urun_adi[100];      // Ürünün adı.
    float baslangic_fiyati;  // Ürünün başlangıç fiyatı.
    Teklif teklifler[MAX_TEKLIF_SAYISI]; // Üzerine yapılan tekliflerin listesi.
    int teklif_sayisi;       // Üzerine yapılan toplam teklif sayısı.
} Urun;

// Bir ürüne yeni bir teklif eklemek için kullanılan fonksiyon.
void teklifEkle(Urun *urun, const char *ad, float miktar) {
    if (urun->teklif_sayisi < MAX_TEKLIF_SAYISI) {
        strcpy(urun->teklifler[urun->teklif_sayisi].ad, ad); // Teklifi yapan kişinin adını kopyalar.
        urun->teklifler[urun->teklif_sayisi].teklif_miktari = miktar; // Yapılan teklif miktarını kaydeder.
        urun->teklif_sayisi++; // Teklif sayısını bir artırır.
    } else {
        printf("Maksimum teklif sayisina ulasildi!\n"); // Maksimum teklif sayısına ulaşıldığında uyarı mesajı.
    }
}

// Bir ürünün bilgilerini ekrana yazdırmak için kullanılan fonksiyon.
void urunBilgisiGoster(const Urun *urun) {
    printf("Urun Adi: %s\n", urun->urun_adi);
    printf("Baslangic Fiyati: %.2f\n", urun->baslangic_fiyati);
    printf("Teklif Sayisi: %d\n", urun->teklif_sayisi);

    // Üzerine yapılan teklifleri listeleyen döngü.
    for (int i = 0; i < urun->teklif_sayisi; i++) {
        printf("%s tarafindan %.2f teklif edildi.\n", urun->teklifler[i].ad, urun->teklifler[i].teklif_miktari);
    }
}

int main() {
    // "bilgisayar" adında bir ürün oluşturuldu ve başlangıç fiyatı belirlendi.
    Urun bilgisayar;
    strcpy(bilgisayar.urun_adi, "Dell Laptop");
    bilgisayar.baslangic_fiyati = 3000.0;
    bilgisayar.teklif_sayisi = 0; // Başlangıçta teklif sayısı sıfır olarak ayarlandı.

    // "bilgisayar" ürününe iki farklı kişi tarafından teklif yapıldı.
    teklifEkle(&bilgisayar, "Ahmet", 3100.0);
    teklifEkle(&bilgisayar, "Mehmet", 3150.0);

    // "bilgisayar" ürününün bilgileri ekrana yazdırıldı.
    urunBilgisiGoster(&bilgisayar);

    return 0;
}

