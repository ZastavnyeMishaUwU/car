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

    Part* car = new Part("���������");


    Part* engine = new Part("������");
    Part* body = new Part("�����");
    Part* wheels = new Part("������");

    car->addSubPart(engine);
    car->addSubPart(body);
    car->addSubPart(wheels);


    engine->addSubPart(new Part("�����"));
    engine->addSubPart(new Part("�������"));
    engine->addSubPart(new Part("���������� ���"));


    body->addSubPart(new Part("����"));
    body->addSubPart(new Part("³���"));
    body->addSubPart(new Part("������"));


    wheels->addSubPart(new Part("����"));
    wheels->addSubPart(new Part("�����"));


    car->print();


    delete car;

    return 0;
}
