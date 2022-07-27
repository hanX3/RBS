// target1_1750keV.root vs. target2_1750keV.root


Double_t p0_170 = 4.13;
Double_t p1_170 = 0.31395;

Double_t p0_165 = 5.77;
Double_t p1_165 = 0.32146;

TString str_file_name_1 = "target1_1750keV";
TString str_file_name_3 = "target3_1750keV";

// 170 degree
void check_carbon_170()
{
  TFile *file_in_1 = TFile::Open(TString::Format("../../data/%s.root",str_file_name_1.Data()).Data());
  if(file_in_1->IsZombie()){
    cout << "wrong open the file" << endl;
    return;
  }

  TFile *file_in_3 = TFile::Open(TString::Format("../../data/%s.root",str_file_name_3.Data()).Data());
  if(file_in_3->IsZombie()){
    cout << "wrong open the file" << endl;
    return;
  }

  TH1F *h1_170 = (TH1F*)file_in_1->Get("h1");
  if(!h1_170){
    cout << "no h1" << endl;
    return;
  }

  TH1F *h3_170 = (TH1F*)file_in_3->Get("h1");
  if(!h3_170){
    cout << "no h3" << endl;
    return;
  }

  TH1D* h1 = new TH1D("h1", "target1 Si 170 degree @ 1750 keV", h1_170->GetNbinsX(), p0_170, p0_170+p1_170*h1_170->GetNbinsX());
  for(int i=0;i<h1_170->GetNbinsX();i++){
    h1->SetBinContent(i+1, h1_170->GetBinContent(i+1));
  }

  TCanvas *c1 = new TCanvas("c1");
  c1->cd();
  h1->Rebin(4);
  h1->Draw();

}


// 165 degree
void check_carbon_165()
{
  TFile *file_in_1 = TFile::Open(TString::Format("../../data/%s.root",str_file_name_1.Data()).Data());
  if(file_in_1->IsZombie()){
    cout << "wrong open the file" << endl;
    return;
  }

  TFile *file_in_3 = TFile::Open(TString::Format("../../data/%s.root",str_file_name_3.Data()).Data());
  if(file_in_3->IsZombie()){
    cout << "wrong open the file" << endl;
    return;
  }

  TH1F *h1_165 = (TH1F*)file_in_1->Get("h2");
  if(!h1_165){
    cout << "no h1" << endl;
    return;
  }

  TH1F *h3_165 = (TH1F*)file_in_3->Get("h2");
  if(!h3_165){
    cout << "no h3" << endl;
    return;
  }

  TH1D* h1 = new TH1D("h1", "target1 Si 165 degree @ 1750 keV", h1_165->GetNbinsX(), p0_165, p0_165+p1_165*h1_165->GetNbinsX());
  for(int i=0;i<h1_165->GetNbinsX();i++){
    h1->SetBinContent(i+1, h1_165->GetBinContent(i+1));
  }

  TCanvas *c1 = new TCanvas("c1");
  c1->cd();
  h1->Rebin(4);
  h1->Draw();

}