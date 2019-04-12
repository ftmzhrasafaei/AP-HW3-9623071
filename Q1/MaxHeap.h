#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <string>
#include <iostream>
#include <cstdarg>
#include <map>
#include <cmath>

class MaxHeap;
void max_heapify(int*,int ,int);
void build_maxheap(int*,int);

class MaxHeap
{
public:
  
  
  MaxHeap(const std::initializer_list<int>&);
  MaxHeap(const int array[],const int size_of_array);
  MaxHeap();
  MaxHeap(const MaxHeap& heap);
  ~MaxHeap();
  
  void add(int key);
  void Delete();
  
  void printArray()const;
  int size()const;
  int Parent(int k)const;
  int getHeight()const;
  int RightChild(int k)const;
  int LeftChild(int k)const;
  int Max()const;

  void Heapsort();
  
  int& operator[](int k);
  friend std::ostream& operator<<(std::ostream& os ,const MaxHeap& h);

 private:
 
 int count;
 int* arr;

 int par(int k)const;
 int Right(int k)const;
 int Left(int k)const;

};
#endif
