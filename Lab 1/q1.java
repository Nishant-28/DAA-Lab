import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class q1 {

    public static void main(String[] args) {
        if (args.length != 3) {
            System.out.println("Usage: java q1 <n> <input_file> <output_file>");
            return;
        }

        int n = Integer.parseInt(args[0]);
        String inputFileName = args[1];
        String outputFileName = args[2];

        try {
            BufferedReader reader = new BufferedReader(new FileReader(inputFileName));
            BufferedWriter writer = new BufferedWriter(new FileWriter(outputFileName));
            String line;
            while ((line = reader.readLine()) != null && n > 0) {
                int decimal = Integer.parseInt(line);
                String binary = convertToBinary(decimal, 16); // You can change the second argument to represent the number of bits for the binary representation
                writer.write("The binary equivalent of " + decimal + " is " + binary + "\n");
                n--;
            }
            reader.close();
            writer.close();
        } catch (IOException e) {
            System.out.println("Error reading/writing files: " + e.getMessage());
        }
    }

    private static String convertToBinary(int decimal, int numBits) {
        if (numBits == 0) {
            return "";
        } else {
            int bit = decimal % 2;
            decimal /= 2;
            String partialBinary = convertToBinary(decimal, numBits - 1);
            return partialBinary + bit;
        }
    }
}
