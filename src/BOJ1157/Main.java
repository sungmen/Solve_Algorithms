// BOJ1157.Main.java
import java.util.Scanner;
public class Main {
	static private Scanner scan = new Scanner(System.in);
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] alphabet = new int[26];
		String paragraph = scan.next();
		String upper = paragraph.toUpperCase();
		for (int i = 0; i < upper.length(); i++) {
			alphabet[(int)upper.charAt(i)-65]++;
		}
		
		int max = 0;
		char resolve = 0;
		for (int i = 0; i < 26; i++) {
			if (max < alphabet[i]) {
				max = alphabet[i];
				resolve = (char)(i+65);
			} else if (max == alphabet[i]) {
				resolve = '?';
			}
		}
		
		System.out.println(resolve);
	}

}
