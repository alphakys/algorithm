package algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Boj9020 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));	
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		boolean[] isPrime = new boolean[10001];
		Arrays.fill(isPrime, true);
		isPrime[1]=false;
		
		for(int i=2;i<10000;i++) {
			
			if(isPrime[i]) {
				
				for(int j=2; (j*i)<10000; j++) {
					if(isPrime[i*j]) {
						isPrime[i*j] = false;
					}
				}
			}
		}
		
		int T = Integer.parseInt(br.readLine());
		
		for(int i=0;i<T;i++) {
			
			int n = Integer.parseInt(br.readLine());
			
			int left = n/2;
			int right = n/2;
			
			while(true) {
				
				if(isPrime[left] && isPrime[right]) {
					
					System.out.println(left +" "+ right);
					break;
				}
				
				left--;
				right++;
				
			}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			/*
			int left = n/2;
			int right = n/2;
			
			
			while(true) {
				int sum = left + right;
				
				if(isPrime[left]) {
					//System.out.println("left::"+left);
					if(isPrime[right]) {
						//System.out.println("right:::"+right);
							
							if(sum==n) {
								System.out.println("left:"+left+","+"right:"+right);
								break;
							}else if(sum>n){
								left--;
								continue;
							}else {
								right++;
								continue;
							}
						
							
						
						
					}else {
						right++;
					}
					
				}else {
					left--;
				}
			}
			*/
		}
		
	}

}
