#ifndef QRGAME_LOGIC_H
#define QRGAME_LOGIC_H

#include "../InputManager.h"
#include "Player.h"
#include "Wall.h"

#include <random>
#include <iostream>

class Logic {
private:
    const int wallsGap = 30;
    const double playerSpeed = 10;
    int score = 0;
    Player player = Player(1, 1);
    std::vector<Wall> walls;
    std::random_device rd;

public:
    Logic() = default;

    void initialize(int height, int width) {
        walls.clear();
        score = 0;
        player.setX(width / 4);
        player.setY(height / 2 - player.getSprite().sprite.size() / 2);
        for (int i = 0; i < width / wallsGap + 1; ++i) {
            walls.emplace_back(Wall());
            walls[i].setX(width + i * wallsGap);
            std::uniform_real_distribution<> dis(0, (double) (height - walls[i].getGapHeight()) / height);
            std::mt19937 gen(rd());
            walls[i].setHeight(dis(gen));
        }
    }

    void update(double movement, int height, int width, double deltaTime) {

        // Move player
        player.setY(movement * (height - 2 - player.getSprite().sprite.size()) + 1);

        // Move walls
        for (auto &wall : walls) {
            if (wall.getX() <= 0) {
                std::uniform_real_distribution<> dis(0, (double) (height - wall.getGapHeight()) / height);
                std::mt19937 gen(rd());
                wall.setX(walls.size() * wallsGap);
                wall.setHeight(dis(gen));
                wall.setCounted(false);
            } else {
                wall.setX(wall.getX() - playerSpeed * deltaTime);
                // Update score
                if (wall.getX() + wall.getWidth() < player.getX() && !wall.isCounted()) {
                    ++score;
                    wall.setCounted(true);
                }
                // Check collision
                if (wall.getX() < player.getX() + player.getSprite().length && wall.getX() >= player.getX() ||
                    wall.getX() + wall.getWidth() < player.getX() + player.getSprite().length &&
                    wall.getX() + wall.getWidth() >= player.getX()) {
                    // Reset game if needed
                    if (player.getY() < wall.getHeight() * height - 1 ||
                        player.getY() + player.getSprite().sprite.size() >=
                        wall.getHeight() * height + wall.getGapHeight()) {
                        this->initialize(height, width);
                    }
                }
            }
        }
    }

    int getScore() const {
        return score;
    }

    Player &getPlayer() {
        return player;
    }

    const std::vector<Wall> &getWalls() const {
        return walls;
    }

};


#endif //QRGAME_LOGIC_H
