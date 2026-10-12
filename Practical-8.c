#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *left, *right;
};
struct node *root = NULL;
struct node *createnode(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = x;
    temp->left = temp->right = NULL;
    return temp;
}
void setleft(struct node *t, int x)
{
    struct node *p;
    p = createnode(x);
    t->left = p;
}
void setright(struct node *t, int x)
{
    struct node *p;
    p = createnode(x);
    t->right = p;
}
void inorder(struct node *p)
{
    if (p == NULL)
        return;
    inorder(p->left);
    printf("%d ", p->info);
    inorder(p->right);
}
void preorder(struct node *p)
{
    if (p == NULL)
        return;
    printf("%d ", p->info);
    preorder(p->left);
    preorder(p->right);
}
void postorder(struct node *p)
{
    if (p == NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    printf("%d ", p->info);
}
int main()
{
    char ch;
    int n, choice;
    struct node *p, *q;
    printf("Please enter root: ");
    scanf("%d", &n);
    root = createnode(n);
    while (1)
    {
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &ch);
        if (ch == 'n' || ch == 'N')
            break;
        printf("Please enter element: ");
        scanf("%d", &n);
        p = q = root;
        while (p != NULL)
        {
            q = p;
            if (p->info < n)
                p = p->right;
            else
                p = p->left;
        }
        if (q->info < n)
            setright(q, n);
        else
            setleft(q, n);
    }
    while (1)
    {
        printf("\n1. Inorder Traversal");
        printf("\n2. Preorder Traversal");
        printf("\n3. Postorder Traversal");
        printf("\n4. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                if (root == NULL)
                    printf("Tree is empty.");
                else
                {
                    printf("Inorder Traversal: ");
                    inorder(root);
                }
                break;
            case 2:
                if (root == NULL)
                    printf("Tree is empty.");
                else
                {
                    printf("Preorder Traversal: ");
                    preorder(root);
                }
                break;
            case 3:
                if (root == NULL)
                    printf("Tree is empty.");
                else
                {
                    printf("Postorder Traversal: ");
                    postorder(root);
                }
                break;
            case 4:
                printf("Program terminated.");
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }
    return 0;
}