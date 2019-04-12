#ifndef HUMAN_H
#define HUMAN_H
#include <string>
class human
{
public:
  static inline int count{};
  human(std::string firstName , std::string lastName , int hairColor , int eyeColor , int age ,bool gender , int numberOfChildren);
  human();
  human(const human&);
  ~human();
  human& operator=(const human&);
  
  std::string getFirstName();
  std::string getLastName();
  bool getGender();
  int getHairColor();
  int getEyeColor();
  int getAge();
 
  bool operator>(human&);
  bool operator==(human&);
  bool canMarry(human*);
    
 
  human* operator+(human&);
  human* getspouse(human&);
  void setspouse(human&);
  human* bigfather();

  void operator++();
  void operator++(int);
 
 std::string getwife();
 
 void setFirstName(std::string);
 bool isChileOf(human*);
 bool isFatherOf(human*);
 bool isMotherOf(human*);
 void printChildren();
 friend class Oracle;
int m;
private:
  human* father;
  human* mother;
  human* spouse;
  human** Children;
  std::string firstName;
  std::string lastName;
  int hairColor;
  int eyeColor;
  int age;
  bool gender;
  int numberOfChildren;
  
  
 
 
};
#endif
