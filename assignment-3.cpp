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

// Main program
int main()
{
  // Create a vector to store particles
  std::vector<particle> particles;

  // Create the following particles: 
  // two electrons, four muons, three taus, one antielectron, one antimuon, one antitau use parameterised constructor
  
  // Add electrons
  for(int electrons_number = 0; electrons_number < 2; ++electrons_number)
  {
    double randomVelocity = static_cast<double>(std::rand()) / RAND_MAX * 3e8;
    particle electron;
    electron.set_name("electron");
    electron.set_rest_mass(0.511);
    electron.set_charge(1);
    electron.set_velocity(randomVelocity);
    electron.set_beta(randomVelocity);
    particles.push_back(electron);
  }

  // Add muons
  for(int muons_number = 0; muons_number < 4; ++muons_number)
  {
    double randomVelocity = static_cast<double>(std::rand()) / RAND_MAX * 3e8;
    particle muon;
    muon.set_name("muon");
    muon.set_rest_mass(105.7);
    muon.set_charge(1);
    muon.set_velocity(randomVelocity);
    muon.set_beta(randomVelocity);
    particles.push_back(muon);
  }

  // Add antielectron
  double randomVelocity = static_cast<double>(std::rand()) / RAND_MAX * 3e8;
  particle antielectron;
  antielectron.set_name("antielectron");
  antielectron.set_rest_mass(0.511);
  antielectron.set_charge(-1);
  antielectron.set_velocity(randomVelocity);
  antielectron.set_beta(randomVelocity);
  particles.push_back(antielectron);

  // Add antimuon
  randomVelocity = static_cast<double>(std::rand()) / RAND_MAX * 3e8;
  particle antimuon;
  antimuon.set_name("antimuon");
  antimuon.set_rest_mass(105.7);
  antimuon.set_charge(-1);
  antimuon.set_velocity(randomVelocity);
  antimuon.set_beta(randomVelocity);
  particles.push_back(antimuon);

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
    calorimeter.detect_particles(each_particle);
    muon_chamber.detect_particles(each_particle);
  }

  // Print a summary of how many particles were detected
  tracker.print_detected_results();
  calorimeter.print_detected_results();
  muon_chamber.print_detected_results();

  return 0;
}