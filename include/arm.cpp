#include "vex.h"

using namespace vex;

/*
The arm class
This will put all of the control for the arm on controller two
*/
class Arm {

    public:

        // set the stopping values and speeds of all the motors
        Arm() {
            turret.setVelocity(1, percent);
            shoulder.setStopping(hold);
            elbow.setStopping(hold);
            flinger.setVelocity(100, percent);
        }



        void manipulatorControl() {
            // make sure the current state of the controller is up to date
            updateControls();
            // move the motors


            shoulder.setStopping(hold);
            elbow.setStopping(hold);
            // don't allow drift of the shoulder
            if (absoluteValue(shoulderSpin) >= 10) {
                shoulder.spin(forward);
            } else {
                shoulder.stop();
            }

            // don't allow drift of the shoulder
            if (absoluteValue(elbowSpin) >= 10) {
                elbow.spin(forward);
            } else {
                elbow.stop();
            }

            // spin the turret
            if (spinTurretLeft) {
                turret.spin(reverse);
            } else if (spinTurretRight) {
                turret.spin(forward);
            } else {
                turret.stop();
            }

            // fling the fling fling  
            if (fling) {
                flinger.setVelocity(10, percent);
                flinger.spinFor(reverse, 720, degrees, false);
            } else {
                //flinger.stop();
            }
        }

        // destroys the class object
        void destroy() {
            delete this;
        }

    private:

        // variables that spin the turret
        bool spinTurretLeft;
        bool spinTurretRight;

        // the value to articulate the shoulder
        int shoulderSpin;

        // the value to articulate the elbow
        int elbowSpin;

        // value to fling the flinger
        bool fling;

        // update all of the controller values
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
            // updates the value that will fling the flinger
            fling = Controller2.ButtonA.pressing() && !flinger.isSpinning();
        }

        // return the absolute value of a number
        double absoluteValue(double num) {
            if (num >= 0) {
                return num;
            } else {
                return num * -1;
            }
        }
};