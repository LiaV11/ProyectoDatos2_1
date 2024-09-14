#ifndef MPOINTER_H
#define MPOINTER_H

#include "MPointerGC.h"

template <typename T>
class MPointer {
private:
    T* ptr;
    int id;

public:
    // Constructor por defecto
    MPointer() : ptr(nullptr), id(-1) {}

    // Constructor con puntero
    explicit MPointer(T* p) : ptr(p), id(MPointerGC::getInstance().registerPointer(p)) {}

    // Constructor de copia
    MPointer(const MPointer& other) : ptr(other.ptr), id(other.id) {}

    // Destructor
    ~MPointer() {
        if (ptr) {
            MPointerGC::getInstance().deregisterPointer(ptr);
            delete ptr;
        }
    }

    // Operador de acceso a miembros
    T* operator->() {
        return ptr;
    }

    // Operador de desreferenciación
    T& operator*() {
        return *ptr;
    }

    // Método estático para crear un nuevo MPointer
    static MPointer<T> New() {
        return MPointer<T>(new T());
    }
};

#endif // MPOINTER_H
