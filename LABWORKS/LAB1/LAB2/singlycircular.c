#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct prop{
    char name[10];
    struct prop *right;
}*newptr,*first,*last,*temp,*prev,*next;


int create(){
    char ch;
	while(1)
	{
		newptr=(struct prop*) malloc(sizeof(struct prop));
		if(newptr==NULL){
			printf("Memory allocation error");
			return 0;
	    }
		printf("\nEnter Name of prop");
		scanf("%s",&newptr->name);
		newptr->right=NULL;
		if(first==NULL)
		   first=temp=last=newptr;
		   else
			{
				temp->right=newptr;
				temp=temp->right;
			}
		printf("want to add more props(Y/N)");
		ch=getch();
		if(ch=='n'||ch=='N')
         {
			temp=first;
			while(temp->right!=NULL)
			{
				temp=temp->right;
				last=temp;
			}	
			last->right= first; 
			return(0);
		 }
  }
	     
}


void display(){
    temp= first;
    if(temp==NULL){
        printf("There are no props\n"); 
        return;
    }
	do{
		printf("[%s]--->",temp -> name );
        temp = temp-> right ;
	}while(temp!=first);
	printf("(%s)",last->right->name);
}

void insert_begining(){
	newptr = (struct prop *)malloc( sizeof( struct prop ) );
	if(newptr==NULL){
			printf("Memory allocation error");
			return;
	    }
	printf("\nEnter Name of new prop : ");
	scanf("%s",&newptr->name);
	newptr->right=NULL;
	if(first == NULL)
	{
		first=last=newptr;
    }
	else
	{
		newptr->right=first;
		first=newptr;
	}
    last->right= first;      
}

void insert_end(){
	newptr=(struct prop*)malloc(sizeof(struct prop));
	if(newptr==NULL){
			printf("Memory allocation error");
			return;
	    }
	printf("\nEnter Name of new prop : ");
	scanf("%s",&newptr->name);
	newptr->right=NULL;
	last->right=newptr;
    last=newptr;
    last->right=first;

}

void insert_middle(){
	int pos,c;c=0;
	newptr=(struct prop*)malloc(sizeof(struct prop));
	printf("Enter Postion for prop to be inserted : ");
	scanf("%d",&pos);
	printf("\nEnter Name of new prop : ");
	scanf("%s",&newptr->name);
	temp= first;
	while (temp!=NULL)
	{
		c++;
		if(c==pos-1){
		   next=temp->right;
		   newptr->right=next;
		   temp->right=newptr;
		   break;
		}
		temp=temp->right;
	}
}

void delete_begining(){
	if(first==NULL){
		printf("\nThere are no props");
	}
	else{
		temp = first;
		first = first -> right;
		last->right=first;
		free(temp);
		printf("\nFirst prop deleted\n");


	}
}

void delete_end(){
	if(first==NULL){
		printf("\nThere are no props");
		return;
	}
	temp=first;
	while(temp!=last){
		prev=temp;
		temp=temp->right;
	}	     
	prev->right=NULL;
	last=prev;
    last->right=first;
    printf("\nLast prop deleted\n");
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
        while(temp->right != NULL){
            c++;
            if(c == pos - 1){
                prev = temp;
                next = temp->right->right;
                free(temp->right);
                prev->right = next;
                printf("\nprop at position %d deleted\n", pos);
                break;
            }
            temp = temp->right;
        }
    }
}

void search(){
	char search_name[25];
	int pos ,foundFlag=0;pos=0;
	temp = first;
	printf("\nEnter name of the prop you want to find : ");
	scanf("%s",&search_name);

	do{
		pos++;
		if(strcmpi(search_name,temp->name)==0){
			foundFlag =1;
			printf("\nprop Found at %d",pos);
			break;
		}
		temp= temp->right;

	}while(temp!=first);

	if(foundFlag==0){
		printf("\n\tNo such prop found!");
	}
}

void exit_program(){
    temp = first;
    while (temp != NULL) {
        struct prop* nextNode = temp->right;
        free(temp);
        temp = nextNode;
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
	printf(" | 1.Create props            |\n");
	printf(" | 2.Display props           |\n");
	printf(" | 3.Insert prop Begining    |\n");
	printf(" | 4.Insert prop Middle      |\n");
	printf(" | 5.Insert prop End         |\n");
	printf(" | 6.Delete prop Begining    |\n");
	printf(" | 7.Delete prop Middle      |\n");
	printf(" | 8.Delete prop End         |\n");
	printf(" | 9.Search prop             |\n");
	printf(" | 10.Exit                     |\n");
    printf(" +-----------------------------+\n");
	printf("enter your option");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:create();break;
		case 2:display();break;
		case 3:insert_begining();break;
		case 4:insert_middle();break;
		case 5:insert_end();break;
		case 6:delete_begining();break;
		case 7:delete_middle();break;
		case 8:delete_end();break;
		case 9:search();break;
		case 10:exit_program();
	}
	getch();
 }
}