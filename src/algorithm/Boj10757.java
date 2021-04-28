package algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.text.NumberFormat;

public class Boj10757 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		long max = 9223372036854775807L;
		
		String[] str = br.readLine().split(" ");
		
		BigDecimal N = new BigDecimal(str[0]);
		BigDecimal K = new BigDecimal(str[1]);
			
		System.out.println(N.add(K));
		
	}

}
