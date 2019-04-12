#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <iostream>
#include <cstdarg>
#include <map>
#include <utility>
#include <cmath>
#include <exception>


using namespace std::rel_ops;

class Vector
{
public:
  
  Vector(const std::initializer_list<int>& list);
  Vector();
  Vector(const Vector& vector);
  Vector(Vector&& vector);
  ~Vector();

  void push_back(int key);
  void show()const;
  void pop_back();

  int size()const;
  int Capacity()const;
  int operator*(const Vector& v);
  int& operator[](int k);
  double Length()const;
    
  Vector operator+(const Vector& v);
  Vector& operator=(const Vector& v);
  Vector& operator=(Vector&& v);
  Vector& operator=(const std::initializer_list<int>& list);

  bool operator<(const Vector& v) const;
  bool operator==(const Vector&v) const;
  
 private:
  
  int count;
  int capacity;
  int* arr;
  
};
#endif
