#include<stdio.h>
#include<stdlib.h>
#include"head.h"

Node* head;

int main() {
	int i, n, data, choice;
	head = NULL;
	while (1) {
		printf("\n��������ADT\n");
		printf("1.��������(ͷ�巨)\n");
		printf("2.��������\n");
		printf("3.����ڵ�\n");
		printf("4.���ҽڵ�\n");
		printf("5.ɾ���ڵ�\n");
		printf("6.��������\n");
		printf("7.��ת����(������)\n");
		printf("8.��ת����(�ݹ鷨)\n");
		printf("9.�����е�\n");

		printf("����������Ҫ�Ĳ���:");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("Ҫ�����������:");
			
			scanf_s("%d", &n);
			for (i = 0; i < n; i++) {
				printf("������Ҫ���������:");
				scanf_s("%d", &data);
				Creat(data);
			}
			printf("�������ɹ�\n");
			break;
		case 2:
			Print();
			break;
		case 3:
			printf("������Ҫ���������:\n");
			scanf_s("%d", &data);
			printf("������Ҫ�����λ��:\n");
			scanf_s("%d", &n);
			Insert(data, n);
			break;
		case 4:
			printf("������Ҫ���ҵ�����:\n");
			scanf_s("%d", &data);
			Search(data);
			break;
			
		case 5:
			Del();
			break;
		case 6:
			Destroy();
			break;
		case 7:
			Reverse_1();
			break;
		case 8:
			Reverse_2(head);
			break;
		case 9:
		{
			Node* mid;
			Node* temp = head;
			mid = Search_mid(head);
			if (List_len(head) % 2 == 0) {  //������Ϊ����
				printf("��������е�����Ϊ%d\n", mid->data);
			}
			else {	//������Ϊż��
				while (temp->next != mid) {   //�ҵ�ͬΪ�е�Ŀ���ͷ�ڵ������
					temp = temp->next;
				}
				printf("��������е�Ϊ%d��%d\n", temp->data, temp->next->data);
			}
			break;
		}
		default:
			printf("û�еĲ�����Ҫ��ѡ�t���F���䣩�s\n");
			break;
		}
	}return 0;
}
