#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Öğrenci bilgilerini tutan yapı (Class)
class Ogrenci {
public:
    int id;
    string ad;
    double vize;
    double final;
    double ortalama;

    Ogrenci(int _id, string _ad, double _vize, double _final) {
        id = _id;
        ad = _ad;
        vize = _vize;
        final = _final;
        ortalama = (vize * 0.4) + (final * 0.6);
    }

    void bilgileriGoster() const {
        cout << setw(5) << id << setw(15) << ad << setw(10) << vize 
             << setw(10) << final << setw(12) << fixed << setprecision(2) << ortalama << endl;
    }
};

// CRUD İşlemlerini Yöneten Sınıf
class OgrenciYonetimi {
private:
    vector<Ogrenci> ogrenciler;

public:
    // CREATE (Ekleme)
    void ogrenciEkle(int id, string ad, double vize, double final) {
        ogrenciler.push_back(Ogrenci(id, ad, vize, final));
        cout << "Ogrenci basariyla eklendi.\n";
    }

    // READ (Listeleme)
    void listele() {
        if (ogrenciler.empty()) {
            cout << "Kayitli ogrenci bulunamadi.\n";
            return;
        }
        cout << "\n--- Ogrenci Listesi ---\n";
        cout << setw(5) << "ID" << setw(15) << "Ad" << setw(10) << "Vize" 
             << setw(10) << "Final" << setw(12) << "Ortalama" << endl;
        cout << "--------------------------------------------------------\n";
        for (const auto& ogrenci : ogrenciler) {
            ogrenci.bilgileriGoster();
        }
    }

    // DELETE (Silme)
    void ogrenciSil(int id) {
        for (auto it = ogrenciler.begin(); it != ogrenciler.end(); ++it) {
            if (it->id == id) {
                ogrenciler.erase(it);
                cout << "ID: " << id << " olan ogrenci silindi.\n";
                return;
            }
        }
        cout << "Ogrenci bulunamadi!\n";
    }

    // UPDATE (Güncelleme)
    void notGuncelle(int id, double yeniVize, double yeniFinal) {
        for (auto& ogrenci : ogrenciler) {
            if (ogrenci.id == id) {
                ogrenci.vize = yeniVize;
                ogrenci.final = yeniFinal;
                ogrenci.ortalama = (yeniVize * 0.4) + (yeniFinal * 0.6);
                cout << "Notlar guncellendi.\n";
                return;
            }
        }
        cout << "Ogrenci bulunamadi!\n";
    }
};

int main() {
    OgrenciYonetimi sistem;
    int secim, id;
    string ad;
    double vize, final;

    while (true) {
        cout << "\n--- Ogrenci Kayit Sistemi ---\n";
        cout << "1. Ogrenci Ekle\n2. Ogrencileri Listele\n3. Not Guncelle\n4. Ogrenci Sil\n5. Cikis\n";
        cout << "Seciminiz: ";
        cin >> secim;

        if (secim == 5) break;

        switch (secim) {
            case 1:
                cout << "ID: "; cin >> id;
                cout << "Ad: "; cin >> ad;
                cout << "Vize: "; cin >> vize;
                cout << "Final: "; cin >> final;
                sistem.ogrenciEkle(id, ad, vize, final);
                break;
            case 2:
                sistem.listele();
                break;
            case 3:
                cout << "Guncellenecek ID: "; cin >> id;
                cout << "Yeni Vize: "; cin >> vize;
                cout << "Yeni Final: "; cin >> final;
                sistem.notGuncelle(id, vize, final);
                break;
            case 4:
                cout << "Silinecek ID: "; cin >> id;
                sistem.ogrenciSil(id);
                break;
            default:
                cout << "Gecersiz secim!\n";
        }
    }

    return 0;
}
