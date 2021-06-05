#include "import_all.h"
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
    a.push_back(37);
    cout<<a.get_element(2)<<endl;
    cout<<a.get_element(3)<<endl;
    cout<<a.max_capacity()<<endl;
    a.push_back(-1);
    a.push_back(24);
    cout<<a.get_element(2)<<endl;
    cout<<a.get_element(3)<<endl;
    cout<<a.get_element(4)<<endl;
    cout<<a.get_element(5)<<endl;
    cout<<a.max_capacity()<<endl;
    printall(a.begin(), a.end(), ' ');
    cout<<*min_element(a.begin(), a.end())<<endl;
    cout<<*max_element(a.begin(), a.end())<<endl;
    cout<<(find(a.begin(), a.end(), 37) - a.begin())<<endl;
    printall(a.begin(), a.end(), ' ');
    reverse(a.begin(), a.end());
    printall(a.begin(), a.end(), ' ');
    a.push_back(50);
    printall(a.begin(), a.end(), ' ');
    reverse(a.begin() + 1, a.begin() + 4);
    printall(a.begin(), a.end(), ' ');
    
    custom_stl::pair<int, int> hello;
    vector<vector<custom_stl::pair<int, double>>> hello2(5);
    return 0;
}
