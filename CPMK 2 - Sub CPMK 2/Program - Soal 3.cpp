#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// PROGRAM SORTING DAN CEK ANAGRAM DARI DUA BUAH ARRAY OF STRINGS

// fungsi mengecek anagram
vector<string> cekAnagram(const vector<string>& array1, const vector<string>& array2) {
    // memastikan panjang kedua array sama
    if (array1.size() != array2.size()) {
        vector<string> result(array1.size(), "tidak anagram");
        return result;
    }

    vector<string> result(array1.size());
    // for looping untuk ubah semua string menjadi huruf kecil serta mengurutkan karakternya
    for (size_t i = 0; i < array1.size(); i++) {
        // deklarasi string 1 dan string 2
        string string1 = array1[i];
        string string2 = array2[i];
        
        // konversi string ke huruf kecil
        transform(string1.begin(), string1.end(), string1.begin(), ::tolower);
        transform(string2.begin(), string2.end(), string2.begin(), ::tolower);
        
        // urutkan string
        sort(string1.begin(), string1.end());
        sort(string2.begin(), string2.end());

        // bandingkan apakah kedua string merupakan anagram atau tidak
        // jika string 1 sama dengan string 2, maka anagram
        if (string1 == string2) {
            result[i] = "anagram";
        } 
        // jika string 1 tidak sama dengan string 2, maka tidak anagram
        else {
            result[i] = "tidak anagram";
        }
    }
    return result;
}

// main program (program utama)
int main() {
    // isi string 1 
    vector<string> string1 = {"bahu", "makan"};
    // isi string 2
    vector<string> string2 = {"buah", "minum"};
    
    // panggil fungsi pengecekan anagram
    vector<string> result = cekAnagram(string1, string2);
    
    // for looping untuk mencetak hasil
    for (size_t i = 0; i < string1.size(); ++i) {
        cout << "String 1: " << string1[i] << endl;
        cout << "String 2: " << string2[i] << endl;
        cout << "Result  : " << result[i] << endl;
        cout << endl;
    }
    return 0;
}
