package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj2839 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());	
		
		for(int quotient = N/5; ;quotient--) {
			int remainder = N-(5*quotient);
			
			if((remainder%3)==0) {
				System.out.println(quotient+(remainder/3));
				break;
			}else if(quotient==0) {
				System.out.println(-1);
				break;
			}
		}
		
		

		
	}

}
