# Durumları temsil eden sınıflar
class State:
    def handle_event(self, car):
        pass

class IdleState(State):
    def handle_event(self, car):
        print("Otomobil durakta.")
        return StartState()

class StartState(State):
    def handle_event(self, car):
        print("Otomobil çalıştırıldı.")
        return HighSpeedState()

class HighSpeedState(State):
    def handle_event(self, car):
        print("Otomobil yüksek hızda sürülüyor.")
        return LowSpeedState()

class LowSpeedState(State):
    def handle_event(self, car):
        print("Otomobil düşük hızda sürülüyor.")
        return StopState()

class StopState(State):
    def handle_event(self, car):
        print("Otomobil durdu.")
        return None

# Araba sınıfı
class Car:
    def __init__(self):
        self.state = IdleState()

    def change_state(self, new_state):
        self.state = new_state

    def run(self):
        while self.state is not None:
            print("\nSürücü ne yapmalı? (1: Çalıştır, 2: Hızlı Sür, 3: Yavaş Sür, 4: Durdur, 5: Kapat)")
            choice = input()
            if choice == "1":
                self.state = self.state.handle_event(self)
            elif choice == "2":
                self.state = self.state.handle_event(self)
            elif choice == "3":
                self.state = self.state.handle_event(self)
            elif choice == "4":
                self.state = self.state.handle_event(self)
            elif choice == "5":
                self.state = self.state.handle_event(self)
            else:
                print("Geçersiz seçenek.")

# Ana program
if __name__ == "__main__":
    car = Car()
    car.run()
