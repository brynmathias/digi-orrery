#ifndef planet_hh
#define planet_hh
#include <math.h>
#include "functions.hh"
#include "FourVec.hh"
#include "ThreeVec.hh"
static const double G = 1.; // Put in vale for newtons gravitational constant.


// Currently assuming circular orbits, needs to be updated, although if we work in X,Y,Z then we get around this problem, translating this later on might be a good idea.

class object // celestial object, base class from which objects with sable orbits and non stable orbits will inherit. All objects have some mass and some position + the ability to have some relitive position. 
{
public:
  object (double mass, x_y_z_point initialPos, ThreeVec initialConditions);
  ~object (){;}
  double DistanceTo(object* o);
  double ForceFrom(object* o);
  x_y_z_point GetInitialPosition();
  x_y_z_point current_pos_;
  double mass_;
  /* data */
private:
  ThreeVec initialConds_;
  x_y_z_point initalPos_;

};


#endif // planet_hh
