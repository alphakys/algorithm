package algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj1011 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int i=0; i<T; i++) {
			String[] str = br.readLine().split(" ");
			
			long x = Long.parseLong(str[0]);
			long y = Long.parseLong(str[1]);
			
			long distance = y-x-1;
			
			
			for(long k=1;;k++) {
				
				long go = x +(k*(k+1))/2;
				
				if(go>=y-1) {
					long answer = k+1;
					System.out.println(answer);
					//bw.write(String.valueOf(answer));
					break;
				}
				
				
			}
			
			bw.flush();
			
		}
		
		br.close();
		bw.close();
		
	}


}
