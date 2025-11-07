#include <cstddef>

template <typename T>
class DynamicArray {
private:
    T* data;
    size_t size;
    size_t capacity;

    void increase_capacity() {
        size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
        T* new_data = new T[new_capacity];

        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    DynamicArray() : data(nullptr), size(0), capacity(0) {}
    
    ~DynamicArray() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            increase_capacity();
        }
        data[size++] = value;
    }

    const T* get_data() const {
        return data;
    }
    
    size_t get_size() const {
        return size;
    }
};