#include <iostream>
#include <queue>
using namespace std;

// PROGRAM ADOPSI KUCING DAN / ATAU ANJING
// class animal
class animal {
public:
    // deklarasi jenis dan waktu masuk (timeIn)
    string jenis;
    int timeIn;

    // kelola antrian
    animal(string jenis, int timeIn) {
        this->jenis = jenis;
        this->timeIn = timeIn;
    }

    friend ostream& operator<<(ostream& os, const animal& animal) {
        os << animal.jenis << " masuk: " << animal.timeIn;
        return os;
    }
};

class Queue {
public:
    queue<animal> antrianHewan;

    // tambah hewan ke antrian
    void enqueue(const animal& animal) {
        antrianHewan.push(animal);
    }

    // hapus hewan dari antrian (bisa kucing maupun anjing)
    animal dequeueAny() {
        if (antrianHewan.empty()) {
            return animal("", -1);
        }
        animal hewanTertua = antrianHewan.front();
        antrianHewan.pop();
        return hewanTertua;
    }

    // hapus anjing dari antrian
    animal dequeueDog() {
        queue<animal> tempQueue;
        animal foundAnimal("", -1);
        while (!antrianHewan.empty()) {
            animal currentAnimal = antrianHewan.front();
            antrianHewan.pop();
            if (currentAnimal.jenis == "Anjing" && foundAnimal.jenis == "") {
                foundAnimal = currentAnimal;
            } else {
                tempQueue.push(currentAnimal);
            }
        }
        swap(antrianHewan, tempQueue);
        return foundAnimal;
    }

    // hapus kucing dari antrian
    animal dequeueCat() {
        queue<animal> tempQueue;
        animal foundAnimal("", -1);
        while (!antrianHewan.empty()) {
            animal currentAnimal = antrianHewan.front();
            antrianHewan.pop();
            if (currentAnimal.jenis == "Kucing" && foundAnimal.jenis == "") {
                foundAnimal = currentAnimal;
            } else {
                tempQueue.push(currentAnimal);
            }
        }
        swap(antrianHewan, tempQueue);
        return foundAnimal;
    }
};

// main program (program utama)
int main() {
    Queue Queue;

    // masukkan jumlah hewan anjing dan kucing ke dalam antrian
    animal animal1("Anjing", 50);
    animal animal2("Kucing", 20);
    animal animal3("Anjing", 30);

    // tambahkan hewan ke dalam antrian
    Queue.enqueue(animal1);
    Queue.enqueue(animal2);
    Queue.enqueue(animal3);

    // adopsi hewan tertua (tidak memilih jenis hewan)
    animal adopsiHewan = Queue.dequeueAny();
    if (adopsiHewan.jenis != "") {
        cout << "Hewan yang diadopsi: " << adopsiHewan << endl;
    } else {
        cout << "Tidak ada hewan yang tersedia untuk diadopsi." << endl;
    }

    // adopsi hewan tertua (memilih jenis hewan)
    string jenisHewan;
    cout << "Pilih jenis hewan yang ingin diadopsi (Anjing/Kucing): ";
    cin >> jenisHewan;

    // jika user memasukkan anjing atau kucing
    if (jenisHewan == "Anjing" || jenisHewan == "Kucing") {
        animal adopsiHewan;
        // jika user memasukkan "Anjing", maka menjalankan dequeueDog
        if (jenisHewan == "Anjing") {
            adopsiHewan = Queue.dequeueDog();
        } 
        // jika user memasukkan "Kucing", maka menjalankan dequeueCat
        else {
            adopsiHewan = Queue.dequeueCat();
        }

        // input jenis hewan yang ingin diadopsi
        if (adopsiHewan.jenis != "") {
            cout << "Hewan yang diadopsi: " << adopsiHewan << endl;
        } else {
            cout << "Tidak ada " << jenisHewan << " yang tersedia untuk diadopsi." << endl;
        }
    } else {
        cout << "Jenis hewan tidak valid." << endl;
    }

    return 0;
}
