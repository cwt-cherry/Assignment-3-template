// // PHYS 30762 Programming in C++
// // Assignment 3
// // Practice with C++ classes and their interactions

// #include<iostream>
// #include<string>
// #include<vector>
// #include<cmath>

// using std::string;

// // Beginning of particle class
// class particle
// {
// private:
//   string particle_name;
//   //...other data members (see slides on BB)

// public:
//   // Constructors
//   // Here you need a default constructor, and a parameterised constructor

//   // Destructor

//   // Getter functions (accessors) to 
//   // This should include function returning beta value 

//   // Setter functions, to change value of data members
//   // Make sure you check input validity before changing something
//   // Hint: you can use the input checking functions you used in assignment 1

//   // Function to print info about a particle
//   void print_data();

// };

// // Implementation of print_data function goes here

// // End of particle class and associated member functions

// // Beginning of detector class

// // Functionalities needed, in addition to constructor/destructor/setters/getters (see slides on BB):
// // - write a function that takes a particle 
// //   and returns a bool and a print-out on whether this type of detector detected the particle
// //   depending on the detector/particle combination (see slides on BB)
// // - have data members that keep track of how many particles were detected by this particular detector, 
// //   and of which type
// // - write a function (accessor) that prints how many particles passed through this detector

// // End of detector class

// // Main program
// int main()
// {

//   // Create the following particles: 
//   // two electrons, four muons, three taus, one antielectron, one antimuon, one antitau 
//   // Use the parameterised constructor

//   // Print out the data from all the particles (put them in a vector)

//   // Create the following detectors: a tracker, a calorimeter, a muon chamber

//   // Pass the list of particles into each detector

//   // Print a summary of how many particles were detected

//   return 0;
// }


#include <iostream>
#include <string>
#include <cmath>

class Lepton {
private:
    std::string particleType;
    double restMass;  // in MeV
    int charge;       // +1 for particles, -1 for antiparticles
    double velocity;   // in m/s

    // Constant for the speed of light
    static const double speedOfLight;

public:
    // Constructor
    Lepton(std::string type, double mass, int charge, double velocity)
        : particleType(type), restMass(mass), charge(charge) {
        setVelocity(velocity);
    }

    // Getter functions
    std::string getParticleType() const { return particleType; }
    double getRestMass() const { return restMass; }
    int getCharge() const { return charge; }
    double getVelocity() const { return velocity; }
    double getBeta() const { return velocity / speedOfLight; }

    // Setter function for velocity with input checking
    void setVelocity(double newVelocity) {
        if (newVelocity >= 0 && newVelocity <= speedOfLight) {
            velocity = newVelocity;
        } else {
            std::cerr << "Invalid velocity. Velocity should be between 0 and the speed of light." << std::endl;
        }
    }

    // Function to display lepton information
    void displayLeptonInfo() const {
        std::cout << "Particle Type: " << particleType << std::endl;
        std::cout << "Rest Mass: " << restMass << " MeV" << std::endl;
        std::cout << "Charge: " << charge << std::endl;
        std::cout << "Velocity: " << velocity << " m/s" << std::endl;
        std::cout << "Beta: " << getBeta() << std::endl;
    }
};

// Initialization of the speed of light constant
const double Lepton::speedOfLight = 2.99792458e8;

int main() {
    // Example usage
    Lepton electron("Electron", 0.511, -1, 2.0e7); // Electron at 2.0e7 m/s

    // Display lepton information
    electron.displayLeptonInfo();

    // Change the velocity and display information again
    electron.setVelocity(3.0e8); // Attempting to set velocity greater than the speed of light
    electron.displayLeptonInfo();

    return 0;
}
