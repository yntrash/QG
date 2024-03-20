#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* Create(int data);
void Insert();
void deleteNode();
void Print();
void ReversePrint();
