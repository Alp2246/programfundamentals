#include <iostream>

int main() {
    // Bellek tahsisi
    int* dynamicArray = new int[10];

    // Belleğe değer atama
    for (int i = 0; i < 10; i++) {
        dynamicArray[i] = i * 2;
    }

    // Bellek serbest bırakma
    delete[] dynamicArray;

    return 0;
}
