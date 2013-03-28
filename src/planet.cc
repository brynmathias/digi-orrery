#include "planet.hh"

object::object(double mass, x_y_z_point initialPos, ThreeVec initialConditions):
  initialConds_(initialConditions),
  initalPos_(initialPos),
  mass_(mass)
  {current_pos_=initialPos;}

x_y_z_point object::GetInitialPosition(){
  return initalPos_;
}

double object::DistanceTo(object* o){
  double dx = fabs(this->current_pos_.x_ - o->current_pos_.x_);
  double dy = fabs(this->current_pos_.y_ - o->current_pos_.y_);
  double dz = fabs(this->current_pos_.z_ - o->current_pos_.z_);  
  return sqrt(dx*dx + dy*dy + dz*dz);
}

double object::ForceFrom(object* o){
  double r = object::DistanceTo(o);
  double Mm = this->mass_ * o->mass_; // no approximation of orbits around a central point, this might make things far far far too hard.
  if(r*r > 0.) return G*Mm/(r*r);
  else return 0.;
}




