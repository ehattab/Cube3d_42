*This project has been created as part of the 42 curriculum by ehattab, toroman*


🧊 Cub3D

📝 Description

Cub3D is a graphics programming project inspired by the legendary 90s game Wolfenstein 3D, the first FPS ever created. The goal is to build a realistic 3D graphical representation of a maze from a first-person perspective using the Raycasting technique.

This project allows us to explore the mathematics behind 3D rendering (trigonometry, vector manipulation, matrix rotations) and pixel manipulation in C using the MiniLibX library.

🛠️ Instructions

Prerequisites (Linux)

Before starting, ensure you have the necessary system dependencies installed to run the MiniLibX library on Linux.

sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev


Installation

Follow these steps strictly to set up the project environment.

Clone the Repository:

git clone [https://github.com/ehattab/Cube3d_42.git](https://github.com/ehattab/Cube3d_42.git)

cd Cube3d_42


Install MiniLibX:
The project requires the MiniLibX library to be located in the utils folder.

git clone [https://github.com/42paris/minilibx-linux.git](https://github.com/42paris/minilibx-linux.git) utils/minilibx-linux


Compile MiniLibX:
You must compile the library once before building the main project.

make -C utils/minilibx-linux


Compilation

Once the library is ready, you can compile the cub3D executable:

make


Execution

To launch the game, you must provide a valid map file (ending with .cub) as an argument:

./cub3D maps/map.cub


🎮 Controls

Key

Action

W

Move Forward

S

Move Backward

A

Move Left (Strafe)

D

Move Right (Strafe)

⬅️

Rotate Camera Left

➡️

Rotate Camera Right

ESC

Quit the program

📚 Resources

References

The following resources were essential for the development of this project:

Developpez.com - Raycasting Principles

Used to understand the fundamental math and logic behind the Raycasting technique.

Lodev's Raycasting Tutorial

Used as the primary reference for implementing the DDA algorithm and Texture Mapping in C.

Raycasting in C (YouTube Tutorial)

Used to get hands-on experience with the initial project setup and basic rendering loop.

AI Usage

Generative AI tools were used to assist in the learning process and documentation for this project.

AI Tool Used: Gemini AI

Specific Usage:

Math & Algorithms: Gemini was used to clarify complex mathematical concepts (vectors, rotation matrices) and to explain specific parts of the raycasting logic.

Documentation: Gemini was used to help structure, format, and draft this README.md file to ensure clarity and compliance with the subject requirements.