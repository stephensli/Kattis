import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int amount = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i < amount; i++) {
            String[] values = scanner.nextLine().split(" ");

            double velocity = Double.parseDouble(values[0]);
            double angle = Math.toRadians(Double.parseDouble(values[1]));
            double x1 = Double.parseDouble(values[2]);
            double h1 = Double.parseDouble(values[3]);
            double h2 = Double.parseDouble(values[4]);

            double time = x1 / (velocity * Math.cos(angle));
            double y = (velocity * time * Math.sin(angle)) - (0.5 * (9.81) * time * time);

            if (h1 + 1 <= y && y <= h2 - 1) {
                System.out.println("Safe");
            } else {
                System.out.println("Not Safe");
            }
        }
    }
}
