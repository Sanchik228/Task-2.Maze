#include <iostream>
#include <vector>
#include <random>

const char ROAD = ' ';
const char WALL = '#';

int rows, cols;
std::vector<std::vector<char>> maze;

void generateMaze(int x, int y) {
    maze[x][y] = ROAD;
    std::vector<int> dirs = { 0, 1, 2, 3 };

    std::shuffle(dirs.begin(), dirs.end(), std::default_random_engine(std::time(0)));


}

int main() {
    std::cout << "Enter maze size (rows cols): ";
    std::cin >> rows >> cols;

    maze = std::vector<std::vector<char>>(rows, std::vector<char>(cols, WALL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}