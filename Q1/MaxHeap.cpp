#include "MaxHeap.h"



// maxheap construcror with list
MaxHeap::MaxHeap(const std::initializer_list<int>& list){
  //  std::cout<<"Binary tree created by list!"<<std::endl;
  // size of maxheap array = size of input list
  count = list.size();
  // allocating memory
  arr = new int[count];

  
  // copying data in list to maxheap array
  int i{};
  for(auto x:list){
    arr[i] = x;
    i++;
  }
  

  // building maxheap with array 
  build_maxheap(arr,count);
  
}


//maxheap constructor with an array and its size
MaxHeap::MaxHeap(const int array[],const int size_of_array){
  //  std::cout<<"Binary tree created by array!"<<std::endl;
  //szie of maxheap array = size of input array
  count = size_of_array;
  //allocating memory 
  arr = new int[count];
  //copying data from input array to maxheap array
  for(int i{} ; i < count ; i++){
    arr[i] = array[i];
  }

  //building maxheap with array
  build_maxheap(arr,count);
    
}

//maxheap copy constructor
MaxHeap:: MaxHeap(const MaxHeap& heap){
  //  std::cout<< " binary tree copy constructor!"<<std::endl;
  // size of maxheap array = size of input heap
  count = heap.count;
  //allocating memory
  arr = new int[count];
  // copying data
    for(int i{} ; i < count ; i++){
    arr[i] = heap.arr[i];
  }
  
}




// maxheap default constructor 
MaxHeap::MaxHeap(){
  //  std::cout<<" Binary tree without input"<<std::endl;
  this->count = 0;
  arr=nullptr;
}


//maxheap destructor 
MaxHeap::~MaxHeap(){
  //  std::cout<<" Binary tree deleted!"<<std::endl;
  //free allocated memory
  delete[] arr;
  
}

// function for adding new data 
void MaxHeap::add(int key){
  //  std::cout<<"new node added"<<std::endl;
  // allocating memory for copying old heap 
  int* help{new int[count]};
  // copying old heap to help array
  for(int i{} ; i < count ; i++)
    help[i] = arr[i];
  //free allocated memory
  delete[] arr;
  //increasing size of maxheap array
  count++;
  //allocating memory for new maxheap with increased size 
  arr = new int[count];
  //copying old data to new heap
  for(int i{} ; i < count - 1 ; i++){
    arr[i] = help[i];
  }
  // adding input node at the end of heap
  arr[count - 1] = key;
  // free allocated memory for helping to save data
  delete[] help;
  // building heap with new array include new node
  build_maxheap(arr,count);

}

//function for showing maxheap in a line
void MaxHeap::printArray()const{
  for(int i{} ; i < count - 1 ; i++)
    std::cout<<arr[i]<<",";
  std::cout<<arr[count - 1]<<std::endl;
}


// function for returing size of heap
int MaxHeap::size()const{return count;}

//find key of parent node input
int MaxHeap::par(int k)const{
  if(k == 0)
    return 0;
  else
    return ((k-1)/2);
}

//find  key of rightchild node input
int MaxHeap::Right(int k)const{
  return (2*k+2);
}

//fing key of leftchild node input
int MaxHeap::Left(int k)const{
  return (2*k+1);
}

//find value of parnet node input
int MaxHeap::Parent(int k)const{
  return (arr[par(k)]);
}


//find value of rightchild node input
int MaxHeap::RightChild(int k)const{
  return (arr[Right(k)]);
}

//find valude of leftchild node input
int MaxHeap::LeftChild(int k)const{
  return (arr[Left(k)]);
}

//return vaule of first node include max value in heap
int MaxHeap::Max()const{

  return arr[0];
 }



//delete the last node of heap
void MaxHeap::Delete(){
  //  std::cout<<"Delete a node"<<std::endl;
  //allocating memory for saving old data
  int*help{new int[count - 1]};
  //copying old data to help array
  for(int i{1} ; i < count ; i++){
    help[i - 1] = arr[i];
  }

  //free allocated memory of maxheap array
  delete[] arr;
  //decreasing size of maxheap array
  count--;
  //allocating new memory for maxheap array
  arr = new int[count];
  //coping data to maxheap arrya without last node
  for(int i{}; i < count ; i++){
    arr[i] = help[i];
  }
  //free allocated memory that saved old data
  delete[] help;
  // building maxheap with new data
  build_maxheap(arr,count);
}

//return value of node input
int& MaxHeap::operator[](int k)
{
  //also for saving anatomy of maxheap after operator + - = * ...
  // build maxheap for sure
  build_maxheap(arr,count);

  return arr[k];
}







//print heap like a tree 
std::ostream& operator<<(std::ostream& os ,const MaxHeap& h){
  int levelnum{};
  int levelis{1};
  int levelprint{};
  std::string space{" "};
  
  for(int i{} ; i < h.count ; i++)
    {
    if(levelprint == 0)
      os<<'\n'; 
    os<<space<< h.arr[i]<<space;
    levelprint++;
    if(levelprint == levelis){
      levelnum++;
      levelis  *= 2;
      levelprint = 0;
    }
  }
  os<<'\n';

  return os;
}

//return height of tree
int MaxHeap::getHeight()const{
  return (ceil(log2(count + 1)) - 1);
}


//sorting heap form max to min
void MaxHeap::Heapsort(){
  //  std::cout<<"Heap sort!"<<std::endl;
  //buildng maxheap
   build_maxheap(arr,count);
   //swaping first node and last node
   //making heap withount last node
   //arrange heap min to max
  for(int i{count - 1} ; i >= 0 ; i--){
    std::swap(arr[0],arr[i]);
    max_heapify(arr,i,0);
  }
  //allocating new memory for saving data max to min
  int*help{new int[count]};
  //copying data of heap to help array 
  for(int i{} ;i < count ; i++)
    help[i] = arr[count - 1 - i];
  //copying rearranged max to min to heap array
  for(int i{} ; i < count ; i++)
    arr[i] = help[i];
  //free allocated memory
  delete[] help;
  

}



//building a maxheap with array and its size
void build_maxheap(int arr[], int n){

  for (int i = n / 2 - 1; i >= 0; i--)
     max_heapify(arr, n, i);
}

//for each input node "i" 
void max_heapify(int arr[], int n, int i)
{
  //as default set i as max(parent) node
   int largest = i;
   //find node of leftchild node i 
   int l = 2*i + 1;
   //find node of rightchild node i
   int r = 2*i + 2;
   
   //check that is parent was smaller than left child
   //,set leftchild as max node
   if (l < n && arr[l] > arr[largest])
     largest = l;
   //check that is parent was smaller than right child
   //,set rightchild as max node
   if (r < n && arr[r] > arr[largest])
     largest = r;
   //check that  did one of 2 previous if do?
   //if yes ; swap them
   if (largest != i)
   {
     std::swap(arr[i], arr[largest]);

     // Recursively maxheapify the affected tree
     max_heapify(arr, n, largest);
   }
}
