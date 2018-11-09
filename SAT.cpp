#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void clauseCheck(int* clause, int* soln, int vars);
int posNegRand();
void randSoln(int* soln, int vars);

ifstream dimacsIn;

int main()
{
  //Inputting from a file
  string line;
  string p = "p";
  int i = 0;
  int solnVar;
  int vars = 5;
  int* clause = new int[vars];
  int* soln = new int[vars]{1,1,1,1,1};

  dimacsIn.open("SATWebsite");

  //Setting all the clauses values eqaul to zero
  for(i= 0; i < vars;i++)
  {
    clause[i] = 0;
  }

  //TODO: Traverse and retrieve the # of Vars and Clauses
  if(dimacsIn.is_open())
  {
    do {
      getline(dimacsIn,line);
    } while(line.find_first_of(p));
    cout << line << endl;

    //NOTE:
    //How can I send in a clause if its not even filled yet
    clauseCheck(clause,soln,vars);

    /*Might want to leave for later. Should instead
    have the clauses go through each clause in clauseCheck
    for(i = 0, i < clauseNum, i++)
    {
      clauseCorrect = clauseCheck(clause,soln, vars);
    }
    */
  }
  else
  {
    cout << "The file did not open" << endl;
  }

  dimacsIn.close();
  return 0;
}

void clauseCheck(int* clause, int* soln, int vars)
{
  int num;
  int i = 0;
  bool argMet = false;
  if(dimacsIn.is_open())
  {
    while(!dimacsIn.eof())
    {
      dimacsIn>>num;
      //cout << num << " ";
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
        cout << "reached end of clause";
        
        //Printing out cluase to test
        //NOTE all clauses are read and stored correctly
        cout << endl;
        for(i= 0; i < vars;i++)
        {
          cout << clause[i] << " ";
        }

        //Check the array and reset it to 0's.
        for(i=0;i<vars;i++)
        {
          if(clause[i] == soln[i])
          {
            cout << "Clause satisfied" << endl;
            argMet = true;
          }
          //This if/esle if block is in the for loop
          //Since otherwise we would check each variable
          //of every clause before moving on to next
          if(argMet==true)
          {
            //Might want to return something that Will
            //be used somewhere else to know
            //how many clauses were satisfied

            //Possibily return 1 and have a counter that
            //Increments the count of clauses satisfied in main()

            argMet = false;
            break;
          }
          else if(argMet==false)
          {
            //None of the ifs went in therefore clause not
            //satisifed
            //call function again with new randoms
            cout << "Calling another soln again" << endl;
            randSoln(soln,vars);
            clauseCheck(clause, soln, vars);
          }
        }
        //Reseting to 0's for next clause
        for(i= 0; i < vars;i++)
        {
          clause[i] = 0;
        }
        //NOTE TEST: Printing out to test clause indices
        //resets correctly MIGHT NOT BREAK CORRECTLY
        cout << endl;
        for(i= 0; i < vars;i++)
        {
          cout << clause[i] << " ";
        }

      }
    }
    //We have gone through every clause and resulted in a match
    cout << "All clauses met" << endl;
    //Printing
    for(i= 0; i < vars;i++)
    {
      cout << soln[i] << " ";
    }

  }
  else
  {
    cout << "Error in opening file";
    //return 1;
  }
}

int posNegRand()
{
  int posNeg = rand() % 4+1;
  if(posNeg>2)
  {
    return 1;
  }
  else if(posNeg<3)
  {
    return -1;
  }
}

void randSoln(int* soln, int vars)
{
  for(int i=0;i<vars;i++)
  {
    //soln is either filled with 1 or -1
    soln[i] = posNegRand();
  }
}
