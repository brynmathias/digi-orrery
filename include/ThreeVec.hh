#ifndef ThreeVec_hh
#define ThreeVec_hh
#include <iostream>
class ThreeVec
{
public:
  ThreeVec(double x, double y, double z);
  ThreeVec();
  // ~ThreeVec (){;}
  void operator+(ThreeVec);
  void operator-(ThreeVec);
  void operator+=(ThreeVec);
  void operator-=(ThreeVec);
  void operator=(ThreeVec);
  void operator*=(double);
  friend std::ostream& operator<<(std::ostream&,const ThreeVec&);
  double x;
  double y;
  double z;

};

#endif // ThreeVec_hh
