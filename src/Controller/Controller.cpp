#include "Controller.h"
#include "../View/World.h"
#include <thread>

namespace ctrl {

    Controller::Controller() {

    }

    Controller::Controller(const Controller &rhs) {

    }

    Controller &Controller::operator=(const Controller &rhs) {
        return *this;
    }

    Controller::~Controller() {

    }

    void Controller::addEntity(std::unique_ptr<model::Entity> modelEntity, std::unique_ptr<view::Entity> viewEntity) {
        m_entities[std::move(modelEntity)] = std::move(viewEntity);
    }

    void Controller::setShip(std::unique_ptr<model::Ship> modelShip, std::unique_ptr<view::Entity> viewShip) {
        m_ship = std::make_pair(std::move(modelShip), std::move(viewShip));
    }

    void Controller::control(view::World& world) {
        std::unique_ptr<Stopwatch> stopwatch (new Stopwatch());
        updateShip(m_ship.first, stopwatch);
        m_ship.second->draw(world, m_ship.first->getX(), m_ship.first->getY());
        for (auto& entityPair : m_entities) {

        }
    }

    void Controller::updateShip(std::unique_ptr<model::Ship>& ship, std::unique_ptr<Stopwatch>& stopwatch) {
        stopwatch->start();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            ship->move(model::LEFT);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            ship->move(model::RIGHT);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            ship->move(model::UP);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            ship->move(model::DOWN);
        }
        while (stopwatch->stop() < std::chrono::microseconds(30)) {

        }





    }


} //namespace ctrl