import java.util.Scanner;

public class StringStack {
  // Tao Scanner
  private static Scanner sc = new Scanner(System.in);

  // Kich thuoc cua Stack
  private int size;

  // Vi tri tren cung cua Stack
  private StackElement<Character> top;

  // Khoi tao gia tri ban dau cho Stack
  public StringStack(){
    size = 0;
    top = null;
  }

  // Dua du lieu vao Stack
  public void push(Character value) {
    this.size++;
    top = new StackElement<>(value, top);
  }

  // Lay du lieu ra khoi Stack
  public Character pop() {
    size--;
    StackElement<Character> oldTop = top;
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
    StringStack stack = new StringStack();

    // Nhap du kien tu bai tap
    System.out.println("Input:"); String input = sc.next();

    // Lay ky tu tu vi tri i, dua vao Stack
    for (int i = 0; i< input.length(); i++) {
      stack.push(input.charAt(i));
    }

    // Xuat ra ket qua tu Stack
    while (!(stack.isEmpty())) {
      System.out.print(stack.pop());
    }
  }
}