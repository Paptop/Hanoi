#include "Tower.h"
#include <algorithm>
#include <iostream>
#include <cassert>
#define MAX_INT 2147483647

Tower::Tower(int size, std::string name)
: m_size(size)
, m_name(name)
{
    m_tower.reserve(size);
}

void Tower::Prepare()
{
    for(int i = 0; i < m_size; ++i)
    {
       m_tower.push_back(m_size - i);
    }
}

void Tower::PlaceOnTop(int value)
{
    if(!m_tower.empty())
    {
        int topValue = m_tower.front();
        assert(value < topValue);
    }

    m_tower.push_back(value);
}

void Tower::PrintToConsole()
{
    std::cout << "--" << m_name << "--" << std::endl;
    for_each(m_tower.rbegin(),m_tower.rend(),[](int i){
        std::cout << "[" << i << "]" << std::endl;
    });
    std::cout << "-----" <<  std::endl;
}

int Tower::Top()
{
    if(m_tower.empty())
    {
        return MAX_INT;
    }
    return m_tower.back();
}

int Tower::Pop()
{
    int res = m_tower.back();
    m_tower.pop_back();
    return res;
}
