import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Integer setCount = -1;

        List<Integer[][]> sets = new ArrayList<>();

        while (setCount != 0) {
            setCount = Integer.parseInt(scanner.nextLine());

            Integer[] set1 = new Integer[setCount];
            Integer[] set2 = new Integer[setCount];

            Integer[][] set = new Integer[2][setCount];

            for (int i = 0; i < setCount; i++) {
                set1[i] = Integer.parseInt(scanner.nextLine());
            }

            for (int i = 0; i < setCount; i++) {
                set2[i] = Integer.parseInt(scanner.nextLine());
            }

            set[0] = set1;
            set[1] = set2;

            sets.add(set);
        }

        Integer count = 0;

        for (Integer[][] set : sets) {
            if (count > 0 && count != sets.size()) {
                System.out.println(" ");
            }
            count += 1;

            List<Integer> set1 = Arrays.asList(set[0].clone());
            List<Integer> set2 = Arrays.asList(set[1].clone());

            Collections.sort(set1);
            Collections.sort(set2);

            for (int i = 0; i < set1.size(); i++) {
                Integer toFind = Arrays.asList(set[0]).get(i);
                Integer index = set1.indexOf(toFind);
                System.out.println(set2.get(index));
            }
        }
    }
}