// Declares common STL algorithms for any container
#include <iostream>

namespace custom_stl{
    template <typename T> void printall(T * begin, T * end, char sep = ' ');
    template <typename T> T min(T a, T b);
    template <typename T> T max(T a, T b);
    template <typename T> T * min_element(T * begin, T * end);
    template <typename T> T * max_element(T * begin, T * end);

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

    // returns pointer to first occurance of the minimum element in the given pointer range
    // return end pointer if container is empty
    template <typename T> T * min_element(T * begin, T * end){
        if(begin == end){
            return end;
        }
        T * ans = begin;
        T * curr_element = begin + 1;
        while(curr_element != end){
            if(*curr_element < *ans){
                ans = curr_element;
            }
            curr_element++;
        }
        return ans;
    }

    // returns pointer to first occurance of the maximum element in the given pointer range
    // return end pointer if container is empty
    template <typename T> T * max_element(T * begin, T * end){
        if(begin == end){
            return end;
        }
        T * ans = begin;
        T * curr_element = begin + 1;
        while(curr_element != end){
            if(*curr_element > *ans){
                ans = curr_element;
            }
            curr_element++;
        }
        return ans;
    }
}