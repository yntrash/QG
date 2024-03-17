
#include"head.h"

Node* head = NULL;
Node* Create(int data) {   //�������������ٴ�����
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void Insert() {  // ��˫�������в���ڵ�
    int data;
    printf("������Ҫ����Ľڵ����ݣ�");
    scanf_s("%d", &data);

    Node* newNode = Create(data);

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("�ڵ����ɹ�\n");
}
// ��˫��������ɾ���ڵ�
void deleteNode() {
    if (head == NULL) {
        printf("����Ϊ�գ��޷�ɾ��\n");
        return;
    }

    int data;
    printf("������Ҫɾ���Ľڵ����ݣ�");
    scanf_s("%d", &data);

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("δ�ҵ�Ҫɾ���Ľڵ�\n");
    }
    else {
        if (prev == NULL) {
            head = current->next;
        }
        else {
            prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = prev;
            }
        }
        free(current);
        printf("�ڵ� %d ɾ���ɹ�\n", data);
    }
}
// �����ӡ����
void Print() {
    Node* temp = head;
    printf("�����ӡ˫������");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// �����ӡ����
void ReversePrint() {
    Node* temp = head;
    if (temp == NULL) {
        printf("����Ϊ��\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("�����ӡ˫������");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

