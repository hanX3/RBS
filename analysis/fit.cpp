

Double_t FunA(Double_t *i, Double_t *p);

//
void fit_1750()
{
  TString str_name = TString::Format("Backing_Ta_1750keV");
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

  h1->Draw();
  h1->GetXaxis()->SetRangeUser(5350, 5500);

  TF1 *tf_a = new TF1("tf_a", FunA, 5350, 5500, 6);
  tf_a->SetParameter(0, 400);
  tf_a->SetParameter(1, 2);
  tf_a->SetParameter(2, 2);
  tf_a->SetParameter(3, 5500);
  tf_a->SetParameter(4, -1);
  tf_a->SetParameter(5, 1);
  h1->Fit(tf_a, "R");

  Double_t s1 = 0;
  for(int i=5350;i<5370;i++){
    s1 += tf_a->Eval((Double_t)i);
  }
  s1 /= 20.;
  cout << "s1 " << s1 << endl;

  Double_t s2 = 0;
  for(int i=5480;i<5500;i++){
    s2 += tf_a->Eval((Double_t)i);
  }
  s2 /=  20.;
  cout << "s2 " << s2 << endl;
    
  cout << "s1+s2 /2 " << (s1+s2)/2. << endl;

  Double_t s = (s1+s2)/2.;

  for(int i=5350;i<5500;i++){
    if((tf_a->Eval((Double_t)i)-s)*(tf_a->Eval((Double_t)i+1.)-s) < 0){
      cout << i << endl;
      break;
    }
  }
}

//
void fit_2000()
{
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

  h1->Draw();
  h1->GetXaxis()->SetRangeUser(6150, 6300);

  TF1 *tf_a = new TF1("tf_a", FunA, 6150, 6300, 6);
  tf_a->SetParameter(0, 400);
  tf_a->SetParameter(1, 2);
  tf_a->SetParameter(2, 2);
  tf_a->SetParameter(3, 6200);
  tf_a->SetParameter(4, -1);
  tf_a->SetParameter(5, 1);
  h1->Fit(tf_a, "R");

  Double_t s1 = 0;
  for(int i=6150;i<6170;i++){
    s1 += tf_a->Eval((Double_t)i);
  }
  s1 /= 20.;
  cout << "s1 " << s1 << endl;

  Double_t s2 = 0;
  for(int i=6280;i<6300;i++){
    s2 += tf_a->Eval((Double_t)i);
  }
  s2 /=  20.;
  cout << "s2 " << s2 << endl;
    
  cout << "s1+s2 /2 " << (s1+s2)/2. << endl;

  Double_t s = (s1+s2)/2.;

  for(int i=6150;i<6300;i++){
    if((tf_a->Eval((Double_t)i)-s)*(tf_a->Eval((Double_t)i+1.)-s) < 0){
      cout << i << endl;
      break;
    }
  }
}



Double_t FunA(Double_t *i, Double_t *p)
{
  Double_t s = 0.;

  s = p[0]*exp(p[1]/(p[2])*(1-exp(p[2]*(i[0]-p[3])))) + p[4]*(i[0]-p[3]) + p[5];
  
  return s;
}
