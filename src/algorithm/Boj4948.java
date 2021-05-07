package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj4948 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n;
		
		while((n = Integer.parseInt(br.readLine()))!=0) {
			
			int count = 0;
			
			for(int j=n+1; j<=2*n; j++) {
				
				
				for(int i=2; i<=Math.sqrt(j); i++) {
					
					if(j%i==0) {
						//System.out.println("j:"+j);
						//System.out.println("i:"+i);
						count++;
						//System.out.println("count:"+count);
						break;
					}
				}
			
				
			}
			System.out.println(((2*n)-n)-count);
			continue;
		}
	}

}
