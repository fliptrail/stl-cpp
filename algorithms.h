// Declares common STL algorithms for any container
#include <iostream>

namespace custom_stl{
    template <typename T> void printall(T * begin, T * end, char sep = ' ');
    template <typename T> T min(T a, T b);
    template <typename T> T max(T a, T b);
    template <typename T> T * min_element(T * begin, T * end);
    template <typename T> T * max_element(T * begin, T * end);
    template <typename T> T * find(T * begin, T * end, T element);
    template <typename T> void reverse(T * begin, T * end);
    template <typename T> void swap(T &a, T &b);

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

    // returns pointer to first occurance of the given element in the given pointer range
    // return end pointer if element is not found or container is empty
    template <typename T> T * find(T * begin, T * end, T element){
        while(begin != end){
            if(*begin == element){
                return begin;
            }
            begin++;
        }
        return begin;
    }

    template <typename T> void swap(T &a, T &b){
        T temp = a;
        a = b;
        b = temp;
    }

    template <typename T> void reverse(T * begin, T * end){
        if(begin == end){
            return ;
        }
        end--;
        while(begin != end){
            custom_stl:swap(*begin, *end);
            begin++;
            if(begin == end){
                return ;
            }
            end--;
        }
    }

    template <typename T1, typename T2> custom_stl::pair<T1, T2> make_pair(T1 a, T2 b){
        custom_stl::pair<T1, T2> temp;
        temp.first = a;
        temp.second = b;
        return temp;
    }
}
