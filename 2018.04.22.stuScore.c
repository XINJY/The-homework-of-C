#include <stdio.h>
#include <stdlib.h>

struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};

struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );

int main()
{
    int min_score;
    struct stud_node *p, *head = NULL;

    head = createlist();
    scanf("%d", &min_score);
    head = deletelist(head, min_score);
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

struct stud_node *createlist()
{
    struct stud_node *head, *tail, *q;
    head = NULL;
    tail = NULL;
    int num;
    scanf ("%d", &num);
    while (num != 0)
    {
        q = (struct stud_node *)malloc (sizeof (struct stud_node));
        scanf ("%s %d", q->name, &q->score);
        q->num = num;
        q->next = NULL;
        if (head == NULL){
            head = q;
        }
        else{
            tail->next = q;
        }
        tail = q;
        scanf ("%d", &num);
    }
    return head;
}
struct stud_node *deletelist( struct stud_node *head, int min_score )
{
    struct stud_node *ptr1, *ptr2;
    while (head != NULL && head->score < min_score)
    {
        ptr2 = head;
        head = head->next;
        free(ptr2);
    }
    if (head == NULL){
        return NULL;
    }
    ptr1 = head;
    ptr2 = head->next;
    while (ptr2 != NULL)
    {
        if (ptr2->score < min_score) {
            ptr1->next = ptr2->next;
            free(ptr2);
        }
        else{
             ptr1 = ptr2;
        }
        ptr2 = ptr1->next;
    }
    return head;
}
