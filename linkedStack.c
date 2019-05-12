#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

struct node {
    int value;
    struct node *next;
};

typedef struct node _node;

_node *addElement(int element, _node *root) {
    _node *newNode;
    
    newNode = (_node *) malloc(sizeof(_node));
    
    if (newNode != NULL) {
        newNode->value = element;
        newNode->next = root;
        root = newNode;
    }
    
    return root;
}

_node *removeElement(_node *root) {
    _node *nodeToRemove;
    
    if (root != NULL) {
        nodeToRemove = root;
        root = root->next;
            
        free(nodeToRemove);
    }
    
    return root;
}

void print(_node *root) {
    _node *aux;
    
    aux = root;
    
    printf("stack:\n");
    
    while (aux != NULL) {
        printf("[%d]\n", aux->value);
        aux = aux->next;
    }

    printf("\n");
}

int size(_node *root) {
    _node *aux;
    int size = 0;
    
    aux = root;
    
    if (root != NULL) {
        while (aux != NULL) {
            size++;
            aux = aux->next;
        }
    }
    
    return size;
}

int main() {
    _node *root;
    
    root = NULL;
    
    root = addElement(5, root);
    root = addElement(11, root);
    root = addElement(3, root);
    root = addElement(2, root);
    root = addElement(1, root);
    root = addElement(9, root);
    root = addElement(50, root);
    root = addElement(30, root);
    root = addElement(53, root);
    
    print(root);
        
    printf("size: %d\n", size(root));
    
    root = removeElement(root);
    
    print(root);
    
    return EXIT_SUCCESS;
}
