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
  object sun(1.989E27,ThreeVec{0.,0.,0.},ThreeVec{0.,0.,0.},"sun");
  object earth(5.972E21,ThreeVec{149600000.,0.,0.},ThreeVec{0.,600.,0.},"earth");
  object moon(10.,ThreeVec{149597871.,0.,0.},ThreeVec{0.,30.,0.},"moon");
  /* std::cout << "Force between earth and sun  = " << */
  /*    sun.ForceFrom(&earth) << " Force between Earth and moon " << */
  /*    earth.ForceFrom(&moon) << " Force between moon and sun " << */
  /*    sun.ForceFrom(&sun) << " difference = " << fabs(moon.ForceFrom(&sun) - */
  /*    moon.ForceFrom(&earth)) << std::endl; */
  std::vector<object*> objs{&sun,&earth,&moon};
  ThreeVec Accn;

  // void evolve(std::vector<object*> objV, double t ){}
  for(unsigned i = 0; i < 2500; i++){
    double dt = 10.;
    evolve(objs, dt );
    for(auto planet1 : objs){
      Accn = planet1->resultantAcceletation(objs);
      /* std::cout << "accn: " << Accn.x << " " << Accn.y << std::endl; */
      /* std::cout << "force on earth from sun is " << earth.ForceFrom(&sun) << std::endl; */
      std::cout << planet1->name_ << ","<< i << ", "
        << planet1->current_pos_ << ", "
        << sqrt(planet1->current_pos_.x*planet1->current_pos_.x+planet1->current_pos_.y*planet1->current_pos_.y+planet1->current_pos_.z*planet1->current_pos_.z) << ", "
        << planet1->current_vel_ <<
        std::endl;
    }
  }


  return 0;
}
