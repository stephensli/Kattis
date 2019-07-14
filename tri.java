import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String[] strings = scanner.nextLine().split(" ");

        int first = Integer.parseInt(strings[0]);
        int second = Integer.parseInt(strings[1]);
        int third = Integer.parseInt(strings[2]);


        if (first + second == third) { System.out.println(String.format("%d+%d=%d", first, second, third)); }
        else if (first - second == third) { System.out.println(String.format("%d-%d=%d", first, second, third)); }
        else if (first * second == third) { System.out.println(String.format("%d*%d=%d", first, second, third)); }
        else if (first / second == third) { System.out.println(String.format("%d/%d=%d", first, second, third)); }
        else if (second + third == first) { System.out.println(String.format("%d=%d+%d", first, second, third)); }
        else if (second - third == first) { System.out.println(String.format("%d=%d-%d", first, second, third)); }
        else if (second * third == first) { System.out.println(String.format("%d=%d*%d", first, second, third)); }
        else if (second / third == first) { System.out.println(String.format("%d=%d/%d", first, second, third)); }

    }
}

