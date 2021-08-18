package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj10870 {
	
	public static int fibonacci(int N) {
		
		if(N==0) {
			System.out.println(0);
			return 0;
		}else if(N==1) {
			System.out.println(1);
			return 1;
		}else {
			return fibonacci(N-1) + fibonacci(N-2);
		}
		
	}
	
	
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		int[][] arr = new int[41][41];
		
		//System.out.println(fibonacci(N));
		
		
		
		
	}

}
