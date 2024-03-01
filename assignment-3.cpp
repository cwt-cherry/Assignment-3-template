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
  particle(string particle_name, double particle_rest_mass, int particle_charge, double particle_velocity, double particle_beta):
    name{particle_name}, rest_mass{particle_rest_mass}, charge{particle_charge}, velocity{particle_velocity}
  {
    // Include setter functions here?
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
  string set_name(int particle_charge, double particle_rest_mass)
  {
    if(particle_rest_mass==0.511)
    {
      if(particle_charge==1)
      {
        name = "electron";
      }
      else if(particle_charge==-1)
      {
        name = "antielectron";
      }
      else
      {
        std::cout<<"particle is not identified"<<std::endl;
        return 0;
      }
    }
    else if(particle_rest_mass==105.7)
    {
      if(particle_charge==1)
      {
        name = "muon";
      }
      else if(particle_charge==-1)
      {
        name = "antimuon";
      }
      else
      {
        std::cout<<"particle is not identified"<<std::endl;
        return 0;
      }
    }
    else
    {
      std::cout<<"particle is not identified"<<std::endl;
      return 0;
    }
  }
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

  void set_beta(double velocity, const double speed_of_light)
  {
    beta = velocity / speed_of_light;
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

// Implementation of print_data function goes here


// End of particle class and associated member functions

// Beginning of detector class
class detector
{
private:
  string tracker;
  string calorimeter;
  string muon_chamber;
  bool status;

public:
  // Destruct Constructor
  detector(): tracker{}, calorimeter{}, muon_chamber{}, status{}
  {
  }

  // Parameterised Constructor
  detector(string chosen_status):
    status{set_status(chosen_status)}
  {
  }

  // Destructor
  ~detector()
  {
    std::cout<<"Destroying "<<status<<std::endl;
  }

  // Setter
bool set_status(string chosen_status)
{
    while(true)
    {
        std::cin >> chosen_status;
        if (chosen_status == "on")
        {
            status = true;
            return true;
        }
        else if (chosen_status == "off")
        {
            status = false;
            return true;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter choice again." << std::endl;
        }
    }
    return false;
}

  // Getter
  bool get_status()
  {
    return status;
  }
// Functionalities needed, in addition to constructor/destructor/setters/getters (see slides on BB):
particle detected_particle;
// - write a function that takes a particle and returns a bool and a print-out on whether this type of detector detected the particle
//   depending on the detector/particle combination (see slides on BB)
// - have data members that keep track of how many particles were detected by this particular detector, 
//   and of which type

// Detect number of electrons
int electrons_number()
{
  int electrons_number{0};
  if(detected_particle.get_name()=="electron")
  {
    electrons_number++;
  }
}

// Detect number of antielectrons
int antielectrons_number()
{
  int antielectrons_number{0};
  if(detected_particle.get_name()=="antielectron")
  {
    antielectrons_number++;
  }
}

// Detect number of muons
int muons_number()
{
  int muons_number{0};
  if(detected_particle.get_name()=="muon")
  {
    muons_number++;
  }
}

// Detect number of antimuons
int antimuons_number()
{
  int antimuons_number{0};
  if(detected_particle.get_name()=="antimuon")
  {
    antimuons_number++;
  }
}

// Tracker detects electrons, muons and their antiparticles
int tracker_particles()
{
  std::cout<<"Enter status of tracker: ";
  bool tracker_status = get_status();
  if(tracker_status)
  {
    int tracker_particles{0};
    return tracker_particles;
  }
  else
  {
    return 0;
  }
}

// Calorimeter detects electrions and antielectrons
int calorimeter_particles()
{
  std::cout<<"Enter status of calorimeter: ";
  bool calorimeter_status = get_status();
  if(calorimeter_status)
  {
    int electrons_number{0};
    int antielectrons_number{0};
    if(detected_particle.get_name()=="electron")
    {
      electrons_number++;
    }
    else if(detected_particle.get_name()=="antielectron")
    {
      antielectrons_number++;
    }
    int calorimeter_particles = electrons_number + antielectrons_number;
    return calorimeter_particles, electrons_number, antielectrons_number;
  }
  else
  {
    return 0;
  }
}
// Muon chamber detects muons and antimuons
int muon_chamber_particles()
{
  std::cout<<"Enter status of muon chamber: ";
  bool muon_chamber_status = get_status();
  if(muon_chamber_status)
  {
    int muons_number{0};
    int antimuons_number{0};
    if(detected_particle.get_name()=="muon")
    {
      muons_number++;
    }
    else if(detected_particle.get_name()=="antimuon")
    {
      antimuons_number++;
    }
    int muon_chamber_particles = muons_number + antimuons_number;
    return muon_chamber_particles, muons_number, antimuons_number;
  }
  else
  {
    return 0;
  }
}
// - write a function (accessor) that prints how many particles passed through this detector
void print_detected_results()
{
  std::cout<<"Number of particles passed through the tracker is: "<<tracker_particles<<std::endl;
  std::cout<<"Number of particles passed through the calorimeter is: "<<calorimeter_particles<<std::endl;
  std::cout<<"Number of particles passed through the muon chamber is: "<<muon_chamber_particles<<std::endl;
  std::cout<<detected_particle.get_name()<<" was detected."<<std::endl;
}
};
// End of detector class

// Main program
int main()
{

  // Create the following particles: 
  // two electrons, four muons, three taus, one antielectron, one antimuon, one antitau 
  // Use the parameterised constructor

  // Print out the data from all the particles (put them in a vector)

  // Create the following detectors: a tracker, a calorimeter, a muon chamber

  // Pass the list of particles into each detector

  // Print a summary of how many particles were detected

  return 0;
}


// #include <iostream>
// #include <string>
// #include <cmath>

// class Lepton {
// private:
//     std::string particleType;
//     double restMass;  // in MeV
//     int charge;       // +1 for particles, -1 for antiparticles
//     double velocity;   // in m/s

//     // Constant for the speed of light
//     static const double speedOfLight;

// public:
//     // Default Constructor
//     Lepton(std::string type, double mass, int charge, double velocity)
//         : particleType(type), restMass(mass), charge(charge) {
//         setVelocity(velocity);
//     }

//     // Getter functions
//     std::string getParticleType() const { return particleType; }
//     double getRestMass() const { return restMass; }
//     int getCharge() const { return charge; }
//     double getVelocity() const { return velocity; }
//     double getBeta() const { return velocity / speedOfLight; }

//     // Setter function for velocity with input checking
//     void setVelocity(double newVelocity) {
//         if (newVelocity >= 0 && newVelocity <= speedOfLight) {
//             velocity = newVelocity;
//         } else {
//             std::cerr << "Invalid velocity. Velocity should be between 0 and the speed of light." << std::endl;
//         }
//     }

//     // Function to display lepton information
//     void displayLeptonInfo() const {
//         std::cout << "Particle Type: " << particleType << std::endl;
//         std::cout << "Rest Mass: " << restMass << " MeV" << std::endl;
//         std::cout << "Charge: " << charge << std::endl;
//         std::cout << "Velocity: " << velocity << " m/s" << std::endl;
//         std::cout << "Beta: " << getBeta() << std::endl;
//     }
// };

// // Initialization of the speed of light constant
// const double Lepton::speedOfLight = 2.99792458e8;

// int main() {
//     // Example usage
//     Lepton electron("Electron", 0.511, -1, 2.0e7); // Electron at 2.0e7 m/s

//     // Display lepton information
//     electron.displayLeptonInfo();

//     // Change the velocity and display information again
//     electron.setVelocity(3.0e8); // Attempting to set velocity greater than the speed of light
//     electron.displayLeptonInfo();

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <cmath>

// const double speed_of_light = 2.997924588e8;

// // Lepton class
// class Lepton {
// private:
//     std::string particle_type;
//     double rest_mass; // MeV
//     int charge;
//     double velocity; // m/s
//     double beta;

// public:
//     // Constructors
//     Lepton() : particle_type{}, rest_mass{}, charge{}, velocity{}, beta{} {}
//     Lepton(std::string type, double mass, int charge, double velocity) : particle_type{type}, rest_mass{mass}, charge{charge}, velocity{velocity} {
//         setBeta();
//     }

//     // Destructor
//     ~Lepton() {
//         std::cout << "Destroying " << particle_type << std::endl;
//     }

//     // Getters
//     std::string getType() const { return particle_type; }
//     double getMass() const { return rest_mass; }
//     int getCharge() const { return charge; }
//     double getVelocity() const { return velocity; }
//     double getBeta() const { return beta; }

//     // Setters
//     void setVelocity(double v) {
//         if (v >= 0 && v <= speed_of_light) {
//             velocity = v;
//             setBeta();
//         } else {
//             std::cerr << "Invalid velocity. Velocity should be between 0 and the speed of light." << std::endl;
//         }
//     }

//     // Print particle data
//     void printData() const {
//         std::cout << "Particle Type: " << particle_type << std::endl;
//         std::cout << "Rest Mass: " << rest_mass << " MeV" << std::endl;
//         std::cout << "Charge: " << charge << std::endl;
//         std::cout << "Velocity: " << velocity << " m/s" << std::endl;
//         std::cout << "Beta Value: " << beta << std::endl;
//     }

// private:
//     void setBeta() {
//         beta = velocity / speed_of_light;
//     }
// };

// // Detector class
// class Detector {
// private:
//     std::string detector_type;
//     bool status;
//     int particles_detected;

// public:
//     // Constructors
//     Detector() : detector_type{}, status{false}, particles_detected{} {}
//     Detector(std::string type) : detector_type{type}, status{false}, particles_detected{} {}

//     // Destructor
//     ~Detector() {
//         std::cout << "Destroying " << detector_type << std::endl;
//     }

//     // Turn on the detector
//     void turnOn() {
//         status = true;
//     }

//     // Turn off the detector
//     void turnOff() {
//         status = false;
//     }

//     // Detect a particle and return whether it was detected
//     bool detectParticle(const Lepton& particle) {
//         if (status) {
//             std::cout << particle.getType() << " was detected by " << detector_type << std::endl;
//             particles_detected++;
//             return true;
//         }
//         return false;
//     }

//     // Print detector information
//     void printDetectorInfo() const {
//         std::cout << "Detector Type: " << detector_type << std::endl;
//         std::cout << "Status: " << (status ? "On" : "Off") << std::endl;
//         std::cout << "Particles Detected: " << particles_detected << std::endl;
//     }
// };

// int main() {
//     // Instantiate particles on the heap
//     Lepton* electron = new Lepton("electron", 0.511, 1, 0);
//     Lepton* muon = new Lepton("muon", 105.7, 1, 0);
//     Lepton* antiElectron = new Lepton("antielectron", 0.511, -1, 0);
//     Lepton* antiMuon = new Lepton("antimuon", 105.7, -1, 0);

//     // Put particle pointers in a vector
//     std::vector<Lepton*> particles = {electron, electron, muon, muon, muon, muon, antiElectron, antiMuon};

//     // Instantiate detectors on the heap
//     Detector* tracker = new Detector("Tracker");
//     Detector* calorimeter = new Detector("Calorimeter");
//     Detector* muonChamber = new Detector("Muon Chamber");

//     // Ask the user to turn on/off detectors separately
//     std::cout << "Enter 'on' to turn on Tracker: ";
//     std::string trackerChoice;
//     std::cin >> trackerChoice;
//     if (trackerChoice == "on") {
//         tracker->turnOn();
//     }

//     std::cout << "Enter 'on' to turn on Calorimeter: ";
//     std::string calorimeterChoice;
//     std::cin >> calorimeterChoice;
//     if (calorimeterChoice == "on") {
//         calorimeter->turnOn();
//     }

//     std::cout << "Enter 'on' to turn on Muon Chamber: ";
//     std::string muonChamberChoice;
//     std::cin >> muonChamberChoice;
//     if (muonChamberChoice == "on") {
//         muonChamber->turnOn();
//     }

//     // Detect particles based on detector status
//     for (const auto& particle : particles) {
//         tracker->detectParticle(*particle);
//         calorimeter->detectParticle(*particle);
//         muonChamber->detectParticle(*particle);
//     }

//     // Turn off detectors
//     tracker->turnOff();
//     calorimeter->turnOff();
//     muonChamber->turnOff();

//     // Delete particles on the heap
//     for (auto particle : particles) {
//         delete particle;
//     }

//     // Delete detectors on the heap
//     delete tracker;
//     delete calorimeter;
//     delete muonChamber;

//     return 0;
// }
