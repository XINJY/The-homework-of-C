#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode  *list1, *list2;

    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);

    return 0;
}
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2){
    struct ListNode *p=NULL,*head=NULL,*tail=NULL;
    int list[100],i=0,j=0,swap=0,count=0;
    while(list1!=NULL){
        list[i]=list1->data;
        list1=list1->next;
        i++;
        count++;
    }
    while(list2!=NULL){
        list[i]=list2->data;
        list2=list2->next;
        i++;
        count++;
    }
    for(i=0;i<count;i++){
        for(j=i+1;j<count;j++){
                if(list[i]>list[j]){
                    swap=list[i];list[i]=list[j];list[j]=swap;
                }
        }
    }
    for(i=0;i<count;i++){
        p=(struct ListNode*)malloc(sizeof(struct ListNode));
        p->data=list[i];
        p->next=NULL;
        if(head==NULL){
            head=p;
        }
        else{
            tail->next=p;
        }
        tail=p;
    }
    return head;
}
