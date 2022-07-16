
void graph2hist()
{
  // read data
  ifstream file_in;
  file_in.open("rbs_example_1.txt");
  if(!file_in){
    cout << "can not open the file" << endl;
    return ;
  }

  vector<double> v_x;
  vector<double> v_y;

  double x, y;
  while(1){
    file_in >> x >> y;
    if(!file_in.good()){
      break;
    }

    v_x.push_back(x);
    v_y.push_back(y);
  }

  

}
