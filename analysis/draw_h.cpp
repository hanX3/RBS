
void draw_h()
{
  TStyle *han_style= new TStyle("han_style","");

  // use plain black on white colors
  han_style->SetCanvasBorderMode(0);
  han_style->SetCanvasColor(0);
  han_style->SetFrameBorderMode(0);
  han_style->SetFrameBorderSize(3);
  han_style->SetFrameLineStyle(1);
  han_style->SetFrameLineWidth(2);
  han_style->SetFrameLineColor(0);
  han_style->SetPadBorderMode(0);
  han_style->SetPadColor(0);
  han_style->SetStatColor(0);

  // set the paper & margin sizes
  han_style->SetPaperSize(20, 40);
  han_style->SetPadTopMargin(0.05);
  han_style->SetPadRightMargin(0.15);
  han_style->SetPadBottomMargin(0.15);
  han_style->SetPadLeftMargin(0.15);

  // do not display any of the standard histogram decorations
  han_style->SetOptTitle(0);
  han_style->SetOptStat(0);
  han_style->SetOptFit(0);

  // put tick marks on top and RHS of plots
  han_style->SetPadTickX(1);
  han_style->SetPadTickY(1);
  han_style->SetOptTitle(0);
  han_style->SetHistLineWidth(2);
  
  printf("Welcome to ROOT!\n");
  gROOT->SetStyle("han_style");
  gStyle->SetLineWidth(2);

  gStyle->SetOptLogz();
  gStyle->SetTextSize(0.08);
  gStyle->SetTextFont(22);

  //gROOT->SetBatch(1);


  // real code
  TFile *file_in = TFile::Open("../../data/target1_center_position_2.root");
  if(file_in->IsZombie()){
    cout << "wrong open the file" << endl;
    return;
  }

  TH1F *h1 = (TH1F*)file_in->Get("h1");

  TCanvas *cav = new TCanvas("cav", "", 0, 0, 520, 360);
  cav->cd();

  h1->Draw();
  h1->GetXaxis()->SetTitle("Channel");
  h1->GetXaxis()->SetTitleSize(0.06);
  h1->GetYaxis()->SetTitle("Count");
  h1->GetYaxis()->SetTitleSize(0.06);
  h1->GetXaxis()->CenterTitle();
  h1->GetYaxis()->CenterTitle();
}