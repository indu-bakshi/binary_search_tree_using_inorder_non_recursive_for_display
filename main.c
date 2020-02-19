#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* right;
    struct node* left;
};

struct stack
{
    struct node *dataa[30];
    int top;
};

struct stack *s=NULL;
struct node* root=NULL;
struct node* parent;
void insert();
void display_inorder();
void init();
void push(struct node *);
struct node* pop();
int isEmpty();

int main()
{

    int ch;
    while(1)
    {
        printf("\n============Enter Your Choice===============\n");
        printf("\n1. Insert \n2.Display Inorder \n3. Exit \nCHOICE = ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\n===========INSERT============\n");
                insert();

                break;
            case 2:
                printf("\n============Display Inorder============\n ");
                init();
                display_inorder();

                break;
            case 3: exit(0);
        }
    }
}

void insert()
{
    //int elem,i;
    int a;
    //printf("Enter the no. of elements\n");
    //scanf("%d",&elem);
    //for(i=0;i<elem;i++)
    printf("Enter the number\n");
    scanf("%d",&a);
    struct node* t;

    //for(i=0;i<elem;i++)
    //printf("%d",a[i]);
    t=(struct node*)malloc(sizeof(struct node));
    t->data=a;
    t->left=NULL;
    t->right=NULL;
    if(root==NULL)
    {
        root=t;
    }
    else
    {
        struct node* curr;
        //struct node*parent;
        curr=root;
        while(curr!=NULL)
        {
            parent=curr;
            if(t->data > curr->data)
            {
                curr=curr->right;
            }
            else
            {
                curr=curr->left;
            }
        }
        if(a<parent->data)
            parent->left=t;
        else
            parent->right=t;

    }
}

/*void display_inorder_recursive(struct node*root)
{
    if(root)
    {
        display_inorder(root->left);
        printf("%d+",root->data);
        display_inorder(root->right);
    }


}
*/
void display_inorder()
{
    while(1)
    {
        while(root!=NULL)
        {
            push(root);
            root=root->left;
        }
        if(isEmpty()==1){
            break;
        }
        root=pop();
        printf("%d-> ",root->data);
        root=root->right;
    }
    s->top=-1;
}
void init()
{
    s= (struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
}

void push(struct node* temp) {
    s->top++;
    s->dataa[s->top]=temp;
}
struct node* pop()
{
    struct node *temp;
    temp= s->dataa[s->top];
    s->top=(s->top)-1;
    return(temp);

}
int isEmpty(){
    if( s->top==-1)
        return(1);
    else
        return(0);
}