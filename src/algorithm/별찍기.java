package algorithm;

import java.util.Scanner;

public class 별찍기 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		//*00
		//**0
		//***
		//**0 4
		//*00 5
		
		//1 2 3 4 5 6
		//1 3 5 7 9 11
		//1 + 2(n-1)
		
		
		for(int i=0; i<N-1; i++) {
			for(int j=0; j<=i;j++) {
				System.out.print("*");
			}
			System.out.println();
		}
		
		
		for(int i=N; i>0; i--) {
			
			for(int j=0; j<i;j++) {
				System.out.print("*");
			}
			System.out.println();
		}
		
	
	}

}
