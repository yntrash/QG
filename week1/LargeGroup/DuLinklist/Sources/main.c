#include"head.h"

Node* head;
int main() {
    int choice;
    while (1) {
        printf("\n\ ˫������ADT \n");
        printf("1. ����˫������\n");
        printf("2. ����ڵ�\n");
        printf("3. ɾ���ڵ�\n");
        printf("4. ��ӡ����(����)\n");
        printf("5. ��ӡ����(����)\n");
        printf("�����������Ĳ�����");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            head = NULL;
            printf("˫���������ɹ�\n");
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
            printf("û�����ѡ����أ�\n");
            break;
        }
    }
    return 0;
}