public class StackElement<T> {
  // Init value of stack
  private T value;

  // Init next stack
  private StackElement<T> next;

  // Contructor de nhap du lieu vao Stack
  public StackElement(T value, StackElement<T> under) {
    this.value = value;
    this.next = under;
  }

  // Get-set for Top stack value
  public T getValue() {
    return this.value;
  }

  public void setValue(T value) {
    this.value = value;
  }

  // Get-Set for next stack
  public StackElement<T> getNext() {
    return this.next;
  }

  public void setNext(StackElement<T> next) {
    this.next = next;
  }

}

