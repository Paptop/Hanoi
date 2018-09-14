#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#include "Tower.h"

typedef std::vector<std::string> Moves;

#define DEBUG 1

void MoveDisk(Tower* towers,
              int from,
              int to,
              Moves& moves)
{
#if DEBUG
    std::string move = std::to_string(from) + " -> " + std::to_string(to);
    moves.push_back(move);
#endif

    towers[to].PlaceOnTop(towers[from].Pop());
}

int main(int argc, char** argv)
{
    int disks = 0;
    std::cout << "------ HANOI TOWER -----\n";
    std::cout << " Enter number of disks : ";
    std::cin >> disks;
    while(!std::cin || disks < 0 || disks > 30)
    {
       std::cin.clear();
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
       std::cout << " Invalid disk number \n";
       std::cout << " Enter number of disks : ";
       std::cin >> disks;
    }

    Tower towers[3] = { {disks,"A"}, {disks,"B"}, {disks,"C"}};
    int dir;
    // index of tower with min disk on top
    int towerMin;
    int totalMoves = (1 << disks) - 1;
    int next[3] = {1, 2, 0};
    int prev[3] = {2, 0, 1};
    Moves moves;
    bool moveMin = true;

    disks % 2 == 0 ? dir = 1: dir = -1;
    towers[0].Prepare();

    for( int i = 0; i < totalMoves; ++i)
    {
       if(moveMin)
       {
          int from = towerMin;
          towerMin = (from + dir + 3) % 3;
          MoveDisk(towers,from,towerMin,moves);
       }
       else
       {
           if(towers[next[towerMin]].Top() > towers[prev[towerMin]].Top())
           {
              MoveDisk(towers, prev[towerMin],next[towerMin], moves);
           }
           else
           {
               MoveDisk(towers,next[towerMin],prev[towerMin], moves);
           }

       }
       moveMin = !moveMin;
    }


#if DEBUG
    for(std::string& str : moves)
    {
        std::cout << str << std::endl;
    }

    std::cout << "Total moves : " << moves.size() << std::endl;
#endif

    for(int i = 0 ; i < 3; ++i)
    {
        towers[i].PrintToConsole();
    }

    return 0;
}