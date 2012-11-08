#include <iostream>
#include "planet.hh"
int main (int argc, char const *argv[])
{
  // object sel_obj(10.,true);
  // std::cout << "sel_obj mass = " << sel_obj.mass() << " sel_obj has stable" <<
  planet_t plan(1000.);
  
  
    // sel_obj.stable_orbit() << std::endl;
  std::cout << "Hello world, the mass of the planet is "<< plan.mass()  << std::endl;
  return 0;
}