#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Kelas Hewan
class Animal {
public:
    string jenis;
    int timeAdd;

    Animal(string jenis, int timeAdd) {
        this->jenis = jenis;
        this->timeAdd = timeAdd;
    }

    friend ostream& operator<<(ostream& os, const Animal& animal) {
        os << animal.jenis << " masuk: " << animal.timeAdd;
        return os;
    }
};

// Kelas Shelter
class Queue {
public:
    queue<Animal> antrianHewan;

    // Menambahkan hewan ke shelter
    void enqueue(const Animal& animal) {
        antrianHewan.emplace(animal);
    }

    // Menghapus hewan tertua dari shelter
    Animal dequeueAny() {
        if (antrianHewan.empty()) {
            return Animal("", -1);
        }
        Animal hewanTertua = antrianHewan.front();
        antrianHewan.pop();
        return hewanTertua;
    }

    // Menghapus anjing tertua dari shelter
    Animal dequeueDog() {
        Animal foundDog("", -1); // Inisialisasi dengan Animal kosong
        queue<Animal> temp;
        while (!antrianHewan.empty()) {
            Animal hewan = antrianHewan.front();
            antrianHewan.pop();
            if (hewan.jenis == "Anjing") {
                foundDog = hewan;
                break;
            } else {
                temp.push(hewan);
            }
        }
        while (!temp.empty()) {
            Animal hewan = temp.front();
            temp.pop();
            antrianHewan.push(hewan);
        }
        return foundDog;
    }

    // Menghapus kucing tertua dari shelter
    Animal dequeueCat() {
        Animal foundCat("", -1); // Inisialisasi dengan Animal kosong
        queue<Animal> temp;
        while (!antrianHewan.empty()) {
            Animal hewan = antrianHewan.front();
            antrianHewan.pop();
            if (hewan.jenis == "Kucing") {
                foundCat = hewan;
                break;
            } else {
                temp.push(hewan);
            }
        }
        while (!temp.empty()) {
            Animal hewan = temp.front();
            temp.pop();
            antrianHewan.push(hewan);
        }
        return foundCat;
    }
};

// Program Utama
int main() {
    Queue shelter;

    // Menambahkan hewan ke shelter
    Animal animal1("Anjing", 50);
    Animal animal2("Kucing", 20);
    Animal animal3("Anjing", 30);

    shelter.enqueue(animal1);
    shelter.enqueue(animal2);
    shelter.enqueue(animal3);

    // Adopsi hewan tertua (tanpa memilih jenis)
    Animal adopsiHewan = shelter.dequeueAny();
    if (adopsiHewan.jenis != "") {
        cout << "Hewan yang diadopsi: " << adopsiHewan << endl;
    } else {
        cout << "Tidak ada hewan yang tersedia untuk diadopsi." << endl;
    }

    // Adopsi hewan tertua (memilih jenis)
    string jenisHewan;
    cout << "Pilih jenis hewan yang ingin diadopsi (Anjing/Kucing): ";
    cin >> jenisHewan;

    if (jenisHewan == "Anjing" || jenisHewan == "Kucing") {
        Animal adopsiHewanResult; // Gunakan nama yang berbeda
        if (jenisHewan == "Anjing") {
            adopsiHewanResult = shelter.dequeueDog();
        } else {
            adopsiHewanResult = shelter.dequeueCat();
        }

        if (adopsiHewanResult.jenis != "") {
            cout << "Hewan yang diadopsi: " << adopsiHewanResult << endl;
        } else {
            cout << "Tidak ada " << jenisHewan << " yang tersedia untuk diadopsi." << endl;
        }
    } else {
        cout << "Jenis hewan tidak valid." << endl;
    }

    return 0;
}
