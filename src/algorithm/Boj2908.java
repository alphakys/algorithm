package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj2908 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb1 = new StringBuilder();
		StringBuilder sb2 = new StringBuilder();
		
		String[] strArr = br.readLine().split(" ");
		
		int a=0;
		int b=0;;
		
		for(int i=2; i>=0; i--) {
			sb1.append(strArr[0].charAt(i));
			a = Integer.parseInt(sb1.toString());
		}
		
		for(int i=2; i>=0; i--) {
			sb2.append(strArr[1].charAt(i));
			b = Integer.parseInt(sb2.toString());
		}
		
		if(a>b) {
			System.out.println(a);
		}else {
			System.out.println(b);
		}
		
		
	}

}
