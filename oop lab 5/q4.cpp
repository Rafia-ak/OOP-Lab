#include <iostream>
#include <ctime>

using namespace std;

void customSleep(int seconds) {
    time_t start = time(0);
    while (time(0) - start < seconds);
}

class Blend {
public:
    void blendJuice() {
        cout << "Blending started...\n";
        cout << "Blending in progress...\n";
    	customSleep(4);
        cout << "Blending completed!\n";
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding started...\n";
        customSleep(5);
        cout << "Grinding completed!\n";
    }
};

class JuiceMaker {
    Blend blend;
    Grind grind;
public:
    void makeJuice() {
        blend.blendJuice();
        grind.grindJuice();
        cout << "Juice is ready!\n";
    }
};

int main() {
    JuiceMaker maker;
    maker.makeJuice();
    return 0;
}