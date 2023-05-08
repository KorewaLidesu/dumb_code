public class Test {
  int id;
  String name;
  int age;

  Test(int i, String n) {
    name = n;
    age = i;
  }

  Test(int i, String n, int a) {
    id = i;
    name = n;
    age = a;
  }

  void display() {
    System.out.println(id + " " + name + " " + age);
  }

  public static void main(String args[]) {
    Test s1 = new Test(111, "Viet");
    Test s2 = new Test(222, "Tuts", 25);
    s1.display();
    s2.display();
  }
}
