#include <iostream>
#include <vector>

class ElementA;
class ElementB;

// Ziyaretçi arabirimi
class Visitor {
public:
    virtual void visitElementA(ElementA* elementA) = 0;
    virtual void visitElementB(ElementB* elementB) = 0;
};

// Element sınıfı
class Element {
public:
    virtual void accept(Visitor* visitor) = 0;
};

// ElementA sınıfı
class ElementA : public Element {
public:
    void accept(Visitor* visitor) {
        visitor->visitElementA(this);
    }

    void operationA() {
        std::cout << "ElementA işlemi" << std::endl;
    }
};

// ElementB sınıfı
class ElementB : public Element {
public:
    void accept(Visitor* visitor) {
        visitor->visitElementB(this);
    }

    void operationB() {
        std::cout << "ElementB işlemi" << std::endl;
    }
};

// ConcreteVisitor sınıfı
class ConcreteVisitor : public Visitor {
public:
    void visitElementA(ElementA* elementA) {
        elementA->operationA();
    }

    void visitElementB(ElementB* elementB) {
        elementB->operationB();
    }
};

int main() {
    ElementA elementA;
    ElementB elementB;

    std::vector<Element*> elements = { &elementA, &elementB };
    ConcreteVisitor visitor;

    for (Element* element : elements) {
        element->accept(&visitor);
    }

    return 0;
}
