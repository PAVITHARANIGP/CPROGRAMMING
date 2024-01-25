#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a photography prop in the graph
struct Prop {
    char name[50];
    struct Prop** related_props;
    int num_related_props;
    int visited;
};

// Function to create a new prop
struct Prop* createProp(const char* name) {
    struct Prop* newProp = (struct Prop*)malloc(sizeof(struct Prop));
    strcpy(newProp->name, name);
    newProp->num_related_props = 0;
    newProp->visited = 0;
    newProp->related_props = NULL;
    return newProp;
}

// Function to add a relationship between two props
void addRelationship(struct Prop* prop1, struct Prop* prop2) {
    prop1->related_props = realloc(prop1->related_props, (prop1->num_related_props + 1) * sizeof(struct Prop*));
    prop1->related_props[prop1->num_related_props++] = prop2;

    prop2->related_props = realloc(prop2->related_props, (prop2->num_related_props + 1) * sizeof(struct Prop*));
    prop2->related_props[prop2->num_related_props++] = prop1;
}

// Breadth-First Traversal
void breadthFirstTraversal(struct Prop* startProp) {
    struct Prop* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = startProp;
    startProp->visited = 1;

    while (front < rear) {
        struct Prop* current = queue[front++];
        printf("%s ", current->name);

        for (int i = 0; i < current->num_related_props; i++) {
            struct Prop* relatedProp = current->related_props[i];
            if (!relatedProp->visited) {
                queue[rear++] = relatedProp;
                relatedProp->visited = 1;
            }
        }
    }
}

// Depth-First Traversal
void depthFirstTraversal(struct Prop* startProp) {
    printf("%s ", startProp->name);
    startProp->visited = 1;

    for (int i = 0; i < startProp->num_related_props; i++) {
        struct Prop* relatedProp = startProp->related_props[i];
        if (!relatedProp->visited) {
            depthFirstTraversal(relatedProp);
        }
    }
}

// Example usage
int main() {
    struct Prop* prop1 = createProp("Camera");
    struct Prop* prop2 = createProp("Tripod");
    struct Prop* prop3 = createProp("Lighting Kit");
    struct Prop* prop4 = createProp("Backdrop");
    struct Prop* prop5 = createProp("Lens Set");

    addRelationship(prop1, prop2);
    addRelationship(prop1, prop3);
    addRelationship(prop2, prop4);
    addRelationship(prop2, prop5);

    printf("Breadth-First Traversal: ");
    breadthFirstTraversal(prop1);
    printf("\n");

    // Reset visited flags
    prop1->visited = 0;
    prop2->visited = 0;
    prop3->visited = 0;
    prop4->visited = 0;
    prop5->visited = 0;

    printf("Depth-First Traversal: ");
    depthFirstTraversal(prop1);
    printf("\n");

    // Free allocated memory
    free(prop1->related_props);
    free(prop2->related_props);
    free(prop3->related_props);
    free(prop4->related_props);
    free(prop5->related_props);
    free(prop1);
    free(prop2);
    free(prop3);
    free(prop4);
    free(prop5);

    return 0;
}
