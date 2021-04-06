package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class String5662 {
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str[] = br.readLine().split("");
		
		int time = 0;
		for(int i=0; i<str.length; i++) {
			
			
			switch(str[i].charAt(0)) {
			
				case 'A': case 'B': case 'C': time+=3; 
				break;
				case 'D': case 'E': case 'F': time+=4;
				break;	
				case 'G': case 'H': case 'I': time+=5;	
				break;	
				case 'J': case 'K': case 'L': time+=6;
				break;	
			    case 'M': case 'O': case 'N': time+=7;
			    break;	
			    case 'R': case 'P': case 'S': case 'Q': time+=8;
			    break;	
			    case 'V': case 'U': case 'T': time+=9;
			    break;
			    case 'X': case 'Y': case 'W': case 'Z': time+=10;
			    break;	
			    
				
				
				
			}
			
			
			
		}
		System.out.println(time);

	}
	
	
	
}
