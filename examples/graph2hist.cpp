
void graph2hist()
{
  // read data
  ifstream file_in;
  file_in.open("rbs_example_1.txt");
  if(!file_in){
    cout << "can not open the file" << endl;
    return ;
  }

  vector<long double> v_x;
  vector<long double> v_y;

  long double x, y;
  while(1){
    file_in >> x >> y;
    if(!file_in.good()){
      break;
    }

    v_x.push_back(x);
    v_y.push_back(y);
  }

  map<long double, double> m_xy;
  map<long double, double>::iterator it_found;

  for(int i=0;i<v_x.size();i++){
    cout << i << " " <<  v_x[i] << " " << v_y[i] << endl;

    while(1){
      if(m_xy.find(v_x[i]) == m_xy.end()){
        break;
      }
      v_x[i] += 0.0005;
    }
    m_xy.insert(pair<long double, double>(v_x[i], v_y[i]));
  }

  ofstream file_out;
  file_out.open("rbs_example_1_sort.txt");

  map<long double, double>::iterator it;
  

  int j = 0;

  for(it=m_xy.begin();it!=m_xy.end();++it){
    cout << j << " " << it->first << " " << it->second << endl;
    j++;
    file_out << it->first << " " << it->second << endl;
  }

  file_out.close();

  // TGraph *gr = new TGraph();

  // map<double, double>::iterator it;
  // int i=0;
  // for(it=m_xy.begin();it!=m_xy.end();++it){
  //   // cout << it->first << " " << it->second << endl;
  //   gr->SetPoint(i, it->first, it->second);
  //   i++;
  // }

  // TCanvas* c1 = new TCanvas("c1", "c1", 0, 0, 480, 360);
  // c1->cd();
  // gr->Draw();
}
