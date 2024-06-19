
# <h1 align="center">Hash Table</h1>
<p align="center">2311110051 - Ardelia Rachma Laksita</p>

## Table of Contents
1. [Penjelasan](#penjelasan)
2. [Contoh Program](#contoh-program)
3. [Penjelasan Alur Program](#penjelasan-alur-program)
4. [Referensi](#referensi)

# Penjelasan
Tabel hash adalah struktur data yang memetakan kunci ke nilai menggunakan fungsi hash [1]. Tabel hash menawarkan kompleksitas waktu kasus rata-rata O(1) untuk penyisipan, penghapusan, dan pengambilan data, menjadikannya alat penting dalam banyak algoritma dan aplikasi. Table hash membutuhkan parameter key untuk operasi kuncinya. Hash table menggunakan chaining digunakan untuk menyelesaikan kasus collision [2]. 

### Implementasi Hash Table:

![Cuplikan layar 2024-06-04 104155](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/88dcc3bc-3de3-4e90-9a72-ee3ca4936f31)

**Separate Chaining**

![Cuplikan layar 2024-06-04 104223](https://github.com/ardelialaksita/Praktikum-Struktur-Data-Assignment/assets/157208713/452e4f69-becd-4b46-88ce-9c98d4c559f4)


**_Sitasi : 3_**

Separate Chaining adalah konsep mempertahankan struktur data (daftar tertaut) untuk menampung semua pasangan nilai kunci untuk nilai hash tertentu [3]. Pada diagram di atas, kita memiliki nilai hash yang sama untuk alice dan bob, jadi kita telah membuat rantai terpisah untuk menyimpan semua nilai kunci untuk nilai hash 0.

**Open Addressing**

Open addressing adalah teknik lain untuk menyelesaikan masalah tabrakan (collision issues) [3]. Tabel hash terdiri dari serangkaian _array of buckets_, masing-masing dengan indeks unik. Indeks array ditentukan oleh fungsi hash yang mengambil kunci sebagai masukan dan mengembalikan nilai bilangan bulat.

Ketika _collision_ terjadi, elemen baru dimasukkan ke dalam array kosong berikutnya yang tersedia di tabel. Ada beberapa teknik untuk mencari array kosong berikutnya, seperti: _Linear probing_, _Quadratic probing_, dan _Double hashing_ [3].


# Contoh Program
```C++

```

# Penjelasan Alur Program


# Referensi