# Conway's Game of Life (C + Raylib)

A high-performance implementation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) built in C using the **Raylib** graphics library. This project features a fully interactive grid where users can draw patterns, pause the simulation, and randomize the board.

![Game Screenshot](https://via.placeholder.com/800x450?text=Add+Your+Screenshot+Here)
## 🌟 Features
* **Interactive Editor:** Left-click to draw living cells, Right-click to erase.
* **Simulation Controls:** Pause, Resume, and Step through generations.
* **Random Generator:** Instantly fill the board with random "soup."
* **Optimized Rendering:** Runs efficiently using Raylib's hardware acceleration.
* **Grid Visualization:** Auto-adjusting grid lines to visualize dead cells vs. live cells.

## 🛠️ Prerequisites
To build and run this project, you need:
1.  **w64devkit** (High-performance GCC compiler).
2.  **Raylib 5.0+** (MinGW version).

## 🚀 Installation & Setup

### 1. ⚠️ CRITICAL STEP: Toolchain Configuration
This project is configured with specific paths in `.vscode/tasks.json`. **You must follow these installation steps exactly for the build to work.**

#### A. Install the Compiler (w64devkit)
1.  Download the latest **w64devkit** (zip file) from [GitHub Releases](https://github.com/skeeto/w64devkit/releases).
2.  Extract the folder.
3.  Rename the extracted folder to `w64devkit`.
4.  Move it to the root of your C: drive.
    * **Target Path:** `C:\w64devkit`
    * *Verify:* You should see `C:\w64devkit\bin\gcc.exe`.

#### B. Install the Library (Raylib)
1.  Download **Raylib 5.0 (MinGW 64-bit)** from the [official releases](https://github.com/raysan5/raylib/releases).
2.  Extract the zip file.
3.  Rename the extracted folder to simply `raylib`.
4.  Move it to the root of your C: drive.
    * **Target Path:** `C:\raylib`
    * *Verify:* You should see `C:\raylib\include` and `C:\raylib\lib` inside.

### 2. Clone the Repository
```bash
git clone [https://github.com/ridwanurrhmn/GameOfLife.git](https://github.com/ridwanurrhmn/GameOfLife.git)
cd GameOfLife
