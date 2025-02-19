#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* last = *head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }
}

void displayList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void deleteNode(Node** head, int position) {
    if (*head == nullptr) 
        return;

    Node* temp = *head;

    if (position == 0) {
        *head = temp->next;
        delete temp;
        return;
    }

    for (int i = 0; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) 
        return;

    Node* next = temp->next->next;
    delete temp->next;
    temp->next = next;
}

int main() {
    Node* head = nullptr;
    insertEnd(&head, 5);
    insertEnd(&head, 74);
    insertEnd(&head, 495);
    displayList(head);
    deleteNode(&head, 1);
    displayList(head);

    return 0;
}