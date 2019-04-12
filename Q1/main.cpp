#include "MaxHeap.h"
#include <iostream>

int main()
{
  
  MaxHeap h1{};
  h1.add(25);
  h1.add(32);
  h1.add(17);
  h1.add(23);
  h1.add(101);  
 
  std::cout<<h1<<std::endl;  
	/* 
	101,
	32, 17,
	23, 25
	*/
  std::cout<<"parent(2): "<<h1.Parent(2)<<std::endl;
  // 101
  std::cout<<"leftChild(0) : "<<h1.LeftChild(0) << std::endl;  // 32
  std::cout<<"RightChild(0): "<<h1.RightChild(0) << std::endl;  // 17


  int arr[7] {23, 1, 7, 52, 11, 10, 75};
  MaxHeap h2{arr, 7};
			
  std::cout << h2 << std::endl;
  std::cout<<"h2 height: "<<h2.getHeight()<<std::endl;
	// 2


  MaxHeap h3{h2};

  h2.Heapsort();
  h2.printArray();
	// 75, 52, 23, 11, 10, 7, 1

	
  std::cout <<"h3 MAx : " <<h3.Max()<<std::endl;
  
  //75

  std::cout<<"before : "<<h3[0]<<std::endl;
  h3[0] = h3[0] - 25;
  std::cout<<"after : "<<h3[0]<<std::endl;
  // h3.printArray();
  std::cout <<"h3 MAx : " <<h3.Max()<<std::endl;
  
	//52
  h3.Delete();
  std::cout <<"h3 MAx : " <<h3.Max()<<std::endl;
  
	//50
  MaxHeap h4{1,5,8,2,4};
  std::cout<<h4<<std::endl;
		
  return 0;
}
