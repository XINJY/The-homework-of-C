#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}
struct ListNode *readlist(){
    int num=0;
    struct ListNode *head=NULL, *p=NULL, *tail=NULL;
    p = (struct ListNode*)malloc(sizeof(struct ListNode));
    scanf("%d", &num);
    while(num != -1){
        p->data = num;
        p->next=NULL;
        if(head == NULL){
            head=p;
        }
        else{
            tail->next=p;
        }
        tail=p;
        p=(struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &num);
    }
    free(p);
    return head;
}
  struct ListNode *getodd(struct ListNode **L){
      int n = 0;
      struct ListNode *head=NULL, *tail=NULL, *q=NULL, *p=*L, *p1=NULL, *p2=NULL, *ptr=NULL;

      while (p!=NULL)
      {
          if (p->data % 2 != 0)
          {
              q = (struct ListNode *) malloc(sizeof(struct ListNode));
              q->data = p->data;
              q->next = NULL;
              if (head == NULL){
                head = q;
              }
              else{
                tail->next = q;
              }
              tail = q;
              ptr = p;
              p = p->next;
              free(ptr);
          }
          else
          {
              if (p1 == NULL){
                p1 = p;
              }
              else{
                p2->next = p;
              }
              p2 = p;
              p = p->next;
              n = 1;
          }
      }
      if (n==1){
        p2->next = NULL;
      }
      *L = p1;
      return head;
  }
