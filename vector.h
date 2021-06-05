#include <iostream>
#define CAPACITY_TO_SIZE 1.5

// vector <T> class
namespace custom_stl{
    template <typename T> class vector{
        private:
            T * beginit;
            T * endit;
            int curr_size;
            int capacity;
            void fill_same_element(T*, T);
            void resize_internal(int);
            void shift_element(T*, bool, int);

        public:
            vector();
            vector(int);
            vector(int, T);
            int size();
            int max_capacity();
            bool empty();
            void resize(int);
            void resize(int, T);
            T * begin();
            T * end();
            T get_element(int);
            void set_element(int, T);
            void push_back(T);
            void insert(T*, T);
            void insert(int, T);
    };

    // default constructor
    template <typename T> vector<T>::vector(){
        beginit = new T[0];
        endit = beginit;
        curr_size = 0;
        capacity = 0;
    }

    // create vector of given size with empty elements by delegation constructor
    template <typename T> vector<T>::vector(int new_size) : vector<T>::vector(){
        resize(new_size);
    }

    // create vector of given size with given elements by delegation constructor
    template <typename T> vector<T>::vector(int new_size, T element) : vector<T>::vector(new_size){
        fill_same_element(beginit, element);
    }

    template <typename T> T * vector<T>::begin(){
        return beginit;
    }

    template <typename T> T * vector<T>::end(){
        return endit;
    }

    template <typename T> int vector<T>::size(){
        return curr_size;
    }

    template <typename T> int vector<T>::max_capacity(){
        return capacity;
    }

    template <typename T> bool vector<T>::empty(){
        return curr_size == 0;
    }

    // return element at given index
    template <typename T> T vector<T>::get_element(int idx){
        return *(beginit + idx);
    }

    // set given element at given index
    template <typename T> void vector<T>::set_element(int idx, T element){
        beginit[idx] = element;
    }

    int min(int a, int b){
        if (a < b){
            return a;
        }
        return b;
    }

    template <typename T> void vector<T>::resize_internal(int new_size){
        capacity = new_size * CAPACITY_TO_SIZE;
        T * temp = new T[capacity];
        for(int i = 0; i < min(new_size, curr_size); ++i){
            temp[i] = beginit[i];
        }
        delete[] beginit;
        beginit = temp;
        endit = beginit + new_size;
    }
    
    template <typename T> void vector<T>::resize(int new_size){
        resize_internal(new_size);
        curr_size = new_size;
    }

    template <typename T> void vector<T>::resize(int new_size, T element){
        resize_internal(new_size);
        if(new_size > curr_size){
            fill_same_element(beginit + curr_size, element);
        }
        curr_size = new_size;
    }

    template <typename T> void vector<T>::push_back(T element){
        if(curr_size == capacity){
            resize(curr_size);
        }
        beginit[curr_size] = element;
        curr_size++;
    }

    template <typename T> void vector<T>::fill_same_element(T* start, T element){
        for(T* it = start; it != endit; ++it){
            *it = element;
        }
    }
    
    template <typename T> void vector<T>::insert(int idx, T element){
        insert(beginit + idx, element);
    }

    template <typename T> void vector<T>::insert(T* pos, T element){
        if(curr_size == capacity){
            resize(curr_size);
        }
        shift_element(pos, 1, 1);
        *pos = element;
    }

    // dir = 1 for right, dir = 0 to shift left
    template <typename T> void vector<T>::shift_element(T* pos, bool dir, int count){
        T * curr_element;
        T * last_element;
        if(!dir){
            dir = -1;
            curr_element = pos + count;
            last_element = beginit + curr_size - 1;
        }
        else{
            curr_element = beginit + curr_size;
            last_element = pos;
        }
        while(curr_element != last_element){
            curr_element += -1*dir;
            *(curr_element + dir*count) = *curr_element;
        }
        curr_size += dir*count;
        endit = beginit + curr_size;
    }
}
