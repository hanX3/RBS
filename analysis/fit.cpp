

Double_t FunA(Double_t *i, Double_t *p);

//
void fit_1750_170()
{
  TString str_name = TString::Format("Backing_Ta_1750keV");
  cout << str_name << endl;

  Double_t a = 5350.;
  Double_t b = 5500.;

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
  h1->GetXaxis()->SetRangeUser(a, b);

  TF1 *tf_a = new TF1("tf_a", FunA, a, b, 6);
  tf_a->SetParameter(0, 400);
  tf_a->SetParameter(1, 2);
  tf_a->SetParameter(2, 2);
  tf_a->SetParameter(3, b);
  tf_a->SetParameter(4, -1);
  tf_a->SetParameter(5, 1);
  h1->Fit(tf_a, "R");

  Double_t s1 = 0;
  for(int i=a;i<a+20;i++){
    s1 += tf_a->Eval((Double_t)i);
  }
  s1 /= 20.;
  cout << "s1 " << s1 << endl;

  Double_t s2 = 0;
  for(int i=b-20;i<b;i++){
    s2 += tf_a->Eval((Double_t)i);
  }
  s2 /=  20.;
  cout << "s2 " << s2 << endl;
    
  cout << "s1+s2 /2 " << (s1+s2)/2. << endl;

  Double_t s = (s1+s2)/2.;

  for(int i=a;i<b;i++){
    if((tf_a->Eval((Double_t)i)-s)*(tf_a->Eval((Double_t)i+1.)-s) < 0){
      cout << i << endl;
      break;
    }
  }
}

//
void fit_1750_165()
{
  TString str_name = TString::Format("Backing_Ta_1750keV");
  cout << str_name << endl;

  Double_t a = 5240.;
  Double_t b = 5390.;

  TFile *file_in = TFile::Open(TString::Format("../../data/%s.root",str_name.Data()).Data());
  if(file_in->IsZombie()){
    cout << "wrong open the file" << endl;
    return;
  }

  TH1F *h1 = (TH1F*)file_in->Get("h2");
  if(!h1){
    cout << "no h1" << endl;
    return;
  }

  h1->Draw();
  h1->GetXaxis()->SetRangeUser(a, b);

  TF1 *tf_a = new TF1("tf_a", FunA, a, b, 6);
  tf_a->SetParameter(0, 400);
  tf_a->SetParameter(1, 2);
  tf_a->SetParameter(2, 2);
  tf_a->SetParameter(3, b);
  tf_a->SetParameter(4, -1);
  tf_a->SetParameter(5, 1);
  h1->Fit(tf_a, "R");

  Double_t s1 = 0;
  for(int i=a;i<a+20;i++){
    s1 += tf_a->Eval((Double_t)i);
  }
  s1 /= 20.;
  cout << "s1 " << s1 << endl;

  Double_t s2 = 0;
  for(int i=b-20;i<b;i++){
    s2 += tf_a->Eval((Double_t)i);
  }
  s2 /=  20.;
  cout << "s2 " << s2 << endl;
    
  cout << "s1+s2 /2 " << (s1+s2)/2. << endl;

  Double_t s = (s1+s2)/2.;

  for(int i=a;i<b;i++){
    if((tf_a->Eval((Double_t)i)-s)*(tf_a->Eval((Double_t)i+1.)-s) < 0){
      cout << i << endl;
      break;
    }
  }
}

//
void fit_2000_170()
{
  TString str_name = TString::Format("Backing_Ta_2");
  cout << str_name << endl;

  Double_t a = 6150.;
  Double_t b = 6300.;

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
  h1->GetXaxis()->SetRangeUser(a, b);

  TF1 *tf_a = new TF1("tf_a", FunA, a, b, 6);
  tf_a->SetParameter(0, 400);
  tf_a->SetParameter(1, 2);
  tf_a->SetParameter(2, 2);
  tf_a->SetParameter(3, b);
  tf_a->SetParameter(4, -1);
  tf_a->SetParameter(5, 1);
  h1->Fit(tf_a, "R");

  Double_t s1 = 0;
  for(int i=a;i<a+20;i++){
    s1 += tf_a->Eval((Double_t)i);
  }
  s1 /= 20.;
  cout << "s1 " << s1 << endl;

  Double_t s2 = 0;
  for(int i=b-20;i<b;i++){
    s2 += tf_a->Eval((Double_t)i);
  }
  s2 /=  20.;
  cout << "s2 " << s2 << endl;
    
  cout << "s1+s2 /2 " << (s1+s2)/2. << endl;

  Double_t s = (s1+s2)/2.;

  for(int i=a;i<b;i++){
    if((tf_a->Eval((Double_t)i)-s)*(tf_a->Eval((Double_t)i+1.)-s) < 0){
      cout << i << endl;
      break;
    }
  }
}

//
void fit_2000_165()
{
  TString str_name = TString::Format("Backing_Ta_2");
  cout << str_name << endl;

  Double_t a = 6000.;
  Double_t b = 6150.;

  TFile *file_in = TFile::Open(TString::Format("../../data/%s.root",str_name.Data()).Data());
  if(file_in->IsZombie()){
    cout << "wrong open the file" << endl;
    return;
  }

  TH1F *h1 = (TH1F*)file_in->Get("h2");
  if(!h1){
    cout << "no h1" << endl;
    return;
  }

  h1->Draw();
  h1->GetXaxis()->SetRangeUser(a, b);

  TF1 *tf_a = new TF1("tf_a", FunA, a, b, 6);
  tf_a->SetParameter(0, 400);
  tf_a->SetParameter(1, 2);
  tf_a->SetParameter(2, 2);
  tf_a->SetParameter(3, b);
  tf_a->SetParameter(4, -1);
  tf_a->SetParameter(5, 1);
  h1->Fit(tf_a, "R");

  Double_t s1 = 0;
  for(int i=a;i<a+20;i++){
    s1 += tf_a->Eval((Double_t)i);
  }
  s1 /= 20.;
  cout << "s1 " << s1 << endl;

  Double_t s2 = 0;
  for(int i=b-20;i<b;i++){
    s2 += tf_a->Eval((Double_t)i);
  }
  s2 /=  20.;
  cout << "s2 " << s2 << endl;
    
  cout << "s1+s2 /2 " << (s1+s2)/2. << endl;

  Double_t s = (s1+s2)/2.;

  for(int i=a;i<b;i++){
    if((tf_a->Eval((Double_t)i)-s)*(tf_a->Eval((Double_t)i+1.)-s) < 0){
      cout << i << endl;
      break;
    }
  }
}

//
Double_t FunA(Double_t *i, Double_t *p)
{
  Double_t s = 0.;

  s = p[0]*exp(p[1]/(p[2])*(1-exp(p[2]*(i[0]-p[3])))) + p[4]*(i[0]-p[3]) + p[5];
  
  return s;
}
