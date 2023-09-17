#include <iostream>
#include <cstring>

// Öğrenci veri yapısı
struct Student {
    char* name;
    int age;
};

// Öğrenci bilgilerini dinamik olarak oluşturan fonksiyon
Student* createStudent(const char* name, int age) {
    Student* student = new Student;
    student->name = new char[strlen(name) + 1];
    strcpy(student->name, name);
    student->age = age;
    return student;
}

// Öğrenci bilgilerini ekrana yazdıran fonksiyon
void printStudent(const Student* student) {
    std::cout << "Öğrenci Adı: " << student->name << std::endl;
    std::cout << "Öğrenci Yaşı: " << student->age << std::endl;
}

// Öğrenci belleğini serbest bırakan fonksiyon
void deleteStudent(Student* student) {
    delete[] student->name;
    delete student;
}

int main() {
    // Öğrenci bilgilerini oluştur
    Student* student1 = createStudent("Ahmet", 20);
    Student* student2 = createStudent("Mehmet", 22);

    // Öğrenci bilgilerini ekrana yazdır
    std::cout << "Öğrenci 1 Bilgileri:" << std::endl;
    printStudent(student1);

    std::cout << "\nÖğrenci 2 Bilgileri:" << std::endl;
    printStudent(student2);

    // Belleği serbest bırak
    deleteStudent(student1);
    deleteStudent(student2);

    return 0;
}
