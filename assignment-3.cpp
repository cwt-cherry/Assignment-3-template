// PHYS 30762 Programming in C++
// Assignment 3
// Practice with C++ classes and their interactions

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "particle.h"
#include "detector.h"

using std::string;

// Main program
int main()
{
  // Create the following particles: 
  // two electrons, four muons, three taus, one antielectron, one antimuon, one antitau use the parameterised constructor
  particle electron1("electron", 0.511, -1, 2e8);
  particle electron2("electron", 0.511, -1, 2.5e8);
  particle muon1("muon", 105.7, -1, 2.3e8);
  particle muon2("muon", 105.7, -1, 2e8);
  particle muon3("muon", 105.7, -1, 2e8);
  particle muon4("muon", 105.7, -1, 2e8);
  particle tau1("tau", 1777, -1, 2e8);
  particle tau2("tau", 1777, -1, 2e8);
  particle tau3("tau", 1777, -1, 2e8);
  particle antielectron("antielectron", 0.511, 1, 2e8);
  particle antimuon("antimuon", 105.7, 1, 2e8);
  particle antitau("antitau", 1777, 1, 2e8);

  // Create a vector to store particles
  std::vector<particle> particles;

  // Add particles to the vector
  particles.emplace_back(electron1);
  particles.emplace_back(electron2);
  particles.emplace_back(muon1);
  particles.emplace_back(muon2);
  particles.emplace_back(muon3);
  particles.emplace_back(muon4);
  particles.emplace_back(tau1);
  particles.emplace_back(tau2);
  particles.emplace_back(tau3);
  particles.emplace_back(antielectron);
  particles.emplace_back(antimuon);
  particles.emplace_back(antitau);

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