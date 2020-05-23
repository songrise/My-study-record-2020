class Dog {
    String names;
    String says;
}

public class Ex_5_2 {
    public static void main(String[] args) {
        Dog spot = new Dog();
        Dog scruffy = new Dog();

        spot.names = "spot";
        scruffy.names = "scruffy";
        spot.says = "Ruff!";
        scruffy.says = "Wurf!";
        System.out.println(spot.names + " says " + spot.says);
        System.out.println(scruffy.names + " says " + scruffy.says);
    }

}