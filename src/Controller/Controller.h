#ifndef GRADIUS_CONTROLLER_H
#define GRADIUS_CONTROLLER_H

#include "Stopwatch.h"
#include "../Model/Ship.h"
#include "../View/Entity.h"
#include <memory>
#include <map>

namespace ctrl {

    class Controller {
    public:
        Controller();

        Controller(const Controller &rhs);

        Controller &operator=(const Controller &rhs);

        ~Controller();

        void addEntity(std::unique_ptr<model::Entity> modelEntity, std::unique_ptr<view::Entity> viewEntity);

        void setShip(std::unique_ptr<model::Ship> modelShip, std::unique_ptr<view::Entity> viewShip);

        void control();

        void updateShip(std::unique_ptr<model::Ship>& ship, std::unique_ptr<Stopwatch>& stopwatch);

    private:
        std::map<std::unique_ptr<model::Entity>, std::unique_ptr<view::Entity>> m_entities;
        std::pair<std::unique_ptr<model::Ship>, std::unique_ptr<view::Entity>> m_ship;
    };

} //namespace ctrl

#endif //GRADIUS_CONTROLLER_H
