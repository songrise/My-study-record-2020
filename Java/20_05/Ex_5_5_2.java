class Dog {

    Dog(int i) {
        System.out.println("This is dog " + i + " barking!");
    }

    Dog(double i) {
        System.out.println("This is dog " + i + " howling!");
    }

}

public class Ex_5_5_2 {
    public static void main(String[] args) {
        Dog d1 = new Dog(1);
        Dog d2 = new Dog(3.14);
        // Dog d3 = new Dog(); // buggy, no constructor.
    }
}