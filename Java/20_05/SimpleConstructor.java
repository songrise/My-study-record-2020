class Rock {
    Rock() {// constructor should have identical name with class
        System.out.println("Rock ");
    }
}

public class SimpleConstructor {
    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            new Rock();
        }
    }
}