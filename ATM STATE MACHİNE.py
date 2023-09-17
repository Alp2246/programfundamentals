# Durumları temsil eden sınıflar
class State:
    def handle_event(self, atm):
        pass

class StartState(State):
    def handle_event(self, atm):
        print("Lütfen kartınızı takın.")
        return TransactionSelectionState()

class TransactionSelectionState(State):
    def handle_event(self, atm):
        print("Lütfen işlem seçeneğinizi girin (1: Para Çekme, 2: Bakiye Sorgulama):")
        choice = input()
        if choice == "1":
            return WithdrawalState()
        elif choice == "2":
            return BalanceInquiryState()
        else:
            print("Geçersiz seçenek.")
            return self

class WithdrawalState(State):
    def handle_event(self, atm):
        print("Lütfen çekmek istediğiniz miktarı girin:")
        amount = float(input())
        if amount > atm.balance:
            print("Yetersiz bakiye. Başka bir miktar girin.")
            return self
        else:
            atm.balance -= amount
            print(f"{amount} TL çekildi.")
            return CardEjectionState()

class BalanceInquiryState(State):
    def handle_event(self, atm):
        print(f"Bakiyeniz: {atm.balance} TL")
        return CardEjectionState()

class CardEjectionState(State):
    def handle_event(self, atm):
        print("Kartınız iade ediliyor. İyi günler!")
        return None

# ATM sınıfı
class ATM:
    def __init__(self):
        self.state = StartState()
        self.balance = 1000.0

    def change_state(self, new_state):
        self.state = new_state

    def run(self):
        while self.state is not None:
            self.state = self.state.handle_event(self)

# Ana program
if __name__ == "__main__":
    atm = ATM()
    atm.run()
