#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void Insert_front(int key) {
        Node* newNode = new Node(key);
        newNode->next = head;
        head = newNode;
        PrintList();
    }

    void Insert_back(int key) {
        Node* newNode = new Node(key);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        PrintList();
    }

    void Insert_after_node(int key, int v) {
        Node* current = head;
        while (current) {
            if (current->data == v) {
                Node* newNode = new Node(key);
                newNode->next = current->next;
                current->next = newNode;
                PrintList();
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
                return;
            }
            current = current->next;
        }
        std::cout << "Node with value " << v << " not found." << std::endl;
    }

    void Remove_head() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        PrintList();
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
        while (current->next) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                PrintList();
                return;
            }
            current = current->next;
        }
        std::cout << "Node with value " << key << " not found." << std::endl;
    }

    void Remove_end() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next->next) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        PrintList();
    }

    void PrintList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};


int main() {
    LinkedList list;

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
