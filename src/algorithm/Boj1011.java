package algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj1011 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int i=0; i<T; i++) {
			
			String[] str = br.readLine().split(" ");
			
			long x = Long.parseLong(str[0]);
			long y = Long.parseLong(str[1]);
				
			long half = ((y-x-1)/2);
			
			long plus;
			long go;
			
			if((y-x)==2) {
				System.out.println(2);
				continue;
			}
			
			for(long j=1;; j++) {
				
				go = (j*(j-1))/2;
				
				if(go>half) {
					
					plus = j-2;
					go = ((j-1)*(j-2))/2;
					break;
				}
			}
			
			System.out.println("반:"+half);
			System.out.println("간거리:"+go);
			System.out.println("횟수:"+plus);
			
			long remainder = ((y-x-1)) - go;
			
			System.out.println("남은거리:"+remainder);
			System.out.println("간거리-남은거리:"+(go-remainder));
			System.out.println("횟수-(간거리-남은거리):"+(plus-(go-remainder)));
			
			if(remainder<=0) {
				System.out.println(((plus*2)+1));
			}
			else {
				System.out.println(((plus*2)+1));
			}
			
			//41707 2147483647  2147483645 2147483647  2147483643 2147483647
		}
		
	}


}
