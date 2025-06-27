#include <iostream>
#include <vector>

int main() {
    int rows, cols;
    std::cout << "Enter maze size (rows cols): ";
    std::cin >> rows >> cols;

    std::vector<std::vector<char>> maze(rows, std::vector<char>(cols, '#'));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}