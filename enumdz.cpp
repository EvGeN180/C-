#include <iostream>
#include <string>
using namespace std;

enum class State {
    Idle,
    Walking,
    Running,
    Jumping,
    Attacking,
    Dead
};

string stateToString(State s) {
    switch (s) {
    case State::Idle: return "Idle";
    case State::Walking: return "Walking";
    case State::Running: return "Running";
    case State::Jumping: return "Jumping";
    case State::Attacking: return "Attacking";
    case State::Dead: return "Dead";
    default: return "Unknown";
    }
}

class GameCharacter {
private:
    State curState;
    State prevState;
    int health;

public:
    GameCharacter() : curState(State::Idle), prevState(State::Idle), health(100) {}

    void setHealth(int h) {
        health = h;
        cout << "Health set to " << health << endl;
        if (health <= 0) {
            changeState(State::Dead);
        }
    }

    void takeDamage(int damage) {
        health -= damage;
        cout  << damage << " damage. Health: " << health << endl;
        if (health <= 0) {
            changeState(State::Dead);
        }
    }

    void changeState(State newState) {
        if (curState == State::Dead) {
            cout << "Dead!"<<endl;
            return;
        }

        if (newState == State::Jumping &&
            !(curState == State::Walking || curState == State::Running)) {
            cout << "Cant jump"<<endl;
            return;
        }

        prevState = curState;
        curState = newState;
        cout  << stateToString(curState) << endl;
    }

    void attack() {
        if (curState == State::Dead) {
            cout << "Dead!"<<endl;
            return;
        }

        cout << "Attacking!"<<endl;
        prevState = curState;
        curState = State::Attacking;
        cout << "State  Attacking"<<endl;

        if (prevState != State::Dead) {
            curState = prevState;
            cout << "Returned to previous state: " << stateToString(curState) << endl;
        }
    }

    void printState() {
        cout << "Current State: " << stateToString(curState)<< "  Health: " << health << endl;
    }
};

int main() {
    GameCharacter hero;

    hero.printState();
    hero.changeState(State::Walking);
    hero.changeState(State::Jumping);
    hero.attack();
    hero.changeState(State::Idle);
    hero.attack();
}