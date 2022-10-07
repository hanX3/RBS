
void get_error(double a, double a_err, double b, double b_err)
{
  double u = a/(a+b);
  cout << "N concentration = " << u << endl;

  double du_da = (b/(a+b)/(a+b));
  double du_db = -(a/(a+b)/(a+b));

  double du2 = du_da*du_da*a_err*a_err + du_db*du_db*b_err*b_err;
  double du = sqrt(du2);
  cout << "error = " << du << endl;
}
