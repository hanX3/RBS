
void draw()
{
  ifstream file_in;
  file_in.open("100keV_Ta_10000_event_TRIM.txt");

  TH1D *h = new TH1D("h", "h", 100, 0, 4000);
  int i = 0;

  double a, b;
  while(1){
    file_in >> a >> b;
    if(!file_in.good()){
      break;
    }

    //  cout << a << " " << b << endl;
    i++;
    h->SetBinContent(i, b);
  }

  file_in.close();

  TCanvas *c1 = new TCanvas("c1", "", 0, 0, 400, 300);
  c1->cd();
  h->Draw();

  double sum = 0;
  for(i=0;i<h->GetNbinsX();i++){
    sum += h->GetBinContent(i+1)*h->GetBinCenter(i+1);
  }

  cout << sum << endl;
}