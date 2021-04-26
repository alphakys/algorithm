package algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj2869 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String[] str = br.readLine().split(" ");
		
		int A = Integer.parseInt(str[0]);
		int B = Integer.parseInt(str[1]);
		int V = Integer.parseInt(str[2]);
		
		if(A==V) {
			bw.write(String.valueOf(1));
		}else if((A-B) != 1) {
			
			
			int answer = (V-A)/(A-B);
			
			if(answer>0) {
				
				if((V-A)%(A-B)==0) {
					answer = answer+1;
					bw.write(String.valueOf(answer));
				}else {
					answer = answer+2;
					bw.write(String.valueOf(answer));
				}
				
			}else {
				bw.write(String.valueOf(2));
			}
			
			
		}else {
			bw.write(String.valueOf((V-A)+1));
		}
			
		bw.flush();
		bw.close();
		br.close();

	}

}
