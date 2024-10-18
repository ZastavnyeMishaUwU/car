#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Part {
public:
    string name; 
    vector<Part*> subParts; 


    Part(string name) : name(name) {}


    void addSubPart(Part* part) {
        subParts.push_back(part);
    }


    void print(int level = 0) {
        for (int i = 0; i < level; ++i)
            cout << "  "; 
        cout << "- " << name << endl;
        for (Part* subPart : subParts) {
            subPart->print(level + 1);
        }
    }


    ~Part() {
        for (Part* subPart : subParts) {
            delete subPart;
        }
    }
};

int main() {

    Part* car = new Part("Автомобіль");


    Part* engine = new Part("Двигун");
    Part* body = new Part("Кузов");
    Part* wheels = new Part("Колеса");

    car->addSubPart(engine);
    car->addSubPart(body);
    car->addSubPart(wheels);


    engine->addSubPart(new Part("Поршні"));
    engine->addSubPart(new Part("Клапани"));
    engine->addSubPart(new Part("Колінчастий вал"));


    body->addSubPart(new Part("Двері"));
    body->addSubPart(new Part("Вікна"));
    body->addSubPart(new Part("Сидіння"));


    wheels->addSubPart(new Part("Шини"));
    wheels->addSubPart(new Part("Диски"));


    car->print();


    delete car;

    return 0;
}
