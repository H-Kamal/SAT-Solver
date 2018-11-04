#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
//NOTE: Will likely want to store the value of our
//Guess in an array and test it against each clause
//By storing each into a seperate char array


  //Inputting from a file
  string line;
  string p = "p";
  int i = 0;
  int num =-1;
  int vars = 5;
  int clause[vars];
  int soln[vars] = {1,0,1,-1,0};
  int arg = 0;


  ifstream dimacsIn;
  //NOTE THAT THE .txt isnt required.
  dimacsIn.open("SATWebsite");

  if(dimacsIn.is_open())
  {
    /* NOTE Dont need this since Im going to check each var against the value
    getline(dimacsIn,line);
    //How to make sure 2 strings are the same
  */
    do {
      getline(dimacsIn,line);
    } while(line.find_first_of(p));
    cout << line << endl;

    for(i= 0; i < vars;i++)
    {
      clause[i] = 0;
    }

/*
    while(!(dimacsIn.eof()))
    {
      while(num != 0)
      {
        dimacsIn>>num;
        cout << "Went into seconds while" << endl;
        if(num>0)
        {
          cout << "num >0" << endl;
          clause[num] = 1;
        }
        else if(num<0)
        {
          cout << "num < 0" << endl;
          clause[num] = -1;
        }
        cout << num << " ";
      }
*/
        //Segmentation fault occurs here
        /*
        if(!dimacsIn.eof())
        {
          dimacsIn >> num;
        }

        //i = i+1;
      }
      */
      //dimacsIn >> num;

      //cout << num << " ";

      /*
      while(!dimacsIn.eof())
      {
        dimacsIn>>num;
        do
        {
          if(num > 0)
          {
            clause[num-1] = 1;
          }
          else if(num < 0)
          {
            num = num*-1;
            clause[num-1] = -1;
          }
        }while(num!=0);
      }
      */
      while(!dimacsIn.eof())
      {
        dimacsIn>>num;
          if(num > 0)
          {
            clause[num-1] = 1;
          }
          else if(num < 0)
          {
            num = num*-1;
            clause[num-1] = -1;
          }
          else if(num ==0)
          {
            //Check the array and reset it to 0's.
            for(i=0;i<vars;i++)
            {
              if(clause[i] == soln[i])
              {
                cout << "Clause satisfied" << endl;
                arg = arg+1;
              }

              if(arg>0)
              {
                break;
              }
              else if(arg==0)
              {
                //None of the ifs went in therefore clause not
                //satisifed
                //call function again with new randoms
              }
            }
            //Reseting to 0's for next clause
            for(i= 0; i < vars;i++)
            {
              clause[i] = 0;
            }
          }
      }
      //Printing
      for(i= 0; i < vars;i++)
      {
        cout << clause[i] << " ";
      }

  }
  else
  {
    cout << "Error in opening file";
  }

  dimacsIn.close();

  return 0;
}
