#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void generateNumbers(int);
ofstream fout;


int main() {
  srand(time(NULL));

  generateNumbers(10);
  generateNumbers(100);
  generateNumbers(1000);
  generateNumbers(10000);
  generateNumbers(100000);
  generateNumbers(1000000);
  generateNumbers(10000000);
  generateNumbers(100000000);
  generateNumbers(1000000000);  
}

void generateNumbers(int n){
  string filename = "input" + to_string(n);
  filename += ".txt";
  fout.open(filename);
  int count = n;
  while(count--){
    int a = (rand()%9)+1;
    int b = (rand()%9)+1;
    fout << a << ' ' << b << '\n';
  }
  fout.close();
  cout << "\n\nCompleted " << filename << "\n";
}