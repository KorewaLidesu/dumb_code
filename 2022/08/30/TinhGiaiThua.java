import java.util.Scanner;

public class TinhGiaiThua {
  public static void main(String[] arg) {
    Scanner myObj = new Scanner(System.in);
    long N = myObj.nextLong();
    long sum = 1;
    if (N<2) System.out.println("1! = 1");
    else {
      for (long i = N; i > 1 ; i--) {
        sum *= i;
      }
    }
    System.out.println(N + "! = " + sum);
  }
}
