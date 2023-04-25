#include "LibHouses.h"
namespace DarkSpace
{
   int GetInt(string strInt)
   {
       int intNum = 0 ;
       stringstream ss{strInt} ;
       ss>>intNum ;

       if(ss.fail())
       {
           cerr << "Could not convert string into an integer "<<endl;
           exit(ERROR_CONVERSION);
       }

       return intNum ;
   }
   TwoArray MemoryAllocation (int intRows , int intCols)
   {
       TwoArray arrInts ;
       arrInts =  new OneArray [intRows];

       for(int r = 0 ;r<intRows ;r++)
       {
           arrInts[r]= new int [intCols];
       }

       return arrInts ;
   }
   bool IsInWorld (int intRows, int intCols, int intRow, int intCol)
   {
       return (intRow >=0 && intRow < intRows && intCol >=0 && intCol < intCols);
   }

   void FindPlayer(TwoArray arrFuses, int intRows, int intCols, int &intPRow, int&intPCol)
   {
      intPRow = -1;
      intPCol = -1;
       for(int r=0;r<intRows;r++)
            {
                 for(int c=0;c<intCols;c++)
                 {
                      if(arrFuses[r][c]==VAL_PLAYER)
                       {
                           intPRow = r;
                           intPCol = c;
                            return;
                        }
                }
            }
  }
  int GetRand(int intLower, int intUpper)
  {
      assert(intUpper>intLower) ;
      int intRange= intUpper - intLower +1 ;
      return rand()%intRange+intLower ;
  }
  void PlaceFeauture(TwoArray arrNums, int intRows , int intCols , int intFeauture , int intPRow , int intPCol)
  {
      int intRow = GetRand(0,intRows-1);
      int intCol = GetRand(0,intCols-1 );

      bool blnPlayerLocation = false ;
      if (intRow==intPRow && intCol==intPCol)
        blnPlayerLocation = true ;

      while(arrNums[intRow][intCol]!= VAL_SPACE || blnPlayerLocation!=false)
      {

          intRow = GetRand(0,intRows-1 );
          intCol = GetRand(0,intCols-1 );
          if(intRow == intPRow && intCol == intPCol)
              blnPlayerLocation= true ;
          else
            blnPlayerLocation = false ;

      }

      arrNums[intRow][intCol]=intFeauture ;


  }
  TwoArray InitFuse(int intRows , int intCols , int intFuseCount)
  {
      TwoArray arrFuse = MemoryAllocation(intRows,intCols);
      for(int r = 0 ; r<intRows ; r++)
      {
          for(int c = 0 ; c<intCols ; c++)
          {
              arrFuse[r][c] = VAL_SPACE ;
          }
      }
      int intPRow = GetRand(0,intRows-1) ;
      int intPCol = GetRand(0,1) ;
      arrFuse[intPRow][intPCol] = VAL_PLAYER ;

      PlaceFeauture(arrFuse, intRows,intCols,VAL_FUSE,intPRow,intPCol);
      PlaceFeauture(arrFuse,intRows,intCols,VAL_FUSEBOX,intPRow,intPCol);
      PlaceFeauture(arrFuse,intRows,intCols,VAL_DARKNESS,intRows,intPCol);
      PlaceFeauture(arrFuse,intRows,intCols,VAL_TORCH_CABINET,intRows,intPCol);
      PlaceFeauture(arrFuse,intRows,intCols,VAL_WALLS,intRows,intPCol);

      return arrFuse ;
  }
  TwoArray InitStairwells(int intRows , int intCols ,int intStairwells , TwoArray arrFuses)
  {

      assert(arrFuses!=nullptr);
      TwoArray arrStairwells = MemoryAllocation(intRows,intCols) ;
      for(int r = 0 ; r<intRows ; r++)
      {
          for(int c = 0 ; c<intCols ;c++)
          {
              arrStairwells[r][c] = VAL_STAIRWELLS ;
          }
      }

      int intPRow ;
      int intPCol ;
      FindPlayer(arrFuses, intRows, intCols,intPRow,intPCol);
      assert(intPRow=-1);
      assert(intPCol=-1);


            PlaceFeauture(arrStairwells,intRows,intCols,VAL_STAIRWELLS,intPRow,intPCol);


      return arrStairwells ;
  }

  void DeleteArray(TwoArray &arrNums , int intRows )
  {
      for (int r = 0 ; r<intRows ; r++)
      {
          delete[] arrNums[r];
      }
      delete[] arrNums;
      arrNums = nullptr ;
  }
  void OutputHouse(TwoArray arrFuses,TwoArray arrStairwells, int intRows, int intCols)
  {
      for(int r = 0 ; r<intRows ;r++)
      {
          for(int c = 0 ; c<intCols ;c++)
          {
           if(arrFuses[r][c]== VAL_PLAYER)
            cout << CH_PLAYER ;


            else
            {
                if(arrStairwells[r][c]==VAL_FUSE)
                    cout << CH_FUSE ;
                else
                   cout << CH_SPACE ;
            }
            cout << " " ;
          }
          cout <<endl;
      }
  }


}
