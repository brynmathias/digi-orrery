#include "ThreeVec.hh"

ThreeVec::ThreeVec(double x, double y, double z):
x(x),
y(y),
z(z)
{;}

ThreeVec::ThreeVec():
x(0.),y(0.),z(0.){}


//-------------ThreeVec Implmentation-------//
void ThreeVec::operator+ (ThreeVec vec) {
  this->x += (vec.x);
  this->y += (vec.y);
  this->z += (vec.z);
}

void ThreeVec::operator- (ThreeVec vec) {
  this->x -= (vec.x);
  this->y -= (vec.y);
  this->z -= (vec.z);
}

void ThreeVec::operator+= (ThreeVec vec){
  this->x += (vec.x);
  this->y += (vec.y);
  this->z += (vec.z);
}

void ThreeVec::operator= (ThreeVec vec){
  this->x = (vec.x);
  this->y = (vec.y);
  this->z = (vec.z);
}

void ThreeVec::operator* (double val){
  this->x *= val;
  this->y *= val;
  this->z *= val;
}


//-----------------------------------------//

