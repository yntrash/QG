#pragma once
typedef struct Node {
	int data;
	struct Node* next;
}Node;
void Creat(int data);
void Insert(int data, int n);
void Print();
void Search(int data);
void Del();
void Destroy();
void Reverse_1();
void Reverse_2(Node* temp1);
Node* Search_mid(Node* head);
int List_len(Node* head);