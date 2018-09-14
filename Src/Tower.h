#ifndef TOWERHANOI_TOWER_H
#define TOWERHANOI_TOWER_H
#include <vector>
#include <string>

typedef unsigned int u32;

class Tower
{
public:
    Tower(int size, std::string name);

    void PlaceOnTop(int value);
    void Prepare();
    int  Top();
    int  Pop();
    void PrintToConsole();

private:
    const u32 m_size;
    std::string m_name;
    std::vector<int> m_tower;
};


#endif //TOWERHANOI_TOWER_H
