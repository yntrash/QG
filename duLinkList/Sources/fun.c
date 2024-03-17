
#include"head.h"

Node* head = NULL;
Node* Create(int data) {   //建立函数，减少代码量
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void Insert() {  // 在双向链表中插入节点
    int data;
    printf("请输入要插入的节点数据：");
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
    printf("节点插入成功\n");
}
// 从双向链表中删除节点
void deleteNode() {
    if (head == NULL) {
        printf("链表为空，无法删除\n");
        return;
    }

    int data;
    printf("请输入要删除的节点数据：");
    scanf_s("%d", &data);

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("未找到要删除的节点\n");
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
        printf("节点 %d 删除成功\n", data);
    }
}
// 正向打印链表
void Print() {
    Node* temp = head;
    printf("正向打印双向链表：");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 反向打印链表
void ReversePrint() {
    Node* temp = head;
    if (temp == NULL) {
        printf("链表为空\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("反向打印双向链表：");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

