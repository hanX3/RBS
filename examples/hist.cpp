
void hist()
{
  ifstream file_in;
  file_in.open("hist.txt");

  double x, y;
  vector<double> v_y;
  int yy;

  while(1){
    file_in >> x >> y;
    if(!file_in.good()){
      break;
    }

    v_y.push_back(y);
  }

  TH1D *h1 = new TH1D("h1", "h1", 669, 20., 800.);
  double bin_width = h1->GetBinWidth(0);

  cout << bin_width << endl;
  for(int i=0;i<v_y.size();i++){
    yy = (int)v_y[i];
    h1->SetBinContent(i+1, yy);
  }

  TCanvas* c1 = new TCanvas("c1", "c1", 0, 0, 480, 360);
  c1->cd();
  h1->Draw();

  ofstream file_out;
  file_out.open("rbs_example_1.txt");

  for(int i=0;i<17;i++){
    file_out << i << " " << 0 << endl;
  }
  for(int i=0;i<669;i++){
    file_out << i+17 << " " << h1->GetBinContent(i+1) << endl;
  }

  file_out.close();
}