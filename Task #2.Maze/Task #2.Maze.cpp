#include <iostream>
#include <vector>
#include <random>

const char ROAD = ' ';
const char WALL = '#';

int rows, cols;
std::vector<std::vector<char>> maze;

const int dx[] = { -2, 2, 0 ,0 };
const int dy[] = { 0, 0, -2, 2 };

bool isValid(int x, int y) {
    return x > 0 && x < rows - 1 && y > 0 && y < cols - 1 && maze[x][y] == WALL;
}

void generateMaze(int x, int y) {
    maze[x][y] = ROAD;
    std::vector<int> dirs = { 0, 1, 2, 3 };

    std::shuffle(dirs.begin(), dirs.end(), std::default_random_engine(std::time(0)));

    for (int i : dirs) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny)) {
            maze[x + dx[i] / 2][y + dy[i] / 2] = ROAD;
            generateMaze(nx, ny);
        }
    }
}

int main() {
    std::cout << "Enter maze size (rows cols): ";
    std::cin >> rows >> cols;

    if (rows % 2 == 0) rows += 1;
    if (cols % 2 == 0) cols += 1;

    maze = std::vector<std::vector<char>>(rows, std::vector<char>(cols, WALL));

    generateMaze(1, 1);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}