#include "ActionInitialization.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "RootIO.hh"

//
ActionInitialization::ActionInitialization(G4int thesaveFlag)
: G4VUserActionInitialization(),
  saveFlag(thesaveFlag)
{

}

//
ActionInitialization::~ActionInitialization()
{}

//
void ActionInitialization::BuildForMaster() const
{
  PrimaryGeneratorAction* fPriGen = new PrimaryGeneratorAction();
  RootIO* fRootIO = new RootIO(saveFlag);

  SetUserAction(new RunAction(fRootIO, fPriGen));
}

//
void ActionInitialization::Build() const
{
  PrimaryGeneratorAction* fPriGen = new PrimaryGeneratorAction();
  RootIO* fRootIO = new RootIO(saveFlag);

  SetUserAction(fPriGen);
  SetUserAction(new RunAction(fRootIO, fPriGen));
  SetUserAction(new EventAction(fRootIO));
  // DetectorConstruction *detconstruct = new DetectorConstruction();
  // SetUserAction(new SteppingAction(detconstruct));
}