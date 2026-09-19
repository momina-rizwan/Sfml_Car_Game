# 2D Ball Collecting Game

A C++ 2D arcade game built using **Visual Studio** and **SFML (Simple and Fast Multimedia Library)**[cite: 20, 23].

## 🎮 Gameplay
In this game, you control a car to collect falling green balls while avoiding missing them[cite: 23].
* **Collect Balls:** Move your vehicle using keyboard controls to catch falling green targets[cite: 23].
* **Game Over:** If any ball falls past the bottom of the screen, the game ends and displays a Game Over screen[cite: 23].
* **Score Counter:** Tracks total balls collected in real-time on screen[cite: 23].

---

## 🕹️ Controls
* **W**: Move Up[cite: 23]
* **A**: Move Left[cite: 23]
* **S**: Move Down[cite: 23]
* **D**: Move Right[cite: 23]

---

## 📁 Project Structure
* `Source.cpp`: Contains main game logic, movement handling, collision detection, and score rendering[cite: 23].
* `Project1.sln` & `Project1.vcxproj`: Visual Studio solution and project configurations[cite: 19, 20].
* `pr.png`, `pr2.jpg`, `pr3.png`, `END.png`: Game road background, car sprite, and game over screen graphics[cite: 14, 16, 17, 18, 23].
* `Hibo.otf`: Custom font used for rendering the score text on screen[cite: 15, 23].

---

## ⚙️ How to Build and Run
1. Clone this repository to your computer.
2. Open `Project1.sln` in **Visual Studio 2022**[cite: 19].
3. Ensure **SFML 2.x** is installed and configured in project properties (Graphics, Window, and System modules)[cite: 20].
4. Set solution configuration to **Debug** or **Release** (x86 or x64)[cite: 19, 20].
5. Build and run the project (`F5`).
