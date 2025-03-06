#include<bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

const int GRID_SIZE = 20;
const int WIDTH = 800;
const int HEIGHT = 600;
const int SPEED_INCREMENT = 5;

struct SnakeSegment {
    int x, y;
};

class SnakeGame {
private:
    sf::RenderWindow window;
    std::vector<SnakeSegment> snake;
    SnakeSegment food;
    sf::Vector2i direction;
    sf::SoundBuffer eatBuffer, gameOverBuffer;
    sf::Sound eatSound, gameOverSound;
    sf::Font font;
    sf::Text scoreText;
    bool isGameOver;
    int score, speed;

public:
    SnakeGame() : window(sf::VideoMode(WIDTH, HEIGHT), "Snake Game"), direction(1, 0), isGameOver(false), score(0), speed(100) {
        snake.push_back({WIDTH / 2, HEIGHT / 2});
        spawnFood();
        loadResources();
    }

    void loadResources() {
        eatBuffer.loadFromFile("eat.wav");
        gameOverBuffer.loadFromFile("gameover.wav");
        eatSound.setBuffer(eatBuffer);
        gameOverSound.setBuffer(gameOverBuffer);
        font.loadFromFile("arial.ttf");
        scoreText.setFont(font);
        scoreText.setCharacterSize(24);
        scoreText.setFillColor(sf::Color::White);
    }

    void spawnFood() {
        food.x = (rand() % (WIDTH / GRID_SIZE)) * GRID_SIZE;
        food.y = (rand() % (HEIGHT / GRID_SIZE)) * GRID_SIZE;
    }

    void handleInput() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction.y == 0)
            direction = {0, -1};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction.y == 0)
            direction = {0, 1};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction.x == 0)
            direction = {-1, 0};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction.x == 0)
            direction = {1, 0};
    }

    void update() {
        if (isGameOver) return;
        SnakeSegment newHead = {snake[0].x + direction.x * GRID_SIZE, snake[0].y + direction.y * GRID_SIZE};
        
        if (newHead.x < 0 || newHead.x >= WIDTH || newHead.y < 0 || newHead.y >= HEIGHT) {
            gameOver();
            return;
        }

        for (const auto &segment : snake)
            if (newHead.x == segment.x && newHead.y == segment.y) {
                gameOver();
                return;
            }
        
        snake.insert(snake.begin(), newHead);
        
        if (newHead.x == food.x && newHead.y == food.y) {
            eatSound.play();
            score += 10;
            speed = std::max(50, speed - SPEED_INCREMENT);
            spawnFood();
        } else {
            snake.pop_back();
        }
        
        scoreText.setString("Score: " + std::to_string(score));
    }

    void gameOver() {
        gameOverSound.play();
        isGameOver = true;
    }

    void render() {
        window.clear();
        sf::RectangleShape segmentShape(sf::Vector2f(GRID_SIZE, GRID_SIZE));
        segmentShape.setFillColor(sf::Color::Green);
        for (const auto &segment : snake) {
            segmentShape.setPosition(segment.x, segment.y);
            window.draw(segmentShape);
        }
        sf::RectangleShape foodShape(sf::Vector2f(GRID_SIZE, GRID_SIZE));
        foodShape.setFillColor(sf::Color::Red);
        foodShape.setPosition(food.x, food.y);
        window.draw(foodShape);
        window.draw(scoreText);
        window.display();
    }

    void run() {
        sf::Clock clock;
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            handleInput();
            if (clock.getElapsedTime().asMilliseconds() >= speed) {
                update();
                render();
                clock.restart();
            }
        }
    }
};

int main() {
    srand(time(0));
    SnakeGame game;
    game.run();
    return 0;
}
