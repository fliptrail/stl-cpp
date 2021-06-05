// Declares common STL algorithms for any container
#include <iostream>

namespace custom_stl{
    template <typename T> void printall(T * begin, T * end, char sep = ' ');

    template <typename T> void printall(T * begin, T * end, char sep){
        while(begin != end){
            std::cout<<*begin<<sep;
            begin++;
        }
        std::cout<<std::endl;
    }

    template <typename T> T min(T a, T b){
        if(a < b){
            return a;
        }
        return b;
    }

    template <typename T> T max(T a, T b){
        if(a > b){
            return a;
        }
        return b;
    }
}