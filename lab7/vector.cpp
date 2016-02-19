#include <iostream>
#include <random>
#include <algorithm>
#include <functional>
#include <iterator>

void print_vector(const std::vector<int> &v)
{
    for(auto i = v.begin(); i != v.end(); ++i)
    {
        std::cout << *i << " ";
    }
}

int main(){
    std::random_device rd;
    std::mt19937 mersenne_engine(rd());
    std::uniform_int_distribution<int> dis(1, 100 );
    auto gen = std::bind(dis, mersenne_engine);
    std::vector<int> v (15);
    std::generate(begin(v), end(v), gen);
    std::cout<<"Random:" <<std::endl;
    print_vector(v);
    std::cout << std::endl;
    std::cout<<"Sorted:" <<std::endl;
    std::sort(v.begin(), v.end());
    print_vector(v);
    std::cout << std::endl;
    std::vector<int> vCopy (v);
    std::cout<<"Before Shuffle:" <<std::endl;
    print_vector(vCopy);
    std::cout << std::endl;
    std::random_shuffle ( vCopy.begin(), vCopy.end());
    std::cout<<"After Shuffle:" <<std::endl;
    print_vector(vCopy);
    std::cout << std::endl;
}//end of main

