# Durumları temsil eden sınıflar
class State:
    def handle_event(self, event):
        pass

class ClosedState(State):
    def handle_event(self, event):
        if event == "open":
            print("Müzik çalar açılıyor.")
            return StandbyState()
        else:
            print("Müzik çalar kapalı.")

class StandbyState(State):
    def handle_event(self, event):
        if event == "play":
            print("Müzik çalma başlıyor.")
            return PlayingState()
        elif event == "volume":
            print("Ses ayarı yapılıyor.")
            return VolumeAdjustingState()
        elif event == "close":
            print("Müzik çalar kapatılıyor.")
            return ClosedState()
        else:
            print("Bekleme modu")

class PlayingState(State):
    def handle_event(self, event):
        if event == "pause":
            print("Müzik duraklatılıyor.")
            return PausedState()
        elif event == "stop":
            print("Müzik durduruluyor.")
            return StandbyState()
        else:
            print("Müzik çalıyor.")

class PausedState(State):
    def handle_event(self, event):
        if event == "play":
            print("Müzik devam ettiriliyor.")
            return PlayingState()
        elif event == "stop":
            print("Müzik duraklatıldı.")
            return StandbyState()
        else:
            print("Duraklatıldı.")

class VolumeAdjustingState(State):
    def handle_event(self, event):
        if event == "volume":
            print("Ses ayarı yapılıyor.")
            return VolumeAdjustingState()
        elif event == "play":
            print("Müzik çalma başlıyor.")
            return PlayingState()
        elif event == "close":
            print("Müzik çalar kapatılıyor.")
            return ClosedState()
        else:
            print("Ses ayarı modu.")

# Müzik çalar sınıfı
class MusicPlayer:
    def __init__(self):
        self.state = ClosedState()

    def change_state(self, new_state):
        self.state = new_state

    def handle_event(self, event):
        self.state = self.state.handle_event(event)

# Ana program
if __name__ == "__main__":
    player = MusicPlayer()

    player.handle_event("open")
    player.handle_event("play")
    player.handle_event("pause")
    player.handle_event("play")
    player.handle_event("volume")
    player.handle_event("stop")
    player.handle_event("close")
