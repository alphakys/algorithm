package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj10872 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		System.out.println(function.factorial(N));

	}

}

class function {
	
	static int factorial(int N) {
			
		if(N<=1) {
			return 1;
		}else {
			return N*factorial(N-1);
		}
		
		
	}
}