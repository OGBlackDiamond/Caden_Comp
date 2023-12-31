#include "vex.h"

using namespace vex;

/*
  The driver class
  All of the control for the driver will be placed on the first controller
*/
class Driver {

  public:

    Driver() {}

    void driverControl(bool toggleDriveTrain) {
      // refresh control stick values
      updateControls(toggleDriveTrain);
      // spin the motors
      leftDriveTrain.spin(forward);
      rightDriveTrain.spin(forward);
    }

    // destroys the class object
    void destroy() {
      delete this;
    }

  private:
    // define integer values for left and right sticks
    int leftDrive;
    int rightDrive;

    // variables that control the hook
    bool hookUp;
    bool hookDown;

    // update the controller values 
    void updateControls(bool driveTrainToggle) {
      // get the current reading from the stick values
      leftDrive = driveTrainToggle ? Controller1.Axis3.position() * 0.75 : Controller1.Axis3.position();
      rightDrive = driveTrainToggle ? Controller1.Axis2.position() * 0.75 : Controller1.Axis2.position();
      // apply them to the current motor velocity
      leftDriveTrain.setVelocity(leftDrive, percent);
      rightDriveTrain.setVelocity(rightDrive, percent);
    }
};