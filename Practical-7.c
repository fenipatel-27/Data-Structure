#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *first=NULL;
void insert_first(int x)
{
    struct node *t,*y;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    if(first==NULL)
    {
        first=t;
        t->next=first;
    }
    else
    {
        y=first;
        while(y->next!=first)
            y=y->next;
        t->next=first;
        y->next=t;
        first=t;
    }
}
void insert_last(int x)
{
    struct node *t,*y;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    if(first==NULL)
    {
        first=t;
        t->next=first;
    }
    else
    {
        y=first;
        while(y->next!=first)
            y=y->next;
        y->next=t;
        t->next=first;
    }
}
void insert_after(int x,int y)
{
    struct node *t,*z;
    if(first==NULL)
    {
        printf("List is empty");
        return;
    }
    z=first;
    do
    {
        if(z->data==x)
        {
            t=(struct node*)malloc(sizeof(struct node));
            t->data=y;
            t->next=z->next;
            z->next=t;
            return;
        }
        z=z->next;
    }while(z!=first);
    printf("Node not found");
}
void del_first()
{
    struct node *t,*x;
    if(first==NULL)
        printf("List is empty");
    else if(first->next==first)
    {
        free(first);
        first=NULL;
    }
    else
    {
        x=first;
        while(x->next!=first)
            x=x->next;
        t=first;
        first=first->next;
        x->next=first;
        free(t);
    }
}
void del_last()
{
    struct node *t,*x;
    if(first==NULL)
        printf("List is empty");
    else if(first->next==first)
    {
        free(first);
        first=NULL;
    }
    else
    {
        x=first;
        while(x->next->next!=first)
            x=x->next;
        t=x->next;
        x->next=first;
        free(t);
    }
}
void del_after(int x)
{
    struct node *t,*y;
    if(first==NULL)
    {
        printf("List is empty");
        return;
    }
    y=first;
    do
    {
        if(y->data==x)
        {
            t=y->next;
            if(t==first)
                first=first->next;
            y->next=t->next;
            free(t);
            return;
        }
        y=y->next;
    }while(y!=first);
    printf("Node not found");
}
void display()
{
    struct node *t;
    if(first==NULL)
    {
        printf("List is empty");
        return;
    }
    t=first;
    do
    {
        printf("%d->",t->data);
        t=t->next;
    }while(t!=first);
    printf("first");
}
int main()
{
    int ch,x,y;
    do
    {
        printf("\n\n1. Insert First");
        printf("\n2. Insert Last");
        printf("\n3. Insert After Given Node");
        printf("\n4. Delete First");
        printf("\n5. Delete Last");
        printf("\n6. Delete Node After Given Node");
        printf("\n7. Display");
        printf("\n8. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&x);
                insert_first(x);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d",&x);
                insert_last(x);
                break;

            case 3:
                printf("Enter given node: ");
                scanf("%d",&x);
                printf("Enter data: ");
                scanf("%d",&y);
                insert_after(x,y);
                break;

            case 4:
                del_first();
                break;

            case 5:
                del_last();
                break;

            case 6:
                printf("Enter given node: ");
                scanf("%d",&x);
                del_after(x);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exit");
                break;

            default:
                printf("Invalid choice");
        }
    }while(ch!=8);
    return 0;
}