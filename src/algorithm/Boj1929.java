package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;

public class Boj1929 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		String[] str = br.readLine().split(" ");
		
		int M = Integer.parseInt(str[0]);
		int N = Integer.parseInt(str[1]);
		
		if(M==1) {
			M=2;
		}
		HashMap<Integer, Boolean> map = new HashMap<>(); 
		ArrayList<Integer> arr = new ArrayList<>();
		
		Boolean[] prime = new Boolean[N-M+1];
		int[] num = new int[N-M+1];
				
			for(int i=0, j=M; i<num.length; i++, j++) {

				for(int k=2; k<=Math.sqrt(j); k++) {
					
					
					if(j%k==0) {
					
						num[i] = j;
						prime[i] = false;
						break;
					}
					
					
					}
				
					if(prime[i]==null) {
						num[i] = j;
						prime[i] = true;
						
					}
				
				
			}
			
		
		
		for(int i=0; i<num.length; i++) {
			
			if(prime[i]) {
				System.out.println(num[i]);
			}
		}
		
		
	}

}
