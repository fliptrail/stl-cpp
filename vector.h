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
            void push_back(T);
    };

    // default constructor
    template <typename T> vector<T>::vector(){
        beginit = new T[0];
        endit = beginit;
        curr_size = 0;
        capacity = 0;
    }

    // create vector of given size with empty elements by delegation constructor
    template <typename T> vector<T>::vector(int allot_size) : vector<T>::vector(){
        resize(allot_size);
    }

    // create vector of given size with given elements by delegation constructor
    template <typename T> vector<T>::vector(int allot_size, T element) : vector<T>::vector(allot_size){
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

    int min(int a, int b){
        if (a < b){
            return a;
        }
        return b;
    }

    template <typename T> void vector<T>::resize_internal(int allot_size){
        capacity = allot_size * CAPACITY_TO_SIZE;
        T * temp = new T[capacity];
        for(int i = 0; i < min(allot_size, curr_size); ++i){
            temp[i] = beginit[i];
        }
        delete[] beginit;
        beginit = temp;
        endit = beginit + allot_size;
    }
    
    template <typename T> void vector<T>::resize(int allot_size){
        resize_internal(allot_size);
        curr_size = allot_size;
    }

    template <typename T> void vector<T>::resize(int allot_size, T element){
        resize_internal(allot_size);
        if(allot_size > curr_size){
            fill_same_element(beginit + curr_size, element);
        }
        curr_size = allot_size;
    }

    template <typename T> void vector<T>::push_back(T element){

    }

    template <typename T> void vector<T>::fill_same_element(T* start, T element){
        for(T* it = start; it != endit; ++it){
            *it = element;
        }
    }
}