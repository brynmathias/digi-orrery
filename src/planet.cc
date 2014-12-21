#include "planet.hh"
#include <string>
#include <iostream>
#include <vector>
#include "ThreeVec.hh"

object::object(double mass, ThreeVec initialPos,
                ThreeVec initialConditions, std::string name):
  mass_(mass),
  name_(name),
  initalPos_(initialPos),
  initialConds_(initialConditions)
  {
   current_pos_ = initialPos;
   current_vel_ = initialConds_;
  }

ThreeVec object::GetInitialPosition(){
  return initalPos_;
}

double object::DistanceTo(object* o){
  double dx = fabs(this->current_pos_.x - o->current_pos_.x);
  double dy = fabs(this->current_pos_.y - o->current_pos_.y);
  double dz = fabs(this->current_pos_.z - o->current_pos_.z);
  return sqrt(dx*dx + dy*dy + dz*dz);
}

double object::ForceFrom(object* o){
  double r = object::DistanceTo(o);
  double Mm = this->mass_ * o->mass_; // no approximation of orbits around a central point, this might make things far far far too hard.
  if(r*r > 0.) return -G*Mm/(r*r);
  else return 0.;
}

ThreeVec object::resultantAcceletation(std::vector<object*> otherBodies){
  double F = 0.;
  double aTot = 0.;
  double r = 0.;
  double dx = 0.;
  double dy = 0.;
  double dz = 0.;
  ThreeVec accn{0.,0.,0.};
  for( auto &obj : otherBodies){
    F = object::ForceFrom(obj);
    r = object::DistanceTo(obj);
    dx = this->current_pos_.x - obj->current_pos_.x;
    dy = this->current_pos_.y - obj->current_pos_.y;
    dz = this->current_pos_.z - obj->current_pos_.z;
    aTot = F/this->mass_;
    if( r > 0.){
        ThreeVec thisAccn{dx/r* aTot, dy/r * aTot, dz/r *aTot};
        accn += thisAccn;
    }
  }
  return accn;

}

std::string object::GetName(){
  return name_;
}

