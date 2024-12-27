import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()){
            int num = sc.nextInt();
            int one = 1;
            int res = 1;

            while (true){
                if (one % num == 0) break;
                else{
                    one = one * 10 + 1;
                    one %= num;
                    res += 1;
                }
            }
            System.out.println(res);
        }
    }
}
