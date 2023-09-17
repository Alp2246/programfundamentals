#include <stdio.h>

// İki alt diziyi birleştiren fonksiyon
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Geçici diziler oluştur
    int leftArray[n1], rightArray[n2];

    // Verileri geçici dizilere kopyala
    for (i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        rightArray[j] = arr[middle + 1 + j];
    }

    // İki alt diziyi birleştir
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Geriye kalan elemanları kopyala (eğer varsa)
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Merge Sort algoritması
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // İlk yarıyı sırala
        mergeSort(arr, left, middle);

        // İkinci yarıyı sırala
        mergeSort(arr, middle + 1, right);

        // İki sıralı yarıyı birleştir
        merge(arr, left, middle, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Dizinin sıralanmamış hali:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("\nDizinin sıralanmış hali:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
