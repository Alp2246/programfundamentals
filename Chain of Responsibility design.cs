using System;

// İşlemi işleyen soyut sınıf
abstract class Handler {
    protected Handler successor;

    public void SetSuccessor(Handler successor) {
        this.successor = successor;
    }

    public abstract void HandleRequest(int request);
}

// İşlemi işleyen somut sınıf
class ConcreteHandlerA : Handler {
    public override void HandleRequest(int request) {
        if (request < 10) {
            Console.WriteLine("ConcreteHandlerA işlemi gerçekleştirdi.");
        } else if (successor != null) {
            successor.HandleRequest(request);
        }
    }
}

// İşlemi işleyen somut sınıf
class ConcreteHandlerB : Handler {
    public override void HandleRequest(int request) {
        if (request >= 10 && request < 20) {
            Console.WriteLine("ConcreteHandlerB işlemi gerçekleştirdi.");
        } else if (successor != null) {
            successor.HandleRequest(request);
        }
    }
}

class Client {
    static void Main() {
        Handler handler1 = new ConcreteHandlerA();
        Handler handler2 = new ConcreteHandlerB();

        handler1.SetSuccessor(handler2);

        int[] requests = { 5, 12, 17, 25 };

        foreach (int request in requests) {
            handler1.HandleRequest(request);
        }
    }
}
