#ifndef FourVec_hh
#define FourVec_hh

class FourVec
{
public:
  FourVec (double p, double x, double y, double z);
  ~FourVec(){;}
  void operator+(FourVec);
  double p;
  double x;
  double y;
  double z;

};


FourVec a = FourVec(0.,0.,0.,0.);

#endif // FourVec_hh
