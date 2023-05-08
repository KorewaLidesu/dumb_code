public class CircularlyLinkedList<E> {

  public static void main(String[] arg) {
    CircularlyLinkedList<Integer> List = new CircularlyLinkedList<>();
    // Test class bang stack List

    List.insertLast(2);
    List.insertFirst(10);
    List.insertLast(3);
//    List.insertAfter(4, 3);

    List.insertFirst(99);

    System.out.println(List.head.item);
    System.out.println(List.head.next.item);
    System.out.println(List.head.next.next.item);
    System.out.println(List.head.next.next.next.item);
    System.out.println(List.head.next.next.next.next.item);
    System.out.println(List.head.next.next.next.next.next.item);
    System.out.println(List.head.next.next.next.next.next.next.item);
    System.out.println(List.head.next.next.next.next.next.next.next.item);
    System.out.println(List.head.next.next.next.next.next.next.next.next.item);

  }

  transient int size;
  transient Node<E> head;
  transient Node<E> tail;

  /**
   * Cho biet so phan tu dang co trong danh sach
   */
  int getSize() {
    return size;
  }

  /**
   * Cho biet danh sach hien tai co rong hay khong
   */
  boolean isEmpty() {
    return size == 0;
  }

  /**
   * Tim mot Node trong danh sach dang co chua gia tri e. Ket qua tra ve cua phuong thuc nay
   * la chinh Node do (neu tim duoc.). Neu Node khong ton tai trong danh sach thi ket qua
   * tra ve cua phuong thuc la NULL
   * */
  public Node<E> search(E e) {
    if (size <=0) {
      return null;
    }

    if (e == null) {
      for (Node<E> x = head; x != null; x = x.next) {
        if (x.item == null)
          return x;
      }
    } else {
      for (Node<E> x = head; x != null; x = x.next) {
        if (e.equals(x.item))
          return x;
      }
    }
    return null;
  }

  /**
   * Them mot Node moi co gia tri du lieu la e vao dau danh sach
   */
  public void insertFirst(E e) {
    Node<E> f = head;
    final Node<E> newNode = new Node<>(tail, e, f);
    if ()
    head = newNode;
    size++;
    if (f == null || f == tail) {
      if (f == null)
        tail = head;
      tail.next = newNode;
      tail.prev = newNode;
      return;
    }
    f = head;
    f.prev = head;
  }

  public void insertLast(E e) {
    Node<E> l = tail;
    tail = new Node<>(l, e, head);
    size++;
    if (l == null || l == head) {
      if (l == null)
        head = tail;
      head.next = tail;
      head.prev = tail;
      return;
    }
    l.next = tail;

  }

  void insertAfter(E v, E x) {
    final Node<E> node = search(x);

    if (node.next == head) {
      insertLast(v);
      return;
    }

    final Node<E> preNode = node.next.prev;
    final Node<E> newNode = new Node<>(preNode, v, node.next);
    node.next.prev = newNode;
    if (preNode == null)
      head = newNode;
    else
      preNode.next = newNode;
    size++;
  }

  void insertBefore(E v, E y) {
    final Node<E> node = search(y);

    if (node.prev == tail || node.prev == null) {
      insertFirst(v);
      return;
    }

    final Node<E> preNode = node.prev;
    node.prev = new Node<>(preNode, v, node);
    node.next = node;
    size++;
  }

  private static class Node<E> {
    private E item; // an item stored at this node
    private Node<E> prev; // previous node
    private Node<E> next; // next node

    public Node(Node<E> prev, E item, Node<E> next) {
      this.item = item;
      this.prev = prev;
      this.next = next;
    }
  }
}
