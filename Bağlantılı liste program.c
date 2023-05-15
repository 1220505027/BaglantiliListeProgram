#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

void ekle(struct LinkedList* list, int data) {
    struct Node* yeniDugum = (struct Node*)malloc(sizeof(struct Node));
    if (yeniDugum == NULL) {
        printf("Hata: Bellek tahsisi basarisiz.\n");
        return;
    }
    
    yeniDugum->data = data;
    yeniDugum->next = NULL;

    if (list->head == NULL) {
        list->head = yeniDugum;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = yeniDugum;
    }

    printf("%d degeri eklendi.\n", data);
}

void sil(struct LinkedList* list, int data) {
    if (list->head == NULL) {
        printf("Hata: Baglantili liste bos.\n");
        return;
    }

    if (list->head->data == data) {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        printf("%d degeri silindi.\n", data);
        return;
    }

    struct Node* current = list->head;
    struct Node* prev = NULL;
    
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("%d degeri bulunamadi.\n", data);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("%d degeri silindi.\n", data);
}

void goruntule(struct LinkedList* list) {
    struct Node* current = list->head;

    if (current == NULL) {
        printf("Baglantili liste bos.\n");
        return;
    }

    printf("Baglantili liste: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct LinkedList list;
    list.head = NULL;
    int secim, data;

    while (1) {
        printf("1. Ekle\n");
        printf("2. Sil\n");
        printf("3. Goruntule\n");
        printf("4. Cikis\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Eklenecek degeri giriniz: ");
                scanf("%d", &data);
                ekle(&list, data);
                break;
            case 2:
                printf("Silinecek degeri giriniz: ");
                scanf("%d", &data);
                sil(&list, data);
                break;
            case 3:
                goruntule(&list);
                break;
            case 4:
                printf("Program sonlandiriliyor.\n");
                exit(0);
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    }

    return 0;
}
