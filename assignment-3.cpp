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

  // Getter functions (accessors) to 
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
  // This should include function returning beta value 
  double get_beta()
  {
    return beta;
  }

  // Setter functions, to change value of data members
  // Make sure you check input validity before changing something
  // Hint: you can use the input checking functions you used in assignment 1
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

  // void set_beta(double velocity, const double speed_of_light)
  // {
  //   beta = velocity / speed_of_light;
  // }

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

// Implementation of print_data function goes here


// End of particle class and associated member functions

// Beginning of detector class
class detector
{
private:
  // string tracker;
  // string calorimeter;
  // string muon_chamber;
  string type;
  bool status;
  int particles_count;

public:
  // Destruct Constructor
  detector(): type{}, status{}// tracker{}, calorimeter{}, muon_chamber{}
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
      }
      else if (chosen_status == "off")
      {
        turn_off();
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
// Functionalities needed, in addition to constructor/destructor/setters/getters (see slides on BB):
//particle detected_particle;
// - write a function that takes a particle and returns a bool and a print-out on whether this type of detector detected the particle
//   depending on the detector/particle combination (see slides on BB)
// - have data members that keep track of how many particles were detected by this particular detector, 
//   and of which type
  bool detect_particles(particle detected_particle)
  {
    if(status)
    {
      if(detected_particle.get_name()=="electron"||detected_particle.get_name()=="antielectron"||detected_particle.get_name()=="muon"||detected_particle.get_name()=="antimuon"&&type=="tracker")
      {
        std::cout<<detected_particle.get_name()<<" was detected."<<std::endl;
        particles_count++;
        return true;
      }
      else if(detected_particle.get_name()=="electron"||detected_particle.get_name()=="antielectron"&&type=="calorimeter")
      {
        std::cout<<detected_particle.get_name()<<" was detected."<<std::endl;
        particles_count++;
        return true;
      }
      else if(detected_particle.get_name()=="muon"||detected_particle.get_name()=="antimuon"&&type=="muon_chamber")
      {
        std::cout<<detected_particle.get_name()<<" was detected."<<std::endl;
        particles_count++;
        return true;
      }
    }
    else
    {
      std::cout<<"No particles were detected."<<std::endl;
      return false;
    }
  }

// - write a function (accessor) that prints how many particles passed through this detector
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
  // two electrons, four muons, three taus, one antielectron, one antimuon, one antitau 
  // Use the parameterised constructor
  particle electron("electron", 0.511, -1, 2e8);
  particle electron("electron", 0.511, -1, 2.5e8);
  particle muon("muon", 105.7, -1, 2e8);
  particle muon("muon", 105.7, -1, 2e8);
  particle muon("muon", 105.7, -1, 2e8);
  particle muon("muon", 105.7, -1, 2e8);
  particle tau("tau", 1777, -1, 2e8);
  particle tau("tau", 1777, -1, 2e8);
  particle tau("tau", 1777, -1, 2e8);
  particle antielectron("antielectron", 0.511, 1, 2e8);
  particle antimuon("antimuon", 105.7, 1, 2e8);
  particle antitau("antitau", 1777, 1, 2e8);

  // Create a vector to store particles
  std::vector<particle> particles;

  // Add particles to the vector
  particles.push_back(particle("electron", 0.511, -1, 2e8));
  particles.push_back(particle("electron", 0.511, -1, 2.5e8));
  particles.push_back(particle("muon", 105.7, -1, 2.3e8));
  particles.push_back(particle("muon", 105.7, -1, 2.1e8));
  particles.push_back(particle("muon", 105.7, -1, 2.4e8));
  particles.push_back(particle("muon", 105.7, -1, 2.6e8));
  particles.push_back(particle("tau", 1777, -1, 2.7e8));
  particles.push_back(particle("tau", 1777, -1, 1.2e8));
  particles.push_back(particle("tau", 1777, -1, 1.1e8));
  particles.push_back(particle("antielectron", 0.511, 1, 1e8));
  particles.push_back(particle("antimuon", 105.7, 1, 1.3e8));
  particles.push_back(particle("antitau", 1777, 1, 1.4e8));

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
  for(particle &each_particle: particles)
  {
    tracker.print_detected_results();
    calorimeter.print_detected_results();
    muon_chamber.print_detected_results();
  }

  return 0;
}

  // string set_name(int particle_charge, double particle_rest_mass)
  // {
  //   if(particle_rest_mass==0.511)
  //   {
  //     if(particle_charge==1)
  //     {
  //       name = "electron";
  //     }
  //     else if(particle_charge==-1)
  //     {
  //       name = "antielectron";
  //     }
  //     else
  //     {
  //       std::cout<<"particle is not identified"<<std::endl;
  //       return 0;
  //     }
  //   }
  //   else if(particle_rest_mass==105.7)
  //   {
  //     if(particle_charge==1)
  //     {
  //       name = "muon";
  //     }
  //     else if(particle_charge==-1)
  //     {
  //       name = "antimuon";
  //     }
  //     else
  //     {
  //       std::cout<<"particle is not identified"<<std::endl;
  //       return 0;
  //     }
  //   }
  //   else
  //   {
  //     std::cout<<"particle is not identified"<<std::endl;
  //     return 0;
  //   }
  // }

// // Detect number of electrons
// int electrons_number()
// {
//   int electrons_number{0};
//   if(detected_particle.get_name()=="electron")
//   {
//     electrons_number++;
//   }
//   return electrons_number;
// }

// // Detect number of antielectrons
// int antielectrons_number()
// {
//   int antielectrons_number{0};
//   if(detected_particle.get_name()=="antielectron")
//   {
//     antielectrons_number++;
//   }
//   return antielectrons_number;
// }

// // Detect number of muons
// int muons_number()
// {
//   int muons_number{0};
//   if(detected_particle.get_name()=="muon")
//   {
//     muons_number++;
//   }
//   return muons_number;
// }

// // Detect number of antimuons
// int antimuons_number()
// {
//   int antimuons_number{0};
//   if(detected_particle.get_name()=="antimuon")
//   {
//     antimuons_number++;
//   }
//   return antimuons_number;
// }

// // Tracker detects electrons, muons and their antiparticles
// int tracker_particles()
// {
//   std::cout<<"Enter status of tracker: ";
//   bool tracker_status = get_status();
//   int tracker_particles{0};
//   if(tracker_status)
//   {
//     tracker_particles = electrons_number() + antielectrons_number() + muons_number() + antimuons_number();
//   }
//   else
//   {
//     return 0;
//   }
//   return tracker_particles;
// }

// // Calorimeter detects electrions and antielectrons
// int calorimeter_particles()
// {
//   std::cout<<"Enter status of calorimeter: ";
//   bool calorimeter_status = get_status();
//   int calorimeter_particles{0};
//   if(calorimeter_status)
//   {
//     calorimeter_particles = electrons_number() + antielectrons_number();
//   }
//   else
//   {
//     return 0;
//   }
//   return calorimeter_particles;
// }
// // Muon chamber detects muons and antimuons
// int muon_chamber_particles()
// {
//   std::cout<<"Enter status of muon chamber: ";
//   bool muon_chamber_status = get_status();
//   int muon_chamber_particles{0};
//   if(muon_chamber_status)
//   {
//     muon_chamber_particles = muons_number() + antimuons_number();
//   }
//   else
//   {
//     return 0;
//   }
//   return muon_chamber_particles;
// }


// // #include <iostream>
// // #include <string>
// // #include <cmath>

// // class Lepton {
// // private:
// //     std::string particleType;
// //     double restMass;  // in MeV
// //     int charge;       // +1 for particles, -1 for antiparticles
// //     double velocity;   // in m/s

// //     // Constant for the speed of light
// //     static const double speedOfLight;

// // public:
// //     // Default Constructor
// //     Lepton(std::string type, double mass, int charge, double velocity)
// //         : particleType(type), restMass(mass), charge(charge) {
// //         setVelocity(velocity);
// //     }

// //     // Getter functions
// //     std::string getParticleType() const { return particleType; }
// //     double getRestMass() const { return restMass; }
// //     int getCharge() const { return charge; }
// //     double getVelocity() const { return velocity; }
// //     double getBeta() const { return velocity / speedOfLight; }

// //     // Setter function for velocity with input checking
// //     void setVelocity(double newVelocity) {
// //         if (newVelocity >= 0 && newVelocity <= speedOfLight) {
// //             velocity = newVelocity;
// //         } else {
// //             std::cerr << "Invalid velocity. Velocity should be between 0 and the speed of light." << std::endl;
// //         }
// //     }

// //     // Function to display lepton information
// //     void displayLeptonInfo() const {
// //         std::cout << "Particle Type: " << particleType << std::endl;
// //         std::cout << "Rest Mass: " << restMass << " MeV" << std::endl;
// //         std::cout << "Charge: " << charge << std::endl;
// //         std::cout << "Velocity: " << velocity << " m/s" << std::endl;
// //         std::cout << "Beta: " << getBeta() << std::endl;
// //     }
// // };

// // // Initialization of the speed of light constant
// // const double Lepton::speedOfLight = 2.99792458e8;

// // int main() {
// //     // Example usage
// //     Lepton electron("Electron", 0.511, -1, 2.0e7); // Electron at 2.0e7 m/s

// //     // Display lepton information
// //     electron.displayLeptonInfo();

// //     // Change the velocity and display information again
// //     electron.setVelocity(3.0e8); // Attempting to set velocity greater than the speed of light
// //     electron.displayLeptonInfo();

// //     return 0;
// // }

// #include <iostream>
// #include <string>
// #include <vector>
// #include <cmath>

// using std::string;

// // Beginning of particle class
// class particle
// {
// private:
//     string particle_type;
//     double rest_mass; // MeV
//     int charge;
//     double velocity; // m/s
//     const double speed_of_light = 2.997924588; // m/s
//     double beta; // Between 0-1

// public:
//     // Constructors
//     particle() : particle_type{}, rest_mass{}, charge{}, velocity{}, beta{} {}
//     particle(string p_type, double r_mass, int p_charge, double p_velocity)
//         : particle_type{p_type}, rest_mass{r_mass}, charge{p_charge}, velocity{p_velocity}
//     {
//         // Include input validation and setting beta value
//         if (velocity >= 0 && velocity <= speed_of_light)
//         {
//             beta = velocity / speed_of_light;
//         }
//         else
//         {
//             std::cerr << "Invalid velocity. Velocity should be between 0 and the speed of light." << std::endl;
//         }
//     }

//     // Destructor
//     ~particle() { std::cout << "Destroying " << particle_type << std::endl; }

//     // Getter functions
//     string get_particle_type() const { return particle_type; }
//     double get_rest_mass() const { return rest_mass; }
//     int get_charge() const { return charge; }
//     double get_velocity() const { return velocity; }
//     double get_beta() const { return beta; }

//     // Setter functions
//     // Include input validation before changing values

//     // Function to print info about a particle
//     void print_data()
//     {
//         std::cout << "Particle Type: " << particle_type << std::endl;
//         std::cout << "Rest Mass: " << rest_mass << " MeV" << std::endl;
//         std::cout << "Charge: " << charge << std::endl;
//         std::cout << "Velocity: " << velocity << " m/s" << std::endl;
//         std::cout << "Beta Value: " << beta << std::endl;
//     }
// };

// // End of particle class

// // Beginning of detector class
// class detector
// {
// private:
//     string detector_type;
//     bool status;
//     int detected_particles_count;

// public:
//     // Constructors
//     detector() : detector_type{}, status{}, detected_particles_count{} {}
//     detector(string d_type, bool d_status)
//         : detector_type{d_type}, status{d_status}, detected_particles_count{} {}

//     // Destructor
//     ~detector() { std::cout << "Destroying " << detector_type << " detector" << std::endl; }

//     // Getter functions
//     bool get_status() const { return status; }

//     // Setter functions
//     void turn_on() { status = true; }
//     void turn_off() { status = false; }

//     // Function to detect particles
//     bool detect_particle(const particle &p)
//     {
//         if (status)
//         {
//             // Logic to detect particles based on detector type and particle type
//             // Update detected_particles_count accordingly
//             // Print relevant information
//             std::cout << p.get_particle_type() << " was detected by " << detector_type << " detector." << std::endl;
//             detected_particles_count++;
//             return true;
//         }
//         else
//         {
//             std::cout << detector_type << " detector is off. Cannot detect particles." << std::endl;
//             return false;
//         }
//     }

//     // Function to print detected results
//     void print_detected_results()
//     {
//         std::cout << "Number of particles detected by " << detector_type << " detector: " << detected_particles_count << std::endl;
//     }
// };

// // End of detector class

// // Main program
// int main()
// {
//     // Create particles
//     particle electron("electron", 0.511, -1, 0.8);
//     particle muon("muon", 105.7, -1, 0.6);

//     // Print particle data
//     electron.print_data();
//     muon.print_data();

//     // Create detectors
//     detector tracker("Tracker", true);
//     detector calorimeter("Calorimeter", false);
//     detector muon_chamber("Muon Chamber", true);

//     // Detect particles using detectors
//     tracker.detect_particle(electron);
//     calorimeter.detect_particle(electron);
//     muon_chamber.detect_particle(muon);

//     // Print detected results
//     tracker.print_detected_results();
//     calorimeter.print_detected_results();
//     muon_chamber.print_detected_results();

//     return 0;
// }

