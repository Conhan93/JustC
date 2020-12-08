#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Employee.h"


void labb1();
void labb2();
void labb3();
void labb4();
void labb5();
void labb6();
void labb7();
void labb8();
void labb9();
void labb10();

int main()
{
    //labb1();
    //labb2();
    //labb3();
    //labb4();
    //labb5();
    //labb6();
    //labb7();
    //labb8();
    //labb9();
    labb10();

    return 0;
}
void labb1()
{
    // instantiates three objects of class employee
    Employee employee1(160);
    Employee employee2(160,140);
    Employee employee3(160,160,0.4);

    // call object methods
    std::cout << employee1.calculateSalary() << '\n';
    std::cout << employee2.calculateSalary() << '\n';
    std::cout << employee3.calculateSalary() << '\n';
}

/*
    Functions share the same name but differ on input
    arguments, will overload each other depending
    on what arguments are given to function when called.
*/
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

/*
    Same principle as minSuperPrint, compiler
    will find the correct function to call
    depending on the arguments given to the
    function call of summera
*/
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
void labb7()
{
    // initialize vector with ints
    std::vector<int> hardCode {0,1,2,3,4,10,9,8,6,5};

    // C-style loop using iterators
    for(auto it = begin(hardCode) ; it < end(hardCode) ; it++)
      std::cout << *it << ' ';

    /*
        this is what a range based for loop actually looks like.
        like a traditional for loop over an array like we're used
        to in C.

        Difference being that the loop is using iterators, pointers
        to navigate the array/collection(which is why we have to dereference
        the iterator to print the number!)
    */

    // sort vector using sort func from <algorithm>
    std::sort(begin(hardCode),end(hardCode));

    /*
        provide pointers(iterators) to the start and end of your
        container and the sort function will loop through and sort
        it for you.
    */

    std::cout << '\n' << "Sorted" << '\n';

    // range based for loop with auto type detection
    for(auto number : hardCode)
      std::cout << number << ' ';

    /*
        Range-based for loop that works like the for loop in Python.

        for number in hardCode:
          print(number)

        this one creates a copy of the value in hardCode and
        gives it to number, you can use the value directly by
        turning number into a reference using "auto& number".

        auto is a kind of compile-time polymorphism, polymorphism meaning many
        shapes(kinda?).
        The compiler will try to figure out what datatype auto
        should have by looking at what value is used to
        initialize it.

    */
}
void labb8()
{
    /*
        Dice guessing game, roll dice, guess the number
    */
    // seed rand with current time
    srand(time(NULL));

    /*
        srand seeds the rand functions, the rand functions
        have a sort of random walk that is based on the seed.

        if you've ever had issues with rand() giving off the Same
        values, it's probably because you called srand() with the same
        value everytime you tried to use rand().
        Causing rand() to take the first step of the same
        random walk based on the same seed
        every
        single
        time
    */

    int diceRoll;
    while(true)
    {
      // used for input
      std::string buffer;

      // rolls dice
      diceRoll = (rand() % 100) + 1;

      auto nrGuesses{0};
      auto correctGuess{false};

      /*
          Braced initialization throws errors if truncating occurs.
          ex. initalizing an int with a float value 3.5 will cause
          a narrowing conversion from 3.5 to 3 which means a loss
          of data, using braced initializers throws warnings at
          compile time.

          Kinda unneccesary here.
      */

      // while correctGuess == false
      while(!correctGuess)
      {
        auto guess{0};
        std::cout << "Enter your guess(1-100): ";

        // uses getline to avoid any issues with newlines
        std::getline(std::cin,buffer);
        // stoi(string to int) converts to input to integer
        guess = stoi(buffer);


        // elif chain
        if(diceRoll < guess) std::cout << "Little lower..." << '\n';
        else if(diceRoll > guess) std::cout << "Little Higher..." << '\n';
        else correctGuess = true; // break out of loop

        nrGuesses++; // count number of guesses
      }

      // yay
      std::cout << "Correct! you made " << nrGuesses << " Attempts" << '\n';

      // start over again
    }
}
void labb9()
{
  /*
      Enter a number(1-100) and write a program
      to guess the number
  */

  // constants
  enum limits { max = 100, min = 1 };
  std::string buffer; // input buffer

  auto diceRoll{0};
  auto correctGuess{false};
  auto nrGuesses{0};

  // get diceroll
  std::cout << "Enter your number(1-100): ";
  std::getline(std::cin,buffer);

  // convert input to integer
  diceRoll = stoi(buffer);

  // initialize computers guess
  int guess{max/2};

  while(!correctGuess)
  {
      nrGuesses++;
      std::cout << "Computers guess is " << guess << '\n'
      << "lower,higher or correct?: ";
      std::getline(std::cin,buffer);

      if(buffer == "lower") guess -= (max - guess)/2;
      else if(buffer == "higher") guess += (max - guess)/2;
      else if(buffer == "correct") correctGuess = true;

      if(guess < min || guess > max)
      {
        // the computer knows
        std::cout << "Liar" << '\n';
        correctGuess = true;
      }
  }

  std::cout << "Only took me " << nrGuesses << " attempts! hooman" << '\n';
}
void labb10()
{
    /*
        Read from input.txt and convert all chars
        to lower case and print into lower.txt
    */

    std::vector<std::string> buffer;
    std::string inputBuffer;

    /*
        A vector of strings to store read lines
        from the input file
    */

    // initialize streams with filenames/paths
    std::ifstream input("input.txt");
    std::ofstream output("lower.txt");

    /*
        getline reads from a stream(our is infilesteam "input")
        and stores in string inputBuffer, it reads up to a delim
        which is set to '\n' by default.

        getline evaluates to true while it is able to read from
        a stream(uses flags in ios).
        by checking the return value of getline you can read
        until end of file

        each read line is saved in buffer string vector
    */
    while(std::getline(input,inputBuffer)) buffer.push_back(inputBuffer);

    /*
        auto determines type by looking at the type of it's
        initializing value(buffer or line).

        the outer loop gets references(actual object) for each
        line/string read into the vector.

        the inner loop gets references to the members of the line/strings
        (chars) and uses tolower to change each letter
        to lowercase
    */
    for(auto& line : buffer)
      for(auto& letter : line) letter = tolower(letter);

    /*
        For each line/string in buffer
          print line to output file
          then
          print newline to output file
    */
    for(auto line : buffer)
      output << line << '\n';


    // tolower del 2

    for(auto& line : buffer)
      for(auto& letter : line)
        if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o'
          || letter == 'u')
          letter = toupper(letter);

    std::ofstream output2("bigvowels.txt");

    for(auto line : buffer)
      output2 << line << '\n';
}
