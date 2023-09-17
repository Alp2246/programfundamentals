#include <stdio.h>
#include <stdlib.h>

// Durumları temsil eden sabitler
#define IDLE 0
#define TAKEOFF 1
#define HOVER 2
#define MOVE_TO_TARGET 3
#define CAPTURE_IMAGE 4
#define LAND 5

// Drone durumu için veri yapısı
struct DroneState {
    int state;
    int batteryLevel;
};

// Fonksiyonlar
void initializeDrone(struct DroneState* drone) {
    drone->state = IDLE;
    drone->batteryLevel = 100;
}

void takeoff(struct DroneState* drone) {
    if (drone->state == IDLE && drone->batteryLevel >= 20) {
        drone->state = TAKEOFF;
        drone->batteryLevel -= 20;
        printf("Drone kalkış yaptı.\n");
    } else {
        printf("Kalkış yapılamıyor. Drone şu anda uçuşta veya pil düşük.\n");
    }
}

void moveToTarget(struct DroneState* drone) {
    if (drone->state == HOVER && drone->batteryLevel >= 30) {
        drone->state = MOVE_TO_TARGET;
        drone->batteryLevel -= 30;
        printf("Hedefe doğru hareket ediliyor.\n");
    } else {
        printf("Hedefe gitmek mümkün değil. Drone şu anda uçuşta veya pil düşük.\n");
    }
}

void captureImage(struct DroneState* drone) {
    if (drone->state == MOVE_TO_TARGET && drone->batteryLevel >= 10) {
        drone->state = CAPTURE_IMAGE;
        drone->batteryLevel -= 10;
        printf("Kamera ile görüntü yakalandı.\n");
    } else {
        printf("Görüntü yakalama yapılamıyor. Drone hareket halinde veya pil düşük.\n");
    }
}

void land(struct DroneState* drone) {
    if (drone->state == CAPTURE_IMAGE) {
        drone->state = LAND;
        printf("Drone iniş yapıyor.\n");
    } else {
        printf("İniş yapılamıyor. Drone şu anda uçuşta değil veya işlem tamamlanmadı.\n");
    }
}

int main() {
    struct DroneState drone;
    initializeDrone(&drone);

    // Örnek uçuş senaryosu
    takeoff(&drone);
    moveToTarget(&drone);
    captureImage(&drone);
    land(&drone);

    return 0;
}
