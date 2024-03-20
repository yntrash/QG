#include<stdio.h>
#include<stdlib.h>
#include"head.h"

Node* head;
void Creat(int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = head;
	head = temp;
	return;
}
void Insert(int data, int n) {
	int i;
	Node* temp1 = (Node*)malloc(sizeof(Node));
	temp1->data = data;
	temp1->next = NULL;
	if (n == 1) {
		temp1->next = head;
		head = temp1;
		return;
	}
	Node* temp2 = head;
	for (i = 0; i < n - 2; i++) {	//遍历链表至所选节点 
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
	printf("插入成功\n");
}
void Print() {
	Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void Search(int data) {
	int a = 1;
	Node* temp = head;
	while (temp->next) {
		temp = temp->next;
		a++;
		if (temp->data == data) {
			printf("存在该数据，在第%d位\n", a);
			return;
		}
	}
	printf("不存在该数据");
	return;
}
void Del() {
	int n;
	printf("请输入想删除的节点位置:");
	scanf_s("%d", &n);
	Node* temp1 = head;
	int i;
	if (n == 1) {		//当删除位置为头节点的情况
		head = temp1->next;
		free(temp1);
	}
	else {			//删除位置为非头节点 
		for (i = 0; i < n - 2; i++) {
			temp1 = temp1->next;
		}
		Node* temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
		printf("删除成功\n");
	}
	printf("删除该节点后的链表:\n");
	Print();
}
void Destroy() {
	Node* temp = head;
	while (temp != NULL) {
		temp = temp->next;
		free(head);
		head = temp;
	}
	printf("销毁成功，当前已无链表\n");
	return;
}
void Reverse_1() {    //迭代方式 
	Node* current, * prev, * next;
	prev = NULL;
	current = head;
	while (current != NULL) {
		//储存下一个节点的地址 
		next = current->next;
		//反转当前节点
		current->next = prev;
		//储存当前节点的地址
		prev = current;
		//移动到下一节点
		current = next;
	}
	//重新设置头节点
	head = prev;
	printf("反转成功\n");
	return head;
}
void Reverse_2(Node* temp1) {
	if (temp1->next == NULL) {
		head = temp1;
		return;
	}
	Reverse_2(temp1->next);
	Node* temp2 = temp1->next;
	temp2->next = temp1;
	temp1->next = NULL;
	printf("反转成功\n");
	return;
}
Node* Search_mid(Node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}//fast每次走两步，slow每次走一步
	Node* fast, * slow;
	fast = slow = head;
	while (fast->next != NULL) {
		if (fast->next == NULL) {
			fast = fast->next;    //当快节点走不了两步时使只走一步
		}
		else {
			fast = fast->next->next;
		}
		slow = slow->next;
	}
	return slow;
}
int List_len(Node* head) {
	int num = 1;
	Node* temp = head;
	while (temp != NULL) {
		temp = temp->next;
		num++;
	}
	return num;
}