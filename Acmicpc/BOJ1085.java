// Main.java

import java.util.Scanner;

public class Main {
	static private Scanner scan = new Scanner(System.in);
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int x = scan.nextInt(), 
			y = scan.nextInt(), 
			w = scan.nextInt(), 
			h = scan.nextInt();
        
		int hy = h - y,
			wx = w - x;
        
		int min = hy > wx ? (wx > y ? (y > x ? x : y):(wx > x ? x : wx)):(hy > y ? (y > x ? x : y):(hy > x ? x : hy));
        
		System.out.println(min);
	}
}
