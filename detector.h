#ifndef DETECTOR_H
#define DETECTOR_H
#include "particle.h"

// Beginning of detector class
class detector
{
private:
  string type;
  bool status;
  int particles_count{0};

public:
  // Default Constructor
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

  // Getter
  bool get_status()
  {
    return status;
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
      std::cout<<"Enter status of "<<type<<": (on/ off)"<<std::endl;
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

  // Function to detect particles
  bool detect_particles(particle detected_particle)
  {
    if(status)
    {
      if(type=="tracker"&&(detected_particle.get_name()=="electron"||detected_particle.get_name()=="positron"||detected_particle.get_name()=="muon"||detected_particle.get_name()=="antimuon"))
      {
        std::cout<<detected_particle.get_name()<<" was detected in the tracker."<<std::endl;
        particles_count++;
        return true;
      }
      else if(type=="calorimeter"&&(detected_particle.get_name()=="electron"||detected_particle.get_name()=="positron"))
      {
        std::cout<<detected_particle.get_name()<<" was detected in the calorimeter."<<std::endl;
        particles_count++;
        return true;
      }
      else if(type=="muon_chamber"&&(detected_particle.get_name()=="muon"||detected_particle.get_name()=="antimuon"))
      {
        std::cout<<detected_particle.get_name()<<" was detected in the muon chamber."<<std::endl;
        particles_count++;
        return true;
      }
      return false;
    }
    else
    {
      std::cout<<"No particles were detected in the "<<type<<" ."<<std::endl;
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

#endif