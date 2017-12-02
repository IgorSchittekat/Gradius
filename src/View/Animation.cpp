#include "Animation.h"


Animation::Animation(const std::shared_ptr<sf::Texture>& texture, unsigned int imageCount, double switchTime) :
        m_imageCount(imageCount),
        m_currentImage(0),
        m_totalTime(0),
        m_switchTime(switchTime)
         {
    uvRect.width = texture->getSize().x / imageCount;
    uvRect.height = texture->getSize().y;
}

Animation::Animation(const Animation &rhs) {

}

Animation &Animation::operator=(const Animation &rhs) {
    return *this;
}

Animation::~Animation() {

}

void Animation::update(double deltaTime) {
    m_totalTime += deltaTime;
    if (m_totalTime <= m_switchTime) {
        m_totalTime -= m_switchTime;
        m_currentImage++;
        if (m_currentImage >= m_imageCount)
            m_currentImage = 0;
    }
    uvRect.left = m_currentImage * uvRect.width;
    uvRect.top = 0;
}