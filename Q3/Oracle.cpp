#include "Oracle.h"
//oracle constructor
Oracle::Oracle(std::string Name){
  this->Name = Name;
  //  std::cout<<" Oracle constructor"<<std::endl;
}

//set 2 person as their spouse 
bool Oracle::marry(human* p1, human* p2){
  if(p1->getAge()>=18 && p2->getAge()>=18 && p1->canMarry(p2))
    {
      // std::cout<<" can marry "<<std::endl;
      p1->setspouse(*p2);
      //  std::cout<<" spouse seted"<<std::endl;
    return true;
    }
  else
    return false;
}



void Oracle::setChild(human*child, human*mom, human*dad){
  // ezdevaj nkrdn ya bache baraabar nbodn ::: if
 

    int numchild{mom->numberOfChildren};
    if(mom->Children == 0){
      mom->Children = new human*[numchild];
      dad->Children = new human*[numchild];

      (mom->Children[0]) = child;
      (dad->Children[0]) = child;

    }
    else{
      int j{};
      for(int i{} ; i<numchild ; i++){
	if(mom->Children[i] == 0){
	  i = j;
	  break;
      }
      }
      (mom->Children[j]) = child;
      (dad->Children[j]) = child;
      
    }
    //  std::cout<<"child seted"<<std::endl;
    (child->mother) = mom;
    (child->father) = dad;
    // std::cout<<" momy & dady seted"<<std::endl;
 
  
  
}


  
