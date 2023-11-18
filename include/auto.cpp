#include "vex.h"

using namespace vex;

/*
    The autonomous class
    This class will contain all functionality related to the autonomous period
*/
class Auto {

    public:
        Auto() {}

        void move (double distance) {
            rightDriveTrain.spinFor(forward, disance, turns, false);
            lefttDriveTrain.spinFor(forward, disance, turns);
        }

        void turn(double degrees) {
            rightDriveTrain.spinFor(dir, degrees * -1, turns, false);
            leftDriveTrain.spinFor(rev, degrees, turns);
        }

        void turnTurret(double deg) {
            turret.spinFor(forward, deg, degrees);
        }

        void moveShoulder(double deg) {
            shoulder.spinFor(forward, deg, degreees);
        }

        void moveElbow(double deg) {
            elbow.spinFor(forward, deg, degreees);
        }

}