import java.util.ArrayList;
import java.util.List;

// Gözlemci arabirimi
interface Observer {
    void update(String message);
}

// Gözlenen sınıf
class Subject {
    private List<Observer> observers = new ArrayList<>();
    private String message;

    public void attach(Observer observer) {
        observers.add(observer);
    }

    public void detach(Observer observer) {
        observers.remove(observer);
    }

    public void setMessage(String message) {
        this.message = message;
        notifyObservers();
    }

    public void notifyObservers() {
        for (Observer observer : observers) {
            observer.update(message);
        }
    }
}

// Gözlemci sınıfı
class ConcreteObserver implements Observer {
    private String name;

    public ConcreteObserver(String name) {
        this.name = name;
    }

    public void update(String message) {
        System.out.println(name + " alındı: " + message);
    }
}

public class ObserverPatternExample {
    public static void main(String[] args) {
        Subject subject = new Subject();

        ConcreteObserver observer1 = new ConcreteObserver("Gözlemci 1");
        ConcreteObserver observer2 = new ConcreteObserver("Gözlemci 2");

        subject.attach(observer1);
        subject.attach(observer2);

        subject.setMessage("Yeni bir mesaj geldi!");

        subject.detach(observer1);

        subject.setMessage("Bir diğer mesaj geldi!");
    }
}
