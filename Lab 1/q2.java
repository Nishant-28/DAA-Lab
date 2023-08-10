import java.io.*;

public class q2 {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java q2 <inputFileName> <outputFileName>");
            return;
        }

        String inputFileName = args[0];
        String outputFileName = args[1];

        try {
            BufferedReader br = new BufferedReader(new FileReader(inputFileName));
            BufferedWriter bw = new BufferedWriter(new FileWriter(outputFileName));

            String line;
            while ((line = br.readLine()) != null) {
                String[] numbers = line.trim().split(" ");
                if (numbers.length == 2) {
                    int num1 = Integer.parseInt(numbers[0]);
                    int num2 = Integer.parseInt(numbers[1]);

                    int gcd = findGCD(num1, num2);

                    String result = String.format("The GCD of %d and %d is %d\n", num1, num2, gcd);
                    bw.write(result);
                }
            }

            br.close();
            bw.close();
            System.out.println("GCD calculation completed. Results stored in " + outputFileName);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Recursive method to find the GCD of two numbers
    public static int findGCD(int a, int b) {
        if (b == 0)
            return a;
        return findGCD(b, a % b);
    }
}
