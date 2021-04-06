package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class String2675 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
				
		int T = Integer.parseInt(br.readLine());
		
		for(int i=0; i<T; i++) {
			
		
		String[] strArr = br.readLine().split("");
		
		int rotation = Integer.parseInt(strArr[0]);
		
		
		for(int j=2; j<strArr.length; j++) {
			
			for(int k=0; k<rotation; k++) {
				System.out.print(strArr[j]);
			}
			
		}
		System.out.println();
		
		
		}
	}

}
