# Özne sınıfı
class Subject:
    def request(self):
        pass

# Gerçek nesne sınıfı
class RealSubject(Subject):
    def request(self):
        print("Gerçek nesne isteği")

# Proxy sınıfı
class Proxy(Subject):
    def __init__(self):
        self._real_subject = RealSubject()

    def request(self):
        print("Proxy isteği")
        self._real_subject.request()

if __name__ == "__main__":
    proxy = Proxy()
    proxy.request()
