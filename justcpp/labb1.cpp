#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Employee.h"


void labb1();
void labb2();
void labb3();
void labb4();
void labb5();
void labb6();

int main()
{
    //labb1();
    //labb2();
    //labb3();
    //labb4();
    //labb5();
    labb6();
}
void labb1()
{
    Employee employee1(160);
    Employee employee2(160,140);
    Employee employee3(160,160,0.4);

    std::cout << employee1.calculateSalary() << '\n';
    std::cout << employee2.calculateSalary() << '\n';
    std::cout << employee3.calculateSalary() << '\n';
}
void minSuperPrint(int val)
{
  std::cout << val << '\n';
}
void minSuperPrint(float val)
{
  std::cout << val << '\n';
}
void minSuperPrint(char* val)
{
  std::cout << val << '\n';
}
void labb2()
{
  int v1 = 5;
  float v2 = 3.5;
  char string[] = "Hello, World!";

  minSuperPrint(v1);
  minSuperPrint(v2);
  minSuperPrint(string);
}
int summera(int v1, int v2) {return v1 + v2; }
int summera(int v1, int v2, int v3) {return v1+v2+v3; }
int summera(int v1, int v2, int v3, int v4) {return v1+v2+v3+v4;}
int summera(int v1, int v2, int v3, int v4, int v5) {return v1+v2+v3+v4+v5;}
float summera(float f1, float f2) {return f1+f2;}
float summera(float f1, float f2, float f3) {return f1+f2+f3;}
float summera(float f1, float f2, float f3 , float f4) {return f1+f2+f3+f4;}
float summera(float f1, float f2, float f3, float f4, float f5){return f1+f2+f3+f4+f5;}

void labb3()
{
  int v1 = 3, v2 = 4, v3 = 15, v4 = 20, v5 = -2;
  float f1 = 2.5, f2 = 3.5, f3 = 35.25, f4 = 50, f5 = -2.5;

  std::cout << summera(v1,v2) << '\n';
  std::cout << summera(v1,v2,v3) << '\n';
  std::cout << summera(v1,v2,v3,v4) << '\n';
  std::cout << summera(v1,v2,v3,v4,v5) << '\n';
  std::cout << summera(f1,f2) << '\n';
  std::cout << summera(f1,f2,f3) << '\n';
  std::cout << summera(f1,f2,f3,f4) << '\n';
  std::cout << summera(f1,f2,f3,f4,f5) << '\n';
}

void labb4()
{
    // instead of writing "std::"
    using namespace std;
    /*
        using namespaces are kinda like calling a scope.
        instead of just declaring a datatype, we're also
        declaring a scope type.

        So we don't accidentally overload a function from
        std with something else.

        I think of it kinda lika "import whatever as whatev" in
        Python, we're using methods from this library or class
    */
    int nr_lines = 0;
    char filename[50];
    char new_line[100];

    cout << "Enter nr lines to read: ";
    cin >> nr_lines;
    cin.ignore();

    cout << '\n' << "Enter filename: ";
    cin.getline(filename,50);

    ofstream outfile;
    outfile.open(filename);

    for(int iteration = 0 ; iteration < nr_lines ; iteration++)
    {
      cout << "Enter line nr " << iteration << " : ";
      cin.getline(new_line,100);
      outfile << new_line << endl;
    }
    outfile.close();
}
void labb5()
{
  // so we don't have to write std:: infront of EVERYTHING!!!
  using namespace std;


  // filenames
  string filename1, filename2;

  // get filenames
  cout << "Enter filename1: ";
  getline(cin, filename1);
  cout << '\n' << "Enterfilename2: ";
  getline(cin, filename2);

  // list of strings
  vector<string> buffer;

  // fopens, read
  ifstream infile1(filename1);
  ifstream infile2(filename2);
  // string to read input to
  string read;

  //read with getline, put read string onto buffer list
  while(getline(infile1,read)) buffer.push_back(read);
  infile1.close();
  while(getline(infile2,read)) buffer.push_back(read);
  infile2.close();

  // get filename for third file
  string outfilename;
  cout << '\n' << "Enter filename for outfile: ";
  getline(cin,outfilename);

  // assign filename to outstream
  ofstream outfile(outfilename);

  // loop through buffer list(vector) and print to outfile
  for(size_t index = 0 ; index < buffer.size() ; index++)
  {
    outfile << buffer[index] << endl;
  }

  outfile.close();

}
void labb6()
{
  double km = 0;
  // cout to print string literal to terminal
  std::cout << "Enter number of kms to convert: ";
  // cin(c-in) to get input
  std::cin >> km;
  // ignore what's left on stdin
  std::cin.ignore();

  // print all this crap
  std::cout << "\n" << km << " is " << km * 1.609 << " miles" << std::endl;
}
