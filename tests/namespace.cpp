#include <iostream>

// First namespace
namespace FirstNamespace {
    void display() {
        std::cout << "Inside FirstNamespace" << std::endl;
    }
	int a = 1;
}

// Second namespace
namespace SecondNamespace {
    void display() {
        std::cout << "Inside SecondNamespace" << std::endl;
    }
}

int main() {
    // Call function from FirstNamespace
    FirstNamespace::display();

    // Call function from SecondNamespace
    SecondNamespace::display();

	int a = 0;
	printf("::a=%d,FirstNamespace::a=%d\n",a, FirstNamespace::a);
    return 0;
}

