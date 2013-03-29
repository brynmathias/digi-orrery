#ifndef ThreeVec_hh
#define ThreeVec_hh

class ThreeVec
{
public:
  ThreeVec(double x, double y, double z);
  ThreeVec();
  ~ThreeVec (){;}
  void operator+(ThreeVec);
  void operator-(ThreeVec);
  void operator+=(ThreeVec);
  void operator=(ThreeVec);
  void operator*(double);
  double x;
  double y;
  double z;

};

#endif // ThreeVec_hh
