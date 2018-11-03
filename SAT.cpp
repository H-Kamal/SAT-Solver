#include <iostream>
#include<fstream>
#include <string>

using namespace std;

int main()
{
//NOTE: Will likely want to store the value of our
//Guess in an array and test it against each clause
//By storing each into a seperate char array


  //Inputting from a file
  string line;
  string c = "c";
  string p = "p";
  string zero = "0";
  char num;
  int sizeString;
  ifstream dimacsIn;
  //NOTE THAT THE .txt isnt required.
  dimacsIn.open("SATWebsite");
  if(dimacsIn.is_open())
  {
    /* NOTE Dont need this since Im going to check each var against the value
    getline(dimacsIn,line);
    //How to make sure 2 strings are the same
    if(line.compare(c) == 0)
    {
      cout << "The strings are the same";
    }
    cout << endl;
    cout  << line << endl;
    */

    //NOTE I DONT KNOW HOW IM GOING TO SEARCH FOR A 0 IN A STRING!
    //Works aslong as p is the first letter
    do {
      getline(dimacsIn,line);
    } while(line.find_first_of(p));
    cout << line << endl;

    //Only extracts the first number of this string
    /*
    string check = "4 5";
    int lineConverted = stoi(check);
    cout << "Using stoi, the line is: " << lineConverted << endl;
    */
    char clause[6];
    for(int i=0; i<6; i++)
    {
      clause[i] = '*';
    }


    while(dimacsIn.get(num))
    {
      if(isdigit(num)!=0)
      {
        //cout << "Its the digit " <<num << endl;
        clause[num] = 'b';
        //cout << clause[num];
      }
      cout << num << " ";
    }

    int j = 0;
    for(j = 0; j<6;j++)
    {
      cout << clause[j] << " ";
    }

  }
  else
  {
    cout << "Error in opening file";
  }

  dimacsIn.close();

  return 0;
}
