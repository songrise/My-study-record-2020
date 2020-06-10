public class Leaf {
    int i = 0;

    Leaf increment() {
        i++;
        return this;
    }

    void print() {
        System.out.println("i = " + i); // i == this.i
    }

    public static void main(String[] args) {
        Leaf x = new Leaf();
        // enclosure 闭包性
        x.increment().increment().increment().print();
    }
}