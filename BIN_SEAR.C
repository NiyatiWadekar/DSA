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
NODE *root=NULL;

void preorder(NODE *r)
{
    if(r!=NULL)
	{
      printf("%d->",r->data);
      preorder(r->lchild);
      preorder(r->rchild);
    }
}

void inorder(NODE *r)
{
    if(r!=NULL)
    {
      inorder(r->lchild);
      printf("%d->",r->data);
      inorder(r->rchild);
    }
}

void postorder(NODE *r)
{
    if(r!=NULL)
    {
      postorder(r->lchild);
      postorder(r->rchild);
      printf("%d->",r->data);
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
printf("\n Postorder : ");
	postorder(root);

getch();
}