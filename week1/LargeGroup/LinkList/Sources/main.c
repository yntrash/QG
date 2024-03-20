#include<stdio.h>
#include<stdlib.h>
#include"head.h"

Node* head;

int main() {
	int i, n, data, choice;
	head = NULL;
	while (1) {
		printf("\n单向链表ADT\n");
		printf("1.创建链表(头插法)\n");
		printf("2.遍历链表\n");
		printf("3.插入节点\n");
		printf("4.查找节点\n");
		printf("5.删除节点\n");
		printf("6.销毁链表\n");
		printf("7.反转链表(迭代法)\n");
		printf("8.反转链表(递归法)\n");
		printf("9.查找中点\n");

		printf("请输入你想要的操作:");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("要输入多少数据:");
			
			scanf_s("%d", &n);
			for (i = 0; i < n; i++) {
				printf("请输入要插入的数字:");
				scanf_s("%d", &data);
				Creat(data);
			}
			printf("链表创建成功\n");
			break;
		case 2:
			Print();
			break;
		case 3:
			printf("请输入要插入的数据:\n");
			scanf_s("%d", &data);
			printf("请输入要插入的位置:\n");
			scanf_s("%d", &n);
			Insert(data, n);
			break;
		case 4:
			printf("请输入要查找的数据:\n");
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
			if (List_len(head) % 2 == 0) {  //链表长度为奇数
				printf("该链表的中点数据为%d\n", mid->data);
			}
			else {	//链表长度为偶数
				while (temp->next != mid) {   //找到同为中点的靠近头节点的数据
					temp = temp->next;
				}
				printf("该链表的中点为%d和%d\n", temp->data, temp->next->data);
			}
			break;
		}
		default:
			printf("没有的操作不要乱选╰（‵□′）╯\n");
			break;
		}
	}return 0;
}
