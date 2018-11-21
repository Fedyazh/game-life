#ifndef LOGIC_HPP
#define LOGIC_HPP

#include<vector>

std::vector<std::vector<bool> > createworld(int worldSize);
std::vector<std::vector<bool> > nextGen(const std::vector<std::vector<bool> > &world);
bool setCell(int count, bool cellStatus);
int countNeighbour(const std::vector<std::vector<bool> > &world, int i, int j);
bool convertedWorld(const std::vector<std::vector<bool> > &world, int i, int j);
int convertCoordinate(const int &coordinate, const int &maxLimit);

#endif