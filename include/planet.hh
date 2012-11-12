#ifndef planet_hh
#define planet_hh
#include <math.h>
struct x_y_z_point{
  double x_;
  double y_;
  double z_;
  };



static const double G = 1.; // Put in vale for newtons gravitational constant.


// Currently assuming circular orbits, needs to be updated, although if we work in X,Y,Z then we get around this problem, translating this later on might be a good idea.

class object // celestial object, base class from which objects with sable orbits and non stable orbits will inherit. All objects have some mass and some position + the ability to have some relitive position. 
{
public:
  object (double mass, x_y_z_point initialPos);
  virtual ~object (){;}
  double DistanceTo(object* o);
  double ForceFrom(object* o);
  x_y_z_point GetInitialPosition();
private:

  x_y_z_point initalPos_;
public:
  x_y_z_point current_pos_;
  double mass_;
  /* data */
};

x_y_z_point object::GetInitialPosition(){
  return initalPos_;
}

double object::DistanceTo(object* o){
  double dx = fabs(this->current_pos_.x_ - o->current_pos_.x_);
  double dy = fabs(this->current_pos_.y_ - o->current_pos_.y_);
  double dz = fabs(this->current_pos_.z_ - o->current_pos_.z_);  
  return sqrt(dx*dx + dy*dy + dz*dz);
}

double object::ForceFrom(object* o){
  double r = object::DistanceTo(o);
  double Mm = this->mass_ * o->mass_; // no approximation of orbits around a central point, this might make things far far far too hard.
  if(r*r > 0.) return G*Mm/(r*r);
  else return 0;
}


object::object(double mass, x_y_z_point initialPos):
  initalPos_(initialPos),
  mass_(mass)
    
  {current_pos_=initialPos;}


// class planet_t : public object
// {
// public:
//   planet_t ();
//   virtual ~planet_t (){;}
//   double mass();
// private:
//   double mass_;
// };
// 
// double planet_t::mass(){
//   return mass_;
// }

#endif // planet_hh
