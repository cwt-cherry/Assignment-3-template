// PHYS 30762 Programming in C++
// Assignment 3
// Practice with C++ classes and their interactions

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
  double velocity; // Between 0 and c, in m/s
  const double speed_of_light = 2.9979245e8; // Unit of m/s
  double beta; // Between 0-1

public:
  // Destruct Constructor
  particle(): name{}, rest_mass{}, charge{}, velocity{}, beta{}
  {
  }

  // Parameterised Constructor
  particle(string particle_name, double particle_rest_mass, int particle_charge, double particle_velocity):
    name{particle_name}, rest_mass{particle_rest_mass}, charge{particle_charge}, velocity{particle_velocity}, beta{}
  {
    beta = velocity / speed_of_light;
  }

  // Destructor
  ~particle()
  {
    std::cout<<"Destroying "<<name<<std::endl;
  }

  // Getter functions
  string get_name()
  {
    return name;
  }
  double get_rest_mass()
  {
    return rest_mass;
  }
  int get_charge()
  {
    return charge;
  }
  double get_velocity()
  {
    return velocity;
  }
  double get_beta()
  {
    return beta;
  }

  // Setter functions
  void set_velocity(double particle_velocity)
  {
    if (speed_of_light >= particle_velocity >= 0)
    {
      velocity = particle_velocity;
    }
    else
    {
      std::cerr << "Invalid velocity. Velocity should be between 0 and the speed of light." << std::endl;
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
  }

};
// End of particle class and associated member functions

// Beginning of detector class
class detector
{
private:
  string type;
  bool status;
  int particles_count;

public:
  // Destruct Constructor
  detector(): type{}, status{}
  {
  }

  // Parameterised Constructor
  detector(string chosen_type, bool chosen_status):
    type{chosen_type}, status{chosen_status}
  {
  }

  // Destructor
  ~detector()
  {
    std::cout<<"Destroying "<<type<<std::endl;
  }

  // Setter
  void turn_on()
  {
    status = true;
  }
  void turn_off()
  {
    status = false;
  }

  // Ask user to enter detector status
  bool set_status(string type)
  {
    string chosen_status;
    while(true)
    {
      std::cout<<"Enter status of "<<type<<":"<<std::endl;
      std::cin >> chosen_status;
      if (chosen_status == "on")
      {
        turn_on();
        return true;
      }
      else if (chosen_status == "off")
      {
        turn_off();
        return false;
      }
      else
      {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Invalid input. Please enter choice again." << std::endl;
      }
    }
  }

  // Getter
  bool get_status()
  {
    return status;
  }

  // Function to detect particles
  bool detect_particles(particle detected_particle)
  {
    if(status)
    {
      if(type=="tracker"&&(detected_particle.get_name()=="electron"||detected_particle.get_name()=="antielectron"||detected_particle.get_name()=="muon"||detected_particle.get_name()=="antimuon"))
      {
        std::cout<<detected_particle.get_name()<<" was detected."<<std::endl;
        particles_count++;
        return true;
      }
      else if(type=="calorimeter"&&(detected_particle.get_name()=="electron"||detected_particle.get_name()=="antielectron"))
      {
        std::cout<<detected_particle.get_name()<<" was detected."<<std::endl;
        particles_count++;
        return true;
      }
      else if(type=="muon_chamber"&&(detected_particle.get_name()=="muon"||detected_particle.get_name()=="antimuon"))
      {
        std::cout<<detected_particle.get_name()<<" was detected."<<std::endl;
        particles_count++;
        return true;
      }
      return false;
    }
    else
    {
      std::cout<<"No particles were detected."<<std::endl;
      return false;
    }
  }

// Accessor that prints how many particles passed through this detector
  void print_detected_results()
  {
    std::cout<<"Number of particles passed through "<<type<<": "<<particles_count<<std::endl;
  }
};
// End of detector class

// Main program
int main()
{
  // Create the following particles: 
  // two electrons, four muons, three taus, one antielectron, one antimuon, one antitau use the parameterised constructor
  particle electron1("electron", 0.511, -1, 2e8);
  particle electron2("electron", 0.511, -1, 2.5e8);
  particle muon1("muon", 105.7, -1, 2e8);
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
  particles.push_back(electron1);
  particles.push_back(electron2);
  particles.push_back(muon1);
  particles.push_back(muon2);
  particles.push_back(muon3);
  particles.push_back(muon4);
  particles.push_back(tau1);
  particles.push_back(tau2);
  particles.push_back(tau3);
  particles.push_back(antielectron);
  particles.push_back(antimuon);
  particles.push_back(antitau);

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