#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
void push(node** head, int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void printList(node* head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}
int LEQ(node* a, node* b){
    return ((a->data <= b->data)?1:0);
}
void qs(node * hd, node * tl, node ** rtn)
{
    int nlo, nhi;
    node *lo, *hi, *q, *p;

    /* Invariant:  Return head sorted with `tl' appended. */
    while (hd != NULL) {

        nlo = nhi = 0;
        lo = hi = NULL;
        q = hd;
        p = hd->next;

        /* Start optimization for O(n) behavior on sorted and reverse-of-sorted lists
        while (p != NULL && LEQ(p, hd)) {
            hd->next = hi;
            hi = hd;
            ++nhi;
            hd = p;
            p = p->next;
        }

        // If entire list was ascending, we're done.
        if (p == NULL) {
            *rtn = hd;
            hd->next = hi;
            q->next = tl;
            return;
        }
         End optimization.  Can be deleted if desired. */

        /* Partition and count sizes. */
        while (p != NULL) {
            q = p->next;
            if (LEQ(p, hd)) {
                p->next = lo;
                lo = p;
                ++nlo;
            } else {
                p->next = hi;
                hi = p;
                ++nhi;
            }
            p = q;
        }

        /* Recur to establish invariant for sublists of hd,
        choosing shortest list first to limit stack. */
        if (nlo < nhi) {
            qs(lo, hd, rtn);
            rtn = &hd->next;
            hd = hi;        /* Eliminated tail-recursive call. */
        } else {
            qs(hi, tl, &hd->next);
            tl = hd;
            hd = lo;        /* Eliminated tail-recursive call. */
        }
    }
    /* Base case of recurrence. Invariant is easy here. */
    *rtn = tl;
}
int main(){
    node* head = NULL;
    push(&head,1);
    push(&head,3);
    push(&head,5);
    push(&head,2);
    push(&head,4);
    printList(head);
    qs(head,NULL,&head);
    printList(head);
    return 0;
}
