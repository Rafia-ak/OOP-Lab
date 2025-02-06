#include<iostream>
#include<vector>
using namespace std;

struct Person {
    int id;
    string name;
};

bool compareByID(Person &a, Person &b) {
    return a.id > b.id;
}

bool compareByName(Person &a, Person &b) {
    return a.name > b.name;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Please provide the number of people as the first argument." << endl;
        return 1;
    }

    int N = atoi(argv[1]);
    if (argc != 2 + 2 * N) {
        cout << "Incorrect number of arguments." << endl;
        return 1;
    }

    vector<Person> people(N);
    int index = 2;
    for (int i = 0; i < N; i++) {
        people[i].id = atoi(argv[index++]);
        people[i].name = argv[index++];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (compareByID(people[i], people[j])) {
                swap(people[i], people[j]);
            }
        }
    }

    cout << "\nSorted by ID:\n";
    for (int i = 0; i < N; i++) {
        cout << people[i].id << " " << people[i].name << endl;
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (compareByName(people[i], people[j])) {
                swap(people[i], people[j]);
            }
        }
    }

    cout << "\nSorted by Name:\n";
    for (int i = 0; i < N; i++) {
        cout << people[i].id << " " << people[i].name << endl;
    }

    return 0;
}

