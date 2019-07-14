import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int x = Integer.parseInt(scanner.nextLine());
        int y = Integer.parseInt(scanner.nextLine());

        int number = 0;

        if (x > 0) {
            if (y > 0) {
                number = 1;
            } else if (y < 0) {
                number = 4;
            }
        } else if (x < 0) {
            if (y > 0) {
                number = 2;
            } else if (y < 0) {
                number = 3;
            }
        }


        System.out.println(number);

    }
}
