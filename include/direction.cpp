#include "vex.h"

using namespace vex;

/*
    The gyro class
    This class will contain all functionality related to the gyroscope
*/
class Direction {

  public:

    Direction() {
      calibrate();
    }

    void accountForSpin() {
      updateRotation();
      spinTurret();
    }


  private:

    double relativeSpin = dir.heading(degrees);
    double previousRelativeSpin;

    void updateRotation() {
      previousRelativeSpin = relativeSpin;
      relativeSpin = dir.heading(degrees);
    }

    void spinTurret() {
      turret.setVelocity(100, percent);
      turret.spinFor(forward, gyroOverflow(), degrees);
    }

    void calibrate() {
      dir.calibrate();
    }

    double gyroOverflow() {
      double rotationValue = relativeSpin - previousRelativeSpin;
      // if (rotationValue > 340) {
      //   rotationValue -= 360;
      // } else if (rotationValue < -340) {
      //   rotationValue += 360;
      // }

      return rotationValue;
    }

    double absoluteValue(double num) {
      if (num > 0) {
        return num;
      } else {
        return num * -1;
      }
    }
};