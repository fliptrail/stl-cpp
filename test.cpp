#include "vector.h"
#include <iostream>

using namespace std;
using namespace custom_stl;

int main(){
    vector<double> b(5, 1.14);
    cout<<b.get_element(2)<<endl;
    b.resize(8, 2.69);
    cout<<b.get_element(2)<<endl;
    cout<<b.get_element(6)<<endl;
    cout<<b.max_capacity()<<endl;
    vector<int> a(3, 10);
    cout<<a.get_element(2)<<endl;
    cout<<a.max_capacity()<<endl;
    a.push_back(17);
    cout<<a.get_element(2)<<endl;
    cout<<a.get_element(3)<<endl;
    cout<<a.max_capacity()<<endl;
    a.push_back(21);
    cout<<a.get_element(2)<<endl;
    cout<<a.get_element(3)<<endl;
    cout<<a.get_element(4)<<endl;
    cout<<a.get_element(5)<<endl;
    cout<<a.max_capacity()<<endl;
    return 0;
}
