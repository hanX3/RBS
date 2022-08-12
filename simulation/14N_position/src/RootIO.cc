#include "TH1D.h"
#include "TFile.h"
#include "TTree.h"

#include "RootIO.hh"

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include "G4UnitsTable.hh"
#include "G4ThreeVector.hh"

//
RootIO::RootIO(G4int save)
: flag_save(save),
  file_in(NULL)
{
}

//
RootIO::~RootIO()
{
  if(file_in){
    delete file_in;
    file_in = NULL;
  }    
}

//
void RootIO::Open()
{
  if(flag_save){
    time_t t;
    struct tm* tt;
    t=time(0);
    tt=localtime(&t);
    sprintf(file_name, "%d%02d%02d_%02dh%02dm%02ds", tt->tm_year+1900, tt->tm_mon, tt->tm_mday, tt->tm_hour, tt->tm_min, tt->tm_sec);
    G4cout << "\n----> Tree file is opened in " << file_name << G4endl;

    std::stringstream ss;
    ss.str("");
    ss << DATAPATH << "/" << file_name << ".root";

    file_in = new TFile(ss.str().c_str(), "RECREATE");
    //  check file_in
    if(!file_in){
      G4cout << " RootIO::book :" << " problem creating the ROOT TFile!!!" << G4endl;
      return ;
    }

    //  creat tree
    tr = new TTree("tr", "simulation data");
    tr->Branch("target_track", &target_track, "target_track/I");
    tr->Branch("target_e", &target_e, "target_e/D");
    tr->Branch("target_xx", &target_xx, "target_xx/D");
    tr->Branch("target_yy", &target_yy, "target_yy/D");
    tr->Branch("target_zz", &target_zz, "target_zz/D");

    if(!tr){
      G4cout << "\n can't create tree" << G4endl;
      return ;
    }

    G4cout << "\n----> Tree file is opened in " << ss.str() << G4endl;
  }
}

//
void RootIO::FillTree(G4int ii, G4double ee, G4double xx, G4double yy, G4double zz)
{
  target_track = ii;
  target_e = ee;
  target_xx = xx;
  target_yy = yy;
  target_zz = zz;

  tr->Fill();
}

//
void RootIO::Close()
{
  if(!file_in){
    return;
  }

  tr->Write();
  file_in->Close();

  G4cout << "\n----> RootIO is saved.\n" << G4endl;
}