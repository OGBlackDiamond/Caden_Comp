#include "vex.h"

using namespace vex;

/*
    The autonomous class
    This class will contain all functionality related to the autonomous period
*/
class Auto {

    public:
        Auto() {}

        void move (directionType dir, double distance) {
            rightDriveTrain.spinFor(dir, disance, turns, false);
            lefttDriveTrain.spinFor(dir, disance, turns);
        }

        void turn(double degrees) {
            directionType dir;
            directionType rev;
            if (degrees > 0) {
                dir = forward;
                rev = reverse;
            } else {
                dir = reverse;
                rev = forward;
            }

            rightDriveTrain.spinFor(dir, degrees, turns, false);
            leftDriveTrain.spinFor(rev, degrees, turns);
        }
    private:

}