#include <iostream>
#include <vector>
#include <string>
using namespace std;

// fungsi binary search untuk menemukan kayta
void binarysearch(const vector<string>& dataArray, const string& word) {
    int left = 0;
    int right = static_cast<int>(dataArray.size()) - 1;

    // apabila data di sisi kiri lebih kecil atau sama dengan data kanan
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // jika elemen tengah adalah string kosong, cari elemen non-kosong di sekitarnya
        if (dataArray[mid].empty()) {
            int l = mid - 1;
            int r = mid + 1;

            while (true) {
                if (l < left && r > right) {
                    cout << "\nData tidak ditemukan\n";
                    return; 
                } else if (r <= right && !dataArray[r].empty()) {
                    mid = r;
                    break;
                } else if (l >= left && !dataArray[l].empty()) {
                    mid = l;
                    break;
                }
                r++;
                l--;
            }
        }

        // perbandingan menggunakan binary search 
        // jika array di tengah (setelah diurutkan) memiliki isi yang sama seperti kata yang dicari
        if (dataArray[mid] == word) {
            // mencetak data ditemukan pada index ke berapa
            cout << "\nData ditemukan pada index ke- " << mid << endl;
            return;
        } 
        // jika array di tengah (setelah diurutkan) lebih kecil daripda kata yang dicari
        else if (dataArray[mid] < word) {
            // pencarian dilakukan pada sisi bagian kiri dengan operasi mid array + 1
            left = mid + 1;
        } 
        // pencarian dilakukan pada sisi bagian kanan dengan operasi mid array - 1
        else {
            right = mid - 1;
        }
    }

    // tampilkan data tidak ditemukan jika data tidak ada di dalam array
    cout << "\nData tidak ditemukan\n";
}

// fungsi void untuk menampilkan data array 
void cetakdata(const vector<string>& data) {
    cout << "Data: {";
    for (size_t i = 0; i < data.size(); ++i) {
        cout << "\"" << data[i] << "\"";
        if (i != data.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

// main program (program utama)
int main() {
    // deklarasi word
    string word;
    
    // cetak header pada program
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "================ Program Mencari Kata Menggunakan Binary Search =====================" << endl;
    
    // data yang mengandung string kosong
    vector<string> dataArray = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};

    // panggil fungsi cetakData
    cetakdata(dataArray);
    
    // input kata yang ingin dicari
    cout << "Kata apa yang ingin Anda cari pada data tersebut? : ";
    cin >> word;

    // panggil fungsi untuk lakukan pencarian dengan binary search
    binarysearch(dataArray, word);

    // cetak footer pada program
    cout << "-------------------------------------------------------------------------------------" << endl;

    return 0;
}
