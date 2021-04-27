package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj10250 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		int H;
		int W;
		int N;

		for(int i=0; i<T; i++) {
			String str[] = br.readLine().split(" ");
			
			H = Integer.parseInt(str[0]);
			W = Integer.parseInt(str[1]);
			N = Integer.parseInt(str[2]);
			
			int roomNum;
		
			if(N%H==0) {
				roomNum = (H*100) + (N/H);
			}else {
				roomNum = ((N%H)*100)+ (N/H)+1;
			}
			System.out.println(roomNum);
		}
			
		
	}

}
