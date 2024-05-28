#include <stdio.h>
struct node //Constructing node's parts using struct  for linked list
{
    int info;
    struct node *link;
};

struct node n1,n2,n3; // declaring nodes 

void print_node(struct node *n) // Function to print node info values by using its link parts
{
    while(n!= NULL)
    {
        printf("%d ", n->info);
        n = n->link;
    }
    printf("\n");
}

int main() //Giving values to info part and linking the nodes to each other
{
    n1.info=10;
    n2.info=20;
    n3.info=30;
    n1.link=&n2;
    n2.link=&n3;
    n3.link=NULL;
    print_node(&n1);
    return 0;
}
