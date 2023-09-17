# Temel bileşen sınıfı
class Coffee:
    def cost(self):
        return 5

# Temel decorator sınıfı
class CoffeeDecorator:
    def __init__(self, coffee):
        self._coffee = coffee

    def cost(self):
        return self._coffee.cost()

# Süsleme (decorator) sınıfı 1
class MilkDecorator(CoffeeDecorator):
    def cost(self):
        return self._coffee.cost() + 2

# Süsleme (decorator) sınıfı 2
class SugarDecorator(CoffeeDecorator):
    def cost(self):
        return self._coffee.cost() + 1

if __name__ == "__main__":
    simple_coffee = Coffee()
    print("Basit kahve maliyeti:", simple_coffee.cost())

    milk_coffee = MilkDecorator(simple_coffee)
    print("Süt eklenmiş kahve maliyeti:", milk_coffee.cost())

    sugar_coffee = SugarDecorator(simple_coffee)
    print("Şeker eklenmiş kahve maliyeti:", sugar_coffee.cost())

    milk_and_sugar_coffee = SugarDecorator(MilkDecorator(simple_coffee))
    print("Süt ve şeker eklenmiş kahve maliyeti:", milk_and_sugar_coffee.cost())
