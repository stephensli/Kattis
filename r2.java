import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String[] numbers = scanner.nextLine().split(" ");

        int r1 = Integer.parseInt(numbers[0]);
        int r3 = Integer.parseInt(numbers[1]);

        int total = r3 * 2;

        int r2 = total - r1;

        System.out.println(r2);

    }
}
