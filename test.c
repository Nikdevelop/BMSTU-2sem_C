#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list* next;
} list;

void add_el(list* head, int el)
{
    list* cur = head;
    while (cur->next != NULL)
        cur = cur->next;

    list* new = (list*)malloc(sizeof(list));
    new->data = el;
    new->next = NULL;
    
    cur->next = new;
}
void print_lst(list* head)
{
    list* cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}
int main(void)
{
    list* head = (list*)malloc(sizeof(list));
    head->data = 0;
    head->next = NULL;
    for (int i = 1; i < 10; ++i)
    {
        add_el(head, i);
    }
    print_lst(head);
    printf("\n");

    return 0;
}
