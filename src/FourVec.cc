#include "FourVec.hh"

//-----------FourVec Implimentation--------//

void FourVec::operator+ (FourVec vec) {
  this->x += (vec.x);
  this->y += (vec.y);
  this->z += (vec.z);
}

// FourVec::~FourVec(){;}

//-----------------------------------------//