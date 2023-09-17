// Durum arabirimi
interface State {
    void doAction(Context context);
}

// Durum 1
class StateOne implements State {
    public void doAction(Context context) {
        System.out.println("Durum 1 çalışıyor");
        context.setState(this);
    }

    public String toString() {
        return "Durum 1";
    }
}

// Durum 2
class StateTwo implements State {
    public void doAction(Context context) {
        System.out.println("Durum 2 çalışıyor");
        context.setState(this);
    }

    public String toString() {
        return "Durum 2";
    }
}

// Durumları yöneten bağlam sınıfı
class Context {
    private State state;

    public void setState(State state) {
        this.state = state;
    }

    public State getState() {
        return state;
    }
}

public class StatePatternExample {
    public static void main(String[] args) {
        Context context = new Context();

        StateOne stateOne = new StateOne();
        stateOne.doAction(context);

        System.out.println("Şu anki durum: " + context.getState());

        StateTwo stateTwo = new StateTwo();
        stateTwo.doAction(context);

        System.out.println("Şu anki durum: " + context.getState());
    }
}
