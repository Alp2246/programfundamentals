# Durumları temsil eden sınıflar
class State:
    def handle_event(self, coffee_machine):
        pass

class StartState(State):
    def handle_event(self, coffee_machine):
        print("Kahve makinesi başlatıldı.")
        return AddWaterState()

class AddWaterState(State):
    def handle_event(self, coffee_machine):
        print("Su ekleniyor.")
        coffee_machine.storage["water"] = True
        return AddCoffeeState()

class AddCoffeeState(State):
    def handle_event(self, coffee_machine):
        print("Kahve ekleniyor.")
        coffee_machine.storage["coffee"] = True
        return BrewState()

class BrewState(State):
    def handle_event(self, coffee_machine):
        if coffee_machine.storage["water"] and coffee_machine.storage["coffee"]:
            print("Kahve yapılıyor.")
            coffee_machine.storage["coffee"] = False
            coffee_machine.storage["water"] = False
            return ReadyState()
        else:
            print("Su veya kahve eksik. İşlem iptal edildi.")
            return StartState()

class ReadyState(State):
    def handle_event(self, coffee_machine):
        print("Kahve hazır. Afiyet olsun!")
        return None

# Kahve makinesi sınıfı
class CoffeeMachine:
    def __init__(self):
        self.state = StartState()
        self.storage = {"water": False, "coffee": False}

    def change_state(self, new_state):
        self.state = new_state

    def run(self):
        while self.state is not None:
            print("\nSürücü ne yapmalı? (1: Su Ekle, 2: Kahve Ekle, 3: Kahve Yap, 4: Kapat)")
            choice = input()
            if choice == "1":
                self.state = self.state.handle_event(self)
            elif choice == "2":
                self.state = self.state.handle_event(self)
            elif choice == "3":
                self.state = self.state.handle_event(self)
            elif choice == "4":
                self.state = self.state.handle_event(self)
            else:
                print("Geçersiz seçenek.")

# Ana program
if __name__ == "__main__":
    coffee_machine = CoffeeMachine()
    coffee_machine.run()
