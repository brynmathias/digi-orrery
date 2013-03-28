#include "FourVec.hh"

//-----------FourVec Implimentation--------//

FourVec::FourVec(double p , double x, double y, double z)
  {;}

void FourVec::operator+ (FourVec vec) {
  this->x += (vec.x);
  this->y += (vec.y);
  this->z += (vec.z);
}

// FourVec::~FourVec(){;}

//-----------------------------------------//