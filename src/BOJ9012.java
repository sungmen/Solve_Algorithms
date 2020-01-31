// BOJ9012.java

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		for(int i = 0; i < N; i++){
			String cal = scan.next();
			build(cal);
		}
	}

	static void build(String cal) {
		Stack stk = new Stack();
		for (int i = 0; i < cal.length(); i++) {
			if (cal.charAt(i) == '(') {
				stk.create(cal.charAt(i));
			} else if (cal.charAt(i) == ')') {
				try {
					if ((char) stk.top.data == '(')
						stk.pop();
					else {
						stk.check = false;
						break;
					}
				}catch(NullPointerException e) {
					stk.check = false;
					break;
				}
			}
		}
		stk.print();
	}
}

class Node {
	Object data;
	Node link;
}

class Stack {
	Node top;
	boolean check = true;

	void create(Object x) {
		Node temp;
		
		if (top == null) {
			top = new Node();
			top.data = x;
			top.link = null;
		} else {
			temp = new Node();
			temp.data = x;
			temp.link = top;
			top = temp;
		}
	}

	void pop() {
		if (top == null)
			top = null;
		else
			top = top.link;
	}

	void print() {
		Node temp;
		temp = top;
		if(temp == null && check == true)
			System.out.println("YES");
		else {
			System.out.println("NO");
			while(temp!=null) {
				temp = temp.link;
			}
		}
	}
}
