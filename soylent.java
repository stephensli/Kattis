import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Double cases = Double.parseDouble(scanner.nextLine());

        for (int i = 0; i < cases; i++) {
            Double cals = Double.parseDouble(scanner.nextLine());

            System.out.println(String.format("%.0f", Math.ceil(cals / 400)));
        }

    }
}
