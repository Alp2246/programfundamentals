#include <iostream>
#include <vector>

// Alıcı sınıf
class Light {
public:
    void turnOn() {
        std::cout << "Işık açık" << std::endl;
    }

    void turnOff() {
        std::cout << "Işık kapalı" << std::endl;
    }
};

// Komut arayüzü
class Command {
public:
    virtual void execute() = 0;
};

// Işığı açma komutu
class TurnOnLightCommand : public Command {
private:
    Light* light;

public:
    TurnOnLightCommand(Light* l) : light(l) {}

    void execute() {
        light->turnOn();
    }
};

// Işığı kapama komutu
class TurnOffLightCommand : public Command {
private:
    Light* light;

public:
    TurnOffLightCommand(Light* l) : light(l) {}

    void execute() {
        light->turnOff();
    }
};

// Komut istemcisi
class RemoteControl {
private:
    std::vector<Command*> commands;

public:
    void addCommand(Command* command) {
        commands.push_back(command);
    }

    void pressButton(int index) {
        if (index >= 0 && index < commands.size()) {
            commands[index]->execute();
        }
    }
};

int main() {
    Light light;
    TurnOnLightCommand onCommand(&light);
    TurnOffLightCommand offCommand(&light);

    RemoteControl remote;
    remote.addCommand(&onCommand);
    remote.addCommand(&offCommand);

    remote.pressButton(0); // Işığı aç
    remote.pressButton(1); // Işığı kapat

    return 0;
}
