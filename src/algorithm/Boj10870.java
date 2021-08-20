package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj10870 {
	
	static int[] zero = new int[41];
	static int[] one = new int[41];
	
	public static void fibonacci(int n) {
		
		zero[n] = zero[n-1] + zero[n-2];
		one[n] = one[n-1] + one[n-2];
	}
	
	
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		zero[0] = 1;
		zero[1] = 0;
		one[0] = 0;
		one[1] = 1;
		
		for(int i=2; i<=40; i++) {
			fibonacci(i);
		}
		
		for(int i=0; i<N; i++) {
			int n = Integer.parseInt(br.readLine());
			
			System.out.println(zero[n]+ " " + one[n]);
		}
		
		/*
		for(int i=0; i<40; i++) {
			System.out.println("zero : "+ zero[i] + " one : "+one[i]);
		}
		*/
		
		
		
		
		
		
		
		//System.out.println(fibonacci(N));
		
		
		
		
	}

}
