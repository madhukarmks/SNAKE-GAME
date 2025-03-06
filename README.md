##A GRAPHICAL SNAKE GAME
USING LIBRARIES LIKE SFML OR SDL.
*COMPANY*: CODETECH IT SOLUTIONS

*NAME*: MADHUKAR KUMAR

*INTERN ID*: CT6WOZM

*DOMAIN*: C++ PROGRAMMING

DURATION: 6 WEEEKS

*MENTOR*: NEELA SANTOSH KUMAR

**Overview**

This C++ program implements a classic Snake Game using the SFML (Simple and Fast Multimedia Library) for graphics and audio. The game features a snake that moves around a grid, eating food to grow longer while avoiding collisions with itself or the screen boundaries. The game speeds up as the player scores points, and sound effects are played for eating food and game-over events.

**Key Components of the Code**

1. Libraries Used
   
#include<bits/stdc++.h> – Includes all standard C++ libraries for general-purpose functionality.
#include <SFML/Graphics.hpp> – Used for rendering the game's graphics (snake, food, text, etc.).
#include <SFML/Audio.hpp> – Used for handling sound effects (eating food and game over).
Other standard libraries like <vector>, <cstdlib>, and <ctime> for managing data structures, randomization, and time-based events.

3. Constants and Global Variables
   
GRID_SIZE = 20 – Defines the size of each cell in the grid where the snake and food are placed.
WIDTH = 800, HEIGHT = 600 – Specifies the window size.
SPEED_INCREMENT = 5 – Controls how much the game speed increases when the snake eats food.
5. Snake Segment Structure
The struct SnakeSegment defines a single unit of the snake’s body, consisting of two integer values (x and y) representing its position on the grid.

6. SnakeGame Class
   
The SnakeGame class encapsulates the game logic, rendering, and event handling.

4.1 Member Variables

window – The SFML window where the game is rendered.
snake – A vector of SnakeSegment objects representing the snake's body.
food – A SnakeSegment representing the position of the food.
direction – A sf::Vector2i that stores the current movement direction of the snake.
eatSound & gameOverSound – Sound effects for eating food and game-over scenarios.
font & scoreText – Used to display the player's score.
isGameOver – Boolean flag to indicate if the game has ended.
score – Stores the current score.
speed – Controls how fast the snake moves, decreasing as the score increases.

5. Class Methods
   
5.1 Constructor (SnakeGame())

Initializes the game window.
Sets the initial direction of movement.
Initializes the snake at the center of the screen.
Spawns the first piece of food.
Loads game assets (sounds and fonts).

5.2 loadResources()

Loads sound files for eating (eat.wav) and game-over (gameover.wav).
Loads a font (arial.ttf) to display the score on the screen.

5.3 spawnFood()

Randomly places the food at a valid grid position.
Uses rand() to ensure the food appears within the game boundaries.
5.4 handleInput()
Detects keyboard input (Arrow Keys) to change the snake's movement direction.
Prevents the snake from reversing directly (e.g., it cannot move left if currently moving right).

5.5 update()

Handles the game's core logic:

Moves the snake forward by adding a new head segment in the current direction.
Checks for collisions with walls or itself—if detected, the game ends.
If the snake eats food:
Plays the eating sound.
Increases the score.
Decreases the speed (making the game harder).
Spawns a new piece of food.
If food is not eaten, the last segment of the snake is removed to maintain its length.
Updates the score text for rendering.

5.6 gameOver()

Plays the game-over sound.
Sets isGameOver = true, stopping further movement.

5.7 render()

Clears the window.
Draws the snake (green rectangles).
Draws the food (red rectangle).
Displays the score text.
Refreshes the window to show updates.

5.8 run()

The main game loop:

Runs continuously while the window is open.
Handles user input (e.g., closing the window).
Updates the game logic periodically based on the elapsed time (sf::Clock).
Calls render() to draw the updated game state.

6. main() Function
   
Initializes the random seed using srand(time(0)).
Creates a SnakeGame object.
Calls game.run(), starting the game loop.

**Gameplay and Features**

✅ Basic Snake Movement – The snake moves continuously in one direction and changes direction based on user input.
✅ Food Collection – The snake grows when it eats food, and the score increases.
✅ Game Over Conditions – The game ends when the snake collides with the wall or itself.
✅ Sound Effects – Eating food and game-over events are accompanied by sound effects.
✅ Increasing Difficulty – The snake moves faster as the score increases.
✅ Simple UI – The score is displayed in real-time.

**Possible Improvements**

Restart Mechanism – Allow players to restart after game over.
More Visual Effects – Smooth animations or a more stylized snake design.
High Score Tracking – Save and display the highest score achieved.
Obstacle Mode – Introduce obstacles for an extra challenge.

**Conclusion**

This SFML-based Snake Game is a well-structured implementation of a classic game using C++ and object-oriented programming. It efficiently handles game logic, rendering, and user interaction, making it a great project for learning game development with SFML.

