using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftDriveTrain;
extern motor rightDriveTrain;
extern controller Controller1;
extern controller Controller2;
extern motor turret;
extern motor shoulder;
extern motor elbow;
extern motor flinger;
extern motor hooker;
extern motor hand;
extern inertial dir;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );