#include <stdio.h>
#include <stdlib.h>

// Çift yönlü bağlı liste düğümü
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Çift yönlü bağlı liste oluşturma
Node* createLinkedList() {
    return NULL;
}

// Yeni bir düğüm oluşturma
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Hafıza tahsisi başarısız!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Düğümü çift yönlü bağlı listeye ekleme
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Çift yönlü bağlı listeden düğümü çıkarma
void deleteNode(Node** head, int data) {
    Node* current = *head;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
    printf("Düğüm bulunamadı: %d\n", data);
}

// Çift yönlü bağlı listeyi yazdırma
void printList(Node* head) {
    printf("Çift Yönlü Bağlı Liste:\n");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* myList = createLinkedList();
    insertNode(&myList, 1);
    insertNode(&myList, 2);
    insertNode(&myList, 3);

    printf("Bağlı liste başlangıcı:\n");
    printList(myList);

    deleteNode(&myList, 2);

    printf("Bağlı liste son hali:\n");
    printList(myList);

    return 0;
}
