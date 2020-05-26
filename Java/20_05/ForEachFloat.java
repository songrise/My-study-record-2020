import java.util.*;

public class ForEachFloat {
    public static void main(String[] args) {
        Random rand = new Random(47);
        float f[] = new float[10];
        for (int i = 0; i < 10; i++) {
            f[i] = rand.nextFloat();
        }
        for (float x : f) {
            // python for each x in f:
            System.out.println(x);
        }
    }
}