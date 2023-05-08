import java.util.LinkedList;

public class SinglyLinkedList<E> {

  public static void main(String[] arg) {
    SinglyLinkedList<Integer> List = new SinglyLinkedList<>();
    // Test class bang stack List

  }

  /**
  * Khoi tao stack
  * */
  transient int size;
  transient Node<E> first;
  transient Node<E> last;

  /**
   * Cho biet so phan tu dang co trong danh sach
   */
  public int getSize() {
    return size;
  }

  /**
   * Cho biet danh sach hien tai co rong hay khong
   */
  public boolean isEmpty() {
    return first == null;
  }

  /**
   * Tra ve gia tri cua phan tu o dau danh sach
   */
  public E first() {
    return first.item;
  }

  /**
   * Tra ve gia tri cua phan tu o cuoi danh sach
   */
  public E last() {
    return last.item;
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
      for (Node<E> x = first; x != null; x = x.next) {
        if (x.item == null)
          return x;
      }
    } else {
      for (Node<E> x = first; x != null; x = x.next) {
        if (e.equals(x.item))
          return x;
      }
    }

    return null;
  }

  /**
   * Them mot Node moi co gia tri du lieu la e vao dau danh sach
   */
  public void addFirst(E e) {
    final Node<E> f = first;
    final Node<E> newNode = new Node<>(null, e, f);
    first = newNode;
    if (f == null)
      last = newNode;
    else
      f.prev = newNode;
    size++;
  }

  /**
   * Them mot Node moi co gia tri du lieu la e vao cuoi danh sach
   */
  public void addLast(E e) {
    final Node<E> l = last;
    final Node<E> newNode = new Node<>(l, e, null);
    last = newNode;
    if (l == null)
      first = newNode;
    else
      l.next = newNode;
    size++;
  }

  /**
  * Them mot Node moi co gia tri du lieu la e vao sau Node co gia tri du lieu la f trong
  * danh sach. Neu Node f khong ton tai thi phan tu moi se duoc them vao cuoi danh sach
  * */
  public void add(E f, E e) {
    final Node<E> node = search(f);

    if (node == null || node.next == null) {
      addLast(e);
      return;
    }

    final Node<E> pred = node.next.prev;
    final Node<E> newNode = new Node<>(pred, e, node.next);
    node.next.prev = newNode;
    if (pred == null)
      first = newNode;
    else
      pred.next = newNode;
    size++;
  }

  /**
   * Xoa bo Node dau danh sach
   */
  public void removeFirst() {
    if (first == null)
      return;

    final Node<E> next = first.next;
    first.item = null;
    first.next = null; // help GC
    first = next;
    if (next == null)
      last = null;
    else
      next.prev = null;
    size--;
  }

  /**
   * Xoa bo Node cuoi danh sach
   */
  public void removeLast() {
    if (last == null) {
      this.removeFirst();
      return;
    }

    final Node<E> prev = last.prev;
    last.item = null;
    last.prev = null; // help GC
    last = prev;
    if (prev == null)
      first = null;
    else
      prev.next = null;
    size--;
  }

  /**
   * Xoa bo Node dau tien co gia tri la e trong danh sach
   */
  public void remove(E e) {
    if (this.first == null)
      return;

    for (Node<E> x = first; x != null; x = x.next) {
      if (x.item == e) {
        final Node<E> next = x.next;
        final Node<E> prev = x.prev;

        if (prev == null) {
          first = next;
        } else {
          prev.next = next;
          x.prev = null;
        }

        if (next == null) {
          last = prev;
        } else {
          next.prev = prev;
          x.next = null;
        }

        x.item = null;
        size--;
        return;
      }
    }
  }

  /**
   * Xoa bo tat ca cac Node co gia tri la e trong danh sach
   */
  public void removeAll(E e) {
    while (search(e) != null)
      remove(e);
  }

  /**
   * Hoan vi/Hoan doi vi tri cua hai Node A va B trong danh sach
   */
  public void swapNode(Node<E> nodeA, Node<E> nodeB) {
    // TODO FUCK YOU TEACHER
  }

  /**
  * Hoan vi/Hoan doi gia tri cua hai Node dang co chua gia tri lan luot la a va b trong
  * danh sach. Neu khong dong thoi tim ra duoc 2 Node nhu vay trong danh sach thi phuong
  * thuc nay khong can thuc hien.
  * */
  public void swapValue(E a, E b) {
    final Node<E> nodeA = search(a);
    final Node<E> nodeB = search(b);
    if (nodeA == null || nodeB == null) return;
    nodeA.item = b;
    nodeB.item = a;
  }

  /**
  * Khoi tao Node
  * */
  private static class Node<E> {
    // Khoi tao gia tri
    E item;

    // Khoi tao vi tri tiep theo
    Node<E> next;

    // Khoi tao vi tri truoc do
    Node<E> prev;

    // Contructor nhap du lieu vao Node
    Node(Node<E> prev, E item, Node<E> next) {
      this.item = item;
      this.next = next;
      this.prev = prev;
    }
  }
}
