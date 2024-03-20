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
	for (i = 0; i < n - 2; i++) {	//������������ѡ�ڵ� 
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
	printf("����ɹ�\n");
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
			printf("���ڸ����ݣ��ڵ�%dλ\n", a);
			return;
		}
	}
	printf("�����ڸ�����");
	return;
}
void Del() {
	int n;
	printf("��������ɾ���Ľڵ�λ��:");
	scanf_s("%d", &n);
	Node* temp1 = head;
	int i;
	if (n == 1) {		//��ɾ��λ��Ϊͷ�ڵ�����
		head = temp1->next;
		free(temp1);
	}
	else {			//ɾ��λ��Ϊ��ͷ�ڵ� 
		for (i = 0; i < n - 2; i++) {
			temp1 = temp1->next;
		}
		Node* temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
		printf("ɾ���ɹ�\n");
	}
	printf("ɾ���ýڵ�������:\n");
	Print();
}
void Destroy() {
	Node* temp = head;
	while (temp != NULL) {
		temp = temp->next;
		free(head);
		head = temp;
	}
	printf("���ٳɹ�����ǰ��������\n");
	return;
}
void Reverse_1() {    //������ʽ 
	Node* current, * prev, * next;
	prev = NULL;
	current = head;
	while (current != NULL) {
		//������һ���ڵ�ĵ�ַ 
		next = current->next;
		//��ת��ǰ�ڵ�
		current->next = prev;
		//���浱ǰ�ڵ�ĵ�ַ
		prev = current;
		//�ƶ�����һ�ڵ�
		current = next;
	}
	//��������ͷ�ڵ�
	head = prev;
	printf("��ת�ɹ�\n");
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
	printf("��ת�ɹ�\n");
	return;
}
Node* Search_mid(Node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}//fastÿ����������slowÿ����һ��
	Node* fast, * slow;
	fast = slow = head;
	while (fast->next != NULL) {
		if (fast->next == NULL) {
			fast = fast->next;    //����ڵ��߲�������ʱʹֻ��һ��
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