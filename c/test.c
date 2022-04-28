#include <stdio.h>


typedef struct 
{
    int y;
    int x;
    

} Node;

void func(Node* node){
    printf("%d %d", node->x, node->y);
}

void main(){

    //printf("%p", main);
    int n = 1;

    Node node;

    node.x = 1;
    node.y = 2;

    func(&node);
    //printf("%d\n", sizeof(Node));

    //printf("node : %d %d %d %d", &node, &node.x[0], &node.x[1], &node.y);



}