#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "G4ThreeVector.hh"

#include "globals.hh"
#include "Constants.hh"

class RootIO;
class TFile;

// Event action class
class EventAction: public G4UserEventAction
{
public:
  EventAction(RootIO *io);
  virtual ~EventAction();

  virtual void  BeginOfEventAction(const G4Event* );
  virtual void    EndOfEventAction(const G4Event* );

private:
  G4int target_track;
  G4double target_e;
  G4ThreeVector target_pos;

  RootIO *root_IO;
};

#endif
