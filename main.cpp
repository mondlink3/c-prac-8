#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "LibHouses.h"
using namespace std;
using namespace DarkSpace ;
int main(int argc , char** argv)
{
    srand(time(nullptr));
    if(argc != 5 )
    {
        cerr<<"Incorrect number of command line arguments "<<endl ;
        cout <<"please run "<<argv[0]<<"<rows><cols><stairwells><fuses>"<<endl ;
        exit(ERROR_ARGC);
    }
    //command line variables
    int intRows = GetInt(argv[1]);
    int intCols = GetInt(argv[2]);
    int intStairwells = GetInt(argv[3]);
    int intFuses = GetInt(argv[4]);


   TwoArray arrFuses =InitFuse(intRows,intCols,intFuses);
   TwoArray arrStairwells = InitStairwells(intRows,intCols,intStairwells,arrFuses);

   bool blnContinue = true ;
   do
   {
      //OutputHouse(arrFuses,arrStairwells,  intRows,  intCols);
       system("cls");
       cout << "a) Up "<<endl
            << "b) Down "<<endl
            << "c) Left "<<endl
            << "d) Right "<<endl
            << "x) Exit "<<endl
            << "Selection : ";
            char chSelect ='\0';
            cin>>chSelect ;
           // if(cin.fail())
        switch(toupper(chSelect))
        {
        case 'a':
        case 'b':
        case 'c':
        case 'd':
            break ;
        case 'x':
            blnContinue = false ;
        default:
            cerr <<"Incorrect selection, please retry " <<endl ;
        }
   }while(blnContinue);
//    DeleteArray(arrFuses,intRows);
 //   DeleteArray(arrStairwells,intRows);
    return SUCCESS;
}
