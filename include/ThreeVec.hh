#ifndef ThreeVec_hh
#define ThreeVec_hh

class ThreeVec
{
public:
  ThreeVec(double x, double y, double z);
  ~ThreeVec (){;}
  void operator+(ThreeVec);
  void operator-(ThreeVec);
  double x;
  double y;
  double z;
private:
  double x_;
  double y_;
  double z_;
};

#endif // ThreeVec_hh
