#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct prop {
    char name[50];  // Increase the size of the name to accommodate prop names
    struct prop* next;
};

struct prop *newptr, *first, *last, *temp, *prev, *next;

int numberOfProps = 0;

// Function to create a new prop
int create() {
    char ch;
    while (1) {
        newptr = (struct prop*)malloc(sizeof(struct prop));
        if (newptr == NULL) {
            printf("Memory allocation error");
            return 0;
        }
        printf("\nEnter Name of the prop: ");
        scanf("%s", &newptr->name);
        numberOfProps++;
        newptr->next = NULL;
        if (first == NULL)
            first = temp = newptr;
        else {
            temp->next = newptr;
            temp = temp->next;
        }
        printf("Want to add more props (Y/N): ");
        ch = getch();
        if (ch == 'n' || ch == 'N')
            return 0;
        temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
            last = temp;
        }
    }
}

// Function to display all props
void display() {
    temp = first;
    if (temp == NULL) {
        printf("There are no props\n");
        return;
    }
    while (temp != NULL) {
        printf("[%s]--->", temp->name);
        temp = temp->next;
    }
    printf("NULL \n");
}

// Function to insert a new prop at the beginning
void insert_beginning() {
    newptr = (struct prop*)malloc(sizeof(struct prop));
    if (newptr == NULL) {
        printf("Memory allocation error");
        return;
    }
    printf("\nEnter Name of new Prop: ");
    scanf("%s", &newptr->name);
    numberOfProps++;
    newptr->next = NULL;
    if (first == NULL) {
        first = last = newptr;
    }
    else {
        newptr->next = first;
        first = newptr;
    }
}

// Function to insert a new prop at the end
void insert_end() {
    newptr = (struct prop*)malloc(sizeof(struct prop));
    if (newptr == NULL) {
        printf("Memory allocation error");
        return;
    }
    printf("\nEnter Name of new Prop: ");
    scanf("%s", &newptr->name);
    numberOfProps++;
    newptr->next = NULL;
    temp = first;
    while (temp != NULL) {
        last = temp;
        temp = temp->next;
    }
    last->next = newptr;
    newptr->next = NULL;
}

// Function to insert a new prop in the middle
void insert_middle() {
    int pos, c;
    c = 0;
    newptr = (struct prop*)malloc(sizeof(struct prop));
    if (newptr == NULL) {
        printf("Memory allocation error");
        return;
    }
    printf("Enter Position for prop to be inserted: ");
    scanf("%d", &pos);
    printf("\nEnter Name of new Prop: ");
    scanf("%s", &newptr->name);
    numberOfProps++;
    temp = first;
    while (temp != NULL) {
        c++;
        if (c == pos - 1) {
            next = temp->next;
            newptr->next = next;
            temp->next = newptr;
            break;
        }
        temp = temp->next;
    }
}

// Function to delete the first prop
void delete_beginning() {
    if (first == NULL) {
        printf("\nThere are no Props");
    }
    else {
        temp = first;
        first = first->next;
        free(temp);
        numberOfProps--;
        printf("\nFirst Prop deleted\n");
    }
}

// Function to delete the last prop
void delete_end() {
    if (first == NULL) {
        printf("\nThere are no Props");
        return;
    }
    temp = first;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
        last = temp;
    }
    prev->next = NULL;
    last = prev;
    printf("\nLast Prop deleted\n");
    numberOfProps--;
    free(temp);
}

// Function to delete a prop from the middle
void delete_middle() {
    if (first == NULL) {
        printf("\nThere are no props");
    }
    else {
        int pos, c;
        c = 0;
        printf("Enter the position of the prop you want to delete: ");
        scanf("%d", &pos);

        temp = first;
        while (temp->next != NULL) {
            c++;
            if (c == pos - 1) {
                prev = temp;
                next = temp->next->next;
                free(temp->next);
                prev->next = next;
                printf("\nProp at position %d deleted\n", pos);
                numberOfProps--;
                break;
            }
            temp = temp->next;
        }
    }
}

// Function to search for a prop by name
void search() {
    char search_name[50];
    int pos, foundFlag = 0;
    pos = 0;
    temp = first;
    printf("\nEnter name of the prop you want to find: ");
    scanf("%s", &search_name);
    while (temp != NULL) {
        pos++;
        if (strcmpi(search_name, temp->name) == 0) {
            foundFlag = 1;
            printf("\nProp Found at %d", pos);
        }
        temp = temp->next;
    }
    if (foundFlag == 0) {
        printf("\nNo such prop found!");
    }
}

// Function to exit the program and free memory
void exit_program() {
    temp = first;
    while (temp != NULL) {
        struct prop* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    exit(0);
}

int main() {
    int opt;
    opt = 0;
    first = temp = NULL;
    while (1) {
        printf("\n");
        printf("+---------Photography-Prop-Store-Menu---------+\n");
        printf("| 1. Create Props                            |\n");
        printf("| 2. Display Props                           |\n");
        printf("| 3. Insert Prop at Beginning               |\n");
        printf("| 4. Insert Prop in the Middle              |\n");
        printf("| 5. Insert Prop at End                     |\n");
        printf("| 6. Delete Prop at Beginning               |\n");
        printf("| 7. Delete Prop in the Middle              |\n");
        printf("| 8. Delete Prop at End                     |\n");
        printf("| 9. Search for Prop                         |\n");
        printf("| 10. Exit                                  |\n");
        printf("+-------------------------------------------+\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch (opt) {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_beginning();
            break;
        case 4:
            numberOfProps >= 2 ? insert_middle() : printf("\nNeed More Than 1 Prop\n");
            break;
        case 5:
            insert_end();
            break;
        case 6:
            delete_beginning();
            break;
        case 7:
            numberOfProps >= 2 ? delete_middle() : printf("\nNeed More Than 1 Prop\n");
            break;
        case 8:
            delete_end();
            break;
        case 9:
            search();
            break;
        case 10:
            exit_program();
        }
        getch();
    }
}
