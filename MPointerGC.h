#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <vector>
#include <mutex>
#include <algorithm>

class MPointerGC {
private:
    struct PointerEntry {
        void* ptr;
        int count;
    };

    std::vector<PointerEntry> pointer_list; // Lista de punteros y sus contadores de referencias
    static MPointerGC* instance;
    std::mutex mtx;

    MPointerGC() {}

public:
    static MPointerGC& getInstance() {
        static MPointerGC instance;
        return instance;
    }

    void registerPointer(void* ptr) {
        std::lock_guard<std::mutex> lock(mtx);
        if (ptr) {
            auto it = std::find_if(pointer_list.begin(), pointer_list.end(),
                                   [ptr](const PointerEntry& entry) { return entry.ptr == ptr; });

            if (it != pointer_list.end()) {
                it->count++; // Incrementa el contador de referencias
            } else {
                pointer_list.push_back({ptr, 1}); // Inicializa el contador de referencias
            }
        }
    }

    void deregisterPointer(void* ptr) {
        std::lock_guard<std::mutex> lock(mtx);
        if (ptr) {
            auto it = std::find_if(pointer_list.begin(), pointer_list.end(),
                                   [ptr](const PointerEntry& entry) { return entry.ptr == ptr; });

            if (it != pointer_list.end()) {
                if (--it->count == 0) {
                    delete static_cast<char*>(ptr); // Libera la memoria si el contador llega a cero
                    pointer_list.erase(it); // Elimina el puntero de la lista
                }
            }
        }
    }
};

#endif // MPOINTERGC_H
