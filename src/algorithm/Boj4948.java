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
			int mid = ((3*n)+1)/2;
			
			if(n%2==0) {
				for(int i=n+1, j=2*n; i<=mid; i++,j--) {
					
					if(!isPrime[i] || !isPrime[j]) {
						count++;
					}
				}
			}else {
				
				for(int i=n+1, j=2*n; i<=mid-1; i++,j--) {
					
					if(!isPrime[i]) {
						count++;
						
					}
					if(!isPrime[j]) {
						count++;
						
					}
				}
				
				if(!isPrime[mid]) {
					count++;
				}
			}
				
			
			System.out.println(count);
			n = Integer.parseInt(br.readLine());
		}
		
	}

}
