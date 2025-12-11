# Conway's Game of Life (C + Raylib)

A high-performance implementation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) built in C using the **Raylib** graphics library. This project features a fully interactive grid where users can draw patterns, pause the simulation, and randomize the board.

![Game Simulation running with random patterns]<img width="899" height="627" alt="paste 2" src="https://github.com/user-attachments/assets/835d33c7-2c3b-4ba3-9802-7aceba7deba1" />

## 🌟 Features
* **Interactive Editor:** Start with a blank grid. Left-click to draw living cells, Right-click to erase.
* **Simulation Controls:** Pause, Resume, and Step through generations with the Spacebar.
* **Random Generator:** Press 'R' to instantly fill the board with random "soup."
* **Optimized Rendering:** Runs efficiently using Raylib's hardware acceleration.
* **Grid Visualization:** Auto-adjusting grid lines to visualize dead cells vs. live cells.

![Blank Setup Mode for drawing patterns]<img width="901" height="624" alt="paste 1" src="https://github.com/user-attachments/assets/d471d1e4-0f94-47fe-80b9-0c02b131cb3d" />
*Screenshot: The interactive setup mode ready for user input.*

## 🛠️ Prerequisites
To build and run this project, you need:
1.  **w64devkit** (High-performance GCC compiler).
2.  **Raylib 5.0+** (MinGW version).

## 🚀 Installation & Setup

### 1. ⚠️ CRITICAL STEP: Toolchain Configuration
This project is configured with specific paths. **You must follow these installation steps exactly for the build to work.**

#### A. Install the Compiler (w64devkit)
1.  Download the latest **w64devkit** (zip file) from [GitHub Releases](https://github.com/skeeto/w64devkit/releases).
2.  Extract the folder.
3.  Rename the extracted folder to `w64devkit`.
4.  Move it to the root of your C: drive.
    * **Target Path:** `C:\w64devkit`

#### B. Install the Library (Raylib)
1.  Download **Raylib 5.0 (MinGW 64-bit)** from the [official releases](https://github.com/raysan5/raylib/releases).
2.  Extract the zip file.
3.  Rename the extracted folder to simply `raylib`.
4.  Move it to the root of your C: drive.
    * **Target Path:** `C:\raylib`
    * *Verify:* You should see `C:\raylib\include` and `C:\raylib\lib` inside.

### 2. Clone the Repository
```bash
git clone https://github.com/YourUsername/GameOfLife.git
cd GameOfLife
```

### 3. Build & Run

#### Option A: Using VS Code (Recommended)
This project includes a `.vscode/tasks.json` pre-configured for the paths above.
1.  Open the project folder in VS Code.
2.  Press `Ctrl + Shift + B` to Build and Run.

#### Option B: Using Code::Blocks
If you prefer using an IDE, follow these manual configuration steps:

1.  Open Code::Blocks and create a new **Console C Project**.
2.  **Configure Compiler:**
    * Go to `Settings` > `Compiler` > `Toolchain executables`.
    * Set the **Compiler's installation directory** to: `C:\w64devkit`
3.  **Configure Search Directories:**
    * Go to the `Search directories` tab.
    * Under **Compiler**, add: `C:\raylib\include`
    * Under **Linker**, add: `C:\raylib\lib`
4.  **Configure Linker Settings:**
    * Go to the `Linker settings` tab.
    * Under **Link libraries**, add these specific libraries in this **exact order**:
        * `raylib`
        * `opengl32`
        * `gdi32`
        * `winmm`
5.  Press `F9` to Build and Run.

#### Option C: Manual Terminal Build
If you have set your PATH correctly, you can run:

```cmd
C:\w64devkit\bin\gcc.exe main.c -o game.exe -O2 -Wall -I C:/raylib/include -L C:/raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm
./game.exe
```

## 🎮 Controls

| Key | Action |
| :--- | :--- |
| **SPACE** | Pause / Unpause Simulation |
| **R** | Reset Board (Randomize) |
| **C** | Clear Board (Kill All Cells) |
| **Left Click** | Draw Cell (Make Alive) |
| **Right Click** | Erase Cell (Make Dead) |
| **ESC** | Exit Game |

## 📜 License
This project is open-source. Feel free to modify and distribute it as needed for educational purposes.
