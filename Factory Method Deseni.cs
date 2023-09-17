using System;

// Ürün soyut sınıfı
abstract class Product {
    public abstract void ShowInfo();
}

// Ürün sınıfının somut bir uygulaması
class ConcreteProductA : Product {
    public override void ShowInfo() {
        Console.WriteLine("Ürün A oluşturuldu.");
    }
}

// Ürün sınıfının somut bir uygulaması
class ConcreteProductB : Product {
    public override void ShowInfo() {
        Console.WriteLine("Ürün B oluşturuldu.");
    }
}

// Ürün yaratma metodu
abstract class Creator {
    public abstract Product FactoryMethod();
}

// Ürün yaratma metodu uygulaması
class ConcreteCreatorA : Creator {
    public override Product FactoryMethod() {
        return new ConcreteProductA();
    }
}

// Ürün yaratma metodu uygulaması
class ConcreteCreatorB : Creator {
    public override Product FactoryMethod() {
        return new ConcreteProductB();
    }
}

class Program {
    static void Main() {
        Creator creatorA = new ConcreteCreatorA();
        Product productA = creatorA.FactoryMethod();
        productA.ShowInfo();

        Creator creatorB = new ConcreteCreatorB();
        Product productB = creatorB.FactoryMethod();
        productB.ShowInfo();
    }
}
