#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct prop{
	char name[10];
	struct prop *right;
	struct prop *left;
}*temp,*prev,*first,*last,*newptr,*next;

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
		newptr->right=NULL;
		newptr->left=NULL;
		if(first==NULL)
		   first=temp=last=newptr;
		else
			{
				temp->right=newptr;
				newptr->left=temp;
				temp=temp->right;
			}

		printf("Want to add more props(Y/N)");
		ch=getch();
		if(ch=='n'||ch=='N')
		{
			temp=first;
			while(temp->right!=NULL)
			{
				temp=temp->right;
				last=temp;
			}
			last->right = first;
			first->left = last;
			return(0);	
		}
		      
   }	
}


void display_forward()
{
	temp= first;
    if(temp==NULL){
        printf("There are no props\n"); 
        return;
    }
    printf("Forward Display of props : \n");
	do{
		printf("<---[%s]--->",temp -> name );
        temp = temp-> right ;
	}while(temp!=first);
	printf("(%s)",last->right->name);
}

void display_backward()
{
	temp= last;
    if(temp==NULL){
        printf("There are no props\n"); 
        return;
    }
    printf("Backward Display of props : \n");
	do{
		printf("<---[%s]--->",temp -> name );
        temp = temp-> left ;
	}while(temp!=last);
	printf("(%s)",first->left->name);
}

void search(){
   
	char search_name[10];
	printf("Enter prop Name to be Searched");
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
		return;
	}	
   printf("\nEnter prop Name ");
   scanf("%s",&newptr->name);
   newptr->left=last;
   first->left=newptr;
   newptr->right=first;
   first=newptr;
   last->right=first;

}

void insert_end()
{
   newptr=(struct prop*) malloc(sizeof(struct prop)); 	
   if(newptr==NULL){
		printf("Memory allocation error");
		return;
	}  	
   printf("\nEnter prop Name ");
   scanf("%s",&newptr->name);
	newptr->right=first;
    last->right=newptr;
	newptr->left=last;
	last=newptr;
	first->left=last;
}

void delete_begining()
{
	temp=first;
	first=first->right;
	first->left=last;
	temp->right=NULL;
    temp->left=NULL;
    last->right=first;
	free(temp);
}

void delete_end()
{
	temp=last;
	last=last->left;
	last->right=first;
	temp->left=NULL;
    temp->right=NULL;
    first->left=last;
	free(temp);
}

void delete_middle(){
    if(first==NULL){
        printf("\nThere are no props");
    }
    else{
        int pos, c; c = 0;
        printf("Enter the position of the prop you want to delete: ");
        scanf("%d", &pos);

        temp = first;
        while(temp!= NULL){
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
		return;
	} 
	printf("\nEnter the position  at which insert prop");
	scanf("%d",&pos);	  	
	printf("\nEnter prop Name");
	scanf("%s",&newptr->name);
	temp=first;
	while(temp!=NULL)
	{
		c++;
		if(c==pos)
		{
			prev=temp->left;
			prev->right=newptr;
			newptr->left=prev;
			temp->left=newptr;
			newptr->right=temp;
			break;
		}
		temp=temp->right;
	}
	
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
	printf(" | 1.Create props            |\n");
	printf(" | 2.Display props           |\n");
    printf(" | 3.Display props Reverse   |\n");
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
		case 5:insert_middle();break;
		case 6:insert_end();break;
		case 7:delete_begining();break;
		case 8:delete_middle();break;
		case 9:delete_end();break;
		case 10:search();break;
		case 11:exit(0);
	}
	getch();
 }
}