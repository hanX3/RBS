#include "PhysicsList.hh"

#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmLowEPPhysics.hh"
#include "G4EmLivermorePhysics.hh"
#include "G4EmPenelopePhysics.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4EmStandardPhysics_option4.hh"

#include "PhysListEmStandard.hh"

#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4EmParameters.hh"

//
PhysicsList::PhysicsList() 
: G4VModularPhysicsList(){
  SetVerboseLevel(1);

  // Default physics
  RegisterPhysics(new G4DecayPhysics());

  // Radioactive decay
  RegisterPhysics(new G4RadioactiveDecayPhysics());

  // EM physics
  // RegisterPhysics(new PhysListEmStandard());
  // RegisterPhysics(new G4EmStandardPhysics());
  // RegisterPhysics(new G4EmLowEPPhysics());
  // RegisterPhysics(new G4EmLivermorePhysics());
  // RegisterPhysics(new G4EmPenelopePhysics());
  // RegisterPhysics(new G4EmStandardPhysics_option3());
  RegisterPhysics(new G4EmStandardPhysics_option4());
}

//
PhysicsList::~PhysicsList()
{

}

//
void PhysicsList::SetCuts()
{
  G4VUserPhysicsList::SetCuts();

  DumpCutValuesTable();
}