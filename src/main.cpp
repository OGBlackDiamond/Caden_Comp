/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftDriveTrain       motor         11              
// rightDriveTrain      motor         20              
// Controller1          controller                    
// Controller2          controller                    
// turret               motor         16              
// shoulder             motor         15              
// elbow                motor         14              
// dir                  inertial      10              
// ---- END VEXCODE CONFIGURED DEVICES ----

// Caden bot
// Caden^1/2 * Caden^2 = Caden


// Critically
// Acclaimed
// Destroyer (of)
// Entire
// Nations


#include "vex.h"
#include "driver.cpp"
#include "arm.cpp"
//#include "direction.cpp"
#include "auto.cpp"

using namespace vex;

// A global instance of competition
competition Competition;

// the driver class
Driver driver;

// the arm class
Arm arm;

// the gyro class
//Direction direction;

// the autonomous class
Auto autoClass;


// toggle variables have to be defined globally for some reason
bool flingerToggle = false;
bool armToggle = false;
bool armHoldToggle = false;
bool driveTrainToggle = false;

// define your global instances of motors and other devices here




// other functions

// function that toggles the flinger
void toggleFlinger() {
  flingerToggle = !flingerToggle;
}

// function that toggles the arm speed
void toggleArm() {
  armToggle = !armToggle;
}

// function that toggles whether the arm will hold iteself up or not
// this is because the arm sometimes draws too much power, and limits the drivetrain.
void toggleArmHold() {
  armHoldToggle = !armHoldToggle;
}

void toggleDriveTrain() {
  driveTrainToggle = !driveTrainToggle;
}

// sets the toggle functions
void setToggles() {
    // toggles the flinger if the A button is pressed
    Controller2.ButtonA.pressed(toggleFlinger);
    Controller2.ButtonL1.pressed(toggleArm);
    Controller2.ButtonR1.pressed(toggleArm);
    Controller1.ButtonA.pressed(toggleArmHold);
    Controller1.ButtonB.pressed(toggleDriveTrain);
}





/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

  //autoClass.auto2();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop

  // sets all toggle values 
  setToggles();
  while (1) {
    //direction.accountForSpin();
    arm.manipulatorControl(armToggle, armHoldToggle, flingerToggle);
    driver.driverControl(driveTrainToggle);

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}