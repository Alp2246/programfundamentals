# Bileşen arabirimi
class Component:
    def operation(self):
        pass

# Yaprak sınıfı
class Leaf(Component):
    def operation(self):
        print("Yaprak işlemi")

# Bileşen sınıfı
class Composite(Component):
    def __init__(self):
        self._children = []

    def add(self, component):
        self._children.append(component)

    def remove(self, component):
        self._children.remove(component)

    def operation(self):
        print("Composite işlemi")
        for child in self._children:
            child.operation()

if __name__ == "__main__":
    leaf1 = Leaf()
    leaf2 = Leaf()
    composite = Composite()

    composite.add(leaf1)
    composite.add(leaf2)

    composite.operation()
