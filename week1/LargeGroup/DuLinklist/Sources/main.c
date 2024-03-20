#include"head.h"

Node* head;
int main() {
    int choice;
    while (1) {
        printf("\n\ 双向链表ADT \n");
        printf("1. 创建双向链表\n");
        printf("2. 插入节点\n");
        printf("3. 删除节点\n");
        printf("4. 打印链表(正向)\n");
        printf("5. 打印链表(反向)\n");
        printf("请输入想做的操作：");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            head = NULL;
            printf("双向链表创建成功\n");
            break;
        case 2:
            Insert();
            break;
        case 3:
            deleteNode();
            break;
        case 4:
            Print();
            break;
        case 5:
            ReversePrint();
            break;
        default:
            printf("没有这个选项￣へ￣\n");
            break;
        }
    }
    return 0;
}