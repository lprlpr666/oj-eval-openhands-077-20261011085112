#ifndef SOLUTION_HPP
#define SOLUTION_HPP

namespace sjtu {
    class CrossArray {
    private:
        int** arrays;        // Pointers to each array
        int* array_sizes;    // Size of each array
        int capacity;        // Maximum number of arrays
        int count;           // Current number of inserted arrays
        
    public:
        explicit CrossArray(int lines);
        CrossArray(const CrossArray & o);
        CrossArray & WhichGreater(CrossArray & o);
        bool IsSame(const CrossArray & o);
        bool InsertArrays(const int * Input, int size);
        void AppendArrays(const int * Input, int Line, int size);
        void DoubleCrossLength();
        const int * AtArray(int i);
        int & At(int i, int j);
        ~CrossArray();
    };
    
    // Constructor
    CrossArray::CrossArray(int lines) : capacity(lines), count(0) {
        arrays = new int*[capacity];
        array_sizes = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            arrays[i] = nullptr;
            array_sizes[i] = 0;
        }
    }
    
    // Copy Constructor
    CrossArray::CrossArray(const CrossArray & o) : capacity(o.capacity), count(o.count) {
        arrays = new int*[capacity];
        array_sizes = new int[capacity];
        
        for (int i = 0; i < capacity; i++) {
            if (o.arrays[i] != nullptr) {
                array_sizes[i] = o.array_sizes[i];
                arrays[i] = new int[array_sizes[i]];
                for (int j = 0; j < array_sizes[i]; j++) {
                    arrays[i][j] = o.arrays[i][j];
                }
            } else {
                arrays[i] = nullptr;
                array_sizes[i] = 0;
            }
        }
    }
    
    // Destructor
    CrossArray::~CrossArray() {
        for (int i = 0; i < capacity; i++) {
            if (arrays[i] != nullptr) {
                delete[] arrays[i];
                arrays[i] = nullptr;
            }
        }
        delete[] arrays;
        delete[] array_sizes;
    }
    
    // InsertArrays function
    bool CrossArray::InsertArrays(const int * Input, int size) {
        if (count >= capacity) {
            return false;
        }
        
        arrays[count] = new int[size];
        array_sizes[count] = size;
        
        for (int i = 0; i < size; i++) {
            arrays[count][i] = Input[i];
        }
        
        count++;
        return true;
    }
    
    // At function
    int & CrossArray::At(int i, int j) {
        return arrays[i][j];
    }
    
    // WhichGreater function
    CrossArray & CrossArray::WhichGreater(CrossArray & o) {
        int this_total = 0;
        int o_total = 0;
        
        for (int i = 0; i < capacity; i++) {
            if (arrays[i] != nullptr) {
                this_total += array_sizes[i];
            }
        }
        
        for (int i = 0; i < o.capacity; i++) {
            if (o.arrays[i] != nullptr) {
                o_total += o.array_sizes[i];
            }
        }
        
        if (this_total >= o_total) {
            return *this;
        } else {
            return o;
        }
    }
    
    // IsSame function
    bool CrossArray::IsSame(const CrossArray & o) {
        return (this == &o);
    }
    
    // AppendArrays function
    void CrossArray::AppendArrays(const int * Input, int Line, int size) {
        if (arrays[Line] == nullptr) {
            arrays[Line] = new int[size];
            array_sizes[Line] = size;
            for (int i = 0; i < size; i++) {
                arrays[Line][i] = Input[i];
            }
        } else {
            int* new_array = new int[array_sizes[Line] + size];
            for (int i = 0; i < array_sizes[Line]; i++) {
                new_array[i] = arrays[Line][i];
            }
            for (int i = 0; i < size; i++) {
                new_array[array_sizes[Line] + i] = Input[i];
            }
            delete[] arrays[Line];
            arrays[Line] = new_array;
            array_sizes[Line] += size;
        }
    }
    
    // AtArray function
    const int * CrossArray::AtArray(int i) {
        return arrays[i];
    }
    
    // DoubleCrossLength function
    void CrossArray::DoubleCrossLength() {
        int new_capacity = capacity * 2;
        int** new_arrays = new int*[new_capacity];
        int* new_array_sizes = new int[new_capacity];
        
        for (int i = 0; i < new_capacity; i++) {
            if (i < capacity) {
                new_arrays[i] = arrays[i];
                new_array_sizes[i] = array_sizes[i];
            } else {
                new_arrays[i] = nullptr;
                new_array_sizes[i] = 0;
            }
        }
        
        delete[] arrays;
        delete[] array_sizes;
        
        arrays = new_arrays;
        array_sizes = new_array_sizes;
        capacity = new_capacity;
    }
}

#endif