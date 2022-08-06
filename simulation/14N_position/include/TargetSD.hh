#ifndef TargetSD_h
#define TargetSD_h 1

#include "G4VSensitiveDetector.hh"
#include "TargetHit.hh"

#include <vector>

class G4Step;
class G4HCofThisEvent;  //save multi SD hitcollection objects

class TargetSD: public G4VSensitiveDetector
{
public:
  TargetSD(const G4String &sd_name, const G4String &hits_collection_name);
  virtual ~TargetSD();

  //  methods from base class
  virtual void  Initialize(G4HCofThisEvent *hit_collection);
  virtual G4bool ProcessHits(G4Step *step, G4TouchableHistory *);
  virtual void   EndOfEvent(G4HCofThisEvent *hit_collection);

private:
  TargetHitsCollection *hits_collection;
};

#endif
