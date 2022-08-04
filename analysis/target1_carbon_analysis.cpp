// target1 and Ta target normalized
// target1 - Ta target histogram


//
void target1_carbon_analysis()
{
  //target1
  TFile *file_in_1 = TFile::Open("../../data/target1_1750keV.root");
  if(file_in_1->IsZombie()){
    cout << "wrong open the file" << endl;
    return;
  }

  TH1F *ha_165 = (TH1F*)file_in_1->Get("h1");
  if(!ha_165){
    cout << "no h1" << endl;
    return;
  }

  //ta target
  TFile *file_in_2 = TFile::Open("../../data/Backing_Ta_1750keV.root");
  if(file_in_2->IsZombie()){
    cout << "wrong open the file" << endl;
    return;
  }

  TH1F *hb_165 = (TH1F*)file_in_2->Get("h1");
  if(!hb_165){
    cout << "no h1" << endl;
    return;
  }

  //
  cout << "bins " << ha_165->GetNbinsX() << endl;
  cout << "bins " << hb_165->GetNbinsX() << endl;


  double sum_a165 = ha_165->Integral(4400, 5000);
  double sum_b165 = hb_165->Integral(4400, 5000);
  cout << "ha_165 integral " << ha_165->Integral(4400, 5000) << endl;
  cout << "hb_165 integral " << hb_165->Integral(4400, 5000) << endl;

  //

  hb_165->Scale(sum_a165/sum_b165);
  ha_165->Rebin(8);
  hb_165->Rebin(8);



  TCanvas *c1 = new TCanvas("c1");
  c1->cd();
  ha_165->SetLineColor(2);
  ha_165->Draw();
  hb_165->SetLineColor(4);
  hb_165->Draw("same hist");


  TH1D *hha = new TH1D("hha", "", ha_165->GetNbinsX(), 0, 8192);
  //
  ofstream file_out;
  file_out.open("target1-Ta.txt");

  for(int i=0;i<ha_165->GetNbinsX();i++){
    hha->SetBinContent(i+1, ha_165->GetBinContent(i+1)-hb_165->GetBinContent(i+1));
    file_out << i+1 << "  " << ha_165->GetBinContent(i+1)-hb_165->GetBinContent(i+1) << endl;
  }

  file_out.close();

  c1->cd();
  hha->SetLineColor(3);
  hha->Draw("same");
}