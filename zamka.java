import java.net.Inet4Address;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int L = Integer.parseInt(scanner.nextLine());
        int D = Integer.parseInt(scanner.nextLine());
        int X = Integer.parseInt(scanner.nextLine());

        boolean foundFirst = false;

        int firstNumber = 0;
        int secondNumber = 0;

        for (int i = L; i <= D; i++) {
            String stringInt = Integer.toString(i);

            String[] split = stringInt.split("");
            int total = 0;

            for (String val : split) {
                total += Integer.parseInt(val);
            }

            if (total == X && !foundFirst) {
                firstNumber = i;
                secondNumber = i;
                foundFirst = true;
            } else if (total == X) {
                secondNumber = i;
            }

        }

        System.out.println(firstNumber);
        System.out.println(secondNumber);

    }
}
