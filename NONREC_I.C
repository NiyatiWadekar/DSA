#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Btree
{
   int data;
   struct Btree *lchild;
   struct Btree *rchild;
};

typedef struct Btree NODE;
#define max 10

NODE *root=NULL,*q,*S[max];
int top=-1;

int isEmpty();
int isFull();
void push(NODE*);
NODE* pop();

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if(top==max-1)
		return 1;
	else
		return 0;
}

void push(NODE *x)
{
	if(isFull())
		printf("\n Stack is FULL.");
	else
	{
		top++;
		S[top]=x;
	}
}

NODE* pop()
{
	NODE *t;
	t=S[top--];
	return t;
}

void preorder(NODE *root)
{
    NODE *q;
    q=root;
    push(q);
    while(!isEmpty())
    {
	 q=pop();
	 printf("%d->",q->data);
	 if(q->rchild!=NULL)
		push(q->rchild);
	 if(q->lchild!=NULL)
		push(q->lchild);
    }
}

void inorder(NODE *root)
{
	NODE *q;
	q=root;
	while(1)
	{
		while(q->lchild!=NULL)
		{
			push(q);
			q=q->lchild;
		 }
		 while(q->rchild==NULL)
		 {
			printf("%d->",q->data);
			if(isEmpty())
				return;
			q=pop();

		 }
		 printf("%d->",q->data);
		 q=q->rchild;
	}
}

void insert()
{
	NODE *temp,*q;
		int x;
	char d,ch;
       do
       {
		temp=(NODE *)malloc(sizeof(NODE));
		printf("\n enter Value of x :");
		scanf("%d",&x);
		temp->data=x;
		temp->lchild=NULL;
		temp->rchild=NULL;
		if(root==NULL)
			root=temp;
		else

		    {
			   q=root;
			   while(1)
			   {
				   if(temp->data<q->data)
				   {
					if(q->lchild!=NULL)
						q=q->lchild;
					else
					    {
						q->lchild=temp;
						break;
					     }
				   }
				    else if(temp->data>q->data)
				    {
					if(q->rchild!=NULL)
						q=q->rchild;
					else
					    {
						q->rchild=temp;
						break;
					    }
				    }
			   }
		 }
	     printf("\nAdd more (Y/N)");
	     ch=getche();
	}while(ch=='Y');
}

void main()
{
int i,h,l;
clrscr();

insert();

printf("\n Preorder : ");
	preorder(root);
printf("\n Inorder : ");
	inorder(root);

getch();
}
