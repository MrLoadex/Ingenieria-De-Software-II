#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Interfaz del Observador
class IObserver {
public:
    virtual ~IObserver() {}
    virtual void update(const string message) = 0;
};

// Interfaz del Sujeto
class ISubject {
public:
    virtual ~ISubject() {}
    virtual void attach(IObserver *observer) = 0;
    virtual void detach(IObserver *observer) = 0;
    virtual void notify() = 0;
};

// Implementación concreta del Sujeto
class Subject : public ISubject {
public:
    void attach(IObserver *observer) override {
        observers.push_back(observer);
    }

    void detach(IObserver *observer) override {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void notify() override {
        for (IObserver *observer : observers) {
            observer->update(message);
        }
    }

    void createMessage(const string newMessage) {
        message = newMessage;
        notify();
    }

private:
    vector<IObserver *> observers;
    string message;
};

// Implementación concreta del Observador
class ConcreteObserver : public IObserver {
public:
    ConcreteObserver(const string name) : observerName(name) {}

    void update(const string message) override {
        cout << observerName << " recibio el mensaje: " << message << endl;
    }

private:
    string observerName;
};

int main() {
    Subject subject;

    ConcreteObserver* observer1 = new ConcreteObserver("Observador 1");
    ConcreteObserver* observer2 = new ConcreteObserver("Observador 2");
    ConcreteObserver* observer3 = new ConcreteObserver("Observador 3");

    subject.attach(observer1);
    subject.attach(observer2);
    subject.attach(observer3);
    subject.createMessage("Hola, Observadores!");

    subject.detach(observer1);

    subject.createMessage("Otro mensaje para los observadores.");

    delete observer1;
    delete observer2;

    return 0;
}