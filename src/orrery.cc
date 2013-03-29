#include <iostream>
#include "planet.hh"
#include "functions.hh"
#include "ThreeVec.hh"
// #include "FourVec.hh"


int main ()
{
  object sun(1000000.,ThreeVec{0.,0.,0.},ThreeVec{0.,0.,0.},"sun");
  object earth(100000.,ThreeVec{10.,10.,0.},ThreeVec{0.,0.,0.},"earth");
  object moon(10.,ThreeVec{10.1,10.1,0.},ThreeVec{0.,0.,0.},"moon");
  std::cout << "Force between earth and sun  = " << 
     sun.ForceFrom(&earth) << " Force between Earth and moon " <<
     earth.ForceFrom(&moon) << " Force between moon and sun " << 
     sun.ForceFrom(&sun) << " difference = " << fabs(moon.ForceFrom(&sun) - 
     moon.ForceFrom(&earth)) << std::endl;
  std::vector<object> objs{sun,earth,moon};
  ThreeVec Accn;
  for(auto planet1 : objs){
  Accn = planet1.resultantAcceletation(objs);
  std::cout << "The resultant acceleration on The " << planet1.name_ << " is " << Accn.x << " " << Accn.y << " " << Accn.z << std::endl;
  }

  return 0;
}
