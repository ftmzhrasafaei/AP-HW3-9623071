#include <iostream>
#include "Vector.h"

Vector make_vector(int n);
int main(){
  Vector v1{1,2,3};
  std::cout<<"v1 : "<<std::endl;
  v1.show();
  Vector v2{make_vector(2)};
  std::cout<<"v2 : "<<std::endl;
  v2.show();
  Vector v3{v1};
  std::cout<<"v3 : "<<std::endl;
  v3.show();
  Vector v4{};
  std::cout<<"v4 : "<<std::endl;
  v4.show();
  v4.push_back(6);
  std::cout<<"v4 : "<<std::endl;
  v4.show();
  v2.pop_back();
  std::cout<<"v2 : "<<std::endl;
  v2.show();
  Vector v5{v1 + v2};
  std::cout<<"v5 : "<<std::endl;
  v5.show();
  v4 = v2;
  std::cout<<"v4 : "<<std::endl;
  v4.show();
  v3 = v3 + v1;
  std::cout<<"v3 : "<<std::endl;
  v3.show();
  v2 = {5, 8 ,9};
  std::cout<<"v2 : "<<std::endl;
  v2.show();
  
   return 0;
}

//for testing move constructor 
Vector make_vector(int n){
  Vector v1{1,5,9};
  Vector v2{1,2,4,8,16};
  if(n%2 == 1)
    return v1;
  else
    return v2;
}

