#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct prop{
	char name[10];
	struct prop *right;
	struct prop *left;
}*temp,*prev,*first,*last,*newptr,*next;

int numOfPROPs = 0;

int create()
{
	char ch;
	while(1)
	{
		newptr=(struct prop*) malloc(sizeof(struct prop));
		if(newptr==NULL){
			printf("Memory allocation error");
			return 0;
		}
		printf("\nEnter Name of prop : ");
		scanf("%s",&newptr->name);
		numOfPROPs++;
		newptr->right=NULL;
		newptr->left=NULL;
		if(first==NULL)
		   first=temp=newptr;
		   else
			{
				temp->right=newptr;
				newptr->left=temp;
				temp=temp->right;
			}
		printf("Want to add more prop(Y/N) : ");
		ch=getch();
		if(ch=='n'||ch=='N')
         return(0);	
	temp=first;
	while(temp->right!=NULL)
	{
		temp=temp->right;
		last=temp;
	}	      
   }
   
	
}
void display_forward()
{
	if(first==NULL){
		printf("There are no prop\n");
		return;
	}
	temp=first;
	printf("Forward Display of prop : \n");
	printf("NULL");
	while(temp!=NULL)
	{
		printf("<--[%s]-->",temp->name);
		temp=temp->right;
	}
	printf("NULL\n");
}

void display_backward()
{
	if(first==NULL){
		printf("There are no prop\n");
		return;
	}
	temp=first;
    printf("Reverse Display of prop : \n");
	while(temp->right!=NULL)
	{
		temp=temp->right;
		last=temp;
	}
	temp=last;
	printf("NULL");
	while(temp!=NULL)
	{
		printf("<--[%s]-->",temp->name);
		temp=temp->left;	
	}
	// printf("<--[%s]-->",first->name);
	printf("NULL\n");
}

void search(){
	if(first==NULL){
		printf("There are no prop\n");return;
	}
	char search_name[10];
	printf("Enter prop Name to be Searched : ");
	scanf("%s",&search_name);
	temp = first;
	int pos = 0;
	int foundFlag=0;
		while(temp->right!=NULL)
	   {
		pos++;
		if(strcmpi(search_name,temp->name)==0)
		{

			printf("prop found at position : %d ",pos);
			foundFlag=1;
			break;
		}
		temp=temp->right;
	}
	if(foundFlag==0){
		printf("prop is not in List");
	}
	

}

void insert_begining()
{
   newptr=(struct prop*) malloc(sizeof(struct prop)); 
   if(newptr==NULL){
		printf("Memory allocation error");
		return ;
	}	  	
   printf("\nEnter prop Name ");
   scanf("%s",&newptr->name);
   numOfPROPs++;
   newptr->left=NULL;
   first->left=newptr;
   newptr->right=first;
   first=newptr;
   printf("\nprop Added At Begining");
}

void insert_end()
{
   newptr=(struct prop*) malloc(sizeof(struct prop)); 
   if(newptr==NULL){
		printf("Memory allocation error");
		return ;
	}	  	
   printf("\nEnter prop Name : ");
   scanf("%s",&newptr->name);
   numOfPROPs++;
	newptr->right=NULL;
    last->right=newptr;
	newptr->left=last;
	last=newptr;
	printf("\nprop Added At end");
}

void delete_begining()
{
	if(first==NULL){
		printf("There are no prop\n");return;
	}
	temp=first;
	first=first->right;
	first->left=NULL;
	temp->right=NULL;
	free(temp);
	numOfPROPs--;
	printf("\nprop Deleted from Begining");
}

void delete_end()
{

	if(first==NULL){
		printf("There are no prop\n");return;
	}
	temp=last;
	last=last->left;
	last->right=NULL;
	temp->left=NULL;
	numOfPROPs--;
	free(temp);
	printf("\nprop Deleted from end");

}


void delete_middle(){
    if(first==NULL){
        printf("\nThere are no prop");
    }
    else{
        int pos, c; c = 0;
        printf("Enter the position of the prop you want to delete : ");
        scanf("%d", &pos);

        temp = first;
        while(temp->right != NULL){
            c++;
            if(c == pos){
                prev= temp->left;
				next = temp->right;
				prev->right = next;
				next->left = prev;
				temp->left=NULL;
		        temp->right=NULL;  
				free(temp);
                printf("\nprop at position %d deleted\n", pos);
				numOfPROPs--;
                break;
            }
            temp = temp->right;
        }
    }
}


void insert_middle()
{
	int pos,c;c=0;
	newptr=(struct prop*) malloc(sizeof(struct prop));
	if(newptr==NULL){
		printf("Memory allocation error");
		return ;
	} 
	printf("\nEnter the position  at which insert prop : ");
	scanf("%d",&pos);	  	
	printf("\nEnter prop Name : ");
	scanf("%s",&newptr->name);
	numOfPROPs++;
	temp=first;
	while(temp->right!=NULL)
	{
		c++;
		if(c==pos)
		{
			prev=temp->left;
			prev->right=newptr;
			newptr->left=prev;
			temp->left=newptr;
			newptr->right=temp;
		}
		temp=temp->right;
	}
	
}

void exit_program(){
    temp = first;
    while (temp != NULL) {
        struct prop* nextPROP = temp->right;
        free(temp);
        temp = nextPROP;
    }
	exit(0);
}

void main()
{
	int opt;
	opt=0;
	first=temp=NULL;
	while(1)
 {
	printf("\n");
	printf(" +---------prop-Menu---------+\n");
	printf(" | 1.Create prop            |\n");
	printf(" | 2.Display prop           |\n");
    printf(" | 3.Display prop Reverse   |\n");
	printf(" | 4.Insert prop Begining    |\n");
	printf(" | 5.Insert prop Middle      |\n");
	printf(" | 6.Insert prop End         |\n");
	printf(" | 7.Delete prop Begining    |\n");
	printf(" | 8.Delete prop Middle      |\n");
	printf(" | 9.Delete prop End         |\n");
	printf(" | 10.Search prop            |\n");
	printf(" | 11.Exit                     |\n");
    printf(" +-----------------------------+\n");
	printf("Enter your option");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:create();break;
		case 2:display_forward();break;
		case 3:display_backward();break;
		case 4:insert_begining();break;
		case 5:numOfPROPs>=2?insert_middle():printf("\nNeed More Than 1 PROP\n");break;
		case 6:insert_end();break;
		case 7:delete_begining();break;
		case 8:numOfPROPs>=2?delete_middle():printf("\nNeed More Than 1 PROP\n");break;
		case 9:delete_end();break;
		case 10:search();break;
		case 11:exit_program();
	}
	getch();
 }
}