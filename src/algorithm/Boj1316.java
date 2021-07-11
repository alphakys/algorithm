package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1316 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		int[] arr = new int[26];
		
		for(int i=0; i<N; i++) {
			int a = br.read();
			
			while(a>96) {
				
				arr[a-97]++;
				
				a = br.read();
			}
			
			
			
		}
		
		for(int b : arr) {
			System.out.println(b);
		}
		
		
	}

}
