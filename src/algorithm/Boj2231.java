package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Boj2231 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str = br.readLine();
		
		int N = Integer.parseInt(str);
		
		if(N<10) {
			
			for(int i=1;i<10;i++) {
				if((i+i)==N) {
					System.out.println(i);
					return;
				}
			}
			System.out.println(0);
			return;
		}else if(N<19) {
			
			for(int i = 10; i<=N; i++) {
				
				String[] stArr = String.valueOf(i).split("");
				
				int sum=0;
				for(int j=0;j<stArr.length;j++) {
					
					sum += Integer.parseInt(stArr[j]);	
				}
				
				if(sum+i==N) {
					System.out.println(i);
					return;
				}
		
			}
			
			System.out.println(0);
			return;
			
		}else {
			String strArr[] = str.split("");
		
			for(int i = N-(strArr.length*9); i<N; i++) {
				
				String[] stArr = String.valueOf(i).split("");
				
				int sum=0;
				for(int j=0;j<stArr.length;j++) {
					
					sum += Integer.parseInt(stArr[j]);
			
					
				}
				if(sum+i==N) {
						System.out.println(i);
						return;
				}
			}
			System.out.println(0);
			return;
		}
		
		
		
	}

}
