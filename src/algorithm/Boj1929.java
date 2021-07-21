package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Boj1929 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		String[] strArr = br.readLine().split(" ");
		
		int M = Integer.parseInt(strArr[0]);
		int N = Integer.parseInt(strArr[1]);
		
		boolean[] isPrime = new boolean[N+1];
		
		for(int i=2; i<=N; i++) {
			
			if(isPrime[i]) {
				continue;
			}
			
			if(i>=M) sb.append(i).append("\n");
			
			for(int j=2; i*j<=N; j++) {
				isPrime[i*j]=true;
			}
		}
		System.out.println(sb);	
	}

}
