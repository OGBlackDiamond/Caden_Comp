#include "vex.h"

using namespace vex;

class RotGyro {

  public:

    RotGyro() {
      calibrate();
      wait(2, seconds);
    }

    void accountForSpin() {
      updateRotation();
      spinTurret();
    }


  private:

    double relativeSpin = rotGyro.heading(degrees);
    double previousRelativeSpin;

    void updateRotation() {
      previousRelativeSpin = relativeSpin;
      relativeSpin = rotGyro.heading(degrees);
    }

    void spinTurret() {
      turret.spinFor(forward, gyroOverflow(), degrees);
    }

    void calibrate() {
      rotGyro.calibrate();
    }

    double gyroOverflow() {
      double rotationValue = relativeSpin - previousRelativeSpin;
      if (rotationValue > 360) {
        rotationValue -= 360;
      } else if (rotationValue < 0) {
        rotationValue += 360;
      }

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