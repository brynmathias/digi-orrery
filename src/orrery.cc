#include <iostream>
#include "planet.hh"
int main (int argc, char const *argv[])
{
  object sun(1000000.,x_y_z_point{0.,0.,0.});
  object earth(1000.,x_y_z_point{10.,10.,0.});
  object moon(10.,x_y_z_point{10.1,10.1,0.});
  std::cout << "Force between earth and sun  = " << 
     sun.ForceFrom(&earth) << " Force between Earth and moon " <<
     earth.ForceFrom(&moon) << " Force between moon and sun " << 
     sun.ForceFrom(&sun) << " difference = " << fabs(moon.ForceFrom(&sun) - 
       moon.ForceFrom(&earth)) << std::endl;
  return 0;
}