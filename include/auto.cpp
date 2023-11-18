#include "vex.h"

using namespace vex;

/*
    The autonomous class
    This class will contain all functionality related to the autonomous period
*/
class Auto {

    public:
        Auto() {}


        // defines options for autonomous configuration

        void auto1() {
            closeClaw();
            moveElbow(100);
            moveShoulder(100);
            turnTurret(-100);
            openClaw();
            turn(-100);
            move(999);
        }

        void auto2() {
            closeClaw();
            move(100);
            move(-100);
        }

    private:

        //
        // The following functions define a set of instructions to make defining an autonomous program easier
        //

        void move(double distance) {
            rightDriveTrain.spinFor(forward, distance, turns, false);
            leftDriveTrain.spinFor(forward, distance, turns);
        }

        void turn(double degrees) {
            rightDriveTrain.spinFor(forward, degrees * -1, turns, false);
            leftDriveTrain.spinFor(forward, degrees, turns);
        }

        void turnTurret(double deg) {
            turret.spinFor(forward, deg, degrees);
        }

        void moveShoulder(double deg) {
            shoulder.spinFor(forward, deg, degrees);
        }

        void moveElbow(double deg) {
            elbow.spinFor(forward, deg, degrees);
        }

        void openClaw() {
            hand.spinFor(forward, 100, degrees, false);
        }

        void closeClaw() {
            hand.spinFor(reverse, 100, degrees, false);
        }

        void setMotorFunctions() {
            turret.setStopping(hold);
            shoulder.setStopping(hold);
            elbow.setStopping(hold);
        }

        //
        // End of auto function definitions
        //
};