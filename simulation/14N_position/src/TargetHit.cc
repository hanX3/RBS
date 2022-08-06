#include "TargetHit.hh"
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

#include <iomanip>

G4ThreadLocal G4Allocator<TargetHit>* TargetHitAllocator = 0;

//
TargetHit::TargetHit()
: G4VHit(),
  e_dep(0.)
{

}

//
TargetHit::~TargetHit() 
{

}

//
TargetHit::TargetHit(const TargetHit& right)
: G4VHit(),
  e_dep(right.e_dep)
{
  
}

//
const TargetHit& TargetHit::operator=(const TargetHit& right)
{
  e_dep = right.e_dep;

  return *this;
}

//
G4int TargetHit::operator==(const TargetHit& right) const
{
  return ( this == &right ) ? 1 : 0;
}

//
void TargetHit::Draw()
{

}

//
void TargetHit::Print()
{
  G4cout << "   trackID: " << track << "  Edep: " << std::setw(7) << G4BestUnit(e_dep, "Energy") << "   Position: " << std::setw(7) << G4BestUnit(pos, "Length") << G4endl;
}
