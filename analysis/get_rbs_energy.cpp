
#define M_BEAM 1
#define M_TARGET 12
#define THETA 165.

#define E_BEAM 2. // MeV

void get_rbs_energy()
{
  double m1 = M_BEAM;
  double m2 = M_TARGET;
  double theta = THETA*3.14159/180.;

  double k = m1*cos(theta);
  k += sqrt(m2*m2-m1*m1*sin(theta)*sin(theta));
  k /= (m1+m2);
  k = k*k;

  double e = E_BEAM*k;

  cout << "e = " << e << endl;
}
