#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>

const char ROAD = ' ';
const char WALL = '#';

int rows, cols;
std::vector<std::vector<char>> maze;

const int dx[] = { -2, 2, 0 ,0 };
const int dy[] = { 0, 0, -2, 2 };

bool isValid(int x, int y) {
    return x > 0 && x < rows - 1 && y > 0 && y < cols - 1 && maze[x][y] == WALL;
}

void generateMaze(int x, int y, std::mt19937& rng) {
    maze[x][y] = ROAD;
    std::vector<int> dirs = { 0, 1, 2, 3 };

    std::shuffle(dirs.begin(), dirs.end(), rng);

    for (int i : dirs) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny)) {
            maze[x + dx[i] / 2][y + dy[i] / 2] = ROAD;
            generateMaze(nx, ny, rng);
        }
    }
}

int main() {
    std::cout << "Enter maze size (rows cols): ";
    std::cin >> rows >> cols;

    if (rows % 2 == 0) rows += 1;
    if (cols % 2 == 0) cols += 1;

    maze = std::vector<std::vector<char>>(rows, std::vector<char>(cols, WALL));

    std::mt19937 rng(std::random_device{}());
    generateMaze(1, 1, rng);

    bool enterPleced = false;
    for (int i = 1; i < cols && !enterPleced; i++) {
        if (maze[1][i] == ROAD) {
            maze[0][i] = 'E';
            enterPleced = true;
        }
    }
    for (int i = 1; i < rows && !enterPleced; i++) {
        if (maze[i][1] == ROAD) {
            maze[i][0] = 'E';
            enterPleced = true;
        }
    }

    bool exitPlaced = false;
    for (int i = cols - 2; i > 0 && !exitPlaced; i--) {
        if (maze[rows - 2][i] == ROAD) {
            maze[rows - 1][i] = 'X';
            exitPlaced = true;
        }
    }
    for (int i = rows - 2; i > 0 && !exitPlaced; i--) {
        if (maze[i][cols - 2] == ROAD) {
            maze[i][cols - 1] = 'X';
            exitPlaced = true;
        }
    }

    std::vector<std::pair<int, int>> freeCels;

    for (int i = 1; i < rows - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {
            if (maze[i][j] == ROAD) {
                freeCels.emplace_back(i, j);
            }
        }
    }
    if (!freeCels.empty()) {
        std::pair<int, int> treasure;
        std::sample(freeCels.begin(), freeCels.end(), &treasure, 1, rng);
        auto [x, y] = treasure;
        maze[x][y] = '$';

        freeCels.erase(std::remove(freeCels.begin(), freeCels.end(), treasure), freeCels.end());

        std::srand(std::time(0));
        int trapCount = std::min(std::rand() % 6, static_cast<int>(freeCels.size()));

        std::vector<std::pair<int, int>> traps(trapCount);
        std::sample(freeCels.begin(), freeCels.end(), traps.begin(), trapCount, rng);

        for (auto [x, y] : traps) {
            maze[x][y] = 'T';
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}