package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj2775 {

	public static void main(String[] args)throws IOException {
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int i=0; i<T; i++) {
			
			int k = Integer.parseInt(br.readLine());
			int n = Integer.parseInt(br.readLine());
			
			int[][] apart = new int[k+1][n];
			
			for(int f=0; f<1;f++) {
				
				for(int no=1;no<=n ;no++) {
					
					apart[f][no-1] = no;
					
				}
					
			}
			
			
			for(int f=1; f<=k;f++) {
					
					int num=0;
					int no;
					for(no=0; no<n; no++) {
						
						num+= apart[f-1][no];
						
						apart[f][no] = num;
						
					}
								
			}
			
			System.out.println(apart[k][n-1]);
			
		}
		
		
	}	
	
}

