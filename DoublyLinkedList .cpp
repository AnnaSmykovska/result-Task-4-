#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;
    Node(T value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {

    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* tempNext = temp->next;
            delete temp;
            temp = tempNext;
        }
    }

    void insertAtHead(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteFirst() {
        if (head == nullptr) {
            std::cout << "List is empty, nothing to delete" << std::endl;
            return;
        }
        Node<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteLast() {
        if (tail == nullptr) {
            std::cout << "List is empty, nothing to delete" << std::endl;
            return;
        }
        Node<T>* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void display() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    int size() {
        Node<T>* temp = head;
        int size = 0;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        return size;
    }
};

int main() {
    DoublyLinkedList<int> list;

    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    std::cout << "List after adding elements: ";
    list.display();

    list.deleteFirst();
    std::cout << "List after removing the first element: ";
    list.display();

    list.deleteLast();
    std::cout << "List after removing the last element: ";
    list.display();

    std::cout << "Length of the list: " << list.size() << std::endl;

    return 0;
}