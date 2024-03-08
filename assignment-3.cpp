// PHYS 30762 Programming in C++
// Assignment 3
// Practice with C++ classes and their interactions

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<ctime>

#include "particle.h"
#include "detector.h"

using std::string;

// Define variable
const double speed_of_light = 2.9979245e8; // Unit of m/s

// Random velocity generating function
double random_velocity() 
{
  return static_cast<double>(std::rand()) / RAND_MAX * speed_of_light;
}

// Main program
int main()
{
  // Create the following particles: 
  // two electrons, four muons, three taus, one positron, one antimuon, one antitau use parameterised constructor
  particle electron1("electron", 0.511, -1, random_velocity(), false);
  particle electron2("electron", 0.511, -1, random_velocity(), false);
  particle electron3("positron", 0.511, 1, random_velocity(), true);
  particle muon1("muon", 105.7, -1, random_velocity(), false);
  particle muon2("muon", 105.7, -1, random_velocity(), false);
  particle muon3("muon", 105.7, -1, random_velocity(), false);
  particle muon4("muon", 105.7, -1, random_velocity(), false);
  particle muon5("antimuon", 105.7, 1, random_velocity(), true);

  // Create a vector to store particles
  std::vector<particle> particles;

  // Add particles to the vector
  particles.push_back(electron1);
  particles.push_back(electron2);
  particles.push_back(electron3);
  particles.push_back(muon1);
  particles.push_back(muon2);
  particles.push_back(muon3);
  particles.push_back(muon4);
  particles.push_back(muon5);

  // Print out the data from all the particles (put them in a vector)
  for(particle &each_particle: particles)
  {
    each_particle.print_data();
  }

  // Create the following detectors: a tracker, a calorimeter, a muon chamber
  detector tracker("tracker", tracker.set_status("tracker"));
  detector calorimeter("calorimeter", calorimeter.set_status("calorimeter"));
  detector muon_chamber("muon_chamber", muon_chamber.set_status("muon_chamber"));
  
  // Pass the list of particles into each detector
  for(particle &each_particle: particles)
  {
    tracker.detect_particles(each_particle);
    tracker.detect_particle_type(each_particle);
    calorimeter.detect_particles(each_particle);
    calorimeter.detect_particle_type(each_particle);
    muon_chamber.detect_particles(each_particle);
    muon_chamber.detect_particle_type(each_particle);
  }

  // Print a summary of how many particles were detected
  tracker.print_detected_results();
  calorimeter.print_detected_results();
  muon_chamber.print_detected_results();

  return 0;
}