package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj2292 {

	public static void main(String[] args)throws IOException {
			
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str = br.readLine();
		
		int N = Integer.parseInt(str);
		
		int sum = 0;
		
		if(N==1) {
			System.out.println(1);
		}
		else if(1<N && N<=7) {
			System.out.println(2);
		}
		else {
		
			
			
			for(int n=1; ;n++) {
				
				for(int k=1; k<=n; k++) {
				sum += 6*k;
				}
				
				if(1+sum < N && N <= 1+sum + ((n+1)*6)) {
					System.out.println(n+2);
					break;
				
				}else {
					sum=0;
				}
				
				
			}
			
		
		}
		
		
	}

}
