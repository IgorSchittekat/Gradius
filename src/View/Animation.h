#ifndef GRADIUS_ANIMATION_H
#define GRADIUS_ANIMATION_H
#pragma once


#include <SFML/Graphics.hpp>

class Animation {
public:
    Animation(const std::shared_ptr<sf::Texture>& texture, unsigned int imageCount, double totalTime);

    Animation(const Animation &rhs);

    Animation &operator=(const Animation &rhs);

    ~Animation();

    void update(double deltaTime);

public:
    sf::IntRect uvRect;

private:
    unsigned int m_imageCount;
    unsigned int m_currentImage;
    double m_totalTime;
    double m_switchTime;
};


#endif //GRADIUS_ANIMATION_H
