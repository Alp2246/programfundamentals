#include <iostream>

class Singleton {
private:
    static Singleton* instance;
    Singleton() {} // Örneğin sadece bu sınıf içinde oluşturulmasını sağlar.

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() {
        std::cout << "Merhaba, Singleton!" << std::endl;
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* singleton = Singleton::getInstance();
    singleton->showMessage();

    return 0;
}
