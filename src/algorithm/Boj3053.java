package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj3053 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		double R = Integer.parseInt(br.readLine());
		double num = (R*R*Math.PI)*1000000;
		
		System.out.println(Math.round(num)*0.000001);
		
		System.out.println(String.format("%.6f", 2*(R*R)));
		
		
		
	}

}
