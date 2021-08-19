package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj10870 {
	
	static class fiboData{
		int zero;
		int one;
		
		public fiboData(int x, int y) {
			x = this.zero;
			y = this.one;
		}
		
		@Override
		public String toString() {
			return "fiboData [zero=" + zero + ", one=" + one + "]";
		}
		
		
	}
	
	static fiboData[] fibo = new fiboData[40];
	
	public static void add(int num, int num1) {
		
		int zero = fibo[num].zero + fibo[num1].zero;
		int one = fibo[num].one + fibo[num1].one;
		
		fibo[num+num1] = new fiboData(zero, one);

	}
	
	public static void fibonacci() {
		
		fibo[0] = new fiboData(1,0);
		
		fibo[1] = new fiboData(0,1);

		System.out.println(fibo[0].zero);
		for(int i=2; i<=40; i++) {
			add(i-1, i-2);
		}
		
	}
	
	
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		fibonacci();
		for(fiboData f : fibo ) {
			System.out.println(f);
		}
		
		
		
		
		
		
		
		
		
		
		//System.out.println(fibonacci(N));
		
		
		
		
	}

}
