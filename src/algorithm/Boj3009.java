package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Boj3009 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int[] xArr = new int[3];
		int[] yArr = new int[3];
		
		for(int i=0; i<3; i++) {
			String[] arr = br.readLine().split(" ");
			xArr[i] = Integer.parseInt(arr[0]);
			yArr[i] = Integer.parseInt(arr[1]);
			
		}
		
		for(int i=1; i<3; i++) {
			if(xArr[0]==xArr[i]) {
				sb.append(yArr[3-i]).append(" ");
			}
			
			if(yArr[0]==yArr[i]) {
				sb.append(xArr[3-i]);
			}
			
			
		}
		
		System.out.println(sb.toString());
		
			
	}

}
