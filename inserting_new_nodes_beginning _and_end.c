#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node *link;
};

void trav(struct node *node)
{
    struct node *ptr=node;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->info);
        ptr=ptr->link;
    }
    printf("\n");
}

void insert(struct node **head, int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = value;
    temp->link = NULL;

    if(*head == NULL) 
    {
        *head = temp;
    } 
    else 
    {
        struct node *p = *head;
        while(p->link!= NULL) 
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void insert_at_beginning(struct node **head, int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = value;
    temp->link = *head;
    *head = temp;
}

int main() 
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node *head = NULL;
    for(int i = 0; i < n; i++) 
    {
        int value;
        printf("Enter the value for node %d: ", i+1);
        scanf("%d", &value);
        insert(&head, value);
    }
    trav(head);

    int value;
    printf("Enter the value to insert at beginning: ");
    scanf("%d", &value);
    insert_at_beginning(&head, value);
    trav(head);

    printf("Enter the value to insert at end: ");
    scanf("%d", &value);
    insert(&head, value);
    trav(head);

    return 0;
}
