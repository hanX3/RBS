#include "DetectorConstruction.hh"
#include "TargetSD.hh"

#include "G4UserLimits.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Torus.hh"
#include "G4Tubs.hh"
#include "G4Hype.hh"
#include "G4Trd.hh"
#include "G4Orb.hh"
#include "G4UnionSolid.hh"
#include "G4SubtractionSolid.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"
#include "G4VPhysicalVolume.hh"
#include "G4SDManager.hh"

//public methods
DetectorConstruction::DetectorConstruction()
: step_limit(NULL),
  mat_vaccum(NULL),
  mat_ta(NULL)
{

}

//
DetectorConstruction::~DetectorConstruction()
{
  delete step_limit;
}

//
G4VPhysicalVolume *DetectorConstruction::Construct()
{
  //Define materials
  DefineMaterials();

  //Define volumes
  return DefineVolumes();
}

//
void DetectorConstruction::DefineMaterials()
{
  G4NistManager* nist = G4NistManager::Instance();
  mat_vaccum = nist->FindOrBuildMaterial("G4_Galactic");
  mat_ta =  nist->FindOrBuildMaterial("G4_Ta");

  // Print materials
  G4cout << *(G4Material::GetMaterialTable()) << G4endl;
	G4cout << "Define Materials sucefully" << G4endl;
}

//
G4LogicalVolume *DetectorConstruction::GetTargetLog(G4String target_name)
{
  G4cout << " --->: GetTarget, begin" << G4endl;

  G4LogicalVolume *target_log = NULL;
  G4Tubs *solid_target = new G4Tubs("Target", 0, TARGET_R, TARGET_THICKNESS, 0, CLHEP::twopi);
  target_log = new G4LogicalVolume(solid_target, mat_ta, target_name);

  //color
  G4VisAttributes  *p_vis_att = new G4VisAttributes(G4Colour(1.0, 0.0, 0.0, 0.4));
  p_vis_att->SetForceSolid(true);
  target_log->SetVisAttributes(p_vis_att);

  return target_log;
}

//
G4VPhysicalVolume *DetectorConstruction::DefineVolumes()
{
  G4cout << " --->: Construct, begin" << G4endl;

  //Option to switch on/off checking of volumes overlaps
  G4bool check_overlaps = true;

  //define world
  G4Box *solid_world = new G4Box("World", 0.5*WORLD_SIZE_X, 0.5*WORLD_SIZE_Y, 0.5*WORLD_SIZE_Z);
  G4LogicalVolume *logic_world = new G4LogicalVolume(solid_world, mat_vaccum, "World");
  G4VPhysicalVolume *phys_world = new G4PVPlacement(0, G4ThreeVector(), logic_world, "World", 0, false, 0, check_overlaps);
  //color
  G4VisAttributes  *p_vis_att = new G4VisAttributes(G4Colour(0., 0.3, 0.0, 0.));
  p_vis_att->SetForceSolid(false);
  logic_world->SetVisAttributes(p_vis_att);

  
  //Target
  G4ThreeVector position_target = G4ThreeVector(0, 0, TARGET_POS_DIS);
  G4LogicalVolume *target_log = GetTargetLog("Target");
  new G4PVPlacement(0, position_target, target_log, "Target", logic_world, false, 0, check_overlaps);
  
  //Sensitive detectors
  G4SDManager *sd_man = G4SDManager::GetSDMpointer();

  TargetSD *target = new TargetSD("TargetSD", "TargetHitCollection");
  target_log->SetSensitiveDetector(target);
  sd_man->AddNewDetector(target); 

  return phys_world;
}

