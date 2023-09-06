#include <iostream>
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class SortedLinkedList {
private:
    Node* head;

public:
    SortedLinkedList() : head(nullptr) {}

    void Insert(int key) {
        Node* newNode = new Node(key);
        if (!head || key < head->data) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && key >= current->next->data) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void RemoveDuplicates() {
        if (!head) {
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->data == current->next->data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    void PrintList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~SortedLinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    SortedLinkedList list;
    int num;

    while (true) {
        std::cin >> num;
        if (num == -1) {
            break;
        }
        list.Insert(num);
    }

    list.RemoveDuplicates();
    list.PrintList();

    return 0;
}
