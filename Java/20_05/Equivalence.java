
public class Equivalence {
    public static void main(String[] args) {
        Integer n1 = new Integer(47);
        Integer n2 = new Integer(47);
        System.out.println(n1 == n2);
        System.out.println(n1 != n2);
        // operator "==" and "!=" are comparing reference, rather than their value.
        // This law only works for non-basic type.
    }
}