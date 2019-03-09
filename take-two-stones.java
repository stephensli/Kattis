import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // the number of vertices in the biscuit.
        int numberOfRocks = Integer.parseInt(scanner.nextLine());

        if (numberOfRocks % 2 == 0) {
            System.out.println("Bob");
        } else {
            System.out.println("Alice");
        }
    }
}
