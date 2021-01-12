#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int angka;
    node *next;
} *head, *tail;

node *createnode(int angka){
    node *newnode=(node*)malloc(sizeof(node));
    newnode -> angka = angka;
    newnode -> next = NULL;
    return newnode;
}
void pushhead (int angka){

    node *temp = createnode(angka);
    if(!head){
        head = tail = temp;
    }
    else{
        temp -> next = head;
        head = temp;
    }

}

void pushtail (int angka){

    node *temp = createnode(angka);
    if(!head){
        head = tail = temp;
    }
    else{
        tail-> next = temp;
        head = temp;
    }

}

void mid(){
    node *bawah = head;
    node *atas  = head;
    if (head != NULL){
        while (atas != NULL && atas ->next != NULL){
            atas = atas->next->next;
            bawah = bawah->next;
        }

        printf (" Elemen tengah dari link-list is %d\n", bawah->next);
    }
}

void printList(struct node *atas)  
{  
    while (atas != NULL)  
    {  
        printf("%d->", atas->angka);  
        atas = atas->next;  
    }  
    printf("NULL\n");  
}  

void printMiddle(struct node *head)  
{  
     node *bawah = head;  
     node *atas = head;  
  
    if (head!=NULL)  
    {  
        while (atas != NULL && atas->next != NULL)  
        {  
            atas = atas->next->next;  
            bawah = bawah->next;  
        }  
        printf("");
        printf("The middle element is %d\n", bawah->angka);  
    }  
}  


int main(){
   pushhead(10);
   pushhead(25);
   pushhead(50);
   pushhead(44);
   pushhead(46);
   printList(head);
   printMiddle(head);
   return 0;
}
