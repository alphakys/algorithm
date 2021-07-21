package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Boj11653 {

	public static void main(String[] args)throws IOException {
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		if(N==1) {
			return;
		}else {
			
			for(int i=2; i<=Math.sqrt(N); i++) {
				
				while(N%i==0) {
					
					sb.append(i).append("\n");
					
					N = N/i;
				}
				
			}
			if(N!=1) {
				sb.append(N);
			}
		}
		System.out.println(sb);
		
	}

}
