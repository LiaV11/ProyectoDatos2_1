#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "MPointer.h"

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        MPointer<Node> next;
        MPointer<Node> prev;
        T data;

        // Constructor por defecto
        Node() : next(nullptr), prev(nullptr), data(T()) {}
    };

    MPointer<Node> head;
    MPointer<Node> tail;
    int size;

public:
    DoublyLinkedList() : size(0), head(nullptr), tail(nullptr) {}

    void append(T value) {
        MPointer<Node> newNode = MPointer<Node>::New();
        (*newNode).data = value;
        (*newNode).next = nullptr;

        if (tail) {
            (*tail).next = newNode;
            (*newNode).prev = tail;
        } else {
            (*newNode).prev = nullptr;
            head = newNode;
        }

        tail = newNode;
        size++;
    }

    T& operator[](int index) {
        MPointer<Node> current = head;
        for (int i = 0; i < index; i++) {
            current = (*current).next;
        }
        return (*current).data;
    }

    // Método para intercambiar el contenido de dos listas
    void swap(DoublyLinkedList& other) noexcept {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(size, other.size);
    }

    void swap(int other, int i);

    int getSize();
};

#endif // DOUBLYLINKEDLIST_H
