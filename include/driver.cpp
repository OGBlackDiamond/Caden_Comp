#include "vex.h"

using namespace vex;

/*
  The driver class
  All of the control for the driver will be placed on the first controller
*/
class Driver {

  public:

    Driver() {}

    void driverControl() {
      // refresh control stick values
      updateControls();
      // spin the motors
      leftDriveTrain.spin(forward);
      rightDriveTrain.spin(forward);

      // control the hook
      if (hookUp) {
        hooker.spin(forward);
      } else if (hookDown) {
        hooker.spin(reverse);
      } else {
        hooker.stop();
      }
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
    void updateControls() {
      // get the current reading from the stick values
      leftDrive = Controller1.Axis3.position();
      rightDrive = Controller1.Axis2.position();
      // apply them to the current motor velocity
      leftDriveTrain.setVelocity(leftDrive, percent);
      rightDriveTrain.setVelocity(rightDrive, percent);

      // determine the hook controls
      hookUp = Controller1.ButtonUp.pressing();
      hookDown = Controller1.ButtonDown.pressing();
    }
};