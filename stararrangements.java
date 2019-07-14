import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        float amount = Integer.parseInt(scanner.nextLine());

        System.out.println(String.format("%d:", (int) amount));

        // Every other row has the same number of stars.
        // Adjacent rows differ by no more than one star.
        // The first row cannot have fewer stars than the second row.

        List<String> list = new ArrayList<>();


        for (int i = 2; i < amount; i++) {
            int total = 0;

            int valOne = i;
            int valTwo = i - 1;

            boolean added = true;

            while (total < amount) {

                if (added) {
                    total += valOne;
                    added = false;
                } else {
                    total += valTwo;
                    added = true;
                }

                if (total == amount) {
                    String adding = String.format("%d,%d", (int) valOne, (int) valTwo);
                    list.add(adding);
                }
            }

            total = 0;

            while (total < amount) {
                total += valOne;

                if (total == amount) {
                    String adding = String.format("%d,%d", (int) valOne, (int) valOne);
                    list.add(adding);
                }
            }
        }

        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }

    }
}
