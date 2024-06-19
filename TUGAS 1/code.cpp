// Ardelia Rachma Laksita
// 2311110051 (S1SD-04 A)

#include <iostream>
#include <algorithm>

using namespace std;

bool cekDuplikat(int arr[]) {
  int panjangArr = 4;

  sort(arr, arr + panjangArr);

  for (int i = 0; i < panjangArr - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      return true;
    }
  }

  return false;
}

int main(void) {
  int arrA[] = {2, 1, 3, 1};
  cout << cekDuplikat(arrA);
  return 0;
}
