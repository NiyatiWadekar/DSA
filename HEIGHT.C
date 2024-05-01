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

int height(NODE *r)
{
		int left,right;
		if(r==NULL)
			return 0;
		left=height(r->lchild);
		right=height(r->rchild);
		if(left>right)
			return left+1;
		else
			return right+1;
}

void insert()
{
	NODE *temp,*q;//,*root=NULL;
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
				printf("\n Current Node :%d",q->data);
				printf("\n  Enter Direction :");
				d=getche();
				if(d=='L')
				{
					if(q->lchild!=NULL)
						q=q->lchild;
					else
					    {
						q->lchild=temp;
						break;
					     }
				}
				else if (d=='R')
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

h=height(root);
printf("\n Height of tree :%d",h);

getch();
}