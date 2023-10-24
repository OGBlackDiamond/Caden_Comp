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
            directionType rev;
            if (degrees == forward) {
                rev = reverse;
            } else {
                rev = reverse;
            }

            rightDriveTrain.spinFor(dir, degrees, turns, false);
            lefttDriveTrain.spinFor(rev, degrees, turns);
        }
    private:

}