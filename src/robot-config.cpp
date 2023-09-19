#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftDriveTrain = motor(PORT11, ratio18_1, false);
motor rightDriveTrain = motor(PORT20, ratio18_1, true);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
motor turret = motor(PORT16, ratio18_1, false);
motor shoulder = motor(PORT15, ratio36_1, false);
motor elbow = motor(PORT14, ratio36_1, false);
inertial rotGyro = inertial(PORT10);
motor flinger = motor(PORT1, ratio6_1, false);
motor hooker = motor(PORT19, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}