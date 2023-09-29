# cub3D_42
- My First RayCaster with miniLibX

This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.
<img width="1498" alt="Screen Shot 2023-02-19 at 6 21 21 PM" src="https://user-images.githubusercontent.com/90983110/219964068-2e1badb4-0d79-4bc7-bd01-4a02bf54d895.png">

# Foreword
<br>
Developed by Id Software by the über famous John Carmack and John Romero, published in 1992 by Apogee Software, Wolfenstein 3D is the first true “First Person
Shooter” in the history of video games.
<br>
<img width="303" alt="Screen Shot 2023-02-26 at 6 54 35 PM" src="https://user-images.githubusercontent.com/90983110/221427544-8dd357aa-a148-485c-8b09-5167ab2071c2.png">
<br>
Wolfenstein 3D is the ancestor of games like Doom (Id Software, 1993), Doom II
(Id Software, 1994), Duke Nukem 3D (3D Realm, 1996) and Quake (Id Software, 1996),
that are additional eternal milestones in the world of video games.
<br>

## Overview
<br>
cub3D is a first-person perspective maze exploration game inspired by the iconic Wolfenstein 3D. This project allows you to dive into the world of raycasting and create a dynamic 3D view inside a maze. The game is developed in C and utilizes the miniLibX graphics library.
<br>

# Features

- Realistic 3D graphical representation of a maze.
- Smooth window management (e.g., changing windows, minimizing).
- Different wall textures based on orientation (North, South, East, West).
- Customizable floor and ceiling colors.
- Player movement using W, A, S, D keys.
- Player orientation with left and right arrow keys.
- Interactive minimap.
- Doors that can open and close.
- Animated sprites.
- Mouse-based point of view rotation.

<br>

### Prerequisites

- C compiler
- miniLibX graphics library

### Building and Running

1. install readline (brew install readline) for Mac OS
  
3. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/cub3D.git
   ```

4.Compile the project:
 
  ```bash
  make && make bounus
  ```
5.Run the game with a scene description file (e.g, `maps/map.cub`):
  
  ```bash
  ./cub3D_bonus maps/map.cub
  ```

##



  


https://user-images.githubusercontent.com/90983110/222911803-cf19f3d0-4acf-4f57-a01f-11fe9533e010.mov
