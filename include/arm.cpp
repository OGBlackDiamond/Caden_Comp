#include "vex.h"

using namespace vex;

class Arm {

  public:

    Arm() {
      turret.setVelocity(100, percent);
      shoulder.setStopping(hold);
      elbow.setStopping(hold);
    }

    void manipulatorControl() {
      // make sure the current state of the controller is up to date
      updateControls();
      // move the motors

      // don't allow drift of the shoulder
      if (shoulderSpin >= 10) {
        shoulder.spin(forward);
      } else {
        shoulder.stop();
      }

      if (elbowSpin >= 10) {
        elbow.spin(forward);
      } else {
        elbow.stop();
      }


      if (spinTurretLeft) {
        turret.spin(reverse);
      } else if (spinTurretRight) {
        turret.spin(forward);
      } else {
        turret.stop();
      }
    }

    // destroys the class object
    void destroy() {
      delete this;
    }

  private:

    bool spinTurretLeft;
    bool spinTurretRight;

    int shoulderSpin;

    int elbowSpin;

    void updateControls() {
      // updates the values that will spin the turret
      spinTurretLeft = Controller2.ButtonL2.pressing();
      spinTurretRight = Controller2.ButtonR2.pressing();
      // updates the stick values that will control the arm
      elbowSpin = Controller2.Axis3.position();
      shoulderSpin = Controller2.Axis2.position();
      // spins the motors accordingly
      elbow.setVelocity(elbowSpin, percent);
      shoulder.setVelocity(shoulderSpin, percent);
    }
 

};