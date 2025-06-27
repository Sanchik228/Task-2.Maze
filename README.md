# Task #2.Maze

Description:
This is a C++ console program that generates a random 2D maze based on user input size. The maze consists of the following cell types:
'E' — Entrance (placed randomly on the outer edge);
'X' — Exit (placed randomly on the outer edge);
'#' — Wall (impassable);
' '(space) — Road (passable path);
'$' — Treasure (placed on a reachable road cell);
'T' — Trap (0 to 5 traps placed randomly on road cells);
The program uses a recursive depth-first search (DFS) algorithm to carve out the maze paths.

How to run:
- run the code;
- enter maze's rows and cols;
- The program outputs the maze in the console with different symbols representing different cell types.

How It Works:
The maze is initialized as a grid full of walls (#).
Starting from position (1,1), the program recursively carves out paths ( ) using DFS with random direction shuffling.
Entrance (E) and exit (X) are placed on the edges, ensuring accessibility.
A treasure ($) is randomly placed on one of the free road cells.
0 to 5 traps (T) are randomly placed on remaining free road cells, excluding the treasure location.
The maze is printed to the console.

Maze Generation Algorithm:
The maze generation uses recursive DFS with backtracking:
Each cell is visited once and carved from wall to road.
The recursion explores neighbors in random order to create a randomized maze.

Time Complexity:
The DFS visits each cell at most once, so the time complexity is O(rows * cols).

Space Complexity:
The space needed is mainly for the maze storage (2D vector) and recursion stack. 
The maze storage requires O(rows * cols) space. The recursion depth can be up to O(rows * cols) in the worst case but is typically less.

Placing Treasure and Traps
We iterate over all cells to find free road cells, which is O(rows * cols).

Random sampling of treasure and traps is O(k) where k ≤ 5 (constant), negligible compared to maze size.