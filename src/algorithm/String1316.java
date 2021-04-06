package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class String1316 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		boolean check;
		
		for(int i=0; i<N; i++) {
			
			String[] str = br.readLine().split("");
			
				for(int j=0; j<str.length; j++) {
					
					String isSame = str[0];
					String groupChar;
					
					if(!isSame.equals(str[j+1])) {
						
						isSame = str[j+1];
						
						groupChar = isSame;
						
						
						
					}
					
				}
			
				
				
				int[] arr = {1,2,3,4,5};
				
				int max = arr[0];
				
				for(int k=0; k< arr.length; k++) {
					
					if(max< arr[k+1]) {
						
						max = arr[k+1];
					}
					
				}
				
				
				
				
			
			
		}
		
		
		
		
		
		
		
	}

}
