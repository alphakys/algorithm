package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1193 {

	public static void main(String[] args)throws IOException {
		
		
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		if(N==1) {
			System.out.println(1+"/"+1);
			return;
		}else {
			
			for(int n=2; ;n++) {
			
				int start = ((n*(n-1))/2)+1;
				int end = (((n+1)*(n))/2)+1;
				
				if(start<=N && N<end) {
					
					if(start==N && (n%2)==0) {
						//System.out.println("st");
						System.out.println(1+"/"+n);
						break;
					}else if(start==N && (n%2)!=0) {
						//System.out.println("end");
						System.out.println(n+"/"+1);
						break;
					}else {
						
						if((n%2)==0) {
							//System.out.println("st 나머지"+n);
							System.out.println(1+(N%start)+"/"+(n-(N%start)));
							break;
						}else {
							//System.out.println("end 나머지"+n);
							//System.out.println(start);
							System.out.println(n-(N-start)+"/"+(N-start+1));
							break;
						}
						
					}
					
				}
				
				
				
			}
		}
		
	}

}
