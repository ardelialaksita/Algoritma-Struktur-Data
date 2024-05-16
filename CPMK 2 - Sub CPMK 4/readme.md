# <h1 align="center">Tugas CPMK 2 Sub CPMK 4 (Struct)</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Soal 1](#soal-1)
2. [Referensi](#referensi)

## Soal 1
### 1. Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct! (100 poin)
Struct atau struktur data adalah salah satu tipe data di C++ yang memungkinkan kita untuk menggabungkan beberapa tipe data yang berbeda menjadi satu kesatuan logis [2]. Isinya dapat berupa variabel dan fungsi sebagai anggota atau elemennya. Struct dapat digunakan untuk merepresentasikan data yang memiliki banyak elemen dan objek yang kompleks. Apabila ingin menambahkan struct ke dalam struct lain yang bertipe sama, operator relasional tidak bisa digunakan pada variabel struct [7]. Contohnya `if (mahasiswa == mahasiswaBaru)` adalah tindakan ilegal. 

Beberapa anggota dalam struct memungkinkan digunakan secara bersamaan. Struct termasuk data komposit dan lebih dikenali di C++ [4]. Dalam mengakses suatu _field_, notasi seperti berikut digunakan : **_Variabel_struct.namefield_** [3]. Pengikatan struct (struct _bindings_) memungkinkan pembongkaran elemen dari tuples, pairs, atau objects ke dalam variabel dengan nama terpisah sehingga dapat dibaca dengan mudah [1]. Sintaks ini menyederhanakan akses beberapa elemen yang dikembalikan dari suatu fungsi atau menguraikan struktur data yang kompleks [1]. Struct juga dapat meningkatkan kejelasan dari kode. 

Sebuah semikolon (yang berada setelah kurung kurawal kanan) sangat penting untuk mengakhiri statement struct [5]. Semikolon di akhir definisi struct merupakan bagian dari sintaks [8]. Pelabelan struct sama seperti tipe-tipe data C++ yang lain. Deklarasi suatu struct adalah definisi suatu tipe baru [6].

### Penerapan atau Penggunaan Struct :
- Struct memungkinkan anggota digunakan secara bersamaan.
- Anggota atau elemen struct dapat didefinisikan dengan tipe yang berbeda.
- Tipe struct yang telah didefinisikan dapat digunakan untuk mendeklarasikan variabel.
- Pada akhir statement struct harus menggunakan sebuah semikolon (;).

Kode Program
```C++

```



## Referensi
- [1] Farrier, J., Data Structures and Algorithms with the C++ STL. Edisi Pertama. Birmingham : Packt Publishing Ltd, 2024.
- [2] Guntara, R.G., Algoritma dan Pemrograman Dasar : Menggunakan Bahasa Pemrograman C++ dengan Contoh Kasus Aplikasi untuk Bisnis dan Manajemen. Edisi Pertama. Sulawesi Selatan : CV. Ruang Tentor, 2023.
- [3] Nengsih, Y.G., et al., Konsep Algoritma dan Pemrograman : Mengenal Konsep Dasar dan Praktis dalam Bahasa Pascal dan C. Edisi Pertama. Bandung : INDIE PRESS, 2022.
- [4] Putro, S.S. et al., Algoritma Pemrograman. Edisi Pertama. Malang : Media Nusa Creative (MNC Publishing), 2019.
- [5] Satrio, E. dan Pakpahan, S., Pemrograman C++ untuk Pembelajar Mandiri. Jakarta : Penerbit CAHAYA INFORMATIKA, 2019.
- [6] Siahaan, V. dan Sianipar, R.H., Buku Pintar Pemrograman C++. Sumatera Utara : Balige Publishing, 2020.
- [7] Siahaan, V. dan Sianipar, R.H., Pemrograman C++. Sumatera Utara : Sparta Publisher, 2019.
- [8] Siahaan, V. dan Sianipar, R.H., THREE COOKBOOKS IN ONE: Visual C++, Visual Basic, Visual C#. Sumatera Utara : Balige Publishing, 2020.