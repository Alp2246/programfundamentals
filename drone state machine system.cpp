#include <iostream>
#include <string>

// Durumları temsil eden sabitler
enum class DroneState {
    IDLE,
    TAKEOFF,
    HOVER,
    MOVING_TO_TARGET,
    CAPTURING_IMAGE,
    LANDING,
    EMERGENCY_STOP
};

// Drone sınıfı
class Drone {
public:
    Drone(const std::string& name) : name(name), state(DroneState::IDLE) {}

    void takeoff() {
        if (state == DroneState::IDLE) {
            std::cout << name << " kalkış yapıyor." << std::endl;
            state = DroneState::TAKEOFF;
        } else {
            std::cout << "Kalkış yapılabilmesi için drone " << name << " şu anda hazır değil." << std::endl;
        }
    }

    void moveToTarget() {
        if (state == DroneState::HOVER || state == DroneState::MOVING_TO_TARGET) {
            std::cout << name << " hedefe doğru hareket ediyor." << std::endl;
            state = DroneState::MOVING_TO_TARGET;
        } else {
            std::cout << "Hedefe gitmek için drone " << name << " uygun değil." << std::endl;
        }
    }

    void captureImage() {
        if (state == DroneState::MOVING_TO_TARGET) {
            std::cout << name << " kamera ile görüntü yakalıyor." << std::endl;
            state = DroneState::CAPTURING_IMAGE;
        } else {
            std::cout << "Görüntü yakalama için drone " << name << " pozisyonunda değil." << std::endl;
        }
    }

    void land() {
        if (state == DroneState::CAPTURING_IMAGE || state == DroneState::MOVING_TO_TARGET) {
            std::cout << name << " iniş yapıyor." << std::endl;
            state = DroneState::LANDING;
        } else {
            std::cout << "İniş yapabilmesi için drone " << name << " uygun değil." << std::endl;
        }
    }

    void emergencyStop() {
        std::cout << name << " acil durumda duruyor." << std::endl;
        state = DroneState::EMERGENCY_STOP;
    }

    const std::string& getName() const {
        return name;
    }

    DroneState getState() const {
        return state;
    }

private:
    std::string name;
    DroneState state;
};

int main() {
    Drone drone1("Drone-1");
    Drone drone2("Drone-2");

    drone1.takeoff();
    drone1.moveToTarget();
    drone1.captureImage();
    drone1.land();
    drone1.emergencyStop();

    drone2.takeoff();
    drone2.emergencyStop();

    return 0;
}
