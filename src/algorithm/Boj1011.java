package algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj1011 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for(int i=0; i<T; i++) {
			
			String[] str = br.readLine().split(" ");
			
			long x = Long.parseLong(str[0]);
			long y = Long.parseLong(str[1]);
			
			int count=2;
			
			long left = x+1;
			long right = y-1;
			
			int forward = 1;
			int backward = 1;
			
			if(y-x==1) {
				sb.append(1+"\n");
				
			}else if(y-x==2) {
				sb.append(2+"\n");
				
			}else {
				while(true) {
				
					if(left< right) {
						forward++;
						left = left+forward;
						count++;
						
						if(left< right) {
							backward++;
							right = right-backward;
							count++;
						}else {
							break;
						}
					
					}else {
						break;
					}
				}
				sb.append(count+"\n");
			}
			
			
			
		
		}
		System.out.println(sb.toString());
	}


}
