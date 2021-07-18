package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;


public class Boj2581 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int M = Integer.parseInt(br.readLine());
		int N = Integer.parseInt(br.readLine());
		
		boolean[] isPrime = new boolean[N+1];
		Arrays.fill(isPrime, true);
		isPrime[1]=false;
		
		for(int i=2; i<N; i++) {
			
			if(isPrime[i]) {
				
				for(int j=2; (j*i)<=N; j++) {
					
					if(isPrime[j*i]) {
						isPrime[j*i] =false;
					}
						
				}
			}	
		}
	
		int sum=0;
		int min=0;
		
		for(int i=M; i<=N; i++) {
			
			if(isPrime[i]) {
				
				if(min==0) {
					min = i;
				}
				sum+=i;
			}
		}
		
		if(sum==0) {
			System.out.println(-1);
		}else {
			System.out.println(sum);
			System.out.println(min);
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		/*
		for(int i=M; i<=N; i++) {
			
			if(i==1) {
				isPrime[0]=false;
			}else if(i==2) {	 
	
				if((N/2)>=2) {
					for(int a=2;a<=(N/2);a++) {
						
						isPrime[(2*a)-M]=false;
					}
				}
			}else {
			
				if(isPrime[i-M]==true) {
					
					int count=0;
					
					for(int j=2; j<i; j++) {
						
							if((i%j)!=0) {
								count++;
								
								if(count==(i-2)) {

									if((N/i)>=2) {
										
										for(int a=2;a<=(N/i);a++) {
											
											isPrime[(i*a)-M]=false;
										}
									}
								}	
								
							}else {
								isPrime[i-M]=false;
							
								break;
							}
						}
					
				}
			
			}	
		}
		int sum=0;
		int len = isPrime.length;
		int[] arr = new int[1];
		
		for(int z=0;z<len;z++) {
	
			if(isPrime[z]==true) {	
				sum +=(z+M);
				if(arr[0]==0) {
					arr[0] = (z+M);
				}else {
					continue;
				}
				
			}
		}
		
		
		
		if(sum==0) {
			System.out.println(-1);
		}else {
			System.out.println(sum);
			System.out.println(arr[0]);
		}
		*/	
	}	
		
}


