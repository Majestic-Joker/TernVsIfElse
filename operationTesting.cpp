/*
The purpose of this replit is to determine the time savings of using the ternary operator vs a basic if else structure.
A series of tests will be performed using 100 to 1 billion inputs
inputs will be generated randomly from my replit titled RandomNumbers. 
The branch results will be recorded in the file name output to ensure ternary and if else are processing the same data.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

ifstream fin;
ofstream fout;
auto start = std::chrono::system_clock::now();
auto endTime = std::chrono::system_clock::now();

void testRange(vector<pair<int,int>>);

int main() {
  fin.open("input10000000");
  fout.open("output");

  vector<pair<int,int>> range;
  while(!fin.eof())
  {
    int tA, tB;
    fin >> tA >> tB;
    pair<int,int> tP = {tA,tB};

    range.push_back(tP);
  }

  testRange(range);

  fin.close();
  fout.close();
}

void testRange(vector<pair<int,int>> r){ 
  int trueBranch, falseBranch;
  
  trueBranch = falseBranch = 0;
  fout << "==Ternary Operation==\n";
  //begin timer
  start = std::chrono::system_clock::now();
  for(pair<int,int> p : r){
    p.first>p.second? trueBranch++: falseBranch++;
  }
  //end timer
  endTime = std::chrono::system_clock::now();
  std::chrono::duration<double> seconds = endTime-start;
  //record results
  fout << "Total Branches: " << r.size() << "\n";
  fout << "True Branches: " << trueBranch << "\n";
  fout << "False Branches: " << falseBranch << "\n";
  fout << "Executed in: " << seconds.count() << " seconds\n";

  trueBranch = falseBranch = 0;
  fout << "\n==If/Else Operation==\n";
  //begin timer
  start = std::chrono::system_clock::now();
  for(pair<int,int> p : r){
    if(p.first > p.second){
      trueBranch++;
    }
    else{
      falseBranch++;
    }
  }
  //end timer
  endTime = std::chrono::system_clock::now();
  seconds = endTime-start;
  //record results
  fout << "Total Branches: " << r.size() << "\n";
  fout << "True Branches: " << trueBranch << "\n";
  fout << "False Branches: " << falseBranch << "\n";
  fout << "Executed in: " << seconds.count() << " seconds\n";
}