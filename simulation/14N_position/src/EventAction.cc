#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TMath.h"

#include "EventAction.hh"
#include "TargetHit.hh"
#include "RootIO.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4DCofThisEvent.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4ios.hh"
#include "G4SDManager.hh"
#include "G4RunManager.hh"

#include <string.h>

//
EventAction::EventAction(RootIO *io)
: G4UserEventAction(),
  root_IO(io)
{
  target_e = 0;
}

//
EventAction::~EventAction()
{

}

//
void EventAction::BeginOfEventAction(const G4Event*)
{
  target_e = 0;
}

//
void EventAction::EndOfEventAction(const G4Event* event)
{
  target_e = 0;

  auto sdManager = G4SDManager::GetSDMpointer();
  //Target
  G4int target_idd = sdManager->GetCollectionID("TargetSD/TargetHitCollection");
  auto target_hce = event->GetHCofThisEvent();
  auto target_hc = static_cast<TargetHitsCollection*>(target_hce->GetHC(target_idd));

  target_track = (*target_hc)[0]->GetTrackID();
  target_e = (*target_hc)[0]->GetEdep();
  target_e /= keV;
  target_pos = (*target_hc)[0]->GetPos();

  root_IO->FillTree(target_track, target_e, target_pos.x()/nm, target_pos.y()/nm, target_pos.z()/nm);
}
