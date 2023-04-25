#ifndef LIBHOUSES_H
#define LIBHOUSES_H
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;
namespace DarkSpace
{
    const int ERROR_CONVERSION = -1 ;
    const int ERROR_ARGC = -2 ;
    const int ERROR_RANGE = -3 ;
    const int ERROR_MOVEMENT = -4 ;
    const int SUCCESS = 0 ;

    const int VAL_PLAYER = 1 ;
    const int VAL_SPACE = 0 ;
    const int VAL_FUSE = 2 ;
    const int VAL_TORCH_CABINET = 3 ;
    const int VAL_DARKNESS = 4 ;
    const int VAL_FUSEBOX = 5 ;
    const int VAL_WALLS = 6 ;
    const int VAL_STAIRWELLS = 7 ;

    const char CH_PLAYER = 'P';
    const char CH_SPACE =' ';
    const char CH_FUSE = '#';
    const char CH_TORCH_CABINET = '+';
    const char CH_DARKNESS ='.';
    const char CH_FUSEBOX = '*';
    const char CH_WALLS ='^';
    const char CH_STAIRWELLS = '-';

    typedef* OneArray ;
    typedef** TwoArray ;

    int GetInt(string strInt);
    TwoArray InitFuse(int intRows , int intCols , int intFuseCount);
    TwoArray InitStairwells(int intRows , int intCols ,int intStairwells , TwoArray arrFuses);
    void DeleteArray(TwoArray &arrNums , int intRows );
    void OutputHouse(TwoArray arrFuses,TwoArray arrStairwells, int intRows, int intCols);






}


#endif // LIBHOUSES_H
