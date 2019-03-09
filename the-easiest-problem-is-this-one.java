import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int intVal = Integer.parseInt(scanner.nextLine());
        List<Integer> numberList = new ArrayList<>();

        while (intVal != 0) {
            numberList.add(intVal);
            intVal = Integer.parseInt(scanner.nextLine());
        }

        for (int number : numberList) {
            boolean foundAnswer = false;

            int numSum = 0;
            int counter = 11;

            String[] numSplit = Integer.toString(number).split("");
            for (String splitVal : numSplit) {
                numSum += Integer.parseInt(splitVal);
            }

            while (!foundAnswer) {
                int total = number * counter;
                int totalSplit = 0;

                String[] split = Integer.toString(total).split("");
                for (String splitVal : split) {
                    totalSplit += Integer.parseInt(splitVal);
                }

                if (totalSplit == numSum) {
                    System.out.println(counter);
                    foundAnswer = true;
                }

                counter += 1;
            }
        }
    }
}
