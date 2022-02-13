/*
This file works similarly to V1 except the output format is for 9 input files with inline comparisons.

╔═══════════════╦═══════════════╦═══════════════╦═══════════════╦═══════════════╦═══════════════╗
║Filename       ║Lines of Input ║True Branches  ║False Branches ║Ternary Time   ║If/Else Time   ║
╠═══════════════╬═══════════════╬═══════════════╬═══════════════╬═══════════════╬═══════════════╣
║               ║            10 ║               ║               ║               ║               ║
║               ║           100 ║               ║               ║               ║               ║
║               ║          1000 ║               ║               ║               ║               ║
║               ║         10000 ║               ║               ║               ║               ║
║               ║        100000 ║               ║               ║               ║               ║
║               ║       1000000 ║               ║               ║               ║               ║
║               ║      10000000 ║               ║               ║               ║               ║
║               ║     100000000 ║               ║               ║               ║               ║
║               ║    1000000000 ║               ║               ║               ║               ║
╚═══════════════╩═══════════════╩═══════════════╩═══════════════╩═══════════════╩═══════════════╝
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

struct TestData{
  string filename;
  int lines;
  int trues;
  int falses;
  string tTime;
  string iTime;
  TestData(){
    filename = "";
    lines = 0;
    trues = 0;
    falses = 0;
    tTime = "";
    iTime = "";
  }
  TestData(string s, int l, int t, int f, string tT, string iT){
    filename = s;
    lines = l;
    trues = t;
    falses = f;
    tTime = tT;
    iTime = iT;
  }
};

ifstream fin;
ofstream fout;
auto start = std::chrono::system_clock::now();
auto endTime = std::chrono::system_clock::now();
vector<TestData> finalData;
vector<string> filenames;

void TestRange(string);
void OutputData();
void ListFilenames();

int main() {
  fout.open("output.txt");

  ListFilenames();
  cout << filenames.size() << "\n";

  for(string filename : filenames)
    TestRange(filename);

  OutputData();

  cout << finalData.size() << "\n";

  fout.close();
}

void TestRange(string name){
  //load range
  fin.open(name);
    vector<pair<int,int>> r;
    while(!fin.eof())
    {
      int tA, tB;
      fin >> tA >> tB;
      pair<int,int> tP = {tA,tB};

      r.push_back(tP);
    }
  fin.close();

  int trueBranch, falseBranch;
  TestData temp;
  trueBranch = falseBranch = 0;
  //begin timer
  start = std::chrono::system_clock::now();
  for(pair<int,int> p : r){
    p.first>p.second? trueBranch++: falseBranch++;
  }
  //end timer
  endTime = std::chrono::system_clock::now();
  std::chrono::duration<double> seconds = endTime-start;
  //record results
  if(name.size() < 15)
    temp.filename = name;
  else{
    temp.filename = name.substr(0,6);
    temp.filename += "...";
    temp.filename += name.substr(name.length()-6, 6);
  }
  temp.lines = r.size();
  temp.trues = trueBranch;
  temp.falses = falseBranch;
  temp.tTime += to_string(seconds.count());

  trueBranch = falseBranch = 0;
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
  endTime = std::chrono::system_clock::now();filenames.push_back("input10.txt");
  seconds = endTime-start;
  //record results
  temp.iTime += to_string(seconds.count());
  finalData.push_back(temp);
}

void OutputData(){
  fout << "╔═══════════════╦═══════════════╦═══════════════╦═══════════════╦═══════════════╦═══════════════╗\n";
  fout << "║Filename       ║Lines of Input ║True Branches  ║False Branches ║Ternary Time   ║If/Else Time   ║\n";
  fout << "╠═══════════════╬═══════════════╬═══════════════╬═══════════════╬═══════════════╬═══════════════╣\n";
  for(TestData data : finalData)
    fout << "║" << setw(15) << right << data.filename << "║" << setw(15) << right << to_string(data.lines) << "║" << setw(15) << right << to_string(data.trues) << "║" << setw(15) << right << to_string(data.falses) << "║" << setw(15) << right << data.tTime << "║" << setw(15) << right << data.iTime << "║\n";
  fout << "╚═══════════════╩═══════════════╩═══════════════╩═══════════════╩═══════════════╩═══════════════╝\n";
}

void ListFilenames(){
  filenames.push_back("input10.txt");
  filenames.push_back("input100.txt");
  filenames.push_back("input1000.txt");
  filenames.push_back("input10000.txt");
  filenames.push_back("input100000.txt");
  filenames.push_back("input1000000.txt");
  filenames.push_back("input10000000.txt");
  filenames.push_back("input100000000.txt");
  filenames.push_back("input1000000000.txt");
}