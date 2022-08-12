#ifndef RootIO_H
#define RootIO_H 1

#include <globals.hh>

#include <fstream>
#include <map>

#include "Constants.hh"

class TFile;
class TH1D;
class TTree;

//
class RootIO
{
public:
  RootIO(G4int save);
  ~RootIO();

  void Open();
  void Close();

  void FillTree(G4int ii, G4double ee, G4double xx, G4double yy, G4double zz);

private:
  G4int flag_save;

  G4int target_track;
	G4double target_e;
  G4double target_xx;
  G4double target_yy;
  G4double target_zz;

  char file_name[1024];

  TFile *file_in;
  TTree *tr;
};

#endif
