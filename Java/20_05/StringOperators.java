public class StringOperators {
    public static void main(String[] args) {
        int x = 0, y = 1, z = 2;
        String s = "x, y, z";
        System.out.println(s + x + y + z);// 012 instead of 3
        System.out.println(x + " " + s);// convert x to a string
    }
}