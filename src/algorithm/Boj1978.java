package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1978 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		String[] str = br.readLine().split(" ");
		
		int count=0;
		for(int i=0;i<N;i++) {
			
			int n = Integer.parseInt(str[i]);
			
			if(n==1) {
				count++;
			}else {
				for(int j=2;j<n; j++) {
				
					if((n%j)==0) {
						count++;
						break;
					}
				}
				
			}
			

		}
		
		System.out.println(N-count);
		
	}

}
