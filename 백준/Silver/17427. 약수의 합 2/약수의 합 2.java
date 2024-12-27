
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int a = Integer.parseInt(bf.readLine());

        double sum = 0;
        for (int i = 1; i <= a; i++) {
            sum += i * (int)(a / i);
        }

        DecimalFormat df = new DecimalFormat("#");
        String formattedNumber = df.format(sum);

        System.out.println(formattedNumber);
    }
}