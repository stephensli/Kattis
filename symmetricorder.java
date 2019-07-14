import javax.swing.plaf.synth.SynthTextAreaUI;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int currentSetSize = Integer.parseInt(scanner.nextLine());

        List<List<String>> sets = new ArrayList<>();

        while (currentSetSize != 0) {
            List<String> newSet = new ArrayList<>();

            for (int i = 0; i < currentSetSize; i++) {
                newSet.add(scanner.nextLine());
            }

            sets.add(newSet);
            currentSetSize = Integer.parseInt(scanner.nextLine());
        }

        int count = 1;

        for (List<String> set : sets) {
            System.out.println("SET " + count);
            count += 1;

            for (int i = 0; i < set.size(); i++) {
                if (i % 2 != 1) {
                    System.out.println(set.get(i));
                }
            }

            for (int i = set.size() - 1; i > 0; i--) {
                if (i % 2 == 1) {
                    System.out.println(set.get(i));
                }
            }
        }
    }
}

