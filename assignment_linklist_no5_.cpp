#include<stdio.h>
#include<stdlib.h>

struct node {
    int nilai;
    node* next;
}*head = NULL, * tail = NULL;

node* createnode(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->nilai = value;
    temp->next = NULL;
    return temp;
}

void pushhead(int value) {
    node* temp = createnode(value);
    if (!head) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void pushtail(int value) {
    node* temp = createnode(value);
    if (!tail) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}
void printall() {
    if (!head) {
        return;
    }
    node* temp = head;
    while (temp) {
        if (!temp->next) {
            printf("%d\n", temp->nilai);
        }
        else {
            printf("%d -> ", temp->nilai);
        }
        temp = temp->next;
    }
}

void printnth(int index) {
    node* temp = head;
    int panjang = 1;
    while (temp->next) {
        temp = temp->next;
        panjang++;
    }
    panjang -= index;
    if (panjang < 0) {
        return;
    }
    node* temp2 = head;
    while (panjang != 0) {
        temp2 = temp2->next;
        panjang--;
    }
    printf("%d\n", temp2->nilai);
}

int main() {
    int index;
    pushhead(60);
    pushhead(70);
    pushhead(80);
    pushhead(90);
    pushhead(100);
    printall();
    printf("Masukkan index: ", index);
    scanf("%d", &index);
    printf("Index dari %d: ", index);
    printnth(index);

    return 0;
}