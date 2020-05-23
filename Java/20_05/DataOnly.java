public class DataOnly {
    public static void main(String[] args) {
        class Data {
            int num;

            double floatingNum;
            char character;

            void show() {
                // method
                System.out.println(character);
                System.out.println(floatingNum);
                System.out.println(num);
            }
        }

        Data a = new Data();// instantialize
        a.character = 'D';
        a.floatingNum = 3.8;
        a.num = 2000;
        a.show();

    }

}
