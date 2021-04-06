package algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class String11720 {

	public static void main(String[] args)throws IOException {
			
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		String[] strArr = br.readLine().split("");
		
		int sum=0;
		for(int i=0; i<N; i++) {
			
			int a = Integer.parseInt(strArr[i]);
			sum+=a;
			
					
		}
		System.out.println(sum);
		br.close();
		
	}

}
