
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void Insert_front(int key) {
        Node* newNode = new Node(key);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        PrintList();
    }

    void Insert_back(int key) {
        Node* newNode = new Node(key);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        PrintList();
    }

    void Insert_after_node(int key, int v) {
        Node* current = head;
        while (current) {
            if (current->data == v) {
                Node* newNode = new Node(key);
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next) {
                    current->next->prev = newNode;
                } else {
                    tail = newNode;
                }
                current->next = newNode;
                PrintList();
                PrintListReverse();
                return;
            }
            current = current->next;
        }
        std::cout << "Node with value " << v << " not found." << std::endl;
    }

    void Update_node(int key, int v) {
        Node* current = head;
        while (current) {
            if (current->data == v) {
                current->data = key;
                PrintList();
                PrintListReverse();
                return;
            }
            current = current->next;
        }
        std::cout << "Node with value " << v << " not found." << std::endl;
    }

    void Remove_head() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        PrintList();
        PrintListReverse();
    }

    void Remove_element(int key) {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        if (head->data == key) {
            Remove_head();
            return;
        }

        Node* current = head;
        while (current) {
            if (current->data == key) {
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                current->prev->next = current->next;
                delete current;
                PrintList();
                PrintListReverse();
                return;
            }
            current = current->next;
        }
        std::cout << "Node with value " << key << " not found." << std::endl;
    }

    void Remove_end() {
        if (!tail) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        PrintList();
        PrintListReverse();
    }

    void PrintList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void PrintListReverse() {
        Node* current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.Insert_front(3);
    list.Insert_back(5);
    list.Insert_back(7);
    list.Insert_after_node(6, 5);
    list.Update_node(8, 7);
    list.Remove_head();
    list.Remove_element(5);
    list.Remove_end();

    return 0;
}
