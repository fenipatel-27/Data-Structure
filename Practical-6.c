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
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=first;
    first=t;
}
void insert_last(int x)
{
    struct node *t,*y;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
        first=t;
    else
    {
        y=first;
        while(y->next!=NULL)
            y=y->next;
        y->next=t;
    }
}

void insert_at_position(int pos,int x)
{
    struct node *t,*y;
    int i;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    if(pos==1)
    {
        t->next=first;
        first=t;
    }
    else
    {
        y=first;
        for(i=1;i<pos-1 && y!=NULL;i++)
            y=y->next;
        if(y==NULL)
            printf("Invalid position");
        else
        {
            t->next=y->next;
            y->next=t;
        }
    }
}

void display()
{
    struct node *t;
    t=first;
    if(t==NULL)
        printf("List is empty");
    else
    {
        while(t!=NULL)
        {
            printf("%d->",t->data);
            t=t->next;
        }
        printf("NULL");
    }
}

void del_first()
{
    struct node *t;
    if(first==NULL)
        printf("List is empty");
    else
    {
        t=first;
        first=first->next;
        free(t);
    }
}

void del_last()
{
    struct node *t,*x;
    if(first==NULL)
        printf("List is empty");
    else if(first->next==NULL)
    {
        free(first);
        first=NULL;
    }
    else
    {
        x=first;
        while(x->next->next!=NULL)
            x=x->next;
        t=x->next;
        x->next=NULL;
        free(t);
    }
}
void del_pos(int pos)
{
    struct node *t,*x;
    int i;
    if(first==NULL)
        printf("List is empty");
    else if(pos==1)
    {
        t=first;
        first=first->next;
        free(t);
    }
    else
    {
        x=first;
        for(i=1;i<pos-1 && x!=NULL;i++)
            x=x->next;
        if(x==NULL || x->next==NULL)
            printf("Invalid position");
        else
        {
            t=x->next;
            x->next=t->next;
            free(t);
        }
    }
}

int main()
{
    int ch,x,pos;
    do
    {
        printf("\n\n1. Insert First");
        printf("\n2. Insert Last");
        printf("\n3. Insert At Position");
        printf("\n4. Delete First");
        printf("\n5. Delete Last");
        printf("\n6. Delete At Position");
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
                printf("Enter position: ");
                scanf("%d",&pos);
                printf("Enter data: ");
                scanf("%d",&x);
                insert_at_position(pos,x);
                break;

            case 4:
                del_first();
                break;

            case 5:
                del_last();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d",&pos);
                del_pos(pos);
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