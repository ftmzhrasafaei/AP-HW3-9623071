#include "Vector.h"


//constructor works with list
Vector::Vector(const std::initializer_list<int>& list){
  int j{};
  //  std::cout<<"Vector created with list!"<<std::endl;
  //size of array of  vector = size of list
  count = list.size();
  //calculating capacity
  while(capacity < count){
    capacity = pow(2,j);
    j++;
  }
  //allocating memory by capacity
  arr = new int[capacity];
  int i{};
  //copying list into array of vector
  for(auto x:list){
    arr[i] = x;
    i++;
  }
  
    
}

//move constructor 
Vector::Vector(Vector&& vector){
  //  std::cout<< " Vector move constructor!"<<std::endl;
  // size of array of vector = size of input vector
  count = vector.count;
  // capcitu of array of vector = capacity of input vector
  capacity = vector.capacity;
  //set array of vector = array of input vector  
  arr = vector.arr;
  //seting array of input vector = null 
  vector.arr = nullptr;
  //stealing array of input vector
}

//copy constructor
Vector::Vector(const Vector& vector){
  //  std::cout<< " Vector copy constructor!"<<std::endl;
  // size of array of vector = size of input vector
  count = vector.count;
  // capcitu of array of vector = capacity of input vector
  capacity = vector.capacity;
  //allocating memory by capacity
  arr = new int[capacity];
  //copying data from input to array
    for(int i{} ; i < count ; i++){
    arr[i] = vector.arr[i];
  }
  
}


//default constructor
Vector::Vector(){
  //std::cout<<" Vector without input"<<std::endl;
  this->count = 0;
  this->capacity = 1;
  arr=new int[capacity];
  
}





//dectructor
Vector::~Vector(){
  //  std::cout<<" Vector deleted!"<<std::endl;
  //free allocaed memory 
   delete[] arr;
  
}





//fucntion for add new data at the end of vector
void Vector::push_back(int key){
  //allocating memory for saving old data
  int* help{new int[count]};
  //copying old data
  for(int i{} ;i < count ; i++)
    help[i] = arr[i];
  //free old array of vector
  delete[] arr;
  //incresing size of array of vector
  count++;
  int j{};
  //re-calclutig capcity
  while(capacity < count){
    capacity = pow(2,j);
    j++;
  }
  //reallocating memory by new capacity
  arr = new int[capacity];
  //copying old data to new array
  for(int i{} ; i < count - 1 ; i++){
    arr[i] = help[i];
  }
  //copying input data at the end of array
  arr[count - 1] = key;
  //free allocated memory that saved old data
  delete[] help;

}

// function for print vector in a line 
void Vector::show()const{
  if(count > 0){
  for(int i{} ; i < count - 1 ; i++)
    std::cout<<arr[i]<<",";
  std::cout<< arr[count - 1] <<std::endl;
  }
  if(count == 0)
    std::cout<< "empty vector"<<std::endl;
}

//retun size of array , in otherword ; number of vector data
int Vector::size()const{return count;}





//deleting a data at the end of vector
void Vector::pop_back(){
  //allocating  memory for save old data
  int*help{new int[count - 1]};
  //copying old data
  for(int i{} ; i < count - 1 ; i++)
    help[i] = arr[i];
  //free old array
  delete[] arr;
  //decreasing size of array
  count--;
  //re-calculating capacity of array
  int j{};
  while(capacity < count){
    capacity = pow(2,j);
    j++;
  }
  //re-allocating array by new capacity
  arr = new int[capacity];
  //copying data without last one
  for(int i{} ; i < count ; i++){
    arr[i] = help[i];
  }
  //free allocated memory that saved old data
  delete[] help;
}



//retun value of input key
int& Vector::operator[](int k)
{

  //cheking that input key be in range 
  if((k >= 0)&&(k < count))
    return arr[k];
  
   throw std::out_of_range("out of range") ;
}


//retunt capacity of array 
int Vector::Capacity()const{  
  return capacity;
}

//adding 2 vector
//more explanatin in report
Vector Vector::operator+(const Vector& v){
  //  std::cout<<"opeartor + "<<std::endl;
  //new vector = v1 + v2 
  Vector help{};
  //if size 2 vector wasnt equal 
  help.count = std::max(count , v.count);
  int j{};
  //calculating capacity
  while(help.capacity < help.count){
    help.capacity = pow(2,j);
    j++;
  }
  //adding 2 vector until min size   
  for(int i{} ; i < std::min(count,v.count) ; i++){
    help.arr[i] = this->arr[i] + v.arr[i];
  }
  //this for copy extra data of biger vector at the end of result 
  for(int i{std::min(count , v.count)} ; i < help.count ; i++){
    if(count < v.count){
      help.arr[i] = v.arr[i];
    }
    else if(count > v.count){
      help.arr[i] = arr[i];
    }
    else
      break;
  }
  return help;
	     
}



//value of inner product
//more explanatin in report
int Vector::operator*(const Vector& v){
  std::cout<<"opeartor *: inner product "<<std::endl;
  int inner_product{};

   for(int i{};i<std::min(count , v.count);i++){
     inner_product = (arr[i] * v.arr[i])+inner_product;
  }
   
  return inner_product;
}



//seting equal 2 vectors 
Vector& Vector::operator=(const Vector& v){
  //  std::cout<<"operator= copy "<<std::endl;
  //size of array of vector = size of array of input vector
  count = v.count;
  //size of array of vector = size of array of input vector
  capacity = v.capacity;
  //free allocated memory 
  delete[] arr;
  //re-allocating memory by new capacity 
  arr = new int[capacity];
  //copying data
  for(int i{} ; i < count ; i++){
    arr[i] = v.arr[i];
  }
  return  *this;
}

//seting equal 2 vector ,input is rvalue
Vector& Vector::operator=(Vector&& v){
  //  std::cout<<"operator= move "<<std::endl;
  //size of array of vector = size of array of input vector
  count = v.count;
  //size of array of vector = size of array of input vector
  capacity = v.capacity;
  //free allocated memory
  delete[] arr;
  //array of input vector = array of vector
  arr = v.arr;
  //set array of input vector = null
  v.arr = nullptr;
  return  *this;
}



Vector& Vector::operator=(const std::initializer_list<int>& list){
  // std::cout<<"operator= list "<<std::endl;
  //free allocated memory
  delete[] arr;
  int j{};
  //size of array of vector = size of list
  count = list.size();
  //calculating capacity
  while(capacity < count){
    capacity = pow(2,j);
    j++;
  }
  //allocating memory by new capacity 
  arr = new int[capacity];
  int i{};
  //copying list into array of vector
  for(auto x:list){
    arr[i] = x;
    i++;
  }
  
  return  *this;

  
}

//comparing length of vectors by < 
bool Vector::operator<(const Vector& v)const{
  return this->Length()<v.Length();
}
//comparing length of vectors by = 
bool Vector::operator==(const Vector& v)const{
  return this->Length() == v.Length();
}

//calculating length of vector
double Vector::Length()const{
  double length{};
  int length2{};
  for(int i{} ; i < count ; i++){
    length2 = pow(arr[i],2) + length2;
  }
  length = pow(length2,0.5);
  return length;
}
