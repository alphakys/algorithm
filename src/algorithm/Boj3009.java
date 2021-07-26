package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Boj3009 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int[] xArr = new int[4];
		int[] yArr = new int[4];
		
		for(int i=0; i<3; i++) {
			String[] arr = br.readLine().split(" ");
			xArr[i] = Integer.parseInt(arr[0]);
			yArr[i] = Integer.parseInt(arr[1]);
			
		}
		for(int i=1; i<=3; i++) {
			if(xArr[0]==xArr[i] && i<=2) {
				sb.append(xArr[3-i]).append(" ");
				break;
			}else if(i==3){
				sb.append(xArr[0]).append(" ");
				break;
			}
							
		}
		
		for(int i=1; i<=3; i++) {
			if(yArr[0]==yArr[i]) {
				//System.out.println("i:"+i);
				sb.append(yArr[3-i]);
				break;
			}else if(i==3){
				//System.out.println("i:::"+i);
				sb.append(yArr[0]);
				break;
			}
		}
		
		
		
		
		System.out.println(sb.toString());
		
			
	}

}
