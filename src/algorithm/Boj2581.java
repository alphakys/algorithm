package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map.Entry;

public class Boj2581 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int M = Integer.parseInt(br.readLine());
		int N = Integer.parseInt(br.readLine());
		
		boolean[] isPrime = new boolean[N-M+1];
		Arrays.fill(isPrime, true);

		for(int i=M; i<=N; i++) {
			
			if(i==1) {
				isPrime[0]=false;
			}else if(i==2) {
				
				if((N/2)>=2) {
					for(int a=2;a<=(N/2);a++) {
						
						isPrime[(2*a)-1]=false;
					}
				}
			}else {
				
				for(int j=2; j<i; j++) {
					int count=0;
					if(isPrime[i-1]==true) {
						
						if(i%j!=0) {
							count++;
							if(count==(i-2))
								
								if((N/i)>=2) {
									for(int a=2;a<=(N/i);a++) {
										
										isPrime[(i*a)-1]=false;
									}
								}
								
							
						}
					}
					
				}
			
			}	
		}
		int sum=0;
		int arr = new int[1];
		for(int z=0;z<isPrime.length;z++) {
			
			if(isPrime[z]==true) {
				min = z;
				sum +=z+1;
			}
		}
		
		if(sum==0)
			System.out.println(-1);
		else
			System.out.println(sum);
	}	
		
}


