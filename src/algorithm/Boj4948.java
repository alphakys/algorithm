package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj4948 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		boolean[] isPrime = new boolean[(123456*2)+1];
		isPrime[1] = true;
		
		for(int i=2; i<=(123456*2); i++) {
			
			if(isPrime[i]) continue;
			
			for(int j=2; i*j<=123456*2; j++) {
				if(!isPrime[i*j]) {
					isPrime[i*j] = true;
				}
				
			}
		}
		
		while(n!=0) {
			int count=0;
			for(int i=n+1; i<=(2*n); i++) {
				if(!isPrime[i]) {
					count++;
				}
			}
			System.out.println(count);
			n = Integer.parseInt(br.readLine());
		}
		
	}

}
