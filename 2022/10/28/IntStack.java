import java.util.Scanner;

public class IntStack {
  // Tao Scanner
  private static Scanner sc = new Scanner(System.in);

  // Kich thuoc cua Stack
  private int size;

  // Vi tri tren cung cua Stack
  private StackElement<Integer> top;

  // Khoi tao gia tri ban dau cho Stack
  public IntStack(){
    size = 0;
    top = null;
  }

  // Dua du lieu vao Stack
  public void push(int value) {
    this.size++;
    top = new StackElement<>(value, top);
  }

  // Lay du lieu ra khoi Stack
  public int pop() {
    size--;
    StackElement<Integer> oldTop = top;
    top = oldTop.getNext();
    return oldTop.getValue();
  }

  // Kiem tra neu Stack rong
  public boolean isEmpty() {
    return size == 0;
  }

  // Ham main chay cau lenh giai quyet bai tap
  public static void main(String[] arg) {
    // Tao Stack moi
    IntStack stack = new IntStack();

    // Nhap du kien tu bai tap
    System.out.println("Input:"); int input = sc.nextInt();

    // Lay phan du cua du kien, dua vao Stack
    while (input != 0) {
      stack.push(input % 2);
      input /= 2;
    }

    // Xuat ra ket qua tu Stack
    while (!(stack.isEmpty())) {
      System.out.print(stack.pop());
    }
  }
}

