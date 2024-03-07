#include<iostream>
#include "detector.h"

// Accessor that prints how many particles passed through this detector
void detector::print_detected_results() const
{
  std::cout<<"Number of particles passed through "<<type<<": "<<particles_count<<std::endl;
}