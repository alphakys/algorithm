package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj11653 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		int part = N;
		int i=2;
		
		while(i<=N) {
			
			if((part%i)==0) {
				sb.append(i).append("\n");
				part = part/i;
				if(part==1) {
					break;
				}
				i=2;
			}else {
				i++;
			}
			//System.out.println(part);
		}
		
		System.out.println(sb);

	}

}
