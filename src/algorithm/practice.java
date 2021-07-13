package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class practice {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		
		for(int i=0; i<N; i++) {
			String[] strArr = br.readLine().split("");
			
			int index=1;
			sb.append(strArr[0]);
			while(true) {
				
				if(sb.toString().contains(strArr[index])) {
				
					if(!strArr[index-1].equals(strArr[index])) {
						System.out.println("out");
						break;
					}
						
					else {
						sb.append(strArr[index]);
						index++;
					}
					
				}
				
			}
				
			//aaaaaaaaaaaaabbbaa	
			
		}

	}
}