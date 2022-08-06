#ifndef Constants_h
#define Constants_h 1

#include "globals.hh"
#include "G4SystemOfUnits.hh"

#define CSIARRAY
// #define SIPINARRAY

#define DATAPATH "./data"  // no "/"


//
constexpr G4double WORLD_SIZE_X = 2. * m;
constexpr G4double WORLD_SIZE_Y = 2. * m;
constexpr G4double WORLD_SIZE_Z = 2. * m;

// Taregt
constexpr G4double TARGET_R              = 15. * mm;
constexpr G4double TARGET_THICKNESS         = 0.5 * mm;
constexpr G4double TARGET_POS_DIS        = 0.5 * mm;

// BEAM
constexpr G4double BEAM_X   = 0. * mm;
constexpr G4double BEAM_Y   = 0. * mm;
constexpr G4double BEAM_Z   = -100. * mm;

#endif
