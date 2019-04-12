#ifndef Oracle_H
#define Oracle_H
#include <string>
#include <iostream>
#include "human.h"
class Oracle
{
public:
  Oracle(std::string Name );
  bool marry(human*,human*);
  // bool isFamily(human*,human*);
   void setChild(human*,human*,human*);
  // human** getFamily(human*);
  // int getPopulationOfFamily(human*);
private:
  std::string Name;
 
  
  
 
 
};
#endif
