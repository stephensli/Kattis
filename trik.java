import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String[] list = scanner.nextLine().split("");

        // left : 1, middle: 2, right: 3
        int ballPosition = 1;

        for (String string : list) {
            if (string.equals("A") && ballPosition <= 2) {
                if (ballPosition == 1) ballPosition += 1;
                else ballPosition -= 1;
            }

            if (string.equals("B") && ballPosition >= 2) {
                if (ballPosition == 2) ballPosition += 1;
                else ballPosition -= 1;
            }

            if (string.equals("C") && (ballPosition == 1 || ballPosition == 3)) {
                if (ballPosition == 1) ballPosition += 2;
                else ballPosition -= 2;
            }
        }

        System.out.println(ballPosition);

    }
}
