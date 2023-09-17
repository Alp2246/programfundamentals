#include <stdio.h>
#include <stdlib.h>

int main() {
    // Bellek tahsisi
    int* dynamicArray = (int*)malloc(10 * sizeof(int));

    if (dynamicArray == NULL) {
        fprintf(stderr, "Bellek tahsis edilemedi.");
        return 1;
    }

    // Belleğe değer atama
    for (int i = 0; i < 10; i++) {
        dynamicArray[i] = i * 2;
    }

    // Bellek serbest bırakma
    free(dynamicArray);

    return 0;
}
