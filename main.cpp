#include <iostream>
#include "MPointer.h"

int main() {
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 42;
    std::cout << "El valor almacenado en MPointer es: " << *ptr << std::endl;
    return 0;
}
