Double_t pipi = 3.141592654;


// e unit keV
void cali_E(Double_t theta, Double_t e)
{
  Double_t m1 = 1;  // 1H
  Double_t m2 = 12; // 14N

  Double_t e1;

  // cout << "sin(180) " << sin(2*3.14159) << endl;
  Double_t s1 = m2*m2 - m1*m1*sin(theta/180.*pipi)*sin(theta/180.*pipi);
  cout << "s1 " << s1 << endl;
  s1 = sqrt(s1);
  cout << "s1 " << s1 << endl;

  Double_t s2 = m1*cos(theta/180.*pipi);

  Double_t s3 = m1+m2;

  Double_t s4 = (s1+s2)/s3;
  e1 = s4*s4*e;

  cout << "e1 " << e1 << endl;
}