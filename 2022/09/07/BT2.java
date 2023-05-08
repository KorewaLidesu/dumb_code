import java.util.Scanner;

public class BT2 {
    int m1, m2;

    BT2 Runner() {
        System.out.print("Nhap n = ");  int n = scanner.nextInt();
        if (n<2) {return Exception(n);}
        return Step_1(n);
    }

    BT2 Step_1(int n) {
        int[] A = new int[n];
        boolean first = false, second = false;

        for (int i = 0; i<n ; i++) {
            System.out.print("A[" + i + "] = "); A[i] = scanner.nextInt();
            if (!first) { m1 = A[0]; first = true; }
            else if (m1 > A[i]) {
                if (!second || m2 < A[i]) {m2 = A[i]; second = true;}
            }
            else if (m1 < A[i]) {
                if (!second || m2 < m1) {m2 = m1; second = true;}
                m1 = A[i];
            }
        }    
        return Step_2(); 
    }

    BT2 Step_2() {
        System.out.println(m1 + " " + m2);
        return this;
    }

    BT2 Exception(int n) {
        System.out.print("Input khong hop le.");
        if (n == 1) {System.out.println(" Khong the thuc hien so sanh chi voi 1 gia tri. ");}
        return this;
    };
    
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String args[]) {
        new BT2().Runner();
    }
}
