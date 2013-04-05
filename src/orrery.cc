#include <iostream>
#include "planet.hh"
#include "functions.hh"
#include "ThreeVec.hh"
// #include "FourVec.hh"

void evolve(std::vector<object*> objV, double t ){
  for(auto obj : objV){
    auto v = obj->resultantAcceletation(objV); 
    v*=t;
    obj->current_vel_ += v;
  }
  
  for(auto &obj : objV){
    auto dV = obj->current_vel_;
    dV*=t;
    obj->current_pos_ += dV;
  }
  
  
}



int main ()
{
  object sun(100000000.,ThreeVec{0.,0.,0.},ThreeVec{0.,0.,0.},"sun");
  object earth(1000.,ThreeVec{10.,10.,1.},ThreeVec{0.,0.,0.},"earth");
  object moon(10.,ThreeVec{10.1,10.1,1.},ThreeVec{0.,0.,0.},"moon");
  std::cout << "Force between earth and sun  = " << 
     sun.ForceFrom(&earth) << " Force between Earth and moon " <<
     earth.ForceFrom(&moon) << " Force between moon and sun " << 
     sun.ForceFrom(&sun) << " difference = " << fabs(moon.ForceFrom(&sun) - 
     moon.ForceFrom(&earth)) << std::endl;
  std::vector<object*> objs{&sun,&earth,&moon};
  ThreeVec Accn;
  
  // void evolve(std::vector<object*> objV, double t ){}
  for(unsigned i = 0; i < 1000; i++){
    double dt = 10.;
    evolve(objs, dt );
    for(auto planet1 : objs){
      Accn = planet1->resultantAcceletation(objs);
      std::cout << "The current position of The " << planet1->name_ << " is " 
        << planet1->current_pos_.x << " " << planet1->current_pos_.y << " " 
        << planet1->current_pos_.z << std::endl;
    }
  }


  return 0;
}
