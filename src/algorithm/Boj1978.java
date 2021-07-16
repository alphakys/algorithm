package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Boj1978 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());

		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		
		int notPrime=0;
		while(st.hasMoreTokens()) {
			
			int n = Integer.parseInt(st.nextToken());
				
				if(n==1) {
					notPrime++;
				}
				for(int j=2; j<n; j++) {
				
					if(n%j ==0) {
						notPrime++;
						break;
					}
				}
				
		}
		System.out.println(N-notPrime);
		
		
		
	}

}
