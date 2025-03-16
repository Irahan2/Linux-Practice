#include <iostream>
#include <iomanip>

int main() {
    int n;

    std::cout << " Enter a number: ";
    std::cin >> n;

    std::cout << "\nGenerating your triangle...\n\n";

    for (int i = 1; i <= n; i++) {
        std::cout << std::setw(n - i + 1);
        for (int j = 1; j <= (2 * i - 1); j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << "\n Triangle complete! \n";

    return 0;
}
