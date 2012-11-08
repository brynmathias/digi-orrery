#ifndef planet_hh
#define planet_hh


class planet_t
{
public:
  planet_t (double val);
  virtual ~planet_t (){;}
  double mass();
private:
  /* data */
  double mass_;
};

planet_t::planet_t(double val):
  mass_(val)
  {;}
double planet_t::mass(){
  return mass_;
}

#endif // planet_hh
