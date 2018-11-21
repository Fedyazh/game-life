#include "logic.hpp"

std::vector<std::vector<bool> > createworld(int worldSize)
{
    std::vector<std::vector<bool> > world;
    for(int i = 0; i<worldSize; i++)
    {
        std::vector<bool> temp(worldSize, false);
        world.push_back(temp);
    }
    return world;
}
std::vector<std::vector<bool> > nextGen(const std::vector<std::vector<bool> > &world)
{
    std::vector<std::vector<bool> > nextGenWorld = createworld(world.size());
    for(int i = 0; i<world.size(); i++)
    {
        for(int j = 0; j<world[i].size(); j++)
        {
            nextGenWorld[i][j] = setCell(countNeighbour(world, i, j), world[i][j]);
        }
    }
    return nextGenWorld;
}
bool setCell(int count, bool cellStatus)
{
    if(cellStatus)
    {
        if(count == 2 || count == 3)
            return true;
        else 
            return false;
    }
    else
    {
        if(count == 3)
            return true;
        else
            return false;
    }
}
int countNeighbour(const std::vector<std::vector<bool> > &world, int i, int j)
{
    int count = 0;
    for(int I = i-1; I<=i+1; I++)
    {
        for(int J = j-1; J<=j+1; J++)
        {
            if(convertedWorld(world, I,J) && (I!=i || J!=j))
                count++;
        }
    }
    return count;
}
bool convertedWorld(const std::vector<std::vector<bool> > &world, int i, int j)
{
    int i1 = convertCoordinate(i, world.size());
    int j1 = convertCoordinate(j, world.size());
    return world[i1][j1];
}
int convertCoordinate(const int &coordinate, const int &maxLimit)
{
    if(coordinate>=maxLimit)
        return coordinate-maxLimit;
    else if (coordinate<0)
        return coordinate+maxLimit;
    else
        return coordinate;   
}





