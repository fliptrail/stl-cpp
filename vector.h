#include <iostream>

// vector <T> class
namespace custom_stl{
    template <typename T> class vector{
        T a;
        public:
            vector();
    };

    template <typename T> vector<T>::vector(){
        std::cout<<"Vector initialized"<<std::endl;
    }
}