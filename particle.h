#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using std::string;

// Beginning of particle class
class particle
{
private:
  string name; // electron or muon
  double rest_mass; // Unit of MeV
  int charge; // -1 or +1
  const double speed_of_light = 2.9979245e8; // Unit of m/s
  double velocity; // Between 0 and c, in m/s
  double beta; // Between 0-1

public:
  // Default Constructor
  particle(): name{}, rest_mass{}, charge{}, velocity{}, beta{}
  {
  }

  // Parameterised Constructor
  particle(string particle_name, double particle_rest_mass, int particle_charge, double particle_velocity):
    name{particle_name}, rest_mass{particle_rest_mass}, charge{particle_charge}, velocity{particle_velocity}, beta{}
  {
    set_velocity(particle_velocity);
    beta = velocity / speed_of_light;
  }

  // Destructor
  ~particle()
  {
    std::cout<<"Destroying "<<name<<std::endl;
  }

  // Getter functions
  string get_name() {return name;}

//   double get_rest_mass()
//   {
//     return rest_mass;
//   }
//   int get_charge()
//   {
//     return charge;
//   }
//   double get_beta()
//   {
//     return beta;
//   }

  // Setter functions
  double set_velocity(double particle_velocity)
  {
    if (speed_of_light >= particle_velocity && particle_velocity >= 0)
    {
      return velocity = particle_velocity;
    }
    else
    {
      std::cout<<"Invalid velocity. Velocity should be between 0 and the speed of light."<<std::endl;
      exit(0);
    }
  }
  // Function to print info about a particle
  void print_data()
  {
    std::cout<<"particle type: "<<name<<std::endl;
    std::cout<<"rest mass: "<<rest_mass<<std::endl;
    std::cout<<"charge: "<<charge<<std::endl;
    std::cout<<"velocity: "<<velocity<<std::endl;
    std::cout<<"beta value: "<<beta<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
  }

};
// End of particle class and associated member functions

#endif