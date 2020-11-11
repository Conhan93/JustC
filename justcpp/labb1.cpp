#include <iostream>
#include <fstream>
#include "Employee.h"


void labb1();
void labb2();
void labb3();
void labb4();

int main()
{
    //labb1();
    //labb2();
    //labb3();
    labb4();
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
}
