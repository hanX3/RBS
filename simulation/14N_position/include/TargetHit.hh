#ifndef TargetHit_h
#define TargetHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "tls.hh"

class TargetHit: public G4VHit
{
public:
  TargetHit();
  TargetHit(const TargetHit&);
  virtual ~TargetHit();

  //  operator
  const TargetHit& operator=(const TargetHit&);
  G4int operator==(const TargetHit&) const;

  inline void *operator new(size_t);
  inline void  operator delete(void*);

  // methods from base class
  virtual void Draw();
  virtual void Print();

public:
  void SetTrackID(G4int t) { track = t; };
  void SetEdep(G4double de) { e_dep = de; }
  void AddEdep(G4double de) { e_dep += de; }
  void SetPos(G4ThreeVector xyz){ pos = xyz; };

  G4int GetTrackID() const { return track; };
  G4double GetEdep() const { return e_dep; }
  G4ThreeVector GetPos() const { return pos; };

private:
  G4int track;
  G4double e_dep;
  G4ThreeVector pos;
};

//
typedef G4THitsCollection<TargetHit> TargetHitsCollection;

extern G4ThreadLocal G4Allocator<TargetHit>* TargetHitAllocator;

//
inline void* TargetHit::operator new(size_t)
{
  if(!TargetHitAllocator)
      TargetHitAllocator = new G4Allocator<TargetHit>;
  return (void *) TargetHitAllocator->MallocSingle();
}

//
inline void TargetHit::operator delete(void *hit)
{
  TargetHitAllocator->FreeSingle((TargetHit*) hit);
}

#endif
