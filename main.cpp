#include <iostream>
#include <vector>
#include "logic.hpp"
#include <unistd.h>

void printWorld(const std::vector<std::vector<bool> > &world)
{
    for(int i = 0; i < world.size(); i++)
    {
        for(int j = 0; j<world[0].size(); j++)
        {
            if(world[i][j])
                std::cout<<"* ";
            else
                std::cout<<"0 ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
int main()
{
    std::vector<std::vector<bool> > world = createworld(10);
    world[0][1] = true;
    world[1][2] = true;
    world[2][0] = true;
    world[2][1] = true;
    world[2][2] = true;
    for (int i = 0; i < 100; i++)
    {
        std::vector<std::vector<bool> > nextWorld = nextGen(world);
        std::cout<<"generation "<<i+1<<std::endl;
        printWorld(world);
        world = nextWorld;
        usleep(200000);        
    }
    return 0;
}