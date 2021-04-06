package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class String1152 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String strArr[] = br.readLine().trim().split(" ");
		
				
		if("".equals(strArr[0])) {
			System.out.println(0);
		}
		else {
			System.out.println(strArr.length);

		}
			
	br.close();
	
	}
	
}
