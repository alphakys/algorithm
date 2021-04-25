package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj2869 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] str = br.readLine().split(" ");
		
		int A = Integer.parseInt(str[0]);
		int B = Integer.parseInt(str[1]);
		int V = Integer.parseInt(str[2]);
		
		int day = 0;
		int night = 0;
		
		if(A==V) {
			System.out.println(1);
		}else{
			
			for(int i=1; ;i++) {
				day += A*i;
				
				if(day <V) {
					night += (A-B);
					day = night;
				}
			}
			
			
		}
		
	}

}
