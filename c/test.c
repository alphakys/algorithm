#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//char rbuf[1 << 20];

int compare(const void *a, const void *b){

    if(strcmp(a,b)>0){
        return -1;
    }
    else
    {
        return 1;
    };
}

void printArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}



void charArray(char *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

//node* printInfo();

typedef struct _Node{
    struct Node *this;

    int value_;
    void (*printValue)(struct Node *this);

    int (*getValue)(struct Node *this);
    void (*setValue)(struct Node *this, int value);


} Node;

void delNode(Node *ptr);

int getValue_(const Node *this){
    return this->value_;
};

void setValue_(const Node *this, int value){
   // this->value_ = value;
};

void printValue_(const Node *this){
    printf("%d", this->value_);
};

Node * newNode(int val){
    Node *node = (Node *)malloc(sizeof(Node));
    node->value_ = val;

    node->this = node;
    node->printValue = printValue_;
    node->getValue = getValue_;
    node->setValue = setValue_;

    return node;
};



void main()
{
    
    Node *n = newNode(12);
    printf("%d\n", n);
    
    printf("%d\n", n->printValue);
    // n.this = &n;
    // n.value = 11;
    //   n.this = &n;
    //   printf("%d\n", sizeof(n.printInfo));
    // printf("%d\n", n.value);
    // printf("%d\n", n.this->value);
    // n.printInfo = printInfo;

    //printf("%d\n", n.printInfo);
    
    // printf("%p\n", n.printValue);
    // n.printInfo;
    // n.printInfo = printInfo;
    // n.printInfo();
    //  printf("%d\n", n.this);
    //  n = malloc(sizeof(node));
    //  printf("%p\n", n);
}