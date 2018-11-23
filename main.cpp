#include <iostream>
#include <vector>
#include "logic.hpp"
#include <unistd.h>
#include <SFML/Graphics.hpp>

sf::RectangleShape rectangle(const int i, const int j)
{
    sf::RectangleShape rect(sf::Vector2f(12, 12));
    rect.setPosition(2 + 16 * j, 2 + 16 * i);
    rect.setFillColor(sf::Color::White);
    return rect;
}

void drawGrid(sf::RenderWindow &window, int worldSize)
{
    int numberLines = worldSize;

    for (int i = 0; i < numberLines; i++)
    {
        sf::Vertex verticalLines[]{
            sf::Vertex(sf::Vector2f(window.getSize().x / (numberLines + 1) * (i + 1), 0), sf::Color(100, 100, 100)),
            sf::Vertex(sf::Vector2f(window.getSize().x / (numberLines + 1) * (i + 1), window.getSize().y - 40), sf::Color(100, 100, 100))};

        window.draw(verticalLines, 2, sf::Lines);

        sf::Vertex horizontalLines[]{
            sf::Vertex(sf::Vector2f(0, window.getSize().y / (numberLines + 1) * (i + 1)), sf::Color(100, 100, 100)),
            sf::Vertex(sf::Vector2f(window.getSize().x, window.getSize().y / (numberLines + 1) * (i + 1)), sf::Color(100, 100, 100))};
        window.draw(horizontalLines, 2, sf::Lines);
    }
}

int main()
{
    constexpr int WORLDSIZE = 50;

    std::vector<std::vector<bool>> world = createworld(WORLDSIZE);
    std::vector<std::vector<bool>> nextWorld = world;

    //random seed
    for (int i = 0; i < WORLDSIZE; i++)
    {
        for (int j = 0; j < WORLDSIZE; j++)
        {
            double d = (double)(std::rand()) / RAND_MAX;
            if (d >= 0.6)
                world[i][j] = true;
            else
                world[i][j] = false;
        }
    }

    sf::RenderWindow window(sf::VideoMode(800, 840), "game-life", sf::Style::Titlebar | sf::Style::Close);
    int countGeneration(0);
    while (window.isOpen())
    {
        int Population(0);
        sf::Event event;
        countGeneration++;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        drawGrid(window, WORLDSIZE - 1);
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(0, 800), sf::Color(100, 100, 100)),
            sf::Vertex(sf::Vector2f(800, 800), sf::Color(100, 100, 100))};
        window.draw(line, 2, sf::Lines);
        sf::Font font;
        font.loadFromFile("arial.ttf");

        sf::Text textGeneranion;
        textGeneranion.setFillColor(sf::Color::White);
        textGeneranion.setFont(font);
        textGeneranion.setPosition(sf::Vector2f(0, 800));
        textGeneranion.setString("Generation: " + std::to_string(countGeneration));
        window.draw(textGeneranion);

        std::vector<std::vector<bool>> nextWorld = nextGen(world);
        for (int i = 0; i < WORLDSIZE; i++)
        {
            for (int j = 0; j < WORLDSIZE; j++)
            {
                if (world[i][j])
                {
                    window.draw(rectangle(i, j));
                    Population++;
                }
            }
        }
        world = nextWorld;

        sf::Text textLiveCell;
        textLiveCell.setFillColor(sf::Color::White);
        textLiveCell.setFont(font);
        textLiveCell.setPosition(sf::Vector2f(400, 800));
        textLiveCell.setString("Population: " + std::to_string(Population));
        window.draw(textLiveCell);
        usleep(50000);
        window.display();
    }
    return 0;
}