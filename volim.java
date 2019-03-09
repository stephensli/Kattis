import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int activePlayer = Integer.parseInt(scanner.nextLine());
        int numberOfQuestons = Integer.parseInt(scanner.nextLine());

        List<String[]> list = new ArrayList<>();

        for (int i = 0; i < numberOfQuestons; i++) {
            list.add(scanner.nextLine().split(" "));
        }

        float totalTimePassed = 0;

        for (String[] question : list) {
            double time = Double.parseDouble(question[0]);
            String answer = question[1];

            // System.out.println(String.format("total Time: %f, time: %f, answer: %s, active: %d", totalTimePassed, time, answer, activePlayer));

            totalTimePassed += time;

            if (totalTimePassed / 60 >= 3.5) {
                System.out.println(activePlayer);
                break;
            }

            if (answer.equals("T") && activePlayer < 8) {
                activePlayer += 1;
            } else if (answer.equals("T") && activePlayer == 8) {
                activePlayer = 1;
            }


        }
    }
}
