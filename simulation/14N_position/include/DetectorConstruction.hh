#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "tls.hh"
#include "Constants.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Material;
class G4UserLimits;
class G4GlobalMagFieldMessenger;

class DetectorConstruction: public G4VUserDetectorConstruction
{
public:
  DetectorConstruction();
  virtual ~DetectorConstruction();

  virtual G4VPhysicalVolume *Construct();

  // other methods
  G4LogicalVolume *GetTargetLog(G4String target_name);

private:
  void DefineMaterials();
  G4VPhysicalVolume *DefineVolumes();

private:
  G4UserLimits *step_limit;

private:
  G4Material *mat_vaccum;
  G4Material *mat_ta;
};

#endif
