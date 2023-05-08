class Student5 {
  int id;
  String name;
  int age;

  Student5(int i, String n) {
    id = i;
    name = n;
  }

  Student5(int sa, String b, int c) {
    id = sa;
    name = b;
    age = c;
  }

  void display() {
    System.out.println(id + " " + name + " " + age);
  }

  public static void main(String args[]) {
    Student5 s1 = new Student5(111, "Viet");
    Student5 s2 = new Student5(222, "Tuts");
    s1.display();
    s2.display();
  }
}