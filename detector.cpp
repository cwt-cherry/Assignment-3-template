#include<iostream>
#include "detector.h"

// Accessor that prints how many particles passed through this detector
void detector::print_detected_results() const
{
  std::cout<<"Number of particles passed through "<<type<<": "<<particles_count<<std::endl;
  if(status)
  {
    if(type=="tracker")
    {
      std::cout<<"Number of electrons passed through "<<type<<": "<<electrons_count<<std::endl;
      std::cout<<"Number of positrons passed through "<<type<<": "<<positrons_count<<std::endl;
      std::cout<<"Number of muons passed through "<<type<<": "<<muons_count<<std::endl;
      std::cout<<"Number of antimuons passed through "<<type<<": "<<antimuons_count<<std::endl;
      std::cout<<"----------------------------------------------------------------"<<std::endl;
    }
    else if(type=="calorimeter")
    {
      std::cout<<"Number of electrons passed through "<<type<<": "<<electrons_count<<std::endl;
      std::cout<<"Number of positrons passed through "<<type<<": "<<positrons_count<<std::endl;
      std::cout<<"----------------------------------------------------------------"<<std::endl;
    }
    else if(type=="muon_chamber")
    {
      std::cout<<"Number of muons passed through "<<type<<": "<<muons_count<<std::endl;
      std::cout<<"Number of antimuons passed through "<<type<<": "<<antimuons_count<<std::endl;
      std::cout<<"----------------------------------------------------------------"<<std::endl;
    }
  }
}