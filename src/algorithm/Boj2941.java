package algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj2941 {

	public static void main(String[] args)throws IOException {
		String s1 = new String("c=");
		String s2 = new String("c-");
		String s3 = new String("dz=");
		String s4 = new String("d-");
		String s5 = new String("lj");
		String s6 = new String("nj");
		String s7 = new String("s=");
		String s8 = new String("z=");
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		//String[] stArr = br.readLine().split("");
		
		int i = br.read();
		int count=0;
		
		while(i>96) {
			int a = br.read();
			
			if(i==99) {
				
				if(a==45 || a==61) {
					count++;
				}else {
					count++;;
				}
			}else {
				count++;
				
			}
			
			i = br.read();
			
		}
		
		System.out.println(count);
	}

}
