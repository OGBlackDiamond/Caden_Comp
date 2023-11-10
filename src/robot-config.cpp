#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftDriveTrain = motor(PORT16, ratio18_1, false);
motor rightDriveTrain = motor(PORT15, ratio18_1, true);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
motor turret = motor(PORT10, ratio18_1, false);
motor shoulder = motor(PORT1, ratio36_1, false);
motor elbow = motor(PORT17, ratio36_1, true);
motor flinger = motor(PORT20, ratio36_1, false);
motor hand = motor(PORT14, ratio18_1, true);
inertial dir = inertial(PORT6);

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