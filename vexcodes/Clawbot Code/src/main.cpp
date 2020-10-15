/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\zachw                                            */
/*    Created:      Sat Oct 10 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"


using namespace vex;

//This is the Comment outlineing the Robotics code:
//
//
//  Robot Configuration:
//  [Port]            [Name]          [Type]          [Description]       [Reversed]
//  
// /*----------------------------------------------------------------------------*/
 #include "vex.h"


 using namespace vex;
 //
vex::motor LeftMotor        = vex::motor(vex::PORT11, true);
vex::motor RightMotor       = vex::motor(vex::PORT20, false);
vex::motor Arm1             = vex::motor(vex::PORT13, false);
vex::motor Arm2             = vex::motor(vex::PORT, true);
vex::motor Claw             = vex::motor(vex::PORT12, true);
vex::controller Controller2 = vex::controller();

//
//


vex::competition Competition;
 int fwd =100;
 int ArmSpeedPCT = 40;
 int ClawSpeedPCT = 30;

void pre_autonomous( void ){
  //
  // Pre Competition actions.
  //
}
//
void usercontrol( void ) {

  Controller2.Screen.clearScreen();
  Controller2.Screen.print("Sellers is a Goat!");
  

  LeftMotor.setVelocity( 100, vex::velocityUnits::pct );
  RightMotor.setVelocity( 100, vex::velocityUnits::pct );

//
//

// While loop will create an infinite loop to pull program every run through of program.Brain

  while (1) {
  //Drive control

  LeftMotor.spin(vex::directionType::fwd, (Controller2.Axis3.position() + Controller2.Axis4.position())/2, vex::velocityUnits::pct);
RightMotor.spin(vex::directionType::fwd, (Controller2.Axis3.position() - Controller2.Axis4.position())/2, vex::velocityUnits::pct);

//
//
//

    if(Controller2.ButtonL2.pressing()){
      Arm1.spin(vex::directionType::fwd, ArmSpeedPCT, vex::velocityUnits::pct);
      Arm2.spin(vex::directionType::fwd, ArmSpeedPCT, vex::velocityUnits::pct);
    }

    else if (Controller2.ButtonL1.pressing()) {
      Arm1.spin(vex::directionType::rev, ArmSpeedPCT, vex::velocityUnits::pct);
      Arm2.spin(vex::directionType::rev, ArmSpeedPCT, vex::velocityUnits::pct);
    }

    else{
      Arm1.stop(vex::brakeType::brake);
    }

    //

    if(Controller2.ButtonR2.pressing()){
      Claw.spin(vex::directionType::fwd, ClawSpeedPCT, vex::velocityUnits::pct);
    }

    else if (Controller2.ButtonR1.pressing()){
      Claw.spin(vex::directionType::rev, ClawSpeedPCT, vex::velocityUnits::pct);
    }

    else {
      Claw.stop(vex::brakeType::brake);
    }

}

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Competition.drivercontrol( usercontrol );

  pre_autonomous();

  //Prevent infinite loops.

  while(1){
    vex::task::sleep(100); //Sleep to save energy.
  }

}
