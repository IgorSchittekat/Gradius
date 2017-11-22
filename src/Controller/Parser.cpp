#include "Parser.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>

using json = nlohmann::json;

namespace ctrl {

    view::World* Parser::parseWorld() {
        json data;
        std::ifstream JSON("../bin/resources/Game.json");
        if (JSON.is_open()) {
            JSON >> data;
            JSON.close();
        }
        else {
            return nullptr; //TODO: Exception
        }
        unsigned int width = data["window"]["width"];
        unsigned int height = data["window"]["height"];
        std::string title = data["window"]["title"];
        std::string background = data["window"]["background"];
        view::World* world = new view::World(sf::VideoMode(width, height), title, background);

        std::unique_ptr<ctrl::Controller> controller (new ctrl::Controller());

        unsigned int lives = data["ship"]["lives"];
        std::string shipTexture = data["ship"]["texture"];
        double speed = data["ship"]["speed"];
        std::unique_ptr<view::Entity> viewShip (new view::Entity(shipTexture));
        std::unique_ptr<model::Ship> modelShip (new model::Ship(lives, speed));

        controller->setShip(std::move(modelShip), std::move(viewShip));




        world->setController(std::move(controller));
        return world;

    }





} //namespace ctrl
