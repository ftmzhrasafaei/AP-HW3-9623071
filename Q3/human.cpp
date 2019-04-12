#include "human.h"
#include <iostream>
#include <string>
#include "Oracle.h"
#include <ctime>

//constructor definition
human::human(std::string firstName , std::string lastName , int hairColor , int eyeColor , int age ,bool gender , int numberOfChildren){
  // std::cout<<"human main costructor"<<std::endl;
  // seting view by input 
  this->firstName = firstName;
  this->lastName = lastName;
  this->hairColor = hairColor;
  this->eyeColor = eyeColor;
  this->age = age;
  this->gender = gender;
  this->numberOfChildren = numberOfChildren;
  //allocating memory for human**
  Children=new human*[numberOfChildren];
  
  
}

human::~human(){
  // std::cout<<"human destructor"<<std::endl;
  //free allocated memory
   delete [] Children;
 
}

//default constructor
human::human(){
  // std::cout<<"human defualt costructor"<<std::endl;

  this->firstName        = "";
  this->lastName         = "";
  this->hairColor        = 0;
  this->eyeColor         = 0;
  this->age              = 0;
  this->gender           = 0;
  this->numberOfChildren = 0;
  
  Children=new human*[numberOfChildren];

 
 
}


//copy constructor
human::human(const human& hu){
  //  std::cout<<" human copy constructor"<<std::endl;
 
  firstName        = hu.firstName;
  lastName         = hu.lastName;
  hairColor        = hu.hairColor;
  eyeColor         = hu.eyeColor;
  age              = hu.age;
  gender           = hu.gender;
  numberOfChildren = hu.numberOfChildren;
 
  //allocating memory for huamn** 
  Children = new human*[numberOfChildren];
  //defining children pointers
   for(int i{} ; i < numberOfChildren ; i++){
     Children[i] = hu.Children[i];
   }
   
   //defining father , mother , spouse pointers
   
   father = hu.father;
   mother = hu.mother;
   spouse = hu.spouse;
 

  
}




human& human::operator=(const human& hu){
  std::cout<<" operator ="<<std::endl;
  if(this == &hu){
    return *this;
  }
  //free allocated memory of human**  
  delete [] Children;
  //re-allocing memory for human **
  Children=new human*[hu.numberOfChildren];

  
  firstName        = hu.firstName;
  lastName         = hu.lastName;
  hairColor        = hu.hairColor;
  eyeColor         = hu.eyeColor;
  age              = hu.age;
  gender           = hu.gender;
  numberOfChildren = hu.numberOfChildren;
  
  //defining childrns poiters
  for(int i{} ; i < numberOfChildren ; i++){
    Children[i] = hu.Children[i];
  }
  // defining father mother and apouse pointer
  father = hu.father;
  mother = hu.mother;
  spouse = hu.spouse;

  return *this;
  
}


//return fistname
std::string human:: getFirstName(){
  return (this->firstName);
}

//return last name
std::string human::getLastName(){
  return (this->lastName);
}

//returm gender
bool human::getGender(){
  return (this->gender);
}

//return hair color
int human::getHairColor(){
  return (this->hairColor);
}

//retun eye color
int human::getEyeColor(){
  return (this->eyeColor);
}

//return age
int human::getAge(){
  return (this->age);
}


//check that input is humans child
bool human::isChileOf(human* child){
 for(int i{};i<numberOfChildren;i++){
   if(child == this->Children[i])
     return true;
   }
 return false;
}

//check that input is humans mother
bool human::isMotherOf(human* mom){
  if(this->mother == mom)
    return true;
  else
    return false;
}

//check that input is humans father
bool human::isFatherOf(human*dad){
  if(this->father == dad)
    return true;
  else
    return false;
}

//print children with their age
void human::printChildren(){
  //arrange children by thier age
  for(int i{} ; i <numberOfChildren-1;i++){
    for(int j{}; j<numberOfChildren-i-1;j++){
      if( (*Children[j]).age > (*Children[j+1]).age)
	std::swap(Children[j],Children[j+1]);
    }
  }
  //print view of children
  for(int i{};i<numberOfChildren;i++){
    
    std::cout<<"firstName: "<<(*Children[i]).firstName<<std::endl; 
    std::cout<<"lastName: "<<(*Children[i]).lastName<<std::endl;        
    std::cout<<"hairColor: "<<(*Children[i]).hairColor<<std::endl;
    std::cout<<"eyeColor: "<<(*Children[i]).eyeColor<<std::endl;
    std::cout<<"age: "<<(*Children[i]).age<<std::endl;
    std::cout<<"gender: "<<(*Children[i]).gender<<std::endl;   
    std::cout<<"numberOfChildren"<<(*Children[i]).numberOfChildren<<std::endl; 
  

  }

}



//increace age of human
void human::operator++(){
  (this->age)++;
}

//increace age of human
void human::operator++(int){
  (this->age)++;
}


// check that 2 human are equal or not
bool human::operator==(human&hu){
  std::cout<<"operator == "<<std::endl;
  bool view = firstName == hu.firstName && lastName == hu.lastName && hairColor == hu.hairColor && eyeColor == hu.eyeColor && age == hu.age && gender == hu.gender && numberOfChildren ==hu.numberOfChildren;
  bool family = (father == hu.father) && (mother == hu.mother) && (spouse == hu.spouse);
  bool child{};
  for(int i{};i<numberOfChildren ; i++){
    if(Children[i] == hu.Children[i])
      child = true;
    else{
      child = false;
      break;
    }
  }
  bool result{view && family && child};

  
  return(result);   

}

//compare age of humans
bool human::operator>(human& hu){
  return (age > hu.age);
}




human* human::operator+(human& hu){
  // std::cout<<"operator +"<<std::endl;
  //check that 2 human was maried
  if((spouse == &hu)&&(this == (hu.spouse))){


    
    // std::cout<<"was maried"<<std::endl;


    std::string newFirstName{"newborn"};
    //by her of his father
    std::string newLastName{""};
    //random 
    int newHairColor{};
    //random
    int newEyeColor{};
    int newAge{};
    //random
    bool newGender{};
    int newNumChild{};
    human v_mom{};
    human v_dad{};
    
    if(this->gender){
      newLastName = hu.lastName;
      v_mom = *this;
      v_dad = hu;
	      
    }
    else{
      newLastName = this->lastName;
      v_mom = hu;
      v_dad = *this;
    }

    int helprand[3]{};
    srand((int)time(0));
    for(int i{}; i < 3 ; i++){
      int r = (rand()%100)+1;
       helprand[i]=r;
    }
    if(helprand[0]%2 == 0)
      newHairColor = v_dad.hairColor;
    else
      newHairColor = v_mom.hairColor;
    
    if(helprand[1]%2 == 0)
      newEyeColor = v_dad.eyeColor;
    else
      newEyeColor = v_mom.eyeColor;
    
    if(helprand[2]%2 == 0)
      newGender = v_dad.gender;
    else
      newGender = v_mom.gender;
    //making new born with view 
    human* newborn{new human(newFirstName,newLastName,newHairColor,newEyeColor,newAge,newGender,newNumChild)};
    
    //allocating memory for saving old children
    human** helpChild{new human*[numberOfChildren]};
    for(int i{};i<numberOfChildren;i++)
      {
	helpChild[i] = Children[i];
      }
    //free allocated memory for mother and father
    delete[] this->Children;
    delete[] hu.Children;
    //increase father and mother s number of children
    (this->numberOfChildren)++;
    (hu.numberOfChildren)++;

   
    //re-allocating for human** by new number of children
    this->Children = new human*[numberOfChildren];
    hu.Children = new human*[numberOfChildren];
   
   

    //seting mother and fathe of new born
    if(this->gender){
      newborn->mother = this;
      newborn->father = &hu;
      
    }
    else{
      newborn->father = this;
      newborn->mother = &hu;
     
    }

    //copying old children
    for(int i{};i<numberOfChildren-1;i++)
      {
	(this->Children[i]) = helpChild[i] ;
	(hu.Children[i]) = helpChild[i] ;
	
      }
    
    //adding neww born at the end of mother and father human**
    (this->Children[numberOfChildren-1]) = newborn ;
    (hu.Children[numberOfChildren-1]) = newborn;
   
 
    //free allocated memory that saved old children
    delete[] helpChild;
  
    return (newborn);
  }
  //if 2 human wasnt maried
  else{
    std::cout<<"wasnt maried"<<std::endl;
    return nullptr;
  }}



std::string human::getwife(){
  return spouse->getFirstName();
}

//return spouse of human
human* human::getspouse(human&){
  return spouse;
}

//set 2 humans as eachothrs spouse
void human::setspouse(human& p1){
  
  spouse = &p1;
  (p1.spouse) = this;
}
  

//check that can 2 human marry
bool human::canMarry(human* p){
  if(getGender() == p->getGender()){
    std::cout<<" same gender ! -__- "<<std::endl;
    return false;
  }
  else if(spouse == 0 && p->spouse==0 )
    return true;
  else{
    std::cout<<"one of them has spouse"<<std::endl;
    return false;
  }
}


//set name of human
void human::setFirstName(std::string name){
  this->firstName = name;
}

//find big father
//i havant enough time to code oracle class
//this function will be used in oracle class to find family
human* human::bigfather()
{
  human*temp = this;
  while(temp->father != 0)
    temp = temp->father;
  return temp;
}
