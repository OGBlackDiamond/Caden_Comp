#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftDriveTrain = motor(PORT20, ratio18_1, true);
motor rightDriveTrain = motor(PORT4, ratio18_1, false);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
motor turret = motor(PORT18, ratio18_1, false);
motor shoulder = motor(PORT2, ratio36_1, false);
motor elbow = motor(PORT1, ratio36_1, true);
motor flinger = motor(PORT10, ratio36_1, false);
motor hand = motor(PORT9, ratio18_1, false);
inertial dir = inertial(PORT11);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
* Used to initialize code/tasks/devices added using tools in VEXcode Pro.
* 
* This should be called at the start of your int main function.
*/
void vexcodeInit( void ) {
    //
}