#ifndef planet_hh
#define planet_hh
#include <math.h>
#include "functions.hh"
#include "FourVec.hh"
#include "ThreeVec.hh"
#include <string>
#include <vector>
static const double G = 6.667*pow(10,-11); // Put in vale for newtons gravitational constant.


// Currently assuming circular orbits, needs to be updated, although if we work in X,Y,Z then we get around this problem, translating this later on might be a good idea.

class object // celestial object, base class from which objects with sable orbits and non stable orbits will inherit. All objects have some mass and some position + the ability to have some relitive position. 
{
public:
  object (double mass, ThreeVec initialPos, ThreeVec initialConditions, std::string name);
  // ~object (){;}
  double DistanceTo(object* o);
  double ForceFrom(object* o);
  ThreeVec GetInitialPosition();
  std::string GetName();
  ThreeVec resultantAcceletation(std::vector<object*> otherBodies);
  ThreeVec current_pos_;
  double mass_;
  ThreeVec current_vel_;
  /* data */
  std::string name_;

private:
  ThreeVec initalPos_;
  ThreeVec initialConds_; //vx, vy, vz
};


#endif // planet_hh
