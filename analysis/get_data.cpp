
void get_data()
{
  // TString str_name = TString::Format("Backing_Ta_1750keV");
  // TString str_name = TString::Format("target1_1750keV");
  TString str_name = TString::Format("Backing_Ta_2");
  cout << str_name << endl;

  TFile *file_in = TFile::Open(TString::Format("../../data/%s.root",str_name.Data()).Data());
  if(file_in->IsZombie()){
    cout << "wrong open the file" << endl;
    return;
  }

  TH1F *h1 = (TH1F*)file_in->Get("h1");
  if(!h1){
    cout << "no h1" << endl;
    return;
  }

  ofstream file_out1;
  file_out1.open(TString::Format("%s_170_degree.txt",str_name.Data()).Data());

  for(int i=0;i<h1->GetNbinsX();i++){
    file_out1 << h1->GetBinCenter(i+1) << " " << h1->GetBinContent(i+1) << endl;
  }

  file_out1.close();

  //
  TH1F *h2 = (TH1F*)file_in->Get("h2");
  if(!h2){
    cout << "no h2" << endl;
    return;
  }

  ofstream file_out2;
  file_out2.open(TString::Format("%s_165_degree.txt",str_name.Data()).Data());

  for(int i=0;i<h2->GetNbinsX();i++){
    file_out2 << h2->GetBinCenter(i+1) << " " << h2->GetBinContent(i+1) << endl;
  }

  file_out2.close();

  file_in->Close();
}