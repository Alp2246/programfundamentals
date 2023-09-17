#include <iostream>
#include <memory>

int main() {
    // Akıllı işaretçi ile bellek tahsisi
    std::shared_ptr<int> smartPointer = std::make_shared<int[]>(10);

    // Belleğe değer atama
    for (int i = 0; i < 10; i++) {
        smartPointer.get()[i] = i * 2;
    }

    // Bellek otomatik olarak serbest bırakılır, işaretçiye endişe etmeye gerek yok.

    return 0;
}
