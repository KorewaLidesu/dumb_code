import java.util.Scanner;

class BT1 {
	int n;

	BT1 runner(int n) {this.n = n; return step1();}
	
	BT1 step1() { //Kiem tra tinh nguyen to
		String result = " khong";
		if (n<1) {System.out.println("Input khong hop le."); return this;}
		else {
			int i = 2;
			while (i<n) {
				if (n%i==0) break;
				else i++;} 
			if (i==n) result = "";
			System.out.print("So da cho" + result + " la so nguyen to");
			return step2();
		}
	}

	BT1 step2() { //Kiem tra tinh doi xung
		String N = String.valueOf(n);
		int first = 0, last = String.valueOf(n).length();
		if (last < 2) {System.out.println(", khong the xet tinh doi xung!"); return this;}
		else {
			while (last - first > 1) {
				if (!N.substring(first, first+1).contains(N.substring(last-1, last))) {	System.out.println(", khong doi xung."); return this;}
				else {first++; last--;}
			}
		}
		System.out.println(", la so doi xung."); return this;
	}

	private static Scanner scanner = new Scanner(System.in);

	public static void main(String arg[]){
		System.out.print("Nhap n = ");	int n = scanner.nextInt();
		BT1 Main = new BT1();
		Main.runner(n);
	}
}